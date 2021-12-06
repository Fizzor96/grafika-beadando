cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)
project(GrafikaBeadando)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -Wunused-but-set-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")

file(GLOB App_SRC
		"src/*.h"
		"src/*.cpp"
		"src/Components/*.h"
		"src/Components/*.cpp"
		"src/Components/Algo/*.h"
		"src/Components/Algo/*.cpp"
		"src/Components/Core/*.h"
		"src/Components/Core/*.cpp"
		"src/Components/Objects/*.h"
		"src/Components/Objects/*.cpp"
		"src/Components/Primitives/*.h"
		"src/Components/Primitives/*.cpp"
		"src/Components/UI/*.h"
		"src/Components/UI/*.cpp"
		"src/Controllers/*.h"
		"src/Controllers/*.cpp"
		"src/Views/*.h"
		"src/Views/*.cpp"
		"src/zh/*.h"
		"src/zh/*.cpp"
		"src/zhpractice/*.h"
		"src/zhpractice/*.cpp"
		)

IF (WIN32 AND MINGW)
	add_compile_options(-O3 -g -Wall)
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "deps/win/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${App_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Components)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Views)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Controllers)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/zh)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/zhpractice)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ELSE()
	add_compile_options(-O3 -g -Wall)
	set(SFML_DIR "deps/linux/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${App_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Components)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Views)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/Controllers)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/zh)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/zhpractice)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ENDIF()
