import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

class Exec:
    def __init__(self, w, h, b):
        self.w = w
        self.h = h
        self.b = b

    def tiempo_total(self):
        return self.w * self.h + 35 * self.b + 242

lista_T = [Exec(1010, 1581, 319933), 
            Exec(1069, 1065, 227222), 
            Exec(2048, 1160, 474259),
            Exec(300, 168, 10158),
            Exec(1028, 609, 125555),
            Exec(1000, 563, 111982),
            Exec(1038, 692, 144282),
            Exec(937, 914, 172317),
            Exec(1250, 897, 224465)
            ]

lista_map = [e.tiempo_total() for e in lista_T]

dftiempo = pd.DataFrame({
    'tiempo' : [1.276,
                0.858,
                1.143,
                0.048,
                0.479,
                0.315,
                0.453,
                0.706,
                0.857
    ]
})

dfpasos = pd.DataFrame({
    'pasos' : lista_map
})

print(lista_map)


fig = plt.figure()
ax1 = fig.add_subplot(111)
ax1.plot(dfpasos)
ax1.set_ylabel('Tiempo calculado en pasos', color='b')

ax2 = ax1.twinx()
ax2.plot(dftiempo, 'r-')
ax2.set_ylabel('Tiempo de ejecución', color='r')
for tl in ax2.get_yticklabels():
    tl.set_color('r')
plt.show()