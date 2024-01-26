#pragma once
#include "engine.h"
#include "global.h"
#include <windows.h>

class UObject {
public:
	FName get_name() {
		return *(FName*)(uintptr_t(this) + 0x18);
	}

	std::string GetName(FName fName)
	{
		return fName.GetName();
	}

	static UObject* static_find_object(UObject* klass, UObject* outer, const wchar_t* name, bool exact) {
		return reinterpret_cast<UObject * (*)(UObject*, UObject*, const wchar_t*, bool)>(global::function::lpfnFindObject)(klass, outer, name, exact);
	}

	void process_event(UObject* function, void* args) {
		return reinterpret_cast<void (*)(UObject*, UObject*, void*)>(global::function::lpfnProcessEvent)(this, function, args);
	}

	void process_event(void* obj, UObject* function, void* args) {
		auto vtable = *reinterpret_cast<void***>(obj);
		return reinterpret_cast<void (*)(void*, UObject*, void*)>(vtable[0x4C])(obj, function, args);
	}
};

class UEngine : public UObject {
public:
	static inline UEngine** GUEngine = nullptr;
	UObject* get_font() {
		return *(UObject**)((uintptr_t)this + global::offset::EngineFont);
	}

	class UGameViewportClient* get_viewportclient()
	{
		return *(UGameViewportClient**)((uintptr_t)this + global::offset::GameViewport);
	}
};

class UGameViewportClient : public UObject {
public:
	class UWorld* get_world()
	{
		return *(UWorld**)((uintptr_t)this + global::offset::World);
	}

	class UGameinstance* get_game_instance()
	{
		return *(UGameinstance**)((uintptr_t)this + global::offset::GameInstance);
	}
};

class UWorld : public UObject {
public:
	PAD(0x30);
	class ULevel* PersistentLevel;//0x30
	PAD(0x108);//0x38
	TArray<class ULevel*> Levels; // 0x140(0x10)
};

class ULevel : public UObject {
public:
	PAD(0x98);
	TArray<class AActor*> Acotr_Array;
};

class APlayerController : public UObject {
public:
	bool is_key_down(FKey key) {
		struct {
			FKey key;
			bool return_value;
		} params = { key };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerController.IsInputKeyDown", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	bool w2s(FVector world_location, FVector2D* screen_location) {
		struct {
			FVector world_location;
			FVector2D screen_location;
			bool return_value;
		} params = { world_location, FVector2D(), true };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerController.ProjectWorldLocationToScreen", false);
		this->process_event(this, function, &params);
		*screen_location = params.screen_location;
		return params.return_value;
	}

