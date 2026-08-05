// =============================================================================
// FUN_0092c760
// -----------------------------------------------------------------------------
// Stable ID: aa_0092c760
// Address:   0x0092c760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092c760 @ 0x0092c760
// Stable ID: aa_0092c760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT44, FUN_0092c760.
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

uint64_t FUN_0092c760(void)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  int iVar4;

  int in_EAX;

  

  iVar4 = DAT_00af90bc;

  iVar2 = DAT_00af90b8;

  iVar1 = *(int *)(in_EAX + 0xe04);

  if (iVar1 == 0) {

    DAT_00af90bc = DAT_00af90bc + -1 + (uint)(DAT_00af90b8 != 0);

    DAT_00af90b8 = DAT_00af90b8 + -1;

    return CONCAT44(iVar4,iVar2);

  }

  iVar2 = *(int *)(iVar1 + 0xe6e8);

  uVar3 = *(uint64_t *)(iVar1 + 0xe6e8);

  *(uint *)(iVar1 + 0xe6ec) = *(int *)(iVar1 + 0xe6ec) - (uint)(iVar2 == 0);

  *(int *)(iVar1 + 0xe6e8) = iVar2 + -1;

  return uVar3;

}
