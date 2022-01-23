#include <stdio.h>
#include <time.h>
#include <string.h>
int nbre_docs, n, pos, posd;
int nbre_retards = -1;

typedef struct
{
  char nom[40];
  char prenom[40];
} per_ret;

per_ret tar[100];

typedef struct
{
  char nom[40];
  char prenom[40];
  char adresse[40];
  int type;
  int identifiant;
  int nbr_empr;
  char date_emp[50];
} client;

typedef struct
{
  char local[40];
  char titre[40];
  int code;
  int nbre_exp;
  int type;
  char nom_edit[40];
  int jour_edi;
  int mois_edi;
  int anne_edi;
  char nom_aut[40];
  int jour_pub;
  int mois_pub;
  int anne_pub;
  int frequence;
} doc;
client t[100];
doc tab[100];
int verif(int i)
{
  int j = -1;
  do
  {
    j = j + 1;
  } while (t[j].identifiant != t[i].identifiant && j < i);
  if (j >= i)
    return 1;
  else
    return 0;
}
void ajoutDesAdherents()
{
  int test;
  void gestionDesAdhrts();
  n = -1;
retour1:
  n++;
  printf("donner le nom :");
  scanf("%s", &t[n].nom);
  printf("donner le prenom :");
  scanf("%s", &t[n].prenom);
  printf("donner l'adresse :");
  scanf("%s", &t[n].adresse);
  printf("donner le type :");
  printf("(1) pour etudiant|(2) pour enseignant|(3) pour visiteur \n");
  scanf("%d", &t[n].type);
  do
  {
    printf("donner l' identifiant (unique) :");
    scanf("%d", &t[n].identifiant);
  } while (verif(n) == 0);
  printf("tapez 3 pour quitter :");
  printf("tapez 4 pour continuer :");
  scanf("%d", &test);
  printf("---------------------------------------------------\n");
  if (test == 3)
    gestionDesAdhrts();
  else
    goto retour1;
}
void rechercheDesAdherents()
{
  void gestionDesAdhrts();
  int choix, ident_a_chercher, type_a_chercher;
  char nom_a_chercher[40];
  printf("donner le critére de recherche:\n");
  printf("1.selon l'identifiant\n");
  printf("2.selon le nom \n");
  printf("3.selon le type \n");
  printf("donner votre choix : \n");
  scanf("%d", &choix);
  printf("---------------------------------------------------\n");
  switch (choix)
  {
    do
    {
    case 1:
      printf("donner lidentifiant a chercher : \n");
      scanf("%d", &ident_a_chercher);
      printf("--------------------------------------------------- \n");
      for (int i = 0; i < n; i++)
      {
        if (t[i].identifiant == ident_a_chercher)
        {
          printf("%s %s est de type %d et a l'identifiant qui vous cherchez\n", t[i].nom, t[i].prenom, t[i].type);
          pos = i;
          break;
        }
        else
          pos = -1;
      }
      break;
    case 2:
      printf("donner le nom a chercher : \n");
      scanf("%s", &nom_a_chercher);
      printf("---------------------------------------------------\n ");
      for (int i = 0; i < n; i++)
      {
        if (strcmp(t[i].nom, nom_a_chercher) == 0)
        {
          printf("%s %s est de type %d et a le nom qui vous cherchez\n", t[i].nom, t[i].prenom, t[i].type);
          break;
        }
        else
          pos = -1;
      }
      break;

    case 3:
      printf("donner le type a chercher : \n");
      scanf("%d", &type_a_chercher);
      printf("---------------------------------------------------");
      for (int i = 0; i < n; i++)
      {
        if (t[i].type == type_a_chercher)
        {
          printf("%s %s est de type %d \n", t[i].nom, t[i].prenom, t[i].type);
          break;
        }
        else
          pos = -1;
      }
      break;

    default:
      printf("le choix est incorrect ! ");
      break;

    } while (choix != 0);
  }
  if (pos == -1)
    printf("cet utilisateur n'existe pas ");
  printf("---------------------------------------------------\n");
  gestionDesAdhrts();
}
void affiche()
{
  void gestionDesAdhrts();
  int test;
  for (int i = 0; i < n; i++)
  {
    printf("%s %s (de type %d)\n", t[i].nom, t[i].prenom, t[i].type);
  }
  printf("tapez 3 pour quitter :");
  scanf("%d", &test);
  printf("---------------------------------------------------\n");
  if (test == 3)
    gestionDesAdhrts();
  gestionDesAdhrts();
}
void modifierDesAdhs()
{
  int ident_a_chercher, choix;
  void gestionDesAdhrts();
  printf("donner l identifiantifiant de l adherent a modifier :\n");
  scanf("%d", &ident_a_chercher);
  for (int i = 0; i < n; i++)
  {
    if (t[i].identifiant == ident_a_chercher)
    {
      printf("%s %s de type %d est l adherents qui vous voulez modifier \n", t[i].nom, t[i].prenom, t[i].type);
      pos = i;
    }
  }
retour1:
  printf("vous voulez modifier ? :\n");
  printf("1.Le nom : \n");
  printf("2.Le prenom : \n");
  printf("3.L adresse: \n");
  printf("4.Le type : \n");
  printf("donner votre choix :\n");
  scanf("%d", &choix);
  switch (choix)
  {
    do
    {
    case 1:
      printf("donner le nom:\n");
      scanf("%s", &t[pos].nom);
      printf("tapez 1 pour continuer les modifications : \n");
      printf("tapez 2 pour Quitter : \n");
      scanf("%d", &choix);
      if (choix == 1)
        goto retour1;
      else
        gestionDesAdhrts();
      break;

    case 2:
      printf("donner le prenom :\n");
      scanf("%s", &t[pos].prenom);
      printf("tapez 1 pour continuer les modifications : \n");
      printf("tapez 2 pour Quitter : \n");
      scanf("%d", &choix);
      if (choix == 1)
        goto retour1;
      else
        gestionDesAdhrts();
      break;

    case 3:
      printf("donner l adresse:\n");
      scanf("%s", &t[pos].adresse);
      printf("tapez 1 pour continuer les modifications : \n");
      printf("tapez 2 pour Quitter : \n");
      scanf("%d", &choix);
      if (choix == 1)
        goto retour1;
      else
        gestionDesAdhrts();
      break;

    case 4:
      printf("donner le type:\n");
      scanf("%s", &t[pos].type);
      printf("tapez 1 pour continuer les modifications : \n");
      printf("tapez 2 pour Quitter : \n");
      scanf("%d", &choix);
      if (choix == 1)
        goto retour1;
      else
        gestionDesAdhrts();
      break;

    default:
      printf("le choix est incorrect ! ");
      break;

    } while (choix != 0);
  }
}

