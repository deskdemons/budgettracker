#include <string>
#include <vector>
#include <fstream>

#include "budgetmanager.h"

BudgetManager::BudgetManager()
{
    file_name = "budget.csv";

    file_exsistance_assert();

    const char *fname = "budget.csv";
    std::fstream fs;
    fs.open(fname, std::ios::in);

    // Read the file line by line
    std::string temp;
    Budget temp_budget;
    
    // Initial variable name values
    getline(fs,temp);
    
    while (fs.eof() == 0)
    {
        getline(fs, temp);

        Budget b(temp);
        all_budget.push_back(b);
    }
};

std::vector<Budget> BudgetManager::all()
{
    return all_budget;
};

// checks if a file exists or not
bool BudgetManager::file_exsistance_assert()
{
    const char *fname = "budget.csv";

    std::fstream fs;
    fs.open(fname, std::ios::in);

    if (!fs)
    {
        // File doesnot exist
        //Create a file
        std::ofstream fout(fname);
        if (fout)
        {
            // If the creation is successful
            fout << "#id,name,category,date,amount,currency" << std::endl;

            // Close the file handle after performing the operation
            fout.close();
        }
        return false;
    }
    else
    {
        return true;
    }
};