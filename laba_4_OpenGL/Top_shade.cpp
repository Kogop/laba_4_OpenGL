#version 330 core

layout(Location = 0) in vec3 vertexPosition;
layout(Location = 1) in vec3 vertexColor;


out vec3 Color;

uniform mat4 MatModel;
uniform mat4 MatVida;
uniform mat4 MatPerspective;


void main() {
	Color = vertexColor;
	
	gl_Position = MatPerspective * MatVida  * MatModel * vec4(vertexPosition, 1.0);
}