#include <stdio.h>
#include <vorbis/vorbisfile.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return -1;
    }

    OggVorbis_File vf;
    ov_fopen(argv[1], &vf);
    printf("%ld\n", ov_raw_total(&vf, -1));
    ov_clear(&vf);
    return 0;
}
