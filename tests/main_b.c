#include "../main.h"

int main(void)
{
	_printf("%b\n", 98);
	_printf("%b %b\n", 1U, 255U);
	_printf("%b\n", 0U);
	return (0);
}
