#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

constexpr unsigned int WIN_WIDTH = 800;
constexpr unsigned int WIN_HEIGHT = 600;

void glfwErrorCallback(int code, const char *description);

int main(int argc, char *argv[])
{
    glfwSetErrorCallback(glfwErrorCallback);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif //__APPLE__

    GLFWwindow *window = glfwCreateWindow(
        WIN_WIDTH,
        WIN_HEIGHT,
        "OpenGL",
        NULL,
        NULL);
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cout << "GLAD ERROR: Failed to initialize GLAD." << std::endl;

    // ImGui setup
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &imgui_io = ImGui::GetIO();

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Create new frames for ImGui implementations.
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Hello Window");
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwShowWindow(window);
    }

    // Cleanup
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

void glfwErrorCallback(int code, const char *description)
{
    std::cout << "GLFW ERROR " << code << ": " << description << std::endl;
}