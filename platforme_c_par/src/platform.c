#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
//#include "platform.h"
#define FIFO_SCHEDULER 0
using namespace std;
typedef struct task_params{
  int index;
  int periode;
  int deadline;
  int scheduler;
  int nbrIt;
  int priority;
  int affinity;
  string name;
} task_params;

void affiche(struct task_params* tp,int nbr){
    for(int i = 0 ; i < nbr ;i++){
        cout << "---------------" << endl;
        cout <<"Tache : "<< tp[i].index << endl<< "periode :"<<tp[i].periode << endl <<"name :"<<tp[i].name<<endl
        << "DeadLine :"<< tp[i].deadline << endl <<"scheduler :"<< tp[i].scheduler << endl
        << "nbrIt :"<< tp[i].nbrIt << endl << "priority :"<< tp[i].priority << endl << "affinity :"<< tp[i].affinity << endl;
        cout << "---------------" << endl;
    }
}

int  getTaskParams(char* src,struct task_params* ArrayOfTask)
{
    int numtach = -1;
    string ligne;
    int nbr =0;
    ifstream fichier (src);
    if (fichier.is_open())
    {
        while ( getline (fichier,ligne) )
        {
            if (ligne[ligne.size()-1] == ':'){
                numtach++;
                ArrayOfTask[numtach].index = atoi(ligne.substr(ligne.find("_")+1,ligne.find(":")).c_str());
                ArrayOfTask[numtach].name = ligne.substr(0,ligne.find(":")).c_str();
            }
            while (getline (fichier,ligne) && !ligne.empty()){
                string param = ligne.substr(0,ligne.find("=")-1);
                int val =atoi(ligne.substr(ligne.find("=")+1).c_str());
                //if(strcmp(param.c_str(),string("Index").c_str()) == 0){ ArrayOfTask[numtach].Index = val;continue; }
                if(strcmp(param.c_str(),string("periode").c_str())== 0) {ArrayOfTask[numtach].periode = val;continue;}
                if(strcmp(param.c_str(),string("deadline").c_str())== 0){   ArrayOfTask[numtach].deadline = val ;continue;}
                if(strcmp(param.c_str(),string("scheduler").c_str())== 0){  ArrayOfTask[numtach].scheduler = val;continue;}
                if(strcmp(param.c_str(),string("nbrIt").c_str())== 0)  {   ArrayOfTask[numtach].nbrIt = val;continue;}
                if(strcmp(param.c_str(),string("priority").c_str())== 0) {  ArrayOfTask[numtach].priority = val;continue;}
                if(strcmp(param.c_str(),string("affinity").c_str())== 0) {  ArrayOfTask[numtach].affinity = val;continue;}
            }

        }
    }else {
        cout << "le fichier n'existe pas ." << endl;
        return 0;
    }
    fichier.close();
    return numtach+1;
    return 0;
}



int writeFileToFile(char *src,ofstream *dst)
{
  string line;
  ifstream myfile2 (src);
  if (myfile2.is_open())
    {
      while ( getline (myfile2,line) )
	{
	  (*dst) << line << '\n';
	}
      myfile2.close();
      return 0;
    }
  return -1;
}



int InsertRTIncludes(char *src, ofstream *out)
{
  writeFileToFile("lib/_rt_includes.pl",out);
  return -1;
}



int detect_task(char *src,ofstream *out,struct task_params* ArrayOfTask,int nbr_taches)
{
  pthread_t Tab[nbr_taches];

  for (int i = 0; i < nbr_taches; ++i)
  {
     Tab[i]=i;
  }
  //pthread_t Tab[nbr_taches] ={'a1','b2','c3','d4','e5','f6','g7','h8'};

  ifstream myfile (src);
  cout << "struct task_params *cp= (struct task_params *) arg;" << endl;
  cout << "---------------" << endl;


struct task_params pd;
if (myfile.is_open())
  {
       //writeFileToFile("lib/rt_main_task.pl",out);

		for (int i=0 ; i<nbr_taches ; i++){

      cout << "pd.period =" <<ArrayOfTask[i].periode<<";" <<endl;
      cout << "pd.deadline ="<<ArrayOfTask[i].deadline<<";" <<endl;

      cout << "pthread_t " << Tab[i]<< ";"<<endl;
      cout << "param.sched_priority = " <<ArrayOfTask[i].priority<< ";"<<endl;
      cout << "pthread_attr_setschedparam(&attr, &param);"<< endl;
      cout << "pthread_create (""&"<<(Tab[i])<<",Null,"<<ArrayOfTask[i].name<<",(void *)&pd);"<<endl;
      cout << "---------------" << endl;
		}

    for ( int j=0; j<nbr_taches ; j++){
           cout <<"pthread_join ("<<Tab[j]<<",Null);"<< endl;
           cout << "---------------" << endl;
    }

}
  cout<<"}"<<endl;
     return 0;
}



int writeTaskParams(struct task_params params, ofstream *dst)
{
  (*dst) << "int index ="<<params.index<<";"<<endl;
  (*dst) << "int period ="<<params.periode<<";"<<endl;
  (*dst) << "int deadline ="<<params.deadline<<";"<<endl;
  // set scheduler
  (*dst) << "int nbrIt ="<<params.nbrIt<<";"<<endl;
  //(*dst) << "string name ="<<params.name<<";"<<endl;
  (*dst) << "int priority ="<<params.priority<<";"<<endl;
  (*dst) << "int affinity ="<<params.affinity<<";"<<endl;
  (*dst) <<endl<<endl;
  (*dst) << "struct timespec Begin, End;"<< endl;
  (*dst) << "int i=0;"<< endl;
  (*dst) << "int MissedDeadlines=0;"<<endl;
  (*dst) << "while(i<"<<params.nbrIt<<"){"<<endl;
  return 1;
}




