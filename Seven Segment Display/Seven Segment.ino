int seven[]={11,10,9,8,7,6,5,4};
void show(int num) {
if(num==0)
{
digitalWrite(seven[0],HIGH);
digitalWrite(seven[1],HIGH);
digitalWrite(seven[2],HIGH);
digitalWrite(seven[3],HIGH);
digitalWrite(seven[4],HIGH);
digitalWrite(seven[5],HIGH);
digitalWrite(seven[6],HIGH);
digitalWrite(seven[1],HIGH); }}
void setup(){
for(int i=0;i<8;i++){
pinMode(seven[i],OUTPUT);}}
void loop()
{
show(0);
}
int seven[] = {11, 10, 9, 8, 7, 6, 5, 4}; // Pins connected to seven-segment display segments
// Function to display a digit on the seven-segment display void showDigit(int digit) {
// Define the common cathode seven-segment display's segments for each digit (0-9)
int segments[10][7] = {
{1, 1, 1, 1, 1, 1, 0}, // 0
{0, 1, 1, 0, 0, 0, 0}, // 1
{1, 1, 0, 1, 1, 0, 1}, // 2
{1, 1, 1, 1, 0, 0, 1}, // 3
{0, 1, 1, 0, 0, 1, 1}, // 4
{1, 0, 1, 1, 0, 1, 1}, // 5
{1, 0, 1, 1, 1, 1, 1}, // 6
{1, 1, 1, 0, 0, 0, 0}, // 7
{1, 1, 1, 1, 1, 1, 1}, // 8
{1, 1, 1, 1, 0, 1, 1} // 9
};
// Display the segments for the given digit
for (int i = 0; i < 7; i++) {
digitalWrite(seven[i], segments[digit][i]);
}
}
void setup() {
for (int i = 0; i < 8; i++) {
pinMode(seven[i], OUTPUT);
}
}
void loop() {
for (int num = 0; num < 10; num++) {
showDigit(num);
delay(1000);
// Delay for 1 second before displaying the next digit }
}
/*
For connecting the seven-segment display to the Arduino, typically each segment of the display is connected to a digital pin of the Arduino.In your case, you have the following pin
mapping:
Pin 11: Segment 'a’
Pin 10: Segment 'b’
Pin 9: Segment 'c’
Pin 8: Segment 'd’
Pin 7: Segment 'e’
Pin 6: Segment 'f’
Pin 5: Segment ‘g’
Pin 4: Common Cathode (connected to GND)
You need to connect these pins accordingly to your seven-segment display.Connect each segment (a, b, c, d, e, f, g) to the corresponding pin on the Arduino and the common
cathode to the GND pin on the Arduino. Make sure to verify the datasheet of your specific seven-segment display to ensure correct pin connections.*/
HOW IT WORKS?
https://www.youtube.com/watch?v=fYAlE1u5