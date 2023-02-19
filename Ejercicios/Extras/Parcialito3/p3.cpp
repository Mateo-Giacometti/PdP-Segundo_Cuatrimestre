#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <tuple>

class Medicion{
    protected:
        std::chrono::system_clock::time_point time_;
        virtual void stamp(void) {
            time_ = std::chrono::system_clock::now();
        }
    public: 
        Medicion(){std::cout << "Se creo Medicion" << std::endl;}
        virtual ~Medicion(){std::cout << "Se destruyo Medicion" << std::endl;}
        virtual void printMed() const = 0;   
};

class MedicionLidar : public Medicion{
    protected:
        std::vector<double> distance_;
    public: 
        MedicionLidar(std::vector<double> &distance) : distance_(std::move(distance)){std::cout << "Se creo MedicionLidar" << std::endl;}
        virtual ~MedicionLidar(){std::cout << "Se destruyo MedicionLidar" << std::endl;}
        void printMed() const override {
            std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
            std::cout << "MedicionLidar\n";
            std::cout << std::ctime(&stamp);
            std::cout<< "| ";
            for(auto &e : distance_){
                std::cout << e << " | ";
            }
            std::cout<<std::endl;
        }
};

class MedicionGPS : public Medicion{
    protected:
        std::tuple<double,double,double> position_;
    public:
        MedicionGPS(std::tuple<double,double,double> position): position_(position){std::cout << "Se creo MedicionGPS" << std::endl;}
        virtual ~MedicionGPS(){std::cout << "Se destruyo MedicionGPS" << std::endl;}
        void printMed() const override {
            std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
            std::cout << "MedicionGPS\n";
            std::cout << std::ctime(&stamp);
            std::cout << "X: " << std::get<0>(position_) << " Y: " << std::get<1>(position_) << " Z: " << std::get<2>(position_) << std::endl;
        }
};

class MedicionCamara : public Medicion{
    protected:
        std::vector<std::vector<int>> photo_;
    public:
        MedicionCamara(std::vector<std::vector<int>> photo): photo_(photo){std::cout << "Se creo MedicionCamara" << std::endl;}
        virtual ~MedicionCamara(){std::cout << "Se destruyo MedicionCamara" << std::endl;}
        void printMed() const override {
            std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
            std::cout << "MedicionCamara\n";
            std::cout << std::ctime(&stamp);
            for(size_t i = 0; i < photo_.size(); i++){
                for(size_t v = 0; v < photo_[i].size(); v++){
                    std::cout<< photo_[i][v];
                }
                std::cout<<std::endl;
            }
        }
};

class Sensor{
    protected:
    std::string name_;
    public:
        Sensor(std::string name): name_(name) { std::cout  << "Se creo Sensor" << std::endl; }
        virtual ~Sensor() { std::cout  << "Se destruyo Sensor" << std::endl; }
        virtual Medicion* medir() = 0;
        bool operator==(const Sensor& cop){
            return name_ == cop.name_;
        }
        bool operator!=(const Sensor& cop){
            return name_ != cop.name_;
        }
        std::string getName(){return name_;}
};

class Lidar : public Sensor{
    private:
        double res_, ang_;
    public:
        Lidar(double res, double ang): Sensor("Lidar"), res_(res), ang_(ang){std::cout << "Se creo Lidar" << std::endl;}
        Lidar(Lidar &cop): Sensor("Lidar"), res_(cop.res_), ang_(cop.ang_){std::cout << "Se creo Lidar" << std::endl;}
        virtual ~Lidar(){std::cout << "Se destruyo Lidar" << std::endl;}
        const Lidar& operator=(const Lidar& cop) {
        res_ = cop.res_;
        ang_ = cop.res_;
        return *this;
        }
        bool operator==(const Lidar& cop) const {
            return res_ == cop.res_ && ang_ == cop.ang_;
        }
        bool operator!=(const Lidar& cop) const {
            return res_ != cop.res_ && ang_ != cop.ang_;
        }
        Medicion *medir() override {
            std::vector<double> v(ang_ / res_);
            for(int i = 0; i < v.size(); i++){
                v[i] = i;
            }
            return new MedicionLidar(v);
        }
};

class GPS : public Sensor{
    private:
        double pre_;
    public: 
        GPS(double pre): Sensor("GPS"), pre_(pre){std::cout << "Se creo GPS" << std::endl;}
        GPS(GPS& cop):  Sensor("GPS"), pre_(cop.pre_){std::cout << "Se creo GPS" << std::endl;}
        virtual ~GPS(){std::cout << "Se destruyo GPS" << std::endl;}
        const GPS& operator=(const GPS& cop){
            pre_ = cop.pre_;
            return *this;
        }
        bool operator==(const GPS& cop) const {
            return pre_ == cop.pre_;
        }
        bool operator !=(const GPS& cop) const {
            return pre_ != cop.pre_;
        }
        Medicion *medir() override {
            srand(time(NULL));
            std::tuple<double, double, double> p = {rand()%100, rand()%100, rand()%100};
            return new MedicionGPS(p);
        }
};

