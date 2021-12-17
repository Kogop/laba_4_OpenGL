#version 330 core


in vec3 Color;
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;

uniform vec3 lightColor;
uniform vec3 LightPos;

void main() {
    
    vec3 d = normalize(FragPos - LightPos);
    float kDiff = max(dot(Normal, -d), 0);



  //  float ambientStrength = 0.1;
   float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
   vec3 Diffuse = kDiff * lightColor;
   vec3 result = (ambient + Diffuse) * Color;
   // FragColor = vec4(result, 1.0);
   FragColor = vec4(result, 1.0);

}