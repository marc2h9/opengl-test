#include <iostream>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

void frame_buffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {
  // Initialization
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Creating Window
  GLFWwindow *window = glfwCreateWindow(800, 600, "test", NULL, NULL);
  if (window == NULL) {
    std::cout << "GLFW failed to create window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // Loading GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Setting Viewport
  glViewport(0, 0, 800, 600);
  void frame_buffer_size_callback(GLFWwindow *window, int width, int height);

  glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

  while(!glfwWindowShouldClose(window)) {
    // Render Loop
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
