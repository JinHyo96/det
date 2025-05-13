FROM ros:humble

# 필요한 ROS2 패키지 설치
RUN apt update && apt install -y \
    python3-pip \
    python3-colcon-common-extensions \
    ros-humble-std-msgs \
    && rm -rf /var/lib/apt/lists/*

# 코드 복사 및 빌드
COPY ./ros2_ws /ros2_ws
WORKDIR /ros2_ws

RUN . /opt/ros/humble/setup.sh && colcon build

CMD ["bash", "-c", "source /opt/ros/humble/setup.bash && source /ros2_ws/install/local_setup.bash && /ros2_ws/install/collector_node/lib/collector_node/collector_node"]