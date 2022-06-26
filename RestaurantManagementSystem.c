#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

void owner();
void employee();
void sales_record();
void add_item();
void delete_menu();
void view_employee_detail(int );
void add_employee();
void delete_employee();
void menu(int c);
void order();
void spacing();
void welcome();
void login();
void delete_sales_record();

struct employee{
    char name[20];
    int id;
    long salary;
}emp;

struct menu{
    char name[20];
    int price;
}menu_book;

struct people{
    char name[20];
    char gender[10];
}peo;

void spacing(){
    int i;
    for(i=0;i<45;i++)
    printf(" ");
}

int main(){
    welcome();
    return 0;
}

void welcome(){
    system("cls");
    spacing();
    printf("\tWELCOME TO OUR RESTAURANT MANAGEMENT SYSTEM\n\n");
    spacing();
    printf("\t\tCREATED BY : SHARIB (2K20/A15/04) AND SHIVAM KUSHWAHA (2K20/A15/12)\n\n");
    spacing();
    printf("\t\t\n");
    spacing();
    login();
}

void login(){
    int password,n,k;
    printf("\t\tLOGIN:\n\n\n\n");
    spacing();
    star:
    printf("\n\n\t\t\t\t\t");
    printf("\t\t1.owner\n");
    spacing();
    printf("\t\t2.employee\n");
    spacing();
    printf("\t\t3.Exit\n");
    spacing();
    printf("\n\n");
    printf("ENTER YOUR CHOICE (NUMERICAL VALUE ONLY): ");
    scanf("%d",&n);
    system("cls");
    if(n==1){
        go:
        system("cls");
        spacing();
        printf("ENTER LOGIN PASSWORD : ");
        scanf("%d",&password);
        spacing();
        if(password==12345){
            owner();
        }
        else{
            printf("\n");
            spacing();
            printf("WRONG PASSWORD\n");
            spacing();
            printf("1.TRY AGAIN\n");
            spacing();
            printf("2.EXIT\n");
            spacing();
            printf("ENTER CHOICE: ");
            scanf("%d",&k);
            if(k==1){
                goto go;
            }
            else{
                exit(0);
            }
        }
    }
    else if(n==2){
        gogo:
        system("cls");
        spacing();
        printf("ENTER LOGIN PASSWORD : ");
        scanf("%d",&password);
        spacing();
        if(password==78960){
            employee();
        }
        else{
            printf("\n");
            spacing();
            printf("WRONG PASSWORD\n");
            spacing();
            printf("1.TRY AGAIN\n");
            spacing();
            printf("2.EXIT\n");
            spacing();
            printf("ENTER CHOICE: ");
            scanf("%d",&k);
            if(k==1){
                goto gogo;
            }
            else{
               exit(0);
            }
        }
    }
    else if(n==3){
       system("cls");
       printf("\n\n\n");
       spacing();
       printf("THANK YOU FOR USING OUR RESTAURANT MANAGEMENT SYSTEM\n\n\n");
       spacing();
       exit(0);
    }
    else{
        printf("\n\n\t\tWRONG CHOICE PLEASE TRY AGAIN : ");
        goto star;
    }
}

void owner(){
    system("cls");
    int n,k;
    printf("\n\n\t\t\t\t1.VIEW SALES RECORD");
    printf("\n\t\t\t\t2.CHANGE IN MENU");
    printf("\n\t\t\t\t3.VIEW MENU");
    printf("\n\t\t\t\t4.VIEW EMPLOYEE DETAILS");
    printf("\n\t\t\t\t5.DELETE SALES RECORD");
    printf("\n\t\t\t\t6.ADD NEW EMPLOYEE");
    printf("\n\t\t\t\t7.DELETE EMPLOYEE ");
    printf("\n\t\t\t\t8.LOG OUT");
    printf("\n\n\n\t\t\t\tENTER CHOICE : ");
    scanf("%d",&n);
    switch(n){
        case 1:
        sales_record(1);
        break;
        case 2:
        system("cls");
        printf("WHAT DO YOU WANT \n\t\t\t\t1.ADD\n\t\t\t\t2.DELETE\n");
        printf("\t\t\t\tENTER CHOICE: ");
        scanf("%d",&k);
        if(k==1)
        add_item();
        else if(k==2)
        delete_menu();
        else
        printf("\t\t\t\tWRONG CHOICE");
        break;
        case 3:
        menu(1);
        break;
        case 4:
        view_employee_detail(2);
        break;
        case 5:
        delete_sales_record();
        break;
        case 6:
        add_employee();
        break ;
        case 7:
        delete_employee();
        break ;
        case 8:
        welcome();
        break ;
        default:
        printf("\t\t\t\tWRONG CHOICE\n");
    }
}

