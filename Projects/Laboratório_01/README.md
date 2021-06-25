## Laboratório 1:  
   O objetivo deste laboratório é o de dar os primeiros passos no estudo do funcionamento do microcontrolador Tiva TM4C1294XL (Cortex-M4).  
   Dentre os temas estudados nesta prática, estão: 
   - Projetos no IAR EWARM
   - Temporização por hardware e por software
   - Biblioteca TivaWare
   - Driverlib-GPIO
   - Driverlib – SYSCTL
   - Clareza e Legibilidade de código

   O código desenvolvido (./src/Lab1.c) foi utilizado para trocar o estado do LED 4 da placa a cada segundo a partir de Software, e não de interrupções de hardware.  

![](.\Figures\Lab1_Fluxograma.jpg)

#### Pergunta 1 da prática:  
    Depois de ter verificado a temporização por laços de atraso, teste o comportamento do sistema para as seguintes alterações:
        1. Diferentes níveis de otimização do compilador C
        2. Frequência de clock (PLL) de 120MHz  
    Há variações na temporização por software para os casos acima? Quantifique-as.
#### Resposta:
    Seguindo a ideia da função para definição do período de acionamento do Handler do SysTick, SysTickPeriodSet(x), com valor de x = 12 MHz para a  frequência de clock de 24 MHz, tendo que x = clock/2, defini o número de iterações para a temporização como o valor da frequência de clock dividida pela constante de atraso do sistema.
    Para o arranjo 1 (24 MHz e otimização baixa), a constante de clock para obter 1Hz no piscar do LED 4 foi de 12.
    Para o arranjo 2 (compilador e otimização alta), o número de iterações seria elevado demais para um inteiro, portanto ocorreu mudança significativa em performance. 
    Para o arranjo 3 (clock em 120 MHz e otimização baixa), a constante de atraso foi de 24.  

    Assim, concluí que há variações na temporização por software para os casos acima.

#### Pergunta 2 da prática:  
    Os seguintes trechos de código são equivalentes:
    1. GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
    2. GPIOPinWrite(0x40025000, 0x00000010, 0x00000010);
    - Qual dos trechos de código acima é mais legível e fácil de se compreender?
#### Resposta:
    O código 1, pois há a aplicação de parametrização. Valores hard-coded no código são de difícil compreensão, exceto quando há bons comentários e boas justificativas para deixá-los explícitos.

#### Pergunta 3 da prática:
    Os seguintes trechos de código são equivalentes:
    1. GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);
    2. GPIOPinTypeGPIOOutput(0x40025000, 0x00000011);
    - Qual dos trechos de código acima é mais legível e fácil de se compreender?
    Obs: GPIO_PIN_0=0x01; GPIO_PIN_4=0x10
#### Resposta:
    O código 1, pois há a aplicação de parametrização. Valores hard-coded no código são de difícil compreensão, exceto quando há bons comentários e boas justificativas para deixá-los explícitos.
