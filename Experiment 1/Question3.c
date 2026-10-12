#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    int salary;
};

int main()
{
    int size;

    printf("Enter the number of employees: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid number of employees!\n");
        return 1;
    }

    struct Employee *data = malloc(size * sizeof(struct Employee));

    if (data == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &data[i].id);

        printf("Enter name: ");
        scanf(" %49[^\n]", data[i].name);

        printf("Enter salary: ");
        scanf("%d", &data[i].salary);
    }

    FILE *file = fopen("data.dat", "wb");

    if (file == NULL)
    {
        perror("Error opening file");
        free(data);
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (fwrite(&data[i], sizeof(struct Employee), 1, file) != 1)
        {
            printf("Error writing employee records!\n");
            fclose(file);
            free(data);
            return 1;
        }
    }

    fclose(file);

    file = fopen("data.dat", "rb+");

    if (file == NULL)
    {
        perror("Error reopening file");
        free(data);
        return 1;
    }

    struct Employee emp;

    for (int i = 0; i < size; i++)
    {
        if (fread(&emp, sizeof(struct Employee), 1, file) != 1)
        {
            printf("Error reading employee record!\n");
            fclose(file);
            free(data);
            return 1;
        }

        if (emp.salary > 50000)
        {
            emp.salary += emp.salary * 5 / 100;
        }
        else if (emp.salary > 20000)
        {
            emp.salary += emp.salary * 10 / 100;
        }
        else
        {
            emp.salary += emp.salary * 15 / 100;
        }

        fseek(file, -(long)sizeof(struct Employee), SEEK_CUR);

        if (fwrite(&emp, sizeof(struct Employee), 1, file) != 1)
        {
            printf("Error updating employee record!\n");
            fclose(file);
            free(data);
            return 1;
        }
    }

    fclose(file);

    file = fopen("data.dat", "rb");

    if (file == NULL)
    {
        perror("Error opening updated records");
        free(data);
        return 1;
    }

    printf("\n--- Updated Employee Records ---\n");

    while (fread(&emp, sizeof(struct Employee), 1, file) == 1)
    {
        printf("\nID: %d\n", emp.id);
        printf("Name: %s\n", emp.name);
        printf("Updated Salary: %d\n", emp.salary);
    }

    fclose(file);
    free(data);

    return 0;
}
