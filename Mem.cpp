#include "Mem.h"
#include "ImGui/imgui.h"

extern bool Is2DESP = false;
extern bool DrawName = false;
extern bool DrawDistance = false;

extern bool IsAimbot = false;
extern float AimFOV = 90;
extern float AimDistance = 200;

extern bool IsFly = false;
extern bool IsGhost = false;

void SetImGuiStyle()
{
	ImFontConfig config;

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	config.GlyphRanges = io.Fonts->GetGlyphRangesCyrillic();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\consola.ttf", 20); //C:\\Windows\\Fonts\\Arial.ttf
	ImFont* TabFont = io.Fonts->AddFontDefault();
	TabFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\consolab.ttf", 20);
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = ImGui::GetStyle().Colors;
	style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style->WindowBorderSize = 0.0f;
	style->FramePadding = ImVec2(39.f, 6.f);
	style->WindowPadding = ImVec2(10.f, 6.f);
	style->GrabMinSize = 24.f;
	style->WindowBorderSize = 1.f;
	style->WindowMenuButtonPosition = ImGuiDir_Right; //ImGuiDir_None
	style->ColorButtonPosition = ImGuiDir_Left;
	style->FrameRounding = 3.f;
	style->GrabRounding = 4.f;
	style->ItemSpacing = ImVec2(6.f, 6.0f);

	style->Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.039f, 0.039f, 0.078f, 1.00f);
	style->Colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.039f, 0.039f, 0.078f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.0f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.07f, 0.07f, 0.15f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.153f, 0.157f, 0.227f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.176f, 0.176f, 0.247f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.07f, 0.07f, 0.15f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.07f, 0.07f, 0.15f, 1.00f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.15f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.310f, 0.310f, 0.310f, 0.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.310f, 0.310f, 0.310f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.410f, 0.410f, 0.410f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.510f, 0.510f, 0.510f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.800f, 0.557f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.800f, 0.557f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.800f, 0.557f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.070f, 0.070f, 0.130f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.070f, 0.070f, 0.130f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.039f, 0.039f, 0.078f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.070f, 0.070f, 0.130f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.800f, 0.557f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_Separator] = ImVec4(0.039f, 0.039f, 0.078f, 0.00f);
	style->Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.039f, 0.039f, 0.078f, 0.00f);
	style->Colors[ImGuiCol_SeparatorActive] = ImVec4(0.039f, 0.039f, 0.078f, 0.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 0.00f);
	style->Colors[ImGuiCol_Tab] = ImVec4(0.039f, 0.039f, 0.078f, 1.00f);
	style->Colors[ImGuiCol_TabHovered] = ImVec4(0.054f, 0.054f, 0.104f, 1.00f);
	style->Colors[ImGuiCol_TabActive] = ImVec4(0.070f, 0.070f, 0.130f, 1.00f);
}

void RaveTime(static float& Red, static float& Green, static float& Blue, float Speed)
{
	float time = ImGui::GetTime();
	Red = sin(Speed * time + 0.0f) * 0.5f + 0.5f;
	Green = sin(Speed * time + 2.0f) * 0.5f + 0.5f;
	Blue = sin(Speed * time + 4.0f) * 0.5f + 0.5f;
}

int isgoodaddr(void* p)
{
	intptr_t x = (intptr_t)p;
	return 65536 < x && (x & 3) == 0 && !IsBadReadPtr(p, 8);
}

bool IsValid(void* p)
{
	if (!p)return false;
	if (p == nullptr)return false;
	return true;
}

SDK::FVector BoneToLocation(SDK::ACharacter* Player, int BoneId)
{
	SDK::FVector NULLReturn = { 0, 0, 0 };

	if (!IsValid(Player) || isgoodaddr(Player) == 0)return NULLReturn;

	SDK::USkeletalMeshComponent* Mesh = Player->Mesh;
	if (!IsValid(Mesh) || isgoodaddr(Mesh) == 0)return NULLReturn;

	SDK::FVector BoneLocation = Mesh->GetSocketLocation(Mesh->GetBoneName(BoneId));
	return BoneLocation;
}

SDK::FVector2D BoneToScreenLocation(SDK::APlayerController* Controller, SDK::ACharacter* Player, int BoneId)
{
	if (!IsValid(Controller) || isgoodaddr(Controller) == 0)return { 0, 0 };
	if (!IsValid(Player) || isgoodaddr(Player) == 0)return { 0, 0 };
	if (!IsValid(Player->Mesh) || isgoodaddr(Player->Mesh) == 0)return { 0, 0 };

	SDK::USkeletalMeshComponent* Mesh = Player->Mesh;

	SDK::FVector BoneLocation = Mesh->GetSocketLocation(Mesh->GetBoneName(BoneId));
	SDK::FVector2D BoneScreenLocation;

	if (Controller->ProjectWorldLocationToScreen(BoneLocation, &BoneScreenLocation, false))
	{
		float ScaleX = 1920.0f / 2560.0f;
		float ScaleY = 1080.0f / 1440.0f;
		BoneScreenLocation.X *= ScaleX;
		BoneScreenLocation.Y *= ScaleY;
		return BoneScreenLocation;
	}
	return { 0, 0 };
}

