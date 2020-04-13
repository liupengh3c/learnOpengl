#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// GLM
#include <glm/glm.hpp>

// GLAD
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>



unsigned int shaderProgram;

int test()
{
    std::cout << "test debug info 1--------" << std::endl;
    return 0;
}
int shader(const char *vertexPath,const char *fragmentPath)
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
        std::cout << "shader debug info vertexSource--------" << vertexSource << std::endl;
        std::cout << "shader debug info fragSource--------" << fragSource << std::endl;
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
        std::cout << "shader debug info 3--------" << std::endl;
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
        std::cout << "shader debug info 4--------" << std::endl;
        // 将shader放入program，link
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram,fragShader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
            std::cout << "shader link error.\n" << infoLog << std::endl;
            return -3;
        }
        std::cout << "shader debug info 5--------" << std::endl;
        // 删除shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragShader);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void shaderUse()
{
    glUseProgram(shaderProgram);
    return;
}

void setBool(const std::string &name, bool value)
{         
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value); 
}
// ------------------------------------------------------------------------
void setInt(const std::string &name, int value) 
{ 
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void setFloat(const std::string &name, float value) 
{ 
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value); 
}
// ------------------------------------------------------------------------
void setVec2(const std::string &name, const glm::vec2 &value) 
{ 
    glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]); 
}
void setVec2(const std::string &name, float x, float y) 
{ 
    glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y); 
}
// ------------------------------------------------------------------------
void setVec3(const std::string &name, const glm::vec3 &value) 
{ 
    glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]); 
}
void setVec3(const std::string &name, float x, float y, float z) 
{ 
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z); 
}
// ------------------------------------------------------------------------
void setVec4(const std::string &name, const glm::vec4 &value) 
{ 
    glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &value[0]); 
}
void setVec4(const std::string &name, float x, float y, float z, float w) 
{ 
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w); 
}
// ------------------------------------------------------------------------
void setMat2(const std::string &name, const glm::mat2 &mat) 
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void setMat3(const std::string &name, const glm::mat3 &mat) 
{
    glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void setMat4(const std::string &name, const glm::mat4 &mat) 
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}