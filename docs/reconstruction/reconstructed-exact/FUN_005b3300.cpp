// =============================================================================
// FUN_005b3300
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3300
// Address:   0x005b3300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b3300 @ 0x005b3300
// Stable ID: aa_005b3300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006380a0.
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

void FUN_005b3300(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  uVar1 = (**(code **)(*DAT_00b05060 + 0x10))(param_2 * param_3,0x12);

  FUN_006380a0(uVar1,*unaff_EBX,unaff_EBX[1] * param_3);

  if (-1 < (int)unaff_EBX[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*unaff_EBX,(unaff_EBX[2] & 0x7fffffff) * param_3,0x12);

  }

  *unaff_EBX = uVar1;

  unaff_EBX[2] = param_2;

  return;

}
