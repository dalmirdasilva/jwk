#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/631556369/JNIJWkLib.o


# C Compiler Flags
CFLAGS=-shared

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk dist/libJWkLib.so

dist/libJWkLib.so: ${OBJECTFILES}
	${MKDIR} -p dist
	${LINK.c} -o dist/libJWkLib.so ${OBJECTFILES} ${LDLIBSOPTIONS} -lwkhtmltox -shared -fPIC

${OBJECTDIR}/_ext/631556369/JNIJWkLib.o: /home/dalmir/NetBeansProjects/JWkLib/JNIJWkLib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/631556369
	${RM} "$@.d"
	$(COMPILE.c) -g -I/usr/lib/jvm/java-8-oracle/include/linux -I/usr/lib/jvm/java-8-oracle/include -I/usr/local/include/ -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/631556369/JNIJWkLib.o /home/dalmir/NetBeansProjects/JWkLib/JNIJWkLib.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} dist/libJWkLib.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
