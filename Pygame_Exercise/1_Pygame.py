'''
Author: your name
Date: 2021-09-20 11:21:03
LastEditTime: 2021-09-20 13:37:05
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \Python_Advanced\Pygame_Exercise\1_Pygame.py
'''
import sys
import pygame
from pygame.constants import QUIT

pygame.init()
DISPLAYSURF = pygame.display.set_mode((400, 300))
pygame.display.set_caption("hello world!")

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update()