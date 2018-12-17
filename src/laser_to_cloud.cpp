#include "laser_to_cloud.h"

My_Filter::My_Filter(ros::NodeHandle* nodehandle):
    node_(*nodehandle)
{
    std::string published_pointcloud_topic;
    node_.getParam("published_pointcloud_topic", published_pointcloud_topic);
    scan_sub_ = node_.subscribe<sensor_msgs::LaserScan> ("/scan", 100, &My_Filter::scanCallback, this);
    point_cloud_publisher_ = node_.advertise<sensor_msgs::PointCloud2> (published_pointcloud_topic, 100, false);
    tfListener_.setExtrapolationLimit(ros::Duration(0.1));
}

void My_Filter::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan){
    sensor_msgs::PointCloud2 cloud;
    projector_.transformLaserScanToPointCloud("laser", *scan, cloud, tfListener_);
    point_cloud_publisher_.publish(cloud);
}
