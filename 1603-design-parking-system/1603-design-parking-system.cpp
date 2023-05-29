class ParkingSystem {
private:
    int b = 0, med = 0, sml = 0;
    
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        med = medium;
        sml = small;
    }
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 1:
                if(b) {
                    b--;
                    return true;
                }
                return false;
            case 2:
                if(med) {
                    med--;
                    return true;
                }
                return false;
            case 3:
                if(sml) {
                    sml--;
                    return true;
                }
                return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */