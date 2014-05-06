# plain simple and stupid Makefile for cfourcc
#
# author : mypapit
# date : 25 February 2005
#

CC=gcc
CFLAGS=-O2 -pedantic -ansi -Wall
INSTALL=install
PREFIX=/usr/local


all :
	$(CC) $(CFLAGS) cfourcc.c -o cfourcc

install : all
	strip cfourcc
	$(INSTALL) -m755 cfourcc $(PREFIX)/bin

clean : 
	rm -f cfourcc






