#include <iostream>
#include <cmath>

using namespace std;

struct positions
{
    int x , nx , y , ny ;  /// x and y are the location of the piece and nx and ny are the new_x and new_y where the players wants to move his piece to .
};





bool poscheck( positions p , int rp[][6] )
{
    if( (rp[p.x][p.y] == 1 || rp[p.x][p.y] == 2  ))
    {

        /*
        if(   rp[p.x+1][p.y+1] != 1    ||   rp[p.x+1][p.y+1] != 2    ||    rp[p.x-1][p.y-1] != 1   ||   rp[p.x-1][p.y-1] != 2 ||
                 rp[p.x+1][p.y-1] != 1    ||    rp[p.x+1][p.y-1] != 2     ||      rp[p.x-1][p.y+1] != 1   ||   rp[p.x-1][p.y+1] != 2       )
        {
                return true;
        }else*/

        return true;
    }



}


bool newposcheck(  positions p , int cp[][6], int op[][6] )
{
    if((( 1==abs(p.x-p.nx) && 1==abs(p.y-p.ny))||
       ( 2==abs(p.x-p.nx) && 2==abs(p.y-p.ny)))&&
        ( (op[p.nx][p.ny] !=1 && op[p.nx][p.ny] != 2 ) &&
          (cp[p.nx][p.ny] !=1 && cp[p.nx][p.ny] != 2  ) ) )
          {
              return true;
          }else
          return false;

}


bool jumpcheck(positions p , int cp[][6] , int op[][6],int&score)  /// cp[][] is current_player  and op[][] is opponent_player
{
    bool check;

    if( (2==p.nx-p.x && 2 == p.ny-p.y) && cp[p.x][p.y] == op[p.x+1][p.y+1] )
    {
        op[p.x+1][p.y+1]=0;
        swap ( cp[p.nx][p.ny] , cp[p.x][p.y]  );
        score++;
        return true;

    }else if( ( 2==p.x-p.nx && 2 ==p.y-p.ny ) && cp[p.x][p.y] == op[p.x-1][p.y-1]  )
    {
        op[p.x-1][p.y-1]=0;
        swap ( cp[p.nx][p.ny] , cp[p.x][p.y]  );
        score++;
        return true;
    }else if( ( 2==p.nx-p.x && 2==p.y-p.ny) && cp[p.x][p.y] == op[p.x+1][p.y-1]  )
    {
        op[p.x+1][p.y-1]=0;
        swap ( cp[p.nx][p.ny] , cp[p.x][p.y]  );
        score++;
        return true;
    }else if( ( 2==p.x-p.nx && 2==p.ny-p.y ) && cp[p.x][p.y] == op[p.x-1][p.y+1]  )
    {
        op[p.x-1][p.y+1]=0;
        swap ( cp[p.nx][p.ny] , cp[p.x][p.y]  );
        score++;
        return true;
    }else
    {
        cout<< " INVALIED JUMP\n\n";
        return false;
    }


}




// check if a certain position on the board is occupied by a red or black piece
string checkPos(int x, int y, int red[][6], int black[][6])
{
    string str = "";
    if(red[x][y] != 0)
        if(red[x][y] == 1)
            str = "r1";
        else
            str = "r2";
    else if(black[x][y] != 0)
        if(black[x][y] == 1)
            str = "b1";
        else
            str = "b2";
    else
        str = "  ";

    return str;
}

