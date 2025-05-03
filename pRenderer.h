#pragma once
#include "Framework.h"

extern SDK::UFont* engine_font;
void HookPostRender();
void PostRender(SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas);