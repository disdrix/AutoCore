// =============================================================================
// FUN_0062ab70
// -----------------------------------------------------------------------------
// Stable ID: aa_0062ab70
// Address:   0x0062ab70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062ab70 @ 0x0062ab70
// Stable ID: aa_0062ab70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00600080×2, FUN_0062a5d0, FUN_0062ab70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall

FUN_0062ab70(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float unaff_EBX;

  float unaff_ESI;

  float unaff_EDI;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint16_t auStack_44 [2];

  int iStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ *puStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  int iStack_c;

  

  iVar1 = *(int *)(param_1 + 0xc);

  puVar2 = &local_70;

  (**(code **)(**(int **)(iVar1 + 0x3c) + 0x58))(param_5);

  (**(code **)(**(int **)((int)unaff_ESI + 0x3c) + 0x58))(param_5,&stack0xffffff78);

  local_70 = *param_5;

  uStack_6c = param_5[1];

  uStack_68 = param_5[2];

  uStack_64 = param_5[3];

  uStack_60 = param_5[4];

  uStack_5c = param_5[5];

  uStack_58 = param_5[6];

  uStack_54 = param_5[7];

  uStack_38 = param_3;

  auStack_44[0] = 0;

  uStack_2c = 0;

  uStack_3c = param_2;

  puStack_30 = &local_70;

  fStack_28 = (float)param_5[6] * (unaff_EBX - fStack_78) +

              (float)param_5[5] * (unaff_ESI - fStack_7c) +

              (float)param_5[4] * (unaff_EDI - fStack_80);

  iStack_40 = param_1;

  FUN_0062a5d0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),auStack_44);

  if (*(int *)(iVar1 + 100) != 0) {

    FUN_00600080(iVar1,auStack_44);

  }

  if (iStack_c != 0) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00600080(puVar2,auStack_44);

  }

  return (uint)puVar2 & 0xffff0000;

}
