# Display Function to print our matrix
def display(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(f"{matrix[i][j]} ", end="")
        print()
    print()


# Function to check if a matrix is singular or not by its row echelon form
def checkSingular(row_ech):
    if len(row_ech) != len(row_ech[0]):
        print("Determinant is not possible for Non Square Matrices")
    else:
        # Count number of rows that have all values as zero
        k = 0
        for i in row_ech:
            if all(j == 0 for j in i):
                k += 1
        # If rank(REF)!=order or if any row in REF is zero, solution is trivial, hence det(matrix)=0
        if k == 0:
            print("Non Singular Matrix")
        else:
            print("Singular Matrix")


# Function to return the row echelon form of any matrix
def REF(matrix):
    print("Steps to convert above matrix to row echelon form:\n")
    r = len(matrix)
    c = len(matrix[0])
    row_ech = matrix
    for i in range(min(r, c) if r > c else min(r, c) - 1):
        print(f"Step{i + 1}:")
        for j in range(i + 1, r):
            diff = 0 if row_ech[j][i] == 0 else row_ech[j][i] / row_ech[i][i]
            print(f"R{j + 1}=R{j + 1}-({diff})*R{i + 1}")
            row = []
            for k in range(c):
                row.append(row_ech[j][k] - diff * row_ech[i][k])
            row_ech[j] = row
        print()
        display(row_ech)
    return row_ech


# Function to input matrix order and the matrix itself from the user
def inputMatrix():
    r = int(input("Please Enter number of rows : "))
    c = int(input("Please Enter number of columns : "))
    matrix = []
    for i in range(r):
        row = input(f"Please enter {c} elements for row {i + 1} seperated by spaces : ").split()
        matrix.append([float(k) for k in row])
    return matrix


# Firstly we input matrix order and the matrix itself from the user
matrix = inputMatrix()

# Now we print the inputted matrix to the user
print("Your inputted matrix : ")
display(matrix)

# Next we generate the REF of the inputted matrix
row_ech = REF(matrix)

# Lastly we display the Row Echelon Form of the given matrix
print("Row Echelon form matrix : ")
display(row_ech)

# Next we pass our row echelon matrix to check if the inputted matrix is singular or not
checkSingular(row_ech)
