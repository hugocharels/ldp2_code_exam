
int main() {
	
	int x=5, y=7;

	const int* p = &x;
	*p = 1;		// error
	p = &y;

	int* const q = &x;
	*q = 1;
	q = &y;		// error
	
	const int* const r = &x;
	*r = 1;		// error
	r = &y;		// error

	return 0;
}
