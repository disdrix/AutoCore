// =============================================================================
// FUN_0067da10
// -----------------------------------------------------------------------------
// Stable ID: aa_0067da10
// Address:   0x0067da10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067da10 @ 0x0067da10
// Stable ID: aa_0067da10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, goto×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_0067cde0, FUN_0067d980, FUN_0067da10.
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

uint32_t /* width from decompiler */ __thiscall FUN_0067da10(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint8_t uVar1;

  int iVar2;

  

  uVar1 = 1;

  if (*(char *)((int)param_2 + 0xd) == '\0') {

    FUN_0067d980(0,param_3,param_4);

  }

  else {

    uVar1 = FUN_0067cde0(param_2,param_3,param_4);

  }

  if (*(char *)(param_1 + 0x2a10) != '\0') {

    *(uint8_t *)(param_1 + 0x2a11) = 1;

  }

  iVar2 = 0;

  *(uint8_t *)(param_1 + 0x2a10) = 1;

  if (*(byte *)(param_1 + 6) != 0) {

    do {

      if (*(char *)(param_1 + 7 + iVar2) == '\0') goto LAB_0067da8d;

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 6));

  }

  *(uint8_t *)(*(byte *)(param_1 + 6) + 7 + param_1) = 0;

  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';

LAB_0067da8d:

  *(int *)(param_1 + 0x2a04) = *param_2 + 1;

  return CONCAT31((int3)((uint)iVar2 >> 8),uVar1);

}
