#ifndef TASK2_H
#define TASK2_H

#include <bits/stdc++.h>
#include "Matrix.h"
#include "Record.h"
#include "Comparator.h"

using namespace std;

class T2
{
public:
    void run()
    {
        ifstream fin;
        ofstream fout, finds;
        fin.open("./datasheets/sample.csv");
        fout.open("./outputs/task2.csv");
        finds.open("./outputs/task2_indices.txt");
        vector<Record> records;
        string line;
        getline(fin, line);
        vector<string> titles = parseLine(line);
        int count = 0;
        while(fin)
        {
            getline(fin, line);
            vector<string> lol = parseLine(line);
            Record temp = Record(lol);
            records.push_back(temp);
            records[count].setIndx(count);
            count++;
        }
        records.pop_back();

        Record hypAvg = createAvgRecord(records, 4);
        float max = INT_MAX;
        float min = INT_MIN;

        for(int i = 0; i < records.size(); i++)
        {
            float e = records[i].euclideanDistance(hypAvg, 4);
            records[i].setEuc(e);
            if(max <= e)    max = e;
            if(min >= e)    min = e;
        }

        for(int i = 0; i < records.size(); i++)
        {
            float n = normalizeValue(records[i].getEuc(), min, max);
            records[i].setNormal(n);
        }

        sort(records.begin(), records.end(), Compare());

        vector<int> indices;

        for(int i = 0; i < records.size(); i++)
        {
            indices.push_back(records[i].getIndex());
        }
        for(int i = 0; i < indices.size(); i++)
        {
            finds << indices[i] << ", ";
        }
        finds << "\n";
        cout << "Indices after sorting Done!\n";

        Matrix output = Matrix(records.size(), records.size());
        for(int i = 0; i < records.size(); i++)
        {
            for(int j = i + 1; j < records.size(); j++)
            {
                if(i != j)
                {
                    float f = records[i].euclideanDistance(records[j], 4);
                    output.setData(i, j, f);
                    output.setData(j, i, f);
                }
            }
        }

        fout << output;
        cout << "Printing matrix Done!\n";
    }

    float normalizeValue(float x, float min, float max)
    {
        return ((x - min)/(max - min));
    }

    vector<string> parseLine(string line)
    {
        stringstream str_strm(line );
        string temp;
        vector<string> res;
        char delim = ',';

        while(getline(str_strm, temp, delim))
        {
            res.push_back(temp);
        }
        return res;
    }

    Record createAvgRecord(vector<Record> recs, int thre)
    {
        vector<string> res;
        for(int i = 0; i < thre; i++)
        {
            res.push_back("x");
        }

        float avg;
        for(int j = thre; j < recs[0].getSize(); j++)
        {
            for(int i = 0; i < recs.size(); i++)
            {
                avg = avg + stof(recs[i].getFeatureValue(j));
            }
            avg = avg/recs.size();
            string s = to_string(avg);
            res.push_back(s);
        }

        return Record(res);
    }
};

#endif
