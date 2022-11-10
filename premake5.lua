workspace "Mist"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"] = "Mist/vendor/GLFW/include"
IncludeDir["Glad"] = "Mist/vendor/Glad/include"
IncludeDir["ImGui"] = "Mist/vendor/imgui"
IncludeDir["glm"] = "Mist/vendor/glm"

group "Dependencies"
	include "Mist/vendor/GLFW"
	include "Mist/vendor/Glad"
	include "Mist/vendor/imgui"

group ""

project "Mist"
	location "Mist"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mtpch.h"
	pchsource "Mist/src/mtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
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
		cppdialect "C++17"
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
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		runtime "Release"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Mist/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Mist"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"MT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MT_DIST"
		runtime "Release"
		symbols "On"