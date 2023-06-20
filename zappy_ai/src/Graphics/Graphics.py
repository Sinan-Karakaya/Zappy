import os

os.environ["PYGAME_HIDE_SUPPORT_PROMPT"] = "hide"
import pygame


class Graphics:
    def displayText(self, text, x, y):
        font = pygame.font.Font(None, 36)

        # Render the text onto a surface
        text_surface = font.render(text, True, (255, 255, 255))

        # Blit the surface onto the screen
        self.screen.blit(text_surface, (x, y))

    def __init__(self, agent):
        self.state = "This agent dont use state machine"
        self.agent = agent

        # Initialize Pygame
        pygame.init()

        # Set the window size
        self.window_size = (600, 800)

        # Create the window
        self.screen = pygame.display.set_mode(self.window_size)

        # Load the texture
        self.texture = pygame.image.load("src/Graphics/assets/ui_atlas.png")

        # Load the sub texture
        self.profile = pygame.Surface((142, 142))
        self.profile.blit(self.texture, (0, 0), (708, 286, 142, 142))

        self.inventory = pygame.Surface((115, 80))
        self.inventory.blit(self.texture, (0, 0), (316, 293, 115, 80))

    def runGraphics(self):
        self.agent.birth()
        # Run the game loop
        while True:
            self.screen.fill((0, 0, 0))
            self.agent.live()
            try:
                self.state = self.agent.state
            except:
                ...
            # Handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    quit()

            # Update the screen
            self.screen.blit(pygame.transform.scale(self.profile, (284, 284)), (0, 0))
            self.screen.blit(
                pygame.transform.scale(self.inventory, (230, 160)), (0, 284)
            )

            self.displayText(str(self.agent.inventory["linemate"]), 0, 284)
            self.displayText(str(self.agent.inventory["deraumere"]), 83, 284)
            self.displayText(str(self.agent.inventory["sibur"]), 165, 284)

            self.displayText(str(self.agent.inventory["mendiane"]), 0, 364)
            self.displayText(str(self.agent.inventory["phiras"]), 83, 364)
            self.displayText(str(self.agent.inventory["thystame"]), 165, 364)

            self.displayText(self.state, 0, 444)

            pygame.display.update()
            # Create a font object
