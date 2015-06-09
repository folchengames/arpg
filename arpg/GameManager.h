//
//  GameManager.h
//  arpg
//
//  Created by Benjamin Chen on 6/5/15.
//  Copyright (c) 2015 chenjamin. All rights reserved.
//

#ifndef __arpg__GameManager__
#define __arpg__GameManager__

#include <SDL2/SDL.h>
#include <string>

class GameManager
{
    
public:
    
    // Game Loop and Setup
    
    void render();
    void clear();
    void update();
    void handleEvents();
    void quit();
    bool init(std::string title, int x, int y, int width, int height, bool fullscreen);
    void cleanup();
    
    // Public Getters
    SDL_Renderer* getRenderer() { return s_pRenderer; }
    std::string getWindowTitle() { return m_windowTitle; }
    int getWindowWidth() { return m_windowWidth; }
    int getWindowHeight() { return m_windowHeight; }
    bool getFullscreen() { return m_fullscreen; }
    bool getRunning() { return m_running; }
    
    // Singleton Instance
    static GameManager* Instance();
    
private:
    
    // Private Pointer to Singleton
    static GameManager* s_pInstance;
    
    // Private SDL2 Members
    SDL_Window* s_pWindow;
    SDL_Renderer* s_pRenderer;
    
    // Private SDL2 Attributes
    std::string m_windowTitle;
    int m_windowWidth;
    int m_windowHeight;
    bool m_fullscreen;
    bool m_running;
    
    // Private Utility Methods
    bool createRenderer();
    bool createWindow(std::string title, int x, int y, int width, int height, bool fullscreen);
    bool initSDL();
    bool initSDLImage();
    
    // Default Constructor and Destructors
    GameManager();
    ~GameManager();

};

#endif /* defined(__arpg__GameManager__) */