void employee(){
    system("cls");
    int i,n;
    printf("\n\n\t\t\t\t1.VIEW SALES RECORD");
    printf("\n\t\t\t\t2.TAKE ORDER");
    printf("\n\t\t\t\t3.VIEW MENU");
    printf("\n\t\t\t\t4.LOG OUT");
    printf("\n\n\n\t\t\t\tENTER CHOICE: ");
    scanf("%d",&n);
    switch(n){
        case 1:
        sales_record(2);
        break;
        case 2:
        order();
        break;
        case 3:
        menu(2);
        break;
        case 4:
        welcome();
        break ;
        default:
        printf("\t\t\t\tWRONG CHOICE\n");
    }
}

void add_employee(){
    system("cls");
    FILE *file;
    file=fopen("details.txt","a");
    if(file==NULL)
    printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\t\t\t\tENTER THE DETAILS OF NEW EMPOLYEE\n");
        printf("\t\t\t\tENTER NAME ID SALARY\n\t\t\t\t");
        fscanf(stdin,"%s %d %ld",emp.name,&emp.id,&emp.salary);
        fprintf(file,"\n%s %d %ld",emp.name,emp.id,emp.salary);
        printf("\t\t\t\tADDED SUCCESSFULLY");
        fclose(file);
        printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
        getch();
        owner();
    }
}

void view_employee_detail(int c){
    system("cls");
    FILE *file;
    file=fopen("details.txt","r");
    if(file==NULL)
    printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\t\t\t\tEMPLYOEE NAME\tID\t\tSALARY");
        while(feof(file)==0){
            fscanf(file,"%s %d %ld\n",emp.name,&emp.id,&emp.salary);
            fprintf(stdout,"\n\t\t\t\t%s\t\t%d\t\t%ld",emp.name,emp.id,emp.salary);
        }
        fclose(file);
        if(c==1){
            printf("\n\t\t\t\tPRESS ANY KEY: ");
            getch();
        }
        else{
            printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
            getch();
            owner();
        }
    }
}

void delete_employee(){
    view_employee_detail(1);
    char name[30];
    long id;
    FILE *ptr1,*ptr2;
    ptr1=fopen("details.txt","r");
    ptr2=fopen("temp.txt","w");
    if(ptr1==NULL || ptr2==NULL)
        printf("\n\t\t\t\tTHE FILES DOES NOT EXIST.\n");
    else{
        printf("\n\t\t\t\tENTER THE FIRST NAME AND ID OF EMLOYEE.\n");
        printf("\t\t\t\tNAME\t\tID\n\t\t\t\t");
        scanf("%s %d",name,&id);
        while(feof(ptr1)==0){
            fscanf(ptr1,"%s %d %ld",emp.name,&emp.id,&emp.salary);
            if(strcmp(emp.name,name)==0 && emp.id==id)
            continue;
            fprintf(ptr2," %s %ld %ld",emp.name,emp.id,emp.salary);
        }
        fclose(ptr1);
        fclose(ptr2);
        remove("details.txt");
        rename("temp.txt","details.txt");
        printf("\t\t\t\tDELETED SUCCESSFULY\n");
        view_employee_detail(2);
    }
}

void add_item(){
    system("cls");
    FILE *fp2;
    fp2=fopen("menu.txt","a");
    if(fp2==NULL)
        printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\t\t\t\tENTER THE NAME OF ITEMS AND THEIR PRICE:\n");
        printf("\t\t\t\tITEM NAME PRICE\n\t\t\t\t");
        fscanf(stdin,"%s %d",menu_book.name,&menu_book.price);
        fprintf(fp2,"\n%s %d",menu_book.name,menu_book.price);
        fclose(fp2);
        printf("\t\t\t\tADDED ITEM SUCCESSFULY");
        printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
        getch();
        owner();
    }
}

void menu(int c){
    system("cls");
    FILE *file;
    file=fopen("menu.txt","r");
    if(file==NULL)
    printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\t\t\t\tITEM\t\t\tPRICE\n");
        while(feof(file)==0){
            fscanf(file,"%s %d\n",menu_book.name,&menu_book.price);
            fprintf(stdout,"\t\t\t\t%s\t\t\t%d\n",menu_book.name,menu_book.price);
        }
        fclose(file);
        printf("\t\t\t\tPRESS ANY KEY :");
        getch();
        if(c==1){
            owner();
        }
        else if(c==2){
            employee();
        }      
    }
}

