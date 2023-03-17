import pygame

# Initialize Pygame
pygame.init()

# Set the window size
win_width = 800
win_height = 600
win_size = (win_width, win_height)

# Create the window
win = pygame.display.set_mode(win_size)

# Set the title of the window
pygame.display.set_caption("Maze Game")

# Set the font for the text
font = pygame.font.SysFont("arial", 32)

# Set the clock for the game loop
clock = pygame.time.Clock()

# Set the colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# Set the game loop
running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Fill the window with white
    win.fill(WHITE)

    # Draw the text
    text = font.render("Welcome to Maze Game", True, BLACK)
    text_rect = text.get_rect(center=(win_width/2, win_height/2))
    win.blit(text, text_rect)

    # Draw a red rectangle
    pygame.draw.rect(win, RED, (100, 100, 50, 50))

    # Update the display
    pygame.display.update()

    # Set the game clock
    clock.tick(60)

# Quit Pygame
pygame.quit()
