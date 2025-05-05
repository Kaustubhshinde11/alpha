from sklearn.linear_model import LinearRegression
from sklearn.datasets import make_regression
from multiprocessing import Process

def train(seed):
    x, y = make_regression(n_samples=100, n_features=2, noise=0.1, random_state=seed)
    model = LinearRegression()
    model.fit(x, y)
    print("Seed:", seed, "Score:", round(model.score(x, y), 2))

if __name__ == "__main__":
    p1 = Process(target=train, args=(0,))
    p2 = Process(target=train, args=(1,))
    p3 = Process(target=train, args=(2,))

    p1.start()
    p2.start()
    p3.start()

    p1.join()
    p2.join()
    p3.join()
