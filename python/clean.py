import pandas as pd
import sys

def main():
    file = sys.argv[1]
    if not file:
        print("provide file name to read !")
        exit(1)
    try:
        data = pd.read_csv(f"data/{file}", sep="\t")
    except Exception as err:
        print("error reading the file", file, " provide valid file name") 
    useless_cols = [col for col in data.columns if len(data[col].unique()) == 1]
    data = data.drop(useless_cols, axis=1)
    data.to_csv('data/clean_small.tsv', sep='\t', index=False)

if __name__ == '__main__':
    main()
