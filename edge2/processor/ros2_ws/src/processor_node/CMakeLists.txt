cmake_minimum_required(VERSION 3.5)
project(processor_node)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(processor_node src/processor_node.cpp)
ament_target_dependencies(processor_node rclcpp)

install(TARGETS
  processor_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()