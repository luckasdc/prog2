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
#  Copyright 2013, Jan Broeckhove, CoMP group, Universiteit Antwerpen.
#
#############################################################################

#============================================================================
# Build Google test framework gtest (build only, no install)
#============================================================================
set( CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -Wno-unused" )
set( GTEST_RESOURCE_DIR	   ${CMAKE_HOME_DIRECTORY}/test/resources/lib/gtest/ )
include_directories( ${GTEST_RESOURCE_DIR} )
add_definitions( -DGTEST_LANG_CXX11 )
add_library( gtest STATIC ${GTEST_RESOURCE_DIR}/src/gtest-all.cc )	

#############################################################################
