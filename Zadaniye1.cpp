#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

int main(){ 
       int r,a;
       std::vector<int> v1; // Создание начального вектора из чисел  
       std::vector<int> v2; // Создание конечного вектора из чисел
       float X=0;
       float Y=0;         
       fstream F1;  //открываем файл в режиме чтения поток для чтения
       F1.open("/home/fedor/Практика/initial.txt"); //Открытие файла в режиме чтения
       if (F1){ //Если файл найден  
               printf("Файл найден.\n");             
               while (!F1.eof()){ //Цикл до тех пор, пока не закончится файл 
                       F1>>a;  //чтение очередного значения из потока F1 в переменную a    
                       v1.push_back(a); // Добавление элемента в конец вектора v1 
               }
               F1.close(); //Закрытие потока чтения файла
               unsigned int vector1_size = v1.size(); //Сохранение количества элементов вектора v1
               vector1_size=vector1_size-1;
               printf("Исходный массив точек:\n");
               for (int i = 0; i < vector1_size; i=i+2) {                              
                       printf("    x=%d  y=%d\n",v1[i],v1[i+1]); // Вывод на экран элементов вектора                                                   
               }
               printf("Введите радиус.\n");
               scanf("%d",&r);
               printf("Полученный массив точек:\n");       
               for(int i = 0; i < vector1_size; i=i+2){                
                       if(pow((pow(v1[i],2)+pow(v1[i+1],2)),0.5)<=r){
                              v2.push_back(v1[i]);  // Добавление элемента в конец вектора v2 
                              v2.push_back(v1[i+1]);  // Добавление элемента в конец вектора v2 
                              printf("    x=%d  y=%d\n",v1[i],v1[i+1]);                              
                              X=X+v1[i];                             
                              Y=Y+v1[i+1];                                                                         
                       }
               }                 
               unsigned int vector2_size = v2.size(); //Сохранение количества элементов вектора v2
               ofstream F2; //Поток для записи
               F2.open("/home/fedor/Практика/end.txt", ios::out); //Открытие файла в режиме записи(при этом информация о существующем файле уничтожается)
               for(int i = 0; i < vector2_size; i=i+2){                       
                       F2<<v2[i]; //Запись очередного значения из вектора v2 в поток F2 
                       F2<<' '; // Запись пробела в поток F2
                       F2<<v2[i+1]<<'\n';  
               }
               F2.close(); //Закрытие потока записи файла
               printf("Центр масс:\n"); 
               vector2_size=vector2_size*0.5;
               X=X/vector2_size;
               Y=Y/vector2_size;  
               printf("    x=%f  y=%f\n",X,Y);                             
       }
       else{ //Если файл не найден
               printf("Файл не найден!!!\n");
       }
return 0;
}
