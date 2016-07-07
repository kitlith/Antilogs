# Antilogs
_Antichamber timer tools._

## What is this?
At the moment, this is a series of tools meant to be preloaded using LD_PRELOAD
while running Antichamber to provide logs useful for speedrun timers. Eventually, it may be expanded to cover Windows dll stuff.

Currently, there is a method to detect the end of an any% run by using the raw,
compressed length of the data. (`ov_raw_total`)

A utility quickly made for finding out the output of `ov_raw_total` for a given
file is also provided.

## Usage

`LD_PRELOAD=/path/to/antiogg.so /path/to/Antichamber/Binaries/Linux/UDKGame-Linux`

## Hacking
I used `umodel` (available here: http://gildor.org/en/projects/umodel) to
extract the ogg files contained within
`/path/to/Antichamber/UDKGame/CookedLinux/Maps/Hazard/Sublevels/HazardSound.udk`
using the command:
`umodel -export -sounds -nomesh -noanim -nostat -notex -nolightmap /path/to/HazardSound.udk`.
Output files will be contained inside the `UmodelExport/HazardSound/SoundNodeWave` directory.

`oggrawsize` (contained here) is what I'm using to get the needed values to compare
to inside of the shared library. I'm sure there's a much better way to do this,
but I don't know how to get any sort of filename, so this'll do for now.
