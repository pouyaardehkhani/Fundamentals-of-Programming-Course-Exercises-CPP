#include<iostream>
////Header that defines the standard input/output stream objects
#include<sstream>
////Header providing string stream classes
#include<string>
////This header introduces string types, character traits and a set of converting functions
#include<vector>
////Vectors are sequence containers representing arrays that can change in size
#include<cstdlib>
////This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include<cstdio>
////Input and Output operations can also be performed in C++ using the C Standard Input and Output Library
#include<stdexcept>
////This header defines a set of standard exceptions that both the library and programs can use to report common errors.
#include<regex>
////Regular expressions are a standardized way to express patterns to be matched against sequences of characters.


const int MINIMAX_DEPTH = 5; // depth of the game tree search


//// a node which will be part of the game tree, main pieces of info include: state (board configuration) & associated value
struct Node
{
    Node ** children;
    int child_count;
    std::vector<std::vector<int>> move_list;
    char state[8][8];
    int val;
};


void change (char (&board)[8][8], int row, int col, char player1);
bool is_it_changeable (char board[8][8], int row, int col, char player1);
std::vector<std::vector<int>> calculate_legal_moves (char board[8][8], char player);
std::vector<std::vector<int>> get_black_legal_moves(char board[8][8]);
std::vector<std::vector<int>> get_white_legal_moves(char board[8][8]);
bool is_the_game_over (char board[8][8]);
void make_a_move (char (&board)[8][8], int row, int col, char player);
bool is_it_a_legal_move (char board[8][8], std::vector<std::vector<int>> move_list, int row, int col, char player);
void print_the_legal_moves (char board[8][8], char player);
void print_the_Legal_Moves (std::vector<std::vector<int>> move_list);
std::ostream& operator << (std::ostream& os, const char board[8][8]);
int get_the_Score (char board[8][8], char player);
void print_the_Winner (char (&board)[8][8]);
int heuristic(char board[8][8]);
int minimax(Node *position, int depth, bool maximizing_player);



//// method used to initialize a game tree (called everytime the AI has a turn)
Node * CreateTree(char board[8][8], int depth, char player)
{
    Node * node = new Node();
    // get the appropriate list moves
    node->move_list = (player == 'w') ? get_white_legal_moves(board) : get_black_legal_moves(board);
    // keep a count of children for indexes later on
    node->child_count = node->move_list.size();
    // copy the passed in board state to the state of the current node
    std::memcpy(node->state, board, 8 * 8 * sizeof(char));
    //std::memcpy : Copy block of memory
    //Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.

    // determine other player's character
    char other_player = (player == 'w') ? 'b' : 'w';
    // only create children if we're not too deep and this node should have children
    if (depth > 0 && node->child_count > 0) {
        // create an array of nodes as the children of the current node
        node->children = new Node * [node->child_count];
        // cycle through the children and create nodes for them
        for (int i = 0; i < node->child_count; ++i){
            char tmp_board[8][8];
            std::memcpy(tmp_board, board, 8 * 8 * sizeof(char));
            // must make the associating move first so a subtree of 'that' board configuration can be created
            make_a_move (tmp_board, node->move_list[i][0], node->move_list[i][1], player);
            // turn the child into a tree itself
            node->children[i] = CreateTree(tmp_board, depth - 1, other_player);
        }
    } else {
        node->children = NULL;
    }
    return node;
}


