// =============================================================================
// FUN_005b5590
// -----------------------------------------------------------------------------
// Stable ID: aa_005b5590
// Address:   0x005b5590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b5590 @ 0x005b5590
// Stable ID: aa_005b5590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b5590, FUN_006864d0.
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

void __thiscall FUN_005b5590(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = param_2[2];

  FUN_006864d0(*param_2,param_2[1],param_2[2]);

  uVar1 = *param_2;

  uVar2 = param_2[1];

  if (*(int **)(param_1 + 8) != (int *)0x0) {

    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = 0xffffffff;

    *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90) = 3;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x94) = uVar1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x98) = uVar2;

  }

  return;

}
