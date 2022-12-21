#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<pbd_data\datastruct.h>

using namespace std;

void readinp_tet(string Path, vector<vert> &nodes, vector<tet> &tets){
    ifstream fin;
    fin.open(Path);
    if (!fin.good()) {
        cout << "file open failed";
        exit(1);
    }
    string str, c;
    char ch;
    int a;
    double b1, b2, b3;
    vert tmp{0, 0, 0};
    while(fin>>str){
        if(str=="*NODE") break;
    }
    while(1){
        while(1){
            ch = fin.get();
            ch = fin.peek();
            if(ch == '*' || (ch <= '9' && ch >= '0')) break;
        }
        if(ch == '*') break;
        fin>>a>>c>>b1>>c>>b2>>c>>b3;
        tmp.x = b1;
        tmp.y = b2;
        tmp.z = b3;
        nodes.push_back(tmp);
    }
    while(fin>>str){
        if(str=="*ELEMENT,TYPE=C3D4,ELSET=auto1") break;
    }
    int meshid;
    tet tmp2{0, 0, 0, 0};
    while(1){
        while(1){
            ch = fin.get();
            ch = fin.peek();
            if(ch == '*' || (ch <= '9' && ch >= '0')) break;
        }
        if(ch == '*') break;
        fin>>meshid>>c;
        fin>>tmp2.v[0]>>c;
        fin>>tmp2.v[1]>>c;
        fin>>tmp2.v[2]>>c;
        fin>>tmp2.v[3];
        tets.push_back(tmp2);
    }
    fin.close();
}

// TODO
void readinp_tri(){

}