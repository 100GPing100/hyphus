--
-- Created by IntelliJ IDEA.
-- User: 100GPing100
-- Date: 07/09/2016
-- Time: 10:46
-- To change this template use File | Settings | File Templates.
--

function on_key(key)
    if key == "r" then
        set_background("red")
    elseif key =="g" then
        set_background("green")
    elseif key == "b" then
        set_background("blue")
    else
        print("unhandled key '"..key.."'")
    end
end

