// =============================================================================
// FUN_0047c140
// -----------------------------------------------------------------------------
// Stable ID: aa_0047c140
// Address:   0x0047c140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047c140 @ 0x0047c140
// Stable ID: aa_0047c140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×5.
//  - Notable callees: FUN_0047a480×4, FUN_00476d60×3, FUN_00470290, FUN_00476cc0, FUN_0047a400, FUN_0047a420, FUN_0047c140.
//  - Return sites: 5.

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

void __thiscall FUN_0047c140(int param_1,int param_2)



{

  int in_EAX;

  int iVar1;

  uint8_t local_4;

  

  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((*(uint *)(param_1 + 0x68) & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 1) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if (in_EAX != 9) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  iVar1 = FUN_0047a480();

  if (iVar1 == 0) {

    FUN_0047a400(local_4);

    FUN_00470290(param_1);

  }

  return;

}
