#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <vorbis/vorbisfile.h>

static FILE *log;

typedef int (*_ov_open_callbacks_type)(void *datasource, OggVorbis_File *vf, const char *initial, long ibytes, ov_callbacks callbacks);
extern int ov_open_callbacks(void *datasource, OggVorbis_File *vf, const char *initial, long ibytes, ov_callbacks callbacks) {
    _ov_open_callbacks_type _ov_open_callbacks = (_ov_open_callbacks_type)dlsym(RTLD_NEXT, "ov_open_callbacks");
    int ret = _ov_open_callbacks(datasource, vf, initial, ibytes, callbacks);

    long int size = ov_raw_total(vf, -1);
    switch (size) {
        case 55326: // FX_Stereo_BlackTile_PlaceA.ogg
            fputs("END\n", log);
            break;
        case 12423: // FX_ui_click.ogg
            fputs("MAP\n", log);
            break;
        default:
            break;
    }
    #ifdef DEBUG
    fprintf(log, "Ogg size: %ld\n", size);
    #endif
    fflush(log);
    return ret;
}

__attribute__((constructor)) void openLog(void) {
    log = fopen("ogg.log", "w");
}

__attribute__((destructor)) void closeLog(void) {
    fclose(log);
}
