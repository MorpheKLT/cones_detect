// Copyright 2024 BartlomiejGasyna
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CONES_DETECT__CONES_DETECT_NODE_HPP_
#define CONES_DETECT__CONES_DETECT_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

// #include "cuda_utils.h"
// #include "logging.h"
#include "utils.h"
#include "cones_detect/cones_detect.hpp"
#include <cv_bridge/cv_bridge.h>
#include "cones_interfaces/msg/bounding_box.hpp" 
#include "cones_interfaces/msg/cones.hpp"


namespace cones_detect
{
// using ConesDetectPtr = std::unique_ptr<cones_detect::ConesDetect>;

class CONES_DETECT_PUBLIC ConesDetectNode : public rclcpp::Node
{
public:
  explicit ConesDetectNode(const rclcpp::NodeOptions & options);

private:
  // ConesDetectPtr cones_detect_{nullptr};
  int64_t param_name_{123};

  bool build_engine{false};
  bool show_image{false};
  std::string onnx_path{"model.onnx"};
  // std::string engine_path{"engine.engine"};

  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
  rclcpp::Publisher<cones_interfaces::msg::Cones>::SharedPtr bboxes_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
  // Inference Engine class
  Yolo detector;
};
}  // namespace cones_detect

#endif  // CONES_DETECT__CONES_DETECT_NODE_HPP_
