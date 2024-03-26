cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME PhysicsProject)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)

include_directories(
	include/
)

set(
    all_headers
    include/Core/core.h
    include/Core/Window.h
	include/Core/Application.h
    include/Core/Logger.h
    include/Core/EntryPoint.h
    include/Core/Layer.h
    include/Core/LayerStack.h
	include/Core/Timestep.h
)

set(
    all_src
	src/Core/EntryPoint.cpp
    src/Core/Window.cpp
	src/Core/Application.cpp
    src/Core/Logger.cpp
    src/Core/Layer.cpp
    src/Core/LayerStack.cpp
	Sandbox.cpp
)

# Finding SFML 2
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME} ${all_src} ${all_headers})


target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    sfml-system sfml-window sfml-graphics
	fmt::fmt
	spdlog::spdlog
)
