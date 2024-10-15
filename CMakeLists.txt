cmake_minimum_required(VERSION 3.16.3)
project(openGlWindow VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/shaders)
include_directories(${CMAKE_SOURCE_DIR}/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/glm/glm)


add_executable(openGlWindow
# src/main.cpp
# src/mainVersion_1.cpp
# src/mainTwoTriangle.cpp
# src/mainTexture.cpp
# src/mainWindow.cpp
# src/mainTriangle.cpp
# src/shaders/mainShader.h
# src/organizer.cpp
# src/main_Texture.cpp
# src/mainTransformation.cpp
src/mainCamera.cpp
src/shaders/ShaderClass.h
src/shaders/VAO.h
src/shaders/EBO.h
src/shaders/VBO.h
src/shaders/Texture.h
src/shaders/Camera.h
src/shaders/ShaderClass.cpp
src/shaders/VAO.cpp
src/shaders/EBO.cpp
src/shaders/VBO.cpp
src/shaders/stb.cpp
src/shaders/Texture.cpp
src/shaders/Camera.cpp
src/stb_image.h
glad/src/glad.c)

# Include GLM and GLFW headers
include_directories("/usr/include/GLFW")
include_directories("/usr/include/glm")
include_directories("/usr/include/GL/")


# Link against GL
find_package(GLEW REQUIRED)
target_link_libraries(openGlWindow PRIVATE GLEW::GLEW)

# Link against GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(openGlWindow PRIVATE glfw GLU dl)

find_package(OpenGL REQUIRED)
target_link_libraries(openGlWindow PRIVATE OpenGL::GL)


# You do not need to link against GLM since it's a header-only library
# No need to set CMAKE_PREFIX_PATH for GLM since we're only including headers
