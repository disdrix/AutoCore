// =============================================================================
// FUN_00469120
// -----------------------------------------------------------------------------
// Stable ID: aa_00469120
// Address:   0x00469120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00469120 @ 0x00469120
// Stable ID: aa_00469120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00468c50, FUN_00469120, FUN_004691a0.
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

void FUN_00469120(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  

  iVar1 = in_EAX;

  while( true ) {

    iVar3 = iVar1 * 2 + 2;

    if (param_2 <= iVar3) break;

    cVar2 = FUN_00468c50();

    if (cVar2 != '\0') {

      iVar3 = iVar1 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 4);

    iVar1 = iVar3;

  }

  if (iVar3 == param_2) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_2 * 4);

  }

  FUN_004691a0(param_1,in_EAX,param_4);

  return;

}
