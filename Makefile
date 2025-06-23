# Simple and practical Makefile for cfourcc
# Maintainer: mypapit (with some wizardly touch)
# Date: 25 February 2005 (improved: 2025-06-23)
#
# Usage:
#   make         # Builds the program
#   make install # Installs to PREFIX/bin
#   make clean   # Removes built files
#   make uninstall # Removes installed binary

CC      := gcc
CFLAGS  := -O2 -pedantic -ansi -Wall
INSTALL := install
PREFIX  ?= /usr/local
BINDIR  := $(PREFIX)/bin

SRC     := cfourcc.c
TARGET  := cfourcc

# 'all' is the default target
.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@
	@echo "Build complete: $(TARGET)"

install: all
	strip $(TARGET)
	$(INSTALL) -Dm755 $(TARGET) $(BINDIR)/$(TARGET)
	@echo "Installed $(TARGET) to $(BINDIR)"

uninstall:
	rm -f $(BINDIR)/$(TARGET)
	@echo "Uninstalled $(TARGET) from $(BINDIR)"

clean:
	rm -f $(TARGET)
	@echo "Cleaned up build files."
