#version 330 core

layout(Location = 0) in vec3 vertexPosition;
layout(Location = 1) in vec3 vertexColor;
layout(Location = 2) in vec3 vertexNormal;


out vec3 Color;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 MatModel;
uniform mat4 MatVida;
uniform mat4 MatPerspective;

//uniform vec3 lightColor;


void main() {
	Color = vertexColor;
	mat3 MatNormal = transpose(inverse(mat3(MatVida * MatModel)));
	gl_Position = MatPerspective * MatVida  * MatModel * vec4(vertexPosition, 1.0);
	FragPos = vec3(MatVida * MatModel * vec4(vertexPosition, 1.0));
	Normal = normalize(MatNormal * vertexNormal);
}