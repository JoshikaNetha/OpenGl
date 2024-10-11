#include<iostream>
using namespace std;

#include <glad/glad.h>  
/*before glfw The include file for GLAD includes the required OpenGL headers behind the scenes 
(like GL/gl.h) so be sure to include GLAD before other header files that require OpenGL (like GLFW). */
#include <GLFW/glfw3.h>
int main(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(400,300,"BasicWindow",NULL,NULL);
    if(window==NULL){
        glfwTerminate();
        return 0;
    } 
    glfwMakeContextCurrent(window);

    glfwTerminate();
    return 0;
}