// =============================================================================
// FUN_004af0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004af0b0
// Address:   0x004af0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004af0b0 @ 0x004af0b0
// Stable ID: aa_004af0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004aeef0, FUN_004af0b0.
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

void FUN_004af0b0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 code *param_6)



{

  char cVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = param_2;

  while( true ) {

    iVar3 = iVar2 * 2 + 2;

    if (param_3 <= iVar3) break;

    cVar1 = (*param_6)(*(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8),*(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar3 * 8)

                       ,*(uint32_t /* width from decompiler */ *)(param_1 + -8 + iVar3 * 8),

                       *(uint32_t /* width from decompiler */ *)(param_1 + -4 + iVar3 * 8));

    if (cVar1 != '\0') {

      iVar3 = iVar2 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar3 * 8);

    iVar2 = iVar3;

  }

  if (iVar3 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + -8 + param_3 * 8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar2 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_3 * 8);

    iVar2 = param_3 + -1;

  }

  FUN_004aeef0(param_1,iVar2,param_2,param_4,param_5,param_6);

  return;

}
