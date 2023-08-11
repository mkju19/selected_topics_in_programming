#ifndef EXAM_OBSERVERS_H
#define EXAM_OBSERVERS_H

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include "Include/Simulator/StateObserver.h"


class CounterObserver : public StateObserver{
    size_t numberOfReactions = 0;
    void observe(const std::vector<std::string>& vec) override{
        numberOfReactions++;
    }
    void stop() override{
        std::cout<< "Counted " << numberOfReactions << " reactions." << std::endl;
        numberOfReactions = 0;
    }
};

class SilentCounterObserver : public StateObserver{
    size_t numberOfReactions = 0;
    void observe(const std::vector<std::string>& vec) override{
        numberOfReactions++;
    }
    void stop() override{
        numberOfReactions = 0;
    }
};

class CsvObserver : public StateObserver{
    bool running = false;
    bool runningParallel = false;
    const std::string relativePath = "../Data/";//"../Data/test.csv";
    const std::string fileType = ".csv";
    std::string path;
    std::ofstream outfile;
    void writeVector(const std::vector<std::string> &vec) {

        for (auto i = 0; i < vec.size(); i++) {
            if (i != vec.size()-1){
                outfile << vec.at(i) << ";";
            } else{
                outfile << vec.at(i) << std::endl;
            }
        }
    }
    void writeHeader(std::vector<std::string> vec){
        auto header = std::vector<std::string>{"Elapsed Time"};

        auto i = 1;
        if(runningParallel){
            header.push_back("Id");
            i++;
        }
        for(; i < vec.size(); i++){
            auto id = splitString(vec.at(i), ':').at(0);
            header.push_back(id);
        }
        writeVector(header);
    }
     static std::vector<std::string> splitString(const std::string& str, char c){
        auto strCpy = str;
        std::replace(strCpy.begin(), strCpy.end(), c, ' ');  // replace char c with ' '

        std::vector<std::string> vec;
        std::stringstream ss(strCpy);
        std::string temp;
        while (ss >> temp) {
             vec.push_back(temp);
        }
        return vec;
    }
public:
    explicit CsvObserver(const std::string& fileName): path(relativePath + fileName + fileType){}
    void setFileName(std::string fileName){
        path = relativePath + fileName + fileType;
    }
    void observe(const std::vector<std::string> &vec) override {
        if (!running){
            running = true;
            std::filesystem::remove(path);
            outfile.open(path, std::ios_base::app); // append instead of overwrite

            writeHeader(vec);
        }

        auto transformedVec = std::vector<std::string>{vec.at(0)};
        auto i = 1;
        if(runningParallel){
            transformedVec.push_back(vec.at(1));
            i++;
        }

        for (; i < vec.size(); i++){
            auto val = splitString(vec.at(i), ':').at(1);
            transformedVec.push_back(val);
        }
        writeVector(transformedVec);
    }
    void observeParallel(const std::vector<std::string> &vec, int id) override {
        auto vecCpy = std::vector<std::string>{vec.at(0), std::to_string(id)};

        for (auto i = 1; i < vec.size(); i++){
            vecCpy.push_back(vec.at(i));
        }
        runningParallel = true;
        observe(vecCpy);
    }
    void stop() override {
        running = false;
        runningParallel = false;
        outfile.close();
    }
};

class AveragePeakHospitalized : public StateObserver {
    std::unordered_map<int, int> peaks;
    size_t peak = 0;
    void observe(const std::vector<std::string>& vec)override{
        for(const auto &element : vec){
            //The hospitalized variable will have H: as the first to chars in the string
            if (element.at(0) == 'H' && element.at(1) == ':'){
                auto val_str = element.substr(2);

                auto val = std::stoi(val_str);

                peak = val > peak ? val : peak;
            }
        }
    }
    void stop() override{
        std::cout<< "The peak of hospitalized agents is: " << peak << std::endl;
        peak = 0;
    }
    void observeParallel(const std::vector<std::string> &vec, int id) override{
        for(const auto &element : vec){
            //The hospitalized variable will have H: as the first to chars in the string
            if (element.at(0) == 'H' && element.at(1) == ':'){
                auto val_str = element.substr(2);
                auto val = std::stoi(val_str);

                if(peaks.contains(id)){
                    auto old = peaks.at(id);
                    peaks.at(id) = val > old ? val : old;
                } else {
                    peaks.emplace(id, val);
                }
            }
        }
    }
    void stopParallel() override{
        auto size = peaks.size();
        auto sum = 0;
        for(const auto& [id, val] : peaks){
            sum += val;
        }
        std::cout << "The estimated average peak hospitalized over " << size << " simulations: " << sum/size << std::endl;
        peaks.clear();
    }
};
#endif //EXAM_OBSERVERS_H
