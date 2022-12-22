#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<pbd_data/datastruct.h>

using namespace std;

struct output_mesh_data{
    string out_path;
    ofstream fout;
    
    output_mesh_data(string out_path): out_path{out_path} {
        fout.open(out_path);
        // fout.open(out_path, ios::app);
        fout << "MeshData = {" << endl;
    }
    
    ~output_mesh_data(){
        fout.close();
    }

    void output_name(string name){
        fout << "\t'name': \"" + name + "\"," << endl;
    }

    void output_verts(vector<vert> &verts){
        fout << "\t'verts': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < verts.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << verts[i].x << ", " << verts[i].y << ", " << verts[i].z;
            if(i != verts.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_tetIds(vector<tet> &tetIds){
        fout << "\t'tetIds': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < tetIds.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << tetIds[i].v[0] << ", " << tetIds[i].v[1] << ", " << tetIds[i].v[2] << ", " << tetIds[i].v[3];
            if(i != tetIds.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_tetEdgeIds(vector<int> &tetedgeids){
        fout << "\t'tetEdgeIds': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < tetedgeids.size() / 2 ; i++){
            if(cnt == 0) fout << "\t\t";
            fout << tetedgeids[i * 2] << ", " << tetedgeids[i * 2 + 1];
            if(i != tetedgeids.size() / 2 - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_tetSurfaceTriIds(vector<int> &tet_surf_tri_ids){
        fout << "\t'tetSurfaceTriIds': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < tet_surf_tri_ids.size() / 3 ; i++){
            if(cnt == 0) fout << "\t\t";
            fout << tet_surf_tri_ids[i * 3] << ", " << tet_surf_tri_ids[i * 3 + 1] << ", " << tet_surf_tri_ids[i * 3 + 2];
            if(i != tet_surf_tri_ids.size() / 3 - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_fiberDirection(vector<vec3> &fiber){
        fout << "\t'fiberDirection': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < fiber.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << fiber[i].x << ", " << fiber[i].y << ", " << fiber[i].z;
            if(i != fiber.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_sheetDirection(vector<vec3> &sheet){
        fout << "\t'sheetDirection': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < sheet.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << sheet[i].x << ", " << sheet[i].y << ", " << sheet[i].z;
            if(i != sheet.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_normalDirection(vector<vec3> &normal){
        fout << "\t'normalDirection': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < normal.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << normal[i].x << ", " << normal[i].y << ", " << normal[i].z;
            if(i != normal.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_edge_set(int &num_edge_set, vector<int> &edge_set_id){
        fout << "\t'num_edge_set': [" << num_edge_set << "]," << endl;

        fout << "\t'edge_set': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < edge_set_id.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << edge_set_id[i];
            if(i != edge_set_id.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_tet_set(int &num_tet_set, vector<int> &tets_set_id){
        fout << "\t'num_tet_set': [" << num_tet_set << "]," << endl;

        fout << "\t'tet_set': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < tets_set_id.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << tets_set_id[i];
            if(i != tets_set_id.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_bou_tag(vector<int> &bou_tag){
        fout << "\t'bou_tag': [" << endl;
        int cnt = 0;
        for(size_t i = 0; i < bou_tag.size(); i++){
            if(cnt == 0) fout << "\t\t";
            fout << bou_tag[i];
            if(i != bou_tag.size() - 1){
                fout << ", ";
            }else{
                fout << endl;
                fout << "\t]," << endl;
                break;
            }
            cnt++;
            if(cnt == 10){
                cnt = 0;
                fout << endl;
            }
        }
    }

    void output_end(){
        fout << "}" << endl;
    }
};