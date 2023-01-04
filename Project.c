#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100
void menu();
void IdentifyMatrix();
void ScalarAddMatrix();
void ScalarSubtractMatrix();
void ScalarMultiplyMatrix();
void ScalarDivideMatrix();
void AddMatrices();
void SubtractMatrices();
void MultiplyMatrices();
void VerifyCommutativeMatrices();
void CalcTranspose();
void IsSymmetric();
void IsSkewSymmetric();
void Triangular();
void CalcDeterminant();
void CalcInverse();
void CalcAdjoint();
void CramersRule();
void MatrixInversion();
void CalcRowEchelon();
void CalcReducedEchelon();
void CalcRank();
void CalcDependency();
void swaprows(int* arr, int* arr1, int n);
float Determinant(float Matrix1[][size], int row);
#pragma warning (disable:4996)

int main() {

	menu();
}

void menu() {

	int choice = -1;

	printf("\t\t----Matrix Calculator----\n\n");

	while (choice != 23) {

		printf("\tMenu\n\n");

		printf("1. Identify a Matrix (Identity, Diagonal, Scalar, Rectangular, Square)\n");
		printf("2. Add a Scalar to a Matrix\n");
		printf("3. Subtract a Scalar from a Matrix\n");
		printf("4. Multiply a Scalar with a Matrix\n");
		printf("5. Divide a Scalar by a Matrix\n");
		printf("6. Perform Matrix Addition\n");
		printf("7. Perform Matirx Subtraction\n");
		printf("8. Perform Matrix Multiplication\n");
		printf("9. Verify the Commutative property of Matrices for Multiplication\n");
		printf("10. Calculate the transpose of a Matrix\n");
		printf("11. Verify the Symmetry of a Matrix\n");
		printf("12. Verify the Skew-Symmetry of a Matrix\n");
		printf("13. Identify a Triangular Matrix (Upper, Lower)\n");
		printf("14. Calculate the Determinant of a Matrix\n");
		printf("15. Calculate the Inverse of a Matrix\n");
		printf("16. Calculate the Adjoint of a Matrix\n");
		printf("17. Calculate the Solution of a System via Cramer's Rule\n");
		printf("18. Calculate the Solution of a System via Matrix-Inversion Method\n");
		printf("19. Perform Gaussian Elimination on a Matrix\n");
		printf("20. Perform Gauss-Jordan Elimination on a Matrix\n");
		printf("21. Calculate the Rank of a Matrix\n");
		printf("22. Verify the Linear Dependency of a Matrix\n");
		printf("23. Exit\n\n");

		printf("Enter the choice (1-23) : ");
		scanf("%d", &choice);

		while (choice < 1 || choice > 23) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the choice again (1-22) : ");
			scanf("%d", &choice);
		}

		switch (choice) {

		case 1:
			system("cls");
			IdentifyMatrix();
			break;

		case 2:
			system("cls");
			ScalarAddMatrix();
			break;

		case 3:
			system("cls");
			ScalarSubtractMatrix();
			break;

		case 4:
			system("cls");
			ScalarMultiplyMatrix();
			break;

		case 5:
			system("cls");
			ScalarDivideMatrix();
			break;

		case 6:
			system("cls");
			AddMatrices();
			break;

		case 7:
			system("cls");
			SubtractMatrices();
			break;

		case 8:
			system("cls");
			MultiplyMatrices();
			break;

		case 9:
			system("cls");
			VerifyCommutativeMatrices();
			break;

		case 10:
			system("cls");
			CalcTranspose();
			break;

		case 11:
			system("cls");
			IsSymmetric();
			break;

		case 12:
			system("cls");
			IsSkewSymmetric();
			break;

		case 13:
			system("cls");
			Triangular();
			break;

		case 14:
			system("cls");
			CalcDeterminant();
			break;

		case 15:
			system("cls");
			CalcAdjoint();
			break;

		case 16:
			system("cls");
			CalcDeterminant();
			break;

		case 17:
			system("cls");
			CramersRule();
			break;

		case 18:
			system("cls");
			MatrixInversion();
			break;

		case 19:
			system("cls");
			CalcRowEchelon();
			break;

		case 20:
			system("cls");
			CalcReducedEchelon();
			break;

		case 21:
			system("cls");
			CalcRank();
			break;

		case 22:
			system("cls");
			CalcDependency();
			break;

		case 23:
			printf("\nProgram Terminated!!\n\n");
			break;

		}

		if (choice != 23) {
			
			int run;

			printf("\n1. Continue\n");
			printf("2. Exit\n");
			printf("\nEnter Your choice : ");
			scanf("%d", &run);



			while (run < 1 || run > 2) {

				printf("\nInvalid Input!!\n\n");
				printf("\nEnter choice again : ");
				scanf("%d", &run);
			}

			if (run == 1) {

				system("cls");
			}

			else {

				printf("\nProgram Terminated!!\n\n");
				break;
			}

		}

	}

}

