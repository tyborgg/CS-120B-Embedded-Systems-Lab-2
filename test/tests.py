# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

#tests = [ {'description': 'This test will run first.',
#    'steps': [ {'inputs': [('PINA',<val>)], 'iterations': 1 } ],
#    'expected': [('PORT',<val>)],
#    },
#    {'description': 'This test will run second.',
#    'steps': [ {'inputs': [('PIN', <val>)],'iterations': 1}, # Set PIN to val then run one iteration
#        {'inputs': [('PIN',<val>)], 'time': 300 }, # Set PIN to val then run 300 ms
#        {'inputs': [('PIN',<val>)], 'iterations': 1, 'expected': [('PORT',<val>)]}, 
#        {'inputs': [('PIN',<val>)], 'time': 600}, ],
#    'expected': [('PORT',<val>)],
#    },
#    ]
#
# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['<function>::<static-var>','PORTB']

tests = [ {'description': 'Testing PORTD',
    'steps': [ {'inputs': [('PINA',0x40)], 'iterations': 5 },
	       {'inputs': [('PINB',0x40)], 'iterations': 5 },
	       {'inputs': [('PINC',0x40)], 'iterations': 5 }],
    'expected': [('PORTD',0x31)],
    },
    {'description': 'Testing PORTD2',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 },
	       {'inputs': [('PINB',0x23)], 'iterations': 5 },
	       {'inputs': [('PINC',0x55)], 'iterations': 5 }],
    'expected': [('PORTD',0x1E)],
    },
    {'description': 'Testing PORTD3',
    'steps': [ {'inputs': [('PINA',0x32)], 'iterations': 5 },
	       {'inputs': [('PINB',0x3C)], 'iterations': 5 },
	       {'inputs': [('PINC',0x46)], 'iterations': 5 }],
    'expected': [('PORTD',0x2D)],
    },
    {'description': 'Testing PORTD4',
    'steps': [ {'inputs': [('PINA',0x10)], 'iterations': 5 },
	       {'inputs': [('PINB',0x18)], 'iterations': 5 },
	       {'inputs': [('PINC',0x45)], 'iterations': 5 }],
    'expected': [('PORTD',0x18)],
    },	
    {'description': 'Testing PORTD5',
    'steps': [ {'inputs': [('PINA',0x38)], 'iterations': 5 },
	       {'inputs': [('PINB',0x3C)], 'iterations': 5 },
	       {'inputs': [('PINC',0x55)], 'iterations': 5 }],
    'expected': [('PORTD',0x22)],
    },
    ]
#watch = ['PORTB']
