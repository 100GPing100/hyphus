//
// Created by Super on 21/08/2016.
//

#ifndef HYPHUS_LUASTATE_H
#define HYPHUS_LUASTATE_H


// std
#include <string>

// lua
#include <lua/lua.hpp>


namespace hyphus {
    class LuaState final {
    public:
        operator lua_State *() const {
            return L;
        }

        LuaState();
        ~LuaState();

    private:
        lua_State * L;
    };
}


#endif //HYPHUS_LUASTATE_H
