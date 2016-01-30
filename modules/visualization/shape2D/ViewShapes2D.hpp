#ifndef VIEWSHAPES2D_HPP
#define VIEWSHAPES2D_HPP

#include "../../core/shape2D/Shapes2D.hpp"

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

class ViewShapes2D
{
private :

  shape::Shapes2D  *m_ptrShapes;

public :

  ViewShapes2D();

  void setShape(shape::Shapes2D *ptrShapes);

  void exec();

};

#endif
