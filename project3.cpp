#include <iostream>
#include <cstdio>
#include <cstdlib>
// #include "lexer.h"
// #include "execute.h"

using namespace std;


void Task1()
{
    cout << "1\n";
}

// Task 1
void Task2()
{
    cout << "2\n";
}

// Task 3
void Task3()
{
    instNode *code;
    // program 
    // SCALAR a b c d	 
    // ARRAY x y z
    // a = 1;
    // b = 2;
    // c = 3;
    // d = (a+b)*(b+c);
    // OUTPUT d;
    // x[a+b] = d;
    // OUTPUT x[3];
    // 
    // 	a will be at location 0
    // 	b will be at location 1
    // 	c will be at location 2
    //	d will be at location 3
    //	x will be at location 4 - 13
    //	y will be at location 14 - 23
    //	z will be at location 24 - 33
    // 	t1 will be at location 34 : intermediate value for (a+b)
    // 	t2 will be at location 35 : intermediate value for (b+c)
    // 	t3 will be at location 36 : intermediate value (a+b)*(b+c)
    // 	t4 will be at location 37 : intermediate value for a+b index of array
    // 	t5 will be at location 38 : intermediate value for addr of x[a+b] =
    // 				    address_of_x + value of a+b = 
    // 				    4 + value of a+b
    // 	t6 will be at location 39 : intermediate value for addr of x[3] =
    // 				    address_of_x + value of 3 =
    // 				    4 + value of 3 (computation is not done at
    // 				    compile time)
    // 				    
    instNode * i01 = new instNode();
    i01->lhsat=DIRECT; i01->lhs = 0;    // a
    i01->iType=ASSIGN_INST;	        // = 
    i01->op1at=IMMEDIATE; i01->op1 = 1; // 1 
    i01->oper = OP_NOOP;                // no operator

    instNode * i02 = new instNode();
    i02->lhsat=DIRECT; i02->lhs = 1;    // b
    i02->iType=ASSIGN_INST;	        // = 
    i02->op1at=IMMEDIATE; i02->op1 = 2; // 2 
    i02->oper = OP_NOOP;                // no operator

    i01->next = i02;

    instNode * i03 = new instNode();
    i03->lhsat=DIRECT; i03->lhs = 2;    // c
    i03->iType=ASSIGN_INST;	        // = 
    i03->op1at=IMMEDIATE; i03->op1 = 3; // 3 
    i03->oper = OP_NOOP;                // no operator

    i02->next = i03;


    instNode * i1 = new instNode();
    i1->lhsat=DIRECT; i1->lhs = 34; // t1
    i1->iType=ASSIGN_INST;	    // = 
    i1->op1at=DIRECT; i1->op1 = 0;  // a
    i1->oper = OP_PLUS;             // +
    i1->op2at=DIRECT; i1->op2 = 1;  // b

    i03->next = i1;

    instNode * i2 = new instNode();
    i2->lhsat=DIRECT; i2->lhs = 35; // t2
    i2->iType=ASSIGN_INST;	    // = 
    i2->op1at=DIRECT; i2->op1 = 1;  // b
    i2->oper = OP_PLUS;             // +
    i2->op2at=DIRECT; i2->op2 = 2;  // c


    i1->next = i2;

    instNode * i3 = new instNode();
    i3->lhsat=DIRECT; i3->lhs = 36; // t3
    i3->iType=ASSIGN_INST;	    // = 
    i3->op1at=DIRECT; i3->op1 = 34;  // t1 
    i3->oper = OP_MULT;             // *
    i3->op2at=DIRECT; i3->op2 = 35;  // t2 


    i2->next = i3;		    // i3 should be after i1 and i2

    instNode * i4 = new instNode();
    i4->lhsat=DIRECT; i4->lhs = 3;  // d
    i4->iType=ASSIGN_INST;	    // = 
    i4->op1at=DIRECT; i4->op1 = 36; // t3 
    i4->oper = OP_NOOP;             // no operator


    i3->next = i4;

    instNode * i5 = new instNode();
    i5->iType=OUTPUT_INST;	    // OUTPUT
    i5->op1at=DIRECT; i5->op1 = 3;  // d

    i4->next = i5;

    instNode * i6 = new instNode();
    i6->lhsat=DIRECT; i6->lhs = 37; // t4
    i6->iType=ASSIGN_INST;          // =
    i6->op1at=DIRECT; i6->op1 = 0;  // a
    i6->oper = OP_PLUS;             // +
    i6->op2at=DIRECT; i6->op2 = 1;  // b

    i5->next = i6;

    instNode * i7 = new instNode();
    i7->lhsat=DIRECT; i7->lhs = 38;    // t5
    i7->iType=ASSIGN_INST;             // =
    i7->op1at=IMMEDIATE; i7->op1 = 4;  // address of x = 4 available
                                       // at compile time
    i7->oper = OP_PLUS;                // +
    i7->op2at=DIRECT; i7->op2 = 37;    // t5 (contains value of a+b

    i6->next = i7;

    instNode * i8 = new instNode();
    i8->lhsat=INDIRECT; i8->lhs = 38;  // x[a+b]
    i8->iType=ASSIGN_INST;             // =
    i8->op1at=DIRECT; i8->op1 = 3;     // d
    i8->oper = OP_NOOP;

    i7->next = i8;

    instNode * i9 = new instNode();
    i9->lhsat=DIRECT; i9->lhs = 39;    // t6 will contain address of x[3]
    i9->iType=ASSIGN_INST;             // =
    i9->op1at=IMMEDIATE; i9->op1 = 4;  // address of x = 4 available
                                       // at compile time
    i9->oper = OP_PLUS;                // +
    i9->op2at=IMMEDIATE; i9->op2 = 3;  // 3

    i8->next = i9;

    instNode * i10 = new instNode();
    i10->iType=OUTPUT_INST;              // OUTPUT
    i10->op1at=INDIRECT; i10->op1 = 39;  // x[3] by providing its
                                         // address indirectly through
                                         // t6

    i9->next = i10;


    code = i01;

    execute_inst_list(code);
}

int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    

    switch (task) {
        case 1: Task1();
            break;

        case 2: Task2();
            break;

        case 3: Task3();
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}

