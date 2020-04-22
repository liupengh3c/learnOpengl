// 第二部分-光照-颜色

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader_base.h"
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
namespace material
{
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void cursor_callback(GLFWwindow *windo, double xpos, double ypos);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float curTime = 0.0f;
float dealTime = 0.0f;
float lastTime = 0.0f;

glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
glm::vec3 lightColor = glm::vec3(1.0f);
Camera camera(glm::vec3(0, 0, 6.0f));
int materials()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "learn opengl lighting", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "glfw create window fail\n"
                  << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "init glad fail,\n"
                  << std::endl;
        return -1;
    }
    glEnable(GL_DEPTH_TEST);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // 不禁用鼠标，会导致立方体不能移动到窗口最边上
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, cursor_callback);
    lastTime = glfwGetTime();
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f};

    // 物体，立方体,cube
    shader_base cubeShader("shader/src/material/cube_vertex.vert", "shader/src/material/cube_fragment.frag");
    // 光源，lamp
    shader_base lampShader("shader/src/material/lamp_vertex.vert", "shader/src/material/lamp_fragment.frag");

    // 设置立方体，cube
    unsigned int cubeVAO, VBO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // 设置光源,lamp
    unsigned int lampVAO;
    glGenVertexArrays(1, &lampVAO);
    glBindVertexArray(lampVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    const float Yaw = -80.0f;
    const float Pitch = 0.0f;
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        curTime = glfwGetTime();
        dealTime = curTime - lastTime;
        lastTime = curTime;
        processInput(window);

        // 绘制立方体，物体,cube
        cubeShader.shaderUse();

        // 设置材质
        cubeShader.shaderSetVec3("material.ambient", 1.0f, 0.5f, 0.31f);
        cubeShader.shaderSetVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
        cubeShader.shaderSetVec3("material.specular", 0.5f, 0.5f, 0.5f);
        cubeShader.shaderSetFloat("material.shininess", 32.0f);

        // 环境光
        lightColor.x = sin(glfwGetTime() * 2.0f);
        lightColor.y = sin(glfwGetTime() * 0.7f);
        lightColor.z = sin(glfwGetTime() * 1.3f);
        glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
        glm::vec3 ambientColor = lightColor * glm::vec3(0.2f);

        cubeShader.shaderSetVec3("light.diffuse", diffuseColor);
        cubeShader.shaderSetVec3("light.ambient", ambientColor);

        // cubeShader.shaderSetVec3("light.ambient", 1.0f, 1.0f, 1.0f);
        // cubeShader.shaderSetVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
        cubeShader.shaderSetVec3("light.specular", 1.0f, 1.0f, 1.0f);
        cubeShader.shaderSetVec3("light.position", lightPos);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        cubeShader.shaderSetMat4("projection", projection);
        cubeShader.shaderSetMat4("view", view);
        cubeShader.shaderSetVec3("viewPos", camera.Position);
        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(-30.0f) * (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        cubeShader.shaderSetMat4("model", model);

        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // 绘制光源
        lampShader.shaderUse();
        lampShader.shaderSetMat4("projection", projection);
        lampShader.shaderSetMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        // 缩小一下光源
        model = glm::scale(model, glm::vec3(0.2f));
        lampShader.shaderSetMat4("model", model);

        glBindVertexArray(lampVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lampVAO);
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
float lastX, lastY;
bool firstMouse = true;
void cursor_callback(GLFWwindow *windo, double xpos, double ypos)
{
    float deltaX, deltaY;
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    deltaX = lastX - xpos;
    deltaY = ypos - lastY;

    lastX = xpos;
    lastY = ypos;
    std::cout << "xpos:" << xpos << "---ypos:" << ypos << std::endl;
    std::cout << "lastX:" << lastX << "---lastY:" << lastY << std::endl;
    std::cout << "deltaX:" << deltaX << "---deltaY:" << deltaY << std::endl
              << std::endl;
    camera.ProcessMouseMovement(deltaX, deltaY);
}
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(FORWARD, dealTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(BACKWARD, dealTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(LEFT, dealTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.ProcessKeyboard(RIGHT, dealTime);
    }
}
} // namespace material