int main() {
    while (true) {
        //simple interface for the menu
        system("cls");
        //-------------- Initializing the Game Board --------------
        char board[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = '-';
            }
        }
        board[3][3] = 'w';
        board[3][4] = 'b';
        board[4][3] = 'b';
        board[4][4] = 'w';
        //---------------------------------------------------------
        int total_moves = 0;//for counting total moves and more
        char player = 'b'; // black always goes first (its the games rule)
        std::regex move_input_pattern("[0-7] [0-7]"); // regex for row/col input
        int num;
        std::cout << "---------------------------welcome to othello board game--------------------------- \n";
        std::cout << "1: H2H 2: VS CPU  3: rules 4: tips and strategy 5: about 6:exit.\n enter a num: ";
        lbl_switch:
        std::cin >> num;
        //menu commands
        switch (num) {
            case 1: {
                std::cin.ignore();
                while (!is_the_game_over(board)) {

                    std::vector<std::vector<int>> move_list = calculate_legal_moves(board, player);

                    std::cout << ((player == 'w') ? "White's Movelist: " : "Black's Movelist: \n");
                    print_the_Legal_Moves(move_list);
                    std::cout << board; // Show board

                    if (player == 'b' && get_black_legal_moves(board).size() == 0) {
                        player = 'w';
                        continue;
                    }

                    if (player == 'w' && get_white_legal_moves(board).size() == 0) {
                        player = 'b';
                        continue;
                    }

                    // Print input prompt
                    std::cout << ((player == 'w') ? "White's Move: " : "Black's Move: ");

                    std::string user_input;
                    std::getline(std::cin, user_input);

                    if (!std::regex_match(user_input, move_input_pattern)) {
                        std::cout
                                << "\nInvalid input: Moves are inputted as '<row #> <column #>' with numbers [1-8].\n";
                        std::cout << "e.g. If you want to place your piece at row #1, column #2 input '1 2'.\n\n";
                        continue;
                    }

                    // user_input = [<some num>, " ", <some num>], nums will be at indices 0 and 2
                    // subtract '0's ascii value (48) from the user nums to get the real integer
                    int row = user_input[0] - '0';
                    int col = user_input[2] - '0';

                    try {
                        if (is_it_a_legal_move(board, move_list, row, col, player)) {
                            make_a_move(board, row, col, player);
                        } else {
                            std::cout << "Illegal move! Try again.\n";
                            continue;
                        }
                    } catch (std::range_error &e) {
                        std::cout << e.what()
                                  << " - attempted access to element outside of game board, modification after initial input";
                        return 1;
                    }

                    total_moves += 1;
                    int white_total = get_the_Score(board, 'w');
                    int black_total = get_the_Score(board, 'b');

                    std::cout << "Black total: " << black_total << '\n';
                    std::cout << "White total: " << white_total << "\n\n";

                    // Switch players
                    player = (player == 'w') ? 'b' : 'w';
                }
                std::cout << board; // Show final board
                print_the_Winner(board);
                break;
            }
            case 2: {
                std::cin.ignore();
                std::regex player_selection_pattern("w|b"); // regex for w/b player selection
                std::cout << "Enter 'b' to play as black or 'w' to play as white: ";
                std::string selected_player;
                // loop until user makes a valid choice of player
                while (true) {
                    getline(std::cin, selected_player);
                    if (!std::regex_match(selected_player, player_selection_pattern)) {
                        std::cout << "\nInvalid input: \"Enter 'b' to be black or 'w' to be white. \n";
                        continue;
                    }
                    break;
                }

                char player_char = selected_player[0];
                std::cout << "You have chosen to play as " << ((player_char == 'w') ? "white" : "black") << "!\n\n";

                // set AI as the opposite of what the player chose
                char ai_char = ((player_char == 'w') ? 'b' : 'w');

                // main game loop
                while (!is_the_game_over(board)) {
                    // calculate the move list of the current player
                    std::vector<std::vector<int>> move_list = calculate_legal_moves(board, player);

                    //------------------ TURN PASS CONDITIONS ----------------------
                    if (player == 'b' && get_black_legal_moves(board).empty()) {
                        player = 'w';
                        continue;
                    }

                    if (player == 'w' && get_white_legal_moves(board).empty()) {
                        player = 'b';
                        continue;
                    }
                    //----------------------------------------------------------------

                    int white_total = get_the_Score(board, 'w');
                    int black_total = get_the_Score(board, 'b');

                    std::cout << "Black total: " << black_total << '\n';
                    std::cout << "White total: " << white_total << '\n';

                    std::cout << board; // show board
                    std::cout << '\n';
                    if (player == player_char) {
                        print_the_legal_moves(board, player_char); // show possible moves

                        std::string user_input;
                        // loop until user provides a legal move in the correct row/col format
                        while (true) {
                            // Print input prompt
                            std::cout << ((player == 'w') ? "Your move (w): " : "Your move (b): ");
                            std::getline(std::cin, user_input);

                            if (!std::regex_match(user_input, move_input_pattern)) {
                                std::cout
                                        << "\nInvalid input: Moves are inputted as '<row #> <column #>' with numbers [0-7].\n";
                                std::cout
                                        << "e.g. If you want to place your piece at row #1, column #2 input '1 2'.\n\n";
                                continue;
                            } else {
                                // user_input = [<some num>, " ", <some num>], nums will be at indices 0 and 2
                                // subtract '0's ascii value (48) from the user nums to get the real integer
                                int row = user_input[0] - '0';
                                int col = user_input[2] - '0';

                                try {
                                    // if the inserted move is legal, make the move
                                    if (is_it_a_legal_move(board, move_list, row, col, player)) {
                                        make_a_move(board, row, col, player);
                                    } else {
                                        std::cout << "Illegal move! Try again.\n";
                                        continue;
                                    }
                                } catch (std::range_error &e) {
                                    std::cout << e.what()
                                              << " - attempted access to element outside of game board, modification after initial input";
                                    return 1;
                                }
                                break;
                            }

                        }
                        // user has finished turn

                    } else { // AI turn
                        auto gametree = CreateTree(board, MINIMAX_DEPTH,player); // game tree representing MINIMAX_DEPTH decisions
                        bool maximizer = (player == 'b') ? true : false;

                        // find optimal value
                        int optimial_val = minimax(gametree, MINIMAX_DEPTH, maximizer);
                        // loop through children of root node to find the node with the optimal value
                        for (int i = 0; i < gametree->child_count; ++i) {
                            if (gametree->children[i]->val == optimial_val) {
                                bool same_config = true;
                                for (int j = 0; j < 7; ++j) {
                                    for (int k = 0; k < 7; ++k) {
                                        if (gametree->children[i]->state[j][k] != board[j][k])
                                            same_config = false;
                                    }
                                }
                                // copy this optimial choice of node's state into the main game board
                                if (!same_config)
                                    std::memcpy(board, gametree->children[i]->state, 8 * 8 * sizeof(char));
                                else { // if no good move for ai, just pick the first move from the legal move list
                                    make_a_move(board, move_list[0][0], move_list[0][1], player);
                                }
                                break;
                            }
                        }
                    }

                    total_moves += 1;

                    // Switch players
                    player = (player == 'w') ? 'b' : 'w';

                }
                std::cout << board; // Show final board
                print_the_Winner(board);
                break;
            }
            case 3: {
                //rules of the game
                std::cout << "\n Rules: \n";
                std::cout
                        << "Player's toss a coin to decide who will play first (but originally black starts). Each turn,the player places one piece on the board with their colour facing up.\n";
                std::cout
                        << "For the first four moves, the players must play to one of the four squares in the middle of the board and no pieces are captured or reversed.\n";
                std::cout
                        << "Each piece played must be laid adjacent to an opponent's piece so that the opponent's piece or a row of opponent's      pieces is flanked by the new piece and another piece of the player's colour. All of the opponent's pieces between these two\n pieces are 'captured' and turned over to match the player's colour.\n";
                std::cout
                        << "It can happen that a piece is played so that pieces or rows of pieces in more than one direction are trapped between the new piece played and other pieces of the same colour. In this case, all the pieces in all viable directions are turned over.\n";
                std::cout
                        << "The game is over when neither player has a legal move (i.e. a move that captures at least one opposing piece) or when\n the board is full.\n \n";
                std::cout << "enter correct option number\n";
                goto lbl_switch;
            }
            case 4: {
                // new options for the strategies
                std::cout << "\n";
                std::cout << "1: Corners and stable discs\n";
                std::cout << "2: Danger squares\n";
                std::cout << "3: Mobility\n";
                std::cout << "4: exit to menu\n \n";
                int number1;
                std::cout << "enter a number: ";
                lbl_switch1:
                std::cin >> number1;
                //strategies menu
                switch (number1) {
                    case 1:
                        std::cout << "\n Corners and stable discs: \n";
                        std::cout
                                << "According to the rules of Othello,once a disc is placed in a corner,that disc can never be flipped back (it is \"stable\"). Because of that,corners are the most valuable squares on the board. Once you have a corner,you can often build more   adjacent stable discs around it.\n \n";
                        std::cout << "enter correct option number\n";
                        goto lbl_switch1;
                    case 2:
                        std::cout << "\n Danger squares: \n";
                        std::cout
                                << "Within the Othello board there are squares that are safer than others. When starting a game, it is recommended to play  within the 4x4 central area when possible. It is often not recommended to move on the squares next to corners . Moving  in these squares could give the opponent access to the adjacent corner.\n \n";
                        std::cout << "enter correct option number\n";
                        goto lbl_switch1;
                    case 3:
                        std::cout << "\n Mobility: \n";
                        std::cout
                                << "A common beginner mistake is to try to get as many discs as possible from the beginning. This is not a good strategy in Othello. A better strategy is to focus on limiting your opponent's options, while having many possible moves yourself.  This is usually easier to achieve by having fewer discs.\n \n";
                        std::cout << "enter correct option number\n";
                        goto lbl_switch1;
                    case 4:
                        // make sure we send it back to menu
                        std::cout << "enter correct option number\n";
                        goto lbl_switch;
                    default:
                        std::cout << "enter correct option number\n";
                        goto lbl_switch1;
                }
                break;
            }
            case 5: {
                //just introducing myself
                std::cout << "Programmed by Pouya Ardehkhani - 2021\n University of Tehran";
                std::cout << "enter correct option number\n";
                goto lbl_switch;
            }
            case 6: {
                goto lbl_exit;
            }
            default:
                //make sure it will go back to the menu
                std::cout << "enter correct option number\n";
                goto lbl_switch;
        }
    }
    lbl_exit:
    system("pause");
}

