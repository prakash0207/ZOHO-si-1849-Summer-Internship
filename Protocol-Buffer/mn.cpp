#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "login.pb.h"     //user (name, location etc…). protocol structure
#include "file.pb.h"      //Notepad project created should have its content stored in a separate file. gets store using the proto file header
#include "filedata.pb.h"  //Project structure stored in separate file
#include "version.pb.h"   //Version structure will have a id, createdTime, versionNumber etc.. and projectId to map the project.

using namespace std;

//Project portal module
void projectPortal(int userId)
{
    //Once the user logs in, there must be an option with CreateNewFile and also list the already created projects.
    int projectPortalChoice;
    cout << "1)Create new Project" << endl;
    cout << "2)Open already created Project" << endl;
    cin >> projectPortalChoice;
    if (projectPortalChoice == 1)
    {
        string fileName, fileInput;
        int fileId = 0;
        string fileContent;
        bool flag = false;

        textfile::FilePersonBook fpb;
        textfile::FilePerson fp;
        textfile::FilePerson::FileProperties fpp;

        projectstructure::FilePersonBook fpb1;
        projectstructure::FilePerson fp1;
        projectstructure::FilePerson::FileProperties fpp1;
        {
            // Read the existing address book.
            fstream input("file.bin", ios::in | ios::binary);
            if (!input)
            {
                cout << "file.bin" << ": File not found.  Creating a new file." << endl;
            }
            else if (!fpb.ParseFromIstream(&input))
            {
                cerr << "Failed to parse address book." << endl;
            }
        }
        {
            // Read the existing address book.
            fstream input("filestructure.bin", ios::in | ios::binary);
            if (!input)
            {
                cout << "filestructure.bin" << ": File not found.  Creating a new file." << endl;
            }
            else if (!fpb1.ParseFromIstream(&input))
            {
                cerr << "Failed to parse address book." << endl;
            }
        }


        fp.set_userid(userId);
        fp1.set_userid(userId);

      //  std::string* name = person.mutable_name();
        cout << "Enter The file name: ";
        cin >> fileName;

        for (int i = 0; i < fpb.people_size(); i++)
        {
            for (int j = 0; j < fpb.people(i).file_size(); j++)
            {
                if (fpb.people(i).file(j).filename() == fileName && fpb.people(i).userid() == userId)
                {
                    cout << "File name already exist Please try again with different file name or open the file" << endl;
                    return(projectPortal(userId));
                }
                if (fpb.people(i).file(j).fileid() > 0)
                {
                    fileId = fpb.people(i).file(j).fileid();
                }
                
            }
        }
        cout << "New file is created (In new line type Q to exit):-" << endl;
        cin.get();
        getline(cin, fileContent, 'Q');

        fileId = fileId + 1;
        fpp.set_fileid(fileId);
        fpp.set_filename(fileName);
        fpp.set_filecontent(fileContent);
        fp.add_file()->CopyFrom(fpp);
        fpb.add_people()->CopyFrom(fp);

        fpp1.set_fileid(fileId);
        fpp1.set_filename(fileName);
        fp1.add_file()->CopyFrom(fpp1);
        fpb1.add_people()->CopyFrom(fp1);


        {
            fstream output("file.bin", ios::out | ios::trunc | ios::binary);
            if (!fpb.SerializeToOstream(&output))
            {
                cerr << "Failed to write address book." << endl;
            }
        }

        {
            fstream output("filestructure.bin", ios::out | ios::trunc | ios::binary);
            if (!fpb1.SerializeToOstream(&output))
            {
                cerr << "Failed to write address book." << endl;
            }
        }
        return projectPortal(userId);
    }










    else
    {
        string fileChoiceName;
        int optionToEdit;
        textfile::FilePersonBook fpb;
        int operationNumber = 0;
        int versionNumber = 1;
        int fileId;




        {
            // Read the existing address book.
            fstream input("file.bin", ios::in | ios::binary);
            if (!input)
            {
                cout << "file.bin" << ": File not found.  Creating a new file." << endl;
            }
            else if (!fpb.ParseFromIstream(&input))
            {
                cerr << "Failed to parse address book." << endl;
            }
        }

        for (int i = 0; i < fpb.people_size(); i++)
        {
            for (int j = 0; j < fpb.people(i).file_size(); j++)
            {
                if (fpb.people(i).userid() == userId)
                {
                    if (fpb.people(i).file(j).filename() != "")
                    {
                        cout << fpb.people(i).file(j).filename() << endl;
                    }
                    
                }                
            }
        }
        bool flag = true;

        cout << "Enter the project name to open the project: ";
        cin >> fileChoiceName;
        for (int i = 0; i < fpb.people_size(); i++)
        {
            for (int j = 0; j < fpb.people(i).file_size(); j++)
            {
                if (fpb.people(i).userid() == userId && fpb.people(i).file(j).filename() == fileChoiceName)
                {
                    fileId = fpb.people(i).file(j).fileid();
                    cout << "File is located!"<<endl;
                    flag = false;
                }
            }
        }
        if (flag == true)
        {
            cout << "File is not available enter a valid file name" << endl;
            return projectPortal(userId);
        }
        do
        {
            version::FileBook fb;
            version::ParticularFile pf;
            version::ParticularFile::Version pfv;
            {
                // Read the existing address book.
                fstream input("version.bin", ios::in | ios::binary);
                if (!input)
                {
                    cout << "version.bin" << ": File not found.  Creating a new file." << endl;
                }
                else if (!fb.ParseFromIstream(&input))
                {
                    cerr << "Failed to parse address book." << endl;
                }
            }

            //Once the user opens any of the project , have to show options to Add, update, remove and display the notepad content.

            cout << "1)Add" << endl;
            cout << "2)Update" << endl;
            cout << "3)Remove" << endl;
            cout << "4)Display" << endl;
            cout << "5)Revert Back To a version" << endl;
            cout << "6)Exit" << endl;
            cin >> optionToEdit;




            if (optionToEdit == 1)
            {
                string fileContent;
                cout << "Enter the content to append at the end of the file(In new line type Q to exit): ";
                cin.get();
                getline(cin, fileContent, 'Q');


                

                for (int i = 0; i < fpb.people_size(); i++)
                {
                    for (int j = 0; j < fpb.people(i).file_size(); j++)
                    {
                        if (fpb.people(i).userid() == userId && fpb.people(i).file(j).filename() == fileChoiceName)
                        {
                            fileContent = fpb.people(i).file(j).filecontent() + fileContent;
                            fpb.mutable_people(i)->mutable_file(j)->set_filecontent(fileContent);
                        }
                    }
                }




                pfv.set_filecontent(fileContent);
                for (int i = 0; i < fb.file_size(); i++)
                {
                    if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                    {
                        for (int j = 0; j < fb.file(i).ver_size(); j++)
                        {
                            if (fb.file(i).ver(j).operationno() > 0)
                            {
                                operationNumber = fb.file(i).ver(j).operationno();
                            }
                            if (fb.file(i).ver(j).versionno() > 0)
                            {
                                versionNumber = fb.file(i).ver(j).versionno();
                            }
                        }
                    }
                }

                chrono::system_clock::time_point p = chrono::system_clock::now();
                time_t t = chrono::system_clock::to_time_t(p);
                char str[27];
                ctime_s(str, sizeof str, &t); 
                pfv.set_time(str);


                operationNumber += 1;                
                pfv.set_operationno(operationNumber);

                //For every Nth operation create a version number. (N can be 5 by default).
                if (operationNumber % 5 == 0)
                {
                    versionNumber += 1;
                }
                pfv.set_versionno(versionNumber);
                pf.set_fileid(fileId);
                pf.set_userid(userId);
                pf.add_ver()->CopyFrom(pfv);
                fb.add_file()->CopyFrom(pf);

                {
                    fstream output("version.bin", ios::out | ios::trunc | ios::binary);
                    if (!fb.SerializeToOstream(&output))
                    {
                        cerr << "Failed to write address book." << endl;
                    }
                }

                {
                    fstream output("file.bin", ios::out | ios::binary);
                    if (!fpb.SerializeToOstream(&output))
                    {
                        cerr << "Failed to write address book." << endl;
                    }
                }
                
               
            }

            if (optionToEdit == 2)
            {
                int editChoice;
                cout << "1) To overwrite a particular line" << endl;
                cout << "2) To overwrite the entire document" << endl;
                cin >> editChoice;
                if (editChoice == 1)
                {
                    string toUpdate;
                    char updated[10001];
                    int line;
                    int count=1;
                    
                    bool check = true;
                    int counter=0;
                    string updatedS;
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).file(j).filename() == fileChoiceName && fpb.people(i).userid() == userId)
                            {                                
                                for (int k = 0; k < fpb.people(i).file(j).filecontent().length(); k++)
                                {

                                    if ((fpb.people(i).file(j).filecontent()[k] == '\n' || k == 0) && (fpb.people(i).file(j).filecontent()[k+1] != '\0'))
                                    {
                                        cout << endl;
                                        cout << count << ")";
                                        count += 1;
                                    }
                                    
                                    if (fpb.people(i).file(j).filecontent()[k] != '\n' )
                                    {
                                        cout << fpb.people(i).file(j).filecontent()[k];
                                    }
                                    
                                    
                                  
                                }
                                cout << endl;
                                break;
                            }
                        }
                    }

                    cout << "Enter the line that needs to be changed: ";
                    cin >> line;
                    cout << "Enter the text that needs to be overwritten: ";
                    cin.get();
                    getline(cin, toUpdate);
                    count = 0;
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).file(j).filename() == fileChoiceName && fpb.people(i).userid() == userId)
                            {
                                for (int k = 0; k < fpb.people(i).file(j).filecontent().length(); k++)
                                {

                                    if (count == line - 1)
                                    {
                                        if (check)
                                        {
                                            for (int l = 0; l < toUpdate.length(); l++)
                                            {
                                                updated[counter] = toUpdate[l];
                                                counter += 1;
                                            }
                                            updated[counter] = '\n';
                                            counter += 1;
                                            check = false;
                                        }
                                    }
                                    else
                                    {
                                        updated[counter] = fpb.people(i).file(j).filecontent()[k];
                                        counter += 1;
                                    }
                                    if (fpb.people(i).file(j).filecontent()[k] == '\n')
                                    {
                                        count += 1;
                                    }
                                }
                                updated[counter] = '\0';                             
                                updatedS += updated;


                                pfv.set_filecontent(updatedS);
                                for (int i = 0; i < fb.file_size(); i++)
                                {
                                    if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                                    {
                                        for (int j = 0; j < fb.file(i).ver_size(); j++)
                                        {
                                            if (fb.file(i).ver(j).operationno() > 0)
                                            {
                                                operationNumber = fb.file(i).ver(j).operationno();
                                            }
                                            if (fb.file(i).ver(j).versionno() > 0)
                                            {
                                                versionNumber = fb.file(i).ver(j).versionno();
                                            }
                                        }
                                    }
                                }

                                chrono::system_clock::time_point p = chrono::system_clock::now();
                                time_t t = chrono::system_clock::to_time_t(p);
                                char str[27];
                                ctime_s(str, sizeof str, &t);
                                pfv.set_time(str);

                                operationNumber += 1;
                                pfv.set_operationno(operationNumber);

                                //For every Nth operation create a version number. (N can be 5 by default).
                                if (operationNumber % 5 == 0)
                                {
                                    versionNumber += 1;
                                }
                                pfv.set_versionno(versionNumber);
                                pf.set_fileid(fileId);
                                pf.set_userid(userId);
                                pf.add_ver()->CopyFrom(pfv);
                                fb.add_file()->CopyFrom(pf);

                                {
                                    fstream output("version.bin", ios::out | ios::trunc | ios::binary);
                                    if (!fb.SerializeToOstream(&output))
                                    {
                                        cerr << "Failed to write address book." << endl;
                                    }
                                }


                                fpb.mutable_people(i)->mutable_file(j)->set_filecontent(updatedS);
                                {
                                    fstream output("file.bin", ios::out | ios::binary);
                                    if (!fpb.SerializeToOstream(&output))
                                    {
                                        cerr << "Failed to write address book." << endl;
                                    }
                                }


                                break;
                            }
                        }
                    }

                    
                }
                else
                {
                    string toUpdate;
                    cout << "Enter the contents to be overwritten"<<endl;
                    getline(cin, toUpdate, 'Q');
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).userid() == userId && fpb.people(i).file(j).filename() == fileChoiceName)
                            {
                                fpb.mutable_people(i)->mutable_file(j)->set_filecontent(toUpdate);

                                {
                                    fstream output("file.bin", ios::out | ios::binary);
                                    if (!fpb.SerializeToOstream(&output))
                                    {
                                        cerr << "Failed to write address book." << endl;
                                    }
                                }
                            }
                        }
                    }

                    pfv.set_filecontent(toUpdate);
                    for (int i = 0; i < fb.file_size(); i++)
                    {
                        if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                        {
                            for (int j = 0; j < fb.file(i).ver_size(); j++)
                            {
                                if (fb.file(i).ver(j).operationno() > 0)
                                {
                                    operationNumber = fb.file(i).ver(j).operationno();
                                }
                                if (fb.file(i).ver(j).versionno() > 0)
                                {
                                    versionNumber = fb.file(i).ver(j).versionno();
                                }
                            }
                        }
                    }

                    chrono::system_clock::time_point p = chrono::system_clock::now();
                    time_t t = chrono::system_clock::to_time_t(p);
                    char str[27];
                    ctime_s(str, sizeof str, &t);
                    pfv.set_time(str);

                    operationNumber += 1;
                    pfv.set_operationno(operationNumber);

                    //For every Nth operation create a version number. (N can be 5 by default).
                    if (operationNumber % 5 == 0)
                    {
                        versionNumber += 1;
                    }
                    pfv.set_versionno(versionNumber);
                    pf.set_fileid(fileId);
                    pf.set_userid(userId);
                    pf.add_ver()->CopyFrom(pfv);
                    fb.add_file()->CopyFrom(pf);

                    {
                        fstream output("version.bin", ios::out | ios::trunc | ios::binary);
                        if (!fb.SerializeToOstream(&output))
                        {
                            cerr << "Failed to write address book." << endl;
                        }
                    }

                }

                
            }








            if (optionToEdit == 3)
            {
                int editChoice;
                cout << "1) To remove a particular line" << endl;
                cout << "2) To remove the entire document" << endl;
                cin >> editChoice;
                if (editChoice == 1)
                {
                    string toUpdate;
                    char updated[10001];
                    int line;
                    int count = 1;

                    bool check = true;
                    int counter = 0;
                    string updatedS;
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).file(j).filename() == fileChoiceName && fpb.people(i).userid() == userId)
                            {
                                for (int k = 0; k < fpb.people(i).file(j).filecontent().length(); k++)
                                {

                                    if ((fpb.people(i).file(j).filecontent()[k] == '\n' || k == 0) && (fpb.people(i).file(j).filecontent()[k + 1] != '\0'))
                                    {
                                        cout << endl;
                                        cout << count << ")";
                                        count += 1;
                                    }

                                    if (fpb.people(i).file(j).filecontent()[k] != '\n')
                                    {
                                        cout << fpb.people(i).file(j).filecontent()[k];
                                    }



                                }
                                cout << endl;
                                break;
                            }
                        }
                    }
                    cout << "Enter the line that needs to be removed: ";
                    cin >> line;
                    count = 0;
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).file(j).filename() == fileChoiceName && fpb.people(i).userid() == userId)
                            {
                                for (int k = 0; k < fpb.people(i).file(j).filecontent().length(); k++)
                                {

                                    if (count == line - 1)
                                    {
                                    }
                                    else
                                    {
                                        updated[counter] = fpb.people(i).file(j).filecontent()[k];
                                        counter += 1;
                                    }
                                    if (fpb.people(i).file(j).filecontent()[k] == '\n')
                                    {
                                        updated[counter] = fpb.people(i).file(j).filecontent()[k];
                                        count += 1;
                                    }
                                }
                                updated[counter] = '\0';
                                updatedS += updated;
                                fpb.mutable_people(i)->mutable_file(j)->set_filecontent(updatedS);
                                {
                                    fstream output("file.bin", ios::out | ios::binary);
                                    if (!fpb.SerializeToOstream(&output))
                                    {
                                        cerr << "Failed to write address book." << endl;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    pfv.set_filecontent(updatedS);
                    for (int i = 0; i < fb.file_size(); i++)
                    {
                        if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                        {
                            for (int j = 0; j < fb.file(i).ver_size(); j++)
                            {
                                if (fb.file(i).ver(j).operationno() > 0)
                                {
                                    operationNumber = fb.file(i).ver(j).operationno();
                                }
                                if (fb.file(i).ver(j).versionno() > 0)
                                {
                                    versionNumber = fb.file(i).ver(j).versionno();
                                }
                            }
                        }
                    }

                    chrono::system_clock::time_point p = chrono::system_clock::now();
                    time_t t = chrono::system_clock::to_time_t(p);
                    char str[27];
                    ctime_s(str, sizeof str, &t);
                    pfv.set_time(str);

                    operationNumber += 1;
                    pfv.set_operationno(operationNumber);

                    //For every Nth operation create a version number. (N can be 5 by default).
                    if (operationNumber % 5 == 0)
                    {
                        versionNumber += 1;
                    }
                    pfv.set_versionno(versionNumber);
                    pf.set_fileid(fileId);
                    pf.set_userid(userId);
                    pf.add_ver()->CopyFrom(pfv);
                    fb.add_file()->CopyFrom(pf);

                    {
                        fstream output("version.bin", ios::out | ios::trunc | ios::binary);
                        if (!fb.SerializeToOstream(&output))
                        {
                            cerr << "Failed to write address book." << endl;
                        }
                    }


                }
                else
                {
                    string toUpdate;
                    toUpdate = "";
                    
                    for (int i = 0; i < fpb.people_size(); i++)
                    {
                        for (int j = 0; j < fpb.people(i).file_size(); j++)
                        {
                            if (fpb.people(i).userid() == userId && fpb.people(i).file(j).filename() == fileChoiceName)
                            {
                                fpb.mutable_people(i)->mutable_file(j)->set_filename("");
                                fpb.mutable_people(i)->mutable_file(j)->set_fileid(-1);
                                fpb.mutable_people(i)->mutable_file(j)->set_filecontent("");
                               
                                {
                                    fstream output("file.bin", ios::out| ios::trunc | ios::binary);
                                    if (!fpb.SerializeToOstream(&output))
                                    {
                                        cerr << "Failed to write address book." << endl;
                                    }
                                }
                                return projectPortal(userId);
                            }
                        }
                    }
                    for (int i = 0; i < fb.file_size(); i++)
                    {
                        if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                        {
                            
                            fb.mutable_file(i)->Clear();
                            
                        }    
                    }
                    {
                        fstream output("version.bin", ios::out | ios::trunc | ios::binary);
                        if (!fb.SerializeToOstream(&output))
                        {
                            cerr << "Failed to write address book." << endl;
                        }
                    }
                    
                }
            }



            if (optionToEdit == 4)
            {
                int count = 1;
                for (int i = 0; i < fpb.people_size(); i++)
                {
                    for (int j = 0; j < fpb.people(i).file_size(); j++)
                    {
               //         cout << fpb.people(i).userid() << ":" << fpb.people(i).file(j).fileid() << endl;
                        
                        if (fpb.people(i).file(j).filename() == fileChoiceName && fpb.people(i).userid() == userId)
                        {
                            cout << "File Name: " << fileChoiceName << endl;
                            for (int k = 0; k < fpb.people(i).file(j).filecontent().length(); k++)
                            {

                                if ((fpb.people(i).file(j).filecontent()[k] == '\n' || k == 0) && (fpb.people(i).file(j).filecontent()[k + 1] != '\0'))
                                {
                                    cout << endl;
                                    cout << count << ".";
                                    count += 1;
                                }

                                if (fpb.people(i).file(j).filecontent()[k] != '\n')
                                {
                                    cout << fpb.people(i).file(j).filecontent()[k];
                                }



                            }
                            cout << endl;
                            cout << "\n";
                            
                        }
                        
                    }
                }
            }
            if (optionToEdit == 5)
            {
                int versionNo;
                string versionContent;
                for (int i = 0; i < fb.file_size(); i++)
                {
                    if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                    {
                        for (int j = 0; j < fb.file(i).ver_size(); j++)
                        {
                            cout << fb.mutable_file(i)->mutable_ver(j)->DebugString() << endl;
                        }
                    }
                }
                cout << "Enter Version number to get reverted: ";
                cin >> versionNo;
                bool flag = true;

                //option to revert to particular version
                for (int i = 0; i < fb.file_size() && flag; i++)
                {
                    if (fb.file(i).userid() == userId && fb.file(i).fileid() == fileId)
                    {
                        for (int j = 0; j < fb.file(i).ver_size() && flag; j++)
                        {
                            if (fb.file(i).ver(j).versionno() == versionNo)
                            {
                                versionContent = fb.file(i).ver(j).filecontent();
                                flag = false;
                                break;
                            }
                        }
                        
                    }
                    
                }

                for (int i = 0; i < fpb.people_size(); i++)
                {
                    for (int j = 0; j < fpb.people(i).file_size(); j++)
                    {
                        if (fpb.people(i).userid() == userId && fpb.people(i).file(j).filename() == fileChoiceName)
                        {
                            fpb.mutable_people(i)->mutable_file(j)->set_filecontent(versionContent);

                        }
                    }
                }

                {
                    fstream output("file.bin", ios::out | ios::trunc | ios::binary);
                    if (!fpb.SerializeToOstream(&output))
                    {
                        cerr << "Failed to write address book." << endl;
                    }
                }



            }
            
        } while (optionToEdit != 6);

    }
}



