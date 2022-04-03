#include <math.h>
const int thermistor_output = A1;
int increment;
void setup() {
  Serial.begin(9600); 
}
void loop() {
  int thermistor_adc_val;
  double output_voltage, thermistor_resistance, therm_res_ln, temperature; 
  thermistor_adc_val = analogRead(thermistor_output);
  output_voltage = ( (thermistor_adc_val * 5.0) / 1023.0 );
  thermistor_resistance = ( ( 5 * ( 10.0 / output_voltage ) ) - 10 ); 
  thermistor_resistance = thermistor_resistance * 1000 ; 
  therm_res_ln = log(thermistor_resistance);
  temperature = ( 1 / ( 0.001129148 + ( 0.000234125 * therm_res_ln ) + ( 0.0000000876741 * therm_res_ln * therm_res_ln * therm_res_ln ) ) );
  temperature = (temperature - 273.15)*2.7;
  Serial.print("Temperature in degree Celsius = ");
  Serial.print(temperature);
  Serial.print("\t\t");
  Serial.print("\n\n");
  if(temperature>25.5){
    increment++;
  }
  delay(500);
}
