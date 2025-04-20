#include "UIResourceSubManager.h"

void UIResourceSubManager::Preload_StatusToolbar() {
    auto mgr = D2DImageManager::GetInstance();
    mgr->AddImage("status_character_ico", L"assets/interfaces/status_ico.png", 1, 1);
    mgr->AddImage("status_character_bg", L"assets/interfaces/status_bg.png", 1, 1);
    mgr->AddImage("status_hp_bar", L"assets/interfaces/HPBar.png", 1, 1);
    mgr->AddImage("status_hp_bg", L"assets/interfaces/player_hp_barbg.png", 1, 1);
    mgr->AddImage("status_exp_bar", L"assets/interfaces/ExpBar.png", 1, 1);
    mgr->AddImage("status_exp_bg", L"assets/interfaces/player_exp_barbg.png", 1, 1);
    mgr->AddImage("status_level", L"assets/interfaces/level_box.png", 1, 1);
}

void UIResourceSubManager::Preload_QuickSlotToolbar() {
    auto mgr = D2DImageManager::GetInstance();
    mgr->AddImage("item_quick", L"assets/interfaces/item_quick.png", 1, 1);
    mgr->AddImage("search_quick", L"assets/interfaces/search_quick.png", 1, 1);
    mgr->AddImage("sleep_quick", L"assets/interfaces/sleep_quick.png", 1, 1);
    mgr->AddImage("inven_quick", L"assets/interfaces/inven_quick.png", 1, 1);
}

void UIResourceSubManager::Preload_TopRightUI() {
    auto mgr = D2DImageManager::GetInstance();
    mgr->AddImage("stair_ico", L"assets/interfaces/stair_ico.png", 1, 1);
    mgr->AddImage("guidebook_btn", L"assets/interfaces/guidebook_btn.png", 1, 1);
    mgr->AddImage("menu_btn", L"assets/interfaces/menu_btn.png", 1, 1);
}

void UIResourceSubManager::Preload_InventoryUI()
{
    auto mgr = D2DImageManager::GetInstance();
    mgr->AddImage("inventory_bg", L"assets/interfaces/inventory_bg.png", 1, 1);
    mgr->AddImage("inventory_slot", L"assets/interfaces/inventory_slot.png", 1, 1);
}

// ✅ 전체 리소스 초기화
void UIResourceSubManager::PreloadAll() {
    InitFontResources();                 // ⬅ 폰트 먼저
    Preload_StatusToolbar();
    Preload_QuickSlotToolbar();
    Preload_TopRightUI();
}