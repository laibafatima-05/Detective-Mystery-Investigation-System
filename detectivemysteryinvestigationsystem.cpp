#include <iostream>
#include <string>
#include <vector>
using namespace std;

class InvestigationItem
{
protected:
    int id;
public:
    InvestigationItem(int i)
    {
        id = i;
    }
    virtual void display()
    {
        cout << "Investigation Item ID: " << id << endl;
    }
    virtual ~InvestigationItem() {}
};
class Case
{
private:
    int caseID;
    string caseTitle;
    string crimeType;
    string location;
    string status;
public:
    Case(int id, string title, string crime, string loc)
    {
        caseID = id;
        caseTitle = title;
        crimeType = crime;
        location = loc;
        status = "Open";
    }
    void displayCase()
    {
        cout << "\nCase ID: " << caseID << endl;
        cout << "Title: " << caseTitle << endl;
        cout << "Crime Type: " << crimeType << endl;
        cout << "Location: " << location << endl;
        cout << "Status: " << status << endl;
    }
};

class Suspect
{
private:
    int suspectID;
    string name;
    int age;
    string occupation;
    string status;
public:
    Suspect(int id, string n, int a, string occ)
    {
        suspectID = id;
        name = n;
        age = a;
        occupation = occ;
        status = "Under Investigation";
    }
    string getName()
    {
        return name;
    }
    void displaySuspect()
    {
        cout << "\nSuspect ID: " << suspectID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Occupation: " << occupation << endl;
        cout << "Status: " << status << endl;
    }
};
class Evidence : public InvestigationItem
{
private:
    string type;
    string description;
    string location;
public:
    Evidence(int id, string t, string d, string loc)
        : InvestigationItem(id)
    {
        type = t;
        description = d;
        location = loc;
    }
    void display() override
    {
        cout << "\nEvidence ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Description: " << description << endl;
        cout << "Location: " << location << endl;
    }
};

class Clue : public InvestigationItem
{
private:
    string description;
    string relatedSuspect;
public:
    Clue(int id, string d, string suspect)
        : InvestigationItem(id)
    {
        description = d;
        relatedSuspect = suspect;
    }
    string getRelatedSuspect()
    {
        return relatedSuspect;
    }
    void display() override
    {
        cout << "\nClue ID: " << id << endl;
        cout << "Description: " << description << endl;
        cout << "Related Suspect: " << relatedSuspect << endl;
    }
};
class InvestigationSystem
{
private:
    vector<Case> cases;
    vector<Suspect> suspects;
    vector<Evidence> evidences;
    vector<Clue> clues;