inline SDK::FVector VectorSubtract(SDK::FVector Vector1, SDK::FVector Vector2)
{
	SDK::FVector Vec{};
	Vec.X = Vector1.X - Vector2.X;
	Vec.Y = Vector1.Y - Vector2.Y;
	Vec.Z = Vector1.Z - Vector2.Z;
	return Vec;
}

inline SDK::FVector VectorAdd(SDK::FVector Vector1, SDK::FVector Vector2)
{
	SDK::FVector Vec{};
	Vec.X = Vector1.X + Vector2.X;
	Vec.Y = Vector1.Y + Vector2.Y;
	Vec.Z = Vector1.Z + Vector2.Z;
	return Vec;
}

float Calculate2DDistance(const SDK::FVector2D& A, const SDK::FVector2D& B)
{
	const float DeltaX = A.X - B.X;
	const float DeltaY = A.Y - B.Y;
	return std::sqrt(DeltaX * DeltaX + DeltaY * DeltaY);
}

float radiansToDegrees(float radians)
{
	return radians * (180.0f / M_PI);
}

float Square(float val)
{
	return val * val;
}

bool W2S(SDK::UCanvas* Canvas, const SDK::FVector& WorldLoc, SDK::FVector2D* ScreenPos)
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return 0;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return 0;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return 0;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return 0;

	bool bIsOnScreen = PlayerController->ProjectWorldLocationToScreen(WorldLoc, ScreenPos, true);
	return bIsOnScreen;
}

void GetVportSize(SDK::UCanvas* Canvas, SDK::APlayerController* pController, int* SizeX, int* SizeY)
{
	if (!IsValid(Canvas) || isgoodaddr(Canvas) == 0)return;
	if (!IsValid(pController) || isgoodaddr(pController) == 0)return;
	pController->GetViewportSize(SizeX, SizeY);
}

