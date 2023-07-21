# Arduino_Connect_ESP_to_httpClient
### How it works:
This Arduino code connects to a Wi-Fi network, fetches a webpage, and performs actions based on the content of the webpage. It uses the WiFi.h and HTTPClient.h libraries to establish a Wi-Fi connection and make HTTP requests. The SSID and password for the Wi-Fi connection are defined as SSID and password, and the URL of the webpage to retrieve is stored in url.

In the setup() function, the program initiates a serial communication for debugging, connects to the Wi-Fi network, and prints the assigned IP address. Then it tries to fetch the webpage's content.

The loop() function executes the main logic of the program. It uses the HTTPClient class to send a GET request to the defined URL. If the request is successful (indicated by a positive HTTP response code), it retrieves the web page's content (payload) and prints it. If the payload is the string "forward", it sets the digital pin 25 HIGH so the LED will turn on, otherwise, it sets it LOW so the LED will turn off. If the HTTP request fails, it prints the corresponding error message. The loop() function repeats every 5 seconds (5000 milliseconds).
### This is the simulation of the Arduino structure
![image](https://github.com/Rama-Alyoubi/Arduino_Connect_ESP_to_httpClient/assets/128150728/1e01ffb8-be67-48ab-8569-9b047e701d13)
![image](https://github.com/Rama-Alyoubi/Arduino_Connect_ESP_to_httpClient/assets/128150728/a7de35b8-537f-4132-8da3-6ffb8ea88274)
