#include "ShotGlider.h"

ShotGlider::ShotGlider() : Glider()
{
    m_bulletFiringSpeed = 25;
    m_moveSpeed = 3;
}

void ShotGlider::load(unique_ptr<LoaderParams> const &pParams) 
{
    ShooterObject::load(move(pParams));
    m_velocity.setX(-m_moveSpeed);
}

void ShotGlider::update()
{
    if(!m_bDying)
    {
        if(m_bulletCounter == m_bulletFiringSpeed)
        {
            TheBulletHandler::Instance()->addEnemyBullet(m_position.getX(), m_position.getY() + 15, 16, 16, "bullet2", 1, Vector2D(-10, 0));
            m_bulletCounter = 0;
        }
        m_bulletCounter++;
    }
    else
    {
        m_velocity.setX(0);
        doDyingAnimation();
    }
    ShooterObject::update();
}