// =============================================================================
// FUN_006efd10
// -----------------------------------------------------------------------------
// Stable ID: aa_006efd10
// Address:   0x006efd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006efd10 @ 0x006efd10
// Stable ID: aa_006efd10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006efd10.
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

void __thiscall FUN_006efd10(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0ed24;

  iVar1 = param_2[2];

  iVar2 = 0;

  param_1[3] = iVar1;

  if (0 < iVar1) {

    puVar4 = param_1 + 6;

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar4 + param_2[1] + (-0x18 - (int)param_1));

      puVar4[-2] = *puVar3;

      puVar4[-1] = puVar3[1];

      *puVar4 = puVar3[2];

      puVar4[1] = puVar3[3];

      iVar2 = iVar2 + 1;

      puVar4 = puVar4 + 4;

    } while (iVar2 < (int)param_1[3]);

  }

  return;

}
