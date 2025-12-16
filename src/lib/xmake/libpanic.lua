target("libpanic")
    set_basename("panic")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_deps("libc")

    add_files("../panic/*.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
