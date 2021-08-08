#!/usr/bin/env python3

from math import degrees, pi
from time import sleep

import rclpy
from rclpy.node import Node
from serial import Serial
from std_msgs.msg import String


def get_serial_conn():
    conn = Serial('/dev/ttyACM0', baudrate=9600, timeout=3)
    sleep(3)
    return conn

class JointCmdSubscriber(Node):
    def __init__(self, serial_conn):
        super().__init__('joint_pos_cmd_subscriber')
        self.serial_conn = serial_conn
        self.subscription = self.create_subscription(String, '/driver/joint_cmd', self.listener_cb, 10)
    
    def listener_cb(self, msg):
        try:
            cmd = float(msg.data)
            servo_angle = degrees(cmd)
            self.serial_conn.write(f'{servo_angle}\n'.encode())
        except:
            pass

if __name__ == '__main__':
    conn = get_serial_conn()
    rclpy.init(args=None)
    
    motor_vel_cmd_subscriber = JointCmdSubscriber(conn)
    
    rclpy.spin(motor_vel_cmd_subscriber)

    motor_vel_cmd_subscriber.destroy_node()
    rclpy.shutdown()

