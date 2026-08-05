// =============================================================================
// FUN_0069ea40
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ea40
// Address:   0x0069ea40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069ea40 @ 0x0069ea40
// Stable ID: aa_0069ea40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00697380, FUN_00697540, FUN_0069ea40.
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

void __thiscall FUN_0069ea40(int param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 != param_4) {

    iVar2 = FUN_00697540(param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3,param_3);

    iVar1 = *(int *)(param_1 + 8);

    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x54) {

      FUN_00697380();

    }

    *(int *)(param_1 + 8) = iVar2;

  }

  *param_2 = param_3;

  return;

}
