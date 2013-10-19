/*
 * File:   collision_test.c
 * Author: root
 *
 * Created on Oct 7, 2013, 3:27:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../modules/box_collision.h"

/*
 * Simple C Test Suite
 */

void
test1 ()
{

  printf ("First test:\n");
  if (detect_collision (3, 3, 3, 3, 3, 3, 3, 3) != 1)
    printf ("failed. Expecting : 1(TRUE). \n");
  else
    printf ("passed \n");

  printf ("Second test:\n");

  if (detect_collision (99, 99, 3, 3, 3, 3, 3, 3) != 0)
    {
      printf ("failed. Expecting : 0(FALSE). \n");

    }
  else
    printf ("passed.\n");
}

int
main (int argc, char** argv)
{
  printf ("Collision detection tests: \n");
  test1 ();

  return (EXIT_SUCCESS);
}
