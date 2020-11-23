#pragma once
#include <glm/glm.hpp>
#include <string>
#include "Face.h"

class MeshModel
{
public:
	MeshModel(std::vector<Face> faces, std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, const std::string& model_name, glm::mat4x4 T);
	virtual ~MeshModel();
	const Face& GetFace(int index) const;
	int GetFacesCount() const;
	const std::string& GetModelName() const;
	const glm::vec3 GetVertex(int index) const;
	const glm::mat4x4 GetSTmat() const;
	void PrintFaces() const;
	void PrintVertices()const;
	void Set_Tw_mat(glm::mat4x4& transformation);
	void Set_Rw_mat(glm::mat4x4& transformation);
	void Set_Sw_mat(glm::mat4x4& transformation);
	void Set_Tm_mat(glm::mat4x4& transformation);
	void Set_Rm_mat(glm::mat4x4& transformation);
	void Set_Sm_mat(glm::mat4x4& transformation);
	void Set_transmatrix();
	const glm::mat4x4 Get_transmatrix() const;
	void printmat() const;


private:
	std::vector<Face> faces_;
	std::vector<glm::vec3> vertices_;
	std::vector<glm::vec3> normals_;
	std::string model_name_;
	glm::mat4x4 STmat;
	glm::mat4x4 Tm = glm::mat4(1.0f);
	glm::mat4x4 Tw = glm::mat4(1.0f);
	glm::mat4x4 Rw = glm::mat4(1.0f);
	glm::mat4x4 Sw = glm::mat4(1.0f);
	glm::mat4x4 Rm = glm::mat4(1.0f);
	glm::mat4x4 Sm = glm::mat4(1.0f);
	glm::mat4x4 transmatrix= glm::mat4(1.0f);

};
