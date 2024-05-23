#include <iostream>

using namespace std;

struct Max_Element_Result {
	double max_element;
	int max_index_rows;
	int max_index_cols;
};

template <int size_1, int size_2>
void Show(double(&matrix)[size_1][size_2])
{
	for (int i = 0; i < size_1; i++)
	{
		cout << "Sportswoman #" << i + 1 << ": ";
		for (int j = 0; j < size_2; j++)
		{
			cout  << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

template <int size_1, int size_2>
Max_Element_Result Max_Elemnt(double(&matrix)[size_1][size_2])
{
	Max_Element_Result result;
	result.max_element = matrix[0][0];
	result.max_index_rows = 0;
	result.max_index_cols = 0;
	for (int i = 0; i < size_1; i++)
	{
		for (int j = 0; j < size_2; j++)
		{
			if (result.max_element < matrix[i][j])
			{
				result.max_element = matrix[i][j];
				result.max_index_rows = i;
				result.max_index_cols = j;
			}
		}
	}

	return result;
}

int main()
{
	double matrix[5][3] =
	{
		{21.2,23.2,3},
		{12.3,2,33.3},
		{1,45,45.01},
		{12,22.5,55},
		{16,44,7.5},
	};

	Show(matrix);
	Max_Element_Result result = Max_Elemnt(matrix);
	cout << "Sportswoman #" << result.max_index_rows + 1 << " has the best result of " << result.max_element << " from attempt #" << result.max_index_cols + 1;

	return 0;
}