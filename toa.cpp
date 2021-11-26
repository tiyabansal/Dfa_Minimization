/*-----PROBLEM STATEMENT-------*/

/* Q) Implement the state minimization algorithm in C/C++/Python/ Java. 
The program should take a finite automata 
M=(Q, Alphabet, Transition Table, Initial state, set of final states) 
as input. 

The output should give the minimum equivalence state partition 
and the corresponding minimum state transition table.*/

/*Following is written in C++*/
/*Submission by : Tiya Bansal- LIT2020027*/

#include <bits/stdc++.h>
using namespace std;

//OPTIMIZATION
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define rep0(i, k, n) for (int i = k; i < n; i++)
#define rep1(i, k, n) for (int i = k; i <= n; i++)
#define rep2(i, k, n) for (int i = k; i < n; i += 2)
#define rep3(i, k, n) for (int i = k; i > n; i--)

#define in1(t) \
    llint t;   \
    cin >> t;
#define in2(p, q) \
    llint p, q;   \
    cin >> p >> q
#define in3(p, q, r) \
    llint p, q, r;   \
    cin >> p >> q >> r
#define in4(p, q, r, s) \
    llint p, q, r, s;   \
    cin >> p >> q >> r >> s
#define in5(p, q, r, s, t) \
    llint p, q, r, s, t;   \
    cin >> p >> q >> r >> s >> t
#define in6(p, q, r, s, t, u) \
    llint p, q, r, s, t, u;   \
    cin >> p >> q >> r >> s >> t >> u
#define ins(s) \
    string s;  \
    cin >> s
#define arri(a) rep0(i, 0, n) cin >> a[i]
#define arro(a) rep0(i, 0, n) cout << a[i] << " "

#define db(x)                   \
    for (auto element : x)      \
        cout << element << " "; \
    lb;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pp pop_back
#define yaas cout << "YES" \
                  << "\n"
#define nope cout << "NO" \
                  << "\n"
#define lb cout << endl;
#define bye return 0;

typedef long long int llint;
typedef unsigned long long int ullint;
typedef long double ld;
typedef unsigned int uint;
typedef vector<llint> vecl;
typedef vector<vecl> vvec;
typedef vector<char> vecc;
typedef vector<bool> vecb;
typedef pair<llint, llint> pll;
typedef pair<llint, string> pls;
typedef map<llint, llint> mll;


/* --------CODE STARTS HERE---------- */
const int max_states = 50;

/* ADJACENCY LIST */
/*
**Made for dfs
**To find unreachable states
**If vis[state] = 0, it is unreachable
**Treat machine as graph and run dfs 
*/

vector<pair<int, char>> adj[max_states];

int vis[max_states];

int value[max_states][max_states];

map<pair<int, int>, vector<pair<int, int>>> dp;

void dfs(int root)
{
    vis[root] = 1;
    for (auto x : adj[root])
    {
        if (!vis[x.first])
        {
            dfs(x.first);
        }
    }
}

/*
** Backtracking
** Used to reduce the complexity of the problem to N^2
** When we find result for a pair, we mark all the other dependant pairs by backtracking
** This result shows that the pair is not possible (cannot be merged)
*/
void backtract(int state1, int state2)
{
    for (auto x : dp[{state1, state2}])
    {
        value[x.first][x.second] = -1;
        backtract(x.first, x.second);
    }
}


