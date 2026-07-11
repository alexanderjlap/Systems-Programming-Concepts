#include "structhelper.h"

/** 
 * @purpose Create a student using the data provided.
 * 
 * @param name Name of student.
 * @param grade Grade of student.
 * @param gpa GPA of student.
 * 
 * @return A pointer to newly created student.
 */
Student* make_student(char* name, int grade, float gpa)
{
    Student *s = (Student *)malloc(sizeof(Student));
    s->name = mystrndup(name, mystrlen(name));
    s->grade = grade;
    s->gpa = gpa;
    return s;
}

/** 
 * @purpose Student struct is printed.
 * 
 * @param s A pointer to a student struct.
 */
void print_student(Student* s)
{
    printf("Student %s:\n\tGrade: %d\n\tGPA: %f\n", s->name, s->grade, s->gpa);
}

/** 
 * @purpose Makes a student with random data in it. 
 * 
 * @return A student structure contained data created at random.
 */
Student* make_random_student()
{
    Student* rand_student = (Student *)malloc(sizeof(Student));
    char* rand_name = make_random_string(10);
    rand_student->name = mystrndup(rand_name, mystrlen(rand_name));
    rand_student->grade = get_random_int_range(1, 12);
    rand_student->gpa = (int)get_random_int_range(1, 4);
    return rand_student;
}

/** 
 * @purpose Obtains a random string of the desired length. Returns a string that only contains the uppercase letters A through Z.
 *
 * @param length The random string's length.
 * 
 * @return A pointer to the random string.
 */
char* make_random_string(size_t length)
{
    char* rand_str = (char *)malloc(length + 1);
    size_t i;
    for (i = 0; i < length; i++)
    {
        *(rand_str + i) = get_random_char();
    }
    *(rand_str + length) = '\0';
    return rand_str;
}

/** 
 * @purpose Choose a random letter from A to Z. 
 * 
 * @return The random character.
 */
char get_random_char()
{
    double randd = (double)rand() / RAND_MAX;
    return (char)(26*randd + 65);
}

/** 
 * @purpose The range of random integers.
 * 
 * @param min The lowest end of the range 
 * @param max The higest point in the range.
 * 
 * @return The random number.
 */
int get_random_int_range(int min, int max)
{
    double randd = (double)rand() / RAND_MAX;
    return (max - min + 1) * randd + min;
}

/** 
 * @purpose Create a random student array of the specified size.
 * 
 * @param n The quantity of students chosen at random.
 * 
 * @return A pointer to the array of random students.
 */
Student** make_random_student_n(size_t n)
{
    Student** student_arr = (Student **)malloc(n * sizeof(Student*));
    size_t i;
    for (i = 0; i < n; i++)
    {
        student_arr[i] = make_random_student();
    }
    return student_arr;
}

/** 
 * @purpose A variety of students is printed.
 * 
 * @param s_arr Prints the array
 * @param count How many students are in the array.
 */
void print_student_n(Student** s_arr, size_t count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        print_student(s_arr[i]);
    }
}

/** 
 * @purpose A variety of kids shallow copy.
 * 
 * @param source The origin array.
 * @param count A tally of the array's component.
 * 
 * @return The copied array.
 */
Student** student_arr_dup(Student** source, size_t count)
{
    //Copy array.
    Student** student_arr = (Student **)malloc(count * sizeof(Student**));
    size_t i;
    for (i = 0; i < count; i++)
    {
        student_arr[i] = source[i];
    }
    return student_arr;
}

/** 
 * @purpose Give the related pointers a free pass before changing them to null to release an array of pupils. This transfers memory from the array back to the slack. 
 * 
 * @param s_arr The array to free.
 * @param count The array's size in terms  of items.
 */
void free_student_arr(Student** s_arr, size_t count)
{
    size_t i;
    for (i = 0; i < count; i++)
    {
        free(s_arr[i]);
        s_arr[i] = NULL;
    }
}

/** 
 * @purpose Creates a deep copy of a student structure array. Instead of just linking the new struct to the pointers already allocated in the old one, this copies the original struct.
 * 
 * @param s_arr The variety of students to copy.
 * @param count How many items there are in the student array.
 * 
 * @return A pointer to the copied array.
 */
Student** deep_copy_student_arr(Student** s_arr, size_t count)
{
    Student** student_cpy = (Student**)malloc(count * sizeof(Student)); 
    size_t i;
    for (i = 0; i < count; i++)
    {
        student_cpy[i] = make_student(s_arr[i]->name, s_arr[i]->grade, s_arr[i]->gpa);
    }
    return student_cpy;
}
