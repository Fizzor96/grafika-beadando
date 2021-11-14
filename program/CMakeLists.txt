cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)
project(GrafikaBeadando)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++ -s")


IF (WIN32)
	file(GLOB WinApp_SRC
		"src/*.h",
		"src/*.cpp",
		"deps/win/SFML-2.5.1/include/*.h",
		"deps/win/SFML-2.5.1/include/*.cpp"
		)
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "deps/win/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${WinApp_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/components)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ELSE()
	file(GLOB LinuxApp_SRC
		"src/*.h",
		"src/*.cpp",
		"deps/linux/SFML-2.5.1/include/*.h",
		"deps/linux/SFML-2.5.1/include/*.cpp"
		)
	set(SFML_DIR "deps/linux/SFML-2.5.1/lib/cmake/SFML")
	find_package (SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${LinuxApp_SRC})
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "cmake_modules/SFML/include")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/components)
	target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-system sfml-audio sfml-window)
ENDIF()
