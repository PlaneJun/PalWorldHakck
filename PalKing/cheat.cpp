#include <chrono>
#include "cheat.h"
#include "render.hpp"
#include "vmt.hpp"
#include "utils.h"
#include <comutil.h>  
#pragma comment(lib, "comsuppw.lib")

cheat* cheat::instance_ = NULL;
using fnDrawTransitionSim = void(*)(UGameViewportClient* viewport, UCanvas* canvas);
fnDrawTransitionSim g_lpfnOriginDrawTransitionSim = 0;

void hk_DrawTransitionSim_proxy(UGameViewportClient* viewport, UCanvas* canvas)
{
	cheat::get_instance()->render(viewport, canvas);
	return g_lpfnOriginDrawTransitionSim(viewport, canvas);
}

int get_curt_fps()
{
	static int count = 0;
	static auto last = std::chrono::high_resolution_clock::now();
	auto now = std::chrono::high_resolution_clock::now();
	static int fps = 0;

	count++;

	if (std::chrono::duration_cast<std::chrono::milliseconds>(now - last).count() > 1000) {
		fps = count;
		count = 0;
		last = now;
	}

	return fps;
}

void remove_hook_vtbl(int index)
{
	auto vtable = *(uintptr_t**)defines::viewport;
	int vtable_size = 0;
	do vtable_size += 1;
	while (*(uintptr_t*)(uintptr_t(vtable) + (vtable_size * 8)));

	auto original_virtual_function = (void*)vtable[index];

	uintptr_t* fake_vtable = new uintptr_t[vtable_size * 8];

	for (int i = 0; i < vtable_size; i++) {
		if (i == index) continue;
		fake_vtable[i] = *(uintptr_t*)(uintptr_t(vtable) + (i * 8));
	}
	fake_vtable[index] = defines::address;
	*(uintptr_t**)defines::viewport = fake_vtable;
}

std::wstring s2ws(const std::string& s)
{
	_bstr_t t = s.c_str();
	wchar_t* pwchar = (wchar_t*)t;
	std::wstring result = pwchar;
	return result;
}

void draw_bone(Mesh* mesh, APlayerController* PlayerController, float lineless, FLinearColor clr)
{
	FVector2D headPos2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::head), PlayerController);
	FVector2D neckPos2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::neck_01), PlayerController);
	FVector2D spine_012D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::spine_01), PlayerController);
	FVector2D clavicle_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::clavicle_l), PlayerController);
	FVector2D upperarm_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::upperarm_l), PlayerController);
	FVector2D lowerarm_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::lowerarm_l), PlayerController);
	FVector2D hand_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::hand_l), PlayerController);
	FVector2D clavicle_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::clavicle_r), PlayerController);
	FVector2D upperarm_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::upperarm_r), PlayerController);
	FVector2D lowerarm_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::lowerarm_r), PlayerController);
	FVector2D hand_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::hand_r), PlayerController);
	FVector2D thigh_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::thigh_l), PlayerController);
	FVector2D calf_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::calf_l), PlayerController);
	FVector2D foot_l2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::foot_l), PlayerController);
	FVector2D thigh_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::thigh_r), PlayerController);
	FVector2D calf_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::calf_r), PlayerController);
	FVector2D foot_r2D = mesh->GetBone(mesh->GetBoneIndex(BoneFNames::foot_r), PlayerController);
	if (headPos2D.IsValid() &&
		neckPos2D.IsValid() &&
		spine_012D.IsValid() &&
		clavicle_l2D.IsValid() &&
		upperarm_l2D.IsValid() &&
		lowerarm_l2D.IsValid() &&
		hand_l2D.IsValid() &&
		clavicle_r2D.IsValid() &&
		upperarm_r2D.IsValid() &&
		lowerarm_r2D.IsValid() &&
		hand_r2D.IsValid() &&
		thigh_l2D.IsValid() &&
		calf_l2D.IsValid() &&
		foot_l2D.IsValid() &&
		thigh_r2D.IsValid() &&
		calf_r2D.IsValid() &&
		foot_r2D.IsValid()
		)
	{
		render::line(headPos2D, neckPos2D, clr, 1);

		render::line(neckPos2D, spine_012D, clr, 1);

		render::line(neckPos2D, clavicle_l2D, clr, 1);
		render::line(clavicle_l2D, upperarm_l2D, clr, 1);
		render::line(upperarm_l2D, lowerarm_l2D, clr, 1);
		render::line(lowerarm_l2D, hand_l2D, clr, 1);

		render::line(neckPos2D, clavicle_r2D, clr, 1);
		render::line(clavicle_r2D, upperarm_r2D, clr, 1);
		render::line(upperarm_r2D, lowerarm_r2D, clr, 1);
		render::line(lowerarm_r2D, hand_r2D, clr, 1);

		render::line(spine_012D, thigh_l2D, clr, 1);
		render::line(thigh_l2D, calf_l2D, clr, 1);
		render::line(calf_l2D, foot_l2D, clr, 1);

		render::line(spine_012D, thigh_r2D, clr, 1);
		render::line(thigh_r2D, calf_r2D, clr, 1);
		render::line(calf_r2D, foot_r2D, clr, 1);
	}
}

