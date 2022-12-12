# Importing the code
Open the Implementation Folder, which will contain 2 CMake projects.

To open an existing CMake project in CLion, do the following:

    Select File | Open and locate the project directory. 
    This directory should contain a CMakeLists.txt file.

    Select File | Open and point CLion to the top-level CMakeLists.txt file, 
    then choose Open as Project.

    Select File | Open and locate the CMakeCache.txt file, 
    then choose Open as Project.

Follow the steps above for both ListGenerator and CS2353 projects.

CLion should automatically create a CMake Debug profile. If not, then you should navigate to File | Settings | Build, Executions, Deployment | CMake, and click the plus sign to add a debug profile. You may need to reload CMake Project, which can be done by navigating to file, and selecting "Reload CMake Project". Make sure that in the cmake-build-debug folder, that there is also a folder called data.

## Generating the Data Sets

Once ListGenerator has been imported to CLion, you can do the following:

    Use the existing input file, which contains 100 names for a total of 50 pairs.

    Import another .txt file of names, of which must be greater than or equal to 6 
    for a minimum of 3 pairs and a maximum of total number of N/2 pairs rounded down. 
    It should also have the same name as the provided list, which is called namelist.txt
    EX: 100 total names / 2 = maximum total of 50 pairs. 
        101 total names / 2 = maximum total of 50 pairs. 
        102 total names / 2 = maximum total of 51 pairs.

Make sure that if you are using a custom list, to make sure that the list is formatted like the provided list. It should just be a list of names with a single name on each line and nothing else.

    EX: Bob
        Joe
        Billy
        John
        Robert
        Smith

Go to CLion, go to the top bar and click the run, and then click edit configurations. In the program arguments, type in your desired number, data/namelist.txt, data/set_A.txt, data/set_B.txt in that order. If you change the name of the files in the data folder, make sure that it is also changed in the program arguments.

Run the program by clicking the green arrow button at the top right of CLion.

When running the program, type in the number of pairs that you want according to the constraints listed above.

The output files will be titled set_A.txt and set_B.txt, and will be located in the directory ListGenerator/cmake-build-debug/data, or simply go to the side bar of CLion, right click one of the two files under the cmake-build-debug folder, and select "Open in Explorer", which will open up the folder directory. Do not go to the ListGenerator/data folder, as the set_A and set_B txt files will not have anything written.

Copy the two files, and prepare to import the two files later.

## Stable Matching Algorithm

Once set_A.txt and set_B.txt have been copied, paste them into the CS2353/data folder. If you decided to keep the original data sets provided, you can ignore this step. (set_A.txt and set_B.txt have already been provided with this project, and was generated using the original list of names provided in ListGenerator.)

Go to CLion, go to the top bar and click the run, and then click edit configurations. In the program arguments, type in data/set_A.txt and data/set_B.txt. Make sure that it is in that order.

Run the program by clicking the green arrow button at the top right of CLion.

The output will appear in the console, as well as the verification of the stability of the matches.

Keep in mind that the more number of pairs the program must match, the longer it will take to finish. As a baseline, 50 pairs should take roughly 5-20 seconds depending on the computer.