#include <thread>
#include <mutex>

class spinlockMutex {

public:
	spinlockMutex();
	void lock();
	void unlock();

private:
	std::atomic_flag flag = ATOMIC_FLAG_INIT;

};
