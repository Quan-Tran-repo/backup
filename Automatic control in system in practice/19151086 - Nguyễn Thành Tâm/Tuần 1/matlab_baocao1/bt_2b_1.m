clc
G1=tf(5,1);
G2=tf(1, [1 1] );
G3=tf([1 0], 1);
G4=G2;
G5=G3;
G6=tf([1 2],1);
G10=tf(1,1);
G7=tf(1,1);
G8=tf([0 1 ],[1 0 ] );
G9=tf( [0 3 ], [4 1 ]);
T1=append(G1,G2,G3,G4,G5,G6,G7,G8,G9,G10);
Q= [1  10 -7 
    2  1  -8 
    3  2  0  
    4  3  -9 
    5  4  6  
    6  2  0  
    7  5  0  
    8  5  0  
    9  5  0   ];
input=10;
output=5;
Ts=connect(T1,Q,input,output);
Tf=tf(Ts)