supprimer()
{
  int ident_a_chercher;
  printf("donner l identifiantifiant de l adherent a supprimer :\n");
  scanf("%d", &ident_a_chercher);
  for (int i = 0; i < n; i++)
  {
    if (t[i].identifiant == ident_a_chercher)
    {
      printf("%s %s de type %d est l adherents qui vous voulez supprimer \n", t[i].nom, t[i].prenom, t[i].type);
      pos = i;
    }
  }
  for (int i = pos; i < n; i++)
  {
    t[i] = t[i + 1];
  }
  n = n - 1;
}

void affichageRetards()
{
  void gestionDesAdhrts();
  if (nbre_retards == -1)
    printf("aucun retardataire pour le moment \n ");
  else
    for (int i = 0; i < nbre_retards; i++)
    {
      printf(" %s %s est en retard \n", tar[i].nom, tar[i].prenom);
    }
  gestionDesAdhrts();
}

void gestionDesAdhrts()
{
  int choix;
  void menu();
  printf("******Gestion des adhrents******\n");
  printf("---------------------------------------------------\n");
  printf("1.Ajout d'un adherents\n");
  printf("2.Recherche d'un adherent\n");
  printf("3.Modification d'un adherent\n");
  printf("4.Supprimation un adherent\n");
  printf("5.Affichage de la liste des adhrents \n");
  printf("6.Affichage de la liste des retardataires \n");
  printf("7.Retour au menu principal\n");
  printf("---------------------------------------------------\n");
  printf("Donner votre choix\n");
  scanf("%d", &choix);
  printf("---------------------------------------------------\n");
  switch (choix)
  {
    do
    {
    case 1:
      ajoutDesAdherents();
      break;

    case 2:
      rechercheDesAdherents();
      break;

    case 3:
      modifierDesAdhs();
      break;

    case 4:
      supprimer();
      break;

    case 5:
      affiche();
      break;

    case 6:
      affichageRetards();
      break;

    case 7:
      menu();
      break;

    default:
      printf("le choix est incorrect ! ");
      break;

    } while (choix != 0);
  }
}
int verifDeplucationDoucments(int i)
{
  int j = -1;
  do
  {
    j = j + 1;
  } while (tab[j].code != tab[i].code && j < i);
  if (j >= i)
    return 1;
  else
    return 0;
}
void ajoutDesDocuments()
{
  int test;
  void gestionDesDocs();
  nbre_docs = -1;
retour1:
  nbre_docs++;
  printf("donner le titre :\n");
  scanf("%s", &tab[nbre_docs].titre);
  printf("donner la localisation salle/rayon :\n");
  scanf("%s", &tab[nbre_docs].local);
  do
  {
    printf("donner le code de doc :\n");
    scanf("%d", &tab[nbre_docs].code);
  } while (verifDeplucationDoucments(nbre_docs) == 0);
  printf("donner le nbre d exemplaire :\n");
  scanf("%d", &tab[nbre_docs].nbre_exp);
  do
  {
    printf("donner le type :");
    printf("(1) livre|(2) pour article |(3) pour magazine \n");
    scanf("%d", &tab[nbre_docs].type);
    printf("---------------------------------------------------\n");
  } while (tab[nbre_docs].type != 1 && tab[nbre_docs].type != 2 && tab[nbre_docs].type != 3);
  if (tab[nbre_docs].type == 1)
  {
    printf("donner le nom de l auteur : \n");
    scanf("%s", &tab[nbre_docs].nom_aut);
    printf("donner votre nom : \n");
    scanf("%s", &tab[nbre_docs].nom_edit);
    printf("donner la date d edition : \n");
    printf("donner le jour:");
    scanf("%d", &tab[nbre_docs].jour_edi);
    printf("donner le mois:");
    scanf("%d", &tab[nbre_docs].mois_edi);
    printf("donner l anne :");
    scanf("%d", &tab[nbre_docs].anne_edi);
  }
  if (tab[nbre_docs].type == 2)
  {
    printf("donner le nom de l auteur : \n");
    scanf("%s", &tab[nbre_docs].nom_aut);
    printf("donner la date de publication : \n");
    printf("donner le jour:");
    scanf("%d", &tab[nbre_docs].jour_pub);
    printf("donner le mois:");
    scanf("%d", &tab[nbre_docs].mois_pub);
    printf("donner l anne :");
    scanf("%d", &tab[nbre_docs].anne_pub);
  }
  if (tab[nbre_docs].type == 3)
  {
    printf("donner la frequence de parution : \n");
    scanf("%d", &tab[nbre_docs].frequence);
  }
  printf("tapez 3 pour quitter :");
  printf("tapez 4 pour continuer :");
  scanf("%d", &test);
  printf("---------------------------------------------------\n");
  if (test == 3)
    gestionDesDocs();
  else
    goto retour1;
}