class Camara : public Sensor{
    private:
        double width_, length_;
    public:
        Camara(double width, double length): Sensor("Camara"), width_(width), length_(length){std::cout << "Se creo Camara" << std::endl;}
        Camara(Camara &cop): Sensor("Camara"), width_(cop.width_), length_(cop.length_){std::cout << "Se creo Camara" << std::endl;}
        virtual ~Camara(){std::cout << "Se destruyo Camara" << std::endl;}
        const Camara& operator=(Camara& cop){
            width_ = cop.width_;
            length_ = cop.length_;
            return *this;
        }
        bool operator==(Camara& cop) const {
            return width_ == cop.width_ && length_ == cop.length_;
        }
        bool operator!=(Camara& cop) const {
            return width_ != cop.width_ && length_ != cop.length_;
        }
        Medicion *medir() override {
            std::vector<std::vector<int>> rows(length_);
            for(auto &row : rows){
                rows.reserve(width_);
                for(auto& final : rows){
                    final.emplace_back(rand()%10);
                }
            }
            return new MedicionCamara(rows);
        }
};

class AutoAutonomo{
    private:
        std::string patente_;
        std::vector<Sensor*> sensores_;
    public:
        AutoAutonomo(std::string patente): patente_(patente){std::cout << "Se creo AutoAutono" << std::endl;}
        AutoAutonomo(AutoAutonomo &cop): patente_(cop.patente_){std::cout << "Se creo AutoAutono" << std::endl;}
        virtual ~AutoAutonomo(){
            for(const auto sensor : sensores_){
                delete sensor;
            }
            std::cout << "Se destruyo AutoAutono" << std::endl;
        }
        void introduceSensores(Sensor* cop){
            sensores_.emplace_back(cop);
            std::cout << "Se introdujo " << (*cop).getName() << std::endl;
        }
        void log() const {
            for(auto &each : sensores_){
                each->medir()->printMed();
            }
        }
        bool operator==(AutoAutonomo& cop) const {
            return patente_ == cop.patente_;
        }
        bool operator!=(AutoAutonomo& cop){
            return patente_ != cop.patente_;
        }

};

int main(void){
    std::cout << "Construcciones:" << std::endl;
    AutoAutonomo *Mate = new AutoAutonomo("GAY1234");
    GPS *ublox = new GPS(0.1);
    GPS *ublox2 = new GPS(0.1);
    GPS *ublox3 = new GPS(0.2);
    Camara *GoPro = new Camara(4, 5);
    Camara *GoPro2 = new Camara(4, 5);
    Camara *GoPro3 = new Camara(5, 4);
    Lidar *Velodyne = new Lidar(0.1, 360);
    Lidar *Velodyne2 = new Lidar(0.1, 360);
    Lidar *lidar = new Lidar(10, 270);

    std::cout << "Mediciones:" << std::endl;
    ublox->medir()->printMed();
    GoPro->medir()->printMed();
    lidar->medir()->printMed();

    std::cout << "-Operadores-" << std::endl;
    std::cout << "Operadores ==:" << std::endl;
    std::cout << "GPS: " << (*ublox == *ublox2) << std::endl;
    std::cout << "GPS: " << (*ublox == *ublox3) << std::endl;
    std::cout << "Camara: " << (*GoPro == *GoPro2) << std::endl;
    std::cout << "Camara: " << (*GoPro == *GoPro3) << std::endl;
    std::cout << "Lidar: " << (*Velodyne == *Velodyne2) << std::endl;
    std::cout << "Lidar: " << (*Velodyne == *lidar) << std::endl;
    std::cout << "Operadores !=:" << std::endl;
    std::cout << "GPS: " << (*ublox != *ublox2) << std::endl;
    std::cout << "GPS: " << (*ublox != *ublox3) << std::endl;
    std::cout << "Camara: " << (*GoPro != *GoPro2) << std::endl;
    std::cout << "Camara: " << (*GoPro != *GoPro3) << std::endl;
    std::cout << "Lidar: " << (*Velodyne != *Velodyne2) << std::endl;
    std::cout << "Lidar: " << (*Velodyne != *lidar) << std::endl;

    std::cout << "-Auto Autonomo-" << std::endl;
    Mate->introduceSensores(GoPro);
    Mate->introduceSensores(ublox);
    Mate->introduceSensores(lidar);
    Mate->log();

    std::cout << "Destructores: " << std::endl;
    delete ublox2;
    delete ublox3;
    delete GoPro2;
    delete GoPro3;
    delete Velodyne;
    delete Velodyne2;
    delete Mate;

    return EXIT_SUCCESS;
}