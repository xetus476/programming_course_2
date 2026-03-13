n = 4

mat = [[0 for i in range(n)] for j in range(n)]

for mat_i in range(n):
    for mat_j in range(n):
        mat_nach_poz = [[0 for i in range(n)] for j in range(n)]
        mat_nach_poz[mat_i][mat_j] = 1
        print(mat_nach_poz)
        for q in range(n):
            
            

#print(mat)