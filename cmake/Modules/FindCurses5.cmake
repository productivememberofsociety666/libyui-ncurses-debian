# - Try to find curses5
# Once done this will define
#  CURSES_FOUND - System has Curses5
#  CURSES5_INCLUDE_DIR - The Curses5 include directory
#  CURSES5_LIBRARIES - The libraries needed to use Curses5
#  CURSES5_DEFINITIONS - Compiler switches required for using Curses5

message(${LIB_DIR})
FOREACH(path ${CMAKE_LIBRARY_PATH} /usr/${LIB_DIR})
  message(${path})
  FIND_LIBRARY(CURSES5_NCURSESW_LIBRARY NAMES ncursesw PATHS ${path}/ncurses5 ${path} NO_DEFAULT_PATH)
  FIND_LIBRARY(CURSES5_PANELW_LIBRARY NAMES panelw PATHS ${path}/ncurses5 ${path} NO_DEFAULT_PATH)
  FIND_LIBRARY(CURSES5_TINFO_LIBRARY NAMES tinfo PATHS ${path}/ncurses5 ${path} NO_DEFAULT_PATH)
ENDFOREACH()

SET(CURSES5_LIBRARIES ${CURSES5_NCURSESW_LIBRARY} ${CURSES5_PANELW_LIBRARY})
# tinfo is optional (in 12.1 is not there)
IF(${CURSES5_TINFO_LIBRARY})
  SET(CURSES5_LIBRARIES "${CURSES5_LIBRARIES} ${CURSES5_TINFO_LIBRARY}")
ENDIF(${CURSES5_TINFO_LIBRARY})

FIND_PATH(CURSES5_INCLUDE_DIR ncurses.h PATH_SUFFIXES ncurses5)

SET( CURSES5_DEFINITIONS "-DNCURSES_INTERNALS=1" )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Curses5  DEFAULT_MSG
                                  CURSES5_LIBRARIES CURSES5_INCLUDE_DIR)

MARK_AS_ADVANCED(CURSES5_INCLUDE_DIR CURSES5_LIBRARIES CURSES5_DEFINITIONS)
