#ifndef SHADER_H
#define SHADER_H
#include <iostream>

extern unsigned int shaderProgram;
int shader(const char *vertexPath,const char *fragmentPath);
void shaderUse();
void setBool(const std::string &name, bool value);
void setInt(const std::string &name, int value);
void setFloat(const std::string &name, float value);
int test();

#endif