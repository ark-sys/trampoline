/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1;
	
	result_inst_1 = GetApplicationID();	
	TEST_ASSERT_EQUAL_INT(0, result_inst_1);
	
	ActivateTask(t2);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTest,"AutosarTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTest;
}