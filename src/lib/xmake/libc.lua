target("libc")
    set_basename("c")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_deps("libcms", "libprintf")

    add_files("../c/**.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
