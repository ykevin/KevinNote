#!/usr/bin/python 

import rospy
from geometry_msgs.msg import Twist
from math import pi

class TestTurtlesim():
    def __init__(self):
        #rospy.init_node('move_turtlesim', log_level=rospy.DEBUG, anonymous=False)
        rospy.init_node('move_turtlesim',  anonymous=False)

        rospy.on_shutdown(self.shutdown)

        #self.cmd_vel = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=1)
        self.cmd_vel = rospy.Publisher('~/cmd_vel', Twist, queue_size=1)

        self.linear_speed = rospy.get_param("~linear_speed", 2)
        self.goal_distance = rospy.get_param("~goal_distance", 10)
        #rospy.logdebug('Debug info data : %d, %d', self.linear_speed, self.goal_distance)
        rospy.loginfo('Debug info data : %d, %d', self.linear_speed, self.goal_distance)

        rate = 50

        r = rospy.Rate(rate)


        linear_duration = self.goal_distance / self.linear_speed

        move_cmd = Twist()
        move_cmd.linear.x = self.linear_speed
        
        ticks = int(linear_duration * rate)
        for t in range(ticks):
            self.cmd_vel.publish(move_cmd)
            r.sleep()

        move_cmd = Twist()
        self.cmd_vel.publish(move_cmd)
        rospy.sleep(1)

        self.cmd_vel.publish(Twist())

    def shutdown(self):
        rospy.loginfo('Stopping the robot...')
        self.cmd_vel.publish(Twist())
        rospy.sleep(1)

if __name__ == '__main__':
    try:
        TestTurtlesim()
    except :
        rospy.loginfo('Test node terminated !')
