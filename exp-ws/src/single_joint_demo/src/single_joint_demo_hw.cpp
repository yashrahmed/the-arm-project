#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "hardware_interface/system_interface.hpp"
#include "single_joint_demo/single_joint_demo_hw.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


namespace single_joint_demo_hw
{

    JointPositionPublisherUtil::JointPositionPublisherUtil() : Node("minimal_publisher")
    {
        RCLCPP_INFO(rclcpp::get_logger("JointPositionPublisherUtil"), "creating util.....");
        this->publisher = this->create_publisher<std_msgs::msg::String>("/driver/joint_cmd", 10);
    }

    void JointPositionPublisherUtil::publish(std::string joint_positions_str)
    {
        auto message = std_msgs::msg::String();
        message.data = joint_positions_str;
        this->publisher->publish(message);
    }

    JointHardware::JointHardware() : joint_position_pub_util()
    {
        RCLCPP_INFO(rclcpp::get_logger("JointHardware"), "Constructing.....");
    }


    return_type JointHardware::write()
    {
        /*
          // From generic system
          const std::vector<std::string> standard_interfaces_ = {
            hardware_interface::HW_IF_POSITION,
            hardware_interface::HW_IF_VELOCITY,
            hardware_interface::HW_IF_ACCELERATION,
            hardware_interface::HW_IF_EFFORT
            }
        */
        int cmd_size = joint_commands_[0].size();
        std::string joint_positions_str = "";
        for (int i = 0; i < cmd_size; i++)
        {
            joint_positions_str.append(std::to_string(joint_commands_[0][i]));
            if (i < cmd_size - 1)
            {
                joint_positions_str.append(" ");
            }
        }

        RCLCPP_INFO(rclcpp::get_logger("JointHardware"), "writing %s", joint_positions_str.c_str());
        this->joint_position_pub_util.publish(joint_positions_str);
        return return_type::OK;
    }

} // namespace single_joint_demo_hw

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(single_joint_demo_hw::JointHardware, hardware_interface::SystemInterface)
