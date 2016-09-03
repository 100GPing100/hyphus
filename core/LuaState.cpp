//
// Created by Super on 21/08/2016.
//

#include "LuaState.h"


// std
#include <stdexcept>


namespace hyphus {
    LuaState::LuaState() {
        L = luaL_newstate();

        if (L == nullptr) {
            throw std::runtime_error("Failed to create Lua state.");
        }
    }

    LuaState::~LuaState() {
        lua_close(L);
    }
}