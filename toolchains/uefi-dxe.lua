toolchain("uefi-dxe")
set_kind("standalone")

set_toolset("cc", "clang")
set_toolset("cxx", "clang++", "clang++")
set_toolset("ld", "lld-link", "lld-link")     -- Use LLVM's PE/COFF linker
set_toolset("sh", "clang++", "clang")
set_toolset("ar", "ar")                       -- Use the LLVM archiver, this makes the project buildable on Windows.
set_toolset("ex", "ar")
set_toolset("strip", "strip")
set_toolset("mm", "clang")
set_toolset("mxx", "clang", "clang++")
set_toolset("as", "clang")

add_defines("UEFI", "UEFI_DXE=1")

on_check(function(toolchain)
    local ret = import("lib.detect.find_tool")("lld-link")
    if ret then
        return import("lib.detect.find_tool")("clang")
    else
        return nil
    end
end)

on_load(function(toolchain)
    toolchain:add("cflags",
        "-nostdlib",
        "-nostdinc",
        "-nolibc",
        "-mabi=ms",
        "-target x86_64-pc-mingw32-coff",
        "-fno-stack-protector",
        "-fno-stack-clash-protection",
        "-fno-strict-aliasing",
        "-fno-stack-check",
        "-fshort-wchar",
        "-mno-red-zone",
        "-Wno-incompatible-library-redeclaration",
        "-ffreestanding",
        "-Wno-builtin-requires-header",
        "-Wno-incompatible-library-redeclaration",
        "-mno-stack-arg-probe")

    toolchain:add("cxxflags",
        "-nostdlib",
        "-nostdinc",
        "-nolibc",
        "-mabi=ms",
        "-target x86_64-pc-mingw32-coff",
        "-fno-stack-protector",
        "-fno-stack-clash-protection",
        "-fno-strict-aliasing",
        "-fno-stack-check",
        "-fshort-wchar",
        "-mno-red-zone",
        "-Wno-incompatible-library-redeclaration",
        "-ffreestanding",
        "-Wno-builtin-requires-header",
        "-Wno-incompatible-library-redeclaration",
        "-mno-stack-arg-probe",
        "-fno-exceptions",
        "-isystem $(projectdir)/DarwinBoot/include/libcxx/")

    toolchain:add("includedirs", "$(projectdir)/DarwinBoot/include")

    toolchain:add("ldflags", "-subsystem:efi_boot_service_driver -nodefaultlib -dll -entry:platform_main")
end)
toolchain_end()