void Draw2DESP(SDK::UCanvas* Canvas)
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return;
	const auto LocalPawn = PlayerController->K2_GetPawn();
	if (!IsValid(LocalPawn) || isgoodaddr(LocalPawn) == 0)return;

	int vpX, vpY;
	PlayerController->GetViewportSize(&vpX, &vpY);
	const auto LocalLocation = LocalPawn->K2_GetActorLocation();

	for (int i = 0; i < World->Levels.Num(); ++i)
	{
		const auto Level = World->Levels[i];
		if (!IsValid(Level) || isgoodaddr(Level) == 0)continue;

		for (int j = 0; j < Level->Actors.Num(); ++j)
		{
			const auto Actor = Level->Actors[j];
			if (!IsValid(Actor) || isgoodaddr(Actor) == 0)continue;
			if (Actor->IsA(SDK::ACharacter::StaticClass()) && Actor != LocalPawn)
			{
				SDK::AVOblivionPlayerCharacter* Character = static_cast<SDK::AVOblivionPlayerCharacter*>(Actor);
				if (!IsValid(Character) || isgoodaddr(Character) == 0)continue;

				if (Character->IsDead())continue;

				auto Location = Character->K2_GetActorLocation();

				const SDK::FVector DifferenceVector = Location - LocalLocation;
				const float Distance = std::sqrt(DifferenceVector.X * DifferenceVector.X + DifferenceVector.Y * DifferenceVector.Y + DifferenceVector.Z * DifferenceVector.Z);

				SDK::FVector2D ScreenLocation;
				const bool bIsOnScreen = W2S(Canvas, Location, &ScreenLocation);
				if (bIsOnScreen)
				{
					const auto CapsuleComponent = Character->CapsuleComponent;
					if (CapsuleComponent)
					{
						const float CapsuleHalfHeight = CapsuleComponent->GetScaledCapsuleHalfHeight();
						const float CapsuleRadius = CapsuleComponent->GetScaledCapsuleRadius();

						SDK::FVector TopLocation = Location + SDK::FVector(0, 0, CapsuleHalfHeight);
						SDK::FVector BottomLocation = Location - SDK::FVector(0, 0, CapsuleHalfHeight);

						SDK::FVector2D ScreenTopLocation;
						SDK::FVector2D ScreenBottomLocation;

						W2S(Canvas, TopLocation, &ScreenTopLocation);
						W2S(Canvas, BottomLocation, &ScreenBottomLocation);


						const float Height = std::abs(ScreenBottomLocation.Y - ScreenTopLocation.Y);
						const float Width = Height * (CapsuleRadius / CapsuleHalfHeight);

						const float BoxX = ScreenTopLocation.X - Width / 2;
						const float BoxY = ScreenTopLocation.Y;

						Canvas->K2_DrawBox(SDK::FVector2D(BoxX, BoxY), SDK::FVector2D(Width, Height), 1.3, SDK::FLinearColor(1, 1, 1, 1));
						if (DrawName)
						{
							// Draw the actor's name
							std::string ActorName = Character->Name.ToString();
							wchar_t ActorNameBuffer[256];
							swprintf(ActorNameBuffer, sizeof(ActorNameBuffer) / sizeof(wchar_t), L"%hs", ActorName.c_str());
							SDK::FString FStringActorName(ActorNameBuffer);
							SDK::FVector2D ActorNamePosition(BoxX, BoxY - 40);
							Canvas->K2_DrawText(SDK::UEngine::GetEngine()->SmallFont, FStringActorName, ActorNamePosition,
								SDK::FVector2D(1, 1),
								SDK::FLinearColor(1, 1, 1, 1), 0, SDK::FLinearColor(0, 0, 0, 1),
								SDK::FVector2D(1, 1), true, true, true, SDK::FLinearColor(0, 0, 0, 1));
						}
						if (DrawDistance)
						{
							// Draw the distance
							wchar_t DistanceBuffer[64];
							swprintf(DistanceBuffer, sizeof(DistanceBuffer) / sizeof(wchar_t), L"%.2f m", Distance / 100.0f);
							SDK::FString DistanceText(DistanceBuffer);
							SDK::FVector2D TextPosition(BoxX, BoxY - 20);
							Canvas->K2_DrawText(SDK::UEngine::GetEngine()->SmallFont, DistanceText, TextPosition,
								SDK::FVector2D(1, 1),
								SDK::FLinearColor(1, 1, 1, 1), 0, SDK::FLinearColor(0, 0, 0, 1),
								SDK::FVector2D(1, 1), true, true, true, SDK::FLinearColor(0, 0, 0, 1));
						}
					}
				}
			}
		}
	}
}

void Aimbot(SDK::UCanvas* Canvas)
{
	if (!IsValid(Canvas) || isgoodaddr(Canvas) == 0)return;
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return;
	const auto LocalPawn = PlayerController->K2_GetPawn();
	if (!IsValid(LocalPawn) || isgoodaddr(LocalPawn) == 0)return;
	const auto LocalLocation = LocalPawn->K2_GetActorLocation();
	const auto Camera = PlayerController->PlayerCameraManager;
	if (!IsValid(Camera) || isgoodaddr(Camera) == 0)return;
	SDK::FVector  MyLocation = Camera->GetCameraLocation();
	SDK::FRotator MyRotation = Camera->GetCameraRotation();
	SDK::ACharacter* player = static_cast<SDK::ACharacter*>(LocalPawn);
	if (!IsValid(player) || isgoodaddr(player) == 0)return;
	for (int i = 0; i < World->Levels.Num(); ++i)
	{
		const auto Level = World->Levels[i];
		if (!IsValid(Level) || isgoodaddr(Level) == 0) continue;
		for (int j = 0; j < Level->Actors.Num(); ++j)
		{
			const auto Actor = Level->Actors[j];
			if (!IsValid(Actor) || isgoodaddr(Actor) == 0) continue;
			if (Actor->IsA(SDK::ACharacter::StaticClass()))
			{
				SDK::AVOblivionPlayerCharacter* AimTarget = static_cast<SDK::AVOblivionPlayerCharacter*>(Actor);
				if (!IsValid(AimTarget) || isgoodaddr(AimTarget) == 0)continue;
				if (AimTarget->IsDead())continue;
				if (PlayerController->LineOfSightTo(AimTarget, SDK::FVector{0, 0, 0}, false))
				{
					const auto Mesh = AimTarget->Mesh;
					if (!IsValid(Mesh) || isgoodaddr(Mesh) == 0) continue;
					auto gMath = reinterpret_cast<SDK::UKismetMathLibrary*>(SDK::UKismetMathLibrary::StaticClass());
					if (!IsValid(gMath) || isgoodaddr(gMath) == 0) continue;

					SDK::FVector HeadLocation = BoneToLocation(AimTarget, 1);
					if (HeadLocation.X == 0 && HeadLocation.Y == 0) continue;
					SDK::FRotator AimRotation = gMath->FindLookAtRotation(MyLocation, HeadLocation);
					auto Location = AimTarget->K2_GetActorLocation();
					const SDK::FVector DifferenceVector = Location - LocalLocation;
					const float Distance = std::sqrt(DifferenceVector.X * DifferenceVector.X + DifferenceVector.Y * DifferenceVector.Y + DifferenceVector.Z * DifferenceVector.Z);
					if (Distance / 100.f < AimDistance)
					{
						int32_t ScreenWidth, ScreenHeight;
						GetVportSize(Canvas, PlayerController, &ScreenWidth, &ScreenHeight);
						float CenterX = ScreenWidth / 2.0f;
						float CenterY = ScreenHeight / 2.0f;
						auto HeadLoc2D = BoneToScreenLocation(PlayerController, AimTarget, j);	SDK::ACharacter* player = static_cast<SDK::ACharacter*>(LocalPawn);
						if (!IsValid(player) || isgoodaddr(player) == 0)return;
						const float Dist2D = Calculate2DDistance(HeadLoc2D, SDK::FVector2D(CenterX, CenterY));
						if (Dist2D < AimFOV && GetAsyncKeyState(VK_RBUTTON) & 0x8000)
						{
							PlayerController->ClientSetRotation(AimRotation, false);
						}
					}
				}
			}
		}
	}
}