int writeTask_Main(ofstream *dst,struct task_params ArrayOfTask, pthread_t Tab)
{

 (*dst) <<endl<<endl;
 (*dst) << "pd.period =" <<ArrayOfTask.periode<<";"<< endl;
 (*dst) << "pd.deadline ="<<ArrayOfTask.deadline<<";"<< endl;
 (*dst) << "pthread_t " <<"thread"<<Tab<< ";"<<endl;
 (*dst) << "param.sched_priority = " <<ArrayOfTask.priority<< ";"<< endl;
 (*dst) << "pthread_attr_setschedparam(&attr, &param);"<< endl;
 (*dst) << "pthread_create (&thread"<<Tab<<",NULL,"<<ArrayOfTask.name<<",(void *)&pd);"<< endl;
 (*dst) <<endl<<endl;

return -1;
}



int Insert_MainCode_thread(char *src, ofstream *out){

  writeFileToFile("lib/_rt_main_task.pl",out);
  return -1;

}



int writeTask_Main_Join(ofstream *dst, struct task_params ArrayOfTask ,pthread_t Tab)
{
 (*dst) << "pthread_join (thread"<<Tab<<",NULL);"<<endl;

 return -1;
}



int Insert_MainCode_header(ofstream *out, struct task_params params, pthread_t Tab)
{
        writeTask_Main(out,params,Tab);
  return -1;
}



int Insert_MainCode_Join(ofstream *out, struct task_params params, pthread_t Tab )

{
    writeTask_Main_Join(out,params,Tab);

    return -1;
}


int Insert_Main_footer(char *src, ofstream *out){

  writeFileToFile("lib/_rt_main_task_footer.pl",out);
  return -1;

}



int extractMethod(char *MethodName, char *src, char *dst){
  string line;
  ifstream myfile (src);
  ofstream tmp(dst);
  if (myfile.is_open())
    {
      while (getline (myfile,line) )
	{
	    size_t found = line.find(MethodName);
	    if (found!=string::npos)
	    {
	      tmp<<line<<endl;
	      int numberOfBrackets = 1 ;
	      while (numberOfBrackets !=0)
		{
		  getline (myfile,line);
		  for (int i=0; i<line.size();i++)
		    {
		      if (line[i]=='{'){
			numberOfBrackets +=1;
		      }
		      if (line[i]=='}'){
			numberOfBrackets -=1;
		      }
		    }
		  tmp<<line<<endl;
		}
	      myfile.close();
	      tmp.close();
	      return 0;
	    }
	}
    }
  myfile.close();
  tmp.close();
  return -1;
  }


int bracketsUpdate(string line, int n)
{
  for (int i=0; i<line.size();i++)
    {
      if (line[i]=='{')
	n+=1;
      if (line[i]=='}')
	n -=1;
    }
  return n;
}

int InsertRTCode(char *src, ofstream *out, task_params params,pthread_t Tab)
{
  string line;
  ifstream myfile (src);


  if (myfile.is_open())
    {
      while (getline (myfile,line) )
	{

	  size_t found = line.find("rt:");
	  if (found!=string::npos)
	    {
	      writeTaskParams(params,out);
	      writeFileToFile("lib/_rt_task_header.pl",out);
	      int numberOfBrackets = 1;
	      int firstRun=0;
	      while (numberOfBrackets !=0)
		{
		  if (firstRun == 0 ){
		    numberOfBrackets = 0;
		  }
		  firstRun ++;
		  getline (myfile,line);
		  numberOfBrackets=bracketsUpdate(line,numberOfBrackets);
		  (*out)<<line<<endl;
		  cout<<numberOfBrackets<<endl;
		}
      	      writeFileToFile("lib/_rt_task_footer.pl",out);



	    }
	  else {
		  (*out)<<line<<endl;
	  }
	}

    }
  return -1;
}


int main(int argc, char** argv)
{
  task_params tp = {1,100,50, FIFO_SCHEDULER, 10, 10,  0 };
  ofstream myfile("rt_file.c");

  InsertRTIncludes("lib/_rt_includes",&myfile);

  struct task_params ArrayOfTasks[10];
  pthread_t Tab[10];

  for(int i=0;i<10;i++){Tab[i]=i;}

      int nbr = getTaskParams("non_rt.desc",ArrayOfTasks);
      cout << "Le programmer a détecté  " << nbr << " Taches" << endl;
      affiche(ArrayOfTasks,nbr);
      detect_task("non_rt.desc",&myfile, ArrayOfTasks,nbr);


  for (int i=0;i<nbr;i++){

      char* FunctionName  =  const_cast<char*>(ArrayOfTasks[i].name.c_str());
      cout<<FunctionName<<"aa"<<endl;
      int res = extractMethod(FunctionName,"non_rt.c","tmp_c");
      if (res == 0){
        cout<<"Extraction Succeeded"<<endl;
        int res2 = InsertRTCode("tmp_c",&myfile,ArrayOfTasks[i],Tab[i]);
      }
      else cout<<"Function:'"<< FunctionName <<"'extraction failed"<<endl;
      }

      Insert_MainCode_thread("lib/_rt_main_task.pl",&myfile);

      for( int i=0;i<nbr;i++){
        Insert_MainCode_header(&myfile,ArrayOfTasks[i],Tab[i]);
      }

      for(int j=0;j<nbr;j++){
        Insert_MainCode_Join(&myfile,ArrayOfTasks[j],Tab[j]);
      }

      Insert_Main_footer("lib/_rt_main_task_footer.pl",&myfile);

  myfile.close();

  return 0;
}