void IdentifyMatrix() {

	int Matrix1[size][size], row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%d", &Matrix1[i][j]);

		}
	}

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	if (row == col) {

		printf("\nThis is a Square Matrix");
	}

	else
		printf("\nThis is a Rectangular Matrix!\n");

	int count = 0, count1 = 0, count2 = 0;

	int diagonal = Matrix1[0][0];

	if (row == col) {

		for (int i = 0;i < row;i++) {

			for (int j = 0;j < col;j++) {

				if (i != j) {

					if (Matrix1[i][j] != 0) {

						printf("\n");
					}

				}

				else if (i == j) {

					if (Matrix1[i][j] == 1) {

						count++;
					}

					else if (Matrix1[i][j] == 0) {

						count1++;
					}

					else if (Matrix1[i][j] > 1 && (Matrix1[i][j] == diagonal)) {

						count2++;
					}

					else
						printf("\nThis is a Diagonal Matrix!!\n");
				}


			}
		}

	}

	if (count == row)
		printf(" and also an Identity Matrix!!\n");

	else if (count1 == row)
		printf(" and also a Null Matrix!!\n");

	else if (count2 == row)
		printf(" and also a Scalar Matrix!!\n");



}

void ScalarAddMatrix() {

	int Matrix1[100][100], row, col;

	int x;

	printf("\nEnter a scalar value : ");
	scanf("%d", &x);

	const int scalar = x;

	printf("\nEnter the Number of Rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the Number of Columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	int add[size][size] = { 0 };

	printf("\nYour Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			add[i][j] = scalar + *(*(Matrix1 + i) + j);
		}
	}

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(add + i) + j));
		}
		printf("\n");
	}

}

void ScalarSubtractMatrix() {

	int Matrix1[100][100], row, col;

	int x;

	printf("\nEnter a scalar value : ");
	scanf("%d", &x);

	const int scalar = x;

	printf("\nEnter the Number of Rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the Number of Columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	int sub[size][size] = { 0 };

	printf("\nYour Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			sub[i][j] = scalar - *(*(Matrix1 + i) + j);
		}
	}

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(sub + i) + j));
		}
		printf("\n");
	}

}

void ScalarMultiplyMatrix() {

	int Matrix1[100][100], row, col;

	int x;

	printf("\nEnter a scalar value : ");
	scanf("%d", &x);

	const int scalar = x;

	printf("\nEnter the Number of Rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the Number of Columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	int prod[size][size] = { 0 };

	printf("\nYour Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			prod[i][j] = scalar * ( * (*(Matrix1 + i) + j));
		}
	}

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", *(*(prod + i) + j));
		}
		printf("\n");
	}

}

void ScalarDivideMatrix() {

	double Matrix1[100][100], x;

	int row, col;

	printf("\nEnter a scalar value : ");
	scanf("%lf", &x);

	const double scalar = x;

	printf("\nEnter the Number of Rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the Number of Columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%lf", (*(Matrix1 + i) + j));
		}
	}

	double divide[size][size] = { 0 };

	printf("\nYour Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			divide[i][j] = (*(*(Matrix1 + i) + j)) / scalar;
		}
	}

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", *(*(divide + i) + j));
		}
		printf("\n");
	}

}

void AddMatrices() {
	int Matrix1[100][100], Matrix2[100][100], row1, col1, row2, col2;

	printf("Enter the Number of Rows of First Matrix: ");
	scanf("%d", &row1);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of First Matrix: ");
	scanf("%d", &col1);

	while (col1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col1);
	}

	printf("\nEnter the Number of Rows of Second Matrix: ");
	scanf("%d", &row2);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of Second Matrix : ");
	scanf("%d", &col2);

	while (col2 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col2);
	}

	while (row1 != row2 || col1 != col2) {

		printf("\nInvalid Input!! For Addition, Both matrices should have Equal Number of Rows and\n Equal Number of Columns!\n\n");
		printf("\nEnter the values again\n");

		printf("Enter the Number of Rows of First Matrix : ");
		scanf("%d", &row1);

		printf("\nEnter the Number of Columns of First Matrix : ");
		scanf("%d", &col1);

		printf("\nEnter the Number of Rows of Second Matrix : ");
		scanf("%d", &row2);

		printf("\nEnter the Number of Columns of Second Matrix : ");
		scanf("%d", &col2);
	}

	system("cls");

	printf("Enter the First Matrix!\n");

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	system("cls");

	printf("Enter the Second Matrix\n");

	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix2 + i) + j));
		}

	}

	system("cls");

	int add[size][size] = { 0 };

	printf("\nYour 1st Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nYour 2nd Matrix!\n");
	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("%d\t", *(*(Matrix2 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			add[i][j] = *(*(Matrix1 + i) + j) + *(*(Matrix2 + i) + j);
		}
	}

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(add + i) + j));
		}
		printf("\n");
	}

}

