cmake_minimum_required(VERSION 3.5)
project(collector_node)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(collector_node src/collector_node.cpp)
ament_target_dependencies(collector_node rclcpp)

install(TARGETS
  collector_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()