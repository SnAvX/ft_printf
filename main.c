#include "libft/libft.h"
#include "include/ft_printf.h"

int main(void)
{
/*	ft_printf("On est le 18");
	ft_printf("")

	printf("\n|----          Debut           ----|\n\n");
	printf("\n               *Mon Printf* \n");
	ft_printf("Ecriture              |Salut a tous bande de batard|\n");
	ft_printf("Avec tirait           |%-4c|\n", 'a');
	ft_printf("Sans tirait           |%4c|\n", 'a');
	ft_printf("Zero * 5 et 3         |%0*d|\n", 5, 3);
	ft_printf("Zero * -5 et 3        |%0*d|\n", -5, 3);
	ft_printf("Point  5 caractere    |%.5s|\n",  "Salut les gens");
	ft_printf("Point 3 67            |%.3d|\n",  67);
	ft_printf("Point 1 67            |%.1d|\n",  67);
	printf("\n|----           Fin            ----|\n\n");

	printf("\n-----------------------------------------------------\n");
	printf("\n                     *Vrais Printf* \n");
	printf("Ecriture              |Salut a tous bande de batard|\n");
	printf("Avec tirait           |%-4c|\n", 'a');
	printf("Sans tirait           |%4c|\n", 'a');
	printf("Zero * 5 et 3         |%0*d|\n", 5, 3);
	printf("Zero * -5 et 3        |%0*d|\n", -5, 3);
	printf("Point  5 caractere    |%.5s|\n",  "Salut les gens");
	printf("Point 3 67            |%.3d|\n",  67);
	printf("Point 1 67            |%.1d|\n",  67);
	printf("\n|----           Fin            ----|\n\n");
	system("leaks a.out") */;
	printf("%.*s", 3, "hello");
	printf("\n");
	ft_printf("%.*s", 3, "hello");
return (0);
}
