// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ffcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffcf0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005ffcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00638140×2, FUN_005ffcf0, FUN_006501c0, FUN_00650210, FUN_00650290, FUN_00650330, FUN_0065acb0, FUN_0065ad10.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005ffcf0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = param_1;

  uVar2 = FUN_00650290(param_1);

  FUN_0065ad10(&param_1,uVar2);

  if ((char)param_1 == '\0') {

    if (param_2 != 0) {

      uVar2 = FUN_00638140(param_2);

      FUN_00650210(iVar1,uVar2);

    }

    return;

  }

  uVar3 = FUN_0065acb0(uVar2);

  (**(code **)(*DAT_00b05060 + 4))(uVar3);

  if (param_1 != 0) {

    uVar3 = FUN_00638140(param_1);

    FUN_006501c0(uVar2,uVar3);

    return;

  }

  FUN_00650330(uVar2);

  return;

}
