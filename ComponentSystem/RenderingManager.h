#ifndef _RENDERER_H
#define _RENDERER_H

#include "Component.h"

class RenderingManager : public Component
{
public:
	RenderingManager(void);
	~RenderingManager(void);

	void Render();
};

#endif // !_RENDERER_H