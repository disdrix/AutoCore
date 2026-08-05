// =============================================================================
// FUN_0055b4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b4d0
// Address:   0x0055b4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055b4d0 @ 0x0055b4d0
// Stable ID: aa_0055b4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0055b4d0.
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

void FUN_0055b4d0(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_1 != param_2) {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_2 + 0x14);

    puVar2 = (uint32_t /* width from decompiler */ *)(param_3 + 0x14);

    do {

      *(uint32_t /* width from decompiler */ *)(param_3 + -0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x1c);

      param_2 = param_2 + -0x1c;

      puVar2[-0xb] = puVar1[-0xb];

      param_3 = param_3 + -0x1c;

      puVar2[-10] = puVar1[-10];

      puVar2[-9] = puVar1[-9];

      puVar2[-8] = puVar1[-8];

      puVar2[-7] = puVar1[-7];

      puVar2[-6] = puVar1[-6];

      puVar1 = puVar1 + -7;

      puVar2 = puVar2 + -7;

    } while (param_2 != param_1);

  }

  return;

}
