import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import json
import cv2
from ultralytics import YOLO

class YoloProcessor(Node):
    def __init__(self):
        super().__init__('yolo_processor')
        self.subscription = self.create_subscription(Image, 'video_frames', self.image_callback, 10)
        self.publisher = self.create_publisher(String, 'yolo_detections', 10)
        self.bridge = CvBridge()
        self.model = YOLO("yolov5s.pt")  # make sure this is available in container

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        results = self.model.predict(source=frame, conf=0.5, classes=[0], verbose=False)[0]  # class 0 = person
        boxes = []
        for box in results.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()
            boxes.append({"x1": x1, "y1": y1, "x2": x2, "y2": y2})
        self.publisher.publish(String(data=json.dumps(boxes)))
