#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<myheader.h>

using namespace std;

extern class data p;
vector<data> p_data;

float vtemp,vntemp,vttemp;
vector<float> v;
vector<float> vn;
vector<float> vt;

int i,j;
char line[60];

void clearp_data()
{
	p_data.clear();
}
void initialOBJ()
{

FILE *fp;
fp=fopen("temp.obj","r");

	while(!(feof(fp)))
	{
		i=0;
		fscanf(fp,"%s",line);

		if(line[0]=='v'&&line[1]!='n'&&line[1]!='t')
		{
			while(i<3)
			{
			fscanf(fp,"%f",&vtemp);
			v.push_back(vtemp);
			i++;
			}
		}
		
		else if(line[0]=='v'&&line[1]=='n')
		{
		
			while(i<3)
			{
			fscanf(fp,"%f",&vntemp);
			vn.push_back(vntemp);
			i++;
			}

			
		}
		else if(line[0]=='v'&&line[1]=='t')
		{
			while(i<3)
			{
			fscanf(fp,"%f",&vttemp);	
			vt.push_back(vttemp);
			i++;
			}

		}

		
	}
	 fclose(fp);
	

}

void objDraw()
{
dlist=glGenLists(1);
 FILE *fp2;
 fp2=fopen("temp.obj","r");
 int eq;
 char ch[10];

 while(!(feof(fp2)))
 {	
 	i=0;
 	fscanf(fp2,"%s",line);
	if(line[0]=='f')
	{	

		while(i<3)	
		{
			//... VERTEX
			fscanf(fp2,"%d%s",&eq,line);
			eq=eq*3;
			p.v[0]=v[eq];
			p.v[1]=v[eq+1];
			p.v[2]=v[eq+2];
			i++;
			
			//... NORMAL
			while(j<strlen(line))
			{
			ch[j]=line[j+2];
			j++;
			}
			ch[j]='\0';

			eq=atoi(ch);
			eq--;
			eq=eq*3;
			j=0;
			p.vn[0]=vn[eq];
			p.vn[1]=vn[eq+1];
			p.vn[2]=vn[eq+2];

		  p_data.push_back(p);
		}
	} 	

 }
 fclose(fp2);
 v.clear();
 vn.clear();
 vt.clear();
}


void optimisationList()
{

glNewList(dlist, GL_COMPILE);

glBegin(GL_TRIANGLES);
for(i=0;i<p_data.size();i++)
{
glNormal3f(p_data[i].vn[0],p_data[i].vn[1],p_data[i].vn[2]);
glVertex3f(p_data[i].v[0],p_data[i].v[1],p_data[i].v[2]);
}
glEnd();

glEndList();
}