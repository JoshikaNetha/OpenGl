#include "Texture.h"

Texture::Texture(const char *image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType)
{
    // Assigns the type of the texture ot the texture object
	type = texType;

    int widthImg, heightImg, numColCh;
	// Flips the image so it appears right side up
	stbi_set_flip_vertically_on_load(true);

    unsigned char* bytes=stbi_load(image,&widthImg, &heightImg, &numColCh, 0);

	std::cout<<"NUMBER OF CHANNELS"<<numColCh;


    glGenTextures(1,&ID);
    glActiveTexture(GL_TEXTURE0 +slot);
	unit = slot;

	glBindTexture(texType, ID);
    glTexParameteri(texType,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(texType,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

   	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// // Extra lines in case you choose to use GL_CLAMP_TO_BORDER
	// float flatColor[] = {1.0f, 0.0f, 1.0f, 1.0f};
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	if (numColCh == 3)
    	glTexImage2D(texType, 0, GL_RGB, widthImg, heightImg, 0, GL_RGB, pixelType, bytes);
	else if (numColCh == 4)
    	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, pixelType, bytes);

	// Generates MipMaps
	glGenerateMipmap(texType);

	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
    
}

void Texture::texUnit(Shader &shader, const char *uniform, GLuint unit)
{
    // Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
	glUniform1i(texUni, unit);

}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D,ID);
}

void Texture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D,0);
}
void Texture::Delete()
{
    glDeleteTextures(1,&ID);
}