#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=hex
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=hex
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=TinyB18F2455-2550-4455-4550.asm

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o
POSSIBLE_DEPFILES=${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o

# Source Files
SOURCEFILES=TinyB18F2455-2550-4455-4550.asm


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=EEPROM8
MP_LINKER_DEBUG_OPTION= 
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o: TinyB18F2455-2550-4455-4550.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.d 
	@${RM} ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o 
	@${FIXDEPS} dummy.d -e "C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG  -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.asm\" 
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.O ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.ERR ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.err
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.LST ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.lst
	@${DEP_GEN} -d "${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o"
	@${FIXDEPS} "${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
else
${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o: TinyB18F2455-2550-4455-4550.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.d 
	@${RM} ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o 
	@${FIXDEPS} dummy.d -e "C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.ERR" $(SILENT) -rsi ${MP_AS_DIR} -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  $(ASM_OPTIONS)    \"C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.asm\" 
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.O ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.ERR ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.err
	@${MV}  C:/Users/Carlos_Tonche/Documents/bootloader.X/TinyB18F2455-2550-4455-4550.LST ${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.lst
	@${DEP_GEN} -d "${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o"
	@${FIXDEPS} "${OBJECTDIR}/TinyB18F2455-2550-4455-4550.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${MV}  "TinyB18F2455-2550-4455-4550.HEX" dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	@${MV}  "TinyB18F2455-2550-4455-4550.HEX" dist/${CND_CONF}/${IMAGE_TYPE}/bootloader.X.${IMAGE_TYPE}.hex 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
