import pandas as pd

data = pd.read_csv("data/data.tsv", sep="\t")
data.to_excel("data/data.xlsx", index=False)
print("done")

