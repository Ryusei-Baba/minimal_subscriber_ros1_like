#include <rclcpp/rclcpp.hpp>
#include <rclcpp/qos.hpp>
#include <example_interfaces/msg/string.hpp>

rclcpp::Node::SharedPtr node = nullptr;

void topic_callback(const example_interfaces::msg::String::SharedPtr msg){
  RCLCPP_INFO(node->get_logger(), "I heard: %s", msg->data.c_str());
}

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);

  node=rclcpp::Node::make_shared("ros1_like_subscriber_test");
  auto subscription = node->create_subscription<example_interfaces::msg::String>(
    "topic_test",
    rclcpp::QoS(10),
    std::bind(topic_callback, std::placeholders::_1)
  );
  rclcpp::spin(node);
  rclcpp::shutdown();

  subscription = nullptr;
  node = nullptr;
  return 0;
}