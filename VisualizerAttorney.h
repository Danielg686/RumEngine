//VisualizerAttorney
//Daniel Goodrum, Feb 2018

#ifndef VISUALIZERATTORNEY_H
#define VISUALIZERATTORNEY_H

#include "Visualizer.h"


class VisualizerAttorney
{
public:
	class Register
	{
	private:
		friend class VisualizeBSphereCommand;
		friend class VisualizeAABBCommand;
		friend class MathTools;
		///		\brief Passthrough to visualize Bsphere.
		static void RenderBSphere(Matrix& S, Vect& col) { Visualizer::RenderBSphere(S, col); }
		static void RenderAABB(Matrix& S, Vect& col) { Visualizer::RenderAABB(S, col); }
		static void ShowClampPoint(Vect& pos) { Visualizer::ShowClampPoint(pos); }

	};
	class GameLoop
	{
	private: 
		//friend class Scene;
		friend class RumEngine;
		friend class SceneManager;
		///		\brief Passthrough for Scene to call VisualizeAll.
		static void VisualizeAll() { Visualizer::VisualizeAll(); }
		static void Delete() { Visualizer::Delete(); }
	};
};




#endif // !VISUALIZERATTORNEY_H