void rechercheDesDocs()
{
  void gestionDesDocs();
  int type_a_chercher;
retour1:
  printf("donner le type a chercher : \n");
  printf("(1) livre|(2) pour article |(3) pour magazine \n");
  scanf("%d", &type_a_chercher);
  printf("---------------------------------------------------\n");
  switch (type_a_chercher)
  {
  case 1:
    for (int i = 0; i < nbre_docs; i++)
    {
      if (tab[i].type == type_a_chercher)
      {
        printf("%s de %s et edité par %s le  %d / %d /%d \n", tab[i].titre, tab[i].nom_aut, tab[i].nom_edit, tab[i].jour_edi, tab[i].mois_edi, tab[i].anne_edi);
        posd = 1;
      }
    }
    break;

  case 2:
    for (int i = 0; i < nbre_docs; i++)
    {
      if (tab[i].type == type_a_chercher)
      {
        printf("%s de %s et publié le  %d / %d /%d \n", tab[i].titre, tab[i].nom_aut, tab[i].jour_pub, tab[i].mois_pub, tab[i].anne_pub);
        posd = 1;
      }
    }
    break;
  case 3:
    for (int i = 0; i < nbre_docs; i++)
    {
      if (tab[i].type == type_a_chercher)
      {
        printf("%s est une magazine de frequence %d \n", tab[i].titre, tab[i].frequence);
        posd = 1;
      }
    }

    break;

  default:
    printf("le choix est incorrect ! ");
    goto retour1;
    break;
  }
  if (posd != 1)
    printf("ce doc n'existe pas ");
  printf("---------------------------------------------------\n");
  gestionDesDocs();
}

