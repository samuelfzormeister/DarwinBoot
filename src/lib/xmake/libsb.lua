target("libsb")
    set_basename("sb")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_files("../sb/*.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
