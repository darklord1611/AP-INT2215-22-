#pragma once
#include "Vector2D.h"
#include "GameObject.h"


class SDLGameObject : public GameObject 
{
protected:
    Vector2D m_position;
    Vector2D m_velocity;
    // Vector2D m_acceleration;
    int m_width; 
    int m_height;
    int m_currentRow;
    int m_numFrames;
    int m_currentFrame;
    string m_textureID;

public:
    Vector2D& getPosition() { return m_position; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    SDLGameObject(const LoaderParams* pParams);
    virtual void draw(); 
    virtual void update(); 
    virtual void clean(); 
};