void SubtractMatrices() {
	int Matrix1[100][100], Matrix2[100][100], row1, col1, row2, col2;

	printf("Enter the Number of Rows of First Matrix: ");
	scanf("%d", &row1);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of First Matrix: ");
	scanf("%d", &col1);

	while (col1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col1);
	}

	printf("\nEnter the Number of Rows of Second Matrix: ");
	scanf("%d", &row2);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of Second Matrix : ");
	scanf("%d", &col2);

	while (col2 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col2);
	}

	while (row1 != row2 || col1 != col2) {

		printf("\nInvalid Input!! For Subtraction, Both matrices should have Equal Number of Rows and\n Equal Number of Columns!\n\n");
		printf("\nEnter the values again\n");

		printf("Enter the Number of Rows of First Matrix: ");
		scanf("%d", &row1);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of First Matrix: ");
		scanf("%d", &col1);

		while (col1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col1);
		}

		printf("\nEnter the Number of Rows of Second Matrix: ");
		scanf("%d", &row2);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of Second Matrix : ");
		scanf("%d", &col2);

		while (col2 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col2);
		}
	}

	system("cls");

	printf("Enter the First Matrix!\n");

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	system("cls");

	printf("Enter the Second Matrix\n");

	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix2 + i) + j));
		}

	}

	system("cls");

	int sub[size][size] = { 0 };

	printf("\nYour 1st Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nYour 2nd Matrix!\n");
	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("%d\t", *(*(Matrix2 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			sub[i][j] = *(*(Matrix1 + i) + j) - *(*(Matrix2 + i) + j);
		}
	}

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(sub + i) + j));
		}
		printf("\n");
	}

}

void MultiplyMatrices() {
	int Matrix1[100][100], Matrix2[100][100], row1, col1, row2, col2;

	printf("Enter the Number of Rows of First Matrix: ");
	scanf("%d", &row1);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of First Matrix: ");
	scanf("%d", &col1);

	while (col1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col1);
	}

	printf("\nEnter the Number of Rows of Second Matrix: ");
	scanf("%d", &row2);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of Second Matrix : ");
	scanf("%d", &col2);

	while (col2 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col2);
	}

	while (col1 != row2) {

		printf("\nInvalid Input!! For Multiplication, Number of Columns of FIrst Matrix should be equal to the\nNumber of Rows of Second Matrix!\n\n");
		printf("\nEnter the values again\n");

		printf("Enter the Number of Rows of First Matrix: ");
		scanf("%d", &row1);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of First Matrix: ");
		scanf("%d", &col1);

		while (col1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col1);
		}

		printf("\nEnter the Number of Rows of Second Matrix: ");
		scanf("%d", &row2);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of Second Matrix : ");
		scanf("%d", &col2);

		while (col2 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col2);
		}
	}

	system("cls");

	printf("Enter the First Matrix!\n");

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	system("cls");

	printf("Enter the Second Matrix\n");

	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix2 + i) + j));
		}

	}

	system("cls");

	int prod[size][size] = { 0 };

	printf("\nYour 1st Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nYour 2nd Matrix!\n");
	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("%d\t", *(*(Matrix2 + i) + j));
		}
		printf("\n");
	}

	printf("\nThe Resultant Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col2;j++) {

			prod[i][j] = 0;

			for (int k = 0;k < col1;k++) {

				prod[i][j] += (*(*(Matrix1 + i) + k)) * (*(*(Matrix2 + k) + j));
			}
		}
	}

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col2;j++) {

			printf("%d\t", *(*(prod + i) + j));
		}
		printf("\n");
	}

}

void VerifyCommutativeMatrices() {
	int Matrix1[100][100], Matrix2[100][100], row1, col1, row2, col2;

	printf("Enter the Number of Rows of First Matrix: ");
	scanf("%d", &row1);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of First Matrix: ");
	scanf("%d", &col1);

	while (col1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col1);
	}

	printf("\nEnter the Number of Rows of Second Matrix: ");
	scanf("%d", &row2);

	while (row1 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row1);
	}

	printf("\nEnter the Number of Columns of Second Matrix : ");
	scanf("%d", &col2);

	while (col2 < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col2);
	}

	while (col1 != row2 && col2 != row1) {

		printf("\nInvalid Input!! For Commutative Property, Number of Columns of FIrst Matrix should be equal to the\nNumber of Rows of Second Matrix and\nNumber of Columns of Second Matrix should be equal to the\nNumber of Rows of First Matrix!\n\n");
		printf("\nEnter the values again\n");

		printf("Enter the Number of Rows of First Matrix: ");
		scanf("%d", &row1);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of First Matrix: ");
		scanf("%d", &col1);

		while (col1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col1);
		}

		printf("\nEnter the Number of Rows of Second Matrix: ");
		scanf("%d", &row2);

		while (row1 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of rows again : ");
			scanf("%d", &row1);
		}

		printf("\nEnter the Number of Columns of Second Matrix : ");
		scanf("%d", &col2);

		while (col2 < 0) {

			printf("\nInvalid Input!!\n\n");
			printf("Enter the number of columns again : ");
			scanf("%d", &col2);
		}
	}

	system("cls");

	printf("Enter the First Matrix!\n");

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix1 + i) + j));
		}
	}

	system("cls");

	printf("Enter the Second Matrix\n");

	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%d", (*(Matrix2 + i) + j));
		}

	}

	system("cls");

	int prod1[size][size] = { 0 }, prod2[size][size] = { 0 }, count = 0;

	printf("\nYour 1st Matrix!\n");
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col1;j++) {

			printf("%d\t", *(*(Matrix1 + i) + j));
		}
		printf("\n");
	}

	printf("\nYour 2nd Matrix!\n");
	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col2;j++) {

			printf("%d\t", *(*(Matrix2 + i) + j));
		}
		printf("\n");
	}
	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col2;j++) {

			prod1[i][j] = 0;

			for (int k = 0;k < col1;k++) {

				prod1[i][j] += (*(*(Matrix1 + i) + k)) * (*(*(Matrix2 + k) + j));
			}
		}
	}

	for (int i = 0;i < row2;i++) {

		for (int j = 0;j < col1;j++) {

			prod2[i][j] = 0;

			for (int k = 0;k < col2;k++) {

				prod2[i][j] += (*(*(Matrix2 + i) + k)) * (*(*(Matrix1 + k) + j));
			}
		}
	}

	for (int i = 0;i < row1;i++) {

		for (int j = 0;j < col2;j++) {

			if ((*(*prod1 + i) + j) == (*(*prod2 + i) + j)) {

				count++;
			}
		}
	}

	if (count == row1 * col2) {

		printf("\nMatrices obey Commutative Property!\n\n");
	}

	else
		printf("\nMatrices do not obey Commutative Property!\n\n");
}

