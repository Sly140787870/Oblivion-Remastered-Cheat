#include "pRenderer.h"
#include "Mem.h"
#include "VMT.h"

extern SDK::UFont* engine_font = nullptr;
using PostRender_t = void(*)(SDK::UGameViewportClient*, SDK::UCanvas*);
PostRender_t origin_renderer = nullptr;
int PostIndex = 0x70;
extern bool pRendererHooked = false;
extern bool AutoLoot;

void HookPostRender()
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	SDK::UGameViewportClient* ViewportClient = LocalPlayer->ViewportClient;
	if (!IsValid(ViewportClient) || isgoodaddr(ViewportClient) == 0)return;

	DWORD oldProtect;
	if (VirtualProtect(reinterpret_cast<void*>(ViewportClient), sizeof(void*), PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		VMTHook* hook = new VMTHook();
		hook->Initialize(reinterpret_cast<PVOID>(ViewportClient));
		hook->CreateHook(reinterpret_cast<PVOID>(&PostRender), PostIndex);
		origin_renderer = hook->GetFunctionPtr<PostRender_t>(PostIndex);
		VirtualProtect(reinterpret_cast<void*>(ViewportClient), sizeof(void*), oldProtect, &oldProtect);
		pRendererHooked = true;
	}
	engine_font = SDK::UObject::FindObject<SDK::UFont>("Font Roboto.Roboto");
}

void PostRender(SDK::UGameViewportClient* ViewportClient, SDK::UCanvas* Canvas)
{
	if (Canvas)
	{
		Canvas->K2_DrawText(engine_font, SDK::FString(L"Slyware"), SDK::FVector2D{ 0.5, 0.5 }, SDK::FVector2D{ 1, 1 }, SDK::FLinearColor{ 1, 1, 1, 1.f }, 1, SDK::FLinearColor{ 0.f, 0.f, 0.f, 0.f }, SDK::FVector2D{ 1.f, 1.f }, false, false, true, SDK::FLinearColor{ 0.f, 0.f, 0.f, 1.f });
		if (Is2DESP)Draw2DESP(Canvas);
		if (IsAimbot)
		{
			Aimbot(Canvas);
			DrawFOVCircle(Canvas, AimFOV);
		}
	}
	origin_renderer(ViewportClient, Canvas);
}