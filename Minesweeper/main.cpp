//
//  main.cpp
//  Minesweeper
//
//  Created by Pranav NS on 2/26/16.
//  Copyright © 2016 Pranav NS. All rights reserved.
//

/*
 * assign5.cc
 *
 * Pranav Ns
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void buildMineField(vector< vector<bool> > &vec, double prob)
{
    double rnd;
    
    
    for (int i=0;i<vec[0].size();i++)
    {
        for (int j=0; j<vec[0].size(); j++)
        {
            rnd = rand() / (double (RAND_MAX) + 1);
            if(rnd<prob)
            {
                vec[i][j]=true;
            }
            else
            {
                vec[i][j]=false;
            }
            cout<< vec[i][j] <<endl;
        }
    }
    cout<<"exit build mine field"<<endl;
}

void fixCounts(vector< vector<bool> > &vec, vector< vector<int> > &count)
{
    cout<<"enter fixc"<<endl;
    int c;
    for(int i=0;i<vec[0].size();i++)
    {
        for(int j=0;j<vec[0].size();j++)
        {
            if(vec[0].size()>1)
            {
                c=0;
                if(i==0)//traverse first row
                {
                    if(j==0)//first row first column
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        if(vec[i+1][j+1])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else if(j!=vec[0].size()-1)//first row middle columns
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j-1])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        if(vec[i+1][j+1])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else 					//first low last column
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i+1][j-1])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                }
                else if(i!=vec[0].size()-1)	// traverse middle rows
                {
                    if(j==0)				//firsst column
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        if(vec[i-1][j+1])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else if(j!=vec[0].size()-1)	//middle rows and columns
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        if(vec[i-1][j+1])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j+1])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j-1])
                        {
                            c++;
                        }
                        if(vec[i+1][j-1])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else 						//middle row last column
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i+1][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j-1])
                        {
                            c++;
                        }
                        if(vec[i+1][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                }
                else
                {
                    if(j==0) 				//last row first column
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        if(vec[i-1][j+1])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else if(j!=vec[0].size()-1)	// last row middle columns
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        if(vec[i-1][j+1])
                        {
                            c++;
                        }
                        if(vec[i][j+1])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                    else 					//last row last columns
                    {
                        if(vec[i][j])
                        {
                            c++;
                        }
                        if(vec[i][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j-1])
                        {
                            c++;
                        }
                        if(vec[i-1][j])
                        {
                            c++;
                        }
                        count[i][j]=c;
                    }
                }
            }
            else
            {
                if(vec[i][j])
                {
                    count[i][j]=1;
                }
            }
        }
    }
    cout<<"exit fixc"<<endl;
}

void displayMineLocations(vector< vector<bool> > &vec)
{
    for(int i=0;i<vec[0].size();i++)
    {
        for(int j=0;j<vec[0].size();j++) //print the top of the column
        {
            cout<<" ----- ";
            
        }
        cout<<endl;
        for(int j=0;j<=vec[0].size();j++)
        {
            cout<<"|      ";	
        }
        cout<<endl;
        
        for(int j=0;j<=vec[0].size();j++)
        {
            cout<<"|";	
            if(i<vec[0].size()&&j<vec[0].size()&&vec[i][j])
            {
                cout<<"  X   ";
            }
            else
            {
                cout<<"      ";
            }
        }
        cout<<endl;
        for(int j=0;j<=vec[0].size();j++)
        {
            cout<<"|      ";	
        }
        cout<<endl;
        if(i==vec[0].size()-1)
        {
            for(int j=0;j<vec[0].size();j++)
            {
                cout<<" ----- ";
                
            }
            cout<<endl;
        }
    }
}

void displayMineCounts(vector< vector<int> > &vec)
{
    for(int i=0;i<vec[0].size();i++)
    {
        for(int j=0;j<vec[0].size();j++)
        {
            cout<<" ----- ";
            
        }
        cout<<endl;
        for(int j=0;j<=vec[0].size();j++)
        {
            cout<<"|      ";	
        }
        cout<<endl;
        
        for(int j=0;j<=vec[0].size();j++)
        {
            if(j!=vec[0].size())
            {
                cout<<"|";	
                if(i<vec[0].size()&&j<vec[0].size()&&vec[i][j])
                {
                    cout<<"  "<<vec[i][j]<<"   ";
                }
                else
                {
                    cout<<"   0  ";
                }
            }
            else
            {
                cout<<"|";
            }
        }
        cout<<endl;
        for(int j=0;j<=vec[0].size();j++)
        {
            cout<<"|      ";	
        }
        cout<<endl;
        if(i==vec[0].size()-1)
        {
            for(int j=0;j<vec[0].size();j++)
            {
                cout<<" ----- ";
                
            }
            cout<<endl;
        }
    }
} 

int main(int argc, char **argv)
{
    int size;
    double prob;
    string input;
    char in[20];
    vector< vector<bool> > vec;
    vector< vector<int> > count;
    
    while(1)
    {
        vector< vector<bool> > vec;
        vector< vector<int> > count;
        cout<<"Enter the size and probability of the grid "<< endl;
        getline(cin,input);
        cout<<input<<endl;
        if(input.empty())
        {
            exit(0);
        }
        strcpy(in,input.c_str());
        sscanf(in,"%d %lf",&size,&prob);
        //ss>>size>>prob;
        
        cout<<"The size is "<<size<<endl;
        cout<<"The probabitlity is "<<prob<<endl;
        
        for (int i = 0; i < size; i++) 
        {
            vector<bool> row; // Create an empty row
            vector<int> r2;
            for (int j = 0; j < size; j++) 
            {
                row.push_back(false); // Add an element (column) to the row
                r2.push_back(0);
            }
            count.push_back(r2);
            vec.push_back(row); // Add the row to the main vector
        }
        cout<<"asdasda"<<endl;
        buildMineField(vec,prob);
        fixCounts(vec,count);
        cout<<"Mine Locations: size = "<<size<<" x "<<size<<", prob of mine = "<<prob<<endl;
        displayMineLocations(vec);
        cout<<"Mine Count:"<<endl;
        displayMineCounts(count);
        cout<<endl;
    }
    return 0;
}