void delete_menu(){
    menu(3);
    char item[30];
    int price;
    FILE *ptr1,*ptr2;
    ptr1=fopen("menu.txt","r");
    ptr2=fopen("temp.txt","w");
    if(ptr1==NULL||ptr2==NULL)
    printf("\n\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\n\t\t\t\tENTER THE ITEMS AND THEIR PRICE.\n");
        printf("\t\t\t\tITEM\t\tPRICE\n\t\t\t\t");
        scanf("%s %d",item,&price);
        while(feof(ptr1)==0){
            fscanf(ptr1," %s %d",menu_book.name,&menu_book.price);
            if(strcmp(menu_book.name,item)==0 && menu_book.price==price)
            continue;
            fprintf(ptr2," %s %d\n",menu_book.name,menu_book.price);
        }
        fclose(ptr1);
        fclose(ptr2);
        remove("menu.txt");
        rename("temp.txt","menu.txt");
        printf("\t\t\t\tDELETED SUCCESSFULY\n");
        printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
        getch();
        owner();
    }
}

void order(){
    system("cls");
    int i=1,n,k,total=0;
    printf("\t\t\t\tENTER YOUR FIRST NAME AND GENDER:\n\t\t\t\t");
    scanf("%s %s",peo.name,peo.gender);
    printf("\t\t\t\tHERE IS YOURS FOOD, WHICH ONE YOU WANT TO PREFER:\n ");
    FILE *file2;
    FILE *file;
    file=fopen("menu.txt","r");
    if(file==NULL)
    printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        printf("\t\t\t\tITEM\t\tPRICE\n");
        while(feof(file)==0){
            fscanf(file,"%s %d\n",menu_book.name,&menu_book.price);
            fprintf(stdout,"\t\t\t\t%d\t\t%s\t\t%d\n",i,menu_book.name,menu_book.price);
            i++;
        }
        printf("\t\t\t\tENTER NUMBER OF ITEMS YOU WANT: ");
        scanf("%d",&n);
        while(n>0){
            printf("\t\t\t\tENTER YOUR CHIOCE:");
            scanf("%d",&k);
            fseek(file,0,SEEK_SET);
            for(i=0;i<k;i++){
                fscanf(file,"%s %d",menu_book.name,&menu_book.price);
            }
            printf("\t\t\t\tHOW MANY %s DO YOU WANT : ",menu_book.name);
            scanf("%d",&k);
            total+=menu_book.price*k;
            n--;
        } 
        printf("\t\t\t\t\tYOUR TOTAL BILL: %d",total);
        file2=fopen("sales.txt","a");
        fprintf(file2,"%s %s %d\n",peo.name,peo.gender,total);
        fclose(file);
        fclose(file2);
        printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO EMPLOYEE PAGE: ");
        getch();
        employee();
    }
}

void sales_record(int c){
    system("cls");
    long total=0;
    int amount;
    FILE *fp1;
    fp1=fopen("sales.txt","r");
    if(fp1==NULL)
    printf("\t\t\t\tTHE FILE DOES NOT EXIST.\n");
    else{
        int q=1;
        printf("\t\t\t\tS.NO\t\tNAME\t\t\tGENDER\t\tAMOUNT\n");
        while(feof(fp1)==0){
            fscanf(fp1,"%s %s %d\n",peo.name,peo.gender,&amount);
            fprintf(stdout,"\t\t\t\t%d.\t\t%s\t\t\t%s\t\t%d\n",q,peo.name,peo.gender,amount);
            total+=amount;
            q++;
        }
        fclose(fp1);
        printf("\n\t\t\t\tTHE TOTAL SALE TILL NOW IS: %ld",total);
        printf("\n\t\t\t\tPRESS ANY KEY TO RETURN:");
        getch();
        if(c==1){
            owner();
        }
        else{
            employee();
        }
    }
}

void delete_sales_record(){
    system("cls");
    remove("sales.txt");
    FILE *file;
    file=fopen("sales.txt","a");
    fclose(file);
    printf("\t\t\t\tSALES RECORD DELETED SUCCESSFULLY\n");
    printf("\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
    getch();
    owner();
}