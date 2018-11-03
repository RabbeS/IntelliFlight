# includes uclog framework
find_file(UCLOG_DRIVER_DIR "lib/uclog" "${CMAKE_CURRENT_SOURCE_DIR}")
if (UCLOG_DRIVER_DIR STREQUAL "UCLOG_DRIVER_DIR-NOTFOUND")
    message(FATAL_ERROR "Could not locate lib/uclog directory")
endif ()

include_directories(${UCLOG_DRIVER_DIR})

file(GLOB_RECURSE UCLOG_DRIVER_FILES ${UCLOG_DRIVER_DIR}/*.hpp ${UCLOG_DRIVER_DIR}/*.cpp ${UCLOG_DRIVER_DIR}/*.h ${UCLOG_DRIVER_DIR}/*.c)

add_library(UCLOG STATIC ${UCLOG_DRIVER_FILES})

