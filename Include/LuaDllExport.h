#pragma once

#include "Platform/Platform.h"

#ifdef BUILDING_LUA_DLL
#define LuaDllExport __declspec(dllexport)
#else
#define LuaDllExport __declspec(dllimport)
#endif
