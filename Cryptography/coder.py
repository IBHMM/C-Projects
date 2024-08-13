import os

text = "we will fail the exam"
seed = 6

coded = ""

with open('./data/coded.txt', 'w', encoding='utf-8') as file:
    file.write(f"Seed: {seed}\n")

for char in text:
    c = (ord(char) + seed) % 255
    seed = (32 * seed + 10) % 1000000
    coded += chr(c)

def make_message(seed, text):
    message = ""
    for char in text:
        c = (ord(char) - seed) % 255
        if c < 0:
            c += 255
        message += chr(c)
        seed = (32 * seed + 10) % 1000000
    return message

def control(message):
    c_e_i_o_t = 0
    c_j_x_z = 0
    for char in message:
        if char in 'eEiIoOtT':
            c_e_i_o_t += 1
        if char in 'jJxXzZ':
            c_j_x_z += 1
    
    if c_e_i_o_t >= c_j_x_z:
        return 'prefered'
    else:
        return 'not_prefered'

with open('./data/coded.txt', 'a', encoding='utf-8') as file:
    file.write(f"Code: {coded}\n")

for i in range(10):
    message = make_message(i, coded)
    folder_path = f'./data/allmessages/{control(message)}'
    os.makedirs(folder_path, exist_ok=True)
    
    path = f'{folder_path}/messages.txt'

    with open(path, 'a', encoding='utf-8') as file:
        file.write(f"Seed: {i}\n")
        file.write(f"{message}\n")
