#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include <iostream>
#include <fstream>
#include <cerrno>
#include <sstream>
#include <string>
#include <glad/glad.h>
using namespace std;

class Shader{
    public:
    GLuint ID;
    Shader(const char* vertexFile,const char* fragmentFile);
    string get_file_contents(const char* fileName);
    void Activate();
    void Delete();
};
#endif