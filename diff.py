import sys

def diff(file_1, file_2, val=1.000064):
    with open(file_1, 'r') as f1, open(file_2, 'r') as f2:
        f1_lines = f1.readlines()
        f2_lines = f2.readlines()
        
        for i in range(len(f1_lines)):
            f1_v1, f1_v2 = float(f1_lines[i].split()[0]), float(f1_lines[i].split()[1])
            f2_v1, f2_v2 = float(f2_lines[i].split()[0]), float(f2_lines[i].split()[1])
            w1 = float(f1_lines[i].split()[2])
            w2 = float(f2_lines[i].split()[2])
            if(w1 > val and w2 > val):
                if(f1_v1 != f2_v1 or f1_v2 != f2_v2):
                    print(f'Error: {i} ->', f1_lines[i].replace("\n", ""), "|", f2_lines[i].replace("\n", ""))

if __name__ == '__main__':
    diff(sys.argv[1], sys.argv[2])