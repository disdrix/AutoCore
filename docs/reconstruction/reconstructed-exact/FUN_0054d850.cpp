// =============================================================================
// FUN_0054d850
// -----------------------------------------------------------------------------
// Stable ID: aa_0054d850
// Address:   0x0054d850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054d850 @ 0x0054d850
// Stable ID: aa_0054d850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_0054d850.
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

void FUN_0054d850(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

                 uint8_t param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar1 = operator_new(0x644);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = param_1;

    puVar1[2] = param_3;

    puVar1[1] = param_2;

    puVar3 = puVar1 + 3;

    for (iVar2 = 0x18d; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = *param_4;

      param_4 = param_4 + 1;

      puVar3 = puVar3 + 1;

    }

    *(uint8_t *)(puVar1 + 400) = param_5;

    *(uint8_t *)((int)puVar1 + 0x641) = 0;

  }

  return;

}
