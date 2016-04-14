def main():
	startfile = open("STARTUP.txt", 'r')
	shutdownfile = open("SHUTDOWN.txt", 'r')
	outputfile = open("output.txt", 'w')
	start = startfile.readlines()
	shut = shutdownfile.readlines()
	installedPrograms = []
	removedPrograms = []


	
	#Iterates through startup file, if entry not in shutdown:
	#	Add entry to outputfile and removedPrograms List
	for i in start:
		if not(i in shut):
			outputfile.write("Program Removed: " + i + "\n")
			removedPrograms.append(i)
	
	#Iterates through shutdown file, if entry not in startup:
	#	Add entry to outputfile and installedPrograms List
	for i in shut:
		if not(i in start):
			outputfile.write("Program Installed: " + i + "\n")
			installedPrograms.append(i)
	#file cleanup
	startfile.close()
	shutdownfile.close()
	outputfile.close()


	programs = {}
	counter = 0
	#Prints out installed programs
	print()
	print("Installed Programs: ")
	for i in installedPrograms:
		print("\t" + str(counter) + ".  " + i)
		#Adds program name to dictionary w/ key of counter
		programs[str(counter)] = i.strip("\n")
		counter += 1
	print()
	#If there are none then it kindly tells the user
	if installedPrograms == []:
		print("\t" + "No Programs Installed... ")
		print()
	print()
	
	#Does equivalent of above for removed programs
	print("Removed Programs: ")
	for i in removedPrograms:
		print("\t" + str(counter) + ".  " + i)
		#Adds program name to dictionary w/ key of counter
		programs[str(counter)] = i.strip("\n")
		counter += 1
	print()

	#again...
	if removedPrograms == []:
		print("\t" + "No Programs Removed... ")
		print()

	#print(programs)

	revert_programs = []
	print("Enter a Number that corresponds to any program (or \'end\' to exit) \nIn order to either uninstall or install it again")
	while True:
		inputNum = input("\t>> ")
		if inputNum == 'end':
			break
		else:
			try:
				inputNum = int(inputNum)
				if inputNum <= counter and inputNum >= 0:
					print("\t   " + programs[str(inputNum)])
					revert_programs.append(programs[str(inputNum)])
				else:
					print("\t   Sorry Input Out of Range... ")
			except:
				print("\t   Sorry That is an Invalid Input... ")

		
if __name__ == "__main__":
	main()
