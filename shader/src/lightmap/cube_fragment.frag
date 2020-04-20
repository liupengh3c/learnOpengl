#version 330 core
out vec4 FragColor;

struct Material{
   // 我们移除了环境光材质颜色向量，因为环境光颜色在几乎所有情况下都等于漫反射颜色
   // vec3 ambient;
    sampler2D diffuse;
    vec3 specular;
    float shininess; //反光度
};

struct Lamp{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform Lamp light;

in vec3 Normal;
in vec3 FragPos;

in vec2 TexCoords;

void main()
{
    // ambient 
    vec3 ambient = light.ambient * vec3(texture(material.diffuse,TexCoords)).rgb;
    
    // diffuse
    vec3 lightDir = normalize(light.position - FragPos);
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm,lightDir),0.0f);
    vec3 diffuse =  diff * light.diffuse *  vec3(texture(material.diffuse,TexCoords)).rgb;

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir,norm);
    // 计算反光度+材质反光度
    float spec = pow(max(dot(viewDir,reflectDir),0),material.shininess);
    // 镜面反射光+材质
    vec3 specular = spec * light.specular *material.specular;

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}