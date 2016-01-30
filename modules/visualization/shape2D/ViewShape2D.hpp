#ifndef VIEWSHAPE2D_HPP
#define VIEWSHAPE2D_HPP

#include "../../core/shape2D/Shape2D.hpp"

#include <vtkSmartPointer.h>
 
#include <vtkChartXY.h>
#include <vtkContextScene.h>
#include <vtkContextView.h>
#include <vtkFloatArray.h>
#include <vtkPlotPoints.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTable.h>

class ViewShape2D
{
private :

  Shape2D  *m_ptrShape;

public :

  ViewShape2D();

  void setShape(Shape2D *m_ptrShape2D);

  void exec();

};
#endif
