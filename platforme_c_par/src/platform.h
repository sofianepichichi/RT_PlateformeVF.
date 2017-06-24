#ifndef PLATFORM_H
#define PLATFORM_H

#include<iostream>
#include<fstream>
#include <pthread.h>

void affiche(struct task_params* tp,int nbr);

int  getTaskParams(char* src,struct task_params* ArrayOfTask);

int writeFileToFile(char *src,ofstream *dst);

int InsertRTIncludes(char *src, ofstream *out);

int detect_task(char *src,ofstream *out,struct task_params* ArrayOfTask,int nbr_taches);

int writeTaskParams(struct task_params params, ofstream *dst);

int writeTask_Main(ofstream *dst,struct task_params ArrayOfTask, pthread_t Tab);

int Insert_MainCode_thread(char *src, ofstream *out);

int writeTask_Main_Join(ofstream *dst, struct task_params ArrayOfTask ,pthread_t Tab);

int Insert_MainCode_header(ofstream *out, struct task_params params, pthread_t Tab);

int Insert_MainCode_Join(ofstream *out, struct task_params params, pthread_t Tab);

int extractMethod(char *MethodName, char *src, char *dst);

int bracketsUpdate(string line, int n);

int InsertRTCode(char *src, ofstream *out, task_params params,pthread_t Tab);


#endif