void CalcTranspose() {

	int Matrix1[size][size], row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%d", &Matrix1[i][j]);

		}
	}

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	printf("\nTranspose Matrix!\n\n");

	for (int i = 0;i < col;i++) {

		for (int j = 0;j < row;j++) {

			printf("%d\t", Matrix1[j][i]);

		}

		printf("\n");
	}
}

void IsSymmetric() {

	int Matrix1[size][size], row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%d", &Matrix1[i][j]);

		}
	}

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	int symm[size][size];

	for (int i = 0;i < col;i++) {

		for (int j = 0;j < row;j++) {

			symm[i][j] = Matrix1[j][i];

		}
	}

	int count = 0;

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			if (symm[i][j] == Matrix1[i][j])
				count++;

		}
	}

	if (count == row * col) {

		printf("\nMatrix is Symmetric!!\n");
	}

	else
		printf("\nMatrix is not Symmetric!!\n");
}

void IsSkewSymmetric() {

	int Matrix1[size][size], row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%d", &Matrix1[i][j]);

		}
	}

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%d\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	int symm[size][size];

	for (int i = 0;i < col;i++) {

		for (int j = 0;j < row;j++) {

			symm[i][j] = Matrix1[j][i];

		}
	}

	int count = 0;

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			if (symm[i][j] == -1 * Matrix1[i][j])
				count++;

		}
	}

	if (count == row * col) {

		printf("\nMatrix is Skew Symmetric!!\n");
	}

	else
		printf("\nMatrix is not Skew Symmetric!!\n");
}