//// change appropriate pieces after a disc is placed down (called after verifying the move is_it_changeable)
void change (char (&board)[8][8], int row, int col, char player1){
    // declare a list of positions of discs that will be change
    // e.g. {{0,1}, {0,2}} means disc at location board[0][1] & board[0][2] will be change
    std::vector<std::vector<int>> discs_to_change;
    char player2 = (player1 == 'b') ? 'w' : 'b';
    // Check all 8 surround positions by a 2d array and write array element's value
    int surrounding_position_of_a_disc [8][2]={{-1, -1}, {-1, 0}, {-1, 1}, // 3 positions above
                                               {0, -1}, {0, 1}, // 2 positions on same row
                                               {1, -1}, {1, 0}, {1, 1}}; // 3 positions below
    for(auto deltas :surrounding_position_of_a_disc){
        // save what row/col currently on
        int curr_row = row + deltas[0];
        int curr_col = col + deltas[1];
        // ignore if this goes off of the board
        if (curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
            continue;
        // save character in this position
        char char_in_pos = board[curr_row][curr_col];
        // use this variable to save whether or not a line of pieces should be changed
        bool change_this_direction = false;
        // if the character in this delta position is the opponent's piece...
        if (char_in_pos == player2) {
            // continue in this delta position until the next character is no longer the opponent's or you go off the board
            while (char_in_pos == player2) {
                curr_row += deltas[0];
                curr_col += deltas[1];

                // check to see if new position is off board
                if (curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
                    break;

                // save the character
                char_in_pos = board[curr_row][curr_col];
            }
            // if the player1's piece is found after traveling over the opponent's piece(s), we know that will be change
            if (char_in_pos == player1)
                change_this_direction = true;
            // if we found out we should be changed...
            if (change_this_direction){
                // save current position
                curr_row = row + deltas[0];
                curr_col = col + deltas[1];
                char_in_pos = board[curr_row][curr_col];
                // travel over the opponent's pieces, while saving the positions to the big list to be change later
                while (char_in_pos == player2) {
                    //std::cout << "flipping [" << curr_row << ", " << curr_col << "]\n";
                    std::vector<int> disc = {curr_row, curr_col};
                    discs_to_change.push_back(disc);
                    curr_row += deltas[0];
                    curr_col += deltas[1];
                    // save next character
                    char_in_pos = board[curr_row][curr_col];
                }
            }
        }
    }
    // after we've collecting the row/col of all discs to changed, change them to the current player1's color/character
    for (auto pos : discs_to_change)
        board[pos[0]][pos[1]] = player1;
}

//// a move "is_it_changeable" if it causes pieces to change
bool is_it_changeable (char board[8][8], int row, int col, char player1){
    char player2 = (player1=='b')?'w':'b';
    // Check all 8 surround positions by a 2d array and write array element's value
    int surrounding_position_of_a_disc [8][2]={{-1, -1}, {-1, 0}, {-1, 1}, // 3 positions above
                                               {0, -1}, {0, 1}, // 2 positions on same row
                                               {1, -1}, {1, 0}, {1, 1}}; // 3 positions below
    // for every position(deltas) of the surrounding positions
    for(auto deltas :surrounding_position_of_a_disc){
        // skip if the position is off of game board because we dont want it
        if(row+deltas[0] > 7 || row+deltas[0] < 0 || col+deltas[1] > 7 || col+deltas[1] < 0){
            continue;
        }
        char char_in_pos = board[row+deltas[0]][col+deltas[1]]; // grab the character in that spot
        // if the character in this position spot is the opponent's piece...
        if(char_in_pos == player2) {
            // save spot's row and col #
            int curr_row = row + deltas[0];
            int curr_col = col + deltas[1];
            //continue along this delta(position) trajectory until you stop seeing the opponent's pieces
            while(char_in_pos == player2){
                curr_row += deltas[0];
                curr_col += deltas[1];
                // check to see if new position is off board or we will have an error
                if(curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_row < 0)
                    break;
                // save the next character
                char_in_pos = board[curr_row][curr_col];
            }
            // if the player's piece is seen after one (+more) of the opponent's pieces, the original move is a changeable one
            if(char_in_pos == player1)
                return true;
        }
    }
    // if no changeable spot is found after checking all surrounding positions, the original move is not a changeable one
    return false;
}

//// used to algorithmically calculate legal moves belonging to passed-in player
std::vector<std::vector<int>> calculate_legal_moves (char board[8][8], char player) {
    // declare main move list
    std::vector<std::vector<int>> move_list;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // first we must make sure that the spot is empty and not having a disc
            if (board[i][j] == '-') {
                // check to see if placing a piece there will change one (+more) of the opponent's pieces
                if (is_it_changeable(board, i, j, player)) {
                    // if so, create a 2-element vector representative of the move and push back it to the big move list
                    std::vector<int> move = {i, j};
                    move_list.push_back(move);
                }
            }
        }
    }
    return move_list;
}

