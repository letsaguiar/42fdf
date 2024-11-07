#include "fdf.h"
#include <assert.h>

void    should_return_true_for_a_valid_map(void)
{
    t_bool  result = map_validate("maps/3x3.fdf");
    assert(result == TRUE);
}

void    should_return_false_for_an_invalid_map(void)
{
    t_bool  result = map_validate("maps/invalid.fdf");
    assert(result == FALSE);
}

int main(void)
{
    should_return_true_for_a_valid_map();
    should_return_false_for_an_invalid_map();
    return (0);
}