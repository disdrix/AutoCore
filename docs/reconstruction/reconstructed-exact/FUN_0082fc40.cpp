// =============================================================================
// FUN_0082fc40  (Ghidra twin of UI_InteractionMenu_AddTrade_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0082fc40
// Address:   0x0082fc40 – 0x0082fd4a exclusive (autoassault.exe, base 0x400000)
// Size:      0x10A (266 B); RET (C3)
// System:    interaction menu / Trade UI pack
// Generated: 2026-08-05 MEGA-077 dual — Ghidra-name twin; prefer named clean.
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern int* DAT_00d1b6d8;
extern float DAT_00aaa674; // 1600.0f

// Register contract (parent-preserved): ESI = menu host*, EBX = target Object*
// ret 0
void FUN_0082fc40(void)
{
  float fVar1;
  float fVar2;
  float fVar3;
  int* piVar4;
  float* pfVar5;
  // unaff_EBX / unaff_ESI recovered as EBX / ESI by disassembly + call sites
  int unaff_EBX;   // target
  int* unaff_ESI;  // menu host

  if ((*(int*)(unaff_EBX + 0x6b4) < 1) || (0 < *(int*)(DAT_00d1b6d8 + 0x6b4))) {
    piVar4 = (int*)(**(code**)(*unaff_ESI + 0x444))(
        "i_m_int_2d_btn_generic.xml", 0, 0x11175, 0xffffffff);
    if (piVar4 != (int*)0x0) {
      (**(code**)(*piVar4 + 0x1d8))("Trade", 1, 1);
    }
    unaff_ESI[0x154] = (int)piVar4;

    pfVar5 = (float*)(**(code**)(*(int*)(*(int*)(*(int*)(unaff_EBX + 4) + 4) + 4 + unaff_EBX) +
                                 0x1a0))();
    fVar1 = *pfVar5;
    fVar2 = pfVar5[1];
    fVar3 = pfVar5[2];

    pfVar5 = (float*)(**(code**)(*(int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                         DAT_00d1b6d8) + 0x1a0))();

    if (((int*)unaff_ESI[0x154] != (int*)0x0) &&
        (DAT_00aaa674 <
         (fVar3 - pfVar5[2]) * (fVar3 - pfVar5[2]) +
             (fVar2 - pfVar5[1]) * (fVar2 - pfVar5[1]) +
             (fVar1 - *pfVar5) * (fVar1 - *pfVar5))) {
      (**(code**)(*(int*)unaff_ESI[0x154] + 0xd4))(0);
    }
  }
  return;
}
