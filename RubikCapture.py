
import time
import cv2

import numpy as np

import matplotlib.pyplot as plt 
import kociemba
import serial
import re



def replace_patterns(input_string):
    # Définir les motifs à remplacer et leur caractère de remplacement
    patterns = {"F2 B2|B2 F2": "X9",
                "F2 B'|B' F2": "X8",
                "F2 B|B F2": "X7",
                "F' B2|B2 F'": "X6",
                "F' B'|B' F'": "X5",
                "F' B|B F'": "X4",
                "F B2|B2 F": "X3",
                "F B'|B' F": "X2",
                "F B|B F": "X1",  # Remplacer "F B" ou "F B" par "X1"
                "U2 D2|D2 U2": "Y9",
                "U2 D'|D' U2": "Y8",
                "U2 D|D U2": "Y7",
                "U' D2|D2 U'": "Y6",
                "U' D'|D' U'": "Y5",
                "U' D|D U'": "Y4",
                "U D2|D2 U": "Y3",
                "U D'|D' U": "Y2",
                
                "U D|D U": "Y1",  # Remplacer "U D" ou "D U" par "Y1"
                "R2 L2|L2 R2": "Z9",
                "R2 L'|L' R2": "Z8",
                "R2 L|L R2": "Z7",
                "R' L2|L2 R'": "Z6",
                "R' L'|L' R'": "Z5",
                "R' L|L R'": "Z4",
                "R L2|L2 R": "Z3",
                "R L'|L' R": "Z2",
                "R L|L R": "Z1",  # Remplacer "R L" ou "L R" par "Z1"

                }  # Exemple de motif supplémentaire, remplace "X Y" ou "Y X" par "B"

    # Parcourir chaque motif et effectuer le remplacement
    for pattern, replacement in patterns.items():
        input_string = re.sub(pattern, replacement, input_string)

    return input_string



# vid = cv2.VideoCapture(0)

# while(1):
#     # Take video
#     ret, frame = vid.read()
    
#     cv2.imshow('name',frame)

# Chup hinh

# Generate Rubik
rubik = []
core = []
case = ['U','R','F','D','L','B']
casename = ['Up','Right','Front','Down','Left','Back']
caseposition = [[]]

# Open camera
vid = cv2.VideoCapture(0)
    # camera size
win_size = [1920,1080]

# cature zone (Square)
rec_int = [200,100]
rec_size = [300,300]

front_pos = [400,300]


# Create capture position
pos = []
gap = int(rec_size[0]/3)
small_rec_size = [10,10]
    # Create 9 point coordinates
for trash in range(3):
    for i in range(3):
        pos.append([rec_int[0]+50+gap*i,rec_int[1]+50+gap*trash])
        

# capture rubik
for i in range(6):
    color = np.array([])
        
    while(1):
        # Take video
        ret, frame = vid.read()
        
        # frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)

        # Draw capture zone (rect)
        cv2.rectangle(frame, rec_int, (rec_int[0] + rec_size[0], rec_int[1] + rec_size[1]), (0, 255, 0), 2)
        
        # Draw capture position
        for trash in range(9):
            cv2.rectangle(frame, pos[trash], (pos[trash][0]+small_rec_size[0], pos[trash][1] + small_rec_size[1]), (255, 0, 0), 2)
            
            # print(frame[pos[trash][0],pos[trash][1]])
        
        cv2.imshow(casename[i],frame)
        # Wait for input key
        if cv2.waitKey(10) == ord('z'):
            # Capture color
            for trash in range(9):
                color = np.append(color,frame[pos[trash][1]+int(small_rec_size[0]/2), pos[trash][0]+int(small_rec_size[1]/2)])
                
                cv2.rectangle(frame, pos[trash], (pos[trash][0]+small_rec_size[0], pos[trash][1] + small_rec_size[1]), color[-3:], 2)
                # cv2.rectangle(frame, pos[trash], (pos[trash][0]+small_rec_size[0], pos[trash][1] + small_rec_size[1]), (0, 0, 255), 2)
                
            
            corlor = color.reshape(9,3)
            # Take core color of face
            core.append(corlor[4])
            # Save face colors
            rubik.append(corlor)
            # show the captured face 
            cv2.imshow(casename[i], frame[rec_int[1]:rec_int[1] + rec_size[1],rec_int[0]:rec_int[0] + rec_size[0]])
            # Move the window positon
            if (casename[i] == 'Up'):
                cv2.moveWindow(casename[i], front_pos[0] - rec_size[0] ,front_pos[1])
            elif (casename[i] == 'Right'):
                cv2.moveWindow(casename[i], front_pos[0], front_pos[1] - rec_size[0] - 30)
            elif (casename[i] == 'Front'):
                cv2.moveWindow(casename[i], front_pos[0],front_pos[1])
            elif (casename[i] == 'Down'):
                cv2.moveWindow(casename[i], front_pos[0] + rec_size[0],front_pos[1])
            elif (casename[i] == 'Left'):
                cv2.moveWindow(casename[i], front_pos[0], front_pos[1] + rec_size[0] + 30)
            elif (casename[i] == 'Back'):
                cv2.moveWindow(casename[i], front_pos[0] + 2* rec_size[0],front_pos[1])
                
            # cv2.imshow(casename[i], frame)
            time.sleep(1)
            # cv2.destroyAllWindows()
            break
        
