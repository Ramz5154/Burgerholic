#include "Scene1.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <ctime>
#include "Scene0.h"

Scene1::Scene1()
{
}

Scene1::Scene1(SDL_Renderer* renderer) {
    
    font = TTF_OpenFont("assets/Pixelon.ttf", 100); //font size
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    //ADDS TO HEAP BECAUSE IMAGES ARE TOO BIG MIGHT CAUSE STACK OVERFLOW
    //AND NEEED LONGER LIFETIME
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
    bell = new ImageRenderer(renderer, "assets/bell.png");
    pan = new ImageRenderer(renderer, "assets/pan.png");

    cheeseT = { 95,573,60,62 };
    tomatoT = { 15,573,60,62 };
    lettuceT = { 175,573,60,62 };
    burgerT = { 255,573,60,62 };
    bunT = { 340,573,60,62 };
    ketchupB = { 430,565,40,75 };
    bellRect = { 777,570,60,65 };
    panRect = { 880,560,170,85 };

    
    customer = new Customer();// NEEDS LIFETIME
    
    lineUp();// WITHOUT THIS IT WONT PUT OUT THE FIRST CUSTOMER 
   
}

Scene1::~Scene1() {
    //CLEAN HEAP 
    //COULD ITERATE THROUGH IMAGES BETTER PREFORMANCE 
    delete burgerShop;
    delete customer;

    delete plate;
    delete bunTin;
    delete cheeseTin;
    delete tomatoTin;
    delete lettuceTin;
    delete burgerTin;
    delete ketchupBottle;

    delete topBun;
    delete lettuce;
    delete tomato;
    delete ketchup;
    delete cheese;
    delete cookedBurger;
    delete rawBurger;
    delete customerHappy;
    delete customerAngry;
    delete bottomBun;
    delete bell;
    delete pan;
}

