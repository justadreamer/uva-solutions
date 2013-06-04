#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

struct pos {
	int r,c;
	bool operator==(const pos& right) {
		return r==right.r && c==right.c;
	};
} init_pos, cur_pos;

typedef enum {
	W,N,E,S
} direction_enum;

direction_enum cur_dir;

int row,col;
struct cell {
	bool is_wall;
	int visits_count;
};

vector<vector<cell> > maze;

pos next_cell() {
	pos new_pos = cur_pos;
	switch (cur_dir) {
		case W: 
			new_pos.c--;
			break;
		case N:
			new_pos.r--;
			break;
		case E:
			new_pos.c++;
			break;
		case S:
			new_pos.r++;
			break;
	}
	return new_pos;
}

pos right_cell() {
	pos new_pos = cur_pos;
	switch (cur_dir) {
		case W: 
			new_pos.r--;
			break;
		case N:
			new_pos.c++;
			break;
		case E:
			new_pos.r++;
			break;
		case S:
			new_pos.c--;
			break;
	}
	return new_pos;
}

direction_enum turn_left() {
	direction_enum dir = cur_dir;
	if (cur_dir==W) 
		dir = S;
	else 
		dir = (direction_enum)(cur_dir-1);
	return dir;
}

direction_enum turn_right() {
	direction_enum dir = cur_dir;
	if (cur_dir==S) 
		dir = W;
	else
		dir = (direction_enum)(cur_dir+1);
	return dir;	
}

bool is_wall(const pos& _pos) {
	bool is_wall = _pos.r<0 || _pos.c<0 || _pos.r==row || _pos.c==col || 
		maze[_pos.r][_pos.c].is_wall;
	return is_wall;
}


void input_maze() {
	maze = vector<vector<cell> > (row,vector<cell>(col,cell()));

	for (int i = 0;i<row;i++) {
		for (int j=0;j<col;j++) {
			int v = 0;
			scanf("%01d",&v);
			maze[i][j].is_wall = v;
		//	cout<<maze[i][j].is_wall;
		}
		//cout<<endl;
	}
	init_pos.r = row-1;
	init_pos.c = 0;
	cur_pos = init_pos;
	cur_dir = E;
}

void walk_maze() {
	bool finished = false;
	while (!finished) {
		pos next_pos = cur_pos;
		pos right_pos = right_cell();
		if (!is_wall(right_pos)) {
			cur_dir = turn_right();
			next_pos = right_pos;
		} else {
			next_pos = next_cell();
			while (is_wall(next_pos)) {
				cur_dir = turn_left();
				next_pos = next_cell();
			}
		}
		maze[cur_pos.r][cur_pos.c].visits_count++;
		//cout<<"cur="<<cur_pos.r<<" "<<cur_pos.c<<" next="<<next_pos.r<<" "<<next_pos.c<<" right="<<right_pos.r<<" "<<right_pos.c<<endl;
		cur_pos = next_pos;
		if (cur_pos==init_pos) {
			finished = true;
		}
	}
}

int get_stat(int visits) {
	int count = 0;
	for (int i=0;i<row;i++) {
		for (int j=0;j<col;j++) {
			if (!maze[i][j].is_wall && maze[i][j].visits_count==visits) {
				count++;
			}
		}
	}
	return count;
}

void output_stats() {
	int max_stat = 4;
	for (int i=0;i<=max_stat;i++) {
		printf("% 3d",get_stat(i));
	}
	cout<<endl;
}

int main(int argc, char* argv[]) {
	while (cin>>row>>col && row && col) {
		input_maze();
		walk_maze();
		output_stats();
	}

	return 0;
}
