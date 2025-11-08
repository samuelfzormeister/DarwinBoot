target("libcms")
    set_basename("cms")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_files("../cms/*.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
