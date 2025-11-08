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
        "$(projectdir)/External/printf/printf.c"
    )

    add_defines("PRINTF_DISABLE_SUPPORT_FLOAT=1", "PRINTF_DISABLE_SUPPORT_EXPONENTIAL=1")

target("libcorecrypto_darwinboot")
    set_basename("corecrypto_darwinboot")
    set_languages("c17")
    set_kind("static")
    add_includedirs(
        "$(projectdir)/include",
        "$(projectdir)/External/corecrypto/include"
    )

    add_defines("DARWINBOOT=1")

    if is_plat("uefi") then
        set_prefixname("")
        set_extension(".lib")
    end

    add_files(
        "$(projectdir)/External/corecrypto/src/**.c"
    )

    remove_files(
        "$(projectdir)/External/corecrypto/src/kext/*.c",
        "$(projectdir)/External/corecrypto/src/kprng/*.c",
        "$(projectdir)/External/corecrypto/src/kprng/**.c",
        "$(projectdir)/External/corecrypto/src/test/**.c",
        "$(projectdir)/External/corecrypto/src/user/**.c"
    )
