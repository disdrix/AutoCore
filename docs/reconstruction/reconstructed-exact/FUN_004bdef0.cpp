// =============================================================================
// FUN_004bdef0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bdef0
// Address:   0x004bdef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bdef0 @ 0x004bdef0
// Stable ID: aa_004bdef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004bde80, FUN_004bdef0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_004bdef0(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

  iVar1 = *(int *)(iVar2 + 0x38);

  if (((((*(short *)(*(int *)(iVar2 + 0x3c) + 0x3f4) != 3) && (iVar1 != 0x36)) && (iVar1 != 0x38))

      && ((iVar1 != 0x1e && (iVar1 != 0x3c)))) &&

     ((iVar2 = *(int *)(*(int *)(param_1 + 4) + 4),

      (*(byte *)(*(int *)(*(int *)(iVar2 + 0xac + param_1) + 0x3c) + 0x3f2) & 4) == 0 &&

      (*(int *)(param_1 + 0x1c) == 0)))) {

    if ((*(char *)(*(int *)(iVar2 + param_1 + 0xa8) + 0xf5) == '\0') &&

       (iVar2 = FUN_004bde80(*(uint32_t /* width from decompiler */ *)(param_1 + 8)), 20000 < iVar2)) {

      return 0;

    }

    return 1;

  }

  return 0;

}
