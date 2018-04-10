#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
using namespace std;

int n;
int m;
bool choice;

struct location {
	bool n, e, s, w;
	location(): n(true), e(true), s(true), w(true) {}
};

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	cout << "x size: ";
	cin >> m;
	cout << "y size: ";
	cin >> n;

	location maze[n][m];

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			maze[y][x].s = false;
			maze[y][x].e = false;
			maze[y][x].w = false;
			maze[y][x].n = false;

			if (y == 0 && x != 0) {
				maze[y][x].w = true;
			}
			else if (x == 0 && y != 0) {
				maze[y][x].n = true;
			}
		}
	}

	for (int y = 1; y < n; ++y)
	{
		for (int x = 1; x < m; ++x)
		{
			if ((rand()%2) == 0) {
				maze[y][x].w = true;
			}
			else {
				maze[y][x].n = true;
			}
		}
	}

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].w == true) {
				maze[y][x-1].e = true;
			}
			else if (maze[y][x].n == true) {
				maze[y-1][x].s = true;
			}
			else if (maze[y][x].s == true) {
				maze[y+1][x].n = true;
			}
			else if (maze[y][x].e == true) {
				maze[y][x+1].w = true;
			}
		}
	}

	ofstream file ("randomMaze");
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].n == true && maze[y][x].w == true) file << "0";
			else file << "1";
			if (maze[y][x].n == true) file << "00";
			else file << "11";
			if (maze[y][x].n == true && maze[y][x].e == true) file << "0";
			else file << "1";
		}
		file << endl;
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].w == true) file << "0";
			else file << "1";
			if (maze[y][x].n == true || maze[y][x].e == true || maze[y][x].s == true || maze[y][x].w == true) file << "00";
			else file << "11";
			if (maze[y][x].e == true) file << "0";
			else file << "1";
		}
		file << endl;
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].s == true && maze[y][x].w == true) file << "0";
			else file << "1";
			if (maze[y][x].s == true) file << "00";
			else file << "11";
			if (maze[y][x].s == true && maze[y][x].e == true) file << "0";
			else file << "1";
		}
		file << endl;
	}
	file.close();

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].n == true && maze[y][x].w == true) cout << " ";
			else cout << "+";
			if (maze[y][x].n == true) cout << "  ";
			else cout << "--";
			if (maze[y][x].n == true && maze[y][x].e == true) cout << " ";
			else cout << "+";
		}
		cout << endl;
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].w == true) cout << " ";
			else cout << "|";
			if (maze[y][x].n == true || maze[y][x].e == true || maze[y][x].s == true || maze[y][x].w == true) cout << "  ";
			else cout << "++";
			if (maze[y][x].e == true) cout << " ";
			else cout << "|";
		}
		cout << endl;
		for (int x = 0; x < m; ++x)
		{
			if (maze[y][x].s == true && maze[y][x].w == true) cout << " ";
			else cout << "+";
			if (maze[y][x].s == true) cout << "  ";
			else cout << "--";
			if (maze[y][x].s == true && maze[y][x].e == true) cout << " ";
			else cout << "+";
		}
		cout << endl;
	}
}
