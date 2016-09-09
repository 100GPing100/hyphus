//
// Created by Super on 21/08/2016.
//

#ifndef HYPHUS_LUASTATE_H
#define HYPHUS_LUASTATE_H


// std
#include <string>
#include <tuple>

// lua
#include <lua/lua.hpp>


namespace hyphus {
    struct LuaLoadResult {
        enum Value_t {
            Success = 0,
            FileError = LUA_ERRFILE,
            SyntaxError = LUA_ERRSYNTAX,
            MemoryError = LUA_ERRMEM,
        };

        const Value_t value() const { return _val; }
        const std::string message() const { return _msg; }

        LuaLoadResult(Value_t val, const std::string & msg)
                : _val(val), _msg(msg) { }

    private:
        Value_t _val;
        std::string _msg;
    };

    enum class LuaLib : uint16_t {
        None        = 0x000,

        Base        = 0x001, // ""
        Coroutine   = 0x002, // LUA_COLIBNAME
        Table       = 0x004, // LUA_TABLIBNAME
        IO          = 0x008, // LUA_IOLIBNAME


        OS          = 0x010, // LUA_OSLIBNAME
        String      = 0x020, // LUA_STRLIBNAME
        UTF8        = 0x040, // LUA_UTF8LIBNAME
        Math        = 0x080, // LUA_MATHLIBNAME

        Debug       = 0x100, // LUA_DBLIBNAME
        Package     = 0x200, // LUA_LOADLIBNAME

        All         = 0x3FF,

        // bits32 - deprecated
    };

    class LuaState final {
    public:
        template<typename ... T>
        struct _ret {
            typedef typename std::tuple<T ...> type;

            static type pop_get(LuaState & state) {
                return _pop_get<T ...>(state, static_cast<int>(-sizeof...(T)));
            }

        private:
            template<typename U, typename ... Args>
            static typename _ret<U, Args ...>::type _pop_get(LuaState & state, int index) {
                return std::tuple_cat(state.to<U>(index), _pop_get<Args ...>(state, index + 1));
            }
        };

        template<typename T>
        struct _ret<T> {
            typedef T type;

            static type pop_get(LuaState & state) {
                type val = state.to<type>(-1);
                lua_pop(state._l, 1);
                return val;
            }
        };

        LuaLoadResult load(const std::string & filename);

        template<typename T, typename ... Args>
        inline void push(const T value, const Args ... values) {
            _push(value);
            _push(values ...);
        };

        template<typename T>
        inline void push(const T value) {
            _push(value);
        }

        template<typename ... Ret, typename ... Args>
        typename _ret<Ret ...>::type call(const std::string & name, Args ... args) {
            lua_getglobal(_l, name.c_str());

            if (lua_isnil(_l, -1)) {
                throw std::runtime_error("Could not get lua function.");
            }

            push(args ...);

            // @TODO: change to lua_pcall
            lua_call(_l, sizeof...(Args), sizeof...(Ret));

            return _ret<Ret ...>::pop_get(*this);
        };

        template<typename ... Ret, typename ... Args>
        typename _ret<Ret ...>::type call(lua_CFunction fn, Args ... args) {
            lua_pushcfunction(_l, fn);

            push(args ...);
            lua_call(_l, sizeof...(Args), sizeof...(Ret));

            return _ret<Ret ...>::pop_get(*this);
        };

        template<typename T> T to(int index);

        inline void pop(int count) {
            lua_pop(_l, count);
        }

        LuaState(const LuaLib & libs = LuaLib::All);
        ~LuaState();

        LuaState(const LuaState &) = delete; // no copy
        LuaState & operator =(const LuaState &&) = delete; // no move

        void reg(lua_CFunction fn, const std::string & name) {
            lua_pushcfunction(_l, fn);
            lua_setglobal(_l, name.c_str());
        }

    private:
        inline void _push(const int64_t i) { lua_pushinteger(_l, i); }
        inline void _push(const double d) { lua_pushnumber(_l, d); }
        inline void _push(const std::string & str) { lua_pushstring(_l, str.c_str()); }
        inline void _push(const char * str) { lua_pushstring(_l, str); }
        inline void _push(const bool b) { lua_pushboolean(_l, b); }
        inline void _push(const decltype(nullptr)) { lua_pushnil(_l); }

        void _openlibs(const LuaLib & libs);

        lua_State * _l;
    };


    template<>
    struct LuaState::_ret<void> {
        typedef void type;

        static type pop_get(LuaState & state) { }
    };

    template<>
    struct LuaState::_ret<> {
        typedef void type;

        static type pop_get(LuaState & state) { }
    };


    static LuaLib operator |(LuaLib a, LuaLib b) {
        return static_cast<LuaLib>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b));
    }
    static LuaLib operator &(LuaLib a, LuaLib b) {
        return static_cast<LuaLib>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b));
    }
    static bool operator %(LuaLib a, LuaLib b) {
        return (static_cast<uint16_t>(a) & static_cast<uint16_t>(b)) == static_cast<uint16_t>(b);
    }
}


#endif //HYPHUS_LUASTATE_H
