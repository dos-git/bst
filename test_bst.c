#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "bst.h"

int Return_one(){
return 1;
}

void test_Return_One(){

    CU_ASSERT(Return_one()== 1);
}

int init_suite(void)  { return 0; }
int clean_suite(void) { return 0; }

int main(){

     CU_pSuite pSuite = NULL;

   /* Initialize CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* Add suite to registry */
   pSuite = CU_add_suite("Basic_Test_Suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
      }

   /* add test to suite */
   if ((NULL == CU_add_test(pSuite, "test_Return_One", test_Return_One)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run tests using Basic interface */
   CU_basic_run_tests();

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
