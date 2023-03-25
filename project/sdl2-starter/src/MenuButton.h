#pragma once

#ifndef __MenuButton__
#define __MenuButton__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
private:
	enum button_state
	{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
	};

	void (*m_callback) ();

	bool m_bReleased;
public:
	MenuButton();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
};

#endif // define __MenuButton__