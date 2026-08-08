// =============================================================================
// UI_InteractionMenu_AddNameplateLabel_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fd50
// Address:   0x0082fd50 – 0x0082fe20 exclusive (autoassault.exe, base 0x400000)
// Size:      0xD0 (208 B); epilogue pop esi; pop ebp; add esp,8; ret (C3)
// System:    interaction menu / social UI (skills-abilities partition residual)
// Generated: 2026-08-05 MEGA-084 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082fd50 (plate-only alias; retired for role)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create a non-interactive
// nameplate label button for the resolved owner/target. Label text comes from
// the object's display-name getter (vtbl+0x160). Color is chosen from two
// ARGB constants by the target's +0x6B4 numeric field. Button id 0x1117F;
// stored at host +0x53C.
//
// ABI (parent-preserved registers — decompiler unaff_EBX / unaff_EDI):
//   EDI = menu host*
//   EBX = owner/target object*  (parent: EBP = target.vtbl+0x210(0); mov ebx,ebp)
//   ret 0 (no stack cleanup beyond local frame)
//
// Parent: FUN_0082fe20 UI_InteractionMenu_PopulateTargetButtons_Inferred
//   call sites: 0x0082FEC0 (Name-first order), 0x0082FF22 (Name-last order).
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;

// vtbl helpers (byte offsets sealed from decompile + disassemble_function).
// Object adj/RTTI chain + vtbl+0x160 → display name (const char* / string*)
// host->vtbl[0x444/4](xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*
// btn->vtbl[0x1D8/4](label, 1, 1)
// btn->vtbl[0xD4/4](0)           // disable / non-interactive
// btn->vtbl[0x15C/4](1, color*)  // set color
// btn->vtbl[0x1E4/4](1)          // post-setup show/enable chrome

static constexpr uint32_t kBtnIdNameplate = 0x1117F;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";
static constexpr uint32_t kColorLow6B4 = 0xFF1EA0B4u;   // +0x6B4 < 1
static constexpr uint32_t kColorHigh6B4 = 0xFFA01EB4u;  // +0x6B4 >= 1

// Register-arg fragment: EDI=menu, EBX=target. No C++ thiscall formals.
void UI_InteractionMenu_AddNameplateLabel_Inferred(
    /* EDI */ MenuHost* menu,
    /* EBX */ Object* target)
{
  // --- display name via adj chain + vtbl+0x160 ---
  // asm: mov eax,[ebx+4]; mov ecx,[eax+4]; mov edx,[ecx+ebx+4];
  //      lea ecx,[ecx+ebx+4]; call [edx+0x160]
  auto* adjRoot = *(void***)((char*)target + 4);
  auto* adjMid = *(void***)((char*)adjRoot + 4);
  auto* adjSelf = (void**)((char*)adjMid + (uintptr_t)target + 4);
  auto getName = *(const char* (**)(void*))(*(uintptr_t*)adjSelf + 0x160);
  const char* name = getName(adjSelf);

  // --- create button ---
  auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))
      (*(uintptr_t*)menu + 0x444);
  UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdNameplate, 0xFFFFFFFFu);

  if (btn != nullptr) {
    auto setText = *(void (**)(UiButton*, const char*, int, int))
        (*(uintptr_t*)btn + 0x1D8);
    setText(btn, name, 1, 1);
  }

  // host+0x53C = EDI[0x14F]
  *(UiButton**)((char*)menu + 0x53C) = btn;

  if (btn == nullptr) {
    return;
  }

  // Always non-interactive nameplate (not an action pack).
  auto disable = *(void (**)(UiButton*, int))(*(uintptr_t*)btn + 0xD4);
  disable(btn, 0);

  uint32_t color;
  if (*(int*)((char*)target + 0x6B4) < 1) {
    color = kColorLow6B4;
  } else {
    color = kColorHigh6B4;
  }

  auto setColor = *(void (**)(UiButton*, int, uint32_t*))
      (*(uintptr_t*)btn + 0x15C);
  setColor(btn, 1, &color);

  *(uint32_t*)((char*)btn + 0x170) = 0xFFFFFFFEu;

  auto finalize = *(void (**)(UiButton*, int))(*(uintptr_t*)btn + 0x1E4);
  finalize(btn, 1);
}
