#include <ESP8266WiFi.h>
#include <ESP_Mail_Client.h>

// WiFi Credentials
#define WIFI_SSID "Nord2"
#define WIFI_PASSWORD "123456789"

// Email Credentials (Use App Password for Gmail)
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "iotburhan8@gmail.com"
#define AUTHOR_PASSWORD "toywsdryvmonevzb"
#define RECIPIENT_EMAIL "iotburhan8@gmail.com"

// PIR Sensor Pin
#define PIR_PIN D2

// SMTP Session Object
SMTPSession smtp;

// Track last motion detection time to prevent email spam
unsigned long lastMotionTime = 0;
const unsigned long emailCooldown = 30000;  // 30 seconds cooldown between emails

void setup() {
    Serial.begin(115200);
    pinMode(PIR_PIN, INPUT);
    connectToWiFi();
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Lost! Reconnecting...");
        connectToWiFi();
    }

    if (digitalRead(PIR_PIN)) {
        unsigned long currentTime = millis();
        if (currentTime - lastMotionTime > emailCooldown) {
            Serial.println("Motion Detected! Sending Email...");
            sendEmail();
            lastMotionTime = currentTime;
            delay(5000);  // Small delay to avoid multiple triggers
        }
    }

    delay(1000);  // Check PIR sensor every second
}

// Function to connect to WiFi
void connectToWiFi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) { // 10 seconds timeout
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi Connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nWiFi Connection Failed! Retrying in 10 seconds...");
        delay(10000);  // Wait before retrying
        connectToWiFi();
    }
}

// Function to send an email alert
void sendEmail() {
    // Configure SMTP session
    ESP_Mail_Session session;
    session.server.host_name = SMTP_HOST;
    session.server.port = SMTP_PORT;
    session.login.email = AUTHOR_EMAIL;
    session.login.password = AUTHOR_PASSWORD;
    session.login.user_domain = "smtp.gmail.com";  // Optional but recommended

    // Enable SSL for secure email sending
    session.secure.startTLS = false;  // Use SSL, not STARTTLS

    // Connect to SMTP server
    if (!smtp.connect(&session)) {
        Serial.println("SMTP connection failed: " + smtp.errorReason());
        return;
    }

    // Create email message
    SMTP_Message message;
    message.sender.name = "NodeMCU PIR Sensor";
    message.sender.email = AUTHOR_EMAIL;
    message.subject = "🚨 Motion Alert!";
    message.addRecipient("User", RECIPIENT_EMAIL);

    // Email Body
    message.text.content = "Alert! Motion detected by your PIR sensor.";
    message.text.charSet = "utf-8";
    message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

    // Send email
    if (!MailClient.sendMail(&smtp, &message)) {
        Serial.println("Email failed: " + smtp.errorReason());
    } else {
        Serial.println("✅ Email sent successfully!");
    }
}
