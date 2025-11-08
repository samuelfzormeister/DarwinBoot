target("libefi")
    set_basename("efi")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_files("../efi/*.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
