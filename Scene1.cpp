#include "Scene1.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <ctime>
#include "Scene0.h"

Scene1::Scene1(SDL_Renderer* renderer) {
    
    font = TTF_OpenFont("assets/Pixelon.ttf", 100); //font size
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    plate = new ImageRenderer(renderer, "assets/plate.png");
    bunTin = new ImageRenderer(renderer, "assets/bunTin.png");
    burgerTin = new ImageRenderer(renderer, "assets/burgerTin.png");
    lettuceTin = new ImageRenderer(renderer, "assets/lettuceTin.png");
    cheeseTin = new ImageRenderer(renderer, "assets/cheeseTin.png");
    tomatoTin = new ImageRenderer(renderer, "assets/tomatoTin.png");
    ketchupBottle = new ImageRenderer(renderer, "assets/ketchupTin.png");

    burgerShop = new ImageRenderer(renderer, "assets/burgerStoreCounter.png");
    topBun = new ImageRenderer(renderer, "assets/TopBun.png");
    lettuce = new ImageRenderer(renderer, "assets/lettuce.png");
    tomato = new ImageRenderer(renderer, "assets/tomato.png");
    cheese = new ImageRenderer(renderer, "assets/cheese.png");
    ketchup = new ImageRenderer(renderer, "assets/ketchup.png");
    bottomBun = new ImageRenderer(renderer, "assets/bottomBun.png");
    cookedBurger = new ImageRenderer(renderer, "assets/cookedBurger.png");
    rawBurger = new ImageRenderer(renderer, "assets/rawBurger.png");
    customerHappy = new ImageRenderer(renderer, "assets/customerHappy.png");
    customerAngry = new ImageRenderer(renderer, "assets/customerAngry.png");

    cheeseT = { 95,573,60,62 };
    tomatoT = { 15,573,60,62 };
    lettuceT = { 175,573,60,62 };
    burgerT = { 255,573,60,62 };
    bunT = { 340,573,60,62 };
    ketchupB = { 430,565,40,75 };

    customer = new Customer();
    
    lineUp();
   
}

Scene1::~Scene1() {
    delete burgerShop;
    delete customer;

   

}

void Scene1::HandleEvents(SDL_Event& event) {
    player.PlaceOrder(event);
    if (event.type == SDL_QUIT || player.quit) {

    }

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX = event.button.x;
        int mouseY = event.button.y;

        MouseCommand(mouseX, mouseY);
    }

    if (player.enter) {
        bool matched = false;

        for (int i = 0; i < customer->LineUp.size(); ++i) {
            if (ing.ingredientsMatch(customer->LineUp[i], player.playerOrder)) {
                std::cout << "orders match\n";
                customer->LineUp.erase(customer->LineUp.begin() + i); 
                customer->customerLineUp.erase(customer->customerLineUp.begin() + i); 
                ordersFinished += 1;
                timer += 10.0;
                matched = true;
                break;
            }
        }


        if (!matched) {
            std::cout << "orders don't match\n";
        }

        if (customer->LineUp.empty() && customer->customerLineUp.empty()) {
            level += 1;
            customer->burgerSize += 1;
            lineUp();
        }

        player.playerOrder.clear();
        player.enter = false;
    }
}

void Scene1::Update(double deltaTime)
{
   
    cookBurger(deltaTime);
    
    if (!timerDone) {
        timer -= deltaTime;

        if (timer < 0.0) { 
            timerDone = true;
            std::cout << "30 seconds have passed!" << std::endl;
            scene.sceneState = 0;
        }
    }
}


void Scene1::Render(SDL_Renderer* renderer) {
   
    burgerShop->Render(0, 0, 1080, 720);
   
   
     custumerLineUp();

   

     plate->Render(475, 450, 300, 300);
     cheeseTin->Render(0, 480, 250, 250);
     tomatoTin->Render(-80, 480, 250, 250);
     ketchupBottle->Render(400, 550, 100, 100);
     lettuceTin->Render(80, 480, 250, 250);
     burgerTin->Render(160, 480, 250, 250);
     bunTin->Render(240, 480, 250, 250);
   
     int tim = timer;
     std::string order = std::to_string(ordersFinished);
     std::string levelTime = std::to_string(tim);
     renderText(renderer, font, order, 250, 40);
     renderTimer(renderer, font, levelTime, 750, 40);


    if (player.playerOrder.size() > 0 || customer->customerOrder.size() > 0) {
        VectorToImage();
    }
}

int Scene1::GetSceneState()
{
    return scene.sceneState;
}


