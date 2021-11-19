#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};
GLfloat color[]{

	1.0, 0.5, 0.5,
	0.0, 0.5, 0.5,
	0.5, 0.5, 0.5
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	//glViewport(0, 0, 600, 600);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main() {

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);


	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	string shaderCode;
	ifstream shaderFile;
	stringstream shaderStream;
	shaderFile.open("Top_shade.cpp");
	shaderStream << shaderFile.rdbuf();
	shaderFile.close();
	shaderCode = shaderStream.str();
	const char* ShaderSource = shaderCode.c_str();


	string shaderCode1;
	ifstream shaderFile1;
	stringstream shaderStream1;
	shaderFile1.open("Frag_shade.cpp");
	shaderStream1 << shaderFile1.rdbuf();
	shaderFile1.close();
	shaderCode1 = shaderStream1.str();
	const char* ShaderSource1 = shaderCode1.c_str();


	GLuint Top_shade = glCreateShader(GL_VERTEX_SHADER);
	GLuint Frag_shade = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(Top_shade, 1, &ShaderSource, NULL);
	glShaderSource(Frag_shade, 1, &ShaderSource1, NULL);

	glCompileShader(Top_shade);
	glCompileShader(Frag_shade);
	GLint status;

	glGetShaderiv(Top_shade, GL_COMPILE_STATUS, &status);
	if (status)
	{
		cout << "top rabotaet" << endl;
	}
	else {
		int length;
		glGetShaderiv(Top_shade, GL_INFO_LOG_LENGTH, &length);
		char* info_log = new char[length];
		glGetShaderInfoLog(Top_shade, length, NULL, info_log);
		cout << info_log << endl;
	}

	glGetShaderiv(Frag_shade, GL_COMPILE_STATUS, &status);
	if (status)
	{
		cout << "Frag rabotaet" << endl;
	}
	else {
		int length;
		glGetShaderiv(Frag_shade, GL_INFO_LOG_LENGTH, &length);
		char* info_log = new char[length];
		glGetShaderInfoLog(Frag_shade, length, NULL, info_log);
		cout << info_log << endl;
	}


	GLuint Program = glCreateProgram();
	glAttachShader(Program, Top_shade);
	glAttachShader(Program, Frag_shade);
	glLinkProgram(Program);

	glGetProgramiv(Program, GL_LINK_STATUS, &status);
	if (status)
	{
		cout << "Programma rabotaet" << endl;
	}
	else {
		int length;
		glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &length);
		char* info_log = new char[length];
		glGetProgramInfoLog(Program, length, NULL, info_log);
		cout << info_log << endl;
	}

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	GLuint VBO1, VBO2;
	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(Program);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);





		//glDeleteProgram(Program);

		//oooo


		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();





	return 1;
}
