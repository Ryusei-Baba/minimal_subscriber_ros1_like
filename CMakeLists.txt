cmake_minimum_required(VERSION 3.5)
project(minimal_subscriber_ros1_like)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(callback_subscriber_test
  src/callback_main.cpp
)
ament_target_dependencies(callback_subscriber_test
  rclcpp
  example_interfaces
)

add_executable(lambda_subscriber_test
  src/lambda_main.cpp
)
ament_target_dependencies(lambda_subscriber_test
  rclcpp
  example_interfaces
)

install(TARGETS
  callback_subscriber_test
  lambda_subscriber_test
  #DESTINATION lib/${PROJECT_NAME}
  DESTINATION lib/minimal_subscriber_ros1_like
)

ament_package()
