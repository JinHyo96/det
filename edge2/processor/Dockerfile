FROM ros:humble

RUN apt update && apt install -y \
    python3-pip python3-colcon-common-extensions \
    && rm -rf /var/lib/apt/lists/*

COPY ros2_ws /ros2_ws
WORKDIR /ros2_ws

RUN . /opt/ros/humble/setup.sh && colcon build

CMD ["bash", "-c", "source /opt/ros/humble/setup.bash && source /ros2_ws/install/local_setup.bash && /ros2_ws/install/processor_node/lib/processor_node/processor_node"]