void DrawFOVCircle(SDK::UCanvas* Canvas, float FOVRadius)
{
	if (!IsValid(Canvas) || isgoodaddr(Canvas) == 0)return;

	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return;
	const auto LocalPawn = PlayerController->K2_GetPawn();
	if (!IsValid(LocalPawn) || isgoodaddr(LocalPawn) == 0)return;

	int32_t ScreenWidth, ScreenHeight;
	GetVportSize(Canvas, PlayerController, &ScreenWidth, &ScreenHeight);

	const float CenterX = ScreenWidth / 2.0f;
	const float CenterY = ScreenHeight / 2.0f;

	constexpr int32_t NumSegments = 100;

	for (int32_t i = 0; i <= NumSegments; i++)
	{
		const float Angle1 = static_cast<float>(i) / static_cast<float>(NumSegments) * 2.0f * M_PI;
		const float Angle2 = static_cast<float>(i + 1) / static_cast<float>(NumSegments) * 2.0f * M_PI;

		const float X1 = CenterX + FOVRadius * std::cos(Angle1);
		const float Y1 = CenterY + FOVRadius * std::sin(Angle1);
		const float X2 = CenterX + FOVRadius * std::cos(Angle2);
		const float Y2 = CenterY + FOVRadius * std::sin(Angle2);

		Canvas->K2_DrawLine(SDK::FVector2D(X1, Y1), SDK::FVector2D(X2, Y2), 1.0f, SDK::FLinearColor(1, 1, 1, 1.0f));
	}
}


void SlyFly(bool Fly)
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return;
	const auto LocalPawn = PlayerController->K2_GetPawn();
	if (!IsValid(LocalPawn) || isgoodaddr(LocalPawn) == 0)return;
	const auto OblivionChr = static_cast<SDK::AVOblivionPlayerCharacter*>(LocalPawn);
	if (!IsValid(OblivionChr) || isgoodaddr(OblivionChr) == 0)return;
	if (Fly)OblivionChr->ClientCheatFly();
	if (!Fly)OblivionChr->ClientCheatWalk();
}

void SlyGhost(bool Ghost)
{
	SDK::UWorld* World = SDK::UWorld::GetWorld();
	if (!IsValid(World) || isgoodaddr(World) == 0)return;
	const auto OwningGame = World->OwningGameInstance;
	if (!IsValid(OwningGame) || isgoodaddr(OwningGame) == 0)return;
	const auto LocalPlayer = OwningGame->LocalPlayers[0];
	if (!IsValid(LocalPlayer) || isgoodaddr(LocalPlayer) == 0)return;
	const auto PlayerController = LocalPlayer->PlayerController;
	if (!IsValid(PlayerController) || isgoodaddr(PlayerController) == 0)return;
	const auto LocalPawn = PlayerController->K2_GetPawn();
	if (!IsValid(LocalPawn) || isgoodaddr(LocalPawn) == 0)return;
	const auto OblivionChr = static_cast<SDK::AVOblivionPlayerCharacter*>(LocalPawn);
	if (!IsValid(OblivionChr) || isgoodaddr(OblivionChr) == 0)return;
	if (Ghost)OblivionChr->ClientCheatGhost();
	if (!Ghost)OblivionChr->ClientCheatWalk();
}



