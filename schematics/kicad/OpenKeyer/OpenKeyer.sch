EESchema Schematic File Version 4
EELAYER 30 0
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
L MCU_Module:Arduino_Nano_v3.x U1
U 1 1 61E88977
P 6100 3950
F 0 "U1" H 6100 2861 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 6100 2770 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 6100 3950 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 6100 3950 50  0001 C CNN
	1    6100 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 61E8985E
P 4350 3700
F 0 "J1" H 4268 3375 50  0000 C CNN
F 1 "Error Indicator" H 4268 3466 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 4350 3700 50  0001 C CNN
F 3 "~" H 4350 3700 50  0001 C CNN
	1    4350 3700
	-1   0    0    1   
$EndComp
$Comp
L Connector:AudioJack3_Ground J2
U 1 1 61E8C115
P 4350 4200
F 0 "J2" H 4332 4525 50  0000 C CNN
F 1 "Keyer" H 4332 4434 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Horizontal" H 4350 4200 50  0001 C CNN
F 3 "~" H 4350 4200 50  0001 C CNN
	1    4350 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4100 4750 4100
Wire Wire Line
	4950 4100 4950 4500
Wire Wire Line
	4950 5400 6100 5400
Wire Wire Line
	6100 5400 6100 4950
Wire Wire Line
	4550 4200 5050 4200
Wire Wire Line
	5050 4200 5050 3850
Wire Wire Line
	5050 3850 5600 3850
Wire Wire Line
	5600 3950 5150 3950
Wire Wire Line
	5150 3950 5150 4300
Wire Wire Line
	5150 4300 4550 4300
Wire Wire Line
	4350 4500 4950 4500
Connection ~ 4950 4500
Wire Wire Line
	4950 4500 4950 5400
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 61E8DD77
P 4350 3100
F 0 "J3" H 4268 2775 50  0000 C CNN
F 1 "Oscillator" H 4268 2866 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 4350 3100 50  0001 C CNN
F 3 "~" H 4350 3100 50  0001 C CNN
	1    4350 3100
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 61E8E3D8
P 4350 2550
F 0 "J4" H 4268 2225 50  0000 C CNN
F 1 "Visual Indicator" H 4268 2316 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 4350 2550 50  0001 C CNN
F 3 "~" H 4350 2550 50  0001 C CNN
	1    4350 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4550 3600 4750 3600
Wire Wire Line
	4750 3600 4750 4100
Connection ~ 4750 4100
Wire Wire Line
	4750 4100 4950 4100
Wire Wire Line
	4550 3000 4750 3000
Wire Wire Line
	4750 3000 4750 3600
Connection ~ 4750 3600
Wire Wire Line
	4550 2450 4750 2450
Wire Wire Line
	4750 2450 4750 3000
Connection ~ 4750 3000
Wire Wire Line
	5600 4550 5600 4500
Wire Wire Line
	5600 4500 5250 4500
Wire Wire Line
	5250 4500 5250 3100
Wire Wire Line
	5250 3100 4550 3100
$Comp
L Device:R_Small_US R2
U 1 1 61E90ECB
P 4950 2550
F 0 "R2" V 4745 2550 50  0000 C CNN
F 1 "220" V 4836 2550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" H 4950 2550 50  0001 C CNN
F 3 "~" H 4950 2550 50  0001 C CNN
	1    4950 2550
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 61E913FF
P 4950 3700
F 0 "R1" V 4745 3700 50  0000 C CNN
F 1 "220" V 4836 3700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" H 4950 3700 50  0001 C CNN
F 3 "~" H 4950 3700 50  0001 C CNN
	1    4950 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 3700 4550 3700
Wire Wire Line
	5050 3700 5400 3700
Wire Wire Line
	5400 3700 5400 3650
Wire Wire Line
	5400 3650 5600 3650
Wire Wire Line
	4850 2550 4550 2550
Wire Wire Line
	5050 2550 5250 2550
Wire Wire Line
	5250 2550 5250 3100
Connection ~ 5250 3100
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 61E92DCD
P 7400 4350
F 0 "J5" H 7480 4342 50  0000 L CNN
F 1 "I2C Bus" H 7480 4251 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 7400 4350 50  0001 C CNN
F 3 "~" H 7400 4350 50  0001 C CNN
	1    7400 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4350 6600 4350
Wire Wire Line
	7200 4450 6600 4450
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 61E93FC1
P 8450 2000
F 0 "J6" H 8530 1992 50  0000 L CNN
F 1 "VIN" H 8530 1901 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 8450 2000 50  0001 C CNN
F 3 "~" H 8450 2000 50  0001 C CNN
	1    8450 2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 61E948F4
P 7800 2000
F 0 "SW1" H 7800 2235 50  0000 C CNN
F 1 "SW_SPST" H 7800 2144 50  0000 C CNN
F 2 "" H 7800 2000 50  0001 C CNN
F 3 "~" H 7800 2000 50  0001 C CNN
	1    7800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 2000 8250 2000
Wire Wire Line
	7600 2000 7200 2000
Wire Wire Line
	6000 2000 6000 2950
Wire Wire Line
	8250 2100 8250 2400
Wire Wire Line
	8250 5400 6100 5400
Connection ~ 6100 5400
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 61E968FD
P 7200 1100
F 0 "J7" V 7164 912 50  0000 R CNN
F 1 "PWR LED" V 7073 912 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Horizontal" H 7200 1100 50  0001 C CNN
F 3 "~" H 7200 1100 50  0001 C CNN
	1    7200 1100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 61E97397
P 7200 1600
F 0 "R3" H 7268 1646 50  0000 L CNN
F 1 "220" H 7268 1555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" H 7200 1600 50  0001 C CNN
F 3 "~" H 7200 1600 50  0001 C CNN
	1    7200 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1500 7200 1300
Wire Wire Line
	7200 1700 7200 2000
Connection ~ 7200 2000
Wire Wire Line
	7200 2000 6000 2000
Wire Wire Line
	8250 2400 9100 2400
Wire Wire Line
	9100 2400 9100 1400
Wire Wire Line
	9100 1400 7300 1400
Wire Wire Line
	7300 1400 7300 1300
Connection ~ 8250 2400
Wire Wire Line
	8250 2400 8250 5400
$EndSCHEMATC
