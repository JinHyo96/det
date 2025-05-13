#include "rclcpp/rclcpp.hpp"

class CollectorNode : public rclcpp::Node
{
public:
  CollectorNode() : Node("collector_node")
  {
    RCLCPP_INFO(this->get_logger(), "Collector node has started.");
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CollectorNode>());
  rclcpp::shutdown();
  return 0;
}