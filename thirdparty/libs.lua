target("libprintf")
    set_basename("printf")
    add_includedirs("$(projectdir)/include")
    set_languages("c17")
    set_kind("static")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/thirdparty/printf/printf.c"
    )

    add_defines("PRINTF_DISABLE_SUPPORT_FLOAT=1", "PRINTF_DISABLE_SUPPORT_EXPONENTIAL=1")

target("libcorecrypto_darwinboot")
    set_basename("corecrypto_darwinboot")
    set_languages("c17")
    set_kind("static")
    add_includedirs(
        "$(projectdir)/include",
        "$(projectdir)/thirdparty/corecrypto/include"
    )

    add_defines("DARWINBOOT=1")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/thirdparty/corecrypto/src/**.c"
    )

    remove_files(
        "$(projectdir)/thirdparty/corecrypto/src/kext/*.c",
        "$(projectdir)/thirdparty/corecrypto/src/kprng/*.c",
        "$(projectdir)/thirdparty/corecrypto/src/kprng/**.c",
        "$(projectdir)/thirdparty/corecrypto/src/test/**.c",
        "$(projectdir)/thirdparty/corecrypto/src/user/**.c"
    )

target("libcsum")
    set_basename("csum")
    add_includedirs("$(projectdir)/include")
    set_languages("c17")
    set_kind("static")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/thirdparty/csum/*.c"
    )

target("liblzfse")
    set_basename("lzfse")
    add_includedirs("$(projectdir)/include")
    set_languages("c17")
    set_kind("static")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/thirdparty/lzfse/src/*.c"
    )

    remove_files(
        "$(projectdir)/thirdparty/lzfse/src/lzfse.c"
    )

target("liblzss")
    set_basename("lzss")
    add_includedirs("$(projectdir)/include")
    set_languages("c17")
    set_kind("static")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/thirdparty/lzss/*.c"
    )
