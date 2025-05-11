    #include<stdio.h>
    #include<string.h>
    #define max 100000

    typedef struct
    {
        int id;
        char name[100];
        char number[15];
        int age;
        char nationality[50];
        char present_address[300];
    }User;

    typedef struct
    {
        char relation[100];
        char name[100];
        char emergencyContact[15];
        char presentlocation[100];
    }emergency_contact;

    void registration();
    void addcontact();
    void showcontact();
    void showuser();
    void panicbutton();

    int main()
    {
    printf("\t\t\t\t\t\t====================\n");
        printf("\t\t\t\t\t\t    Safety portal\n");
        printf("\t\t\t\t\t\t====================\n");
        printf("\t\t\t\t\t\tWelcome to our site,\n");
        printf("\t\t\t\t\t\tWe prefer your \"SAFETY\"\n");


       printf("As a new user you have to Sign up:\n");

        char email[100];
        printf("Enter your email: ");
        fgets(email,sizeof(email),stdin);

        char password[100];
        printf("Enter a strong password(above 8 characters): ");
        fgets(password,sizeof(password),stdin);

        printf("You have singed up successfully!!!\n");

        printf("\n");

        printf("Sign in your account: \n");

        int attempt=3;


        for(int i=0;i<=3;i++)
        {
            int flag=1;

            char email2[100];
        printf("\nEnter Email: ");
        fgets(email2,sizeof(email2),stdin);

        char password2[100];
        printf("Password: ");
        fgets(password2,sizeof(password2),stdin);

        if(strcmp(email,email2)!=0)
        {
            flag=0;
        }
        if(strcmp(password,password2)!=0)
        {
            flag=0;
        }

        if(flag==0)
        {
            if(attempt==1)
            {
                printf("Please try again later!!!");
                return 0;
            }
            printf("Wrong Email or Password!!!");
            attempt--;
        }
        else
        {
            printf("Logged in successfully!!!\n");
            break;
        }
        }

        int choise;

        do
        {
            printf("\n============== Home Page ==============\n");
            printf("\n");
            printf("            1.Registration\n");
            printf("            2.Add Emergency Contact\n");
            printf("            3.Show all contact\n");
            printf("            4.Show User Information\n");
            printf("            5.Panic Button\n");
            printf("            6.Exit\n");
            printf("\n=======================================\n");

            printf("Enter your choise: ");
            scanf("%d",&choise);
            fflush(stdin);
            printf("\n");

            switch(choise)
            {
            case 1:
                registration();
                break;
            case 2:
                addcontact();
                break;
            case 3:
                showcontact();
                break;
            case 4:
                showuser();
                break;
            case 5:
                panicbutton();
                break;
            case 6:
                printf("Exiting the program!!!\n");
                break;
            default:
                printf("Invalid Choise! Please enter a valid number!!!");
                }
        }while(choise!=6);

    return 0;
    }

    void registration()
    {
        printf("\n============== Registration ==============\n");

        User user;
        FILE *userFile,*lastIdFile;
        int lastId=1000;


        lastIdFile = fopen("last_id.txt", "r");
    if (lastIdFile != NULL) {
        fscanf(lastIdFile, "%d", &lastId);
        fclose(lastIdFile);
    }

    user.id = lastId + 1;

        printf("Enter name: ");
        fgets(user.name,sizeof(user.name),stdin);
        printf("Enter age: ");
        scanf("%d",&user.age);
        fflush(stdin);
        printf("Enter number: ");
        fgets(user.number,sizeof(user.number),stdin);
        printf("Enter nationality: ");
        fgets(user.nationality,sizeof(user.nationality),stdin);
        printf("Enter present address: ");
        fgets(user.present_address,sizeof(user.present_address),stdin);

        char filename[20];
    sprintf(filename, "user_%d.txt", user.id);

    userFile = fopen(filename, "w");
    if (userFile == NULL) {
        printf("Error : Creating user file.\n");
        return;
    }

        fprintf(userFile,"Name: %s",user.name);
        fprintf(userFile,"Age: %d\n",user.age);
        fprintf(userFile,"Number: %s",user.number);
        fprintf(userFile,"Nationality: %s",user.nationality);
        fprintf(userFile,"Present Address: %s",user.present_address);
        fprintf(userFile,"\n");

        fclose(userFile);

        lastIdFile = fopen("last_id.txt", "w");
    fprintf(lastIdFile, "%d", user.id);
    fclose(lastIdFile);

    printf("\n===============User created successfully with ID %d.===============\n", user.id);

    }
    void addcontact()
    {
        printf("\n============== Add Contact ==============\n");
        emergency_contact person;

        int id;
        char filename[20];

        printf("Enter your ID: ");
        scanf("%d",&id);
        fflush(stdin);

        sprintf(filename,"contact_%d.txt",id);

        FILE *contactFile;
        contactFile=fopen(filename,"a");
        if(contactFile==NULL)
        {
            printf("File do not exist!!!");
        }

        printf("Enter relationship with him/her: ");
        fgets(person.relation,sizeof(person.relation),stdin);
        printf("Enter name: ");
        fgets(person.name,sizeof(person.name),stdin);
        printf("Enter number: ");
        fgets(person.emergencyContact,sizeof(person.emergencyContact),stdin);
        printf("Enter present address: ");
        fgets(person.presentlocation,sizeof(person.presentlocation),stdin);


        fprintf(contactFile,"Relation: %s",person.relation);
        fprintf(contactFile,"Name: %s",person.name);
        fprintf(contactFile,"Number: %s",person.emergencyContact);
        fprintf(contactFile,"Present Address: %s",person.presentlocation);
        fprintf(contactFile,"\n");

        fclose(contactFile);
    }
    void showcontact()
    {
printf("\n============== Show Contact ==============\n");
        char information[max];

        int id;
        char filename[200];

        printf("Enter your id: ");
        scanf("%d",&id);

        sprintf(filename,"contact_%d.txt",id);


        FILE *contactFile;
        contactFile=fopen(filename,"r");
        if(contactFile==NULL)
        {
            printf("File do not exist!!!");
            return;
        }

         while (fgets(information, sizeof(information), contactFile)) {
            printf("%s", information);
         }

        fclose(contactFile);
        }
    void showuser()
    {
printf("\n============== Show User ==============\n");
        char userinformation[max];

        int id;
        char filename[200];

        printf("Enter your id: ");
        scanf("%d",&id);

        sprintf(filename,"user_%d.txt",id);


        FILE *userFile;
        userFile=fopen(filename,"r");
        if(userFile==NULL)
        {
            printf("File do not exist!!!");
            return;
        }

         while (fgets(userinformation, sizeof(userinformation), userFile) ) {
            printf("%s", userinformation);
         }

        fclose(userFile);
        }
    void panicbutton()
    {
        printf("\n============== !!!ALERT!!! ==============\n");
        char userinformation[max];

        int id;
        char filename[200];

        printf("Enter your id: ");
        scanf("%d",&id);

        sprintf(filename,"user_%d.txt",id);


        FILE *userFile;
        userFile=fopen(filename,"r");
        if(userFile==NULL)
        {
            printf("File do not exist!!!");
            return;
        }

         while (fgets(userinformation, sizeof(userinformation), userFile) ) {
            printf("%s", userinformation);
         }

        fclose(userFile);

        printf("\n");
        printf("User data & Live location is sending to Emergency Contacts given below!!!\n");
        printf("\n");

        char information[max];

        char filename1[200];

        sprintf(filename1,"contact_%d.txt",id);


        FILE *contactFile;
        contactFile=fopen(filename1,"r");
        if(contactFile==NULL)
        {
            printf("File do not exist!!!");
            return;
        }

         while (fgets(information, sizeof(information), contactFile)) {
            printf("%s", information);
         }

        fclose(contactFile);

    }

