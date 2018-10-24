#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <random>

std::vector<float> loadDataset(int dataSetSize, std::string filename);
int createDataset(int size, std::string filename);
float findAvg(std::vector<float> dataset);
float findMin(std::vector<float> dataset);
float findMax(std::vector<float> dataset);

int main()
{

    int dataSetSize = 0;
    int bufferSize = 0;
    std::string datasetFilename("");
    std::string outputFilename("");

    std::vector<float> dataset(0, 0);

    createDataset(1000, "test.txt");
    dataset = loadDataset(1000, "test.txt");

    float avg = findAvg(dataset);
    std::cout << "avg: " << avg << std::endl;

    float min = findMin(dataset);
    std::cout << "min: " << min << std::endl;

    float max = findMax(dataset);
    std::cout << "max: " << max << std::endl;

    system("pause");
    return 0;
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
    float *vec = new float[size];
	std::random_device rd;

    for (int i = 0; i < size; i++)
    {
		std::mt19937 rng(rd());
		std::uniform_real_distribution<> num(0, 100);
        vec[i] = num(rd);
		//std::cout << vec[i] << std::endl;
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
