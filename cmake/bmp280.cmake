
# includes BMP280 driver

find_file(BMP280_DRIVER_DIR "lib/BMP280_driver" "${CMAKE_CURRENT_SOURCE_DIR}")
if (BMP280_DRIVER_DIR STREQUAL "BMP280_DRIVER_DIR-NOTFOUND")
    message(FATAL_ERROR "Could not locate lib/BMP280_driver directory")
endif ()

link_directories(${BMP280_DRIVER_DIR})
include_directories(SYSTEM ${BMP280_DRIVER_DIR})

