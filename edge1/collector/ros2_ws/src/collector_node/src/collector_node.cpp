#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CollectorNode : public rclcpp::Node {
public:
  CollectorNode() : Node("collector_node") {
    publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      [this]() {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello from collector_node!";
        publisher_->publish(msg);
      });
    RCLCPP_INFO(this->get_logger(), "Collector node with publisher started.");
  }

private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CollectorNode>());
  rclcpp::shutdown();
  return 0;
}