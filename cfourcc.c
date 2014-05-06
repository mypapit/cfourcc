
/*
    cfourcc.c - this is the main (and only) module.
    
    cfourcc - change the FOURCC code in the Microsoft RIFF AVI file.
    Copyright (C) 2004,2005,2014 Mohammad Hafiz bin Ismail (mypapit) <papit58@yahoo.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Project's web :  https://github.com/mypapit/cfourcc
*/

#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define AVILEN 224
#define FLAG_INFO 0x0001
#define FLAG_DESC 0x0010
#define FLAG_USED 0x0100
#define FLAG_HELP 0x1000
#define FLAG_FORCE 0x10000
typedef char AVIHDR[AVILEN];
extern char *strdup (const char *);

int
getDesc (AVIHDR header, char *str)
{
  memcpy (str, &header[0x70], 4);
  return 0;

}

int
getUsed (AVIHDR header, char *str)
{
  memcpy (str, &header[0xbc], 4);
  return 0;
}

int
setDesc (AVIHDR header, const char *str)
{
  memcpy (&header[0x70], str, 4);
  return 0;

}


int
setUsed (AVIHDR header, const char *str)
{
  memcpy (&header[0xbc], str, 4);
  return 0;

}

int
usage (void)
{
  puts
	("usage :\n\tcfoucc [-i] file.avi\n\tcfourcc -u DIVX file.avi\n\tcfourcc -d DIVX file.avi\n\tcfourcc -h\n");
  return 0;
}






int
main (int argc, char *argv[])
{
  AVIHDR avihdr;
  FILE *fin;
  int optchar;
  int flags = 0x00;
  static char strused[5], strdesc[5];
  char *ptrused = NULL, *ptrdesc = NULL;
  char MAGIC[] = { 'R', 'I', 'F', 'F' };

  memset (&avihdr, 0, AVILEN);	/*init avihdr just in case! */
  opterr = 0;

  puts
	("cfourcc 0.1.3 - (stupid) console fourcc changer\nCopyright (C) Mohammad Hafiz bin Ismail <mypapit@gmail.com>\nLicensed under the terms of the GNU General Public License\n");


  while ((optchar = getopt (argc, argv, "d:u:ihf::")) != -1) {
	switch (optchar) {
	case 'i':
/*				printf("print info\n");*/
	  flags |= FLAG_INFO;
	  break;
	
	case 'f':
	  flags |= FLAG_FORCE;
	  break;

	case 'd':
	  flags |= FLAG_DESC;
	  ptrdesc = (char *) strdup (optarg);
	  break;

	case 'u':
	  flags |= FLAG_USED;
	  ptrused = (char *) strdup (optarg);
	  break;

	case '?':

/*				flags|=FLAG_HELP;*/
	  /*usage(); */
	  break;

	case 'h':
	  flags |= FLAG_HELP;
	  usage ();

	  puts ("\t-h\t\t Prints this help ;)");
	  puts ("\t-i\t\t Prints FOURCC information (default)");
	  puts ("\t-f\t\t Force changing FOURCC on unsupported file (dangerous)");
	  puts ("\t-u CODE\t\t Sets FOURCC \'used\' codec");
	  puts ("\t-d CODE\t\t Sets FOURCC \'description\' codec\n");
	  puts ("\t ** refer to \'codeclist.txt\' documentation for a list of FOURCC\n\n");
	  break;


	default:
	  return 0x0;
	}
  }

  if (!((optind > 0) && (optchar = -1) && (argv[optind] != NULL))) {
	if ((flags & FLAG_HELP) != FLAG_HELP)
	  usage ();
	return 0x0f;
  }

  fin = fopen (argv[optind], "rb");
  if (fin == NULL) {
	fprintf (stderr, "Error : Cannot access %s\n", argv[optind]);
	return 0x01;
  }

  if (fread (avihdr, sizeof (char), AVILEN, fin) < AVILEN) {
	fprintf (stderr, "Error : Read end unexpectedly, incomplete file?\n");
	return 0x02;
  }
  fclose (fin);

  /*lazy verifier! */
  if (memcmp (avihdr, MAGIC, 4) && !(flags & FLAG_FORCE) ) {
	fprintf (stderr, "Error : Probably not a supported AVI or media file\n");
	return 0x03;
  }

  if (flags == 0x0 || ( (flags & FLAG_INFO) == FLAG_INFO)) {	/*default behaviour */


	getDesc (avihdr, strdesc);
	getUsed (avihdr, strused);

	printf ("FOURCC of \'%s\' :\nDescription : %s\nUse : %s\n\n",
			argv[optind], strdesc, strused);
	return 0x00;


  }

  if (((flags & FLAG_USED) == FLAG_USED)
	  || ((flags & FLAG_DESC) == FLAG_DESC)) {

	fin = fopen (argv[optind], "r+b");
	if (fin == NULL) {
	  fprintf (stderr, "Error : Cannot access %s for writing\n",
			   argv[optind]);
	  return 0x01;
	}
	if (flags & FLAG_USED)
	  setUsed (avihdr, ptrused);

	if (flags & FLAG_DESC)
	  setDesc (avihdr, ptrdesc);

	fseek (fin, 0, SEEK_SET);
	fwrite (avihdr, sizeof (char), AVILEN, fin);
	fflush (fin);
	fclose (fin);

	puts ("Attempting to change FOURCC value...\n");

  }

  puts ("Done.\n");

  return 0;

}
