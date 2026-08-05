// =============================================================================
// FUN_00448e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00448e20
// Address:   0x00448e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00448e20 @ 0x00448e20
// Stable ID: aa_00448e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00448e20.
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

void FUN_00448e20(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,code *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  

  while (param_2 < in_EAX) {

    iVar3 = (in_EAX + -1) / 2;

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8);

    cVar2 = (*param_5)(puVar1,&param_3);

    if (cVar2 == '\0') break;

    *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 8) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4 + in_EAX * 8) = puVar1[1];

    in_EAX = iVar3;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + in_EAX * 8) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4 + in_EAX * 8) = param_4;

  return;

}
