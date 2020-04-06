cmake_minimum_required(VERSION 3.6)

##---------------------------- Globals ----------------------------##
project(Lua)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
IF(NOT DEFINED CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
ENDIF()

##---------------------------- end Globals ----------------------------##


##------------------------------ Lua ------------------------------##
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.c ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.hpp)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})						   
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    FOLDER "Celeste"
    CXX_STANDARD 17)
    
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${LUA_PROJECT_DIR}/src
    ${LUA_PROJECT_DIR}/build    #for luaconf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Include)

target_link_libraries(${PROJECT_NAME} PUBLIC
    liblua
    sol2
    FileSystem)

target_compile_options(${PROJECT_NAME} PRIVATE /MP4 /W4 /WX)