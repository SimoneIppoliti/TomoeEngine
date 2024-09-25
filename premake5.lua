workspace "TomoeEngine"
    architecture "x64"
    
    startproject "Sandbox"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "TomoeEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "TomoeEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "TomoeEngine/vendor/imgui"

group "Dependencies"
    include "TomoeEngine/vendor/GLFW"
    include "TomoeEngine/vendor/Glad"
    include "TomoeEngine/vendor/imgui"

group ""

project "TomoeEngine"
    location "TomoeEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tomoepch.h"
    pchsource "TomoeEngine/src/tomoepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "TOMOE_PLATFORM_WINDOWS",
            "TOMOE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "TOMOE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "TOMOE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "TOMOE_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"

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
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "TOMOE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TOMOE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "TOMOE_RELEASE"
        runtime "Release"
        optimize "On"
        
        filter "configurations:Dist"
        defines "TOMOE_DIST"
        runtime "Release"
        optimize "On"
