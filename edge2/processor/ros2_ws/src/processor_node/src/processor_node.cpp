#include "rclcpp/rclcpp.hpp"

class ProcessorNode : public rclcpp::Node {
public:
  ProcessorNode() : Node("processor_node") {
    RCLCPP_INFO(this->get_logger(), "Processor node has started.");
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ProcessorNode>());
  rclcpp::shutdown();
  return 0;
}