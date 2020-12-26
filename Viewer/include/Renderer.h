#pragma once
#include "Scene.h"
#include <glad/glad.h>
#include <glm/glm.hpp>

class Renderer
{
public:
	Renderer(int viewportWidth, int viewportHeight);
	
	virtual ~Renderer();
	void Render(const Scene& scene);
	void SwapBuffers();
	void ClearColorBuffer(const glm::vec3& color);
	int GetViewportWidth() const;
	int GetViewportHeight() const;
	void Scan_andset_Zbuffer(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
	void Set_ZBuffertoMax();
	void Set_Z_value(int i, int j, float z);
	float Get_Z_value(int i, int j);
	float Calc_z(int x, int y, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
	float Calc_area(int x1, int y1, float x2, float y2, float x3, float y3);
	bool IsInsidetheTrianle( int x, int y,int x1, int y1, int x2, int y2, int x3, int y3);
	glm::vec3 Get_GrayColor(float z);
	void filltheTriangles();
	void fillthewith_RandomColor(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
	

	
	
private:
	void PutPixel(const int i, const int j, const glm::vec3& color);
	void DrawLine(const glm::ivec2& p1, const glm::ivec2& p2, const glm::vec3& color);

	void CreateBuffers(int w, int h);
	void CreateOpenGLBuffer();
	void InitOpenGLRendering();

	float* color_buffer_;
	int viewport_width_;
	int viewport_height_;
	GLuint gl_screen_tex_;
	GLuint gl_screen_vtc_;
	float maxbufferZ = std::numeric_limits<float>::min(); //
	float minbufferZ = std::numeric_limits<float>::max();; //
	float* z_buffer_;

};
