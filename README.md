# Automatic-parking-barrier-AI-license-plate-recognition
Automatic parking barrier AI license plate recognition
This project is carried out in a school environment, by fourth year students from the general engineering school ECAM Rennes.
The goal is to use the ESP32-cam module. We therefore chose to have automatic private parking. The camera therefore serves us to detect
the license plate of the car presented in front of the barrier.


automatic parking project operation guide

download python 3.10.9.
download the requirements.txt file in your python 3.10.9 environment
change all folder paths to match yours (do this for all 4 files)
modify the wifi connection of the esp32-cam card.
modify the connection port of the barrier system (arduino module).
run app3.py file in command prompt (python app3.py in terminal)
Turn on your camera.
enable artificial intelligence (GetNumberInternationalLicensePlate_Yolov8_Filters_PaddleOCR_V3 file)
(AI links: https://github.com/ablanco1950/LicensePlate_Yolov8_Filters_PaddleOCR)

How to upload the code to your ESP32CAM:

1) Install the driver CH341
2) Open Arduino IDE
3) In "Board manager" search for ESP32 by "Espressif systems" and install it.
4) go to --> preference and copy this link in "addition boards manager URLs": https://dl.espressif.com/dl/package_esp32_index.json
5) Now choose "AI thinker ESP32-cam" and the right serial port
6) Open --> Exemple --> ESP32 --> Camera --> CameraWebServer
7) Try to upload it, if it's not working correctly try to reboot your computer
8) Modify mvtwifi with your ip and pin of your sensor.
9) upload it and it should work.




This project was carried out by Mathis OBERLIN, Eva SEVERIAN, Mathéo BERTIN, Abdou DIOP, Quentin WIMEZ and Basile GIRARD. We worked for about 2 months.
