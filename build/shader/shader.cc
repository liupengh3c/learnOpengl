#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// GLAD
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>



unsigned int Id = glCreateProgram();

int Shader(const char *vertexPath,const char *fragmentPath)
{
    std::string strVertexSource;
    std::string strFragSource;

    std::stringstream vertexShaderStream;
    std::stringstream fragShaderStream;

    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    const char *vertexSource;
    const char *fragSource;

    int success = 0;
    char infoLog[512] = {};

    try
    {
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);

        vertexShaderStream << vertexShaderFile.rdbuf();
        fragShaderStream << fragmentShaderFile.rdbuf();

        strVertexSource = vertexShaderStream.str();
        strFragSource = fragShaderStream.str();

        vertexSource = strVertexSource.c_str();
        fragSource = strFragSource.c_str();

        unsigned int vertexShader,fragShader;
        
        // 处理顶点着色器
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vertexSource,NULL);
        glCompileShader(vertexShader);


        glGetShaderiv(vertexShader,GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
            std::cout << "vertex compile error.\n" << infoLog << std::endl;
            return -1;
        }
        
        // 处理片段着色器
        fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragShader,1,&fragSource,NULL);
        glCompileShader(fragShader);

        glGetShaderiv(fragShader,GL_COMPILE_STATUS,&success);
        if (!success)
        {
            glGetShaderInfoLog(fragShader,512,NULL,infoLog);
            std::cout << "fragment compile error.\n" << infoLog << std::endl;
            return -2;
        }

        // 将shader放入program，link
        glAttachShader(Id,vertexShader);
        glAttachShader(Id,fragShader);
        glLinkProgram(Id);

        glGetProgramiv(Id,GL_LINK_STATUS,&success);
        if (!success)
        {
            glGetProgramInfoLog(Id,512,NULL,infoLog);
            std::cout << "shader link error.\n" << infoLog << std::endl;
            return -3;
        }
        
        // 删除shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragShader);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Use()
{
    glUseProgram(Id);
    return;
}

void setBool(const std::string &name, bool value)
{         
    glUniform1i(glGetUniformLocation(Id, name.c_str()), (int)value); 
    return;
}
// ------------------------------------------------------------------------
void setInt(const std::string &name, int value) 
{ 
    glUniform1i(glGetUniformLocation(Id, name.c_str()), value); 
    return;
}
// ------------------------------------------------------------------------
void setFloat(const std::string &name, float value)
{ 
    glUniform1f(glGetUniformLocation(Id, name.c_str()), value); 
    return;
}