void Triangular() {

	int row, col, z;
	int i, j, k, flag = 0, flag1 = 0, count = 0;
	float Matrix[size][size], DETERMINANT = 1;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}


	if (row != col)
	{
		printf("Matrix is not Triangular!!\n");
	}
	else
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				printf("\n Enter the element %d x %d of Matrix : ", i + 1, j + 1);
				scanf("%f", &Matrix[i][j]);
			}
		}
		system("cls");

		printf("\nYour Matrix!!\n\n");

		for (i = 0; i < row; i++)
		{

			for (j = 0; j < col; j++)
			{
				printf("%.2f\t", Matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for (int i = 0; i < row; i++)
		{
			for (int j = 0;j < col;j++)
			{
				if ((i < j) && Matrix[i][j] != 0)
				{
					flag++;
				}
				else if ((i > j) && Matrix[i][j] != 0)
				{
					flag1++;
				}
			}
		}
		if (flag == 0 && flag1 == 0)
		{
			printf("Matrix is both Upper & lower Triangular!!\n");
		}
		else if (flag == 0 && flag1 != 0)
		{
			printf("Matrix is lower Triangular!!\n");
		}
		else if (flag != 0 && flag1 == 0)
		{
			printf("Matrix is Upper Triangular!!\n");
		}
		else
		{
			printf("Matrix is neither Upper nor lower Triangular!!\n");
		}
	}
}

void CalcDeterminant() {

	int row, col;
	float Matrix1[size][size];

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	while (row != col) {

		printf("Invalid Input!!\n\n");
		printf("Enter the values again\n");
		printf("\nEnter the Number of Rows : ");
		scanf("%d", &row);

		printf("\nEnter the Number of Columns : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%f", &Matrix1[i][j]);
		}
	}

	system("cls");

	printf("\nYour Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;
	float DETERMINANT = 1;

	printf("Solution :\n\n");

	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], col);
						DETERMINANT *= -1;
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.2f\t", Matrix1[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], col);
								DETERMINANT *= -1;
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				DETERMINANT *= temp;
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix1[k][z];

					for (j = 0; j < col; j++)
					{
						Matrix1[k][j] += (Matrix1[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				DETERMINANT *= temp;
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix1[k][i];
				for (j = 0; j < col; j++)
				{
					Matrix1[k][j] -= (Matrix1[i][j] * p);
				}
			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.2f\t", Matrix1[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}

	printf("Determinant = %.2f\n", DETERMINANT);

}

void CalcInverse() {

	float Matrix1[size][size];

	int row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	while (row != col) {

		printf("Inverse not possible\n\n");

	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%f", &Matrix1[i][j]);

		}
	}
	//copying matrix
	float Matrix[size][size];
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			Matrix[i][j] = Matrix1[i][j];

		}
	}

	system("cls");

	printf("\nYour Matrix!\n\n");

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			printf("%.2f\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	float det = Determinant(Matrix1, row);


	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			Matrix1[i][j] = Matrix[i][j];

		}
	}
	if (det == 0) {

		printf("\nMatrix is not Invertible!!\n\n");
	}

	else {

		float temp[size][size], cofac[size][size];
		int x, y, m, n, i, j;

		for (x = 0; x < row; x++)
		{
			for (y = 0; y < row; y++)
			{
				m = 0;
				n = 0;
				for (i = 0; i < row; i++)
				{
					for (j = 0; j < row; j++)
					{
						if (i != x && j != y)
						{
							temp[m][n] = Matrix1[i][j];

							if (n < (row - 2)) {

								n++;
							}

							else {

								n = 0;
								m++;
							}
						}
					}
				}
				cofac[x][y] = pow(-1, x + y) * Determinant(temp, row - 1);
			}
		}

		float inverse[size][size];

		printf("\nInverse Matrix!!\n\n");

		for (int i = 0; i < col; i++) {

			for (int j = 0; j < row; j++) {

				inverse[i][j] = cofac[j][i];
			}
		}

		for (int i = 0; i < row; i++) {

			for (int j = 0; j < col; j++) {

				inverse[i][j] /= det;
			}
		}

		for (int i = 0; i < row; i++) {

			for (int j = 0; j < col; j++) {

				printf("%.2f\t", inverse[i][j]);
			}

			printf("\n");
		}
	}
}

void CalcAdjoint() {

	float Matrix1[size][size];

	int row, col;

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%f", &Matrix1[i][j]);

		}
	}

	system("cls");

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);

		}

		printf("\n");
	}


	float temp[size][size], cofac[size][size];
	int x, y, m, n, i, j;

	for (x = 0;x < row; x++)
	{
		for (y = 0;y < row; y++)
		{
			m = 0;
			n = 0;
			for (i = 0;i < row; i++)
			{
				for (j = 0;j < row; j++)
				{
					if (i != x && j != y)
					{
						temp[m][n] = Matrix1[i][j];

						if (n < (row - 2)) {

							n++;
						}

						else {

							n = 0;
							m++;
						}
					}
				}
			}
			cofac[x][y] = pow(-1, x + y) * Determinant(temp, row - 1);
		}
	}

	printf("\nAdjoint Matrix!!\n\n");

	for (int i = 0;i < col;i++) {

		for (int j = 0;j < row;j++) {

			printf("%.2f\t", cofac[j][i]);
		}

		printf("\n");
	}

}