/* ----------DRIVER CODE---------- */
int main()
{
    cout << "\n\n\n";
    cout << "||--------STATE MINIMIZATION ALGORITHM--------||"
         << "\n";

    cout << "\n\n\n";

    cout << "Give input according to given instructions!";
    cout << "\n\n\n";

    int num; /* NUMBER OF STATES */
    cout << "Enter number of States - ";
    cin >> num;
    cout << "\n\n";

    int state[num];
    cout << "Enter states - ";

    for (int i = 0; i < num; i++)
    {
        cin >> state[i];
    }
    cout << "\n\n";

    int num_alphabet; /* NUMBER OF ALPHABETS */
    cout << "Enter number of Alphabets - ";
    cin >> num_alphabet;
    cout << "\n\n";

    /* Alphabets like a, b,.... or even 0,1,.... */
    char alphabet[num_alphabet];
    cout << "Enter alphabets - ";

    for (int i = 0; i < num_alphabet; i++)
    {
        cin >> alphabet[i];
    }
    cout << "\n\n";

    int start; /* STARTING STATE */
    cout << "Enter the Starting State - ";
    cin >> start;
    cout << "\n\n";

    int num_final; /* NUMBER OF FINAL STATES */
    cout << "Enter number of final states - ";
    cin >> num_final;
    cout << "\n\n";

    int final_state[num_final]; /* FINAL STATES */
    cout << "Enter final states - ";

    for (int i = 0; i < num_final; i++)
    {
        cin >> final_state[i];
    }
    cout << "\n\n";

    /* ----------TRANSITION TABLE----------- */

    int table[num][num_alphabet];
    cout << "Enter the Transition Table - ";

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            cin >> table[i][j];
        }
    }
    cout << "\n\n\n\n";

    /* Check for some UNREACHABLE NODE and
       Remove them because they can't be reached from STARTING STATE! */

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            adj[state[i]].push_back({table[i][j], alphabet[j]});
        }
    }

    for (int i = 0; i < num + 5; i++)
    {
        vis[i] = 0; /* Initially none are VISITED */
    }

    cout << "||--------INITIAL AUTOMATA ACC. TO USER INPUT--------||";
    cout << "\n\n";

    cout << "Number of states - " << num;
    cout << "\n\n";

    cout << "States - ";

    for (int i = 0; i < num; i++)
    {
        cout << state[i] << "    ";
    }
    cout << "\n\n";

    cout << "Number of Alphabets - " << num_alphabet;
    cout << "\n\n";

    cout << "Alphabets - ";

    for (int i = 0; i < num_alphabet; i++)
    {
        cout << alphabet[i] << "    ";
    }
    cout << "\n\n";

    cout << "Starting state - " << start;
    cout << "\n\n";

    cout << "Final state count - " << num_final;
    cout << "\n\n";

    cout << "Final states - ";

    for (int i = 0; i < num_final; i++)
    {
        cout << final_state[i] << "   ";
    }
    cout << "\n\n";

    cout << "Transitions - " << endl;
    cout << "\n";

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            cout << table[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "\n\n";

    /* Call DFS for Finding UNREACHABLE STATES */
    dfs(start);

    /* Now for those which are still UNREACHABLE
       (IF) vis[i] == 0, then they remain UNREACHABLE! */
    for (int i = 0; i < num; i++)
    {
        if (vis[state[i]] == 0)
        {
            state[i] = -1; /* DO NOT EXIST */
        }
    }

    for (int i = 0; i < num + 2; i++)
    {
        for (int j = 0; j < num + 2; j++)
        {
            value[i][j] = 0; /* "0" means they are not DISTINGUISHABLE */
        }
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state[i] == -1 || state[j] == -1)
            {
                continue; /* NON-REACHABLE STATES */
            }

            int is_first_final = 0;
            int is_second_final = 0;
            for (int k = 0; k < num_final; k++)
            {
                if (final_state[k] == state1)
                {
                    is_first_final = 1;
                }
                if (final_state[k] == state2)
                {
                    is_second_final = 1;
                }
            }

            if (is_first_final == 0 && is_second_final == 1)
            {
                value[state1][state2] = -1; /* It means they are now DISTINGUISHABLE/SEPARABLE/CANNOT BE MERGED */
            }
            else if (is_first_final == 1 && is_second_final == 0)
            {
                value[state1][state2] = -1;
            }
        }
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state[i] == -1 || state[j] == -1)
            {
                continue; /* NON-REACHABLE STATES */
            }

            if (value[state1][state2] == -1)
            {
                /* End bcoz of "-1" */
                continue;
            }
            else
            {

                for (int k = 0; k < num_alphabet; k++)
                {

                    /* state1 output on this input */
                    int output1 = table[i][k];

                    /* state2 output on this input */
                    int output2 = table[j][k];

                    if (output1 == output2)
                    {

                        continue;
                    }

                    if (output1 == state1 && output2 == state2)
                    {

                        continue;
                    }

                    if (output1 == state2 && output2 == state1)
                    {

                        continue;
                    }

                    if (output1 > output2)
                    {
                        swap(output1, output2);
                    }

                    /* Therefore, COMBINED STATE = {output1, output2}
                       where output1 < output2 */

                    if (value[output1][output2] == -1)
                    {
                        value[state1][state2] = -1;

                        /* If we are marking this as "-1"
                           Then, we have to backtrack
                           and mark others as "-1".
                           
                           They must be having some values stored
                           And, have backtrackked also! */

                        for (auto x : dp[{state1, state2}])
                        {
                            value[x.first][x.second] = -1;

                            backtract(x.first, x.second);
                        }

                        /* If "-1", then no need to check other Inputs */
                        break;
                    }
                    else
                    {
                        /* FOR BACKTRACKING PURPOSE
                           If Later we get "-1"
                           Then we'll put "-1" here as well! */

                        dp[{output1, output2}].push_back({state1, state2});
                    }
                }
            }
        }
    }

    int parent[num];

    for (int i = 0; i < num; i++)
    {
        parent[i] = state[i];
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state1 == -1 || state2 == -1)
            {
                continue;
            }

            if (value[state1][state2] == -1)
            {
                continue; // cannot merge them
            }
            else
            {
                /* Parent of State1 = "parent1" */
                /* Parent of State2 = "parent2" */
                int parent1 = parent[i];
                int parent2 = parent[j];

                /* Make parent1 equal to parent2  */

                for (int k = 0; k < num; k++)
                {
                    if (parent[k] == parent1)
                    {
                        parent[k] = parent2;
                    }
                }
            }
        }
    }

    cout << "||------------------FINAL AUTOMATA------------------||";
    cout << "\n\n";

    map<int, vector<int>> new_states;

    for (int i = 0; i < num; i++)
    {
        if (parent[i] != -1)
        {
            new_states[parent[i]].push_back(state[i]);
        }
    }

    int new_state_count = new_states.size();

    cout << "Number of new states - " << new_state_count;
    cout << "\n\n";

    cout << "Minimum Equivalence State Partition - ";
    cout << "\n\n";

    for (auto x : new_states)
    {
        cout << x.first << "  -->  ";
        for (auto y : x.second)
        {
            cout << y << " | ";
        }
        cout << endl;
    }

    map<int, int> isfinal; // IF FINAL -> 1   --- IF NOT FINAL -> 0

    for (auto x : new_states)
    {
        isfinal[x.first] = 0;
    }

    /* CHECKING IF FINAL OR NOT */
    for (auto x : new_states)
    {
        int check = 0;
        for (auto y : x.second)
        {
            /* CHECK IF "y" IS FINAL OR NOT */
            for (int i = 0; i < num_final; i++)
            {
                if (final_state[i] == y)
                {
                    check = 1;
                    break;
                }
            }
        }
        if (check)
        {
            isfinal[x.first] = 1;
        }
    }

    cout << "\n";
    cout << "New Final States - ";

    for (auto x : isfinal)
    {
        if (x.second == 1)
        {
            cout << x.first << " ";
        }
    }

    cout << "\n";

    int new_start;
    for (auto x : new_states)
    {
        for (auto y : x.second)
        {
            /* CHECK IF "y" IS FINAL OR NOT */
            if (y == start)
            {
                new_start = x.first;
                break;
            }
        }
    }

    cout << "New Starting State - " << new_start;
    cout << "\n\n";

    /* FINDING A TRANSITION TABLE! */
    map<int, vector<pair<char, int>>> final_adj;

    for (auto x : new_states)
    {
        /* char checker = (*(x.second.begin())) */
        int checker = x.first;

        int number_in_initial_state = -1;

        for (int i = 0; i < num; i++)
        {
            if (checker == state[i])
            {
                number_in_initial_state = i;
                break;
            }
        }

        for (int i = 0; i < num_alphabet; i++)
        {

            int going_to = table[number_in_initial_state][i];

            int state_of_going_to;
            for (auto k : new_states)
            {
                for (auto kk : k.second)
                {
                    if (going_to == kk)
                    {
                        state_of_going_to = k.first;
                        break;
                    }
                }
            }

            final_adj[checker].push_back({alphabet[i], state_of_going_to});
        }
    }

    cout << "Corresponding Minimum State Transition Table - ";
    cout << "\n\n";

    for (auto x : final_adj)
    {
        cout << x.first << "  -->  ";
        for (auto y : x.second)
        {
            cout << "(" << y.first << "  -  " << y.second << ") ";
        }
        cout << endl;
    }

    cout << "\n\n\n\n";
    return 0;
}

/*------------------CODE ENDS HERE---------------------*/
