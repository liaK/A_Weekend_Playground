#############################################################################
# Makefile for building: DownloadManager
# Generated by qmake (2.01a) (Qt 4.7.4) on: Wed May 9 15:06:18 2012
# Project:  DownloadManager.pro
# Template: app
# Command: /home/yudhi/QtSDK/Desktop/Qt/474/gcc/bin/qmake -spec ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile DownloadManager.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ -I. -I../../../QtSDK/Desktop/Qt/474/gcc/include/QtCore -I../../../QtSDK/Desktop/Qt/474/gcc/include/QtNetwork -I../../../QtSDK/Desktop/Qt/474/gcc/include/QtGui -I../../../QtSDK/Desktop/Qt/474/gcc/include -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/yudhi/QtSDK/Desktop/Qt/474/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/yudhi/QtSDK/Desktop/Qt/474/gcc/lib -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/yudhi/QtSDK/Desktop/Qt/474/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		downloaddialog.cpp \
		statusdialog.cpp moc_downloaddialog.cpp \
		moc_statusdialog.cpp
OBJECTS       = main.o \
		downloaddialog.o \
		statusdialog.o \
		moc_downloaddialog.o \
		moc_statusdialog.o
DIST          = ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf \
		DownloadManager.pro
QMAKE_TARGET  = DownloadManager
DESTDIR       = 
TARGET        = DownloadManager

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: DownloadManager.pro  ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++/qmake.conf ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile DownloadManager.pro
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/g++.conf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/unix.conf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/common/linux.conf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/qconfig.pri:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/debug.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/qt.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/moc.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/resources.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/uic.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/lex.prf:
../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/474/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile DownloadManager.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/DownloadManager1.0.0 || $(MKDIR) .tmp/DownloadManager1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/DownloadManager1.0.0/ && $(COPY_FILE) --parents downloaddialog.h statusdialog.h .tmp/DownloadManager1.0.0/ && $(COPY_FILE) --parents main.cpp downloaddialog.cpp statusdialog.cpp .tmp/DownloadManager1.0.0/ && (cd `dirname .tmp/DownloadManager1.0.0` && $(TAR) DownloadManager1.0.0.tar DownloadManager1.0.0 && $(COMPRESS) DownloadManager1.0.0.tar) && $(MOVE) `dirname .tmp/DownloadManager1.0.0`/DownloadManager1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/DownloadManager1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_downloaddialog.cpp moc_statusdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_downloaddialog.cpp moc_statusdialog.cpp
moc_downloaddialog.cpp: downloaddialog.h
	/home/yudhi/QtSDK/Desktop/Qt/474/gcc/bin/moc $(DEFINES) $(INCPATH) downloaddialog.h -o moc_downloaddialog.cpp

moc_statusdialog.cpp: statusdialog.h
	/home/yudhi/QtSDK/Desktop/Qt/474/gcc/bin/moc $(DEFINES) $(INCPATH) statusdialog.h -o moc_statusdialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp downloaddialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

downloaddialog.o: downloaddialog.cpp downloaddialog.h \
		statusdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o downloaddialog.o downloaddialog.cpp

statusdialog.o: statusdialog.cpp statusdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statusdialog.o statusdialog.cpp

moc_downloaddialog.o: moc_downloaddialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_downloaddialog.o moc_downloaddialog.cpp

moc_statusdialog.o: moc_statusdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statusdialog.o moc_statusdialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