void Scene1::HandleEvents(SDL_Event& event) {
    player.PlaceOrder(event);
    if (event.type == SDL_QUIT || player.quit) {
        event.type = SDL_QUIT;// PRESS ESC TO QUIT
        SDL_PushEvent(&event);
    }

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX = event.button.x;///WHEN LEFT CLICK GETS X AND Y OF MOUSE AND SEES IF ITS INSIDE THE X OR Y OF A RECT
        // AND THE HIEGHT AND WIDTH 
        int mouseY = event.button.y;

        MouseCommand(mouseX, mouseY);
    }

    if (player.enter) {
        bool matched = false;

        for (int i = 0; i < customer->LineUp.size(); ++i) {// IF THERE IS ANYTHING IN VECTOR 
            if (ing.ingredientsMatch(customer->LineUp[i], player.playerOrder)) {//COMPARES VECTORS
                std::cout << "orders match\n";
                customer->LineUp.erase(customer->LineUp.begin() + i); // ERASES VECTOR AND CUSTOMER
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

        if (customer->LineUp.empty() && customer->customerLineUp.empty()) {//IF NO MORE ORDERS LEVEL UP AND ADD MORE CUSTOMERS
            level += 1;
            customer->burgerSize += 1;// ADD TO THE NUMBERS OF INGRIDNETS ABLE TO BE ADDED TO THE VECTOR CHECK CUSTOMER.CPP
            lineUp();//RUNS LINE
        }

        player.playerOrder.clear();// ERASES PLAYER IF CORRECT OR NOT
        player.enter = false;//RESETS SO YOU CAN PRESS ENTER AGIN
    }
}

void Scene1::Update(double deltaTime)
{
   
    cookBurger(deltaTime);
    
    if (!timerDone) {
        timer -= deltaTime;

        if (timer < 0.0) { // IF TIMER HITS 0 IT WILL CHANGE TO SCENE 3
            timerDone = true;
            std::cout << "30 seconds have passed!" << std::endl;
            scene.sceneState = 2; //SWITCH USED IN MAIN 2 = SCENE 3
        }
    }
}


void Scene1::Render(SDL_Renderer* renderer) {
   
    burgerShop->Render(0, 0, 1080, 720);
   
   
     custumerLineUp();

   
     //RENDERS IMAGES THAT WILL ALWAYS BE NEEDED IN SCENE 1 
     plate->Render(475, 450, 300, 300);
     bell->Render(755, 550, 100, 100);
     pan->Render(835, 435, 330, 300);
     cheeseTin->Render(0, 480, 250, 250);
     tomatoTin->Render(-80, 480, 250, 250);
     ketchupBottle->Render(400, 550, 100, 100);
     lettuceTin->Render(80, 480, 250, 250);
     burgerTin->Render(160, 480, 250, 250);
     bunTin->Render(240, 480, 250, 250);
   
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //SDL_RenderFillRect(renderer, &panRect); // to make the button visable

     int tim = timer;
     std::string order = std::to_string(ordersFinished);// COVERTING TO STRING TO BE USED TO RENDER TEXT
     std::string levelTime = std::to_string(tim);
     renderText(renderer, font, order, 250, 40);//RENDERS TEXT
     renderText(renderer, font, levelTime, 750, 40);


    if (player.playerOrder.size() > 0 || customer->customerOrder.size() > 0) {//ONLY RUNS IF THERE IS SOMETHING INSIDE THE VECTOR COUL OF USED !EMPTY()
        VectorToImage();
    }
}

int Scene1::GetSceneState()
{
    return scene.sceneState;//GETS SCEMR FOR SWITCHING NEED FOR ALL SCENES
}


void Scene1::VectorToImage() //renders the ingriendtes from the vector
{
    int currentY = player.firstIng;// FIRST X POS OR JUST USE 500 
    
  
   

    for (int i = 0; i < player.playerOrder.size(); ++i) {

        int yPos = currentY - (i * 15);// SEPERATION BETWEEN THE INGRIDNETS FOR THE Y AXIS 
            // Special handling for bun at the first index
            if (player.playerOrder[i] == ingredients::ingredientsType::BUN) {
                if (i == 0) {
                    bottomBun->Render(370, yPos, 540, 360);//IF THE FIRST INDEX IS A BUN THAN IT WILL RENDER THE BOTTOM BUN IF NOT TOP BUN
                   
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
                    rawBurger->Render(719, 500, 500, 360);
                   
                    break;
                case ingredients::ingredientsType::COOKEDBURGER:
                    cookedBurger->Render(370, yPos, 540, 360);
                  
                    break;
               

                }
            }
            
    }
   int currentx = 110;
   

    for (int i = 0; i < customer->LineUp.size(); ++i) {
        int xpos = currentx + (i * 320);// SEPRATING THE BURGERS SO IT FITS INTO THE CUSTOMERS ORDER BUBBLE
        for (int y = 0; y < customer->LineUp[i].size(); ++y)
        {
            int yPos = 220 - (y * 13);//SEPRATES ENOUGH TO SHOW THE BURGER CLEARLY
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

                    switch (customer->LineUp[i][y]) {// A VECTOR OF VECTOR IS USED FOR EACH INGRIDNET OF EACH CUSTOMER
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


void Scene1::MouseCommand(int mouseX, int mouseY)// USED IN HANDLE EVNETS TO SEE IF THE MOUSE CORDS MEET THE CORDS OF EACH OF THE BUTTONS 
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

    else if (mouseX >= bellRect.x && mouseX <= bellRect.x + bellRect.w &&
        mouseY >= bellRect.y && mouseY <= bellRect.y + bellRect.h) {
        player.enter = true;
    }

    else if (mouseX >= panRect.x && mouseX <= panRect.x + panRect.w &&
        mouseY >= panRect.y && mouseY <= panRect.y + panRect.h) {
       
       
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
   

    for (int i = 0; i < player.playerOrder.size(); i++) {
        if (player.playerOrder[i] == ingredients::ingredientsType::RAWBURGER) {// IF THERE IS A RAWBURGER IN THE VECTOR THIS WILL RUN
            if (!timerDone) {//IF THE MAIN TIMER IS STILL COUNTING DOWN IT WILL RUN
                cookTimer -= deltatime;// COOK TIMER IS HOW LONG THE BURGER TAKES TO COOK IT
                        //DELTATIME IS 0.016 AND IS COUNTING DOWN EVERY TICK 
                    if (cookTimer <= 0) {//WHEN ITS DONE COOKING
                        burgerCooked = true;
                        player.playerOrder.erase(player.playerOrder.begin() + i);//IT WILL ERASE THE RAW BURGER AND ADD THE COOKED
                        player.playerOrder.push_back(ingredients::ingredientsType::COOKEDBURGER);
                        
                        cookTimer += 3;// RESET THE TIMER FOR THE NEXT RAW BURGER
                        
                       
                    }
                
                
            }
           
        }
       
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

