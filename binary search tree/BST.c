#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
// dugum yapimizi olustururuz.
{
    int veri;
    // veriyi tan�mlar�z.
    struct dugum *sol;
    //sol cocugu isaret eden pointer.
    struct dugum *sag;
    //sag cocugu isaret eden pointer.
} dugum;

dugum *olustur(dugum *, int);
//deger girdigimiz zaman bize dugum olusturucak.

void Inorder(dugum *kok)

{
  if( kok != NULL)
//kok eger bos degilse asaagidaki islemleri yaptiririz.
  {
    Inorder(kok->sol);
// koku sol cocugu atariz.
    printf(" %d ",kok->veri);
// koku veriye atay�p yazdiriririz.
    Inorder(kok->sag);
//koke sag cougu atariz
  }
}

void Preorder(dugum *kok)
//Preorder fonksiyonumuz
{
  if( kok != NULL)
//kok eger bos degilse asaagidaki islemleri yaptiririz.
  {
    printf(" %d ",kok->veri);
// koku veriye atay�p yazdiriririz.
    Preorder(kok->sol);
// koku sol cocugu atariz.
    Preorder(kok->sag);
// koke sag cocugu atariz.
  }
}

void Postorder(dugum *kok)
//Postorder fonksiyonumuz
{
  if( kok != NULL)
//kok eger bos degilse asaagidaki islemleri yaptiririz.
  {
    Postorder(kok->sol);
// koke sol cocugu atariz.
    Postorder(kok->sag);
// koke sag cocugu atariz.
    printf(" %d ",kok->veri);
// koku veriye atay�p yazdiriririz.
  }
}

void main()
{ int islemler;
//islemler diye bir deger tan�mlad�k switch case de kullan�caz
  dugum *kok=NULL;
// parametreleri null yapariz.
  int veri,dugumsayisi1,i,f,dugumsayisi2;
// degerlerimizi tanimladik.


  kok=NULL;
// null degerini koke atad�k
  printf("\nEklemek istediginiz dugum sayisini giriniz: ");
  scanf("%d",&dugumsayisi1);
  // dugum sayisini aldik.
  for(i=0;i<dugumsayisi1;i++)
// kullanici kac tane d�g�m istiyorsa o kadar girsin diye dongu yaptik
  {
    printf("\n %d. dugum : ",i+1);
    scanf("%d",&veri);
//dugumlerizi tek tek aldik
    kok=olustur(kok,veri);
//girdigimiz verilerile ikili arama agac� olusturcagiz.
  }
  printf("\nIKILI ARAMA AGACI OLUSTURULDU\n");

  printf("\n Inorder siralanisi : ");
  Inorder(kok);
  //inorder siralanisi
  printf("\n Preorder siralanisi : ");
  Preorder(kok);
  //preorder siralanisi
  printf("\n Postorder siralanisi : ");
  Postorder(kok);
  //postorder siralanisi
printf("\n\n");
printf( " \n Secmek istediginiz islem \n\n 1:veri ekleme \n\n 2:Islemi bitirme");
// switch casemiz icin islem secmesi yaptik
printf( " \n\n Islemi seciniz:");
// 1 ve ya 2 yi secerek isleme devam edecek
scanf("%d",&islemler);

switch(islemler)
{

    case 1:
 //eklemek istedigi dugum sayisini giricek.
printf("\n Sonradan eklemek istediginiz dugum sayisini giriniz : ");
  scanf("%d",&dugumsayisi2);
  for(f=0;f<dugumsayisi2;f++)
    // for dongusune aldik yine cunku istedigi kadar veri girebilsin diye
  {
printf("\n eklemek istediginiz %d. dugum : ",f+1);
    scanf("%d",&veri);
kok=olustur(kok,veri);
//verilerini girdi ve ikili arama agimizi olusturuyoruz.
  }
  printf("\nIKILI ARAMA AGACI TEKRARDAN OLUSTURULDU\n");
  printf("\n Inorder siralanisi : ");
  Inorder(kok);
  printf("\n Preorder siralanisi : ");
  Preorder(kok);
  printf("\n Postorder siralanisi : ");
  Postorder(kok);
  // siralanislarini yazdik
  break;
  // break kullandik cunli asagidk islemi yazmasin diye

    case 2:
    printf("\n Isleminiz bitmistir.");
// islemin bittigini belirtip programi durdurmamizi saglayan yapi
       break;
}

}

dugum *olustur(dugum *kok, int veri)
// dugum olusturma fonksiyonu
{
  if(kok == NULL)
//kokumuz bossa yerlestirme islemi yapicaz
  {
    kok=(dugum *)malloc(sizeof(dugum));
    kok->sol= kok->sag = NULL;
    kok->veri=veri;
    return kok;
  }
  else if( veri < kok->veri )
//eger veri degeri koke atanan verinin degerinden kucukse
    kok->sol=olustur(kok->sol,veri);
//fonksiyonu yazdiriyor.degeri sola olusturuyor
  else if( veri > kok->veri )
//eger veri degeri koke atanan verinin degerinden kucukse
    kok->sag=olustur(kok->sag,veri);
//fonksiyonu yazdiriyor.degeri saga olusturuyor
//kisa bir aciklama yapicak olursam hangi d�g�m bos olan ugun yere yerlest�r�yor
  else
  {
//ikisinde olmadigi durum onceki dugumlerle esit olmadurumudur bu durumda asag�daki
//yaziyi yazdiriyor

    printf(" AYNI DUGUMU GIRMISTINIZ TEKRAR GIRINIZ !!!");
    printf("\n TEKRAR GIRILEN DUGUM : ");
    scanf("%d",&veri);
    kok=olustur(kok,veri);
//tekrardan veri girmemizi istiyor.
}
  return(kok);

}
