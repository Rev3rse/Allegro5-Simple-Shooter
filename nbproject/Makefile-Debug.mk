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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/modules/box_collision.o \
	${OBJECTDIR}/modules/bullets.o \
	${OBJECTDIR}/modules/enemies.o \
	${OBJECTDIR}/modules/enemy_bullets.o \
	${OBJECTDIR}/modules/explosion_bullets.o \
	${OBJECTDIR}/modules/gravity_bullets.o \
	${OBJECTDIR}/modules/player.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lallegro -lallegro_acodec -lallegro_audio -lallegro_color -lallegro_dialog -lallegro_font -lallegro_image -lallegro_main -lallegro_memfile -lallegro_physfs -lallegro_primitives -lallegro_ttf

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simple_shooter

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simple_shooter: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simple_shooter ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/modules/box_collision.o: modules/box_collision.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/box_collision.o modules/box_collision.c

${OBJECTDIR}/modules/bullets.o: modules/bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/bullets.o modules/bullets.c

${OBJECTDIR}/modules/enemies.o: modules/enemies.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/enemies.o modules/enemies.c

${OBJECTDIR}/modules/enemy_bullets.o: modules/enemy_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/enemy_bullets.o modules/enemy_bullets.c

${OBJECTDIR}/modules/explosion_bullets.o: modules/explosion_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/explosion_bullets.o modules/explosion_bullets.c

${OBJECTDIR}/modules/gravity_bullets.o: modules/gravity_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/gravity_bullets.o modules/gravity_bullets.c

${OBJECTDIR}/modules/player.o: modules/player.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/player.o modules/player.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/collision_test.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/collision_test.o: tests/collision_test.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/collision_test.o tests/collision_test.c


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/modules/box_collision_nomain.o: ${OBJECTDIR}/modules/box_collision.o modules/box_collision.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/box_collision.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/box_collision_nomain.o modules/box_collision.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/box_collision.o ${OBJECTDIR}/modules/box_collision_nomain.o;\
	fi

${OBJECTDIR}/modules/bullets_nomain.o: ${OBJECTDIR}/modules/bullets.o modules/bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/bullets.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/bullets_nomain.o modules/bullets.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/bullets.o ${OBJECTDIR}/modules/bullets_nomain.o;\
	fi

${OBJECTDIR}/modules/enemies_nomain.o: ${OBJECTDIR}/modules/enemies.o modules/enemies.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/enemies.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/enemies_nomain.o modules/enemies.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/enemies.o ${OBJECTDIR}/modules/enemies_nomain.o;\
	fi

${OBJECTDIR}/modules/enemy_bullets_nomain.o: ${OBJECTDIR}/modules/enemy_bullets.o modules/enemy_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/enemy_bullets.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/enemy_bullets_nomain.o modules/enemy_bullets.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/enemy_bullets.o ${OBJECTDIR}/modules/enemy_bullets_nomain.o;\
	fi

${OBJECTDIR}/modules/explosion_bullets_nomain.o: ${OBJECTDIR}/modules/explosion_bullets.o modules/explosion_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/explosion_bullets.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/explosion_bullets_nomain.o modules/explosion_bullets.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/explosion_bullets.o ${OBJECTDIR}/modules/explosion_bullets_nomain.o;\
	fi

${OBJECTDIR}/modules/gravity_bullets_nomain.o: ${OBJECTDIR}/modules/gravity_bullets.o modules/gravity_bullets.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/gravity_bullets.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/gravity_bullets_nomain.o modules/gravity_bullets.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/gravity_bullets.o ${OBJECTDIR}/modules/gravity_bullets_nomain.o;\
	fi

${OBJECTDIR}/modules/player_nomain.o: ${OBJECTDIR}/modules/player.o modules/player.c 
	${MKDIR} -p ${OBJECTDIR}/modules
	@NMOUTPUT=`${NM} ${OBJECTDIR}/modules/player.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/modules/player_nomain.o modules/player.c;\
	else  \
	    ${CP} ${OBJECTDIR}/modules/player.o ${OBJECTDIR}/modules/player_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simple_shooter

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
