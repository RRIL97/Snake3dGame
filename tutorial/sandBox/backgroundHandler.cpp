#include "backgroundHandler.h"
#include <igl/png/texture_from_png.h>
backgroundHandler::backgroundHandler(igl::opengl::glfw::Viewer* viewer)
{
	this->viewer = viewer;

}

void backgroundHandler::initBackground(){
	viewer->load_mesh_from_file("C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\data\\cube.obj", "C:\\Users\\sabin\\Downloads\\EngineForAnimationCourse\\tutorial\\textures\\bricks.png");
	viewer->data().MyScale(Eigen::Vector3d(100, 0.1, 100));
	viewer->parents.push_back(-1);
	viewer->children.push_back(-1);
	viewer->data().MyTranslate(Eigen::Vector3d(0, -3, 0), false);
	viewer->data().set_visible(false, 1);
	  
}
