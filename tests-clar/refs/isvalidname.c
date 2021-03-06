#include "clar_libgit2.h"

void test_refs_isvalidname__can_detect_invalid_formats(void)
{
	cl_assert_equal_i(false, git_reference_is_valid_name("refs/tags/0.17.0^{}"));
	cl_assert_equal_i(false, git_reference_is_valid_name("TWO/LEVELS"));
	cl_assert_equal_i(false, git_reference_is_valid_name("ONE.LEVEL"));
	cl_assert_equal_i(false, git_reference_is_valid_name("HEAD/"));
	cl_assert_equal_i(false, git_reference_is_valid_name("NO_TRAILING_UNDERSCORE_"));
	cl_assert_equal_i(false, git_reference_is_valid_name("_NO_LEADING_UNDERSCORE"));
	cl_assert_equal_i(false, git_reference_is_valid_name("HEAD/aa"));
	cl_assert_equal_i(false, git_reference_is_valid_name("lower_case"));
	cl_assert_equal_i(false, git_reference_is_valid_name("/stupid/name/master"));
	cl_assert_equal_i(false, git_reference_is_valid_name("/"));
	cl_assert_equal_i(false, git_reference_is_valid_name(""));
}

void test_refs_isvalidname__wont_hopefully_choke_on_valid_formats(void)
{
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/tags/0.17.0"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/LEVELS"));
	cl_assert_equal_i(true, git_reference_is_valid_name("HEAD"));
	cl_assert_equal_i(true, git_reference_is_valid_name("ONE_LEVEL"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/stash"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/remotes/origin/bim_with_3d@11296"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/master{yesterday"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/master}yesterday"));
	cl_assert_equal_i(true, git_reference_is_valid_name("refs/master{yesterday}"));
}
