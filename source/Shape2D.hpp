
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


#include <vtkVersion.h>
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

    

class Shape2D
{
 private :

  std::vector<double> m_x;
  std::vector<double> m_y;
  std::string m_fileName;

 public:

  Shape2D();


  double getX(int i);
  double getY(int i);

  void loadLineFile(std::string fileName);
  void loadLineFlux(std::istringstream& line);
  void normalize();
  void show();
  int size();
  void mean(double& meanX, double& meanY);
  void centered();
};


