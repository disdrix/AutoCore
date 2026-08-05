// =============================================================================
// FUN_00646310
// -----------------------------------------------------------------------------
// Stable ID: aa_00646310
// Address:   0x00646310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646310 @ 0x00646310
// Stable ID: aa_00646310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00646310.
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

uint16_t __fastcall FUN_00646310(uint32_t /* width from decompiler */ *param_1)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint16_t uVar3;

  

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[4];

  *param_1 = &PTR_FUN_009e4590;

  psVar1 = (short *)((int)puVar2 + 6);

  *psVar1 = *psVar1 + -1;

  uVar3 = *(uint16_t *)((int)puVar2 + 6);

  if (*psVar1 == 0) {

    uVar3 = (**(code **)*puVar2)(1);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[3];

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  if (*(short *)((int)puVar2 + 6) == 0) {

    uVar3 = (**(code **)*puVar2)(1);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[2];

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  if (*(short *)((int)puVar2 + 6) == 0) {

    uVar3 = (**(code **)*puVar2)(1);

  }

  *param_1 = &PTR_LAB_009cc290;

  return uVar3;

}
