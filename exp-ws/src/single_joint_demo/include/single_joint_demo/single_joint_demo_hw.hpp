#ifndef SINGLE_JOINT_DEMO__SINGLE_JOINT_DEMO_HW_HPP_
#define SINGLE_JOINT_DEMO__SINGLE_JOINT_DEMO_HW_HPP_

#include "fake_components/generic_system.hpp"

namespace single_joint_demo_hw
{
  class HARDWARE_INTERFACE_PUBLIC JointHardware : public fake_components::GenericSystem
  {
    return_type write() override;
  };

} // namespace mock_SINGLE_JOINT_DEMO_HW

#endif // SINGLE_JOINT_DEMO__GENERIC_SYSTEM_HPP_
