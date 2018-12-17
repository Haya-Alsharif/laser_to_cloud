#include "laser_to_cloud.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "laser_to_cloud_node");
    ros::NodeHandle nh("~");
    My_Filter filter(&nh);
    ros::spin();
    return 0;
}
