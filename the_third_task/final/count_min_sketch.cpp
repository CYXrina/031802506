# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <limits>
# include "count_min_sketch.hpp"
using namespace std;

CountMinSketch::CountMinSketch(float ep, float gamm) {
  eps = ep;
  gamma = gamm;
  w = ceil((unsigned int)(exp(1) / eps));
  d = ceil((unsigned int)(log(1/gamma)));
  
  C = new int *[d];
  unsigned int i, j;
  for (i = 0; i < d; i++) {
    C[i] = new int[w];
    for (j = 0; j < w; j++) {
      C[i][j] = 0;
    }
  }
  
  srand(time(NULL));
  hashes = new int* [d];
  for (i = 0; i < d; i++) {
    hashes[i] = new int[2];
    genajbj(hashes, i);
  }
}

CountMinSketch::~CountMinSketch() {
  
  unsigned int i;
  for (i = 0; i < d; i++) {
    delete[] C[i];
  }
  delete[] C;
  
  
  for (i = 0; i < d; i++) {
    delete[] hashes[i];
  }
  delete[] hashes;
}

void CountMinSketch::update(int item, int c) {
  unsigned int hashval = 0;
  for (unsigned int j = 0; j < d; j++) {
    hashval = ((long)hashes[j][0]*item+hashes[j][1])%LONG_PRIME;
	hashval %= w;
	//cout << "C[j][hashval] = " << C[j][hashval] //²âÊÔÓï¾ä
	//	<< '\n' << "w=" << w << '\n' << "hashval=" << hashval << '\n';
    C[j][hashval] = C[j][hashval] + c;
	//cout << "C[j][hashval] = " << C[j][hashval] << "\n\n"; //²âÊÔÓï¾ä
  }
}

void CountMinSketch::update(const char *str, int c) {
  int hashval = hashstr(str);
  update(hashval, c);
 
}

unsigned int CountMinSketch::estimate(int item) {
  int minval = numeric_limits<int>::max();
  unsigned int hashval = 0;
  for (unsigned int j = 0; j < d; j++) {
    hashval = ((long)hashes[j][0]*item+hashes[j][1])%LONG_PRIME;
    hashval %= w;
    minval = MIN(minval, C[j][hashval]);
  }
  return minval;
}

unsigned int CountMinSketch::estimate(const char *str) {
  int hashval = hashstr(str);
  return estimate(hashval);
}

void CountMinSketch::genajbj(int** hashes, int i) {
  hashes[i][0] = int(float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1);
  hashes[i][1] = int(float(rand())*float(LONG_PRIME)/float(RAND_MAX) + 1);
}

unsigned int CountMinSketch::hashstr(const char *str) {
  unsigned long hash = 5381;
  int c;
  while (c = *str++) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}



/**
Class definition for CountMinSketch.
public operations:
// overloaded updates
void update(int item, int c);
void update(char *item, int c);
// overloaded estimates
unsigned int estimate(int item);
unsigned int estimate(char *item);
**/


// CountMinSketch constructor
// ep -> error 0.01 < ep < 1 (the smaller the better)
// gamma -> probability for error (the smaller the better) 0 < gamm < 1

/*if (!(0.009 <= ep && ep < 1)) {
cout << "eps must be in this range: [0.01, 1)" << endl;
exit(EXIT_FAILURE);
} else if (!(0 < gamm && gamm < 1)) {
cout << "gamma must be in this range: (0,1)" << endl;
exit(EXIT_FAILURE);
}*/


// initialize counter array of arrays, C
// initialize d pairwise independent hashes
// CountMinSkectch destructor
// free array of counters, C
// free array of hash values
// countMinSketch update item count (int)
// countMinSketch update item count (string)
// CountMinSketch estimate item count (int)
// CountMinSketch estimate item count (string)
// generates aj,bj from field Z_p for use in hashing
// generates a hash value for a string
// same as djb2 hash function
