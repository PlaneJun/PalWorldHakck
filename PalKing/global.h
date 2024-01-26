#pragma once
#include <stdint.h>

namespace global
{
	namespace offset
	{
		inline uint32_t vtbl_viewport_index = 0x6E;
		inline uint32_t EngineFont = NULL;
		inline uint32_t GameViewport = NULL;
		inline uint32_t World = NULL;
		inline uint32_t GameInstance = NULL;
		inline uint32_t CanvasClipX = NULL;
		inline uint32_t CanvasClipY = NULL;
		inline uint32_t LocalPlayers = NULL;
		inline uint32_t PlayerController = NULL;
		inline uint32_t PlayerState = NULL;
		inline uint32_t PlayerNamePrivate = NULL;
		inline uint32_t PlayerMesh = NULL;

		inline uint32_t ViewportClient = NULL;
		inline uint32_t CharacterMovement = NULL;
		inline uint32_t PlayerCameraManager = NULL;

		inline uint32_t CameraManager_Light = 0x2D0;

		inline uint32_t DefaultTexture = NULL;
		inline uint32_t GameState = NULL;

		inline uint32_t CharacterParameterComponent = NULL;
		inline uint32_t DamageReactionComponent = NULL;
		inline uint32_t ActionComponent = NULL;

		inline uint32_t ShooterComponent = NULL;
		inline uint32_t HasWeapon = NULL;
		inline uint32_t PalWeaponBase = NULL;
		inline uint32_t ownWeaponStaticData = NULL;
		inline uint32_t SneakAttackRate = NULL;
		inline uint32_t AttackValue = NULL;

		inline uint32_t SP = NULL;

		inline uint32_t IndividualParameter = NULL;
		inline uint32_t SaveParameter = NULL;
		inline uint32_t Health = NULL;
		inline uint32_t WeaponSlotControl = NULL;
	}

	namespace function
	{
		inline uintptr_t lpfnProcessEvent = NULL;
		inline uintptr_t lpfnFindObject = NULL;
		inline uintptr_t lpfnGetBoneMatrixF = NULL;
		inline uintptr_t lpfnGetNameByIndex = NULL;
		inline uintptr_t lpfnFreeObject = NULL;
		inline uintptr_t lpfnLineTraceSingleF = NULL;
		
	}
}


