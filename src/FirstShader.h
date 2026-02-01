#pragma once
#include "Shaders.h"
class FirstShader : public Shaders
{
public:
	FirstShader();
	~FirstShader();

    void Start() override;
    void Update() override;
    void ImGuiRender(GLFWwindow* window) override;
    void Render() override;
    void Exit() override;
    static FirstShader* GetInstance();

private:
	static FirstShader instance;

	unsigned int VAO, VBO, shaderProgram;
	bool wireframeMode = false;

	// == Vertex Shader ==
	const char* vertexShaderSource = "";

	//// == Fragment Shader ==
	const char* fragmentShaderSource = "";
};

