#include "Program.h"
#include "newoperator.h"
#include "dll.h"
#include "BST.h"
#include "sll.h"
#include "queue.h"
#include "Stack.h"
#include "Ds.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

vector<string> commands;

// This is the program default constructor.
// The constructor reads in strings from the standard input (cin) one
// line at a time until it encounters a line with the string "#", which
// serves as a sentinel value to indicate the end of input. Each string
// that is read in is added to the "commands" vector.
Program::Program()
{
    string comm;
    getline(cin, comm);
    while (comm.compare("#") != 0)
    {
        commands.push_back(comm);
        getline(cin, comm);
    }
}

void Program::parseCommands()
{
    std::map<string, std::unique_ptr<Stack<string>>> stackMap;
    std::map<string, std::unique_ptr<Queue<string>>> queueMap;
    std::map<string, std::unique_ptr<SLL<string>>> SLLMap;
    std::map<string, std::unique_ptr<DoublyLinkedList<string>>> DLLMap;
    std::map<string, std::unique_ptr<BST<string>>> BSTMap;

    map<string, Value1> prg;

    // This method uses a for-each loop to iterate over the "commands" vector,
    // which was filled with input from the user in the constructor of the Program class.
    for (auto c : commands)
    {
        // In each iteration, it creates a stringstream object,
        // "cmdStream", initialized with the current command string, "c".
        // It also declares several string variables:
        // "first", "Dstype", "stackName", "value", "aFvalue", "queueName", "SLLName"
        // and "BSTName" and an int variable "Qvalue"
        stringstream cmdStream(c);
        string first, Dstype, stackName, value, aFvalue, queueName, SLLName, BSTName, DLLName, VarName, varValue, Svalue;

        int Qvalue;
        cmdStream >> first >> Dstype;

        // Check the first word is "var" and second word is "Stack"
        // If both conditions are true, it creates a new unique_ptr to a Stack of strings
        // using the make_unique function, and assigns it to a variable "newStack".
        // Then insert newStack into the stackMap with the key of "stackName"
        // and value of the moved unique pointer "newStack".
        if (first == "var" && Dstype == "Stack")
        {

            auto newStack = make_unique<Stack<string>>();
            stackMap[stackName] = move(newStack);
            cout << "Stack has been created." << endl;
        }

        // Check the first word is "var" and second word is "Queue"
        // If both conditions are true, it creates a new unique_ptr to a Queue of strings
        // using the make_unique function, and assigns it to a variable "newQueue".
        // Then insert newQueue into the queueMap with the key of "queueName"
        // and value of the moved unique pointer "newQueue".
        if (first == "var" && Dstype == "Queue")
        {
            auto newQueue = make_unique<Queue<string>>();
            queueMap[queueName] = move(newQueue);
            cout << "Queue has been created." << endl;
        }

        // Check the first word is "var" and second word is "SLL"
        // If both conditions are true, it creates a new unique_ptr to a SLL of strings
        // using the make_unique function, and assigns it to a variable "newSLL".
        // Then insert newSLL into the SLLMap with the key of "SLLName"
        // and value of the moved unique pointer "newSLL".
        if (first == "var" && Dstype == "SLL")
        {
            auto newSSL = make_unique<SLL<string>>();
            SLLMap[SLLName] = move(newSSL);
            cout << "SLL has been created." << endl;
        }

        // Check the first word is "var" and second word is "DLL"
        // If both conditions are true, it creates a new unique_ptr to a DLL of strings
        // using the make_unique function, and assigns it to a variable "newDLL".
        // Then insert newDLL into the DLLMap with the key of "DLLName"
        // and value of the moved unique pointer "newDLL".
        if (first == "var" && Dstype == "DLL")
        {
            auto newDLL = std::make_unique<DoublyLinkedList<string>>();
            DLLMap[DLLName] = std::move(newDLL);
            std::cout << "DLL " << queueName << " has been created." << std::endl;
        }

        // Check the first word is "var" and second word is "BST"
        // If both conditions are true, it creates a new unique_ptr to a BST of strings
        // using the make_unique function, and assigns it to a variable "newBST".
        // Then insert newBST into the BSTMap with the key of "BSTName"
        // and value of the moved unique pointer "newBST".
        if (first == "var" && Dstype == "BST")
        {
            auto newBST = make_unique<BST<string>>();
            BSTMap[BSTName] = move(newBST);
            cout << "BST has been created." << endl;
        }

        //------------------------------Stack & Queue --------------------------------

        // Check the first word is "push"
        // it uses the stringstream object to extract another word,"value",from the command string

        else if (first == "push")
        {

            cmdStream >> value;
            // Then, it uses the find() method to check if the "stackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "Push" method for Stack
            if (stackMap.find(stackName) != stackMap.end())
            {

                stackMap[stackName]->Push(value);
            }

            // else, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "Push" method for Queue
            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->Push(value);
            }

            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }

        // Check the first word is "isEmpty"
        else if (first == "isEmpty")
        {
            // Then, it uses the find() method to check if the "stackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "isEmpty" method for Stack
            if (stackMap.find(stackName) != stackMap.end())
            {

                stackMap[stackName]->isEmpty();
            }

            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "isEmpty" method for Queue
            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->isEmpty();
            }
            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }
        // Check the first word is "pop"
        else if (first == "pop")
        {
            // Then, it uses the find() method to check if the "stackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "isEmpty" method for Stack
            cmdStream >> value;
            if (stackMap.find(stackName) != stackMap.end())
            {

                stackMap[stackName]->Pop();
            }

            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "isEmpty" method for Queue
            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->Pop();
            }
            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }

        //------------------------Stack, Queue, SLL, DLL, BST -------------------------

        // Check the first word is "delete"
        else if (first == "delete")
        {

            // Then, it uses the find() method to check if the "StackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "delete" method for Stack
            if (stackMap.find(stackName) != stackMap.end())
            {
                stackMap[stackName]->deleteDs();
                cout << "Stack is deleted" << endl;
            }

            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "delete" method for Queue
            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->deleteDs();
                cout << "Queue is deleted" << endl;
            }

            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "delete" method for SLL
            else if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->deleteDs();
                cout << "List has been deleted!" << endl;
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "delete" method for DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->deleteDs();
                cout << "DLL is deleted." << std::endl;
            }

            else if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->deleteDs();
                cout << "BST is deleted." << endl;
            }

            else
            {
                cout << "Error: Data Structure does not exist." << endl;
            }
        }

        // Check the first word is "print"
        else if (first == "print")
        {
            // Then, it uses the find() method to check if the "stackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "print" method for Stack
            if (stackMap.find(stackName) != stackMap.end())
            {

                stackMap[stackName]->Print();
            }
            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "print" method for Queue
            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->Print();
            }

            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "print" method for SLL
            else if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->Print();
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "print" method for  DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->Print();
            }
            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }

        else if (first == "search")
        {
            cmdStream >> value;
            if (stackMap.find(stackName) != stackMap.end())
            {

                stackMap[stackName]->search(value);
            }

            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->search(value);
            }

            else if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->search(value);
            }

            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->search(value);
            }

            else if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->search(value);
            }
        }

        else if (first == "sortAsc")
        {
            cmdStream >> stackName;
            if (stackMap.find(stackName) != stackMap.end())
            {
                stackMap[stackName]->sortAscending();
            }

            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->sortAscending();
            }

            else if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->sortAscending();
            }

            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->sortAscending();
            }

            else if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[(BSTName)]->sortAscending();
            }

            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }

        else if (first == "sortDes")
        {
            cmdStream >> stackName;
            if (stackMap.find(stackName) != stackMap.end())
            {
                stackMap[stackName]->sortDescending();
            }

            else if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->sortDescending();
            }

            else if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->sortDescending();
            }

            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->sortDescending();
            }

            else if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->sortDescending();
            }

            else
            {
                cout << "Error: Not a valid variable name." << endl;
            }
        }

        //------------------------Stack --------------------------------

        // Check the first word is "top"
        else if (first == "top")
        {
            // Then, it uses the find() method to check if the "stackMap" map contains an entry
            // with the key "stackName". If the key is found in the map, it calls the "showTop" method for Stack

            if (stackMap.find(stackName) != stackMap.end())
            {
                stackMap[stackName]->showTop();
            }
            else
            {
                cout << "Error: Stack does not exist." << endl;
            }
        }

        // -------------------------Queue--------------------------------------

        // Check the first word is "front"
        else if (first == "front")
        {
            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "front" method for Queue

            if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->front();
            }
            else
            {
                cout << "Error: Queue does not exist." << endl;
            }
        }

        // Check the first word is "back"
        else if (first == "back")
        {
            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "back" method for Queue
            cmdStream >> queueName;
            if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->back();
            }
            else
            {
                cout << "Error: Queue does not exist." << endl;
            }
        }
        // Check the first word is "resize"
        // it uses the stringstream object to extract another word,"Qvalue",from the command string
        else if (first == "resize")
        {
            // Then, it uses the find() method to check if the "queueMap" map contains an entry
            // with the key "queueName". If the key is found in the map, it calls the "resize" method for Queue
            cmdStream >> Qvalue;
            if (queueMap.find(queueName) != queueMap.end())
            {
                queueMap[queueName]->resize(Qvalue);
            }
            else
            {
                cout << "Error: Queue does not exist." << endl;
            }
        }

        //--------------------------------Single Link List & Doubly Link List --------------------------------

        // Check the first word is "AddE"
        // it uses the stringstream object to extract another word,"value",from the command string
        else if (first == "AddE")
        {
            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "push_back" method for SLL
            cmdStream >> value;
            if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->push_back(value);
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "push_back" method for DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->push_back(value);
            }
            else
            {
                cout << "Error: SLL does not exist." << endl;
            }
        }

        // Check the first word is "AddF"
        // it uses the stringstream object to extract another word,"value",from the command string
        else if (first == "AddF")
        {
            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "push_front" method for SLL
            cmdStream >> value;
            if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->push_front(value);
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "push_front" method for DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->push_front(value);
            }

            else
            {
                cout << "Error: SLL does not exist." << endl;
            }
        }

        // Check the first word is "AddA"
        // it uses the stringstream object to extract another word,"value" and "aFvalue",from the command string
        else if (first == "AddA")
        {
            if (cmdStream >> value >> aFvalue)
            {
                // Then, it uses the find() method to check if the "SLLMap" map contains an entry
                // with the key "SLLName". If the key is found in the map, it calls the "insert_after" method for SLL
                if (SLLMap.find(SLLName) != SLLMap.end())
                {

                    SLLMap[SLLName]->insert_after(value, aFvalue);
                }

                // Then, it uses the find() method to check if the "DLLMap" map contains an entry
                // with the key "DLLName". If the key is found in the map, it calls the "insert_after" method for DLL
                else if (DLLMap.find(DLLName) != DLLMap.end())
                {
                    DLLMap[DLLName]->insert_after(value, aFvalue);
                }
                else
                {
                    cout << "Error: SLL does not exist." << endl;
                }
            }

            else
            {
                cout << "Error: SLL does not exist." << endl;
            }
        }

        // Check the first word is "DelF"
        else if (first == "DelF")
        {
            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "pop_front" method for SLL
            if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->pop_front();
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "pop_front" method for DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->pop_front();
            }

            else
            {
                cout << "Error: SLL does not exist." << endl;
            }
        }

        // Check the first word is "DelE"
        else if (first == "DelE")
        {
            // Then, it uses the find() method to check if the "SLLMap" map contains an entry
            // with the key "SLLName". If the key is found in the map, it calls the "pop_back" method for SLL
            if (SLLMap.find(SLLName) != SLLMap.end())
            {
                SLLMap[SLLName]->pop_back();
            }

            // Then, it uses the find() method to check if the "DLLMap" map contains an entry
            // with the key "DLLName". If the key is found in the map, it calls the "pop_back" method for DLL
            else if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->pop_back();
            }
            else
            {
                cout << "Error: SLL does not exist." << endl;
            }
        }

        //-----------------------------------------DLL-------------------------------------------------

        else if (first == "printR")
        {
            cmdStream >> DLLName;
            if (DLLMap.find(DLLName) != DLLMap.end())
            {
                DLLMap[DLLName]->PrintR();
            }
            else
            {
                std::cout << "Error: DLL " << DLLName << " does not exist." << std::endl;
            }
        }

        //----------------------------------------------BST--------------------------------------------------------

        // Check the first word is "insert"
        else if (first == "insert")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "insert" method for BST
            cmdStream >> value;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->insert(value);
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        // Check the first word is "remove"
        else if (first == "remove")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "remove" method for BST
            cmdStream >> value;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->remove(value);
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        // Check the first word is "inorder"
        else if (first == "inorder")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "inorder" method for BST
            cmdStream >> BSTName;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->inOrderTraverse();
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        // Check the first word is "preorder"
        else if (first == "preorder")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "preorder" method for BST
            cmdStream >> BSTName;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->preOrderTraverse();
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        // Check the first word is "postorder"
        else if (first == "postorder")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "postorder" method for BST
            cmdStream >> BSTName;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->postOrderTraverse();
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        // Check the first word is "root"
        else if (first == "root")
        {
            // Then, it uses the find() method to check if the "BSTMap" map contains an entry
            // with the key "BSTName". If the key is found in the map, it calls the "root" method for BST
            cmdStream >> BSTName;
            if (BSTMap.find(BSTName) != BSTMap.end())
            {
                BSTMap[BSTName]->getRoot();
            }
            else
            {
                cout << "Error: BST does not exist." << endl;
            }
        }

        //--------------------------------operator-------------------
        else if (first == "read")
        {
            newoperator q;
            q.read();
        }
    }
}
