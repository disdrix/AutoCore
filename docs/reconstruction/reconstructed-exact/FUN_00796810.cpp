// =============================================================================
// FUN_00796810
// -----------------------------------------------------------------------------
// Stable ID: aa_00796810
// Address:   0x00796810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00796810 @ 0x00796810
// Stable ID: aa_00796810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: DirectInput8Create, FUN_00796810, GetModuleHandleA.
//  - Return sites: 2.

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

uint __fastcall

FUN_00796810(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ in_EAX;

  HMODULE pHVar2;

  uint uVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  undefined *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x80) = in_EAX;

  puVar5 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x84);

  for (iVar4 = 0x52; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = *param_2;

    param_2 = param_2 + 1;

    puVar5 = puVar5 + 1;

  }

  uVar8 = 0;

  puVar7 = &DAT_00a0d124;

  uVar6 = 0x800;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x7c) = *param_3;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1cc) = param_4;

  puVar5 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

  pHVar2 = GetModuleHandleA((LPCSTR)0x0);

  iVar4 = DirectInput8Create(pHVar2,uVar6,puVar7,puVar5,uVar8);

  if (iVar4 < 0) {

    return 0x80004005;

  }

  piVar1 = *(int **)(unaff_EBX + 8);

  uVar3 = (**(code **)(*piVar1 + 0x24))

                    (piVar1,0,(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x84),FUN_00796760,&stack0xffffffe4,0x1000)

  ;

  return uVar3 & (-1 < (int)uVar3) - 1;

}