cv2.destroyAllWindows()
vid.release()



# Compare color
cube = ""
for trash in range(6):
    for i in range(9):
        cube = cube + case[sum(abs(rubik[trash][i]-core).transpose()).argmin()]
        
print(cube)




face = []
face_text = []
for k in range(6):
    count = 0
    img = np.empty((3,3,3))
    for j in range(3):
        for i in range(3):            
            # print(k,j,i,cube[k*9+j*3+i])
            if cube[k*9+j*3+i] == "U":
                color = np.array([core[0][2],core[0][1],core[0][0]])/255
            elif cube[k*9+j*3+i] == "R":
                color = np.array([core[1][2],core[1][1],core[1][0]])/255
            elif cube[k*9+j*3+i] == "F":
                color = np.array([core[2][2],core[2][1],core[2][0]])/255
            elif cube[k*9+j*3+i] == "D":
                color = np.array([core[3][2],core[3][1],core[3][0]])/255
            elif cube[k*9+j*3+i] == "L":
                color = np.array([core[4][2],core[4][1],core[4][0]])/255
            elif cube[k*9+j*3+i] == "B":
                color = np.array([core[5][2],core[5][1],core[5][0]])/255
            img[j,i,:] = color
    face.append(img)
    face_text.append(cube[k*9:k*9+9])
    



fig = plt.figure()
fig.add_subplot(3, 4, 5)
plt.imshow(face[0], interpolation='nearest')
plt.title("Up")

fig.add_subplot(3, 4, 6)
plt.imshow(face[2], interpolation='nearest')
plt.title("Front")

fig.add_subplot(3, 4, 2)
plt.imshow(face[1], interpolation='nearest')
plt.title("Right")

fig.add_subplot(3, 4, 8)
plt.imshow(face[5], interpolation='nearest')
plt.title("Back")

fig.add_subplot(3, 4, 10)
plt.imshow(face[4], interpolation='nearest')
plt.title("Left")

fig.add_subplot(3, 4, 7)
plt.imshow(face[3], interpolation='nearest')
plt.title("Down")


plt.show(block = False)





Up = face_text[0]
Right = face_text[1]
Front = face_text[2]
Down = face_text[3]
Left = face_text[4]
Back = face_text[5]

# ans = input("Correct?(y/n): ")
# if ans == 'n':
#     ans = input("Up?(y/n): ")
#     if ans == 'n':
#         ans = input("Correct Up: ")
#         print(ans)


cube_new = Up + Right + Front + Down + Left + Back

print(cube_new)



cv2.destroyAllWindows()





solution = kociemba.solve(cube_new)
# Configuration du port série (adapter le port COM en fonction de votre configuration) 

print("Solution:", solution)





# Exemple d'utilisation
input_string = solution
new_solution = replace_patterns(input_string)
print("Sortie:", new_solution)






input("Press Enter")

ser = serial.Serial('COM8', 9600, timeout=1)
time.sleep(3)
start = "MOVE"
ser.write(start.encode())
time.sleep(3)
# Envoi de la solution à l'Arduino via le port série
ser.write(new_solution.encode())
time.sleep(150)
end = "END"
ser.write(start.encode())



# Fermeture du port 
ser.close()