bool scan_data()
{
	uint64_t Base = utils::GetBase();
	global::function::lpfnFindObject = utils::PatternScan(Base, "48 8B C4 48 89 58 08 48 89 68 18 48 89 70 20 57 41 56 41 57 48 83 EC 60 48 83 FA FF", 0, false); if (!global::function::lpfnFindObject)return false;
	UEngine::GUEngine = reinterpret_cast<decltype(UEngine::GUEngine)>(utils::PatternScan(Base, "48 8B 05 ? ? ? ? 48 8B 88 ? ? ? ?", 7, true)); if (!UEngine::GUEngine)return false;
	global::function::lpfnLineTraceSingleF = utils::PatternScan(Base, "E8 ? ? ? ? 48 8B 4C 24 70 41 88 45 00 48 85 C9 74 ? E8 ? ? ? ? 48 8B 9C 24 60 02 00 00", 5, true); if (!global::function::lpfnLineTraceSingleF)return false;
	global::function::lpfnGetBoneMatrixF = utils::PatternScan(Base, "48 8B C4 48 89 58 20 55 56 57 48 8D A8 08 FF FF FF 48 81 EC E0 01 00 00 0F 29 70 D8 0F 29 78 C8", 0, false); if (!global::function::lpfnGetBoneMatrixF)return false;
	if (!defines::init()) return false;
}

cheat* cheat::get_instance()
{
	if (!instance_)
		instance_ = new cheat();

	return instance_;
}

void cheat::init()
{
	if (scan_data())
	{
		auto engine = *(UEngine**)(UEngine::GUEngine);
		auto viewportclient = engine->get_viewportclient();
		auto game_instance = viewportclient->get_game_instance();
		auto local_player = game_instance->get_local_players()[0];
		auto controller = local_player->get_playercontro();
		auto viewport = local_player->get_viewport();
		defines::viewport = (uintptr_t)viewport;
		defines::fonts = engine->get_font();
		g_lpfnOriginDrawTransitionSim = vmt::vmt<decltype(g_lpfnOriginDrawTransitionSim)>(uintptr_t(viewport), uintptr_t(hk_DrawTransitionSim_proxy), global::offset::vtbl_viewport_index);
	}
}

