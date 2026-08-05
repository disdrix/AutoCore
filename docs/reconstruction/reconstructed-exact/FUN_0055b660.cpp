// =============================================================================
// FUN_0055b660
// -----------------------------------------------------------------------------
// Stable ID: aa_0055b660
// Address:   0x0055b660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055b660 @ 0x0055b660
// Stable ID: aa_0055b660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0055b660.
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

void FUN_0055b660(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  

  if (param_1 != param_2) {

    puVar1 = param_3;

    iVar3 = param_2;

    do {

      iVar4 = iVar3 + -0xc;

      puVar2 = puVar1 + -3;

      *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + -0xc);

      puVar1[-2] = *(uint32_t /* width from decompiler */ *)((param_2 - (int)param_3) + 4 + (int)puVar2);

      puVar1[-1] = *(uint32_t /* width from decompiler */ *)(iVar3 + -4);

      puVar1 = puVar2;

      iVar3 = iVar4;

    } while (iVar4 != param_1);

  }

  return;

}
