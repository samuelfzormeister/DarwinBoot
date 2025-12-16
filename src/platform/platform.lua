target("libplatform")
    set_kind("static")
    set_basename("platform")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_deps("libc", "libefi", "libprintf", "libsb", "libpanic")

    add_files("common/*.c")

    if is_plat("uefi") then
        add_files("uefi/*.c")
        set_extension(".lib")
        set_prefixname("")
    end
