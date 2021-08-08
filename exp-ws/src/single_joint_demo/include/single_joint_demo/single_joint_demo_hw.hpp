#ifndef SINGLE_JOINT_DEMO__SINGLE_JOINT_DEMO_HW_HPP_
#define SINGLE_JOINT_DEMO__SINGLE_JOINT_DEMO_HW_HPP_

#include "fake_components/generic_system.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


namespace single_joint_demo_hw
{

  class JointPositionPublisherUtil : public rclcpp::Node
  {
  private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;

  public:
    JointPositionPublisherUtil();
    void publish(std::string joint_positions_str);
  };

  class HARDWARE_INTERFACE_PUBLIC JointHardware : public fake_components::GenericSystem
  {
  private:
    JointPositionPublisherUtil joint_position_pub_util;

  public:
    return_type write() override;
    JointHardware();
  };

} // namespace single_joint_demo_hw

#endif // SINGLE_JOINT_DEMO__GENERIC_SYSTEM_HPP_
