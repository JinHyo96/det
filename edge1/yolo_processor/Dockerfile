FROM ros:humble

RUN apt update && apt install -y \
    python3-pip \
    python3-colcon-common-extensions \
    python3-opencv \
    ros-humble-cv-bridge \
    && rm -rf /var/lib/apt/lists/*

RUN pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu
RUN pip install ultralytics

COPY ./ros2_ws /ros2_ws
WORKDIR /ros2_ws

RUN . /opt/ros/humble/setup.sh && colcon build

CMD ["bash", "-c", "source /opt/ros/humble/setup.bash && \
                  source /ros2_ws/install/local_setup.bash && \
                  ros2 run yolo_processor yolo_processor_node"]

