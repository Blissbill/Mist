workspace "Mist"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
startproject "Sandbox"

IncludeDir = {}
IncludeDir["GLFW"] = "Mist/vendor/GLFW/include"
IncludeDir["Glad"] = "Mist/vendor/Glad/include"
IncludeDir["ImGui"] = "Mist/vendor/imgui"

include "Mist/vendor/GLFW"
include "Mist/vendor/Glad"
include "Mist/vendor/imgui"

project "Mist"
	location "Mist"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mtpch.h"
	pchsource "Mist/src/mtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MT_PLATFORM_WINDOWS", 
			"MT_BUILD_DLL",
			"MT_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		buildoptions "/MD"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"Mist/vendor/spdlog/include",
		"Mist/src"
	}

	links
	{
		"Mist"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		buildoptions "/MD"
		symbols "On"