/**
 * 1015　德才论
 */ 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct Node{
    long id ;//准考证号
    int deScore;//德分
    int caiScore;//才分
}Student; 

bool sort_key(Student& s1,Student& s2){
    if((s1.deScore+s1.caiScore)>(s2.deScore+s2.caiScore))
        return true;
    
}

void print(Student& s){
    cout<<s.id<<" "<<s.deScore<<" "<<s.caiScore<<endl;
}

int main (void){
    /**
     * N 考生总数
     * L L>=60 录取最低分数线
     * H H<100 优先录取线
     */ 
    int N,L,H;
    cin>>N>>L>>H;
    vector<Student> all_students;
    vector<Student> level_one_students;
    vector<Student> level_two_students;
    vector<Student> level_three_students;
    vector<Student> other_considered_students;

    //采集学生信息
    for(int i=0;i<N;i++){
        Student s_temp;
        cin>>s_temp.id>>s_temp.deScore>>s_temp.caiScore;
        all_students.push_back(s_temp);
    }
    
    //对学生进行分类
    vector<Student>::iterator iter;
    for(iter=all_students.begin();iter!=all_students.end();iter++){
        if(iter->caiScore>=H&&iter->deScore>=H){
            //第一类学生
            level_one_students.push_back(*iter);
        }
        else if(iter->caiScore<H&&iter->deScore>=H){
            //第二类学生
            level_two_students.push_back(*iter);
        }
        else if(iter->deScore<H&&iter->caiScore<H&&iter->deScore>=iter->caiScore){
            //第三类学生
            level_three_students.push_back(*iter);
        }
        else if(iter->caiScore<H&&iter->deScore<H){
            //不在录取考虑范围之类的学生，直接排除
        }
        else {
            //其他
            other_considered_students.push_back(*iter);
        }
    }

    //尽快释放all_students占用的内存
    vector<Student>(all_students).swap(all_students);
    
    //排序
    sort(level_one_students.begin(),level_one_students.end(),sort_key);
    sort(level_two_students.begin(),level_two_students.end(),sort_key);
    sort(level_three_students.begin(),level_three_students.end(),sort_key);
    sort(other_considered_students.begin(),other_considered_students.end(),sort_key);

    //输出
    for_each(level_one_students.begin(),level_one_students.end(),print);
    for_each(level_two_students.begin(),level_two_students.end(),print);
    for_each(level_three_students.begin(),level_three_students.end(),print);
    for_each(other_considered_students.begin(),other_considered_students.end(),print);

    return 0;
}