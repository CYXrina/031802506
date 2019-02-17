# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <cmath>
# include <string>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "count_min_sketch.hpp"
# define T 1500
using namespace std;

int main(int argc, char **argv) {

	CountMinSketch c(0.1, 0.1);
	while (1) {
		char IP[50] = {}, temp[50] = {};
		cin.getline(temp, 50);
		int bytes = 0, len = strlen(temp);
		if (temp[0]<'0' || temp[0]>'9')
			continue;

		char *ptr, i = 0;
		ptr = temp;
		while (1)
		{
			i += (*ptr == ' ');
			if (i == 3)
			{
				*ptr = '\0';
				break;
			}
			ptr++;
		}
		ptr++;
		strcpy(IP, temp);
		len -= (strlen(IP)+1);
		while (*ptr != '\0')
		{
			bytes += (*ptr-'0') * (int)(pow(10, len-1));
			len--;
			ptr++;
		}
		//cout << "bytes = " << bytes << '\n';

		c.update(IP, bytes);
		if (c.estimate(IP) >= T)
			cout << "\n hackIP: " << IP << '\n';
	}

	return 0;
}
