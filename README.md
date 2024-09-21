# Sistema de Estabilização para Dispositivo de Auxílio a Deficientes Visuais

<p>Este repositório contém o firmware desenvolvido para um sistema de estabilização de baixo custo, projetado para dispositivos de auxílio a deficientes visuais. O sistema utiliza um giroscópio, um servo motor e um sensor ultrassônico para fornecer feedback de estabilização e detecção de obstáculos, contribuindo para a navegação segura de pessoas com deficiência visual.</p>

## Descrição do Projeto

<p>O projeto tem como objetivo criar um dispositivo acessível e eficiente, capaz de detectar alterações na inclinação e fornecer respostas adequadas por meio de um servo motor, ao mesmo tempo que emite um alerta por vibração quando obstáculos próximos são detectados. Ele foi desenvolvido utilizando os seguintes componentes:</p>

<ul>
  <li><strong>MPU6050</strong>: Giroscópio e acelerômetro para detectar a inclinação do dispositivo.</li>
  <li><strong>HC-SR04</strong>: Sensor ultrassônico para medir a distância de obstáculos.</li>
  <li><strong>Servo SG90</strong>: Responsável por estabilizar o dispositivo com base nos dados de inclinação.</li>
  <li><strong>Vibrador</strong>: Alerta o usuário quando obstáculos estão dentro de uma distância crítica.</li>
</ul>

## Componentes Utilizados

<ul>
  <li><strong>Arduino Nano</strong> ou equivalente</li>
  <li><strong>MPU6050</strong> (sensor de aceleração e giroscópio)</li>
  <li><strong>HC-SR04</strong> (sensor ultrassônico)</li>
  <li><strong>Servo SG90</strong></li>
  <li><strong>Vibrador</strong> (pequeno motor vibratório)</li>
  <li>Diversos resistores e fiação para conexão dos componentes</li>
</ul>

## Funcionamento

<p>O firmware controla a estabilização do dispositivo e a detecção de obstáculos. A cada iteração do loop principal:</p>

<ol>
  <li>O giroscópio e o acelerômetro MPU6050 medem a inclinação e os dados são processados para controlar o movimento de um servo motor SG90, ajustando a inclinação para manter o dispositivo estável.</li>
  <li>Um sensor ultrassônico HC-SR04 mede a distância até obstáculos. Quando a distância é inferior a 50 cm, o sistema ativa um motor vibratório para alertar o usuário.</li>
  <li>As leituras de inclinação são constantemente ajustadas e mapeadas para o movimento do servo, com o ângulo sendo impresso no monitor serial para análise.</li>
</ol>

## Como Usar

<ol>
  <li>Clone este repositório.</li>
  <li>Carregue o firmware em uma placa Arduino Nano (ou equivalente).</li>
  <li>Conecte os componentes ao Arduino conforme o diagrama no artigo associado a este projeto.</li>
  <li>Abra o monitor serial para acompanhar as leituras do giroscópio e do sensor ultrassônico.</li>
  <li>Utilize o dispositivo em ambientes controlados para testar o feedback de vibração e estabilização.</li>
</ol>

## Referências

<p>Este firmware faz parte de um artigo que descreve detalhadamente o desenvolvimento e as aplicações deste sistema. O artigo pode ser acessado nos anais da Latinoaware2024, com o título de "Desenvolvimento do sistema de estabilização para um dispositivo de auxílio a deficientes visuais de baixo custo".</p>

