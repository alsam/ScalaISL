#
#
#

PWD = $(shell pwd)
ROOT = $(PWD)/../..

CC = gcc
CXX = g++
ISL_INCLUDE = $(ISL_HOME)/include
CFLAGS += -I$(ISL_INCLUDE)
CXXFLAGS += $(CFLAGS)
LDFLAGS += -L$(HOME)/lib -lisl

TEST_DRIVER_SRC = test_driver.cpp

target: test_driver

isl_api_call.txt:
	$(shell perl -ne 'while(/\bisl_\w+/g){print "$$&\n";}' $(TEST_DRIVER_SRC) | sort | uniq > $@)
