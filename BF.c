#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#define PERM_SIZE 256
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 12
#define NUM_COLUMNS 16
#define PERM_SIZE 256
int NUM_BALLS = 10;// Number of balls to create

// Define the Ball struct with just x and y positions
typedef struct {
    float x, y; // Position
    int radius; // Ball radius
} Ball;

// Function to initialize a ball
void initBall(Ball *ball, float x, float y, int radius) {
    ball->x = x;
    ball->y = y;
    ball->radius = radius;
}



void Texter(SDL_Renderer *renderer, SDL_Texture *spriteSheet, 
                      int i, int j, char a, int scale, int cr, int cg, int cb) {
    int characterIndex = 0; // Default character index
    int ind = 97;
    if(a=='a') {
        ind = 97;
    } else if(a=='b') {
        ind = 98;
    } else if(a=='c') {
        ind = 99;
    } else if(a=='d') {
        ind = 100;
    } else if(a=='e') {
        ind = 101;
    } else if(a=='f') {
        ind = 102;
    } else if(a=='g') {
        ind = 103;
    } else if(a=='h') {
        ind = 104;
    } else if(a=='i') {
        ind = 105;
    } else if(a=='j') {
        ind = 106;
    } else if(a=='k') {
        ind = 107;
    } else if(a=='l') {
        ind = 108;
    } else if(a=='m') {
        ind = 109;
    } else if(a=='n') {
        ind = 110;
    } else if(a=='o') {
        ind = 111;
    } else if(a=='p') {
        ind = 112;
    } else if(a=='q') {
        ind = 113;
    } else if(a=='r') {
        ind = 114;
    } else if(a=='s') {
        ind = 115;
    } else if(a=='t') {
        ind = 116;
    } else if(a=='u') {
        ind = 117;
    } else if(a=='v') {
        ind = 118;
    } else if(a=='w') {
        ind = 119;
    } else if(a=='x') {
        ind = 120;
    } else if(a=='y') {
        ind = 121;
    } else if(a=='z') {
        ind = 122;
     
    } else if(a=='A') {
        ind = 65;
    } else if(a=='B') {
        ind = 66;
    } else if(a=='C') {
        ind = 67;
    } else if(a=='D') {
        ind = 68;
    } else if(a=='E') {
        ind = 69;
    } else if(a=='F') {
        ind = 70;
    } else if(a=='G') {
        ind = 71;
    } else if(a=='H') {
        ind = 72;
    } else if(a=='I') {
        ind = 73;
    } else if(a=='J') {
        ind = 74;
    } else if(a=='K') {
        ind = 75;
    } else if(a=='L') {
        ind = 76;
    } else if(a=='M') {
        ind = 77;
    } else if(a=='N') {
        ind = 78;
    } else if(a=='O') {
        ind = 79;
    } else if(a=='P') {
        ind = 80;
    } else if(a=='Q') {
        ind = 81;
    } else if(a=='R') {
        ind = 82;
    } else if(a=='S') {
        ind = 83;
    } else if(a=='T') {
        ind = 84;
    } else if(a=='U') {
        ind = 85;
    } else if(a=='V') {
        ind = 86;
    } else if(a=='W') {
        ind = 87;
    } else if(a=='X') {
        ind = 88;
    } else if(a=='Y') {
        ind = 89;
    } else if(a=='Z') {
        ind = 90;
    } else if(a=='0') {
        ind = 48;
    } else if(a=='1') {
        ind = 49;
    } else if(a=='2') {
        ind = 50;
    } else if(a=='3') {
        ind = 51;
    } else if(a=='4') {
        ind = 52;
    } else if(a=='5') {
        ind = 53;
    } else if(a=='6') {
        ind = 54;
    } else if(a=='7') {
        ind = 55;
    } else if(a=='8') {
        ind = 56;
    } else if(a=='9') {
        ind = 57;
    } else if(a==' ') {
        ind = 0;
    } else if(a=='-') {
        ind = 249;
    }
    characterIndex = ind;
    
    SDL_Rect srcRect = {
                (characterIndex % NUM_COLUMNS) * CHAR_WIDTH,
                (characterIndex / NUM_COLUMNS) * CHAR_HEIGHT,
                CHAR_WIDTH,
                CHAR_HEIGHT
            };

            // Calculate the destination rectangle for rendering
            SDL_Rect dstRect = { i, j, CHAR_WIDTH * scale, CHAR_HEIGHT * scale }; // Scale up for visibility

            // Set color modulation for the texture (optional)
            SDL_SetTextureColorMod(spriteSheet, cr, cg, cb); // Example: render white pixels as green

            // Render the character from the sprite sheet
            SDL_RenderCopy(renderer, spriteSheet, &srcRect, &dstRect);
}
//SheetPrint(renderer,spriteSheet, i,j,219,2,100,100,100);
void SheetPrint(SDL_Renderer *renderer, SDL_Texture *spriteSheet, 
                      int i, int j, int a, int scale, int cr, int cg, int cb) {
    int characterIndex = 0; // Default character index
    int ind = a;
    characterIndex = ind;
    
    SDL_Rect srcRect = {
                (characterIndex % NUM_COLUMNS) * CHAR_WIDTH,
                (characterIndex / NUM_COLUMNS) * CHAR_HEIGHT,
                CHAR_WIDTH,
                CHAR_HEIGHT
            };

            // Calculate the destination rectangle for rendering
            SDL_Rect dstRect = { i, j, CHAR_WIDTH * scale, CHAR_HEIGHT * scale }; // Scale up for visibility

            // Set color modulation for the texture (optional)
            SDL_SetTextureColorMod(spriteSheet, cr, cg, cb); // Example: render white pixels as green

            // Render the character from the sprite sheet
            SDL_RenderCopy(renderer, spriteSheet, &srcRect, &dstRect);
}
void PrintLine(SDL_Renderer *renderer, SDL_Texture *spriteSheet, char *test, int len, int scale, int sx, int sy, int r, int g, int b) {
    for (int i = 0; test[i] != '\0'; i++) {
        Texter(renderer, spriteSheet, sx + (scale * 8 * i), sy, test[i], scale, r, g, b);
    }

}

