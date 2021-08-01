#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "hardware_interface/system_interface.hpp"
#include "panda_moveit_demo_clone/mock_panda_hw_system.hpp"
#include "rclcpp/rclcpp.hpp"


namespace mock_panda_hw_system
{
    return_type MockArmHardware::write()
    {
        RCLCPP_INFO(rclcpp::get_logger("MockArmHardware"), "writing....");
        return return_type::OK;
    }

} // namespace mock_panda_hw_system

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(mock_panda_hw_system::MockArmHardware, hardware_interface::SystemInterface)
