#include <Eigen/Core>
#include <vtkConfigure.h>
#include <vtkObjectBase.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <valarray>
#include <iostream>



int main(int argc, char *argv[])
{

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

     if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *cloud) == -1) //* load the file
     {
       PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
       return (-1);
     }
     std::cout << "Loaded "
               << cloud->width * cloud->height
               << " data points from test_pcd.pcd with the following fields: "
               << std::endl;
     std::cout <<"dimensions ,x:"<<cloud->width<<",y:"<<cloud->height<<endl;
std::string title;
title.append(argv[1]);
title.append(".3d");
std::string *titleptr=&title;
cout<<title<<endl;
     double result[cloud->width][3];
ofstream myfile (title.c_str());
     for (size_t i = 0; i < cloud->points.size (); ++i)
	{
	result[i][1] = cloud->points[i].x;
        result[i][2] = cloud->points[i].y;
        result[i][3] = cloud->points[i].z;
myfile<<result[i][1]<<" "<<result[i][2]<<" "<<result[i][3]<<"\n";
	}

    myfile.close();
 // }
	//std::ostringstream merger;
        //merger<<cloud->points[i].x<<cloud->points[i].y<<cloud->points[i].z;
        //std::string result1 = merger.str();
        //result.push_back(result1);
        //std::cout<<"result size:"<<(int)result.size()<<std::endl;
   /*    std::cout << "    " << cloud->points[i].x
                 << " "    << cloud->points[i].y
                 << " "    << cloud->points[i].z << std::endl;*/
  //  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");

    return 0;
}
