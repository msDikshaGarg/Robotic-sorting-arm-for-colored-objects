# green = np.uint8([[[0,255,0 ]]])
# hsv_green = cv2.cvtColor(green,cv2.COLOR_BGR2HSV)
# print hsv_green
# pink = [[[ 60 255 255]]]
# blue = 50,50,70
# Import OpenCV
import cv2
#Import Numpy
import numpy as np
from picamera.array import PiRGBArray
from picamera import PiCamera

camera = PiCamera()

camera_feed = cv2.VideoCapture(0)
camera_feed.set(cv2.CAP_PROP_FPS, 1)
while(1):
    _,frame = camera_feed.read()
    #Convert the current frame to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    #Define the threshold for finding a blue object with hsv
    lower_blue = np.array([110,100,100])
    upper_blue = np.array([130,255,255])
    #Create a binary image, where anything blue appears white and everything else is black
        mask = cv2.inRange(hsv, lower_blue, upper_blue)
    #Get rid of background noise using erosion and fill in the holes using dilation and erode the final image on last time
        element = cv2.getStructuringElement(cv2.MORPH_RECT,(3,3))
        mask = cv2.erode(mask,element, iterations=2)
        mask = cv2.dilate(mask,element,iterations=2)
        mask = cv2.erode(mask,element)
    #Create Contours for all blue objects
    _, contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    maximumArea = 0
    bestContour = None
    for contour in contours:
        currentArea = cv2.contourArea(contour)
        if currentArea>maximumArea:
            bestContour = contour
            maximumArea = currentArea
    #Create a bounding box around the biggest blue object
            if bestContour is not None:
                x,y,w,h = cv2.boundingRect(bestContour)
                cv2.rectangle(frame, (x,y),(x+w,y+h), (0,0,255), 3)
    #print(x,y)
    #Show the original camera feed with a bounding box overlayed
    cv2.imshow('frame',frame)
    #Show the contours in a seperate window
    cv2.imshow('mask',mask)
    #Use this command to prevent freezes in the feed
    k = cv2.waitKey(5) & 0xFF
    #If escape is pressed close all windows
    if k == 27:
    break
cv2.destroyAllWindows()
camera_feed.release()