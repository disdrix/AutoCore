// =============================================================================
// FUN_004332b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004332b0
// Address:   0x004332b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004332b0 @ 0x004332b0
// Stable ID: aa_004332b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_004332b0.
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

uint __fastcall FUN_004332b0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  uint in_EAX;

  int iVar2;

  int unaff_ESI;

  

  piVar1 = (int *)(in_EAX + 0x1b0);

  if ((((*piVar1 != 0) && (-1 < unaff_ESI)) && (unaff_ESI < *(int *)(in_EAX + 0x10))) &&

     ((-1 < param_2 && (in_EAX = *(uint *)(in_EAX + 0xc), param_2 < (int)in_EAX)))) {

    iVar2 = in_EAX * unaff_ESI + *piVar1;

    return CONCAT31((int3)((uint)iVar2 >> 8),*(uint8_t *)(iVar2 + param_2));

  }

  return in_EAX & 0xffffff00;

}
