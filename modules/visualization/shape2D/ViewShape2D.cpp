#include "ViewShape2D.hpp"

using namespace std;

ViewShape2D::ViewShape2D()
{}

void ViewShape2D::setShape(Shape2D *ptrShape)
{
  m_ptrShape = ptrShape;
}

void ViewShape2D::exec()
{
  // Set up a 2D scene, add an XY chart to it
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetRenderWindow()->SetSize(400, 300);
 
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  view->GetScene()->AddItem(chart);
  chart->SetShowLegend(false);
  
  // Create a table with some points in it...
  vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();
  
  vtkSmartPointer<vtkFloatArray> arrX =   vtkSmartPointer<vtkFloatArray>::New();
  arrX->SetName("X Axis");
  table->AddColumn(arrX);
  
    vtkSmartPointer<vtkFloatArray> arrY =  vtkSmartPointer<vtkFloatArray>::New();
    arrY->SetName("Y Axis");
    table->AddColumn(arrY);
  
    // Test charting with a few more points...
    table->SetNumberOfRows(m_ptrShape->size());
    for (int i = 0; i < m_ptrShape->size(); ++i)
      {
	table->SetValue(i, 0, m_ptrShape->x(i));
	table->SetValue(i, 1, m_ptrShape->y(i));
      }
 
    // Add multiple scatter plots, setting the colors etc
    vtkPlot *points = chart->AddPlot(vtkChart::POINTS);
#if VTK_MAJOR_VERSION <= 5
    points->SetInput(table, 0, 1);
#else
    points->SetInputData(table, 0, 1);
#endif
    points->SetColor(0, 0, 0, 255);
    points->SetWidth(1.0);
    vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CROSS);
   
    //Finally render the scene
    view->GetRenderWindow()->SetMultiSamples(0);
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();
 }
