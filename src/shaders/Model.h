#ifndef MODEL_CLASS
#define MODEL_CLASS

#include <json.h>
#include <Mesh.h>
#include <string>
#include <vector>

using json = nlohmann::json ;
using namespace std;

class Model{
public:

    Model(const char* file);
    void Draw(Shader& shader,Camera& camera);

private:
    const char* file;
    vector<unsigned char> data;
    json JSON;

    	// All the meshes and transformations
	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::quat> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;

	// Prevents textures from being loaded twice
	std::vector<std::string> loadedTexName;
	std::vector<Texture> loadedTex;

	// Loads a single mesh by its index
	void loadMesh(unsigned int indMesh);

	// Traverses a node recursively, so it essentially traverses all connected nodes
	void traverseNode(unsigned int nextNode, glm::mat4 matrix = glm::mat4(1.0f));


    vector<unsigned char> getData();

    vector<float> getFloats(json accessor);  //bufferView
    vector<GLuint> getIndices(json accessor);  // bufferView
	std::vector<Texture> getTextures();

	// Assembles all the floats into vertices
	std::vector<Vertex> assembleVertices
	(
		std::vector<glm::vec3> positions, 
		std::vector<glm::vec3> normals, 
		std::vector<glm::vec2> texUVs
	);
    
    vector<glm::vec2> groupFloatsVec2(vector<float> floatVec);
    vector<glm::vec3> groupFloatsVec3(vector<float> floatVec);
    vector<glm::vec4> groupFloatsVec4(vector<float> floatVec);

};
#endif 