void Scene1::VectorToImage() //renders the ingriendtes from the vector
{
    int currentY = player.firstIng;
    
  
   

    for (int i = 0; i < player.playerOrder.size(); ++i) {

        int yPos = currentY - (i * 15);
            // Special handling for bun at the first index
            if (player.playerOrder[i] == ingredients::ingredientsType::BUN) {
                if (i == 0) {
                    bottomBun->Render(370, yPos, 540, 360);
                   
                }
                else {
                    topBun->Render(370, yPos, 540, 360);
                    
                }
            }
            else {

                switch (player.playerOrder[i]) {
                case ingredients::ingredientsType::TOMATO:
                    
                    tomato->Render(370, yPos, 540, 360);
                 
                    break;
                case ingredients::ingredientsType::LETTUCE:
                    lettuce->Render(370, yPos, 540, 360);
                   
                    break;
                case ingredients::ingredientsType::CHEESE:
                    cheese->Render(370, yPos, 540, 360);
                   
                    break;
                case ingredients::ingredientsType::KETCHUP:
                    ketchup->Render(370, yPos, 540, 360);
                   
                    break;
                case ingredients::ingredientsType::RAWBURGER:
                    rawBurger->Render(700, 500, 540, 360);
                   
                    break;
                case ingredients::ingredientsType::COOKEDBURGER:
                    cookedBurger->Render(370, yPos, 540, 360);
                  
                    break;
               

                }
            }
            
    }
   int currentx = 110;
   

    for (int i = 0; i < customer->LineUp.size(); ++i) {
        int xpos = currentx + (i * 320);
        for (int y = 0; y < customer->LineUp[i].size(); ++y)
        {
            int yPos = 220 - (y * 13);
            // Special handling for bun at the first index
           
                if (customer->LineUp[i][y] == ingredients::ingredientsType::BUN) {
                    if (y == 0) {
                        bottomBun->Render(xpos, yPos, 300, 300);

                    }
                    else {
                        topBun->Render(xpos, yPos, 300, 300);

                    }
                }
                else {

                    switch (customer->LineUp[i][y]) {
                    case ingredients::ingredientsType::TOMATO:

                        tomato->Render(xpos, yPos, 300, 300);

                        break;
                    case ingredients::ingredientsType::LETTUCE:
                        lettuce->Render(xpos, yPos, 300, 300);

                        break;
                    case ingredients::ingredientsType::CHEESE:
                        cheese->Render(xpos, yPos, 300, 300);

                        break;
                    case ingredients::ingredientsType::KETCHUP:
                        ketchup->Render(xpos, yPos, 300, 300);

                        break;
                    case ingredients::ingredientsType::COOKEDBURGER:
                        cookedBurger->Render(xpos, yPos, 300, 300);

                        break;
                    }
                }
            }
        }

    
   

}

void Scene1::custumerLineUp() //renders customer from vector 
{
    int x = 0;

    for (int i = 0; i < customer->customerLineUp.size(); ++i) {
        int xPos = x + (i * 310);
        customer->customerLineUp[i]->Render(xPos, 160, 400, 400);
    }
}

void Scene1::MouseCommand(int mouseX, int mouseY)
{
    if (mouseX >= tomatoT.x && mouseX <= tomatoT.x + tomatoT.w &&
        mouseY >= tomatoT.y && mouseY <= tomatoT.y + tomatoT.h) {
        std::cout << "tomato\n";
        player.playerOrder.push_back(ingredients::TOMATO);
    }
    else if (mouseX >= cheeseT.x && mouseX <= cheeseT.x + cheeseT.w &&
        mouseY >= cheeseT.y && mouseY <= cheeseT.y + cheeseT.h) {
        std::cout << "cheese\n";
        player.playerOrder.push_back(ingredients::CHEESE);
    }
    else if (mouseX >= lettuceT.x && mouseX <= lettuceT.x + lettuceT.w &&
        mouseY >= lettuceT.y && mouseY <= lettuceT.y + lettuceT.h) {
        std::cout << "lettuce\n";
        player.playerOrder.push_back(ingredients::LETTUCE);
    }
    else if (mouseX >= burgerT.x && mouseX <= burgerT.x + burgerT.w &&
        mouseY >= burgerT.y && mouseY <= burgerT.y + burgerT.h) {
        std::cout << "burger\n";
        player.playerOrder.push_back(ingredients::RAWBURGER);
    }
    else if (mouseX >= bunT.x && mouseX <= bunT.x + bunT.w &&
        mouseY >= bunT.y && mouseY <= bunT.y + bunT.h) {
        std::cout << "bun\n";
        player.playerOrder.push_back(ingredients::BUN);
    }
    else if (mouseX >= ketchupB.x && mouseX <= ketchupB.x + ketchupB.w &&
        mouseY >= ketchupB.y && mouseY <= ketchupB.y + ketchupB.h) {
        std::cout << "ketchup\n";
        player.playerOrder.push_back(ingredients::KETCHUP);
    }
}




void Scene1::lineUp() //makes the orders and pushes to vector for customerLineUp() to use
{
    for (int i = 0; i < level; ++i) {
      
           
            customer->makeRandomOrder();
            customer->LineUp.push_back(customer->customerOrder);
            customer->customerLineUp.push_back(customerHappy);
            

            for (int j = 0; j < customer->customerOrder.size(); ++j) {
                std::cout << ' ' << customer->customerOrder[j];
            }
            std::cout << '\n';
        }
    
}

void Scene1::cookBurger(double deltatime)
{
    bool raw = false;

    for (int i = 0; i < player.playerOrder.size(); i++) {
        if (player.playerOrder[i] == ingredients::ingredientsType::RAWBURGER) {
            if (!timerDone) {
                cookTimer -= deltatime;
                if (cookTimer <= 0) {
                    player.playerOrder.erase(player.playerOrder.begin() + i);
                    player.playerOrder.insert(player.playerOrder.begin() + i, ingredients::ingredientsType::COOKEDBURGER);
                    raw = true;
                    cookTimer += 3;
                }
            }
        }
       
    }
    if (!raw) {
        //std::cout << " no raw burger here";
    }
}

void Scene1::renderText(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y)//renders text for customers done
{
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dst = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

void Scene1::renderTimer(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y)//renders timer text
{
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dst = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

