#############################################################################
#  This file is part of the gobelijn software.
#  Gobelijn is free software: you can redistribute it and/or modify it
#  under the terms of the GNU General Public License as published by the
#  Free Software Foundation, either version 3 of the License, or any later
#  version. Gobelijn is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
#  or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU General Public License for details. You should have received
#  a copy of the GNU General Public License along with the software. If not,
#  see <http://www.gnu.org/licenses/>.
#
#  Copyright 2017, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################
#
#  CMakeLists.txt for the whole project.
#
#############################################################################
cmake_minimum_required(VERSION 2.8)

#============================================================================
# CMAKE_BUILD_TYPE: provide default build type:
#============================================================================
set( CMAKE_BUILD_TYPE "Release"
	CACHE STRING "Build type: None Debug Release RelWithDebInfo MinSizeRel." )

#============================================================================
# CMAKE_INSTALL_PREFIX: install directory definitions:
#============================================================================
set( CMAKE_INSTALL_PREFIX  "${CMAKE_BINARY_DIR}/installed" 
	CACHE PATH "Prefix prepended to install directories" )
 
#============================================================================
# Project name:
#============================================================================
project( gobelijn )
if( CMAKE_VERSION VERSION_GREATER 3 )
	cmake_policy(SET CMP0042 NEW)
endif()

#============================================================================
# Configuration for CMake, this build and C++ compile & link.
#============================================================================
include( CMakeCMakeConfig.cmake )
include( CMakeBuildConfig.cmake )
include( CMakeCPPConfig.cmake )

#============================================================================
# Add subdirs (excluding doc dir avoids building doc in development):
#============================================================================
add_subdirectory( main )
add_subdirectory( test )
if( GOBELIJN_INCLUDE_DOC )
	add_subdirectory( doc )
endif()

#============================================================================
# Overview report:
#============================================================================
message( STATUS " " )
message( STATUS "------> Settings and options: " )
message( STATUS "------> GOBELIJN_INCLUDE_DOC        : ${GOBELIJN_INCLUDE_DOC} "      )
message( STATUS "------> GOBELIJN_VERBOSE_TESTING    : ${GOBELIJN_VERBOSE_TESTING} "  )
#
message( STATUS " " )
message( STATUS "------> CMAKE_SYSTEM                : ${CMAKE_SYSTEM} "              )
message( STATUS "------> CMAKE_SYSTEM_VERSION        : ${CMAKE_SYSTEM_VERSION} "      )
message( STATUS "------> CMAKE_SYSTEM_PROCESSOR      : ${CMAKE_SYSTEM_PROCESSOR} "    )
message( STATUS "------> CMAKE_VERSION               : ${CMAKE_VERSION} "             )
message( STATUS "------> CMAKE_BUILD_TYPE            : ${CMAKE_BUILD_TYPE} "          )
message( STATUS "------> CMAKE_BINARY_DIR            : ${CMAKE_BINARY_DIR} "          )
message( STATUS "------> CMAKE_INSTALL_PREFIX        : ${CMAKE_INSTALL_PREFIX}"       )
message( STATUS "------> CMAKE_CXX_COMPILER          : ${CMAKE_CXX_COMPILER}"         )
message( STATUS "------> CMAKE_CXX_COMPILER_ID       : ${CMAKE_CXX_COMPILER_ID}"      )
message( STATUS "------> CMAKE_CXX_COMPILER_VERSION  : ${CMAKE_CXX_COMPILER_VERSION}" )
message( STATUS "------> CMAKE_CXX_FLAGS             : ${CMAKE_CXX_FLAGS}"            )
if( CMAKE_BUILD_TYPE MATCHES "^[Rr]elease$" )
	message( STATUS "------> CMAKE_CXX_FLAGS_RELEASE     : ${CMAKE_CXX_FLAGS_RELEASE}" )
endif()
if( CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug$" )
	message( STATUS "------> CMAKE_CXX_FLAGS_DEBUG       : ${CMAKE_CXX_FLAGS_DEBUG}"   )
endif()
#
message( STATUS "" )
message( STATUS "Report complete." )

#############################################################################