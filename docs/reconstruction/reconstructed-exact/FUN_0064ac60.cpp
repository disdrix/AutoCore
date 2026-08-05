// =============================================================================
// FUN_0064ac60
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ac60
// Address:   0x0064ac60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ac60 @ 0x0064ac60
// Stable ID: aa_0064ac60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0064ac60.
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

void __fastcall FUN_0064ac60(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  

  if (0 < (int)param_1[5]) {

    iVar1 = 0;

    iVar2 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(param_1[4] + iVar1))(0);

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + 0x30;

    } while (iVar2 < (int)param_1[5]);

  }

  if (-1 < (int)param_1[6]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],(param_1[6] & 0x7fffffff) * 0x30,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