void CramersRule() {

	int row, col, z;
	int i, j, k, flag = 0, flag1 = 0, count = 0;
	float Matrix[size][size], DETERMINANT = 1;
	float Matrix1[size][size];

	printf("Enter number of unknown variables : ");
	scanf("%d", &row);

	col = row;

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			printf("\n Enter the element of variable Matrix %d x %d : ", i + 1, j + 1);

			scanf("%f", &Matrix[i][j]);
		}
	}

	//COPYING THE ARRAY INTO ANOTHER

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Matrix1[i][j] = Matrix[i][j];
		}
	}

	float Aug_matrix[size];

	for (int i = 0; i < row; i++) {

		printf("\nEnter the element %d x %d of Solution Matrix! : ", i + 1);

		scanf("%f", &Aug_matrix[i]);
	}

	printf("\nYour Variable Matrix!!\n\n");

	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{
			printf("%.2f\t", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Your Solution Matrix!\n\n");

	for (int i = 0; i < row; i++)
	{
		printf("%.2f\n", Aug_matrix[i]);
	}

	printf("\n");

	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix[i][i]) != 1)
		{

			float temp1 = Matrix[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix[k][i] != 0)
					{

						swaprows(&Matrix[i][0], &Matrix[k][0], col);
						DETERMINANT *= -1;
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.1f\t", Matrix[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix[k][z] != 0)
							{
								swaprows(&Matrix[i][i], &Matrix[k][0], col);
								DETERMINANT *= -1;
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix[i][z];
				DETERMINANT *= temp;
				if (Matrix[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix[i][j] = ((Matrix[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix[k][z];

					for (j = 0; j < col; j++)
					{
						Matrix[k][j] += (Matrix[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix[i][i];
				DETERMINANT *= temp;
				if (Matrix[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix[i][j] = ((Matrix[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix[k][i];
				for (j = 0; j < col; j++)
				{
					Matrix[k][j] -= (Matrix[i][j] * p);
				}
			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.2f\t", Matrix[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}
	printf("\nDETERMINANT : %+.2f\n", DETERMINANT);

	int check = 0;
	float* DET;
	DET = (float*)malloc(col * sizeof(float));

	while (check < col)
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				Matrix[i][j] = Matrix1[i][j];
			}
		}

		float DETERMINANT_1 = 1;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (j == check)
				{
					Matrix[i][j] = Aug_matrix[i];
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%.2f ", Matrix[i][j]);
			}
			printf("\n");
		}

		for (i = 0; i < row; i++)
		{

			count = i;
			if ((Matrix[i][i]) != 1)
			{

				float temp1 = Matrix[i][i];
				if (temp1 == 0)
				{
					for (int k = i + 1; k < row; k++)
					{
						if (Matrix[k][i] != 0)
						{

							swaprows(&Matrix[i][0], &Matrix[k][0], col);
							DETERMINANT_1 *= -1;
							for (int l = 0; l < row; l++)
							{
								for (int q = 0; q < col; q++)
								{
									printf("%.2f\t", Matrix[l][q]);
								}
								printf("\n");

							}
							printf("\n");
							break;
						}
						else
						{
							count++;
						}


					}

				}


				if ((count == row - 1) && (i != (row - 1)))
				{
					flag = 0;
					count = 0;
					for (z = i + 1; z < col; z++)
					{

						if (Matrix[i][z] == 0)
						{
							for (int k = i + 1; k < row; k++)
							{
								if (Matrix[k][z] != 0)
								{
									swaprows(&Matrix[i][i], &Matrix[k][0], col);
									DETERMINANT_1 *= -1;
									flag++;
									break;
								}

							}

						}
						else
						{
							break;
						}
						if (flag != 0)
						{
							break;
						}


					}

					float temp = Matrix[i][z];
					DETERMINANT_1 *= temp;
					if (Matrix[i][z] != 0)
					{
						for (j = i; j < col; j++)
						{
							Matrix[i][j] = ((Matrix[i][j]) / temp);
						}
					}


					for (k = i + 1; k < row; k++)
					{
						float p = -Matrix[k][z];

						for (j = 0; j < col; j++)
						{
							Matrix[k][j] += (Matrix[i][j] * p);
						}
					}

					flag1 = 1;
				}



				if (flag1 == 0)
				{
					float temp = Matrix[i][i];
					DETERMINANT_1 *= temp;
					if (Matrix[i][i] != 0)
					{
						for (j = i; j < col; j++)
						{
							Matrix[i][j] = ((Matrix[i][j]) / temp);
						}
					}


				}

			}
			if (flag1 == 0)
			{
				for (k = i + 1; k < row; k++)
				{
					float p = Matrix[k][i];
					for (j = 0; j < col; j++)
					{
						Matrix[k][j] -= (Matrix[i][j] * p);
					}
				}
			}
			for (int l = 0; l < row; l++)
			{
				for (int q = 0; q < col; q++)
				{
					printf("%.2f\t", Matrix[l][q]);
				}
				printf("\n");

			}
			printf("\n");

		}
		printf("DETERMINANT : %+.2f\n", DETERMINANT_1);

		*(DET + check) = DETERMINANT_1;
		check++;
	}

	for (int i = 0; i < col; i++)
	{
		printf("VALUE FOR %d VARIABLE: %.2f\n", (i + 1), *(DET + i) / DETERMINANT);
	}
	free(DET);
}

void MatrixInversion() {

	float Matrix1[size][size], Matrix2[size][size];

	int var;

	printf("\nEnter the number of unknown variables : ");
	scanf("%d", &var);

	while (var < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &var);
	}

	printf("\nEnter the variable Matrix!\n");

	for (int i = 0;i < var;i++) {

		for (int j = 0;j < var;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%f", &Matrix1[i][j]);

		}
	}

	system("cls");

	printf("\nEnter the solution Matrix!\n");

	for (int i = 0;i < var;i++) {

		for (int j = 0;j < 1;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);

			scanf("%f", &Matrix2[i][j]);

		}
	}

	printf("\nYour Variable Matrix!\n\n");

	for (int i = 0;i < var;i++) {

		for (int j = 0;j < var;j++) {

			printf("%.2f\t", Matrix1[i][j]);

		}

		printf("\n");
	}

	printf("\nYour Solution Matrix!\n\n");

	for (int i = 0; i < var; i++) {

		for (int j = 0; j < 1; j++) {

			printf("%.2f\t", Matrix2[i][j]);

		}

		printf("\n");
	}
	//copying matrix
	float Matrix[size][size];
	for (int i = 0; i < var; i++) {

		for (int j = 0; j < var; j++) {

			Matrix[i][j] = Matrix1[i][j];

		}
	}

	float det = Determinant(Matrix1, var);


	for (int i = 0; i < var; i++) {

		for (int j = 0; j < var; j++) {

			Matrix1[i][j] = Matrix[i][j];

		}
	}
	if (det == 0) {

		printf("\nMatrix is not Invertible!!\n\n");
	}

	else {

		float temp[size][size], cofac[size][size];
		int x, y, m, n, i, j;

		for (x = 0; x < var; x++)
		{
			for (y = 0; y < var; y++)
			{
				m = 0;
				n = 0;
				for (i = 0; i < var; i++)
				{
					for (j = 0; j < var; j++)
					{
						if (i != x && j != y)
						{
							temp[m][n] = Matrix1[i][j];

							if (n < (var - 2)) {

								n++;
							}

							else {

								n = 0;
								m++;
							}
						}
					}
				}
				cofac[x][y] = pow(-1, x + y) * Determinant(temp, var - 1);
			}
		}

		float inverse[size][size];

		printf("\nInverse Matrix!!\n\n");

		for (int i = 0; i < var; i++) {

			for (int j = 0; j < var; j++) {

				inverse[i][j] = cofac[j][i];
			}
		}

		for (int i = 0; i < var; i++) {

			for (int j = 0; j < var; j++) {

				inverse[i][j] /= det;
			}
		}

		float** prod;

		prod = (float**)malloc(var * sizeof(float*));

		for (int i = 0;i < var;i++) {

			prod[i] = (float*)malloc(1 * sizeof(float*));
		}

		for (int i = 0;i < var;i++) {

			for (int j = 0;j < 1;j++) {

				prod[i][j] = 0;

				for (int k = 0;k < var;k++) {

					prod[i][j] += inverse[i][k] * Matrix2[k][j];
				}
			}
		}

		printf("\nSolution :\n\n");

		for (int i = 0;i < var;i++) {

			for (int j = 0;j < 1;j++) {

				printf("X%d = %.2f\n\n", i + 1, prod[i][j]);
			}
		}

		for (int i = 0;i < var;i++) {

			free(prod[i]);
		}

		free(prod);
	}
}

void CalcRowEchelon() {

	int row, col;
	float Matrix1[size][size];

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%f", &Matrix1[i][j]);
		}
	}

	system("cls");

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;

	printf("Solution :\n\n");
	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], col);
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.2f\t", Matrix1[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}

			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], col);
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix1[k][z];

					for (j = 0; j < col; j++)
					{
						Matrix1[k][j] += (Matrix1[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix1[k][i];
				for (j = 0; j < col; j++)
				{
					Matrix1[k][j] -= (Matrix1[i][j] * p);
				}
			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.2f\t", Matrix1[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}
}

void CalcReducedEchelon() {


	int row, col;
	float Matrix1[size][size];

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%f", &Matrix1[i][j]);
		}
	}
	system("cls");
	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;

	printf("Solution :\n\n");
	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], col);
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.2f\t", Matrix1[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], col);
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = 0; k < row; k++)
				{
					if (k != i)
					{
						float p = -Matrix1[k][z];

						for (j = 0; j < col; j++)
						{
							Matrix1[k][j] += (Matrix1[i][j] * p);
						}
					}

				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = 0; k < row; k++)
			{
				if (k != i)
				{
					float p = Matrix1[k][i];
					for (j = 0; j < col; j++)
					{
						Matrix1[k][j] -= (Matrix1[i][j] * p);
					}
				}

			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.2f\t", Matrix1[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}
}

void CalcRank() {

	int row, col;
	float Matrix1[size][size];

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	while (row != col || row > 4 || col > 4) {

		printf("Invalid Input!!\n\n");
		printf("Enter the values again\n");
		printf("\nEnter the Number of Rows : ");
		scanf("%d", &row);

		printf("\nEnter the Number of Columns : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%f", &Matrix1[i][j]);
		}
	}

	system("cls");

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;
	float DETERMINANT = 1;

	printf("Solution :\n\n");
	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], col);
						DETERMINANT *= -1;
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.1f\t", Matrix1[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], col);
								DETERMINANT *= -1;
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				DETERMINANT *= temp;
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix1[k][z];

					for (j = 0; j < col; j++)
					{
						Matrix1[k][j] += (Matrix1[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				DETERMINANT *= temp;
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix1[k][i];
				for (j = 0; j < col; j++)
				{
					Matrix1[k][j] -= (Matrix1[i][j] * p);
				}
			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.1f\t", Matrix1[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}
	if (row == col)
	{
		int rank = 0, flag2;
		for (int l = 0; l < row; l++)
		{
			flag2 = 0;
			for (int q = 0; q < col && flag2 == 0; q++)
			{
				if (Matrix1[l][q] == 1)
				{
					rank++;
					flag2++;
				}
			}
		}

		printf("Rank : %d\n", rank);

	}
}

void CalcDependency(){


	int row, col;
	float Matrix1[size][size];

	printf("\nEnter the number of rows : ");
	scanf("%d", &row);

	while (row < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of rows again : ");
		scanf("%d", &row);
	}

	printf("\nEnter the number of columns : ");
	scanf("%d", &col);

	while (col < 0) {

		printf("\nInvalid Input!!\n\n");
		printf("Enter the number of columns again : ");
		scanf("%d", &col);
	}

	while (row != col || row > 4 || col > 4) {

		printf("Invalid Input!!\n\n");
		printf("Enter the values again\n");
		printf("\nEnter the Number of Rows : ");
		scanf("%d", &row);

		printf("\nEnter the Number of Columns : ");
		scanf("%d", &col);
	}

	printf("\nEnter the Matrix!\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("\nEnter the element %d x %d : ", i + 1, j + 1);
			scanf("%f", &Matrix1[i][j]);
		}
	}

	system("cls");

	printf("\nYour Matrix!\n\n");

	for (int i = 0;i < row;i++) {

		for (int j = 0;j < col;j++) {

			printf("%.2f\t", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;
	float DETERMINANT = 1;

	printf("Solution :\n\n");

	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], col);
						DETERMINANT *= -1;
						for (int l = 0; l < row; l++)
						{
							for (int q = 0; q < col; q++)
							{
								printf("%.1f\t", Matrix1[l][q]);
							}
							printf("\n");

						}
						printf("\n");
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < col; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], col);
								DETERMINANT *= -1;
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				DETERMINANT *= temp;
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix1[k][z];

					for (j = 0; j < col; j++)
					{
						Matrix1[k][j] += (Matrix1[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				DETERMINANT *= temp;
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < col; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix1[k][i];
				for (j = 0; j < col; j++)
				{
					Matrix1[k][j] -= (Matrix1[i][j] * p);
				}
			}
		}
		for (int l = 0; l < row; l++)
		{
			for (int q = 0; q < col; q++)
			{
				printf("%.1f\t", Matrix1[l][q]);
			}
			printf("\n");

		}
		printf("\n");

	}
	if (row == col)
	{
		int rank = 0, flag2;
		for (int l = 0; l < row; l++)
		{
			flag2 = 0;
			for (int q = 0; q < col && flag2 == 0; q++)
			{
				if (Matrix1[l][q] == 1)
				{
					rank++;
					flag2++;
				}
			}
		}

		printf("Rank : %d\n", rank);

		if (rank == col)
		{
			printf("The Matrix is Linealy Independent!!\n");
		}
		else
		{

			printf("The Matrix is Linearly Dependent!!\n");
		}
	}
}

