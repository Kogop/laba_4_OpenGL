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

//float d[3] = { 0.0f, 0.0f, 1.0f };
//float t[3] = { 0.0f, 0.0f, 0.0f };
//float u[3] = { 0.0f, 1.0f, 0.0f };
//float t[3] = p - d;

float xP = 0.0f;
float yP = 0.0f;
float zP = 2.0f;




glm::vec3 VectorPosition = glm::vec3(xP, yP, zP);
//glm::vec3 VectorNapravlenia = glm::vec3(0.0f, 0.0f, -1.0f);


glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraDirection = glm::normalize(VectorPosition - cameraTarget);
glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

GLfloat vertices[] = {
	-0.5f, -0.5f, 0.0f,    //front
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,

	 0.0f,  0.0f, 0.5f,   //right
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,


	-0.5f, -0.5f, 0.0f,   //bottom
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.0f, 0.5f,

	-0.5f, -0.5f, 0.0f,   //left
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

GLfloat normali[36];


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

	if ((key == GLFW_KEY_W) && (action == GLFW_REPEAT)) {
		
		
		VectorPosition -= cameraDirection * 0.1f;
		
		//for (int i = 0; i < 44; i++)
		//{
			//glLoadIdentity();
			//colors[i] = colors[i] + 0.1;
			//

		//}
	}
	if ((key == GLFW_KEY_S) && (action == GLFW_REPEAT)){


		VectorPosition += cameraDirection * 0.1f;





	//	for (int i = 0; i < 44; i++)
	//	{
			//colors[i] = colors[i] - 0.1;

	//	}
	}

	if ((key == GLFW_KEY_A) && (action == GLFW_REPEAT)) {


		cameraRight = glm::normalize(glm::cross(up, cameraFront));
		VectorPosition += cameraRight * 0.1f;
		//for (int i = 0; i < 44; i++)
		//{
			//glLoadIdentity();
			//colors[i] = colors[i] + 0.1;
			//

		//}
	}
	if ((key == GLFW_KEY_D) && (action == GLFW_REPEAT)) {


		cameraRight = glm::normalize(glm::cross(up, cameraFront));
		VectorPosition -= cameraRight * 0.1f;

		//for (int i = 0; i < 44; i++)
		//{
			//glLoadIdentity();
			//colors[i] = colors[i] + 0.1;
			//

		//}
	}





};

double xMouse = 500.0;
double yMouse = 500.0;

float yaw = -90.0f;
float pitch = 0.0f;
glm::vec3 direction;

