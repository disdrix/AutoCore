// =============================================================================
// FUN_0041a530
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a530
// Address:   0x0041a530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041a530 @ 0x0041a530
// Stable ID: aa_0041a530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0041a530, LOCK, UNLOCK.
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

void FUN_0041a530(void)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = (uint32_t /* width from decompiler */ *)(*in_EAX + -0x10);

  piVar1 = (int *)(*in_EAX + -4);

  LOCK();

  iVar2 = *piVar1;

  *piVar1 = *piVar1 + -1;

  UNLOCK();

  if (iVar2 == 1 || iVar2 + -1 < 0) {

    (**(code **)(*(int *)*puVar3 + 4))(puVar3);

  }

  return;

}
