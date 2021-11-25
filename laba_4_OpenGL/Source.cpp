#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

//    / NODEFAULTLIB:"MSVCRT"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



using namespace std;





GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,

	 0.0f,  0.0f, 0.5f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,


	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.0f, 0.5f,

	-0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,
	 0.0f,  0.0f, 0.5f
};

GLfloat color[]{

	1.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,

	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,

	0.7f, 0.2f, 0.6f,
	0.7f, 0.2f, 0.6f,
	0.7f, 0.2f, 0.6f,

	0.4f, 0.4f, 0.5f,
	0.4f, 0.4f, 0.5f,
	0.4f, 0.4f, 0.5f
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



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if ((key == GLFW_KEY_A) && (action == GLFW_REPEAT)) {
		for (int i = 0; i < 44; i++)
		{
			//glLoadIdentity();
			//colors[i] = colors[i] + 0.1;
			//

		}
	}
	if ((key == GLFW_KEY_A) && (action == GLFW_RELEASE))
	{
		for (int i = 0; i < 44; i++)
		{
			//colors[i] = colors[i] - 0.1;

		}
	}

};


void mouse_place(GLFWwindow* window, double xPos, double yPos) {

	/*cout << xPos << "  " << yPos << endl;*/

	for (int i = 16; i < 27; i++)
	{


		//colors[i] = xPos / 1000.0;
		//cout << colors[i] << "  " << i << endl;
	}

};


int main() {

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);
	

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_place);

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
	
	
	
	int f = 0;

	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);

		f++;

		//glm::mat4 MatModel = glm::rotate(glm::mat4(1.0f), glm::radians(f * 1.0), glm::vec3(1.0, 2.0, 3.0));
		glm::mat4 MatModel = glm::mat4(1.0f);
		//GLint glGetUniformLocation(Program, MatModel);
		//glUniformMatrix(glGetUniformLocation(MatModel, 1, NULL, GLFloat value_ptr(mat4 & mat)));

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(Program);



		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 12);

	


	

		//oooo


		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glDeleteProgram(Program);
	glfwTerminate();

	



	return 1;
}
