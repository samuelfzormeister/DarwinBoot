target("boot")
    set_kind("binary")
    set_languages("c17")
    add_includedirs("$(projectdir)/include")

    add_deps("libplatform")

    add_files("../boot/*.c")

    add_defines("APP_BOOT=1")

    if is_plat("uefi") then
        set_extension(".efi")

        on_install(function(target)
            os.cp(target:targetfile(), path.join(target:installdir(), "System/Library/CoreServices/", target:basename()))
        end)
    end
