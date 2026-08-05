// =============================================================================
// FUN_004d28c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d28c0
// Address:   0x004d28c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d28c0 @ 0x004d28c0
// Stable ID: aa_004d28c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_004bade0, FUN_004badf0, FUN_004cf3b0, FUN_004d28c0.
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

void __thiscall FUN_004d28c0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  if (((((param_1 != -0xa0) && (*(char *)(param_1 + 0x100) == '\0')) &&

       (*(int *)(param_1 + 0xac) != 2)) && (param_2 != param_3)) &&

     ((param_3 < 0x10 || (param_2 < 0x10)))) {

    if (0xe < param_3) {

      param_3 = 0xf;

    }

    if (0xe < param_2) {

      param_2 = 0xf;

    }

    FUN_004bade0();

    iVar1 = *(int *)(param_1 + 0xe4e8);

    for (uVar3 = 0;

        (iVar2 = *(int *)(iVar1 + 0x2c), iVar2 != 0 &&

        (uVar3 < (uint)(*(int *)(iVar1 + 0x30) - iVar2 >> 2))); uVar3 = uVar3 + 1) {

      FUN_004cf3b0(*(uint32_t /* width from decompiler */ *)(iVar2 + uVar3 * 4),param_2,param_3);

    }

    FUN_004badf0();

  }

  return;

}
