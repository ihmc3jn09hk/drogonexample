# drogonexample

Clone the repository and run the setup script. WARNING!
```bash
$ chmod +x
$ sudo setup.sh
```

After setting up drogon, then
```bash
$ export PATH=</path/to/drogon>/install/bin:$PATH
```

Build the project
```bash
$ cd build
$ cmake ..
$ make -j8
```

If everything runs smoothly, then
```bash
$ sudo ./example
```

Then open a brower and type in the url "http://127.0.0.1/RESTApi/WhatEverThing"
Check the Terminal running the "./example"

For modifying the functionality, you will need to modify the files in "drogonexample/controller", e.g. RESTApi.cc
```c++
...
		std::string command{"echo HELO"};	//The command you would like to run

		if ( "Autoware.command.code1" == action ){
				command = "echo Command A";
		} else if ( "Autoware.command.code2" == action ){
				command = "echo Command B";
		} else {
				command = "echo Command C";
		}
...
```
