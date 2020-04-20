#version 330 core
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 objColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 ambientColor;

uniform vec3 viewPos;

void main()
{
    vec3 normal = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 reflectDir = reflect(-lightDir,normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    float spec = pow(max(dot(reflectDir,viewDir),0),32);
    vec3 specular = spec * lightColor;

    vec3 diffuse =  max(dot(lightDir,normal),0) * lightColor;
    FragColor = vec4((diffuse + ambientColor + specular) * objColor, 1.0);
}