#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <random>

void automate(int datasetSize, std::string filename);

std::vector<float> loadDataset(int dataSetSize, std::string filename);
int createDataset(int size, std::string filename);
float findAvg(std::vector<float> dataset);
float findMin(std::vector<float> dataset);
float findMax(std::vector<float> dataset);

void selectionSort(std::vector<float>& dataset);
int writeDataset(std::vector<float> dataset, std::string filename, float avg, float min, float max);


int main()
{
    automate(1000, "test2.txt");
    return 0;
}

void automate(int datasetSize, std::string filename)
{
    std::vector<float> dataset(0, 0);

    createDataset(datasetSize, filename);
    dataset = loadDataset(datasetSize, filename);

    float avg = findAvg(dataset);

    float min = findMin(dataset);

    float max = findMax(dataset);

    selectionSort(dataset);

    writeDataset(dataset, "sorted" + filename, avg, min, max);

    system("pause");
}

std::vector<float> loadDataset(int dataSetSize, std::string filename)
{
    std::fstream file(filename, std::ios::in);
    std::vector<float> dataset(0, 0);

    float temp = 0;
    if (file.is_open())
    {
        for (int i = 0; i < dataSetSize; i++)
        {
            file >> temp;
            dataset.push_back(temp);
        }
    }
    

    return dataset;
}

int createDataset(int size, std::string filename)
{
	std::random_device rd;
    std::vector<float> vec;

    for (int i = 0; i < size; i++)
    {
		std::mt19937 rng(rd());
		std::uniform_real_distribution<> num(0, 100);
		//std::cout << vec[i] << std::endl;
        vec.push_back(num(rd));
    }

    std::fstream file(filename, std::ios::out);
    
    for (int i = 0; i < size; i++)
    {
        file << vec[i] << " ";
    }

    return 0;
}

float findAvg(std::vector<float> dataset)
{
    float avg = 0.f;
    for (size_t i = 0; i < dataset.size(); i++)
    {
        avg += dataset[i];
    }
    avg /= dataset.size();

    return avg;
}

float findMin(std::vector<float> dataset)
{
    int min = 0;
    for (size_t i = 1; i < dataset.size(); i++)
    {
        if (dataset[i] < dataset[min])
            min = i;
    }
    return dataset[min];
}

float findMax(std::vector<float> dataset)
{
    int max = 0;
    for (size_t i = 1; i < dataset.size(); i++)
    {
        if (dataset[i] > dataset[max])
            max = i;
    }
    return dataset[max];
}

void selectionSort(std::vector<float>& dataset)
{
    int min = 0;
    for (int i = 0; i < dataset.size() - 1; i++)
    {
        bool minfound = false;
        
        min = i;
        for (int j = i + 1; j < dataset.size(); j++)
        {
            
            if (dataset[j] < dataset[min])
            {
                min = j;
                minfound = true;
            }
        }

        if (minfound)
            std::swap(dataset[i], dataset[min]);
    }
}

int writeDataset(std::vector<float> dataset, std::string filename, float avg, float min, float max)
{
    std::fstream file(filename, std::ios::out);

    if (!file.is_open())
        return -1;

    file << avg << " " << min << " " << max << " ";

    for (size_t i = 0; i < dataset.size(); i++)
    {
        file << dataset[i] << " ";
    }


    return 0;
}