// =============================================================================
// UI_InteractionMenu_AddTrade_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fc40
// Address:   0x0082fc40 – 0x0082fd4a exclusive (autoassault.exe, base 0x400000)
// Size:      0x10A (266 B); epilogue POP EDI; MOV ESP,EBP; POP EBP; RET (C3)
// System:    interaction menu / Trade UI pack (skills-abilities residual family)
// Generated: 2026-08-05 MEGA-077 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     UI_int_btn_generic_0082fc40 (plate-only alias — retired as primary)
// =============================================================================
//
// PURPOSE: On the interaction / radial menu host, create a "Trade" generic
// button for the target object, store the button pointer on the host at
// +0x550, and disable it when squared world-distance to the local player
// exceeds 1600.0f (range 40 units).
//
// ABI (parent-preserved registers — decompiler shows unaff_EBX / unaff_ESI):
//   ESI = menu host*
//   EBX = target object*
//   ret 0 (no stack cleanup)
//
// Parent: FUN_0082fe20 (UI_InteractionMenu_PopulateTargetButtons_Inferred)
//   call sites 0x0082fed7 (order-0) and 0x0082ff0b (order-≠0); both set
//   EBX = target via MOV EBX,EBP before CALL.
// =============================================================================

#include <cstdint>

struct Object;
struct UiButton;
struct MenuHost;

extern Object* DAT_00d1b6d8; // local player character
extern float DAT_00aaa674;  // 1600.0f — max trade range squared (40 units)

// vtbl helpers (byte offsets sealed from disassembly / decompile).
// host->vtbl[0x444/4](xml, 0, buttonId, 0xFFFFFFFF) -> UiButton*
// btn->vtbl[0x1D8/4](label, 1, 1)
// btn->vtbl[0xD4/4](0)                 // disable / hide
// object SharedBase chain -> vtbl[0x1A0/4]() -> float* {x,y,z}

static constexpr uint32_t kBtnIdTrade = 0x11175;
static constexpr const char* kXmlGeneric = "i_m_int_2d_btn_generic.xml";
static constexpr const char* kLabelTrade = "Trade";

void UI_InteractionMenu_AddTrade_Inferred(
    /* ESI */ MenuHost* menu,
    /* EBX */ Object* target)
{
  Object* local = DAT_00d1b6d8;

  // Gate on +0x6B4 (same family as convoy Invite/Kick pack).
  // Asm: cmp [ebx+0x6B4],1; jl body; cmp [local+0x6B4],1; jl exit
  if (!(*(int*)((char*)target + 0x6B4) < 1 ||
        (local != nullptr && *(int*)((char*)local + 0x6B4) > 0))) {
    return;
  }

  auto createBtn = *(UiButton* (**)(MenuHost*, const char*, int, uint32_t, uint32_t))
      (*(uintptr_t*)menu + 0x444);
  UiButton* btn = createBtn(menu, kXmlGeneric, 0, kBtnIdTrade, 0xFFFFFFFFu);
  if (btn != nullptr) {
    auto setText = *(void (**)(UiButton*, const char*, int, int))
        (*(uintptr_t*)btn + 0x1D8);
    setText(btn, kLabelTrade, 1, 1);
  }
  // menu+0x550 = ESI[0x154]
  *(UiButton**)((char*)menu + 0x550) = btn;

  // Target world position via SharedBase vtbl chain +0x1A0
  auto targetSb = *(uintptr_t*)((char*)target + 4);
  targetSb = *(uintptr_t*)(targetSb + 4);
  auto targetVt = *(uintptr_t*)(targetSb + (uintptr_t)target + 4);
  auto getPosTarget = *(float* (**)(void*))(targetVt + 0x1A0);
  float* tpos = getPosTarget((void*)(targetSb + (uintptr_t)target + 4));
  float tx = tpos[0];
  float ty = tpos[1];
  float tz = tpos[2];

  // Local player world position (same chain)
  auto localSb = *(uintptr_t*)((char*)local + 4);
  localSb = *(uintptr_t*)(localSb + 4);
  auto localVt = *(uintptr_t*)(localSb + (uintptr_t)local + 4);
  auto getPosLocal = *(float* (**)(void*))(localVt + 0x1A0);
  float* lpos = getPosLocal((void*)(localSb + (uintptr_t)local + 4));

  if (btn != nullptr) {
    float dx = tx - lpos[0];
    float dy = ty - lpos[1];
    float dz = tz - lpos[2];
    float distSq = dx * dx + dy * dy + dz * dz;
    // DAT_00aaa674 == 1600.0f; disable when farther than 40 units
    if (distSq > DAT_00aaa674) {
      auto disable = *(void (**)(UiButton*, int))(*(uintptr_t*)btn + 0xD4);
      disable(btn, 0);
    }
  }
}
