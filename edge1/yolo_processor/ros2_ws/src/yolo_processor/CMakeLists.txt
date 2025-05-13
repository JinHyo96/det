cmake_minimum_required(VERSION 3.5)
project(yolo_processor)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)

install(PROGRAMS
  ros2_ws/src/yolo_processor/yolo_processor_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()