set(INCLUDES 
    ${LUA_PROJECT_DIR}/src
    ${LUA_PROJECT_DIR}/build    #for luaconf.h
    )

set(LIBS 
    liblua
    sol2
    Assert
    Log
    FileSystem)

build_library(NAME Lua FOLDER Celeste/Packages TYPE SHARED INCLUDES "${INCLUDES}" LIBS "${LIBS}")

target_compile_definitions(Lua PRIVATE -DBUILDING_LUA_DLL)