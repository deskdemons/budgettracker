#include "budgetmanager.h"
#include <string>
#include <fstream>


// checks if a file exists or not, if doesnot exisit, it creates a file
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
            fout << "pk,user_id,title,category,datetime,currency";

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
