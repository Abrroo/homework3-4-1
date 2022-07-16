#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

class adress
{
private:

    std::string city, strt;
    int bldg, appt;

public:
    adress(std::string city, std::string strt, int bldg, int appt)
    {
        this->city = city;
        this->strt = strt;
        this->bldg = bldg;
        this->appt = appt;
    }
    adress() {}

    std::string make_string()
    {
        std::string c = this->city;
        std::string s = this->strt;
        std::string b = std::to_string(this->bldg);
        std::string a = std::to_string(this->appt);
        return c + ", " + s + ", " + b + ", " + a;
    }

};

int open_file(std::string path)
{
    std::ifstream file_read(path);
    if (!file_read.is_open())
    {
        std::cout << "Can't open input file!" << std::endl;
        return 1;
    }
    std::cout << "File is open" << std::endl;
    return 0;
}

int main()
{
    int N = 0;
    int bldg = 0, appt = 0;
    std::string city, strt;

    std::ifstream file_read("in.txt");
    if (!file_read.is_open())
    {
        std::cout << "Can't open input file!" << std::endl;
        return 1;
    }
    std::cout << "Input file is open" << std::endl;
    file_read >> N;
    std::string* adr_arr = new std::string[N]();

    for (int i = 0; i < N; i++)
    {
        file_read >> city;
        file_read >> strt;
        file_read >> bldg;
        file_read >> appt;
        adress adr(city, strt, bldg, appt);
        adr_arr[i] = adr.make_string();
    }

    file_read.close();
    std::ofstream file_write("out.txt");
    if (!file_write.is_open())
    {
        std::cout << "Can't open output file!" << std::endl;
        return 1;
    }
    std::cout << "Output file is open" << std::endl;
    file_write << N << std::endl;
    for (int i = N-1; i >= 0; i--)
    {
        file_write << adr_arr[i] << std::endl;
    }
    
    std::cout << "Done!" << std::endl;


}