float getBallX(Ball balls[], int n) {
    if (n < 0 || n >= NUM_BALLS) {
        printf("Error: Ball index out of range\n");
        return -1; // Return an invalid value if the index is out of range
    }
    return balls[n].x;
}

// Function to get the y position of the n-th ball
float getBallY(Ball balls[], int n) {
    if (n < 0 || n >= NUM_BALLS) {
        printf("Error: Ball index out of range\n");
        return -1; // Return an invalid value if the index is out of range
    }
    return balls[n].y;
}

void removeBall(Ball balls[], int *numBalls, int indexToRemove) {
    if (*numBalls <= 0 || indexToRemove < 0 || indexToRemove >= *numBalls) {
        printf("Invalid index or no balls to remove\n");
        return;
    }

    // Shift all balls after the removed one to the left by one position
    for (int i = indexToRemove; i < *numBalls - 1; i++) {
        balls[i] = balls[i + 1];
    }

    // Decrease the number of balls
    (*numBalls)--;
}
int main() {
int menu = 0;
int cx = 400;
int cy = 850;
int running =1;
int t=0;
SDL_Event event;
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Emerald Lands", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load sprite sheet
    SDL_Texture *spriteSheet = IMG_LoadTexture(renderer, "Tileset/curses.bmp");
    if (!spriteSheet) {
        printf("Failed to load texture: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return 1;
    }

    // Set blend mode for transparency
    SDL_SetTextureBlendMode(spriteSheet, SDL_BLENDMODE_BLEND);
	Ball balls[100000];
    
    // Initialize each ball in the array with different positions
    /*
    for (int i = 0; i < 1; i++) {
        initBall(&balls[i], 100 + i * 50, 100 + i * 50, 10); // Balls with radius 10
    }
	*/
    // Main loop
    float wind=0;
    int borderShrink=0;
    char timeStr[10];
    char timePrev[10];
	int jumpsleft=3;
	int jumpvelocity=0;
	int previous = 0;
    while (running) {
    	SDL_RenderClear(renderer);
    	for(int i = 0; i < 40; i++) {
    		SheetPrint(renderer,spriteSheet, borderShrink-12,i*24,219,2,100,100,100);
    		SheetPrint(renderer,spriteSheet, WINDOW_WIDTH-borderShrink-4,i*24,219,2,100,100,100);
    	}
    	sprintf(timeStr, "%d", t);
    	sprintf(timePrev, "%d", previous);
     	PrintLine(renderer,spriteSheet,timeStr, 9, 2,0, 870, 0, 255, 255);
     	PrintLine(renderer,spriteSheet,timePrev, 9, 2,WINDOW_WIDTH-100, 870, 0, 255, 255);
    	if(t < 1000) {
    		PrintLine(renderer, spriteSheet, "Boulder Fall 2", 9, 2, 2*t-100, 300, t, 2*t+20, 200);
    	}
    	t++;
    	if (cx > WINDOW_WIDTH-20-borderShrink) {
    		cx --;
    	}
    	if (cx < borderShrink) {
    		cx ++;
    	}
    	if (t % 1000 == 0) {
    		borderShrink += 10;
    	}
    	if (t % 1000 < 500) {
    		wind=.1;
    	}
    	else {
    	wind=-.1;
    	}
    	
    	
    
    	
    	for (int i = 0; i < NUM_BALLS; i++) {
            // Example of updating the x and y positions in the main loop
            balls[i].x += wind; // Move each ball horizontally
            balls[i].y += 1; // Move each ball vertically

            
            
            SheetPrint(renderer,spriteSheet, balls[i].x,balls[i].y,7,4,200,200,200);
            if(abs(balls[i].x-cx) < 20) {
            	if(abs(balls[i].y-cy) < 20 && t > 500) {
            		for(int i=0; i < NUM_BALLS; i++) {
            			if(NUM_BALLS > 0) {
            				removeBall(balls, &NUM_BALLS, i);
            				NUM_BALLS--;
            			}
            		}
            		previous=t;
            		borderShrink=0;
            	
            		t=0;
            		cx=800;
            		cy=850;
            	}
            }
            if(balls[i].y > 850) {
            	removeBall(balls, &NUM_BALLS, i);
            	
            }
        }
        if(cy == 850) {
        	jumpsleft=3;
        }
        
        cy-=jumpvelocity;
        if(t % 3 == 0) {
        	jumpvelocity -=1;
        }
        
        if(cy > 850) {
        	cy=850;
        	jumpvelocity=0;
        }
        if (t% 100 == 0 && t > 200) {
        	for (int i = 0; i < t/100; i++) {
        		int randomX = rand() % WINDOW_WIDTH; // Random x position between 0 and screenWidth - 1
    			
        		initBall(&balls[i+NUM_BALLS-1], randomX, -20-(rand() % 100), 10); // Balls with radius 10
        		NUM_BALLS++;
    		}
    	}
        	
        
    
    
    	
    	
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        
                            running = 0; // Exit on ESC key press
                        
                        break;
                    
                    
                        
                    /*
                    case SDLK_DOWN:
                    	for(int i=0; i< 5; i++) {
                        	cy++;
                        }
                        break;
                    */
                    
                    
                    case SDLK_SPACE:
                    	if(jumpsleft > 0) {
                    		jumpsleft--;
                    		jumpvelocity=5;
                    	}
                        	
                        
                    
                    
                    	
                    
                    // Add more keys as needed
                    
                    default:
                        break;
                
                }
            }
        }
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_RIGHT] && cx < WINDOW_WIDTH-20-borderShrink) {
            for (int i = 0; i < 3; i++) {
                cx++;  // Move right
            }
        }

        if (state[SDL_SCANCODE_LEFT]&& cx > borderShrink) {
            for (int i = 0; i < 3; i++) {
                cx--;  // Move left
            }
        }


	
	SheetPrint(renderer,spriteSheet, cx,cy,1,3,100,100,100);
	
	SDL_RenderPresent(renderer);
    usleep(10000);
    fflush(stdout);
	}
	
	return 0;
}
