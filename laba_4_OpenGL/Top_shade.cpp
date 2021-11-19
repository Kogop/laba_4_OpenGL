#version 330 core

layout(Location = 0) in vec3 vertexPosition;
layout(Location = 1) in vec3 vertexColor;


out vec3 Color;


void main() {
	Color = vertexColor;
	gl_Position = vec4(vertexPosition, 1.0);
}