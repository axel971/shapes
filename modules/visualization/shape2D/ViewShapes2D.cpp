#include "ViewShapes2D.hpp"

using namespace std;

ViewShapes2D::ViewShapes2D()
{}


void ViewShapes2D::setShape(shape::Shapes2D *ptrShapes)
{
  m_ptrShapes = ptrShapes;
}

void ViewShapes2D::exec()
{
  // Set up a 2D scene, add an XY chart to it
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetRenderWindow()->SetSize(400, 300);
 
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  view->GetScene()->AddItem(chart);
  chart->SetShowLegend(false);
  
  
  for(int i = 0; i < m_ptrShapes->numberOfShape(); ++i)
      {
	//Create a table with some points in it...
	vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();
  
	vtkSmartPointer<vtkFloatArray> arrX =   vtkSmartPointer<vtkFloatArray>::New();
	arrX->SetName("X Axis");
	table->AddColumn(arrX);
	
	vtkSmartPointer<vtkFloatArray> arrY =  vtkSmartPointer<vtkFloatArray>::New();
	arrY->SetName("Y Axis");
	table->AddColumn(arrY);
  
	//Test charting with a few more points...
	table->SetNumberOfRows(m_ptrShapes->numberOfLandmarksByShape());
  
	for (int j = 0; j < m_ptrShapes->numberOfLandmarksByShape(); ++j)
	  {
	    table->SetValue(j, 0, (*m_ptrShapes)[i].x(j));
	    table->SetValue(j, 1, (*m_ptrShapes)[i].y(j));
	  }
	
	//Add multiple scatter plots, setting the colors etc
	vtkPlot* points	= chart->AddPlot(vtkChart::POINTS);
	
#if VTK_MAJOR_VERSION <= 5
	points->SetInput(table, 0, 1);
#else
	points->SetInputData(table, 0, 1);
#endif
	points->SetColor(0, 0, 0, 255);

      }

    //Finally render the scene
    view->GetRenderWindow()->SetMultiSamples(0);
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();

}
