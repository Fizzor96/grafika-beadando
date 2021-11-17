cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)
project(GrafikaBeadando)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")

file(GLOB App_SRC
		"src/*.h",
		"src/*.cpp",
		"src/components/*.h",
		"src/components/*.cpp",
		"src/components/Algo/*.h",
		"src/components/Algo/*.cpp",
		"src/components/Core/*.h",
		"src/components/Core/*.cpp",
		"src/components/Objects/*.h",
		"src/components/Objects/*.cpp",
		"src/components/Primitives/*.h",
		"src/components/Primitives/*.cpp",
		"src/components/UI/*.h",
		"src/components/UI/*.cpp",
		"src/controller/*.h",
		"src/controller/*.cpp",
		"src/view/*.h",
		"src/view/*.cpp"
		)


IF (WIN32)
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "deps/win/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${App_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/components)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/view)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/controller)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ELSE()
	set(SFML_DIR "deps/linux/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${App_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/components)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/view)
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/controller)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ENDIF()
