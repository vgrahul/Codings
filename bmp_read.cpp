#include <iostream>
#include <cstdio>
#include <fstream>





//static int key1[] = { 23, 14, 0, 20, 10, 16, 19, 8, 6, 12, 18, 13, 9, 21, 11, 2, 4, 1, 7, 22, 5, 17, 15, 3};

//static int key2[] = { 13, 9, 21, 11, 2, 4, 1, 7, 22, 5, 17, 15, 3, 23, 14, 0, 20, 10, 16, 19, 8, 6, 12, 18};




using namespace std;
unsigned char* ReadBMP(char* , int*);

int main(){

 //cout<<" HELLLLOOOOO \n\n\n";

 unsigned char* temp;
 int* array;

 char* fname = "Myfile.bmp";

 temp = ReadBMP(fname,array);

return 0;
}


unsigned char* ReadBMP(char* filename, int* array){

 FILE* img = fopen(filename, "rb");   //read the file

 FILE* newimg = fopen("newfile.bmp","wb"); // write new bmp

 FILE* dummy = fopen("bintext.txt","a"); //write to text

  std::fstream fs;
  fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);


 unsigned char header[54]; 
 fread(header, sizeof(unsigned char), 54, img); // read the 54-byte header

 fwrite(header, sizeof(unsigned char), 54, newimg); // write header to new bmp
 

  

   // extract image height and width from header 
 int width = *(int*)&header[18];     
 int height = *(int*)&header[22]; cout<<"\n Height = "<<height;     
 int padding=0; while ((width*3+padding) % 4!=0) padding++;

 int widthnew=width*3+padding;

 unsigned char* data = new unsigned char[widthnew]; 
  
 int flag  = 0;

 for (int i=0; i<height; i++ ) {                                     

     fread( data, sizeof(unsigned char), widthnew, img);
     fwrite( data, sizeof(unsigned char), widthnew, newimg);


     for (int j=0; j<width*3; j+=3){
     //Convert BGR to RGB and store                       

     array[i*width+j+0] = data[j+2]; cout<<(int)data[j+2]<<' ';                              
     array[i*width+j+1] = data[j+1]; cout<<(int)data[j+1]<<' ';             
     array[i*width+j+2] = data[j+0]; cout<<(int)data[j+0]<<"\n\n"; 

    }
  }     

  fs.close();                    

 cout<<array<<'\n';
// txtfile.close();
 fclose(dummy);
 fclose(img); //close the file 
 fclose(newimg); // close the new file
}
	
