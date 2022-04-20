#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void openDataFile(char dataFileName[], FILE **pointerToDataFile);
void createOutputFile(char outputFileName[], FILE **pointerToOutputFile);
void closeFiles(FILE **pointerToDataFile, FILE **pointerToOutputFile);
void allocateMemory(char **pointerToData, int *stringLenght);
void deleteWords(char data[], int *stringLenght);
void print(char **pointerToData, char data[], int *stringLenght);

#endif // HEADER_H_INCLUDED
