#pragma once
typedef int (*CFT)(const void*,const void*);
class ssort
{
public:
	ssort(void);
	~ssort(void);
private:
	void sort(void *base,size_t n,size_t sz, CFT cmp);
public:
	void run(void);
};