bool LastUse = 1;
void mouse_place(GLFWwindow* window, double xPos, double yPos) {

	/*cout << xPos << "  " << yPos << endl;*/

	//for (int i = 16; i < 27; i++)
	//{
	//double xMouseNow = xPos;
	//double yMouseNow = yPos;

	if (LastUse)
	{
		xMouse = xPos;
		yMouse = yPos;
		LastUse = 0;
	}
	else
	{
			


		float xoffset = xPos - xMouse;
		float yoffset = yMouse - yPos; // уменьшаемое и вычитаемое поменяны местами, так как диапазон y-координаты определяется снизу вверх
		xMouse = xPos;
		yMouse = yPos;

		const float sensitivity = 0.05f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;


		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;



		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(direction);
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


	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//glm::vec3 normali[12];
	glm::vec3 n[4];
	for (int i = 0; i < 1; i++)
	{
		glm::vec3 a[12] /*= { {0,0,0},{0,0,0},{0,0,0},{0,0,0} }*/;
		//glm::vec3  b[4];






		//for (int j = 0; j < 9; j = j + 3)
		//{
		//	int k = 0;
		//	// a[j] = vertices[3 * i + j];
		//	// b[i] = vertices[3 * i + j];

			//1
			a[0].x = vertices[0];
			a[0].y = vertices[1];
			a[0].z = vertices[2];

			a[1].x = vertices[3];
			a[1].y = vertices[4];
			a[1].z = vertices[5];

			a[2].x = vertices[6];
			a[2].y = vertices[7];
			a[2].z = vertices[8];
			//2
			a[3].x = vertices[9];
			a[3].y = vertices[10];
			a[3].z = vertices[11];

			a[4].x = vertices[12];
			a[4].y = vertices[13];
			a[4].z = vertices[14];

			a[5].x = vertices[15];
			a[5].y = vertices[16];
			a[5].z = vertices[17];
			//3
			a[6].x = vertices[18];
			a[6].y = vertices[19];
			a[6].z = vertices[20];

			a[7].x = vertices[21];
			a[7].y = vertices[22];
			a[7].z = vertices[23];

			a[8].x = vertices[24];
			a[8].y = vertices[25];
			a[8].z = vertices[26];
			//4
			a[9].x = vertices[27];
			a[9].y = vertices[28];
			a[9].z = vertices[29];

			a[10].x = vertices[30];
			a[10].y = vertices[31];
			a[10].z = vertices[32];

			a[11].x = vertices[33];
			a[11].y = vertices[34];
			a[11].z = vertices[35];


		//	k++;
		//};
			//a[] = { vertices[j],vertices[j + 1], vertices[j + 2] };
			//k++;
			//cout << normali[i] << endl;
		//int k = i;
		//if (k > 2)
		//{
		//	k = 0;
		glm::vec3 v[8];
		v[0] = a[0] - a[1];
		v[1] = a[2] - a[1];

		v[2] = a[3] - a[4];
		v[3] = a[5] - a[4];

		v[4] = a[6] - a[7];
		v[5] = a[8] - a[7];

		v[6] = a[9] - a[10];
		v[7] = a[11] - a[10];


			n[0] = glm::normalize(glm::cross(v[0], v[1])); // front

			n[1] = glm::normalize(glm::cross(v[3], v[2])); // side

			n[2] = glm::normalize(glm::cross(v[5], v[4]));  // bottom

			n[3] = glm::normalize(glm::cross(v[6], v[7])); // side
		//}
			normali[0] = n[0].x;
			normali[1] = n[0].y;
			normali[2] = n[0].z;
			normali[3] = n[0].x;
			normali[4] = n[0].y;
			normali[5] = n[0].z;
			normali[6] = n[0].x;
			normali[7] = n[0].y;
			normali[8] = n[0].z;

			normali[9] = n[1].x;
			normali[10] = n[1].y;
			normali[11] = n[1].z;
			normali[12] = n[1].x;
			normali[13] = n[1].y;
			normali[14] = n[1].z;
			normali[15] = n[1].x;
			normali[16] = n[1].y;
			normali[17] = n[1].z;

			normali[18] = n[2].x;
			normali[19] = n[2].y;
			normali[20] = n[2].z;
			normali[21] = n[2].x;
			normali[22] = n[2].y;
			normali[23] = n[2].z;
			normali[24] = n[2].x;
			normali[25] = n[2].y;
			normali[26] = n[2].z;

			normali[27] = n[3].x;
			normali[28] = n[3].y;
			normali[29] = n[3].z;
			normali[30] = n[3].x;
			normali[31] = n[3].y;
			normali[32] = n[3].z;
			normali[33] = n[3].x;
			normali[34] = n[3].y;
			normali[35] = n[3].z;


	
		//cout << a[i].x << '\t' << a[i].y << '\t' << a[i].z << endl;

		//cout << v[i].x << '\t' <<v[i].y << '\t' << v[i].z << endl;

		cout << n[0].x << '\t' << n[0].y << '\t' << n[0].z << endl;
		cout << n[1].x << '\t' << n[1].y << '\t' << n[1].z << endl;
		cout << n[2].x << '\t' << n[2].y << '\t' << n[2].z << endl;
		cout << n[3].x << '\t' << n[3].y << '\t' << n[3].z << endl;
	}
	







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
	GLuint VBO1, VBO2, VBO3;
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

	glGenBuffers(1, &VBO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normali), normali, GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	
	glEnable(GL_DEPTH_TEST);

	
	
	float f = 0.0;

	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);

		f = f + 1;
		glUseProgram(Program);


		glm::vec3 lightColor = glm::vec3{ 1.0f, 1.0f, 1.0f };
		GLint location3 = glGetUniformLocation(Program, "lightColor");
		glUniform3fv(location3, 1, glm::value_ptr(lightColor));

		glm::vec3 lightPos = glm::vec3{ 0.0f, 0.0f, 1.0f };
		GLint location4 = glGetUniformLocation(Program, "LightPos");
		glUniform3fv(location4, 1, glm::value_ptr(lightPos));



		//glm::mat4 MatVida = glm::mat4(1.0f);
		glm::mat4 MatVida = glm::lookAt(VectorPosition, VectorPosition + cameraFront , cameraUp);
		glm::mat4 MatPerspective = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
		//TODO   sdelat d MatVida kajdiy vector otdelnim, chtobi mojno bilo menyat pri dvijenii kameri. 

		glm::mat4 MatModel = glm::rotate(glm::mat4(1.0f), glm::radians(f * 1.0f), glm::vec3(0.0, 3.0, 0.0));
		//
		//glm::mat4 matrixRotate = glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(0, 0, 1));   vot tak rabotaet

		//glm::mat4 MatModel = glm::mat4(1.0f);
		GLint location = glGetUniformLocation(Program, "MatModel");            //obyazatelno nayti mesto matrix and otpravit ego
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(MatModel));

		GLint location1 = glGetUniformLocation(Program, "MatVida");
		glUniformMatrix4fv(location1, 1, GL_FALSE, glm::value_ptr(MatVida));

		GLint location2 = glGetUniformLocation(Program, "MatPerspective");
		glUniformMatrix4fv(location2, 1, GL_FALSE, glm::value_ptr(MatPerspective));

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	float ambientStrength = 0.1;
		
		



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
