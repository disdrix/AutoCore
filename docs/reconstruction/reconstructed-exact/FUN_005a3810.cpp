// =============================================================================
// FUN_005a3810
// -----------------------------------------------------------------------------
// Stable ID: aa_005a3810
// Address:   0x005a3810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a3810 @ 0x005a3810
// Stable ID: aa_005a3810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005a3810.
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

void FUN_005a3810(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

                 uint8_t param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = operator_new(0x18);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar2 = param_1;

    puVar2[2] = param_3;

    puVar2[1] = param_2;

    puVar2[3] = *param_4;

    iVar1 = param_4[1];

    puVar2[4] = iVar1;

    if (iVar1 != 0) {

      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

    }

    *(uint8_t *)(puVar2 + 5) = param_5;

    *(uint8_t *)((int)puVar2 + 0x15) = 0;

  }

  return;

}
