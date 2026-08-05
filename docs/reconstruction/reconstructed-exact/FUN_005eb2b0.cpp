// =============================================================================
// FUN_005eb2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb2b0
// Address:   0x005eb2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eb2b0 @ 0x005eb2b0
// Stable ID: aa_005eb2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005eb2b0, FUN_00634450.
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

void __thiscall FUN_005eb2b0(int param_1,int *param_2)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t auStack_30 [44];

  

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;

  uVar3 = (**(code **)(*param_2 + 0x14))();

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = uVar3;

  psVar1 = (short *)((int)puVar2 + 6);

  *psVar1 = *psVar1 + -1;

  if (*psVar1 == 0) {

    (**(code **)*puVar2)(1);

  }

  *(int **)(param_1 + 0xc) = param_2;

  if (*(int *)(param_1 + 8) != 0) {

    (**(code **)(*param_2 + 0x18))

              (param_1 + 0x80,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),auStack_30

              );

    FUN_00634450(&stack0xffffffc4);

  }

  return;

}
