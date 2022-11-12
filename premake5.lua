workspace "Forge"
	architecture "x64"
	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
premake.path = "scripts/cmake-premake/;scripts/premake-clion/"

require "cmake"
require "clion"

project "Forge"
	location "Forge"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs {
		"%{prj.name}/vendors/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FORGE_PLATFORM_WINDOWS",
			"FORGE_BUILD_DLL"
		}

		postbuildcommands {
			("copy %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines { "FORGE_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "FORGE_RELEASE" }
		optimize "On"

	filter "configurations:Distribution"
		defines { "FORGE_DISTRIBUTION" }
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs {
		"Forge/vendors/spdlog/include",
		"Forge/src"
	}

	links {
		"Forge"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FORGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "FORGE_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "FORGE_RELEASE" }
		optimize "On"

	filter "configurations:Distribution"
		defines { "FORGE_DISTRIBUTION" }
		optimize "On"
