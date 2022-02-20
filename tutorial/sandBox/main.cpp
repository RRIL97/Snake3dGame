#include "igl/opengl/glfw/renderer.h"
#include "tutorial/sandBox/inputManager.h"
#include <igl\vertex_triangle_adjacency.h>

#include "sandBox.h"
#include "snake.h"
#include "GameMenu.h"
#include "Game.h"
#include "ObjectManager.h"
#include "backgroundHandler.h"
#include "SoundManager.h"



int main(int argc, char *argv[])
{

	Display* disp = new Display(1200, 800, "Snake Game - Sabina & Ron");

	Renderer renderer;

	igl::opengl::glfw::imgui::ImGuiMenu menu;
	SoundManager soundManager;	
	Game* viewer=new Game(&menu,&soundManager);
	Init(*disp, &menu);
	renderer.init(viewer, 2, &menu);
    //viewer->initMenu();
//	renderer.core().viewport = Eigen::Vector4f(0, 0, 600, 800);
	//renderer.core().camera_zoom =0.2;
	disp->SetRenderer(&renderer);
	disp->launch_rendering(true);
	delete disp;
}
