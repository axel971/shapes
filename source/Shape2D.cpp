 

#include "Shape2D.hpp"

using namespace std;

Shape2D::Shape2D(){}

void Shape2D::loadLineFlux(istringstream& line)
{
  double tmpX, tmpY;
 
  while(line >> tmpX >> tmpY)
    {
      m_x.push_back(tmpX);
      m_y.push_back(tmpY);
    }	 

}

void Shape2D::loadLineFile(string fileName)
{
  m_fileName = fileName;
 
  ifstream file(m_fileName, ios::in);  //Open the file

  if(file) 
    {   
      //Read the line and save the x,y coordinates
      string lineString;

      if(getline(file, lineString))
	{
	  istringstream line(lineString); //Convert the string lineString into the flux line
	  loadLineFlux(line);

	}

      //Close the file
      file.close();
    }

  else
    cerr << "It's impossible to open this file !" << endl;

}


double Shape2D::getX(int i)
{
  return m_x[i];
}
double Shape2D::getY(int i)
{
  return m_y[i];
}


void Shape2D::normalize()
{}

int Shape2D::size()
 {
   return m_x.size();
 }

void Shape2D::show()
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
    table->SetNumberOfRows(size());
    for (int i = 0; i < size(); ++i)
      {
	table->SetValue(i, 0, m_x[i]);
	table->SetValue(i, 1, m_y[i]);
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

void Shape2D::mean(double& meanX, double& meanY)
{
  meanX = 0.;
  meanY = 0.;

  for(vector<double>::iterator itX = m_x.begin(), itY = m_y.begin(); itX < m_x.end(), itY < m_y.end(); ++itX, ++itY)
    {
      meanX += (*itX);
      meanY += (*itY);
    }

  meanX /= m_x.size();
  meanY /= m_y.size();

}

void Shape2D::centered()
{
  double meanX, meanY;

  mean(meanX, meanY);

 for(vector<double>::iterator itX = m_x.begin(), itY = m_y.begin(); itX < m_x.end(), itY < m_y.end(); ++itX, ++itY)
   {
     *itX -= meanX;
     *itY -= meanY;
   }
}
