// =============================================================================
// FUN_004aeef0
// -----------------------------------------------------------------------------
// Stable ID: aa_004aeef0
// Address:   0x004aeef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004aeef0 @ 0x004aeef0
// Stable ID: aa_004aeef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_004aeef0.
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

void FUN_004aeef0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 code *param_6)



{

  char cVar1;

  int iVar2;

  

  while (param_3 < param_2) {

    iVar2 = (param_2 + -1) / 2;

    cVar1 = (*param_6)(*(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 8),*(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar2 * 8)

                       ,param_4,param_5);

    if (cVar1 == '\0') break;

    *(uint32_t /* width from decompiler */ *)(param_1 + param_2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4 + param_2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar2 * 8);

    param_2 = iVar2;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4 + param_2 * 8) = param_5;

  *(uint32_t /* width from decompiler */ *)(param_1 + param_2 * 8) = param_4;

  return;

}
