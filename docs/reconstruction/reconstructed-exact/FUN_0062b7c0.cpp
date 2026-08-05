// =============================================================================
// FUN_0062b7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b7c0
// Address:   0x0062b7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b7c0 @ 0x0062b7c0
// Stable ID: aa_0062b7c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0062b7c0.
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

void __fastcall FUN_0062b7c0(int *param_1)



{

  int iVar1;

  int iVar2;

  

  if (0 < param_1[1]) {

    iVar1 = 0;

    iVar2 = 0;

    do {

      (**(code **)(*DAT_00b05060 + 4))(*(uint32_t /* width from decompiler */ *)(iVar1 + *param_1));

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + 0xc;

    } while (iVar2 < param_1[1]);

  }

  if (-1 < param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,(param_1[2] & 0x7fffffffU) * 0xc,0x12);

  }

  return;

}
