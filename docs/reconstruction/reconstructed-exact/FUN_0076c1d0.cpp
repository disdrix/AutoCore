// =============================================================================
// FUN_0076c1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c1d0
// Address:   0x0076c1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c1d0 @ 0x0076c1d0
// Stable ID: aa_0076c1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT44, FUN_0076c1d0, __aulldiv.
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

float10 FUN_0076c1d0(void)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int in_EAX;

  longlong lVar4;

  

  uVar3 = DAT_00d1a53c;

  iVar2 = DAT_00d1a538;

  iVar1 = *(int *)(in_EAX + 8);

  lVar4 = __aulldiv(iVar1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),DAT_00d1a538,DAT_00d1a53c);

  return (float10)lVar4 +

         (float10)(iVar1 - iVar2 * (int)lVar4) /

         (-(float10)(longlong)(((ulonglong)uVar3 & 0x80000000) << 0x20) +

         (float10)(CONCAT44(uVar3,iVar2) & 0x7fffffffffffffff));

}
