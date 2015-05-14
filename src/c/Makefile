#
#
#

PWD = $(shell pwd)
ROOT = $(PWD)/../..

CC = gcc
CXX = g++
JAVAH = javah
JNI_INCLUDE = $(JAVA_HOME)/include
ISL_INCLUDE = $(ISL_HOME)/include
CFLAGS += -I$(JNI_INCLUDE) -I$(JNI_INCLUDE)/linux -I$(ISL_INCLUDE) -fpic -fPIC

SCALA_LIB_HOME = $(SCALA_HOME)/lib
SCALA_CP = $(SCALA_LIB_HOME)/scala-library.jar:$(SCALA_LIB_HOME)/scala-reflect.jar
SCALA_VER=2.11
ISL_CP = $(ROOT)/target/scala-$(SCALA_VER)/classes

target: isl_jni_dlib

isl_jni_iface:
	cd $(ROOT); sbt compile
	$(JAVAH) -jni -cp $(SCALA_CP):$(ISL_CP) isl.ISL

isl_jni_dlib: isl_jni_iface
	$(CC) $(CFLAGS) -shared -g -Wall -O3 \
		isl_wrapper.c \
		-L$(ISL_HOME)/.libs -lisl \
		-o $(ROOT)/libisl_jni.so

env_test:
	@echo $(PPCG_HOME)
	@echo $(ISL_HOME)
	@echo $(SCALA_HOME)
	@echo $(SCALA_CP)
