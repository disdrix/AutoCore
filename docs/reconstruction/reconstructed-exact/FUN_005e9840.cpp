// =============================================================================
// FUN_005e9840
// -----------------------------------------------------------------------------
// Stable ID: aa_005e9840
// Address:   0x005e9840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e9840 @ 0x005e9840
// Stable ID: aa_005e9840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005e9840.
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

void FUN_005e9840(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_1 != param_2) {

    puVar1 = param_3 + 5;

    puVar2 = param_1 + 5;

    do {

      if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

        *param_3 = *param_1;

        puVar1[-4] = puVar2[-4];

        puVar1[-3] = puVar2[-3];

        puVar1[-2] = puVar2[-2];

        puVar1[-1] = puVar2[-1];

        *puVar1 = *puVar2;

        puVar1[1] = puVar2[1];

        puVar1[2] = puVar2[2];

        puVar1[3] = puVar2[3];

        puVar1[4] = puVar2[4];

        puVar1[5] = puVar2[5];

        puVar1[6] = puVar2[6];

        puVar1[7] = puVar2[7];

        puVar1[8] = puVar2[8];

      }

      param_1 = param_1 + 0xe;

      param_3 = param_3 + 0xe;

      puVar1 = puVar1 + 0xe;

      puVar2 = puVar2 + 0xe;

    } while (param_1 != param_2);

  }

  return;

}
