//
// Created by Super on 21/08/2016.
//

#include "LuaState.h"


// std
#include <stdexcept>


namespace hyphus {
    template<> int64_t          LuaState::to<int64_t>(int index) { return lua_tointeger(_l, index); }
    template<> double           LuaState::to<double>(int index) { return lua_tonumber(_l, index); }
    template<> std::string      LuaState::to<std::string>(int index) { return std::string(lua_tostring(_l, index)); }
    template<> const char *     LuaState::to<const char *>(int index) { return lua_tostring(_l, index); }
    template<> bool             LuaState::to<bool>(int index) { return static_cast<bool>(lua_toboolean(_l, index)); }


    LuaLoadResult LuaState::load(const std::string & filename) {
        const LuaLoadResult::Value_t value = static_cast<LuaLoadResult::Value_t>(luaL_loadfile(_l, filename.c_str()));

        if (value == LuaLoadResult::Success) {
            lua_pcall(_l, 0, LUA_MULTRET, 0);
            return LuaLoadResult { value, "Success" };
        }

        const std::string str = to<std::string>(-1);
        pop(1);

        return LuaLoadResult { value, str };
    }

    LuaState::LuaState(const LuaLib & libs) {
        _l = luaL_newstate();

        if (_l == nullptr) {
            throw std::runtime_error("Failed to create Lua state.");
        }

        _openlibs(libs);
    }

    LuaState::~LuaState() {
        lua_close(_l);
    }

    void LuaState::_openlibs(const LuaLib & libs) {
        if (libs == LuaLib::None) {
            return;
        }

        // if (libs == LuaLib::All)
        if (libs % LuaLib::Base) { call(luaopen_base, "_G"); }
        if (libs % LuaLib::Coroutine) { call(luaopen_coroutine, LUA_COLIBNAME); }
        if (libs % LuaLib::Table) { call(luaopen_table, LUA_TABLIBNAME); }
        if (libs % LuaLib::IO) { call(luaopen_io, LUA_IOLIBNAME); }
        if (libs % LuaLib::OS) { call(luaopen_os, LUA_OSLIBNAME); }
        if (libs % LuaLib::String) { call(luaopen_string, LUA_STRLIBNAME); }
        if (libs % LuaLib::UTF8) { call(luaopen_utf8, LUA_UTF8LIBNAME); }
        if (libs % LuaLib::Math) { call(luaopen_math, LUA_MATHLIBNAME); }
        if (libs % LuaLib::Debug) { call(luaopen_debug, LUA_DBLIBNAME); }
        if (libs % LuaLib::Package) { call(luaopen_package, LUA_LOADLIBNAME); }
    }
}