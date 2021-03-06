#cfourcc

* cfourcc is a UNIX/LINUX tool for changing the FOURCC of an MPEG4 or DivX file on the command line.

* Author: Mohammad Hafiz bin Ismail a.k.a mypapit <mypapit@gmail.com>

* Project's page: https://github.com/mypapit/cfourcc
* 

#Latest Release
Formal release for cfourcc 0.1.3 - http://github.com/mypapit/cfourcc/releases

##Background

FourCC (Four Character Code) is a (rather crude) method to identify codec used to encode Microsoft RIFF AVI files. Application software/hardware use the FourCC to correctly select a codec suitable for playing the AVI file in question. The problem arises when a video player (usually the hardware one) fail to recognize a FourCC, and unable to select a newer/compatible codec to play the AVI file. This simple program solves this problem by providing a simple way to change the FourCC of the AVI file to a value accepted by the video player.

I created this simple program after reading divx/mpeg4 related forums. It comes to me that there arent any software developed in GNU/Linux (nor other UN*X-variant) that have similiar functionality as "Nic's Mini AviC" in Microsoft Windows platform.

* Note : Transcode package includes 'avifix' that can change fourcc, but it isn't compact enough and arent available by itself.

* For an unofficial list of FourCC/codec out there in the wild, please refer to 'codelist.txt'.



###Legal

This software comes with ABSOLUTELY NO WARRANTY!
You may distribute this program with it sources under the terms of GNU General Public License.
For more information about this matter please refer to the file COPYING.



###Installation

1. Just type 'make all'.
2. be a root user and type 'make install'
3. use the software as normal user. - refer usage section


###Usage

To obtain fourcc code for an avi file, type :
* cfourcc file.avi
* cfourcc -i file.avi

To change fourcc code for an avi to 'DIVX' file, type :
* cfourcc -u DIVX -d DIVX 

Note : you only need to change the FOURCC use codec field most of the time, leave out the description code for reference

To obtain online help information, type :
* cfourcc -h

###BUGS

Please refer to the file 'BUGS'.
