// =============================================================================
// FUN_0082fd50  (Ghidra twin of UI_InteractionMenu_AddNameplateLabel_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fd50
// Address:   0x0082fd50 – 0x0082fe20 exclusive (autoassault.exe, base 0x400000)
// Size:      0xD0 (208 B); epilogue pop esi; pop ebp; add esp,8; ret (C3)
// System:    interaction menu / social UI
// Generated: 2026-08-05 MEGA-084 dual (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prefer:    UI_InteractionMenu_AddNameplateLabel_Inferred.cpp
// =============================================================================

#include <cstdint>

// EDI = menu host*; EBX = owner/target*; ret 0  (parent FUN_0082fe20)

void FUN_0082fd50(void)
{
  // Register-arg fragment — decompiler unaff_EBX / unaff_EDI.
  // Reconstructed with named types in UI_InteractionMenu_AddNameplateLabel_Inferred.cpp.

  // name = ObjectAdj(EBX).vtbl+0x160()
  // btn  = (*EDI + 0x444)("i_m_int_2d_btn_generic.xml", 0, 0x1117F, -1)
  // if (btn) (*btn + 0x1D8)(name, 1, 1)
  // *(EDI + 0x53C) = btn
  // if (!btn) return
  // (*btn + 0xD4)(0)
  // color = (*(int*)(EBX + 0x6B4) < 1) ? 0xFF1EA0B4u : 0xFFA01EB4u
  // (*btn + 0x15C)(1, &color)
  // *(uint32_t*)((char*)btn + 0x170) = 0xFFFFFFFEu
  // (*btn + 0x1E4)(1)
}
