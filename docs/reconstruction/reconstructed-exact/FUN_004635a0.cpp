// =============================================================================
// FUN_004635a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004635a0
// Address:   0x004635a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004635a0 @ 0x004635a0
// Stable ID: aa_004635a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044c010, FUN_00462820, FUN_004633e0, FUN_004635a0.
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

uint32_t /* width from decompiler */ * FUN_004635a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = param_2;

  if (in_EAX != param_1) {

    puVar3 = param_2 + 1;

    puVar1 = in_EAX + 1;

    do {

      *puVar2 = *in_EAX;

      if (puVar3 != puVar1) {

        FUN_00462820(&param_2,*(uint32_t /* width from decompiler */ *)puVar3[1],(uint32_t /* width from decompiler */ *)puVar3[1]);

        FUN_004633e0();

      }

      FUN_0044c010();

      in_EAX = in_EAX + 8;

      puVar2 = puVar2 + 8;

      puVar3 = puVar3 + 8;

      puVar1 = puVar1 + 8;

    } while (in_EAX != param_1);

  }

  return puVar2;

}
