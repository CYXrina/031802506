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

	CountMinSketch c(0.1, 0.01);

	freopen("Request.txt", "r", stdin);
	freopen("output_pre.txt", "w", stdout);
	char temp[50] = {};
	while (cin.getline(temp, 50)){
		char IP[50] = {};
		
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

		/*int pre1 = c.estimate(IP) > T;
		int pre2 = c.estimate(IP) > T;
		int pre3 = c.estimate(IP) > T;*/
		c.update(IP, bytes);

		//if (pre1+pre2+pre3 >= 2)
			//continue;
		

		if (c.estimate(IP) >= T ) 
			cout << "HackIP: " << IP << '\n';
			
	}

	return 0;
}