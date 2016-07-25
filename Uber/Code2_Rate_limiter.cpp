// Coding: Rate limiter (http://blog.gssxgss.me/not-a-simple-problem-rate-limiting/) token bucket, leaky bucket 
// Question like design a rate limiter that only support 15 API call per second, over 15 API call will fail. 


// The idea is to use token bucket idea. that create a bucket and add tokens to the bucket according to QPS and 
//then any success call removes the token from bucket. If there are no tokens then failed the call.


#include <iostream>
#include <ctime>

using namespace std;

class RateLimiter{
public: 
	RateLimiter(int TotalRequest, int seconds)
	{
		bucketSize = TotalRequest;
		float = bucketSize / seconds;
		clock_t = clock();
		tokens = 0;
	}

	bool Request()
	{
		clock_t now = clock();
		int diffSec = double(now - lastAccessTime)/CLOCKS_PER_SEC;
		int newTotal = tokens + diffSec * rate;
		lastAccessTime = now;
		if(newTotal >= bucketSize)
		{
			tokens = bucketSize;
		}
		
		if(tokens>0)
		{
			tokens--;
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int bucketSize;
	float rate;
	int tokens;
	clock_t lastAccessTime;
};

int main()
{

	return 0;
}

