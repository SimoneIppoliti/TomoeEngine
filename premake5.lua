workspace "TomoeEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TomoeEngine"
    location "TomoeEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TOMOE_PLATFORM_WINDOWS",
            "TOMOE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "TOMOE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TOMOE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TOMOE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "TomoeEngine/src",
        "TomoeEngine/vendor/spdlog/include"
    }

    links
    {
        "TomoeEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TOMOE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TOMOE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TOMOE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TOMOE_DIST"
        optimize "On"
