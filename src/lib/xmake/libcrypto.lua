target("libcrypto")
    set_basename("crypto")
    set_kind("static")
    set_languages("c17")
    add_includedirs("$(projectdir)/include", "$(projectdir)/External/corecrypto/include")

    add_deps("libcorecrypto_darwinboot")

    add_files("../crypto/*.c")

    if is_plat("uefi") then
        set_extension(".lib")
        set_prefixname("")
    end
