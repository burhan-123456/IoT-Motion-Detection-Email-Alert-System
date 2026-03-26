# IoT-Motion-Detection-Email-Alert-System
An IoT-based motion detection system using a PIR sensor and ESP8266 that sends real-time email alerts when motion is detected.
# 🚨 IoT Motion Detection Email Alert System

## 📌 Project Overview

This project is an IoT-based motion detection system that uses a PIR (Passive Infrared) sensor and an ESP8266 (NodeMCU) microcontroller to detect motion and send real-time email alerts.

When motion is detected, the system triggers an alert and immediately sends an email notification to a predefined recipient. This solution is ideal for home security, surveillance, and smart automation applications.

---

## 🎯 Features

* 📡 Real-time motion detection using PIR sensor
* 📧 Instant email notifications on motion detection
* 🌐 Wi-Fi enabled using ESP8266 (NodeMCU)
* ⚡ Low-cost and energy-efficient system
* 🏠 Suitable for home and office security

---

## 🧰 Components Used

* ESP8266 (NodeMCU)
* PIR Motion Sensor (HC-SR501)
* Jumper wires
* Breadboard (optional)
* Power supply (USB / battery)

---

## ⚙️ How It Works

1. The PIR sensor continuously monitors infrared radiation in its surroundings.
2. When a human or object moves, the sensor detects a change in IR levels.
3. The ESP8266 reads the signal from the PIR sensor.
4. Upon detection, the ESP8266 connects to Wi-Fi.
5. An email alert is sent to the user using an SMTP server.

---

## 🔌 Circuit Connections

* PIR VCC → 3.3V (or Vin) on ESP8266
* PIR GND → GND
* PIR OUT → Digital pin (e.g., D5)

---

## 💻 Installation & Setup

### 1️⃣ Prerequisites

* Arduino IDE installed
* ESP8266 board package installed
* Required libraries (if any for email/SMTP)

---

### 2️⃣ Steps to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/repo-name.git
   ```

2. Open the code in Arduino IDE

3. Update the following in code:

   * Wi-Fi SSID and Password
   * Email credentials (SMTP server, sender email, password)
   * Receiver email address

4. Select board:

   ```
   NodeMCU 1.0 (ESP-12E Module)
   ```

5. Upload the code to ESP8266

6. Open Serial Monitor to check status

---

## 📧 Email Configuration

* SMTP Server: (e.g., Gmail SMTP)
* Port: 465 / 587
* Sender Email: Your email
* App Password: Required (for Gmail)

⚠️ **Note:** Use app passwords instead of your main email password for security.

---

## 🧪 Output

* When motion is detected, an email alert is sent instantly
* Serial monitor displays detection logs

---

## 🚀 Applications

* 🏠 Home security systems
* 🏢 Office monitoring
* 🚪 Intrusion detection
* 🤖 Smart automation systems

---

## 🔮 Future Improvements

* Add buzzer or alarm system
* Integrate mobile app notifications
* Store logs in cloud (Firebase / AWS)
* Add camera module for image capture

---

## 📚 Tech Stack

* Embedded C (Arduino IDE)
* ESP8266 Wi-Fi Module
* PIR Sensor
* SMTP Protocol (Email Service)

---

## 🤝 Contributing

Contributions are welcome! Feel free to fork this repo and submit a pull request.

---

## 📄 License

This project is open-source and available under the MIT License.

---

## 👨‍💻 Author

**Your Name**

* GitHub: https://github.com/your-username