void cheat::render(UGameViewportClient* viewport, UCanvas* canvas)
{
	try
	{
		do
		{
			FVector2D screen_size = FVector2D(canvas->clip_x(), canvas->clip_y());
			FVector2D center = FVector2D(screen_size.x / 2, screen_size.y / 2);

			UWorld* world = viewport->get_world(); if (!world)break;
			ULevel* ulevle = world->PersistentLevel; if (!ulevle)break;
			TArray<AActor*> actor_array = *(TArray<AActor*>*)((uint64_t)ulevle + 0x98);
			UGameinstance* game_instance = defines::game_statics->get_game_instance(world); if (!game_instance)break;
			ULocalPlayer* local_player = game_instance->get_local_players()[0];
			APlayerController* controller = local_player->get_playercontro(); if (!controller)break;
			player_pawn* localplayer = controller->get_pawn();
			APlayerCameraManager* camera_manager = controller->get_player_camera_manager();
			FVector camera_location = camera_manager->get_camera_location();
			FRotator camera_rotation = camera_manager->get_camera_rotation();
			
			if (localplayer)
			{
				UPalCharacterParameterComponent* ParameterComponent = localplayer->get_ParameterComponent();
				if (ParameterComponent)
				{
					if (settings::players::无限体力)
					{
						*(int64_t*)((uint64_t)ParameterComponent + global::offset::SP) = 500000;
					}

					if (settings::players::无敌)
					{
						localplayer->ReviveCharacter_ToServer(int64_t(5000 * 10000000));
					}
				}

				if (camera_manager)
				{
					if (settings::players::游戏亮度)
					{
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light) = settings::players::亮度值;
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light+8) = settings::players::亮度值;
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light+0x10) = settings::players::亮度值;
					}
					else if (!settings::players::游戏亮度)
					{
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light) = 1;
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light + 8) = 1;
						*(double*)((uint64_t)camera_manager + global::offset::CameraManager_Light + 0x10) = 1;
					}
				}


				if (settings::players::秒杀)
				{
					UPalShooterComponent* shooterComponent = localplayer->get_shooterComponent();
					if (shooterComponent)
					{
						auto weaponBase = shooterComponent->get_weaponBase();
						if (weaponBase)
						{
							render::text(std::to_wstring((uint64_t)weaponBase).c_str(), {200,200}, Colors::White, 1.2, true, false, true);
							auto weaponItem = weaponBase->get_weaponItem();
							if (weaponItem)
							{
								weaponItem->set_weapon_data(settings::players::秒杀值 * 1.391f * settings::players::秒杀倍数, (int)(settings::players::秒杀值 * 1.4147f * settings::players::秒杀倍数));
							}
						}
					}
				}

				if (settings::players::加速)
				{
					if (GetAsyncKeyState(VK_OEM_3) != 0)
						*(float*)((uint64_t)localplayer + 0x64) = settings::players::加速倍数;
					else
						*(float*)((uint64_t)localplayer + 0x64) = 1.f;
				}
			}


			render::font = defines::fonts;
			render::world = world;
			render::canvas = canvas;
			render::controller = controller;
			render::screen_center = center;
			render::screen_size = screen_size;
			render::deftexture = canvas->get_texture();
			render::draw_menu();

			render::text((L"FPS:" + std::to_wstring(get_curt_fps())).c_str(), { 15,10 }, Colors::White, 1, false, true, false);

			if (GetAsyncKeyState(VK_END) & 1) 
			{
				settings::players::加速倍数 = 1.f;
				remove_hook_vtbl(global::offset::vtbl_viewport_index);
			}

			if (settings::players::显示怪物)
			{
				TArray<UObject*> monster_array = defines::game_statics->get_all_actors_of_class(world, defines::acotr_monster_class);
				for (int i = 0; i < monster_array.Num(); i++)
				{
					if (!monster_array.IsValidIndex(i))
						continue;

					AActor* monster = reinterpret_cast<AActor*>(monster_array[i]); 
					if (!monster)
						continue;

					UPalCharacterParameterComponent* Parameter = monster->get_ParameterComponent();
					if (Parameter->IsDead())
						continue;

					uint64_t hp = Parameter->GetHP().Value / 1000;
					uint64_t maxhp = Parameter->GetMaxHP().Value / 1000;
					FVector location = monster->GetActorLocation();
					bool IsVisible = defines::math->LineTraceSingle(world, camera_location, location, actor_array);
					FLinearColor clr = IsVisible ? Colors::Green : Colors::White;
					int32_t lv = Parameter->GetLevel();
					std::wstring strLevel = L"LV：" + std::to_wstring(lv);
					std::wstring strHealth = std::to_wstring(hp) + L"/" + std::to_wstring(maxhp);
					FVector2D screen;
					if (controller->w2s(location, &screen))
					{
						if (!screen.IsValid())continue;
						if (settings::players::显示名字)
						{
							render::text(strLevel.c_str(), screen, clr, 1.2, true, false, true);
							render::text(Parameter->GetNickname(), { screen.x,screen.y + 15 }, clr, 1.2, true, false, true);
						}
						if (settings::players::显示血量)
						{
							render::text(strHealth.c_str(), { screen.x,screen.y + 30 }, clr, 1.2, true, false, true);
						}
						if (settings::players::显示距离)
						{
							std::wstring dis = L"[ " + std::to_wstring((int)(camera_location.DistTo(location) / 100)) + L" ]";
							render::text(dis.c_str(), { screen.x,screen.y + 45 }, clr, 1.2, true, false, true);
						}
					}
				}
			}

			if (settings::players::显示玩家)
			{
				TArray<UObject*> player_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_player_class);
				for (int i = 0; i < player_array.Num(); i++)
				{
					if (!player_array.IsValidIndex(i))
						continue;

					AActor* player =reinterpret_cast<AActor*>(player_array[i]); 
					if (!player || player == localplayer)
						continue;

					UPalCharacterParameterComponent* Parameter = player->get_ParameterComponent();
					if (Parameter->IsDead())continue;
					uint64_t hp = Parameter->GetHP().Value / 1000;
					uint64_t maxhp = Parameter->GetMaxHP().Value / 1000;
					FVector location = player->GetActorLocation();
					bool IsVisible = defines::math->LineTraceSingle(world, camera_location, location, actor_array);
					FLinearColor clr = IsVisible ? Colors::HotPink : Colors::Yellow;
					location = { location.x,location.y,location.z - 100.f };
					int32_t lv = Parameter->GetLevel();
					std::wstring draw_Lv = L"LV：" + std::to_wstring(lv);
					std::wstring draw_text = std::to_wstring(hp) + L"/" + std::to_wstring(maxhp);
					FVector2D screen;
					if (controller->w2s(location, &screen))
					{
						if (!screen.IsValid())continue;
						Mesh* mesh = player->Getmesh();
						if (mesh)
						{
							draw_bone(mesh, controller, 1, clr);
						}
							
						if (settings::players::显示名字)
						{
							render::text(draw_Lv.c_str(), screen, clr, 1.2, true, false, true);
							render::text(Parameter->GetNickname(), { screen.x,screen.y + 15 }, clr, 1.2, true, false, true);
						}

						if (settings::players::显示血量)
							render::text(draw_text.c_str(), { screen.x,screen.y + 30 }, clr, 1.2, true, false, true);

						if (settings::players::显示距离)
						{
							std::wstring dis = L"[ " + std::to_wstring((int)(camera_location.DistTo(location) / 100)) + L" ]";
							render::text(dis.c_str(), { screen.x,screen.y + 45 }, clr, 1.2, true, false, true);
						}
					}
				}
			}
		} while (false);

	}
	catch (...)
	{

	}
}
