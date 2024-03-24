#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct  login{

    char fname[100];
    char lname[100];
    char username[20];
    char password[20];
 };

 typedef struct Account{

    char accountName[40];
    char accountNumber[20];
    char DateOfBirth[15];
    char address[50];
    char contactNum[15];
    float accountBalance;
};

void menu();
void createAccount();
void displayAllAccount();
void updateAccount();
void deleteAccount();
void searchAccount();

 int main()
 {
     int menu;
     printf("\n============================================= \n");
     printf("==\t\t\t\t\t   ==  \n");
     printf("==  Selamat datang di program teller bank  == \n");
     printf("==\t\t\t\t\t   == \n");
     printf("============================================= \n\n");
     printf("input angka 1 untuk registrasi \ninput angka 2 untuk login\n\n");
     printf("input angka = ");
     scanf("%d",&menu);
     if(menu == 1)
     {
         system("CLS");
         regis();
     }
     else if(menu == 2)
     {
         system("CLS");
         login();
     }
     else
     {
         printf("Opsi tidak valid\n");
         system("PAUSE");
         system("CLS");
         main();
     }

 }

 void regis()
 {
     // kasih FILE di depan
    FILE *log;
    log=fopen("LOGIN.txt","a");
    struct login l;

    printf("Nama Depan: ");scanf ("%s",l.fname);
    printf("Nama Belakang: ");scanf (" %s",l.lname);

    // ngga typo kan (ussername -> username)
    printf("Username: ") ;scanf ("%s",l.username);

    // sama (pasword -> password)
    printf("Password: ") ;scanf ("%s",l.password) ;

    // kasih sizeof di argumen kedua (l) -> sizeof(l)
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\nUsername = UserID\n");
    printf("\nSilahkan Login Menggunakan Username dan Password...\n") ;
    system("PAUSE");
    system("CLS");
    main();
 }

 void login()
 {
    char username[20],password[20];
    FILE *log;
    log=("LOGIN.txt","a");
    struct login l;
    printf("\nUserID: ");
    scanf("%s",&username);
    printf("\nPassword: ");
    scanf("%s",&password);
    system("CLS");
    while((&l,sizeof(l),1,log))
    {
        if((username,l.username)==0 && (password,l.password)==0)
        {
            printf("\nLogin Sukses\n");
            system("PAUSE");
            system("CLS");
            menu();
        }
        else
        {
            printf("ID Dan Password Salah\n");
            system("PAUSE");
            system("CLS");
            main();
        }
    }
    close();

 }

void menu()
{
    char option;

    // kurang 6 (option !=) -> (option != 6)
    while (option != 6)
    {
    system("CLS");
    printf("========Selamat Datang di Program Teller Bank========\n\n");
    printf("Menu Utama\n\n");
    printf("1. Buat akun \n");
    printf("2. Perbaruhi akun \n");
    printf("3. Hapus akun \n");
    printf("4. Informasi akun \n");
    printf("5. List nasabah \n");
    printf("6. Logout");
    printf("\n\n");
    printf("Masukkan Opsi (1/2/3/4/5/6): ");

        scanf(" %c", &option);
        switch(option)
        {
            //typo nama prosedur Acount -> Account
          case 1: createAccount();
                    break;
                    // typo (;) -> (:)
          case 2: updateAccount();
                    break;
          case 3: deleteAccount();
                    break;
                    // sama (;) -> (:)
          case 4: searchAccount();
                    break;
          case 5: displayAllAccount();
                    break;
          case 6: exit;
                    break;
          default : system("cls");
                    printf("Masukkan Opsi (1/2/3/4/5/6): ");
                    break;
        }
    }
}