    int nextCaseID = 101;
    int nextSuspectID = 1;
    int nextEvidenceID = 1;
    int nextClueID = 1;
public:
   void addCase()
    {
        string title, crime, location;
        cout << "\nEnter Case Title: ";
        getline(cin >> ws, title);

        cout << "Enter Crime Type: ";
        getline(cin, crime);

        cout << "Enter Location: ";
        getline(cin, location);

        cases.push_back(
            Case(nextCaseID, title, crime, location)
        );
        cout << "\nCase Added Successfully!" << endl;
        cout << "Case ID: " << nextCaseID << endl;
        cout << "Status: Open" << endl;
        nextCaseID++;
    }
    void viewCases()
    {
        if (cases.empty())
        {
            cout << "\nNo cases available." << endl;
            return;
        }
        cout << "\nCASES" << endl;
        for (Case &c : cases)
        {
            c.displayCase();
        }
    }
    void addSuspect()
    {
        string name, occupation;
        int age;

        cout << "\nEnter Suspect Name: ";
        getline(cin >> ws, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Occupation: ";
        getline(cin >> ws, occupation);

        suspects.push_back(
            Suspect(nextSuspectID, name, age, occupation)
        );
        cout << "\nSuspect Added Successfully!" << endl;
        cout << "Suspect ID: " << nextSuspectID << endl;
        cout << "Status: Under Investigation" << endl;
        nextSuspectID++;
    }
    void viewSuspects()
    {
        if (suspects.empty())
        {
            cout << "\nNo suspects available." << endl;
            return;
        }
        cout << "\nSUSPECTS" << endl;

        for (Suspect &s : suspects)
        {
            s.displaySuspect();
        }
    }
    void addEvidence()
    {
        string type, description, location;

        cout << "\nEnter Evidence Type: ";
        getline(cin >> ws, type);

        cout << "Enter Description: ";
        getline(cin, description);

        cout << "Enter Location: ";
        getline(cin, location);

        evidences.push_back(
            Evidence(nextEvidenceID, type, description, location)
        );

        cout << "\nEvidence Added Successfully!" << endl;
        cout << "Evidence ID: " << nextEvidenceID << endl;
        nextEvidenceID++;
    }
    void viewEvidence()
    {
        if (evidences.empty())
        {
            cout << "\nNo evidence available." << endl;
            return;
        }
        cout << "\n========== EVIDENCE ==========" << endl;
        for (Evidence &e : evidences)
        {
            e.display();
        }
    }
    void addClue()
    {
        string description, relatedSuspect;

        cout << "\nEnter Clue Description: ";
        getline(cin >> ws, description);

        cout << "Enter Related Suspect Name: ";
        getline(cin, relatedSuspect);

        clues.push_back(
            Clue(nextClueID, description, relatedSuspect)
        );

        cout << "\nClue Added Successfully!" << endl;
        cout << "Clue ID: " << nextClueID << endl;
        nextClueID++;
    }
    void viewClues()
    {
        if (clues.empty())
        {
            cout << "\nNo clues available." << endl;
            return;
        }

        cout << "\nCLUES" << endl;

        for (Clue &c : clues)
        {
            c.display();
        }
    }

    void solveCase()
    {
        if (suspects.empty() || clues.empty())
        {
            cout << "\nNot enough information to solve the case." << endl;
            return;
        }
        cout << "\nSOLVE CASE" << endl;
        bool found = false;

        for (Clue &c : clues)
        {
            for (Suspect &s : suspects)
            {
                if (c.getRelatedSuspect() == s.getName())
                {
                    cout << "\nPossible Suspect: "
                         << s.getName() << endl;

                    found = true;
                }
            }
        }
        if (found)
        {
            cout << "\nCase investigation completed!" << endl;
        }
        else
        {
            cout << "\nNo possible suspect found." << endl;
        }
    }
    void showInvestigationItems()
    {
        cout << "\nINVESTIGATION ITEMS" << endl;
        vector<InvestigationItem*> items;
        for (Evidence &e : evidences)
        {
            items.push_back(&e);
        }
        for (Clue &c : clues)
        {
            items.push_back(&c);
        }
        for (InvestigationItem* item : items)
        {
            item->display();
        }
    }
};
int main()
{
    InvestigationSystem system;
    int choice;
    do
    {
        cout << " DETECTIVE MYSTERY INVESTIGATION SYSTEM" << endl;
        cout << "\n1. Case Management" << endl;
        cout << "2. Suspect Management" << endl;
        cout << "3. Evidence Collection" << endl;
        cout << "4. Clue Investigation" << endl;
        cout << "5. Solve Case" << endl;
        cout << "6. View Investigation Items" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int option;
            cout << "\nCASE MANAGEMENT" << endl;
            cout << "1. Add Case" << endl;
            cout << "2. View Cases" << endl;
            cout << "3. Back" << endl;
            cout << "Enter your choice: ";
            cin >> option;

            if (option == 1)
                system.addCase();
            else if (option == 2)
                system.viewCases();

            break;
        }
        case 2:
        {
            int option;
            cout << "\nSUSPECT MANAGEMENT" << endl;
            cout << "1. Add Suspect" << endl;
            cout << "2. View Suspects" << endl;
            cout << "3. Back" << endl;
            cout << "Enter your choice: ";
            cin >> option;

            if (option == 1)
                system.addSuspect();
            else if (option == 2)
                system.viewSuspects();

            break;
        }
        case 3:
        {
            int option;
            cout << "\nEVIDENCE COLLECTION" << endl;
            cout << "1. Add Evidence" << endl;
            cout << "2. View Evidence" << endl;
            cout << "3. Back" << endl;
            cout << "Enter your choice: ";
            cin >> option;

            if (option == 1)
                system.addEvidence();
            else if (option == 2)
                system.viewEvidence();

            break;
        }
        case 4:
        {
            int option;

            cout << "\nCLUE INVESTIGATION" << endl;
            cout << "1. Add Clue" << endl;
            cout << "2. View Clues" << endl;
            cout << "3. Back" << endl;
            cout << "Enter your choice: ";
            cin >> option;

            if (option == 1)
                system.addClue();
            else if (option == 2)
                system.viewClues();

            break;
        }
        case 5:
            system.solveCase();
            break;
        case 6:
            system.showInvestigationItems();
            break;
        case 7:
            cout << "\nThank you for using Detective Mystery Investigation System!" << endl;
            break;
        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } 
    while (choice != 7);
    return 0;
}