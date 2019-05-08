import cv2
import numpy as np
from keras.models import load_model
faceCascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

video_capture = cv2.VideoCapture(0)
model = load_model('keras_model/fer2013myCNN.99-0.61.hdf5')

target = ['angry','disgust','fear','happy','sad','surprise','neutral']
font = cv2.FONT_HERSHEY_SIMPLEX
while True:
    # Capture frame-by-frame    
    ret, frame = video_capture.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(gray,scaleFactor=1.2)

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2,5)
        face_crop = frame[y:y+h,x:x+w]
        face_crop = cv2.resize(face_crop,(48,48))
        face_crop = cv2.cvtColor(face_crop, cv2.COLOR_BGR2GRAY)
        face_crop = face_crop.astype('float32')/255
        face_crop -= 0.5
        face_crop *= 2
        # face_crop = np.asarray(face_crop)
        # print(face_crop.shape)
        face_crop = face_crop.reshape(1, face_crop.shape[0],face_crop.shape[1], 1)
        # print(face_crop.shape)
        k = model.predict(face_crop)
        print(k)
        result = target[np.argmax(k)] + ' ' + str(round(k[0][np.argmax(k)],2))
        print(result)
        cv2.putText(frame,result,(x,y), font, 1, (200,0,0), 2, cv2.LINE_AA)
        print()
    # Display the resulting frame
    cv2.imshow('Video', frame)

    if cv2.waitKey(10) & 0xFF == ord('q'):
        break

video_capture.release()
cv2.destroyAllWindows()
