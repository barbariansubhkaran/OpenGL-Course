#include <iostream>
#include <GL/glew.h>
#include  <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

using namespace std;

int main()
{

    if(!glfwInit())
    {
    	cout << "ERROR" << endl;

    	glfwTerminate(); 

    	return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "TEST", NULL, NULL);

    if(!mainWindow)
    {
    	cout << "Window Failed" << endl;
    	glfwTerminate();

    	return 1;
    }


     int bufferwidth, bufferheight;

     glfwGetFramebufferSize(mainWindow, &bufferwidth, &bufferheight);


      glfwMakeContextCurrent(mainWindow);

      glewExperimental = GL_TRUE;

      if(glewInit() != GLEW_OK)
      {
      	 cout << "Glew Failed " << endl;
      	 glfwDestroyWindow(mainWindow);
      	 glfwTerminate();

      	 return 1;
      }

      glViewport(0, 0, bufferwidth, bufferheight);

      while(!glfwWindowShouldClose(mainWindow))
      {
      	 glfwPollEvents();

        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);

      }






	return 0;
}