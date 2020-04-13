#include "TestUtils.h"

#include "Assert/Assert.h"
#include "Assert/NullAsserter.h"
#include "Lua/LuaState.h"
#include "FileSystem/Directory.h"


namespace TestLog
{
  //------------------------------------------------------------------------------------------------
  TEST_MODULE_INITIALIZE(TestLua_Initialize)
  {
    Celeste::Assertion::setAsserter(std::make_unique<Celeste::NullAsserter>());

    Celeste::Path testLuaScripts(Celeste::Directory::getExecutingAppDirectory(), UPDIR_STRING, UPDIR_STRING, UPDIR_STRING,
      "Celeste", "Lua", "Tests", "Resources", "Scripts", "?.lua;");
    Celeste::Lua::LuaState::appendToLuaPackagePath(testLuaScripts);
  }
}