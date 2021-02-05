#include<bits/stdc++.h>
using namespace std;
//class that stores the required options map.
class careerObjective
{
public:
   map<string,vector<string>> careerOptions;
   careerObjective()
   {
   	 careerOptions["InternshipPlacementPreparationInternship"]={"Intern GO","Intern ACE","Intern PRO"};
     careerOptions["InternshipPlacementPreparationPlacement"]={"Campus 2 Corporate","Off Campus","Placement Ready"};
     careerOptions["JobHunt"]={"hieq.in","Off-Campus","Placement Ready"};
     careerOptions["CareerReadiness"]={"Industry Ready","Industry Analysis","Company Analysis"};
     careerOptions["IndustryAndCompanyFitmentStudent"]={"CareerUP","GradXplore","Field Engagement Index"};
     careerOptions["IndustryAndCompanyFitmentYoungProfessional"]={"CareerUP","Industry Ready","Field Engagement Index"};
     careerOptions["CareerGuidanceStudent"]={"Career Profiler","GradXplore","Field Engagement Index"};
     careerOptions["CareerGuidanceYoungProfessional"]={"Career Profiler","Industry Ready","Field Engagement Index"};
     careerOptions["DomainFitment"]={"Fitment Analysis","Domain Profiler","Field Engagement Index"};
     careerOptions["BehavioralSkills"]={"Core Behavioral Skill Development","Interpersonal Skills","Social Intelligence Skills"};
     careerOptions["CognitiveSkills"]={"Core Cognitive Skill Development","Analytical and Reasoning Skills","Communication Skills"};
     careerOptions["FunctionalSkills"]={"Core Domain Skill Development","Domain Tool Learning and Training","Domain Productivity Enhancer"};
     careerOptions["CareerPlanningAndProgressionJobHunt"]={"hieq.in","Campus2Corporate","Placement Ready"};
     careerOptions["CareerPlanningAndProgressionUpskilling"]={"Career Planning","Appraisal Booster","People Management"};
     careerOptions["CareerStarterJobHunt"]={"hieq.in","Campus2Corporate","Career Planning"};
     careerOptions["CareerStarterUpskilling"]={"Connect & Thrive","Career Planning","Appraisal Booster"};
     careerOptions["CareerSwitchJobHunt"]={"hieq.in","Career Profiler","Campus2Corporate"};
     careerOptions["CareerSwitchUpskilling"]={"Career Planning","hieq.in","Connect & Thrive"};
   }

};
int main()
{
	careerObjective c;
	vector<string> user={" ","Student","YoungProfessional"};
	vector<string> currentProgression={" ","Internship","Placement","JobHunt","Upskilling"};
	vector<string> desiredGuidance={"1PlacementAndJobPreparation","2CareerSelection","3SkillDevelopment","4CareerProgression"};
	vector<string> careerOptions={" ","InternshipPlacementPreparation","JobHunt","CareerReadiness","IndustryAndCompanyFitment","CareerGuidance",
	                               "DomainFitment","BehavioralSkills","CognitiveSkills","FunctionalSkills","CareerPlanningAndProgression","CareerStarter","CareerSwitchUp"};
	map<string,string> m;
	m["1PlacementAndJobPreparation"]="Placement And Job Preparation";
	m["2CareerSelection"]="Career Selection";
	m["3SkillDevelopment"]="Skill Development";
	m["4CareerProgression"]="Career Progression";
	m["InternshipPlacementPreparation"]="Internship Placement Preparation";
	m["JobHunt"]="Job Hunt";
	m["CareerReadiness"]="Career Readiness";
	m["IndustryAndCompanyFitment"]="Industry and Company Fitment";
	m["CareerGuidance"]="Career Guidance";
	m["DomainFitment"]="Domain Fitment";
	m["BehavioralSkills"]="Behavioral Skills";
	m["CognitiveSkills"]="Cognitive Skills";
	m["FunctionalSkills"]="Functional Skills";
	m["CareerPlanningAndProgression"]="Career Planning and Progression";
	m["CareerStarter"]="Career Starter";
	m["CareerSwitchUp"]="Career Switch";
	vector<int> career;
	vector<string> guidanceOptions,finalOptions,desiredGuidanceAlias=desiredGuidance,recomendations;
	int x=1,y=1,z=1,count=0;


	//step 1: The user
	cout<<"Who are you? Just type the option number (1 or 2)"<<endl;
	cout<<"1. Student   2. Young Professional"<<endl;
	cin>>x;


	//step 2: User's career objective
	cout<<"What is your career objective? Just type the option number."<<endl;
	while(desiredGuidanceAlias.size()>0)
	{
		count=0;

		//display of unselected options
	    for(auto i:desiredGuidanceAlias)
	    {
	    	count++;
	    	cout<<count<<". "<<m[i]<<endl;
	    }
	    cin>>y;
	    if(y<=0||y>=desiredGuidanceAlias.size())
	    {
	    	cout<<"Invalid option"<<endl;
	    }
	    else
	    {
	      career.push_back(desiredGuidanceAlias[y-1][0]-'0');

	      //chosed option deleted
	      desiredGuidanceAlias.erase(desiredGuidanceAlias.begin()+y-1);
	    }
	    //if user wanted to choose more or again(in case of selection of invalid option)
	    cout<<"Do you want to choose again/more?(yes/no)"<<endl;
	    string s;cin>>s;
	    if(s=="yes"||s=="Yes"||s=="YES")
	    	continue;
	    else break;
	}

	//step 3: Current phase of user
	cout<<"What is your Current Stage of Career Progression?"<<endl;
	if(x==1)
	{
		cout<<"1. Internship     2. Placement"<<endl;
		cin>>z;
	}
	else if(x==2)
	{
		cout<<"1. Job hunt       2. Upskilling"<<endl;
		cin>>z;
	}

	//listing options on the basis of above selections
    for(auto i:career)
    {
    	for(int j=3*(i-1)+1;j<=3*(i-1)+3;j++)
    	{
    		guidanceOptions.push_back(careerOptions[j]);
    	}
    }


    //step 4: Areas in which user seek guidence.
    cout<<"What are the areas in which you need guidance? choose from below options according to priority."<<endl;
    cout<<"Type the option number"<<endl;
    while(finalOptions.size()<4)
    {
       count=0;
       //display of unselected option
       for(auto i:guidanceOptions)
       {
         count++;
         cout<<count<<".  "<<m[i]<<endl;
       }
       int w;
	   string s;
       cin>>w;
       if(w>guidanceOptions.size()||w<=0)
       {
         cout<<"Invalid option number."<<endl;
       }
	   else{
       if(guidanceOptions[w-1]=="InternshipPlacementPreparation")
       {
       	 s=guidanceOptions[w-1]+currentProgression[z+x-1];
         finalOptions.push_back(s);
       }
       else if(guidanceOptions[w-1]=="IndustryAndCompanyFitment"||guidanceOptions[w-1]=="CareerGuidance")
       {
       	 s=guidanceOptions[w-1]+user[x];
       	 finalOptions.push_back(s);
       }
       else if(guidanceOptions[w-1]=="CareerPlanningAndProgression"||guidanceOptions[w-1]=="CareerStarter"||guidanceOptions[w-1]=="CareerSwitchUp")
       {
       	 s=guidanceOptions[w-1]+currentProgression[z+x];
       	 finalOptions.push_back(s);
       }
       else finalOptions.push_back(guidanceOptions[w-1]);
       
       //chosed options deleted
       guidanceOptions.erase(guidanceOptions.begin()+w-1);
	   }

       //if user wanted to choose more or again(in case of selection of invalid option)
       cout<<"Do you want to choose again/more?(yes/no)"<<endl;
       cin>>s;
	   if(s=="yes"||s=="Yes"||s=="YES")
	     continue;
	   else break;
    } 

    //addtion of options available on the basis of options selected above
    for(auto i:finalOptions)
    {
    	for(auto j:c.careerOptions[i])
    	{
    		recomendations.push_back(j);
    	}
    }

    // step 5: showing recomendations according to user's priority.
    cout<<"Based on the your selections below are the products that will help you to achieve your goals "<<endl;
    count=0;
    for(int i=0;i<recomendations.size();i++)
    {
    	//shows five product on the basis of priority top one from each interest
    	if(recomendations.size()==12&&(i==1||i%3==0))
    	{
    	  count++;
    	  cout<<count<<".  "<<recomendations[i]<<endl;
    	}
    	//shows four product two from first priority and one from other priorities
    	else if(recomendations.size()==9)
    	{
    		if(i==1||i%3==0)
    		{
    			count++;
    	        cout<<count<<".  "<<recomendations[i]<<endl;
    		}
    	}
    	//shows four product two from each interest
    	else if(recomendations.size()==6)
    	{
    		if(i==0||i==1||i==3||i==4)
    		{
    			count++;
    			cout<<count<<".  "<<recomendations[i]<<endl;
    		}
    	}
    	//shows all three products available on the basis of choices
    	else if(recomendations.size()==3)
    	{
    		count++;
    		cout<<count<<".  "<<recomendations[i]<<endl;
    	}
    }
}