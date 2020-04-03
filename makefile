# Must set this to use source command
SHELL := /bin/bash

#must specify where to find the test inliner
INLINER=/path/to/rose_buildDebug/tests/nonsmoke/functional/roseTests/astInliningTests/inlineEverything

# some with system header, failing postprocessing
FAILED_FILES = \
	specimen26_1.C \
	specimen23_1.C \
	specimen24_1.C \
	simplest_raja.C \
	fail2.C \
	fail1.C
# list of regression tests
CPP_FILES = \
	    function_expressions.C \
	    function_expressions_v1.C \
	specimen01_1.C \
	specimen02_1.C \
	specimen03_1.C \
	specimen04_1.C \
	specimen05_1.C \
	specimen06_1.C \
	specimen07_1.C \
	specimen08_1.C \
	specimen09_1.C \
	specimen10_1.C \
	specimen11_3.C \
	specimen12_3.C \
	specimen13_1.C \
	specimen14_1.C \
	specimen15_1.C \
	specimen16_4.C \
	specimen17_10.C \
	specimen18_1.C \
	specimen19_1.C \
	specimen20_1.C \
	specimen21_1.C \
	specimen22_1.C \
	specimen25_1.C \
	test1A.C \
	test1B.C \
	test1.C \
	test2.C \
	testWithTokenStreamUnparsing_01.C \
	testWithTokenStreamUnparsing_02.C

# different versions of output, using different options

# v1:  without post processing
CPP_FILES_OUT_v1 = $(addprefix rose_v1_,${CPP_FILES}) 
# v2: with post processing, default behavior
CPP_FILES_OUT_v2 = $(addprefix rose_v2_,${CPP_FILES}) 

# rules to generate the output files
$(CPP_FILES_OUT_v1): $(@:rose_v1_%=%)
	$(INLINER) -skip-postprocessing -c $(@:rose_v1_%=%) -rose:output $@

$(CPP_FILES_OUT_v2): $(@:rose_v2_%=%)
	$(INLINER) -c $(@:rose_v2_%=%) -rose:output $@

#--------further convert dot file to pdf and pgn file------
all: $(CPP_FILES_OUT_v1) $(CPP_FILES_OUT_v2) 

check: $(CPP_FILES_OUT_v1) $(CPP_FILES_OUT_v2)

clean:
	rm -rf *.o $(CPP_FILES_OUT_v1) $(CPP_FILES_OUT_v2)
