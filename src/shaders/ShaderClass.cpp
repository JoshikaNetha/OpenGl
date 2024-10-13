#include <ShaderClass.h>
Shader::Shader(const char* vertexFile,const char* fragmentFile){
  string vertexCode = get_file_contents(vertexFile);
  string fragementCode = get_file_contents(fragmentFile);\

  const char* vertexSource = vertexCode.c_str();
  const char* fragementSource = fragementCode.c_str();

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader,1,&vertexSource,NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader,1,&fragementSource,NULL);
  glCompileShader(fragmentShader);

  ID = glCreateProgram();
  glAttachShader(ID,vertexShader);
  glAttachShader(ID,fragmentShader);
  glLinkProgram(ID);

  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);



}
// Reads a text file and outputs a string with everything in the text file
string Shader::get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

void Shader::Activate(){
   glUseProgram(ID);
}
void Shader::Delete(){
   glDeleteProgram(ID);
}