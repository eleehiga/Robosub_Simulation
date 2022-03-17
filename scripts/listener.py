import rospy
from sensor_msgs.msg import Image as msg_Image
import numpy as np

def callback(data):
    # rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data)
    print(data.header)
    print(data.height)
    print(data.width)
    print(data.encoding)
    print(data.is_bigendian)
    print(data.step)
    print(data.data[0])
    image = np.array(data.data)

def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('/realsense_plugin/camera/color/image_raw', msg_Image, callback)
    

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
