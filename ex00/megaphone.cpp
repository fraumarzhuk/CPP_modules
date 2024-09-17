#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 1;
		while (argv[i])
		{
			while (*argv[i])
			{
				char converted_input = toupper(*argv[i]);
				argv[i]++;
				std::cout << converted_input;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}