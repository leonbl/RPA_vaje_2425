#include <Arduino.h>
#define led1 16
#define led2 17
#define tipka 15

TaskHandle_t led_h;
SemaphoreHandle_t sem;

bool stanje = true;
int staro_stanje_tipke = 1;

void task_led1(void *parameter)
{
  pinMode(led1, OUTPUT);
  while (1)
  {
    xSemaphoreTake(sem,portMAX_DELAY);
    for (int n = 0; n < 5; n++)
    {
      digitalWrite(led1, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(led1, LOW);
      vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    xSemaphoreGive(sem);
    yield();
  }
  vTaskDelay(1);
}

void task_led2(void *parameter)
{
  pinMode(led2, OUTPUT);
  while (1)
  {
    xSemaphoreTake(sem,portMAX_DELAY);
    for (int n = 0; n < 5; n++)
    {
      digitalWrite(led2, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(led2, LOW);
      vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    xSemaphoreGive(sem);
    yield();
  }
  vTaskDelay(1);
}

void task_tipka(void *parameter)
{
  pinMode(tipka, INPUT);
  while (1)
  {
    int stanje_tipke = digitalRead(tipka);
    if (staro_stanje_tipke == 0 && stanje_tipke == 1)
    {
      stanje = !stanje;
      if (stanje)
      {
        vTaskResume(led_h);
      }
      else
      {
        vTaskSuspend(led_h);
      }
    }
    staro_stanje_tipke = stanje_tipke;
    vTaskDelay(1);
  }
}

void setup()
{
  Serial.begin(9600);
  xTaskCreate(task_led1, "t1", 3000, NULL, 1, NULL);
  xTaskCreate(task_led2, "t2", 3000, NULL, 1, NULL);
  xTaskCreate(task_tipka, "t3", 3000, NULL, 1, NULL);
  sem = xSemaphoreCreateBinary();
  xSemaphoreGive(sem);
}

void loop()
{
}