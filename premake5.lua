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
IncludeDir["glm"] = "TomoeEngine/vendor/glm"

group "Dependencies"
    include "TomoeEngine/vendor/GLFW"
    include "TomoeEngine/vendor/Glad"
    include "TomoeEngine/vendor/imgui"

group ""

project "TomoeEngine"
    location "TomoeEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tomoepch.h"
    pchsource "TomoeEngine/src/tomoepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "TOMOE_PLATFORM_WINDOWS",
            "TOMOE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
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
    cppdialect "C++20"
    staticruntime "On"

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
        "TomoeEngine/vendor/spdlog/include",
        "TomoeEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "TomoeEngine"
    }

    filter "system:windows"
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