void modifierDoc()
{
  int code_a_chercher, choix;
  void gestionDesDocs();
retour1:
  printf("donner le code du document a modifier :\n");
  scanf("%d", &code_a_chercher);
  for (int i = 0; i < n; i++)
  {
    if (tab[i].code == code_a_chercher)
    {
      printf("%s de type %d est le document qui vous voulez modifier \n", tab[i].titre, tab[i].type);
      pos = i;
    }
  }
  if (tab[posd].type == 1)
  {
    printf("donner votre nom : \n");
    scanf("%s", &tab[posd].nom_edit);
    printf("donner la date d edition : \n");
    printf("donner le jour:");
    scanf("%d", &tab[posd].jour_edi);
    printf("donner le mois:");
    scanf("%d", &tab[posd].mois_edi);
    printf("donner l anne :");
    scanf("%d", &tab[posd].anne_edi);
    printf("tapez 1 pour continuer les modifications : \n");
    printf("tapez 2 pour Quitter : \n");
    scanf("%d", &choix);
    if (choix == 1)
      goto retour1;
    else
      gestionDesDocs();
  }
  if (tab[posd].type == 2)
  {
    printf("donner le nom de l auteur : \n");
    scanf("%s", &tab[posd].nom_aut);
    printf("donner la date de publication : \n");
    printf("donner le jour:");
    scanf("%d", &tab[posd].jour_pub);
    printf("donner le mois:");
    scanf("%d", &tab[posd].mois_pub);
    printf("donner l anne :");
    scanf("%d", &tab[posd].anne_pub);
    printf("tapez 1 pour continuer les modifications : \n");
    printf("tapez 2 pour Quitter : \n");
    scanf("%d", &choix);
    if (choix == 1)
      goto retour1;
    else
      gestionDesDocs();
  }

  if (tab[posd].type == 3)
  {
    printf("donner la frequence de parution : \n");
    scanf("%d", &tab[posd].frequence);
    printf("tapez 1 pour continuer les modifications : \n");
    printf("tapez 2 pour Quitter : \n");
    scanf("%d", &choix);
    if (choix == 1)
      goto retour1;
    else
      gestionDesDocs();
  }
  else
  {
    printf("le choix est incorrecte !! \n");
    goto retour1;
  }
}

supprimerDoc()
{
  int code_a_chercher;
  printf("donner le code du doc a supprimer :\n");
  scanf("%d", &code_a_chercher);
  for (int i = 0; i < nbre_docs; i++)
  {
    if (tab[i].code == code_a_chercher)
    {
      printf("%s de type %d est le document qui vous voulez supprimer \n", tab[i].titre, tab[i].type);
      posd = i;
    }
    if (i >= nbre_docs)
    {
      printf("Il n'existe pas un document avec ce code.\n");
    }
  }
  for (int i = posd; i < nbre_docs; i++)
  {
    tab[i] = tab[i + 1];
  }
  nbre_docs = nbre_docs - 1;
}

void afficheDoc()
{
  void gestionDesDocs();
  int test;
  for (int i = 0; i < nbre_docs; i++)
  {
    printf(" %s  (de type %d) \n", tab[i].titre, tab[i].type);
  }
  printf("tapez une touche pour quitter :");
  scanf("%d", &test);
  printf("---------------------------------------------------\n");
  gestionDesDocs();
}

void gestionDesDocs()
{
  int choix;
  void menu();
  printf("******Gestion des documents******\n");
  printf("---------------------------------------------------\n");
  printf("1.Ajout d'un document\n");
  printf("2.Recherche d'un document\n");
  printf("3.modification d'un document\n");
  printf("4.supprimer un document\n");
  printf("5.afficher la liste de tous les documents\n");
  printf("6.Retour au menu principal\n");
  printf("---------------------------------------------------\n");
  printf("donner votre choix\n");
  scanf("%d", &choix);
  printf("---------------------------------------------------\n");
  switch (choix)
  {
    do
    {
    case 1:
      ajoutDesDocuments();
      break;

    case 2:
      rechercheDesDocs();
      break;

    case 3:
      modifierDoc();
      break;

    case 4:
      supprimerDoc();
      break;

    case 5:
      afficheDoc();
      break;

    case 6:
      menu();
      break;

    default:
      printf("le choix est incorrect ! ");
      break;

    } while (choix != 0);
  }
}

