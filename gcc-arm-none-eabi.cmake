set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX arm-none-eabi)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
set(CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/11.3 rel1/bin")
set(CMAKE_FIND_ROOT_PATH  ${CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH})

set(FLAGS -ffunction-sections 
        -fdata-sections
        -Wall 
        -fstack-usage  
        --specs=nano.specs
        -march=armv7e-m)
set(CPP_FLAGS -fno-exceptions 
        -fno-threadsafe-statics 
        -fno-rtti
        -march=armv7e-m)


set(CMAKE_C_COMPILER  ${CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH}/${TOOLCHAIN_PREFIX}-gcc.exe ${FLAGS})
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER} )
set(CMAKE_CXX_COMPILER ${CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH}/${TOOLCHAIN_PREFIX}-g++.exe ${CPP_FLAGS})
set(CMAKE_OBJCPY ${CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH}/${TOOLCHAIN_PREFIX}-objcopy.exe)
set(CMAKE_SIZE ${CMAKE_CROSSCOMPILER_TOOLCHAIN_BIN_PATH}/${TOOLCHAIN_PREFIX}-size.exe)


set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM     NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY     ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE     ONLY)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

