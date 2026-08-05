// =============================================================================
// FUN_0064cce0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064cce0
// Address:   0x0064cce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064cce0 @ 0x0064cce0
// Stable ID: aa_0064cce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, for×1.
//  - Notable callees: FUN_0064b270, FUN_0064cce0.
//  - Return sites: 4.

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

void __thiscall FUN_0064cce0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  

  iVar3 = param_2;

  iVar1 = *(int *)(param_2 + 4);

  if (iVar1 != *(int *)(param_1 + 4)) {

    if (iVar1 == 0) {

      return;

    }

    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {

      iVar1 = iVar2;

    }

    if (*(int *)(iVar1 + 0x20) == 0) {

      return;

    }

    pcVar4 = (char *)FUN_0064b270(&param_2,0x1000);

    if (*pcVar4 == '\0') {

      return;

    }

  }

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 1;

  return;

}
