#include <stdio.h>
#include <stdlib.h>
struct Grade{
    int data;
    struct Grade *next;
};

struct Student{
    int id;
    struct Grade *grade;
    struct Student *next;
    int avg;
};

struct Student * find_student(struct Student *head){
    int input;
    printf("Enter student id to found : ");
    scanf("%d" , &input);

    if(head == NULL)
        return NULL;
    struct Student *temp_student = head;
    while(temp_student != NULL){
        if(temp_student->id == input){
            printf("Student Found.\n");
            return temp_student;
        }
        temp_student = temp_student->next;
    }
    printf("Student not found\n");
}


void add_grade(struct Student *student){
    if(student->grade == NULL){
        struct Grade *head_grade = (struct Grade *)malloc(sizeof(struct Grade));
        /* get grade for student */
        printf("Enter grade for %d : " , student->id);
        scanf("%d" , &head_grade->data);
        head_grade->next = NULL;
        student->grade = head_grade;
        return;
    }
    struct Grade *temp_grade = student->grade;
    while(temp_grade->next != NULL)
        temp_grade = temp_grade->next;
    struct Grade *new_grade = (struct Grade *)malloc(sizeof(struct Grade));
    temp_grade -> next = new_grade;
    new_grade ->next = NULL;
    printf("Enter grade for %d : " , student->id);
    scanf("%d" , &new_grade->data);
    printf("New grade added.");

}

struct Student *add_student(struct Student *head){
    if(head == NULL){
        struct Student *new_head = (struct Student *)malloc(sizeof(struct Student));
        new_head->next = NULL;
        new_head->grade = NULL;
        new_head -> avg = 0;
        /* get student id */
        printf("Enter student id : ");
        scanf("%d" , &new_head->id);
        printf("New student created succesfully.\n");
        return new_head;
    }
    struct Student *temp_student = head;
    while(temp_student->next != NULL){
        temp_student = temp_student ->next;
    }
    struct Student *new_student = (struct Student *)malloc(sizeof(struct Student));
    temp_student->next = new_student;
    /* get student id */
    printf("Enter student id : ");
    scanf("%d" , &new_student->id);
    new_student -> next = NULL;
    new_student -> grade = NULL;
    new_student -> avg = 0;
    printf("New student created succesfully.\n");
    return head;

}

int calculate_avg_for_specefic_student(struct Student *student){
    struct Grade *temp_grade = student->grade;
    int result = 0;
    int count = 0;
    while(temp_grade != NULL){
        result = result + temp_grade->data;
        count++;
        temp_grade = temp_grade -> next;
    }
    result = result / count;
    return result;
}

void calculate_avg_for_all(struct Student *head){
    struct Student *temp_student = head;

    while(temp_student != NULL){
        int avg = calculate_avg_for_specefic_student(temp_student);
        //save in array
        temp_student = temp_student->next;
    }

    // send array to bubble sort and print it 
    // done 
}

int main(int argc, char const *argv[]){
    
    struct Student *head = NULL;
    struct Student *ali = NULL;
    head = add_student(head);
    head = add_student(head);
    ali = find_student(head);
    add_grade(ali);
    add_grade(ali);
    add_grade(ali);
    add_grade(ali);
    add_grade(ali);
    printf("\n\nali first grade : %d" , ali->grade->data);
    printf("\n\nali first grade : %d" , ali->grade->next->data);
    printf("\n\nali first grade : %d" , ali->grade->next->next->data);
    printf("\n\nali first grade : %d" , ali->grade->next->next->next->data);
    printf("\n\nali first grade : %d" , ali->grade->next->next->next->next->data);
    printf("\n\n ALI AVG : %d" , calculate_avg_for_specefic_student(ali));


}
