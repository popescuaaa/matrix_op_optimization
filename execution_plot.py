import matplotlib.pyplot as plt

FILE_NAME = "logfile"
TIME_COLUMN = 2
NAME_COLUMN = 0

# execution time values 
NEOPT = list()
OPT_M = list()
OPT_F = list()
OPT_F_EXTRA = list()
BLAS = list()


def extract_data():
    file = open(FILE_NAME, "r")
    
    for line in file:
        if "N=1200" in line:
            line_tokens = line.split(" ")
            time = line_tokens[TIME_COLUMN]
            name = line_tokens[NAME_COLUMN]
            time_value = float(time.split("=")[1])
            if "blas" in name:
                BLAS.append(time_value)
            if "opt_m" in name:
                OPT_M.append(time_value)
            if "neopt" in name:
                NEOPT.append(time_value)
            if "opt_f" in name and "opt_f_extra" not in name:
                OPT_F.append(time_value)
            if "opt_f_extra" in name:
                OPT_F_EXTRA.append(time_value)
            

def plot_data():
    extract_data()
    plt.plot(NEOPT, OPT_M)
    plt.xlabel("time")
    plt.show()


if __name__ == "__main__":
    plot_data()