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

cbt_build_project(NAME Lua FOLDER Celeste TYPE SHARED INCLUDES "${INCLUDES}" LIBS "${LIBS}")