cmake_minimum_required(VERSION 3.5)
project(processor_node)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)  # ✅ 추가

add_executable(processor_node src/processor_node.cpp)
ament_target_dependencies(processor_node
  rclcpp
  std_msgs                    # ✅ 추가
)

install(TARGETS
  processor_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()