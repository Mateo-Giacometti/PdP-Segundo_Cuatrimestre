import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def plot_progress(progress : list) -> None:
    df = pd.DataFrame(np.array(progress), columns = ["Generation", "Distance"])
    plt.plot(df.Generation, df.Distance)
    plt.xlabel("Generation")
    plt.ylabel("Distance")
    plt.title("Best Route Distance Evolution")
    plt.show()

def print_route(route : list , title : str = '') -> None:
    x_coordinates = [c[1] for c in route]
    y_coordinates = [c[2] for c in route]
    plt.scatter(x_coordinates, y_coordinates)
    plt.plot(x_coordinates, y_coordinates)
    plt.xlabel("x distance")
    plt.ylabel("y distance")
    plt.title(title)
    plt.show()

def main(firstPopulation, finalPopulation, bestRoutes):
    first, final, generations = [], [], []
    df = pd.read_csv(firstPopulation, comment='#', header=None)
    first = df.values.tolist()
    df = pd.read_csv(finalPopulation, comment='#', header=None)
    final = df.values.tolist()
    df = pd.read_csv(bestRoutes)
    generations = df.values.tolist()
    
    for i in range(len(first)):
        first[i] = tuple(first[i])
    for i in range(len(final)):
        final[i] = tuple(final[i])
    for i in range(len(generations)):
        generations[i] = tuple(generations[i])

    first.append(tuple(first[0]))
    final.append(tuple(final[0]))        
    print_route(first,"Intial Solution Route")
    print_route(final, "Best Solution Route")
    plot_progress(generations)

if __name__ == '__main__':
    main("csvTest.csv", "finalGen.csv", "routeEvolution.csv")