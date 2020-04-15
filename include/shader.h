#ifndef SHADER_H
#define SHADER_H
#include <iostream>
// GLM
#include <glm/glm.hpp>

extern unsigned int shaderProgram;
int shaderLoad(const char *vertexPath, const char *fragmentPath);
void shaderUse();
void shaderSetBool(const std::string &name, bool value);
void shaderSetInt(const std::string &name, int value);
void shaderSetFloat(const std::string &name, float value);
void shaderSetVec2(const std::string &name, const glm::vec2 &value);
void shaderSetVec2(const std::string &name, float x, float y);
void shaderSetVec3(const std::string &name, const glm::vec3 &value);
void shaderSetVec3(const std::string &name, float x, float y, float z);
void shaderSetVec4(const std::string &name, const glm::vec4 &value);
void shaderSetVec4(const std::string &name, float x, float y, float z, float w);
void shaderSetMat2(const std::string &name, const glm::mat2 &mat);
void shaderSetMat3(const std::string &name, const glm::mat3 &mat);
void shaderSetMat4(const std::string &name, const glm::mat4 &mat);

#endif