//// return a list of all the moves available to black
std::vector<std::vector<int>> get_black_legal_moves(char board[8][8]) {
    return calculate_legal_moves(board, 'b');
}

//// return a list of all the moves available to white
std::vector<std::vector<int>> get_white_legal_moves(char board[8][8]) {
    //.empty() : Returns whether the vector is empty (i.e. whether its size is 0).
    return calculate_legal_moves(board, 'w');
}

//// have to determine if the game is ended, makes sure at least 1 player has a move to make
bool is_the_game_over (char board[8][8]) {
    //.empty() : Returns whether the vector is empty (i.e. whether its size is 0).
    return get_black_legal_moves(board).empty() && get_white_legal_moves(board).empty();
}

//// set board[row][col] to player's piece, and change appropriate pieces
void make_a_move (char (&board)[8][8], int row, int col, char player) {
    // set provided row/col position to the player's character piece
    board[row][col] = player;
    // change discs from resulted move
    change(board, row, col, player);
}

//// for a given board configuration, determine if a move is legal (searches through a previously generated move list)
bool is_it_a_legal_move (char board[8][8], std::vector<std::vector<int>> move_list, int row, int col, char player){
    std::vector<int> proposed_Move = {row, col};
    //This error should NOT occur, as the regex pattern validates the user's input
    if(row > 7 || row < 0 || col > 7 || col < 0)
        throw std::range_error{"is_it_a_legal_move()"};
    //This class defines the type of objects thrown as exceptions to report range errors in internal computations

    // Make sure position is empty
    if(board[row][col] != '-'){
        return false;
    }
    if (std::find(move_list.begin(), move_list.end(), proposed_Move) != move_list.end()){
        return true;
    }
    return false;
}

