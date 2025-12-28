# cfourcc

`cfourcc` is a UNIX/LINUX tool for changing the FOURCC of an MPEG4 or DivX file on the command line.

**Author**: Mohammad Hafiz bin Ismail a.k.a mypapit <mypapit@gmail.com>

**Project's page**: [https://github.com/mypapit/cfourcc](https://github.com/mypapit/cfourcc)

## Latest Release

Formal release for cfourcc 0.1.5 - [Releases](http://github.com/mypapit/cfourcc/releases)

## Background

FourCC (Four Character Code) is a (rather crude) method to identify the codec used to encode Microsoft RIFF AVI files. Application software/hardware use the FourCC to correctly select a codec suitable for playing the AVI file in question. The problem arises when a video player (usually the hardware one) fails to recognize a FourCC, and is unable to select a newer/compatible codec to play the AVI file. This simple program solves this problem by providing a simple way to change the FourCC of the AVI file to a value accepted by the video player.

I created this simple program after reading divx/mpeg4 related forums. It came to my attention that there weren't any software developed in GNU/Linux (nor other UN*X-variants) that have similar functionality as "Nic's Mini AviC" in the Microsoft Windows platform.

> **Note**: Transcode package includes `avifix` that can change fourcc, but it isn't compact enough and isn't available by itself.

For an unofficial list of FourCC/codec out there in the wild, please refer to [codeclist.txt](codeclist.txt).

## Legal

This software comes with **ABSOLUTELY NO WARRANTY**!

You may distribute this program with its sources under the terms of the **GNU General Public License**.
For more information about this matter, please refer to the file `COPYING`.

## Installation

1. Just type `make all`.
2. Be a root user and type `make install`.
3. Use the software as a normal user (refer to usage section).

## Usage

To obtain the fourcc code for an avi file:

```bash
cfourcc file.avi
# or
cfourcc -i file.avi
```

To change the fourcc code for an avi to 'DIVX':

```bash
cfourcc -u DIVX -d DIVX file.avi
```

> **Note**: You only need to change the FOURCC 'used' codec field most of the time; leave out the description code for reference.

To obtain online help information:

```bash
cfourcc -h
```

## Bugs

Please refer to the file `BUGS`.