//print board according to red and black arrays indicating positions on the board
void printBoard(int red[][6], int black[][6])
{
    cout << "\n";
    cout << "   ____ ____ ____ ____ ____ ____ " << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "5 | " << checkPos(0, 5, red, black) << " |    | " << checkPos(2, 5, red, black) << " |    | " << checkPos(4, 5, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "4 |    | " << checkPos(1, 4, red, black) << " |    | " << checkPos(3, 4, red, black) << " |    | " << checkPos(5, 4, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "3 | " << checkPos(0, 3, red, black) << " |    | " << checkPos(2, 3, red, black) << " |    | " << checkPos(4, 3, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "2 |    | " << checkPos(1, 2, red, black) << " |    | " << checkPos(3, 2, red, black) << " |    | " << checkPos(5, 2, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "1 | " << checkPos(0, 1, red, black) << " |    | " << checkPos(2, 1, red, black) << " |    | " << checkPos(4, 1, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "0 |    | " << checkPos(1, 0, red, black) << " |    | " << checkPos(3, 0, red, black) << " |    | " << checkPos(5, 0, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "    0    1    2    3    4    5   \n" << endl;
}

void initializePieces(int red[][6], int black[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            red[i][j] = 0;
            black[i][j] = 0;
        }
    red[0][1] = 1;
    red[1][0] = 2;
    red[2][1] = 1;
    red[3][0] = 2;
    red[4][1] = 1;
    red[5][0] = 2;

    black[0][5] = 2;
    black[1][4] = 1;
    black[2][5] = 2;
    black[3][4] = 1;
    black[4][5] = 2;
    black[5][4] = 1;

}




void playGame(int red[][6], int black[][6], int &redPoints, int &blackPoints)
{
    positions redp , blackp ;

    do
    {

    bool redflag=false , blackflag=false ;
    cout << "\n\n   ====== score=====\n"<<
            "    RED   : " << redPoints <<
            "\n    BLACK : " << blackPoints << "\n\n" ;

    cout << "\n\n \t\t RED TURN \n" ;

    ///piece select
    cout << " enter the position of piece u want to move ( x y ) : ";
    cin >> redp.x >> redp.y;
    do
    {
        if( poscheck( redp , red ))
        {
            //cout << "valid \n";
            break;
        }else
        {
            cout << " invalid input \n";
            cout << " enter the position of piece u want to move ( x y ) : ";  /// piece select
            cin >> redp.x >> redp.y;

        }



    }while(1);

    /// move position
    cout << " enter the the position u want to move ( x y )  to OR < -1 -1> to pass : ";
    cin >> redp.nx >> redp.ny ;

    do
    {
        if(redp.nx==-1 && redp.ny==-1)
                break;
        if (newposcheck( redp , red , black  ))
        {
            //cout<< " valid move position\n" ;
            if( 2 == abs(redp.x - redp.nx) && 2==abs(redp.y - redp.ny) )
            {
                if ( jumpcheck( redp , red , black, redPoints))
                {
                    printBoard(red, black);
                    break;
                }else
                redflag=false;

            }else
            {
                swap ( red[redp.nx][redp.ny] , red[redp.x][redp.y]  );
                printBoard(red, black);
                break;
            }



        }else
        {
            cout << " invalid\n";
        }
        if(!redflag)
        {
            cout << " enter the position u want to move to ( x y ) : ";  /// move position
            cin >> redp.nx >> redp.ny ;
        }
    }while(1);



    cout << "\n\n   ====== score=====\n"<<
            "    RED   : " << redPoints <<
            "\n    BLACK : " << blackPoints << "\n\n" ;


            if(redPoints>=3)
               {
                   cout << "\n\n *******  RED WON *******\n\n";
                   break;
               }


    cout << "\n\n \t\t BLACK TURN \n" ;

    /// piece select
    cout << " enter the position of piece u want to move ( x y ) : ";
    cin >> blackp.x >> blackp.y;


    do
    {
        if( poscheck( blackp , black ))
        {
            cout << "valid \n";
            break;
        }else
        {
            cout << " invalid input \n";
            cout << " the the position of piece u want to move ( x y ) : ";  /// piece select
            cin >> blackp.x >> blackp.y;

        }



    }while(1);


    /// move position
    cout << " enter the position u want to move to ( x y ) OR < -1 -1> to pass : ";
    cin >> blackp.nx >> blackp.ny ;

    do
    {
        if( blackp.nx==-1 && blackp.ny == -1 )
                break;
        if (newposcheck( blackp , black , red  ))
        {

            //cout<< " valid move position\n" ;
            if( 2==abs(blackp.x - blackp.nx) && 2==abs(blackp.y - blackp.ny))
            {
                 if ( jumpcheck( blackp , black , red, blackPoints))
                {
                    printBoard(red, black);
                    break;
                }else
                blackflag=false;
            }else
            {

            //cout<< " valid move position\n" ;

            swap ( black[blackp.nx][blackp.ny] , black[blackp.x][blackp.y]  );
            printBoard(red, black);
            break ;
            }



        }else
        {
            cout << " invalid\n";
        }

        if(!blackflag)
        {
            cout << " enter the position u want to move (x y ) to OR < -1 -1> to pass : "; /// move position
            cin >> blackp.nx >> blackp.ny ;
        }

    }while(1);



                if(blackPoints>=3)
               {
                   cout << "\n\n *******  BLACK WON *******\n\n";
                   break;
               }

    }while( 1 );





    /**

    * loop :( red player input , check valid move , print || black player input , check valid move , print)

        ** loop ( until red or black scores 3 points )\
        {

        *** red player input : position of piece he wants to move
            **** print message to ask for input and provide the formate
            **** take input

            *** check if the position in valid
                **** if the given position is not valid pop a error message and ask for valid input

        *** red player input : position he wants to move the piece to
            **** print message to ask for input and provide the formate
            **** take input
            **** check for the presence of the red piece in the give position
                ***** check for the red array[x][y] == 1 0r 2 &&!=0
                ***** check it the piece has valid positions to move
                if not print a error msg



            *** check if the position is valid to move the piece
                **** if the given position is not valid pop a error message and ask for valid input
                    ***** position x

        *** print the board



        *** black player input : position of piece he wants to move
            **** print message to ask for input and provide the formate
            **** take input
            **** print message to ask for input and provide the formate
            **** take input
            **** check for the presence of the red piece in the give position
                ***** check for the array[x][y] == 1 0r 2
                ***** check it the piece has valid positions to move
                if not print a error msg


            *** check if the position in valid
                **** if the given position is not valid pop a error message and ask for valid input

        *** black player input : position he wants to move the piece to
            **** print message to ask for input and provide the formate
            **** take input

            *** check if the position is valid to move the piece
                **** if the given position is not valid pop a error message and ask for valid input

        *** print the board


    */
}

int main()
{
    int red[6][6];
    int black[6][6];
    int redPoints = 0;
    int blackPoints = 0;
    initializePieces(red, black);
    printBoard(red, black);
    playGame(red, black, redPoints, blackPoints);
    return 0;
}