int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    login::PeopleBook pb;
    int signCheck = 0;
    bool loginCheck = true;
    {
        // Read the existing address book.
        fstream input("Login.bin", ios::in | ios::binary);
        if (!input) 
        {
            cout << "Login.bin" << ": File not found.  Creating a new file." << endl;
        }
        else if (!pb.ParseFromIstream(&input)) 
        {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }

    //User Portal
    while (loginCheck)
    {
        //Login Setup
        cout << "1) Sign up" << endl;
        cout << "2) Sign in" << endl;
        cin >> signCheck;
        if (signCheck == 1)
        {
            string name, email, location, password;
            int userId=0;
            bool flag = false;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Location: ";
            cin >> location;
            cout << "Enter Password: ";
            cin >> password;
            
            for (int i = 0; i < password.length(); i++)
            {
                password[i] = password[i] + 5;              //Encryption of password.
            }


            //Validation for signup
            for (int i = 0; i < pb.people_size(); i++)
            {
                if (pb.people(i).name() == name && pb.people(i).email() == email)
                {
                    cout << "User name and email already exist try sign in!" << endl;
                    flag = true;
                }
                userId = pb.people(i).userid();
            }
            userId = userId + 1;

            if (flag == false)
            {
                login::Person p1;
                p1.set_name(name);
                p1.set_location(location);
                p1.set_email(email);
                p1.set_password(password);
                p1.set_userid(userId);
                pb.add_people()->CopyFrom(p1);             
                {
                    fstream output("login.bin", ios::out | ios::trunc | ios::binary);
                    if (!pb.SerializeToOstream(&output))
                    {
                        cerr << "Failed to write address book." << endl;
                        return -1;
                    }
                }
            }
        }

        else
        {
            string email, password;
            int userId;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;

            for (int i = 0; i < password.length(); i++)
            {
                password[i] = password[i] + 5;
            }

            //validation for signin
            for (int i = 0; i < pb.people_size(); i++)
            {
                const login::Person& p = pb.people(i);
                if (p.email() == email && p.password() == password)
                {
                    cout << "Logged In!" << endl;
                    userId = p.userid();
                    loginCheck = false;
                    break;
                }
            }
            if (loginCheck == true)
            {
                cout << "Check User Name and password" << endl;
            }
            if (loginCheck == false)
            {
                projectPortal(userId);
            }
        }
    }
    
}
