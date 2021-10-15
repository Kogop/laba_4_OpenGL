#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


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

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);


	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


	//	glUseProgram(Program);
	//	glBindVertexArray(VAO);

	//	glDrawArrays(GL_TRIANGLES, 0, 3);





		//glDeleteProgram(Program);

		//oooo


		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();





	return 1;
}