void swaprows(int* arr, int* arr1, int n){

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr1 + i);
        *(arr1 + i) = temp;
    }
}

float Determinant(float Matrix1[][size], int row) {

	int i, j, k, z, flag = 0, flag1 = 0, count = 0;

	float DETERMINANT = 1;

	for (i = 0; i < row; i++)
	{

		count = i;
		if ((Matrix1[i][i]) != 1)
		{

			float temp1 = Matrix1[i][i];
			if (temp1 == 0)
			{
				for (int k = i + 1; k < row; k++)
				{
					if (Matrix1[k][i] != 0)
					{

						swaprows(&Matrix1[i][0], &Matrix1[k][0], row);
						DETERMINANT *= -1;
						break;
					}
					else
					{
						count++;
					}


				}

			}


			if ((count == row - 1) && (i != (row - 1)))
			{
				flag = 0;
				count = 0;
				for (z = i + 1; z < row; z++)
				{

					if (Matrix1[i][z] == 0)
					{
						for (int k = i + 1; k < row; k++)
						{
							if (Matrix1[k][z] != 0)
							{
								swaprows(&Matrix1[i][i], &Matrix1[k][0], row);
								DETERMINANT *= -1;
								flag++;
								break;
							}

						}

					}
					else
					{
						break;
					}
					if (flag != 0)
					{
						break;
					}


				}

				float temp = Matrix1[i][z];
				DETERMINANT *= temp;
				if (Matrix1[i][z] != 0)
				{
					for (j = i; j < row; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


				for (k = i + 1; k < row; k++)
				{
					float p = -Matrix1[k][z];

					for (j = 0; j < row; j++)
					{
						Matrix1[k][j] += (Matrix1[i][j] * p);
					}
				}

				flag1 = 1;
			}



			if (flag1 == 0)
			{
				float temp = Matrix1[i][i];
				DETERMINANT *= temp;
				if (Matrix1[i][i] != 0)
				{
					for (j = i; j < row; j++)
					{
						Matrix1[i][j] = ((Matrix1[i][j]) / temp);
					}
				}


			}

		}
		if (flag1 == 0)
		{
			for (k = i + 1; k < row; k++)
			{
				float p = Matrix1[k][i];
				for (j = 0; j < row; j++)
				{
					Matrix1[k][j] -= (Matrix1[i][j] * p);
				}
			}
		}

	}

	return DETERMINANT;

}
