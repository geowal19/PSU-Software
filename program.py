import os
import platform
import sys

device = ''
file = ''
erase = False

for i in range(len(sys.argv)):

	arg = sys.argv[i]

	if '-d' in arg:

		try:
			device = str(sys.argv[i + 1])

		except:
			print(f'{arg} needs an argument!')
			quit()

	if '-f' in arg:

		try:
			file = str(sys.argv[i + 1])

		except:
			print(f'{arg} needs an argument!')
			quit()

	if '-e' in arg:

		erase = True




if not file and not erase:
	print('The input file or erase needs defining.')
	quit()

if not device:
	print('The device needs defining.')
	quit()





if 'psu' in device:
	device = 'STM32H743ZI'




cmd = 'JLink'

if 'Darwin' in platform.system():
	cmd += 'exe'

if 'Windows' in platform.system():
	cmd += '.exe'

if 'Linux' in platform.system():
	cmd += 'Exe'





# Create the command script
f = open('jlink_script.jlink', 'w+')
if erase:
	f.write(f'r\nerase\nr\nq\n')
else:
	f.write(f'r\nloadfile {file}\nr\nq\n')
f.close()




os.system(cmd + f' -device {device} -if SWD -speed 4000 -jtagconf -1,-1 -autoconnect 1 -CommanderScript jlink_script.jlink')
