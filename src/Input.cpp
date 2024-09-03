

#include "Input.hpp"


Input input;
InputState &inputState = input._inputState;


Input& getInput(){
	return input;
}

 
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	double xpos, ypos;
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		glfwGetCursorPos(window, &xpos, &ypos);
        printf("Click! -- %f , %f \n", xpos, ypos);
		// printf("simstate: %d \n", SimState::idle);

        // if(simulation.simState == SimState::idle && ypos < 100.0 && xpos > 700.0){
		if(ypos < 100.0 && xpos > 700.0){
			printf("Start Simulation button clicked! \n");
            inputState.startSimClick = 1;
			// simulation.simState = SimState::startClickDetected;
		}
		inputState.mousePressActive = 1;
		inputState.pointerXLastClick = xpos;
		inputState.pointerYLastClick = ypos;
		
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE){
		// printf("RELEASED LEFT MOUSE BUTON\n");
		inputState.mousePressActive = 0;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS){
		glfwGetCursorPos(window, &xpos, &ypos);
		inputState.middleMouse = 1;
		inputState.pointerXLastFrame = xpos;
		inputState.pointerYLastFrame = ypos;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
		inputState.middleMouse = 0;
	
}
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	// printf("%f , %f \n", xpos, ypos);
	inputState.pointerX = xpos;
	inputState.pointerY = ypos;
	
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // printf("%d\n", key);
	// input.s = key;
	
	

	if ((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL ) && action == GLFW_PRESS)
		inputState.ctrl = 1;
	if ((key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL)  && action == GLFW_RELEASE)
		inputState.ctrl = 0;
	

	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		inputState.w = 1;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		inputState.s = 1;
	if (key == GLFW_KEY_A && action == GLFW_PRESS){
		inputState.a = 1;
		inputState.mostRecentADpress = 'a';
		// printf("A \n");
		// if(inputState.mostRecentADpress == 97)
		// 	printf("'a' is most recent\n");
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS){
		inputState.d = 1;
		inputState.mostRecentADpress = 'd';
		
	}

	if (key == GLFW_KEY_W && action == GLFW_RELEASE)
		inputState.w = 0;
	if (key == GLFW_KEY_S && action == GLFW_RELEASE)
		inputState.s = 0;
	if (key == GLFW_KEY_A && action == GLFW_RELEASE)
		inputState.a = 0;
	if (key == GLFW_KEY_D && action == GLFW_RELEASE)
		inputState.d = 0;

	// ARROW KEYS
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		inputState.au = 1;
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		inputState.al = 1;
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		inputState.ad = 1;
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		inputState.ar = 1;

	if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
		inputState.au = 0;
	if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
		inputState.al = 0;
	if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
		inputState.ad = 0;
	if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
		inputState.ar = 0;
}
 

// process all inputState: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	// if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	// 	printf("S pressed! \n");
	
}


// void mouse_button_callback_2(GLFWwindow* window, int button, int action, int mods)
// {
//    printf("CALLBACK 2\n"); 
// }  