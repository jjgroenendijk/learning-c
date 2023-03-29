#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*!
 * \brief create_banner
 * \return a pointer to a string containing the users name
 * \remark getenv("USER") is an system call to get the current username
 * \remark if you are using windows please replace getenv("USER") with "your name"
 */
char * create_banner(void);

/*!
 * \brief output_report
 * \param nr
 */
void output_report (int nr);

int main (void)
{
   for (int i = 1; i <= 3; i++)
      output_report (i);
   return 0;
}

char * create_banner(void)
{
   const char *user = getenv ("USER");
   size_t len = 1 + 2 * 4 + strlen (user) + 1;
   char *b = malloc (len);
   sprintf (b, "\t|** %s **|", user);
   return b;
   free(b);
   b = NULL;
}

void output_report (int nr)
{
   char *banner = create_banner ();
   puts (banner);
   printf ("Number: %d\n", nr);
   printf ("\n");
   free(banner);
   banner = NULL;
}
