def count_tabs(string:str)->int:
	return string.count("\t")

def main():
	with open("data/data.tsv", "r") as file:
		ok = True
		for line in file:
			if ok:
				tab_count = count_tabs(line)
				if tab_count < 117:
					prev = line.replace("\n", " ")
					ok = False
				else:
					pass
					# print(line)
			else:
				ok = True
				prev += " " + line
				print("repaired line:\n", prev)

if __name__ == "__main__":
	main()