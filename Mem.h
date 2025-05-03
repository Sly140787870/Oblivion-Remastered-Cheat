#pragma once
#include "Framework.h"
#define M_PI 3.14159265358979323846264338327950288

extern bool Is2DESP;
extern bool DrawName;
extern bool DrawDistance;

extern bool IsAimbot;
extern float AimFOV;
extern float AimDistance;

extern bool IsFly;
extern bool IsGhost;

void SetImGuiStyle();
void RaveTime(static float& Red, static float& Green, static float& Blue, float Speed);
int isgoodaddr(void* p);
bool IsValid(void* p);
SDK::FVector BoneToLocation(SDK::ACharacter* Player, int BoneId);
SDK::FVector2D BoneToScreenLocation(SDK::APlayerController* Controller, SDK::ACharacter* Player, int BoneId);
inline SDK::FVector VectorSubtract(SDK::FVector Vector1, SDK::FVector Vector2);
inline SDK::FVector VectorAdd(SDK::FVector Vector1, SDK::FVector Vector2);
float Calculate2DDistance(const SDK::FVector2D& A, const SDK::FVector2D& B);
bool W2S(SDK::UCanvas* Canvas, const SDK::FVector& WorldLoc, SDK::FVector2D* ScreenPos);
void GetVportSize(SDK::UCanvas* Canvas, SDK::APlayerController* pController, int* SizeX, int* SizeY);

void Draw2DESP(SDK::UCanvas* Canvas);
void Aimbot(SDK::UCanvas* Canvas);
void DrawFOVCircle(SDK::UCanvas* Canvas, float FOVRadius);

void SlyFly(bool Fly);
void SlyGhost(bool Ghost);