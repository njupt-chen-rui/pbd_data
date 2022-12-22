#include<iostream>
#include<pbd_data/datastruct.h>
#include<pbd_data/readinp.h>
#include<pbd_data/tetEdgeIds.h>
using namespace std;

int main(){
    cout<<"hello"<<endl;
    string file_name = "test1";
    string file_format = ".inp";
    string input_path = "./data/input/" + file_name + file_format;
    string output_path = "./data/output/" + file_name + ".py";

    vector<vert> verts;
    vector<tet> tets;
    readinp_tet(input_path, verts, tets);
    vector<int> tet_edge_ids;
    tetEdgeIds(verts, tets, tet_edge_ids);
    tetSurfaceTriIds();
    // get_tet_edge();
    // cout<<verts.size()<<endl;
    // for(size_t i = 0;i<10;i++){
    //     cout<<verts[i].x<<" "<<verts[i].y<<" "<<verts[i].z<<endl;
    // }
    // cout<<tets.size()<<endl;
    // for(size_t i = 0;i<10;i++){
    //     cout<<tets[i].v[0]<<" "<<tets[i].v[1]<<" "<<tets[i].v[2]<<" "<<tets[i].v[3]<<endl;
    // }


    // output_meshdata(output_path, file_name);
    return 0;
}