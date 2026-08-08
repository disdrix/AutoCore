// =============================================================================
// FUN_0082f9a0  (Ghidra-name twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082f9a0
// Address:   0x0082f9a0 – 0x0082fa59 exclusive (autoassault.exe, base 0x400000)
// Size:      0xB9 (185 B)
// System:    interaction menu / social UI
// Generated: 2026-08-05 MEGA-075 (mirror of named clean)
// Canonical named unit: UI_InteractionMenu_AddFriendsToggle.cpp
// Exactness: Behavior-preserving decompiler CF. Bit-exact vs EXE: OPEN.
// =============================================================================

#include <cstdint>

extern int DAT_00d1b6d8;
extern int DAT_00d1da2c;

extern "C" int FUN_00573a30(void* /* name pushed; thiscall ECX = list */);

// Decompiler signature void(void). Real operands (parent-preserved):
//   in_EAX    = target object*
//   unaff_EDI = menu host*
// Prefer UI_InteractionMenu_AddFriendsToggle for ports.
void FUN_0082f9a0(void)
{
  int in_EAX;       // target (EAX) — parent MOV EAX,EBP
  int* unaff_EDI;   // menu  (EDI) — parent MOV EDI,ESI
  uint32_t uVar1;
  int iVar2;
  int* piVar3;

  if ((*(int*)(in_EAX + 0x6b4) < 1) || (0 < *(int*)(DAT_00d1b6d8 + 0x6b4))) {
    if (DAT_00d1da2c != 0) {
      // target adjustor vtbl+0x160 → name
      uVar1 = (**(code**)(*(int*)(*(int*)(*(int*)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x160))();
      iVar2 = FUN_00573a30((void*)(uintptr_t)uVar1); // decompiler elides this=DAT_00d1da2c
      if (iVar2 != 0) {
        piVar3 = (int*)(**(code**)(*unaff_EDI + 0x444))(
            "i_m_int_2d_btn_generic.xml", 0, 0x1117a, 0xffffffff);
        if (piVar3 != (int*)0x0) {
          (**(code**)(*piVar3 + 0x1d8))("Remove from Friends", 1, 1);
        }
        unaff_EDI[0x159] = (int)piVar3; // +0x564
        return;
      }
    }
    piVar3 = (int*)(**(code**)(*unaff_EDI + 0x444))(
        "i_m_int_2d_btn_generic.xml", 0, 0x11177, 0xffffffff);
    if (piVar3 != (int*)0x0) {
      (**(code**)(*piVar3 + 0x1d8))("Add to Friends", 1, 1);
    }
    unaff_EDI[0x156] = (int)piVar3; // +0x558
  }
  return;
}
