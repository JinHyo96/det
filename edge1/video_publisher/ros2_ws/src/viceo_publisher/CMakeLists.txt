cmake_minimum_required(VERSION 3.5)
project(video_publisher)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)

install(PROGRAMS
  ros2_ws/src/video_publisher/video_publisher_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()