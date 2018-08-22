// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GAZEBO_ROS__CONVERSIONS__BUILTIN_INTERFACES_HPP_
#define GAZEBO_ROS__CONVERSIONS__BUILTIN_INTERFACES_HPP_

#include "gazebo_ros/conversions/generic.hpp"

#include <builtin_interfaces/msg/time.hpp>
#include <gazebo/common/Time.hh>

namespace gazebo_ros
{
/// \brief Specialized conversion from an Gazebo Time to a ROS Time message.
/// \param[in] in Gazebo Time to convert.
/// \return A ROS Time message with the same value as in
template<>
builtin_interfaces::msg::Time Convert(const gazebo::common::Time & in)
{
  builtin_interfaces::msg::Time time;
  time.sec = in.sec;
  time.nanosec = in.nsec;
  return time;
}

/// \brief Specialized conversion from an Gazebo Time message to a ROS Time message.
/// \param[in] in Gazebo Time message to convert.
/// \return A ROS Time message with the same value as in
template<>
builtin_interfaces::msg::Time Convert(const gazebo::msgs::Time & in)
{
  builtin_interfaces::msg::Time time;
  time.sec = in.sec();
  time.nanosec = in.nsec();
  return time;
}

}  // namespace gazebo_ros
#endif  // GAZEBO_ROS__CONVERSIONS__BUILTIN_INTERFACES_HPP_