int compare_date(int y, int y1, int m, int m1, int d, int d1)
{
  if (y1 > y)
    return 0;
  else if (y1 = y && m1 > m)
    return 0;
  else if (y1 == y && m1 == m && d1 > d)
    return 0;
  else
    return 1;
}

int retard(int ns)
{
  char dd[50];
  int d, m, y, d1, y1, m1;
  if (t[ns].type == 1 || t[ns].type == 3)
  {
    printf("donner la date de l emprunt : \n ");
    printf("Le jour : \n");
    scanf("%d", &d);
    printf("Le mois : \n");
    scanf("%d", &m);
    printf("L anne : \n");
    scanf("%d", &y);
    struct tm ts = {0};
    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    mktime(&ts);
    strftime(t[ns].date_emp, 50, "%Y-%m-%d", &ts);
    printf("%s", t[ns].date_emp);
    ts.tm_mday += 7;
    mktime(&ts);
    strftime(t[ns].date_emp, 50, "%Y-%m-%d", &ts);
    printf("%s", t[ns].date_emp);
    char cur_time[100];
    time_t t4;
    struct tm *ptm;
    t4 = time(NULL);
    ptm = localtime(&t4);
    strftime(cur_time, 100, "%Y-%m-%d ", ptm);
    sscanf(cur_time, "%d-%d-%d", &y1, &m1, &d1);
    if (compare_date(y, y1, m, m1, d, d1) == 1)
      return 1;
    else
      return 0;
  }
  if (t[ns].type == 2)
  {
    printf("donner la date de l'emprunt : \n ");
    printf("Le jour : \n");
    scanf("%d", &d);
    printf("Le mois : \n");
    scanf("%d", &m);
    printf("L'année : \n");
    scanf("%d", &y);
    struct tm ts = {0};
    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    mktime(&ts);
    strftime(t[ns].date_emp, 50, "%Y-%m-%d", &ts);
    ts.tm_mday += 21;
    char cur_time[100];
    time_t t4;
    struct tm *ptm;
    t4 = time(NULL);
    ptm = localtime(&t4);
    strftime(cur_time, 100, "%Y-%m-%d ", ptm);
    sscanf(cur_time, "%d-%d-%d", &y1, &m1, &d1);
    if (compare_date(y, y1, m, m1, d, d1) == 1)
      return 1;
    else
      return 0;
  }
}

int nbr_max(int p)
{
  if (t[p].type == 1)
  {
    if (t[p].nbr_empr > 2)
      return 1;
    else
      return 0;
  }
  if (t[p].type == 2)
  {
    if (t[p].nbr_empr > 4)
      return 1;
    else
      return 0;
  }
  if (t[p].type == 3)
  {
    if (t[p].nbr_empr > 1)
      return 1;
    else
      return 0;
  }
}

void fiche(int ms, int n)
{
  int d, m, y;
  char dd[50] = "";
  if (t[ms].type == 1 || t[ms].type == 3)
  {
    printf("donner la date de l'emprunt : \n ");
    printf("Le jour : \n");
    scanf("%d", &d);
    printf("Le mois : \n");
    scanf("%d", &m);
    printf("L'année : \n");
    scanf("%d", &y);
    struct tm ts = {0};
    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    mktime(&ts);
    strftime(t[ms].date_emp, 50, "%Y-%m-%d", &ts);
    strcat(dd, t[ms].date_emp);
    ts.tm_mday += 7;
    mktime(&ts);
    strftime(t[ms].date_emp, 50, "%Y-%m-%d", &ts);
    printf("----------------------------------------------------\n");
    printf("* Client: %s %s \n", t[ms].nom, t[ms].prenom);
    printf("* Type: %d \n", t[ms].type);
    printf("* identifiantifiant: %d \n", t[ms].identifiant);
    printf("* document: %s de %s \n", tab[n].titre, tab[n].nom_aut);
    printf("* date d emprunt : %s \n", dd);
    printf("* date de retour : %s  \n", t[ms].date_emp);
    printf("----------------------------------------------------\n");
  }
  if (t[ms].type == 2)
  {
    printf("donner la date de l emprunt : \n ");
    printf("Le jour : \n");
    scanf("%d", &d);
    printf("Le mois : \n");
    scanf("%d", &m);
    printf("L anne : \n");
    scanf("%d", &y);
    struct tm ts = {0};
    ts.tm_mday = d;
    ts.tm_mon = m - 1;
    ts.tm_year = y - 1900;
    mktime(&ts);
    strftime(t[ms].date_emp, 50, "%Y-%m-%d", &ts);
    strcat(dd, t[ms].date_emp);
    ts.tm_mday += 7;
    mktime(&ts);
    strftime(t[ms].date_emp, 50, "%Y-%m-%d", &ts);
    printf("----------------------------------------------------\n");
    printf("* Client: %s %s \n", t[ms].nom, t[ms].prenom);
    printf("* Type: %d \n", t[ms].type);
    printf("* Identifiantifiant: %d \n", t[ms].identifiant);
    printf("* Document: %s de %s \n", tab[n].titre, tab[n].nom_aut);
    printf("* Date d'emprunt : %s \n", dd);
    printf("* Date de retour : %s  \n", t[ms].date_emp);
    printf("----------------------------------------------------\n");
  }
}

