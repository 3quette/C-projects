#include<stdio.h>
#include<stdlib.h>
//variables
int deal;
int d1=0;
int d2=0;
int d3=0;
int d4=0;
int d5=0;
int i,j,row,col;
int rply;
char ans;
int Table[5][10];
char han_ki_na;
int countd1=0;
int countd2=0;
int countd3=0;
int countd4=0;
int countd5=0;
int sum=0;
//pointer
int *sp=&sum;
//structure
struct user_data{
		char address[400];
		char phone_number[11];
		char name[50];
	} UD;
	FILE *fp;
//functions
void ask();
void bill();
void menu();
void order();
int user_information();
void TableReservation();
void printArray();
//main 
void main(){
	printf("\t\t\t!________WELCOME TO ASH RESTAURANT________!\n");
    ask();
    }
//to ask if user wants to place an order or to reserve a table
void ask(){
	printf("FOR TABLE RESERVATION PRESS '1' AND FOR ONLINE ORDER PRESS '2'\n");
	scanf("%d",&rply);
	if(rply==1){
		TableReservation();
	}
	else if(rply==2){
		menu();
		order();
        user_information();
        bill();
	}
   }

//Print the menu

void menu(){
	printf("\t\tDEAL 01................Rs.380\n\nA Beef Burger, Fried Chicken Piece, Fries, Coleslaw & A Cold Drink or Masala Lemonade\n");
	printf("\t\tDEAL 02................Rs.350\n\nA Crispy Chicken Burger, Fried Drum Stick, Fries, Coleslaw & A Cold Drink or Masala Lemonade\n");
	printf("\t\tDEAL 03................Rs.280\n\n1 Plate Beef Kabab 1 Paratha & A Cold Drink or Masala Lemonade\n");
	printf("\t\tDEAL 04................Rs.250\n\n1 A Chicken Roll, 4 Piece Wings, Fries, A Cold Drink or Masala Lemonade\n");
	printf("\t\tDEAL 05................Rs.200\n\n1 A Qtr.Crispy Or Masala Broast, Fries & A Cold Drink or Masala Lemonade\n\n\n");
}
//taking orders
void order(){
	do{
	printf("WHICH DEAL NUMBER WOULD YOU LIKE TO ORDER?(!!ENTER DEAL NUMBER!!):\n");
	scanf("%d",&deal);
	if(deal==1){
		d1=d1+380;
		countd1++;
	}
	if(deal==2){
		d2=d2+350;
		countd2++;
	}
	if(deal==3){
		d3=d3+280;
		countd3++;
	}
	if(deal==4){
		d4=d4+250;
		countd4++;
	}
	if(deal==5){
		d5=d5+200;
		countd5++;
	}
	
	if (deal > 5 || deal <= 0) {
		printf("PLEASE ENTER A VALID DEAL NUMBER\n");
	}
		
	printf("WOULD YOU LIKE TO PLACE MORE ORDER? (PRESS 'y' TO CONTINUE ELSE PRESS 'n') \n");
	scanf(" %c",&han_ki_na);
} while(han_ki_na!='n');
}

//storing user's delivery information

int user_information(){
	int i;
	
	printf("\t\t\t\nFOR DELIVERY,ENTER YOUR INFORMATION:\n");
	printf("ENTER NAME:");
	scanf("%s",&UD.name);
	printf("\nENTER PHONE NUMBER :");
	scanf("%s",&UD.phone_number);
	printf("\nENTER ADDRESS :");
	scanf("%s",&UD.address);
	
	fp=fopen("user_info.txt","a");
	if(fp==NULL){
       printf("ERROR!!");
       exit(1);
   }
   printf("%d",*sp);
	fprintf(fp,"\nNAME: %s\nPHONE NUMBER: %s\nADDRESS: %s\nBILL : %d\n",UD.name,UD.phone_number,UD.address,*sp);
	fclose(fp);
	system("cls");

	
}
//Calculating the bill and displaying the final reciept
void bill()
{  
	sum=d1+d2+d3+d4+d5;
    printf("\t\t\t!________RECEIPT________!\n");
    printf("-------------------------------------------------------------------------------\n");
	printf("\n\t\t\tNAME:%s \n\t\t\tPHONE NUMBER: %s \n\t\t\tADDRESS: %s\n",UD.name,UD.phone_number,UD.address);
	printf("-------------------------------------------------------------------------------\n");
	printf("\t\t\tTOTAL DEALS YOU'VE ORDERED\n\t\t\tDEAL 1: %d\tRs.%d\n\t\t\tDEAL 2: %d\tRs.%d",countd1,d1,countd2,d2);
	printf("\n\t\t\tDEAL 3: %d\tRs.%d\n\t\t\tDEAL 4: %d\tRs.%d\n",countd3,d3,countd4,d4);
	printf("\t\t\tDEAL 5: %d\tRs.%d\n",countd5,d5);
	
	printf("\t\t\tYOUR TOTAL AMOUNT IS : Rs.%d",sum);
	

}

//reserves table
void TableReservation(){
	printf("WE HAVE 5 BRANCHES(0-5) AND 10 TABLES\n");
		do{
    	   printArray();
    		printf("ENTER BRANCH NUMBER");
	       	scanf("%d",&row);
	       	printf("ENTER TABLE NUMBER");
	       	scanf("%d",&col);
	       	if(row>5||row<0 || col>10||col<0){
	       		printf("THE TABLE NUMBER IS NOT VALID\n");
			   }
	       	else if(Table[row][col]!=1){
	       		Table[row][col]=1;
	       		printf("YOUR TABLE HAS BEEN BOOKED\n WOULD YOU LIKE TO RESERVE ANOTHER TABLE?\n");
	            printf("PRESS 'Y' TO CONITUE ELSE PRESS'N'\n");
	         	scanf(" %c",&ans);
			   } 
			else if(Table[row][col]==1){
				printf("table is already booked\n");
			}  }
    	while(ans!='n');
	FILE *table_pointer;
	table_pointer=fopen("table_num.txt","a");
	if(table_pointer==NULL){
       printf("ERROR!!");
       exit(1); }
      for(i=0;i<5;i++){
			for(j=0;j<10;j++){
				fprintf(table_pointer,"__%d__",Table[i][j]);
				}
				fprintf(table_pointer,"\n");
  }
  fclose(table_pointer);   }
//printing the table
void printArray(){
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
			printf("__%d__",Table[i][j]);
		}
		printf("\n");}}
   	
	
