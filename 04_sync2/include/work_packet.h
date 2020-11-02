#pragma once 



using namespace std;


class WorkPacket {
    private:
        int id;
       
    public:

        WorkPacket(int number) {
        id = number;
        }

        int get_id() const {
             return this->id;
}

    


};