void createAccount()
{
    // kasih variable file (FILE *) -> (FILE *fileOne), sama +ab nya coba ganti ntar
    FILE *fileOne = fopen("accountInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    // kurang struct (Account accountInformation;) -> (struct Account accountInformation;)
    struct Account accountInformation;

    system("cls");

    printf("====== Bikin Akun Baru ======\n");
    printf("\nMasukkan Nama : ");
    getchar();
    gets(accountInformation.accountName);
    printf("\nMasukkan Nomor Kartu(5 digit) : ");
    gets(accountInformation.accountNumber);
    printf("\nMasukkan Tanggal lahir (dd/mm/yy): ");

    // kurang titik (.) (accountInformationDateOfBirth) -> (accountInformation.DateOfBirth)
    gets(accountInformation.DateOfBirth);
    printf("\nMasukkan Alamat : ");
    gets(accountInformation.address);
    printf("\nMasukkan Nomor Hp : ");
    gets(accountInformation.contactNum);
    printf("\nMasukkan Jumlah UANG : Rp ");
    scanf("%f", &accountInformation.accountBalance);

    // kurang ampersand (&)
    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
    printf("\nAkun berhasil dibuat.....\n");
    system("PAUSE");

    // kurang variable file (fclose();) -> (fclose(fileOne);)
    fclose(fileOne);
}

void displayAllAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "b");

    // kurang struct (Account accountInformation, temp[sizeof(accountInformation)];) -> (struct Account accountInformation, temp[sizeof(accountInformation)];)
    struct Account accountInformation, temp[sizeof(accountInformation)];

    int choice, flag = 1;
    char searchAccountNumber[20], searchName[50];

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== List Akun Nasabah======\n");

    printf("\n1.Sort Berdasarkan Nomor");
    printf("\n2.Sort Berdasarkan Nama");
    printf("\n\nMasukkan Pilihan (1/2) : ");
    scanf("%d", &choice);
    if (choice == 1)
    {

        system("cls");
        printf("====== List Akun Nasabah======\n");

        int i = 0,j = 0;
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            flag++;

            // ini gatahu, coba temp[] nya isi j kalo salah, atau kasih + 1 juga, atau dua dua nya, atau - 1
            temp[i] = accountInformation;

        }
        int n = flag;
        for (i = 1; i < n; i++)
        {

            // kurang struct (Account key = temp[i];) -> (struct Account key = temp[i];)
            struct Account key = temp[i];
            j = i - 1;
            while (j >= 0 && atoi(temp[i].accountNumber) > atoi(key.accountNumber))
            {
                temp[j + 1] = temp[j];
                j =  - 1;
            }

            // kurang end statement (;) (temp[j + 1] = key) -> (temp[j + 1] = key;)
            temp[j + 1] = key;
        }
        for(i ; i < flag; i++)
        {
            printf("\nNama Akun: %s\n", temp[i].accountName);
            printf("\nNomor Kartu : %s\n", temp[i].accountNumber);
            printf("\nTanggal Lahir : %s\n", temp[i].DateOfBirth);
            printf("\nAlamat : s\n", temp[i].address);
            printf("\nNomor HP : %s\n", temp[i].contactNum);
            printf("\nSaldo : %.2f\n", temp[j].accountBalance);
            printf("\n---------------------------------------------------\n");
        }
        if (flag == 1)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("====== List Akun Nasabah======\n");
        int i = 0,j = 0;
        while ((&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            flag++;
            temp[i++] = accountInformation;

        }
        int n = flag;

        // kurang struct (Account temp2;) -> (struct Account temp2;)
        struct Account temp2;
        for(i = 0; i < n; i++)
          for(j = i+1; j < n; j++)
          {
              // typo (if(strcmp(temp[i].accountNama,temp[j].accountName)>0)) -> (if(strcmp(temp[i].accountName,temp[j].accountName)>0))
               if(strcmp(temp[i].accountName,temp[j].accountName)>0)
               {
                  temp2 = temp[i];
                    // salah variabel (x) -> (i)
                  temp[j] = temp[i];
                  // sama (temp100) -> (temp2)
                  temp[j] = temp2;
               }
          }
        for(i = 0; i < flag; i++)
        {
            printf("\nNama Akun: %s\n", temp[i].accountName);
            printf("\nNomor Kartu : %s\n", temp[i].accountNumber);
            printf("\nTanggal Lahir : %s\n", temp[i].DateOfBirth);
            printf("\nAlamat : %s\n", temp[i].address);
            printf("\nNomor HP : %s\n", temp[i].contactNum);
            printf("\nSaldo : %.2f\n", temp[i].accountBalance);
            printf("\n---------------------------------------------------\n");
        }
        if (flag == 0)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else
    {
        printf("\nOpsi tidak valid\n");
    }

    fclose(fileOne);

    system("PAUSE");

}

void updateAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    // kurang struct (Account accountInformation, tempInformation;) -> (struct Account accountInformation, tempInformation;)
    struct Account accountInformation, tempInformation;

    int choice, flag = 0;

    //typo NAILL / NALL -> NULL, OR -> ||
    if (fileOne == NULL || temp == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Perbaharui Informasi Akun ======\n");

    printf("\nMasukkan Nomor Kartu: ");
    getchar();
    gets(tempInformation.accountNumber);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcpy(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        {
            flag++;
            printf("\n1.Perbarui Nama Akun");
            printf("\n2.Perbarui Tanggal Lahir");
            printf("\n3.Perbarui Alamat");
            printf("\n4.Perbarui No HP");
            printf("\n\nMasukkan Opsi (1/2/3/4/): ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\nNama Baru Akun: ");

                // yang bawah comment dulu, coba pakai fgets di line 343
                //getstring();
                fgets(tempInformation.accountName, 40, stdin);
                strcmp(accountInformation.accountName, tempInformation.accountName);

                // bukan plural fwrites -> fwrite
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 2)
            {
                printf("\nTanggal Lahir Baru: ");
                getchar();
                gets(tempInformation.DateOfBirth);
                strcpy(accountInformation.DateOfBirth, tempInformation.DateOfBirth);

                // syntax bukan plural fwrites -> fwrite
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 3)
            {
                printf("\nAlamat Baru: ");
                getchar();
                gets(tempInformation.address);
                strcpy(accountInformation.address, tempInformation.address);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else if (choice == 4)
            {
                printf("\nNomor HP Baru: ");
                getchar();
                gets(tempInformation.contactNum);
                strcpy(accountInformation.contactNum, tempInformation.contactNum);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\nPerbaharui Akun Berhasil!\n\n");
            }
            else
            {
                printf("\nTidak ada di dalam opsi.\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");

    if (flag == 0)
    {
        printf("\nAkun Tidak Ditemukan\n");
    }

    system("PAUSE");
}

void deleteAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    // kurang struct
    struct Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Hapus Akun ======\n");

    printf("\nMasukkan Nomor Kartu(5 Digit) : ");
    getchar();
    gets(tempInformation.accountNumber);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        {
            flag++;
            printf("\nKonfirmasi Hapus Akun!\n\n1.Ya\n2.Kembali\nMasukkan pilihan (1/2): ");
            scanf("%d", &choice);

            // salah variable (pilihlah_coy) -> choice
            if (choice == 1)
            {
                printf("\nAkun Berhasil Dihapus!\n\n");
            }
            else if (choice == 2)
            {
                printf("\nAkun tidak jadi dihapus\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
            else
            {
                printf("\nOpsi tidak valid\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");

    if (flag == 0)
    {
        printf("\nAkun Tidak Ditemukan\n");
    }

    system("PAUSE");
}

void searchAccount()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");

    // kurang struct
    struct Account accountInformation;

    int choice, flag = 0;
    char searchAccountNumber[20], searchName[50];

    if (fileOne == NULL)
    {
        printf("\nError !\n");
    }

    system("cls");

    printf("====== Cari Informasi Akun ======\n");

    printf("\n1.Cari Berdasarkan Nomor");
    printf("\n2.Cari Berdasarkan Nama");
    printf("\n\nMasukkan Pilihan (1/2) : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("====== Cari Informasi Akun ======\n");
        printf("\nMasukkan Nomor Akun : ");
        getchar();
        gets(searchAccountNumber);
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            if (strcmp(accountInformation.accountNumber, searchAccountNumber) == 0)
            {
                flag++;
                printf("\nNama Akun: %s\n", accountInformation.accountName);
                printf("\nNomor Kartu : %s\n", accountInformation.accountNumber);
                printf("\nTanggal Lahir : %s\n", accountInformation.DateOfBirth);
                printf("\nAlamat : %s\n", accountInformation.address);
                printf("\nNomor HP : %s\n", accountInformation.contactNum);
                printf("\nSaldo : %.2f\n", accountInformation.accountBalance);
                printf("\n---------------------------------------------------\n");
            }
        }
        if (flag == 0)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\====== Cari Informasi Akun ======\n");
        printf("\nMasukkan Nama Akun : ");

        // line 529 coba comment dulu, line 530 pakai fgets
        //getchr();
        fgets(searchName, 40, stdin);

        // kelebihan b fbread -> fread
        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            // sama dengan nya kelebihan === -> ==
            if (stricmp(accountInformation.accountName, searchName) == 0)
            {
                flag++;
                printf("\nNama Akun: %s\n", accountInformation.accountName);
                printf("\nNomor Kartu : %s\n", accountInformation.accountNumber);
                printf("\nTanggal Lahir : %s\n", accountInformation.DateOfBirth);
                printf("\nAlamat : %s\n", accountInformation.address);
                printf("\nNomor HP : %s\n", accountInformation.contactNum);
                printf("\nSaldo : %.2f\n", accountInformation.accountBalance);
                printf("\n---------------------------------------------------\n");
            }
        }
        if (flag = 11)
        {
            printf("\nAkun Tidak Ditemukan\n");
        }
    }
    else
    {
        printf("\nOpsi tidak valid\n");
    }

    fclose(fileOne);

    system("HIU");
}