//// for the passed-in player, print all legal moves (displayed on board update)
void print_the_legal_moves (char board[8][8], char player){
    if(player == 'b'){
        std::cout << "Black legal moves:\n";
        auto v = get_black_legal_moves(board);
        for ( const auto &vec : v ) {
            std::cout << "(" << vec[0]  << "," << vec[1] << ")  ";
        }
        std::cout << std::endl; //or \n
    } else {
        std::cout << "White legal moves:\n";
        auto x = get_white_legal_moves(board);
        for ( const auto &vec : x ) {
            std::cout << "(" << vec[0]  << "," << vec[1] << ")  ";
        }
        std::cout << std::endl;//or \n
    }
}

//// pass in a generated move list to "pretty print" them
void print_the_Legal_Moves(std::vector<std::vector<int>> move_list){
    for ( const auto &vec : move_list ){
        std::cout << "(" << vec[0]  << "," << vec[1] << ")  ";
    }
    std::cout << std::endl;
}

//// overload the << operator to "pretty print" the board
std::ostream& operator << (std::ostream& os, const char board[8][8]){
    //std::ostream& : Output stream objects can write sequences of characters and represent other kinds of data. Specific members are provided to perform these output operations
    //The reason behind using std::ostream& in overload of operator<< is that you may don't want to overload the the mentioned operator for all individual stream types, but only for the common base class of them which has the << functionality.
    std::cout << "   0  1  2  3  4  5  6  7\n";
    for(int i = 0; i < 8; ++i){
        std::cout << (i) << "  ";
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << "  ";
        }
        std::cout << '\n';
    }
    return os;
}

