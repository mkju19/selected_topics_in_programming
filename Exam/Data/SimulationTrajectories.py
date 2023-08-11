import pandas as pd
import matplotlib.pyplot as plt

def plotCsv(fileName):
    df = pd.read_csv(fileName + ".csv", sep=';')

    if "env" in df:
        df = df.drop("env", axis=1)

    df.plot(x="Elapsed Time")

    plt.savefig(fileName + ".png")

plotCsv("simple")
plotCsv("CircadianRhythm")
plotCsv("Covid")