EESchema Schematic File Version 4
LIBS:button-board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 5F6127C4
P 4400 3000
F 0 "J1" H 4428 3026 50  0000 L CNN
F 1 "conn" H 4428 2935 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4400 3000 50  0001 C CNN
F 3 "~" H 4400 3000 50  0001 C CNN
	1    4400 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5F61284F
P 3500 3450
F 0 "#PWR01" H 3500 3200 50  0001 C CNN
F 1 "GND" H 3505 3277 50  0000 C CNN
F 2 "" H 3500 3450 50  0001 C CNN
F 3 "" H 3500 3450 50  0001 C CNN
	1    3500 3450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5F612977
P 3700 3300
F 0 "SW2" H 3700 3585 50  0000 C CNN
F 1 "B2" H 3700 3494 50  0000 C CNN
F 2 "button:SMD_Button" H 3700 3500 50  0001 C CNN
F 3 "" H 3700 3500 50  0001 C CNN
	1    3700 3300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5F6129FB
P 3700 2900
F 0 "SW1" H 3700 3185 50  0000 C CNN
F 1 "B1" H 3700 3094 50  0000 C CNN
F 2 "button:SMD_Button" H 3700 3100 50  0001 C CNN
F 3 "" H 3700 3100 50  0001 C CNN
	1    3700 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2900 3500 3300
Connection ~ 3500 3300
Wire Wire Line
	3500 3300 3500 3450
Wire Wire Line
	3500 2900 3500 2500
Wire Wire Line
	3500 2500 4200 2500
Wire Wire Line
	4200 2500 4200 2900
Connection ~ 3500 2900
Wire Wire Line
	4200 3000 4050 3000
Wire Wire Line
	4050 3000 4050 2900
Wire Wire Line
	4050 2900 3900 2900
Wire Wire Line
	4200 3100 3900 3100
Wire Wire Line
	3900 3100 3900 3300
Text Label 4200 2600 0    50   ~ 0
GND
Text Label 4000 2900 0    50   ~ 0
B1
Text Label 3950 3100 0    50   ~ 0
B2
$EndSCHEMATC