//// go through whole board, and count pieces of passed-in player
int get_the_Score(char board[8][8], char player){
    int total = 0;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            if(board[i][j] == player)
                total += 1;

    return total;
}

//// "pretty print" the winner of the game at the end of the game loop
void print_the_Winner(char (&board)[8][8]){
    int white_total = get_the_Score(board, 'w');
    int black_total = get_the_Score(board, 'b');
    std::cout << "Black total: " << black_total << '\n';
    std::cout << "White total: " << white_total << '\n';
    if(black_total == white_total){
        std::cout << "TIE GAME\n";
        return;
    }
    std::cout << ((black_total > white_total) ? "Black" : "White") << " wins!\n";
}

//// heuristic used to give value to varying states of the game
int heuristic(char board[8][8]){
    // initialize black and white total
    int b_total = 0;
    int w_total = 0;
    // factor in the amount of moves each player has
    b_total += get_black_legal_moves(board).size();
    w_total += get_white_legal_moves(board).size();
    // factor in the amount of pieces each player has on the board
    b_total += get_the_Score(board, 'b');
    w_total += get_the_Score(board, 'w');
    // factor in the importance of all 4 corners
    if(board[0][0] == 'w'){
        w_total += 10;
    }
    if(board[0][0] == 'b'){
        b_total += 10;
    }
    if(board[7][0] == 'w'){
        w_total += 10;
    }
    if(board[7][0] == 'b'){
        b_total += 10;
    }
    if(board[0][7] == 'w'){
        w_total += 10;
    }
    if(board[0][7] == 'b'){
        b_total += 10;
    }
    if(board[7][7] == 'w'){
        w_total += 10;
    }
    if(board[7][7] == 'b'){
        b_total += 10;
    }
    // subtract white's total from black, let black be the maximizer
    return (b_total-w_total);
}

//// simplified minimax without alpha-beta pruning
int minimax(Node *position, int depth, bool maximizing_player){
    //std::cout << "DEPTH = " << depth << '\n';
    if(depth == 0 || is_the_game_over(position->state)){
        //std::cout<< "returning heursitic: " << heuristic(position->state) << '\n';
        return heuristic(position->state);
    }

    if(maximizing_player){
        int max_eval = -9999999;
        for(int i = 0; i < position->child_count; ++i){
            int eval = minimax(position->children[i], depth - 1, false);
            max_eval = std::max(max_eval, eval);
        }
        position->val = max_eval;
        return max_eval;
    } else {
        int min_eval = 9999999;
        for(int i = 0; i < position->child_count; ++i){
            int eval = minimax(position->children[i], depth -1, true);
            min_eval = std::min(min_eval, eval);
        }
        position->val = min_eval;
        return min_eval;
    }
}