#include <iostream>
#include <stack>

using namespace std;

struct FCall
{
    int n;                        // the function parameter.
    int result = 0;               // hold the return value of the function.
    int a = 0, b = 0, d = 0;      // local variable of the function that will be used.
    string name;                  // hold the recursive call name to distinguish the recurse call from a or b or d.
    int stage = 0;                // stage equals zero means the first call (not recurse yet) and will be need to resume the function.
                                  // the stage needed since there is processes needed to be done after recursive call.
};

int FIterative(int n)
{
    int R = 0;    //storing the return value.

    FCall fcall; //for the first call to the function.
    fcall.n = n;

    stack <FCall> s;
    s.push(fcall);

    FCall c1;   //for the recursive call in equation a.
    FCall c2;   //for the recursive call in equation b.
    FCall c3;   //for the recursive call in equation d.

    while (!s.empty())
    {
        FCall call = s.top();
        s.pop();

        if (call.stage == 0)   // first call to the function
        {
            if (call.n <= 1)  // base case
            {
                // store 1 in the right result variable for each recursive call.
                if (call.name == "c3")
                    c3.result = 1;

                else if (call.name == "c2")
                    c2.result = 1;

                else if (call.name == "c1")
                    c1.result = 1;

                else
                {
                    call.result = 1;
                    R = 1;
                }
            }
            else
            {
                call.stage = 1;             // to resume the call since stage 1 is for equation a.
                s.push(call);

                // for recurse of equation a.
                c1.n = call.n - 1;
                c1.name = "c1";
                s.push(c1);
            }
        }

        else if (call.stage == 1)
        {
            call.stage = 2;                 // to resume the call since stage 2 is for equation b.
            call.a = call.n + c1.result;    // calculate the equation a.
            call.result = call.a;           // store the result of equation a to the total result.
            s.push(call);

            // for recurse of equation b.
            c2.n = call.n / 2;
            c2.name = "c2";
            s.push(c2);
        }

        else if (call.stage == 2)
        {
            call.stage = 3;                // to resume the call since stage 3 is for equation d.
            call.b = call.n * c2.result;   // calculate the equation b.
            call.result += call.b;         // add the result of equation b to the total result.
            s.push(call);

            // calculate the equation c.
            int c = call.n - 2 - ((call.a + call.b) % 2);

            // for recurse of equation d.
            c3.n = c;
            c3.name = "c3";
            s.push(c3);

        }

        else if (call.stage == 3)
        {
            call.stage = -1;              // to end the call since stage -1 means we reach the end of the function call.
            call.d = c3.result;           // store the result of the recursive f(c) in the equation d.
            call.result += call.d;        // add the result of equation d to the total result.
            s.push(call);

            // get the right result value for each recursive call and store it in its result variable.
            if (call.name == "c1")
                c1.result = call.result;

            else if (call.name == "c2")
                c2.result = call.result;

            else if (call.name == "c3")
                c3.result = call.result;

            R  = call.result;            // store the result in the return variable.
        }


    }

    return R;
}

int main()
{
    int result;

    result = FIterative(0);
    cout << "if n = 0  , the result of the function will be " << result << endl;

    result = FIterative(1);
    cout << "if n = 1  , the result of the function will be " << result << endl;

    result = FIterative(2);
    cout << "if n = 2  , the result of the function will be " << result << endl;

    result = FIterative(3);
    cout << "if n = 3  , the result of the function will be " << result << endl;

    result = FIterative(4);
    cout << "if n = 4  , the result of the function will be " << result << endl;

    result = FIterative(5);
    cout << "if n = 5  , the result of the function will be " << result << endl;

    result = FIterative(6);
    cout << "if n = 6  , the result of the function will be " << result << endl;

    result = FIterative(7);
    cout << "if n = 7  , the result of the function will be " << result << endl;

    result = FIterative(8);
    cout << "if n = 8  , the result of the function will be " << result << endl;

    result = FIterative(9);
    cout << "if n = 9  , the result of the function will be " << result << endl;

    result = FIterative(10);
    cout << "if n = 10 , the result of the function will be " << result << endl;

    result = FIterative(11);
    cout << "if n = 11 , the result of the function will be " << result << endl;

    result = FIterative(12);
    cout << "if n = 12 , the result of the function will be " << result << endl;

    result = FIterative(13);
    cout << "if n = 13 , the result of the function will be " << result << endl;

    result = FIterative(14);
    cout << "if n = 14 , the result of the function will be " << result << endl;

    result = FIterative(15);
    cout << "if n = 15 , the result of the function will be " << result << endl;

    result = FIterative(16);
    cout << "if n = 16 , the result of the function will be " << result << endl;

    result = FIterative(17);
    cout << "if n = 17 , the result of the function will be " << result << endl;

    result = FIterative(18);
    cout << "if n = 18 , the result of the function will be " << result << endl;

    result = FIterative(19);
    cout << "if n = 19 , the result of the function will be " << result << endl;

    result = FIterative(20);
    cout << "if n = 20 , the result of the function will be " << result << endl;

    result = FIterative(21);
    cout << "if n = 21 , the result of the function will be " << result << endl;

    result = FIterative(22);
    cout << "if n = 22 , the result of the function will be " << result << endl;

    result = FIterative(23);
    cout << "if n = 23 , the result of the function will be " << result << endl;

    result = FIterative(24);
    cout << "if n = 24 , the result of the function will be " << result << endl;

    result = FIterative(25);
    cout << "if n = 25 , the result of the function will be " << result << endl;

}
