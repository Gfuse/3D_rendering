#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <boost/filesystem.hpp>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/common/transforms.h>


class save{
public:
   bool dump2map(std::string directory, double r);
   bool frame2map(int argc, char** argv);
   bool map2utm(int argc, char** argv);

private:
  void output_ascii(const std::string& filename, const pcl::PointCloud<pcl::PointXYZI>& cloud, const Eigen::Vector3d& offset);
};

#endif // MAINWINDOW_H
