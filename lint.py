import glob
import subprocess
import os
import sys

print(f'Running on {os.name}')

src_dir = 'Src'
inc_dir = 'Inc'

# A heavy lint?
if len(sys.argv) > 1:
	if sys.argv[1] == '--heavy':
		src_dir = '**'
		inc_dir = '**'

# Unix
if(os.name == 'posix'):
	conf_path = "/Users/georgewaller/Documents/ElectronicsProjects/Uncrustify/u_cnf.cfg"

# Windows
if(os.name == 'Windows'):
	conf_path = "C:/Users/George/Documents/ElectronicsProjects/Uncrustify/u_cnf.cfg"

# Fish on Windows
if(os.name == 'nt'):
	conf_path = "C:/Users/George/Documents/ElectronicsProjects/Uncrustify/u_cnf.cfg"

for filename in glob.iglob(src_dir + '/**/*.c', recursive=True):
	subprocess.run(["uncrustify", "-c", conf_path, "--no-backup", filename])

for filename in glob.iglob(inc_dir + '/**/*.h', recursive=True):
	subprocess.run(["uncrustify", "-c", conf_path, "--no-backup", filename])

print("All done, mate.")