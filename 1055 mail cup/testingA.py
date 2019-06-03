import unittest
from unittest.mock import patch



class TestA(unittest.TestCase):
    def test10(self):
        




    def setUp(self):
        # raw_input is untouched before test
        assert module_under_test.raw_input is __builtins__.raw_input

    def test_using_with(self):
        input_data = "123"
        expected = int(input_data)

        with patch.object(module_under_test, "raw_input", create=True, 
                return_value=expected):
            # create=True is needed as raw_input is not in the globals of 
            # module_under_test, but actually found in __builtins__ .
            actual = module_under_test.function()

        self.assertEqual(expected, actual)        
