set(INCLUDES 
    ${THIRD_PARTY_DIR}/lua/src
    ${THIRD_PARTY_DIR}/lua/build    #for luaconf.h
    )

set(LIBS 
    liblua
    sol2
    Assert
    Log
    FileSystem)

build_library(NAME Lua FOLDER Celeste TYPE SHARED INCLUDES "${INCLUDES}" LIBS "${LIBS}")

target_compile_definitions(Lua PRIVATE -DBUILDING_LUA_DLL)