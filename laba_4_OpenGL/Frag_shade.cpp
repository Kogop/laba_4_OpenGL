#version 330 core


//
//struct Material {
//    sampler2D diffuse;
//    vec3      specular;
//    float     shininess;
//};
//
//
//struct Light {
//    vec3 position;
//
//    vec3 ambient;
//    vec3 diffuse;
//    vec3 specular;
//};
//
//in vec2 TexCoords;

in vec3 Color;
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;

uniform vec3 lightColor;
uniform vec3 LightPos;

void main() {
    
    vec3 d = normalize(FragPos - LightPos);
    float kDiff = max(dot(Normal, -d), 0.0);



 
   float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
   vec3 Diffuse = kDiff * lightColor;
   vec3 result = (ambient + Diffuse) * Color;
    FragColor = vec4(result, 1.0);
   

       // ќкружающа€ составл€юща€
   // vec3 ambient = Light.ambient * texture(Material.diffuse, TexCoords).rgb;

    // ƒиффузна€ составл€юща€ 
   // vec3 norm = normalize(Normal);
   // vec3 lightDir = normalize(light.position - FragPos);
   // float diff = max(dot(norm, lightDir), 0.0);
  //  vec3 Diffuse = Light.diffuse * KDiff * texture(Material.diffuse, TexCoords).rgb;

    // ќтраженна€ составл€юща€
   // vec3 viewDir = normalize(viewPos - FragPos);
  //  vec3 reflectDir = reflect(-lightDir, norm);
   // float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   // vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;
//
  //  vec3 result = ambient + diffuse + specular;
  //  FragColor = vec4(result, 1.0);


}