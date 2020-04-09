# Qt-C
PL
To jest projekt przedstawiający symulację przepływu cieczy przez zbiornik. 
Ciecz doprowadzana jest za pomocą trzech zaworów: ciepła woda, zimna woda i zakłócenia, o określonej, stałej temperaturze natomiast wypływ jest swobodny.
Przyciski  „Rozpocznij symulację” oraz „Zakończ symulację” rozpoczynają i kończą proces przepływu.
Przyciski  „Rozpocznij zbieranie” oraz „Zakończ zbieranie” powodują rozpoczęcie procesu zapisywania danych procesowych i odpowiednio zakończenie tego procesu.
Jest możliwość sterowania ręcznego procesem poprzez regulację przepływu cieczy do zbiornika, z możliwością włączenia zakłóceń losowych za pomocą checkbox „Zakł. Losowe” i możliwością powrotu do początkowych ustawień (punktu pracy) klikając „Powrót do PP”
Na wykresie za pomocą wyboru odpowiedniego checkbox (Temperatura, Wysokość) przedstawiane są zmiany temperatury lub wysokości cieczy w zbiorniku. Rysowana jest wartość aktualna jak i wartość zadana do regulacji)
W sekcji „Monitoring” wyświetlane są wartości temperatury i wysokości cieczy w zbiorniku oraz po przekroczeniu wartości dopuszczalnych temperatury lub wysokości zaczynają migać diody kontrolne i dostępny jest przycisk, który wyłącz kontrolkę i powoduje powrót do wartości początkowych w zbiorniku.
Zaimplementowane są również dwa regulatory PID regulujące temperaturę i wysokość cieczy w zbiorniku, z możliwością zmiany nastaw oraz wartości zadanych. Jest również zaimplementowany regulator z algorytmem LQR, który reguluje obie wielkości jednocześnie. Regulatory włącza się odpowiednimi checkboxes.


ENG 
This is a project that simulates the flow of liquid through a tank. 
The liquid is supplied by three valves: hot water, cold water and interference, with a specific, constant temperature, while the flow is free.
The "Rozpocznij Symulację" and "Zakończ symulację" buttons start and end the flow process.
The buttons " Rozpocznij zbieranie " and "Zakończ zbieranie" start the process data and end the process accordingly.
It is possible to control the process manually by regulating the flow of liquid to the tank, with the possibility of activating random disturbances by means of the "Zakł. losowe" checkbox and the possibility of returning to the initial settings (working point) by clicking "Powrót do PP".
The chart shows changes in temperature or height of the liquid in the tank by selecting the appropriate checkbox (Temperature, Height). The current value as well as the setpoint to be controlled is drawn)
In the "Monitoring" section, the temperature and altitude values of the liquid in the tank are displayed and when the temperature or altitude values are exceeded, the control LEDs start flashing and a button is available to switch off the control and return to the initial values in the tank.
There are also two PID controllers for regulating the temperature and height of the liquid in the tank, with the possibility of changing the settings and setpoints. There is also implemented a regulator with the LQR algorithm, which regulates both values simultaneously. The regulators are switched on with appropriate checkboxes.