	FVector2D get_mouse_position() {
		struct {
			float x;
			float y;
			bool ret;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerController.GetMousePosition", false);
		this->process_event(this, function, &params);
		return FVector2D(params.x, params.y);
	}

	class player_pawn* get_pawn() {
		struct {
			class player_pawn* return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Controller.K2_GetPawn", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	class APlayerCameraManager* get_player_camera_manager()
	{
		return *(class APlayerCameraManager**)((uintptr_t)this + global::offset::PlayerCameraManager);
	}

	void SetControlRotation(FRotator NewRotation)
	{
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Controller.SetControlRotation", false);
		FRotator params;
		params = NewRotation;
		this->process_event(this, function, &params);
	}
};

class ULocalPlayer : public UObject {
public:
	UGameViewportClient* get_viewport() {
		return *(UGameViewportClient**)((uintptr_t)this + global::offset::ViewportClient);
	}

	APlayerController* get_playercontro()
	{
		return*(APlayerController**)((uintptr_t)this + global::offset::PlayerController);
	}
};

class UGameinstance : public UObject {
public:
	TArray<ULocalPlayer*> get_local_players() {
		return *(TArray<ULocalPlayer*>*)((uintptr_t)this + global::offset::LocalPlayers);
	}
};

class AActor : public UObject {
public:
	void enable_input(UObject* playercontroller) {
		struct {
			UObject* playercontroller;
		} params = { playercontroller };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Actor.EnableInput", false);
		this->process_event(this, function, &params);
	}

	void disable_input(UObject* playercontroller) {
		struct {
			UObject* playercontroller;
		} params = { playercontroller };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Actor.DisableInput", false);
		this->process_event(this, function, &params);
	}

	class USceneComponent* K2_GetRootComponent()
	{
		class USceneComponent* params = {};
		static UObject* function;
		if (!function)function = UObject::static_find_object(nullptr, nullptr, L"Actor.K2_GetRootComponent", false);
		this->process_event(this, function, &params);
		return params;
	}

	class APlayerState* GetPlayerState()
	{
		return *(APlayerState**)((uintptr_t)this + global::offset::PlayerState);
	}

	class Mesh* Getmesh()
	{
		return *(Mesh**)((uintptr_t)this + global::offset::PlayerMesh);
	}

	FRotator GetActorRotation() {
		struct {
			FRotator return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Actor.K2_GetActorRotation", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	FVector GetActorLocation() {
		struct {
			FVector return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Actor.K2_GetActorLocation", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	FRotator GetBaseAimRotation()
	{
		FRotator params = {};
		static UObject* function = nullptr;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Pawn.GetBaseAimRotation", false);
		this->process_event(this, function, &params);
		return params;
	}

	bool IsDead()
	{
		bool params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"M1Character.IsDead", false);
		this->process_event(this, function, &params);
		return params;
	}

	bool K2_TeleportTo(FVector DestLocation, FRotator DestRotation)
	{
		struct
		{
			FVector DestLocation;
			FRotator DestRotation;
			bool ret;
		}params = { DestLocation,DestRotation };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Actor.K2_TeleportTo", false);
		this->process_event(this, function, &params);
		return params.ret;
	}// Function Engine.Actor.K2_TeleportTo


	class UPalDamageReactionComponent* get_DamageReactionComponent()
	{
		return *(UPalDamageReactionComponent**)((uint64_t)this + global::offset::DamageReactionComponent);
	}

	class UPalCharacterParameterComponent* get_ParameterComponent()
	{
		return *(UPalCharacterParameterComponent**)((uint64_t)this + global::offset::CharacterParameterComponent);
	}

	class UPalActionComponent* get_PalActionComponent()
	{
		return *(UPalActionComponent**)((uint64_t)this + global::offset::ActionComponent);
	}

	void ReviveCharacter_ToServer(int32_t HP)
	{
		int32_t params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacter.ReviveCharacter_ToServer", false);
		this->process_event(this, function, &params);
	}

	class UPalShooterComponent* get_shooterComponent()
	{
		return *(UPalShooterComponent**)((uint64_t)this + global::offset::ShooterComponent);
	}
};

class UPalShooterComponent : public UObject
{
public:
	class APalWeaponBase* get_weaponBase()
	{
		return *(APalWeaponBase**)((uint64_t)this + global::offset::HasWeapon);
	}
};

class APalWeaponBase : public UObject
{
public:
	class UPalStaticWeaponItemData* get_weaponItem()
	{
		return *(UPalStaticWeaponItemData**)((uint64_t)this + global::offset::ownWeaponStaticData);
	}
};

class UPalStaticWeaponItemData : public UObject
{
public:
	void set_weapon_data(float A, int B)
	{
		*(float*)((uint64_t)this + global::offset::SneakAttackRate) = A;
		*(int*)((uint64_t)this + global::offset::AttackValue) = B;
	}
};

class UPalActionComponent : public UObject
{
public:
	class UPalActionBase* GetCurrentAction()
	{
		class UPalActionBase* params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalActionComponent.GetCurrentAction", false);
		this->process_event(this, function, &params);
		return params;
	}
};

class UPalActionBase : public UObject
{
public:
	void TickAction(float DeltaTime)
	{
		float params = DeltaTime;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalActionBase.TickAction", false);
		this->process_event(this, function, &params);
	}
};

class UPalDamageReactionComponent : public UObject
{
public:
	void SlipDamage(int32_t Damage, bool ShieldIgnore)
	{
		struct
		{
			int32_t Damage;
			bool ShieldIgnore;
		}params = { Damage,ShieldIgnore };
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalDamageReactionComponent.SlipDamage", false);
		this->process_event(this, function, &params);
	}

	void PopupDamageBySlipDamage_ToALL(int32_t Damage)
	{
		int32_t params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalDamageReactionComponent.PopupDamageBySlipDamage_ToALL", false);
		this->process_event(this, function, &params);
	}
};

class UPalCharacterParameterComponent : public UObject
{
public:
	FString GetNickname()
	{
		FString params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.GetNickname", false);
		this->process_event(this, function, &params);
		return params;
	}

	FFixedPoint64 GetMaxHP()
	{
		FFixedPoint64 params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.GetMaxHP", false);
		this->process_event(this, function, &params);
		return params;
	}

	FFixedPoint64 GetHP()
	{
		FFixedPoint64 params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.GetHP", false);
		this->process_event(this, function, &params);
		return params;
	}

	int32_t GetLevel()
	{
		int32_t params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.GetLevel", false);
		this->process_event(this, function, &params);
		return params;
	}

	bool IsDead()
	{
		bool params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.IsDead", false);
		this->process_event(this, function, &params);
		return params;
	}

	bool IsOtomo()
	{
		bool params;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.IsOtomo", false);
		this->process_event(this, function, &params);
		return params;
	}


	void SetMaxSP(int64_t NewMaxSP)
	{
		int64_t params = NewMaxSP;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.SetMaxSP", false);
		this->process_event(this, function, &params);
	}

	void SetSP(int64_t NewSP)
	{
		int64_t params = NewSP;
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalCharacterParameterComponent.SetSP", false);
		this->process_event(this, function, &params);
	}
};

class APlayerState : public UObject {
public:

	FString GetPlayerName()
	{
		FString params;
		static UObject* function;
		if (!function)function = UObject::static_find_object(nullptr, nullptr, L"PlayerState.GetPlayerName", false);
		this->process_event(this, function, &params);
		return params;
	}
};

class Mesh : public UObject {
public:
	int32_t get_num_bones() {
		struct {
			int32_t return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"SkinnedMeshComponent.GetNumBones", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	FName GetBoneName(uint32_t index)
	{
		static UObject* function = nullptr;
		if (!function)
			function = UObject::static_find_object(nullptr, nullptr, L"SkinnedMeshComponent.GetBoneName", false);
		struct
		{
			INT index;
			FName ReturnValue;
		}params;
		params.index = index;
		this->process_event(this, function, &params);
		return params.ReturnValue;
	}

	FVector get_bone_location(int32_t index) {
		FMatrix out_matrix = { };
		reinterpret_cast<FMatrix* (*)(Mesh*, FMatrix*, int32_t)>(global::function::lpfnGetBoneMatrixF)(this, &out_matrix, index);

		return FVector(out_matrix.m[3][0], out_matrix.m[3][1], out_matrix.m[3][2]);
	}

	int GetHeadIndex(const char* pos)
	{
		for (int i = 0; i < 72; i++)
		{
			auto bonename = this->GetBoneName(i).GetName();
			if (bonename.find(pos) != std::string::npos)
			{
				return i;
			}
		}
		return 0;
	}

	inline void GetAllBoneName();

	inline int GetBoneIndex(BoneFNames bone);

	FVector2D GetBone(int  index, class APlayerController* PlayerController)
	{
		FVector WorldLocation = this->get_bone_location(index);
		FVector2D ScreenLocation;
		if (PlayerController->w2s(WorldLocation, &ScreenLocation))return ScreenLocation;
		return { 0,0 };
	}

	void SetRenderCustomDepth(bool bValue)
	{
		struct
		{
			bool bValue;
		}params = { bValue };
		static UObject* function = nullptr;
		if (!function)
			function = UObject::static_find_object(nullptr, nullptr, L"PrimitiveComponent.SetRenderCustomDepth", false);
		this->process_event(this, function, &params);
	}

	void SetCustomDepthStencilValue(int32_t Value)
	{
		struct
		{
			int32_t Value;
		}params;
		static UObject* function = nullptr;
		if (!function)
			function = UObject::static_find_object(nullptr, nullptr, L"PrimitiveComponent.SetCustomDepthStencilValue", false);
		this->process_event(this, function, &params);
	}
};

class APlayerCameraManager : public UObject
{
public:
	FRotator get_camera_rotation() {
		struct {
			FRotator return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerCameraManager.GetCameraRotation", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	FVector get_camera_location() {
		struct {
			FVector return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerCameraManager.GetCameraLocation", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	float get_fov_angle() {
		struct {
			float return_value;
		} params = { };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PlayerCameraManager.GetFOVAngle", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}
};

class player_pawn : public AActor {
public:

};

class USceneComponent : public UObject
{
public:
	PAD(0x1D0);
	FVector servector;
};

class UCanvas : public UObject {
public:
	static inline UCanvas* GUCanvas = nullptr;
	float clip_x() {
		return *(float*)(uintptr_t(this) + global::offset::CanvasClipX);
	}

	float clip_y() {
		return *(float*)(uintptr_t(this) + global::offset::CanvasClipY);
	}

	UObject* get_texture() {
		return *(UObject**)((uintptr_t)this + global::offset::DefaultTexture);
	}

	FVector2D k2_text_size(UObject* render_font, FString render_text, FVector2D scale) {
		struct {
			UObject* render_font;
			FString render_text;
			FVector2D scale;
			FVector2D return_value;
		} params = { render_font, render_text, scale };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Canvas.K2_TextSize", false);
		this->process_event(this, function, &params);
		return params.return_value;
	}

	void k2_draw_text(UObject* render_font, FString render_text, FVector2D screen_position, FVector2D scale, FLinearColor render_color, float kerning, FLinearColor shadow_color, FVector2D shadow_offset, bool center_x, bool center_y, bool outlined, FLinearColor outline_color) {
		struct {
			UObject* render_font;
			FString render_text;
			FVector2D screen_position;
			FVector2D scale;
			FLinearColor render_color;
			float kerning;
			FLinearColor shadow_color;
			FVector2D shadow_offset;
			bool center_x;
			bool center_y;
			bool outlined;
			FLinearColor outline_color;
		} params = { render_font, render_text, screen_position, scale, render_color, kerning, shadow_color, shadow_offset, center_x, center_y, outlined, outline_color };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Canvas.K2_DrawText", false);
		this->process_event(this, function, &params);
	}

	void k2_draw_line(FVector2D screen_position_a, FVector2D screen_position_b, float thickness, FLinearColor render_color) {
		struct {
			FVector2D screen_position_a;
			FVector2D screen_position_b;
			float thickness;
			FLinearColor render_color;
		} params = { screen_position_a, screen_position_b, thickness, render_color };

		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Canvas.K2_DrawLine", false);
		this->process_event(this, function, &params);
	}

	void k2_draw_texture(UObject* texture, FVector2D pos, FVector2D screensize, FLinearColor clr)
	{
		struct
		{
			UObject* Texture;
			FVector2D pos;
			FVector2D screensize;
			FVector2D CoordinatePosition;
			FVector2D CoordinateSize;
			FLinearColor RenderColor;
			uint8_t BlendMode;
			float Rotation;
			FVector2D PivotPoint;
		}params = { texture ,pos,screensize,{0,0},{1,1},clr,7U, 0.f,{0,0} };
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Canvas.K2_DrawTexture", false);
		this->process_event(this, function, &params);
	}

	void K2_DrawBox(FVector2D ScreenPosition, FVector2D ScreenSize, float Thickness, FLinearColor RenderColor)
	{
		struct {
			FVector2D ScreenPosition;
			FVector2D ScreenSize;
			float Thickness;
			FLinearColor RenderColor;
		} params = { ScreenPosition, ScreenSize, Thickness, RenderColor };
		static UObject* function;
		if (!function) function = UObject::static_find_object(nullptr, nullptr, L"Canvas.K2_DrawBox", false);
		this->process_event(this, function, &params);

	}
};

namespace library {
	class UGameplayStatics : public UObject {
	public:

		UGameinstance* get_game_instance(UObject* world_context_object) {
			struct {
				UObject* world_context_object;
				UGameinstance* return_value;
			} params = { world_context_object };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"GameplayStatics.GetGameInstance", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		TArray<UObject*> get_all_actors_of_class(UObject* world_context_object, UObject* actor_class) {
			struct {
				UObject* world_context_object;
				UObject* actor_class;
				TArray<UObject*> out_actors;
			} params = { world_context_object, actor_class };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"GameplayStatics.GetAllActorsOfClass", false);
			this->process_event(this, function, &params);
			return params.out_actors;
		}

		APlayerController* get_player_controller(UObject* world_context_object, int32_t player_index) {
			struct {
				UObject* world_context_object;
				int32_t player_index;
				APlayerController* return_value;
			} params = { world_context_object, player_index };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"GameplayStatics.GetPlayerController", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float get_world_delta_seconds(UObject* world_context_object) {
			struct {
				UObject* world_context_object;
				float return_value;
			} params = { world_context_object };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"GameplayStatics.GetWorldDeltaSeconds", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		APlayerCameraManager* get_player_camera_manager(UObject* world_context_object, std::int32_t player_index) {
			struct {
				UObject* world_context_object;
				std::int32_t player_index;
				APlayerCameraManager* return_value;
			} params = { world_context_object, player_index };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"GameplayStatics.GetPlayerCameraManager", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}
	};

	class UKismetSystemLibrary : public UObject {
	public:
		FString get_object_name(UObject* object) {
			struct {
				UObject* object;
				FString return_value;
			} params = { object };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetObjectName", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FString GetDisplayName(UObject* Object)
		{
			struct
			{
				UObject* object;
				FString ret;
			}params = { Object };
			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetDisplayName", false);
			this->process_event(this, function, &params);
			return params.ret;
		}

		FString GetClassDisplayName(UObject* Class)
		{
			struct
			{
				UObject* object;
				FString ret;
			}params = { Class };
			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetClassDisplayName", false);
			this->process_event(this, function, &params);
			return params.ret;
		}

		UObject* get_outer_object(UObject* object) {
			struct {
				UObject* object;
				UObject* return_value;
			} params = { object };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetOuterObject", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		void GetComponentBounds(USceneComponent* Component, FVector* Origin, FVector* BoxExtent, float* SphereRadius)
		{
			struct
			{
				USceneComponent* SceneComponent;
				FVector Origin;
				FVector BoxExtent;
				float SphereRadius = NULL;
			}params = { Component };

			static UObject* function;
			if (!function)function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetComponentBounds", false);
			this->process_event(this, function, &params);

			if (Origin != nullptr)
				*Origin = params.Origin;
			if (BoxExtent != nullptr)
				*BoxExtent = params.BoxExtent;
			if (SphereRadius != nullptr)
				*SphereRadius = params.SphereRadius;
		}
	};

	class UKismetStringLibrary : public UObject
	{
	public:
		FName string_to_name(FString in_string)
		{
			struct {
				FString in_string;
				FName return_value;
			} params = { in_string };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetStringLibrary.Conv_StringToName", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FString name_to_string(FName InName)
		{
			struct
			{
				FName InName;
				FString return_value;
			}params;
			params.InName = InName;

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetStringLibrary.Conv_NameToString", false);
			this->process_event(this, function, &params);
			return params.return_value;

		}

		FString build_string_float(FString append_to, FString prefix, float in_double, FString suffix) {
			struct {
				FString append_to;
				FString prefix;
				float in_double;
				FString suffix;
				FString return_value;
			} params = { append_to, prefix, in_double, suffix };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetStringLibrary.BuildString_Float", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}
	};

	class UKismetMathLibrary : public UObject
	{
	public:
		float round(float value) {
			return std::round(value);
		}

		float distance2d(FVector2D v1, FVector2D v2) {
			struct {
				FVector2D v1;
				FVector2D v2;
				float return_value;
			} params = { v1, v2 };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.Distance2D", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		double abs(double a) {
			struct {
				double a;
				double return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.Abs", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float sin(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.sin", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float cos(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.cos", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float tan(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.tan", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float asin(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.asin", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float acos(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.acos", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float atan(float a) {
			struct {
				float a;
				float return_value;
			} params = { a };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.atan", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float atan2(float y, float x) {
			struct {
				float y;
				float x;
				float return_value;
			} params = { y, x };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.Atan2", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float vector_distance(FVector v1, FVector v2) {
			struct {
				FVector v1;
				FVector v2;
				float return_value;
			} params = { v1, v2 };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.Vector_Distance", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FRotator find_look_at_rotation(FVector start, FVector target) {
			struct {
				FVector start;
				FVector target;
				FRotator return_value;
			} params = { start, target };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.FindLookAtRotation", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		float f_interp_to(float current, float target, float delta_time, float interp_speed) {
			struct {
				float current;
				float target;
				float delta_time;
				float interp_speed;
				FRotator return_value;
			} params = { current, target, delta_time, interp_speed };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.FInterpTo", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FRotator interp_to(FRotator current, FRotator target, float delta_time, float interp_speed) {
			struct {
				FRotator current;
				FRotator target;
				float delta_time;
				float interp_speed;
				FRotator return_value;
			} params = { current, target, delta_time, interp_speed };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.RInterpTo", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FRotator interp_to_constant(FRotator current, FRotator target, float delta_time, float interp_speed) {
			struct {
				FRotator current;
				FRotator target;
				float delta_time;
				float interp_speed;
				FRotator return_value;
			} params = { current, target, delta_time, interp_speed };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetMathLibrary.RInterpTo_Constant", false);
			this->process_event(this, function, &params);
			return params.return_value;
		}

		FBox GetComponentBounds(USceneComponent* Component)
		{
			struct
			{
				USceneComponent* SceneComponent;
				FVector Origin;
				FVector BoxExtent;
				float SphereRadius = NULL;
			}params;

			params.SceneComponent = Component;

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"KismetSystemLibrary.GetComponentBounds", false);
			this->process_event(this, function, &params);
			FBox box = {};
			box.Min = params.Origin - params.BoxExtent;
			box.Max = params.Origin + params.BoxExtent;
			return box;
		}

		static inline BOOL LineTraceSingle(UWorld* Uworld, FVector& Start, FVector& End, TArray<AActor*> ActorsToIgnore)
		{
			FHitResult UnKnowFHitResult = { };

			auto fnLineTraceSingle = reinterpret_cast<BOOL * (*)(UWorld*, FVector, FVector, CHAR, BOOL, TArray<AActor*>, CHAR, FHitResult*, BOOL)>(global::function::lpfnLineTraceSingleF);

			return !fnLineTraceSingle(Uworld, Start, End, NULL, TRUE, ActorsToIgnore, NULL, &UnKnowFHitResult, TRUE);
		}

	};

	class UPalUtility : public UObject
	{
	public:
		void GiveExpToAroundPlayerCharacter(UObject* WorldContextObject, FVector& Center, float Radius, float Exp, bool bCallDelegate)
		{
			struct {
				UObject* WorldContextObject;
				FVector& Center;
				float Radius;
				float Exp;
				bool bCallDelegate;
			}params = { WorldContextObject,Center,Radius,Exp,bCallDelegate };
			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalUtility.GiveExpToAroundPlayerCharacter", false);
			this->process_event(this, function, &params);

		}

		bool Teleport(AActor* Target, FVector& Location, FRotator& Rotation, bool bNoCheck, bool bAroundCheck)
		{
			struct
			{
				AActor* Target;
				FVector Location;
				FRotator Rotation;
				bool bNoCheck;
				bool bAroundCheck;
				bool ret;
			}params = { Target,Location,Rotation,bNoCheck,bAroundCheck };

			static UObject* function;
			if (!function) function = UObject::static_find_object(nullptr, nullptr, L"PalUtility.Teleport", false);
			this->process_event(this, function, &params);
			return params.ret;
		}// Function Pal.PalUtility.Teleport
	};


}

namespace defines 
{
	static library::UGameplayStatics* game_statics = nullptr;
	static library::UKismetSystemLibrary* system = nullptr;
	static library::UKismetStringLibrary* string = nullptr;
	static library::UKismetMathLibrary* math = nullptr;
	static library::UPalUtility* PalUtility = nullptr;

	static UObject* actor_player_class = nullptr;//Íæ¼Ò
	static UObject* acotr_monster_class = nullptr;//¹ÖÎï
	static UObject* actor_item1_class = nullptr;//ÅÁÂ³µ°
	static UObject* actor_item2_class = nullptr;//
	static UObject* actor_item3_class = nullptr;//
	static UObject* fonts = nullptr;
	static UObject* deftexture = nullptr;
	static uintptr_t address = NULL;
	static uintptr_t viewport = NULL;

	static ULONG32 FindOffset(const wchar_t* Class, const wchar_t* VarName)
	{
		ULONG64 temp = -1;
		ULONG64 CurrentObject = (ULONG64)UObject::static_find_object(nullptr, (UObject*)temp, Class, false);
		for (auto Property = *(uint64_t*)(CurrentObject + 0x50); Property; Property = *(uint64_t*)(Property + 0x20))
		{
			auto Type = *(ULONG64*)(Property + 0x8);
			if (!IsBadReadPtr((void*)Type, 8) && Type)
			{

				auto Property_FName = *(FName*)(Property + 0x28);

				auto Offset = *(ULONG32*)(Property + 0x4C);

				auto FFname = defines::string->name_to_string(Property_FName);

				if (wcscmp(FFname.c_str(), VarName) == 0)
				{
					return Offset;
				}
			}

		}

		return 0;

	}

	static bool init()
	{
		defines::game_statics = (library::UGameplayStatics*)UObject::static_find_object(nullptr, nullptr, L"Engine.Default__GameplayStatics", false);		if (!defines::game_statics)return false;
		defines::system = (library::UKismetSystemLibrary*)UObject::static_find_object(nullptr, nullptr, L"Engine.Default__KismetSystemLibrary", false);		if (!defines::system)return false;
		defines::string = (library::UKismetStringLibrary*)UObject::static_find_object(nullptr, nullptr, L"Engine.Default__KismetStringLibrary", false);		if (!defines::string)return false;
		defines::math = (library::UKismetMathLibrary*)UObject::static_find_object(nullptr, nullptr, L"Engine.Default__KismetMathLibrary", false);		if (!defines::math)return false;
		defines::PalUtility = (library::UPalUtility*)UObject::static_find_object(nullptr, nullptr, L"Pal.PalUtility", false); if (!defines::PalUtility) return false;

		defines::actor_player_class = UObject::static_find_object(nullptr, nullptr, L"Pal.PalPlayerCharacter", false);
		defines::acotr_monster_class = UObject::static_find_object(nullptr, nullptr, L"Pal.PalNPC", false);
		defines::actor_item1_class = UObject::static_find_object(nullptr, nullptr, L"Pal.PalMapObjectSpawnerPalEgg", false);//ÅÁÂ³µ°
		defines::actor_item2_class = UObject::static_find_object(nullptr, nullptr, L"Pal.PalMapObject", false);

		global::offset::GameViewport = FindOffset(L"Engine", L"GameViewport");
		global::offset::World = FindOffset(L"GameViewportClient", L"World");
		global::offset::GameInstance = FindOffset(L"GameViewportClient", L"GameInstance");

		global::offset::GameState = FindOffset(L"World", L"GameState");
		global::offset::PlayerMesh = FindOffset(L"Character", L"Mesh");
		global::offset::PlayerState = FindOffset(L"Pawn", L"PlayerState");
		global::offset::PlayerNamePrivate = FindOffset(L"PlayerState", L"PlayerNamePrivate");

		global::offset::PlayerController = FindOffset(L"Player", L"PlayerController");
		global::offset::ViewportClient = FindOffset(L"LocalPlayer", L"ViewportClient");
		global::offset::LocalPlayers = FindOffset(L"GameInstance", L"LocalPlayers");
		global::offset::PlayerCameraManager = FindOffset(L"PlayerController", L"PlayerCameraManager");

		global::offset::CanvasClipX = FindOffset(L"Canvas", L"ClipX");
		global::offset::CanvasClipY = FindOffset(L"Canvas", L"ClipY");
		global::offset::EngineFont = FindOffset(L"Engine", L"LargeFont");
		global::offset::CharacterMovement = FindOffset(L"Character", L"CharacterMovement");

		global::offset::DefaultTexture = FindOffset(L"Canvas", L"DefaultTexture");
		global::offset::CharacterParameterComponent = FindOffset(L"PalCharacter", L"CharacterParameterComponent");
		global::offset::SP = FindOffset(L"PalCharacterParameterComponent", L"SP");
		global::offset::IndividualParameter = FindOffset(L"PalCharacterParameterComponent", L"IndividualParameter");
		global::offset::SaveParameter = FindOffset(L"PalIndividualCharacterParameter", L"SaveParameter");
		global::offset::Health = FindOffset(L"PalIndividualCharacterSaveParameter", L"HP");
		global::offset::DamageReactionComponent = FindOffset(L"PalCharacter", L"DamageReactionComponent");
		global::offset::ActionComponent = FindOffset(L"PalCharacter", L"ActionComponent");
		global::offset::ShooterComponent = FindOffset(L"PalPlayerCharacter", L"ShooterComponent");//0x800
		global::offset::HasWeapon = FindOffset(L"PalShooterComponent", L"HasWeapon");//0x470
		global::offset::ownWeaponStaticData = FindOffset(L"PalWeaponBase", L"ownWeaponStaticData");//0x4A8
		global::offset::SneakAttackRate = FindOffset(L"PalStaticWeaponItemData", L"SneakAttackRate");//0x15C
		global::offset::AttackValue = FindOffset(L"PalStaticWeaponItemData", L"AttackValue");//0x160

		return true;
	}
}

inline void Mesh::GetAllBoneName()
{
	for (int i = 0; i < 150; i++)
	{
		FString bonename = defines::string->name_to_string(this->GetBoneName(i));
	}
}

inline int Mesh::GetBoneIndex(BoneFNames bone)
{
	for (int i = 0; i < 72; i++) {
		FString BoneName = defines::string->name_to_string(this->GetBoneName(i));

		if (wcscmp(BoneName.c_str(), L"None") == 0)continue;
		switch (bone)
		{
			case head:
				if (wcscmp(BoneName.c_str(), L"head") == 0)
				{
					return i;
				}
				break;
			case neck_01:
				if (wcscmp(BoneName.c_str(), L"neck_01") == 0)
				{
					return i;
				}
				break;
			case pelvis:
				if (wcscmp(BoneName.c_str(), L"pelvis") == 0)
				{
					return i;
				}
				break;
			case spine_01:
				if (wcscmp(BoneName.c_str(), L"spine_01") == 0)
				{
					return i;
				}
				break;
			case clavicle_l:
				if (wcscmp(BoneName.c_str(), L"clavicle_l") == 0)
				{
					return i;
				}
				break;
			case upperarm_l:
				if (wcscmp(BoneName.c_str(), L"upperarm_l") == 0)
				{
					return i;
				}
				break;
			case lowerarm_l:
				if (wcscmp(BoneName.c_str(), L"lowerarm_l") == 0)
				{
					return i;
				}
				break;
			case hand_l:
				if (wcscmp(BoneName.c_str(), L"hand_l") == 0)
				{
					return i;
				}
				break;
			case clavicle_r:
				if (wcscmp(BoneName.c_str(), L"clavicle_r") == 0)
				{
					return i;
				}
				break;
			case upperarm_r:
				if (wcscmp(BoneName.c_str(), L"upperarm_r") == 0)
				{
					return i;
				}
				break;
			case lowerarm_r:
				if (wcscmp(BoneName.c_str(), L"lowerarm_r") == 0)
				{
					return i;
				}
				break;
			case hand_r:
				if (wcscmp(BoneName.c_str(), L"hand_r") == 0)
				{
					return i;
				}
				break;
			case thigh_l:
				if (wcscmp(BoneName.c_str(), L"thigh_l") == 0)
				{
					return i;
				}
				break;
			case calf_l:
				if (wcscmp(BoneName.c_str(), L"calf_l") == 0)
				{
					return i;
				}
				break;
			case foot_l:
				if (wcscmp(BoneName.c_str(), L"foot_l") == 0)
				{
					return i;
				}
				break;
			case thigh_r:
				if (wcscmp(BoneName.c_str(), L"thigh_r") == 0)
				{
					return i;
				}
				break;
			case calf_r:
				if (wcscmp(BoneName.c_str(), L"calf_r") == 0)
				{
					return i;
				}
				break;
			case foot_r:
				if (wcscmp(BoneName.c_str(), L"foot_r") == 0)
				{
					return i;
				}
				break;
			default:
				break;
		}
	}
	return 0;
}
