#include <save.h>

bool save::dump2map(std::string directory, double r = 1000.0) {
	std::string directory;

	boost::filesystem::directory_iterator dir(directory);
	boost::filesystem::directory_iterator end;

	pcl::PointCloud<pcl::PointXYZI>::Ptr accumulated(new pcl::PointCloud<pcl::PointXYZI>());
	for(dir; dir != end; dir++) {
		if(!boost::filesystem::is_directory(dir->path())) {
			continue;
		}

		std::ifstream ifs(dir->path().string() + "/data");

		std::string token;
		ifs >> token >> token >> token >> token;

		Eigen::Matrix4f pose;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				ifs >> pose(i, j);
			}
		}

    bool is_filtered = false;
    while(!ifs.eof()) {
      std::string line;
      std::getline(ifs, line);

      if(line.find("filtered") != std::string::npos) {
        std::stringstream sst(line);
        sst >> token >> is_filtered;
      }
    }

    if(is_filtered) {
      std::cout << "filtered" << std::endl;
      continue;
    }

		std::cout << "--- pose ---" << std::endl << pose << std::endl;
		Eigen::Affine3f affine(pose);

		pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>());
		pcl::io::loadPCDFile(dir->path().string() + "/cloud.pcd", *cloud);

		auto remove_loc = std::remove_if(cloud->begin(), cloud->end(), [=](const pcl::PointXYZI& pt) { return pt.getVector3fMap().norm() > r; });
		cloud->erase(remove_loc, cloud->end());

		pcl::PointCloud<pcl::PointXYZI>::Ptr transformed(new pcl::PointCloud<pcl::PointXYZI>());
		pcl::transformPointCloud(*cloud, *transformed, affine);

		std::copy(transformed->begin(), transformed->end(), std::back_inserter(accumulated->points));
	}

	accumulated->width = accumulated->size();
	accumulated->height = 1;
	accumulated->is_dense = false;

	pcl::io::savePCDFileBinary(directory + "/map.pcd", *accumulated);
	pcl::io::savePLYFileASCII(directory + "/map.asc", *accumulated);
	return true;
}

void save::output_ascii(const std::string& filename, const pcl::PointCloud<pcl::PointXYZI>& cloud, const Eigen::Vector3d& offset) {
  std::ofstream ofs(filename);
  if(!ofs) {
    std::cerr << "failed to open the output file!!" << std::endl;
    std::cerr << filename << std::endl;
    return;
  }

  for(const auto& pt: cloud.points) {
    Eigen::Vector3d p = pt.getVector3fMap().cast<double>() + offset;
		ofs << p.x() << " " << p.y() << " " << p.z() << std::endl;
  }

  ofs.close();
}

bool save::frame2map(int argc, char** argv) {
  std::string directory = argv[argc - 1];
  Eigen::Vector3d offset = Eigen::Vector3d::Zero();
  double r = 1000.0;

  for(int i=1; i<argc; i++) {
    std::string arg = argv[i];
    if(arg == "-r") {
      r = std::atof(argv[i+1]);
    } else if (arg == "--utm") {
      std::ifstream utm_ifs(directory + "/../zero_utm");
      if(!utm_ifs) {
        std::cerr << "error : no utm file!!" << std::endl;
        return 1;
      }

      utm_ifs >> offset[0] >> offset[1] >> offset[2];
      std::cout << "--- zero_utm ---\n" << offset.transpose() << std::endl;
    }
  }

  std::ifstream ifs(directory + "/data");

  std::string token;
  ifs >> token >> token >> token >> token;

  Eigen::Matrix4f pose;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      ifs >> pose(i, j);
    }
  }
  // pose.block<3, 1>(0, 3) += offset;

  std::cout << "--- pose ---" << std::endl << pose << std::endl;
  Eigen::Affine3f affine(pose);

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>());
  pcl::io::loadPCDFile(directory + "/cloud.pcd", *cloud);

  auto remove_loc = std::remove_if(cloud->begin(), cloud->end(), [=](const pcl::PointXYZI& pt) { return pt.getVector3fMap().norm() > r; });
  cloud->erase(remove_loc, cloud->end());

  pcl::PointCloud<pcl::PointXYZI>::Ptr transformed(new pcl::PointCloud<pcl::PointXYZI>());
  pcl::transformPointCloud(*cloud, *transformed, affine);

  transformed->width = transformed->size();
  transformed->height = 1;
  transformed->is_dense = false;

  pcl::io::savePCDFileBinary(directory + "/map.pcd", *transformed);
  // pcl::io::savePLYFileASCII(directory + "/map.asc", *transformed);
  output_ascii(directory + "/map.asc", *transformed, offset);
  return true;
}

bool save::map2utm(int argc, char** argv) {
  std::string utm_filename = argv[1];
  std::string src_filename = argv[2];
  std::string dst_filename = argv[3];

  Eigen::Vector3d offset = Eigen::Vector3d::Zero();
  std::ifstream utm_ifs(utm_filename);
  if(!utm_ifs) {
    std::cerr << "error : no utm file!!" << std::endl;
    return 1;
  }

  utm_ifs >> offset[0] >> offset[1] >> offset[2];
  std::cout << "--- zero_utm ---\n" << offset.transpose() << std::endl;

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>());
  pcl::io::loadPCDFile(src_filename, *cloud);

  save_ascii(dst_filename + ".asc", cloud, offset);
  return true;
}
