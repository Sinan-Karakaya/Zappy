import os

os.environ["PYGAME_HIDE_SUPPORT_PROMPT"] = "hide"
import pygame


class Graphics:
    def displayText(self, text: str, x: int, y: int):
        """
        Display text on the pygame window at a given position

        @param text: The text to display
        @param x: The x position of the text
        @param y: The y position of the text

        @return: None
        """
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
        self.alien = pygame.image.load("src/Graphics/assets/alien.png")
        self.minerals = {
            "thystame": pygame.image.load("src/Graphics/assets/minerals/thystame.png"),
            "phiras": pygame.image.load("src/Graphics/assets/minerals/phiras.png"),
            "mendiane": pygame.image.load("src/Graphics/assets/minerals/mendiane.png"),
            "sibur": pygame.image.load("src/Graphics/assets/minerals/sibur.png"),
            "deraumere": pygame.image.load(
                "src/Graphics/assets/minerals/deraumere.png"
            ),
            "linemate": pygame.image.load("src/Graphics/assets/minerals/linemate.png"),
            "food": pygame.image.load("src/Graphics/assets/minerals/food.png"),
        }
        self.ground = pygame.image.load("src/Graphics/assets/ground.png")
        self.bakcground = pygame.image.load("src/Graphics/assets/background.png")

    def displayInventory(self):
        """
        Display the inventory of the agent

        @return: None
        """

        self.screen.blit(
            pygame.transform.scale(self.minerals["linemate"], (48, 48)), (82, 282)
        )
        self.displayText(str(self.agent.inventory["linemate"]), 132, 315)

        self.screen.blit(
            pygame.transform.scale(self.minerals["deraumere"], (48, 48)), (165, 282)
        )
        self.displayText(str(self.agent.inventory["deraumere"]), 210, 315)

        self.screen.blit(
            pygame.transform.scale(self.minerals["sibur"], (48, 48)), (245, 282)
        )
        self.displayText(str(self.agent.inventory["sibur"]), 285, 315)

        self.screen.blit(
            pygame.transform.scale(self.minerals["mendiane"], (48, 48)), (82, 362)
        )
        self.displayText(str(self.agent.inventory["mendiane"]), 132, 395)

        self.screen.blit(
            pygame.transform.scale(self.minerals["phiras"], (48, 48)), (165, 362)
        )
        self.displayText(str(self.agent.inventory["phiras"]), 210, 395)

        self.screen.blit(
            pygame.transform.scale(self.minerals["thystame"], (48, 48)), (245, 362)
        )
        self.displayText(str(self.agent.inventory["thystame"]), 285, 395)

    def to2d(self, x, y, z):
        return_x = x / z
        return_y = y / z
        return (return_x, return_y)

    def getDirection(self, direction: str):
        if direction == "Left":
            return -1
        elif direction == "Right":
            return 1
        else:
            return 0

    def displayVision(self):
        ##draw a purple rectangle
        self.screen.blit(pygame.transform.scale(self.ground, (600, 200)), (0, 600))
        x_3d = 0
        z_3d = 0
        direction = 0

        for i in range(len(self.agent.vision) - 1, -1, -1):
            z_3d = self.agent._Agent__getYtoGo(i) + 0.5
            x_3d, direction = self.agent._Agent__getXandDirectionToGo(i)
            direction = self.getDirection(direction)

            x, y = self.to2d(x_3d * 300 * direction, 0, z_3d)
            x += 300
            y += 600
            index = 0
            materialAlreadyDraw = []
            for material in self.agent.vision[i]:
                if (
                    material != "player"
                    and material != ""
                    and material not in materialAlreadyDraw
                ):
                    size = 48 / z_3d

                    self.screen.blit(
                        pygame.transform.scale(self.minerals[material], (size, size)),
                        (x + index * (8 / z_3d) - size / 2, y + size / 2),
                    )
                    index += 1
                materialAlreadyDraw.append(material)

    def runGraphics(self):
        """
        run the graphics

        @return: None
        """

        self.agent.birth()
        # Run the game loop
        while True:
            self.screen.fill((0, 0, 0))
            self.screen.blit(self.bakcground, (0, 0))
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
            self.screen.blit(self.texture, (0, 0))

            self.displayInventory()
            self.displayText(self.state, 235, 32)

            self.screen.blit(self.alien, (45, 22))

            self.displayVision()
            pygame.display.update()