void gestionDesEmprts()
{
  int ident_a_chercher, code_a_chercher, choix;
  void menu();
  printf("******Gestion des emprunts******\n");
  printf("---------------------------------------------------\n");
  printf("Voici la liste de tous les adherents : \n");
  for (int i = 0; i < n; i++)
  {
    printf("%s %s (de type %d) avec %d emprunts \n", t[i].nom, t[i].prenom, t[i].type, t[i].nbr_empr);
  }
retour1:
  pos = -1;
  printf("Donner l'identifiantifiant du client svp : \n");
  scanf("%d", &ident_a_chercher);
  for (int i = 0; i <= n; i++)
  {
    if (t[i].identifiant == ident_a_chercher)
    {
      printf("%s %s de type %d est l'dherents avec l'identifiant %d \n", t[i].nom, t[i].prenom, t[i].type, t[i].identifiant);
      pos = i;
    }
  }
  if (pos == -1)
  {
    printf("Identifiant n'existe pas ! \n");
    goto retour1;
  }
  else if (retard(pos) == 1)
  {
    printf("Vous etes en retard emprunt\n");
    nbre_retards = nbre_retards + 1;
    strcat(tar[nbre_retards].prenom, t[pos].prenom);
    strcat(tar[nbre_retards].nom, t[pos].nom);
    menu();
  }
  else if (nbr_max(pos) == 1)
  {
    printf("Vous avez depasser la limite emprunt impossible ! :( \n");
    menu();
  }
  else
  {
  retour3:
    printf("Donner le code du document a emprunter : \n");
    scanf("%d", &code_a_chercher);
    posd = -1;
    for (int i = 0; i <= nbre_docs; i++)
    {
      if (tab[i].code == code_a_chercher)
      {
        printf("%s de %s et edité par %s le  %d / %d /%d est le document a emprunter \n", tab[i].titre, tab[i].nom_aut, tab[i].nom_edit, tab[i].jour_edi, tab[i].mois_edi, tab[i].anne_edi);
        posd = i;
      }
    }
    if (posd == -1)
    {
      printf("le code est incorrect : \n ");
      goto retour3;
    }
    else
    {
      fiche(pos, posd);
      t[pos].nbr_empr = t[pos].nbr_empr + 1;
      tab[posd].nbre_exp = tab[posd].nbre_exp - 1;
    }
  }
retour2:
  printf("Tapez 3 pour un autre emprunt\n");
  printf("Tapez 4 pour quitter \n");
  printf("---------------------------------------------------\n");
  scanf("%d", &choix);
  printf("---------------------------------------------------\n");
  if (choix == 3)
    goto retour1;
  else if (choix == 4)
    menu();
  else
  {
    printf("choix incorrect ! \n");
    goto retour2;
  }
}
void menu()
{
  int choix;
  printf(" ****** BIENVENUE A NOTRE BIBLIOTHEQUE ****** \n");
  printf("1. gestionDesAdherentes\n");
  printf("2. gestionDesDocs\n");
  printf("3. gestionDesEmprts\n");
  printf("4. Quitter\n");
  printf("\n donner votre choix : ");
  scanf("%d", &choix);
  printf("---------------------------------------------------\n");
  switch (choix)
  {
    do
    {
    case 1:
      gestionDesAdhrts();
      break;

    case 2:
      gestionDesDocs();
      break;

    case 3:
      gestionDesEmprts();
      break;

    case 4:
      printf("A la prochaine");
      break;

    default:
      printf("le choix est incorrect ! ");
      break;

    } while (choix != 0);
  }
}
int main()
{
  menu();
  return 0;
}
