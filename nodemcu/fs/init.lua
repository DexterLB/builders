function reflash()
    local result = node.flashreload("lfs.img")
    print(result)
    return result
end

if pcall(node.flashindex("_init")) then
    require('begin')
    begin()
else
    print('No LFS found.')
end
