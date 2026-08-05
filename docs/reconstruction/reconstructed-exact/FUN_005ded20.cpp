// =============================================================================
// FUN_005ded20
// -----------------------------------------------------------------------------
// Stable ID: aa_005ded20
// Address:   0x005ded20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ded20 @ 0x005ded20
// Stable ID: aa_005ded20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00631fd0×2, FUN_005ded20.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005ded20(uint32_t /* width from decompiler */ *param_1)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009dbae4;

  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(1);

  FUN_00631fd0(uVar3);

  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(2);

  FUN_00631fd0(uVar3);

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[4];

  psVar1 = (short *)((int)puVar2 + 6);

  *psVar1 = *psVar1 + -1;

  if (*psVar1 == 0) {

    (**(code **)*puVar2)(1);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[7];

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  if (*(short *)((int)puVar2 + 6) == 0) {

    (**(code **)*puVar2)(1);

  }

  return param_1;

}
