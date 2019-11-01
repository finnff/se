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

SOURCES := armdecomp.asm encoded.asm


encoded.o: compressor.hpp match.hpp compressor.cpp
	$(compiler) -c compressor.cpp -o encoded.o






# source files in this project (main.cpp is automatically assumed)
# header files in this project
HEADERS := match.hpp compressor.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)..
include $(RELATIVE)/Makefile.due
