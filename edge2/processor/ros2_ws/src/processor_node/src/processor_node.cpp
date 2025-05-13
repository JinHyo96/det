#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ProcessorNode : public rclcpp::Node {
public:
  ProcessorNode() : Node("processor_node") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", 10,
      [this](const std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
      });
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ProcessorNode>());
  rclcpp::shutdown();
  return 0;
}