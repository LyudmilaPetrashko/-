Ввод:

enter the number of experiments(value 1): 5

enter the digitizing error(value 1): 0.1
enter the calibration error(value 1): 0.1

enter the result of the 1 experiment(value 1): 12.3
enter the result of the 2 experiment(value 1): 12.4
enter the result of the 3 experiment(value 1): 12.5
enter the result of the 4 experiment(value 1): 12.6
enter the result of the 5 experiment(value 1): 12.7


enter the number of experiments(value 2): 5

enter the digitizing error(value 2): 0.05
enter the calibration error(value 2): 0.05

enter the result of the 1 experiment(value 2): 45.65
enter the result of the 2 experiment(value 2): 45.6
enter the result of the 3 experiment(value 2): 45.7
enter the result of the 4 experiment(value 2): 45.65
enter the result of the 5 experiment(value 2): 45.65

  
Вывод:                                                          Проверка:

value 1=(12.5+-0.3)                                               верно
value 2=(45.65+-0.1)                                              верно
Addition_value1+value2=(58.2+-0.3)                                верно
Addition_value1+double(5)=(17.5+-0.3)                             верно              
Subtraction_value1-value2=(-33.2+-0.3)                            верно
Subtraction_value1-double(5)=(7.5+-0.3)                           верно
Multiplication_value1*value2=(570.6+-13.8)                        верно
Multiplication_value1*double(5)=(62.5+-0.3)                       верно
Division_value1/value2=(0.274+-0.007)                             верно
Division_value1/double(5)=(2.5+-0.3)                              верно
Control=(165.44+-0.12) /*control=5+(t/r)*76-7+(t*t/r)*43-0.55;*/  верно 
