#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int valid(int x, int bit, int half) {
    int lf = 0, ri;

    ri = 1 << bit;

    if(half) {
        ri /= 2;
        lf = -ri;
    }

    ri--;

    if(x >= lf && x <= ri) return 1;

    return 0;
}


int main() {

    freopen ( "00_input.txt", "r", stdin);
    freopen( "00_output.txt", "w", stdout );


    string s1,s2,s3,ar[102];
    int mapped[102],idx,x,tmp;

    map<string,string> am;
    am.clear();


    am["$zero"] = "0";
    am["$t0"] = "1";
    am["$t1"] = "2";
    am["$t2"] = "3";

    am["$t3"] = "4";
    am["$t4"] = "5";
    am["$s0"] = "6";
    am["$s1"] = "7";

    am["$s2"] = "8";
    am["$s3"] = "9";
    am["$s4"] = "A";
    am["$s5"] = "B";

    am["$s6"] = "C";
    am["$eqval"] = "D";
    am["$base"] = "E";
    am["$one"] = "F";



    am["add"] = "0";
    am["sub"] = "1";
    am["addi"] = "2";
    am["and"] = "3";

    am["or"] = "4";
    am["sll"] = "5";
    am["beq"] = "6";
    am["slt"] = "7";

    am["slt"] = "8";
    am["jump"] = "9";
    am["lw"] = "A";
    am["sw"] = "B";

    am["in"] = "C";
    am["out"] = "D";

    //cout << am["fasdf"] << "h" << endl;


    ar[1] = "add";
    ar[2] = "sub";
    ar[3] = "addi";

    ar[4] = "and";
    ar[5] = "or";
    ar[6] = "sll";

    ar[7] = "beq";
    ar[8] = "slt";
    ar[9] = "jump";

    ar[10] = "lw";
    ar[11] = "sw";

    ar[12] = "in";
    ar[13] = "out";

    for(int i = 1; i <= 13; i++) {
        mapped[i] = 0;
    }

    mapped[3] = 1;
    mapped[6] = 1;
    mapped[7] = 1;
    mapped[10] = 1;
    mapped[11] = 1;

    mapped[12] = 2;
    mapped[13] = 2;

    mapped[9] = 3;


    int pos = 0, flag[1002];
    memset(flag,0,sizeof(flag));

    pair<string,int> final[1002];
    string cmd[1002],ts;

    string ecmd = "There was an error in the instruction\n";
    int cflag = 0, y;

    while( cin >> s1 ) {

        ts = "";
        ++pos;
        cmd[pos] = am[s1];

        //cout << am[s1] << " ";

        idx = 0;

        for(int i = 1; i <= 13; i++) {
            if(s1 == ar[i]) {
                idx = i;
                break;
            }
        }

        if(!idx){
            cout << ecmd;
            return 0;
        }



        if(mapped[idx] == 0) { //two string
            cin >> s2 >> s3;

            tmp = s2.size();
            if(s2[tmp-1] != ',') cflag = 1;

            s2 = s2.substr(0, tmp-1 );

            //cout << am[s2] << " " << am[s3] << endl;

            if(am[s2] == "" || am[s3] == "") cflag = 1;

            flag[pos] = 0;
            final[pos].ff = am[s2] + " " + am[s3];
        }

        else if(mapped[idx] == 1) { //one string, one number
            cin >> s2 >> x;

            tmp = s2.size();
            if(s2[tmp-1] != ',') cflag = 1;

            s2 = s2.substr(0, tmp-1 );

            if(am[s2] == "") cflag = 1;

            if(s2 == "lw" || s2 == "sw") y = 0;
            else y = 1;

            if(!valid(x,4,y)) cflag = 1;

            //cout << am[s2] << " ";
            //printf("%X\n",x);

            flag[pos] = 1;
            final[pos].ff = am[s2];
            final[pos].ss = x;
        }

        else if(mapped[idx] == 2) { //io - 1 string
            cin >> s2;

            if(am[s2] == "") cflag = 1;

            //cout << am[s2] << " " << am[s3] << endl;

            flag[pos] = 0;
            final[pos].ff = am[s2];
        }

        else { //jump - one number
            cin >> x;

            if(!valid(x,8,1)) cflag = 1;

            //printf("%X\n",x);

            flag[pos] = 2;
            final[pos].ss = x;
        }


        if(cflag) {
            cout << ecmd;  return 0;
        }
    }


    for(int i = 1; i <= pos; i++) {

        cout << cmd[i] << " ";

        if(!flag[i]) {
            cout << final[i].ff << endl;
        }

        else if(flag[i] == 1) {
            cout << final[i].ff << " ";

            if(final[i].ss < 0) { printf("-"); final[i].ss = -final[i].ss; }
            printf("%X\n",final[i].ss);
        }

        else {

            if(final[i].ss < 0) { printf("-"); final[i].ss = -final[i].ss; }
            printf("%X\n",final[i].ss);
        }
    }


    return 0;
}
