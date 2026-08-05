// =============================================================================
// FUN_006a3db0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3db0
// Address:   0x006a3db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3db0 @ 0x006a3db0
// Stable ID: aa_006a3db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT44, FUN_006a3db0, ROUND.
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

ulonglong FUN_006a3db0(void)



{

  ulonglong uVar1;

  uint uVar2;

  float fVar3;

  float10 in_ST0;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ uStack_1c;

  

  uVar1 = (ulonglong)ROUND(in_ST0);

  local_20 = (uint)uVar1;

  uStack_1c = (float)(uVar1 >> 0x20);

  fVar3 = (float)in_ST0;

  if ((local_20 != 0) || (fVar3 = uStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {

    if ((int)fVar3 < 0) {

      uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));

    }

    else {

      uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));

      uVar1 = CONCAT44((int)uStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);

    }

  }

  return uVar1;

}
