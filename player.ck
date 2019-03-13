ConsoleInput in;
StringTokenizer tok;
Step s => dac;

string x, v;
float vals[100001];
0 => int i;


for (0 => i ; i < 100001 ; i++) {
    in.prompt() => now;
       tok.set(in.getLine());
       tok.next() => x;
       tok.next() => v;
       Std.atof(x) => vals[i];
       i++;
}

//5::second => now;

<<< vals[100] >>>;

// while (true) {
//     for (0 => i ; i < 100001 ; i++) {
//         10.0 * vals[i] => s.next;
//         1::samp => now;
//     }
// }