#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    
}

void Player::handleInput() 
{
    target = _InputHandler::Instance()->getMousePosition();

    m_velocity = *target - m_position;

    m_velocity /= 50;
}


void Player::draw() 
{ 
    SDLGameObject::draw(); 
}

void Player::update() 
{
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    if(_InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) 
    { 
        m_velocity.setX(2); 
    }
    if(_InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) 
    { 
        m_velocity.setX(-2); 
    }
    if(_InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) 
    { 
        m_velocity.setY(-2); 
    }
    if(_InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) 
    { 
        m_velocity.setY(2); 
    }
    SDLGameObject::update();
}
void Player::clean() 
{

}
