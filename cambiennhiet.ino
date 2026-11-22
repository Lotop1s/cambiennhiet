// Khai báo các chân kết nối
const int sensorPin = A0;   // Chân tín hiệu cảm biến nhiệt độ TMP36
const int redLedPin = 13;   // LED Đỏ cảnh báo
const int greenLedPin = 8;  // LED Xanh bình thường
// Ngưỡng nhiệt độ cảnh báo (°C)
const float TEMP_THRESHOLD = 30.0;
void setup() {
  Serial.begin(9600);  
  // Cấu hình các chân LED là OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}
void loop() {
  // 1. Đọc giá trị analog từ cảm biến (0 - 1023)
  int rawValue = analogRead(sensorPin);
  // 2. Đổi giá trị đọc sang điện áp (Volt)
  float voltage = rawValue * (5.0 / 1024.0);
  // 3. Công thức tính nhiệt độ chuẩn của cảm biến TMP36:
  // TMP36 xuất 500mV ở 0°C và tăng 10mV mỗi 1°C
  float temperatureC = (voltage - 0.5) * 100.0;
  // In ra Serial Monitor để theo dõi
  Serial.print("Dien ap: ");
  Serial.print(voltage);
  Serial.print(" V | Nhiet do: ");
  Serial.print(temperatureC);
  Serial.println(" *C");
  // 4. Điều kiện điều khiển 2 LED
  if (temperatureC >= TEMP_THRESHOLD) {
    // Quá nhiệt: Bật LED đỏ, tắt LED xanh
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    // Bình thường: Bật LED xanh, tắt LED đỏ
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
  delay(500); // Đọc lại sau mỗi 0.5 giây
}