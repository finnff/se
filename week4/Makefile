#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

	compiler := /bin/g++


.PHONY: build schoon

schoon:
	rm -f output.txt
	rm -f encoded.asm
	rm -f compressor.exe
	touch output.txt

encoded.asm:
	$(compiler) compressor.cpp -o compressor.exe
	./compressor.exe

SOURCES := armdecomp.asm encoded.asm



# source files in this project (main.cpp is automatically assumed)
# header files in this project
HEADERS := match.hpp compressor.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)..
include $(RELATIVE)/Makefile.due
