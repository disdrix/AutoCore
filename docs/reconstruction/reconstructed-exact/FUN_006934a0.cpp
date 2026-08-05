// =============================================================================
// FUN_006934a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006934a0
// Address:   0x006934a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006934a0 @ 0x006934a0
// Stable ID: aa_006934a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00691d80, FUN_006934a0.
//  - Return sites: 2.

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

int FUN_006934a0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  if (param_1 == param_2) {

    return param_3;

  }

  do {

    iVar1 = param_2 + -0x30;

    iVar2 = param_3 + -0x30;

    FUN_00691d80(iVar1);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x20);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x1c);

    *(uint8_t *)(param_3 + -0x18) = *(uint8_t *)(param_2 + -0x18);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0x14) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x14);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0x10) = *(uint32_t /* width from decompiler */ *)(param_2 + -0x10);

    *(uint32_t /* width from decompiler */ *)(param_3 + -0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + -0xc);

    *(uint32_t /* width from decompiler */ *)(param_3 + -8) = *(uint32_t /* width from decompiler */ *)(param_2 + -8);

    *(uint32_t /* width from decompiler */ *)(param_3 + -4) = *(uint32_t /* width from decompiler */ *)(param_2 + -4);

    param_2 = iVar1;

    param_3 = iVar2;

  } while (iVar1 != param_1);

  return iVar2;

}
