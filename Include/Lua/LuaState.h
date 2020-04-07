#pragma once

#include "LuaDllExport.h"
#include "Lua/LuaHeaders.h"
#include "FileSystem/Path.h"


namespace Celeste::Lua
{
  class LuaState
  {
    public:
      LuaDllExport static sol::state& instance();
      LuaDllExport static sol::protected_function_result script(const std::string& code);
      LuaDllExport static sol::protected_function_result scriptFile(const Path& path);
      LuaDllExport static sol::protected_function_result requireModule(const std::string& moduleName);

      LuaDllExport static void appendToLuaPackagePath(const Path& pathToAppend);
      LuaDllExport static void appendToLuaPackagePath(const std::string& pathToAppend);

    private:
      LuaState();
      ~LuaState() = default;
      LuaState(const LuaState&) = delete;
      LuaState& operator=(const LuaState&) = delete;

      sol::state m_state;
  };
}