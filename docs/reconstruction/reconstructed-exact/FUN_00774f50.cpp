// =============================================================================
// FUN_00774f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00774f50
// Address:   0x00774f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00774f50 @ 0x00774f50
// Stable ID: aa_00774f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007707d0×2, FUN_00770440, FUN_00770540, FUN_00772390, FUN_00773600, FUN_00774f50.
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

int FUN_00774f50(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ local_8;

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = FUN_00773600(param_1);

    if (iVar1 == 0) {

      if (local_8 != *(int *)(in_EAX + 8)) {

        iVar1 = FUN_00772390();

        FUN_007707d0();

        return iVar1;

      }

      iVar1 = 0;

      FUN_00770540();

    }

    FUN_007707d0();

  }

  return iVar1;

}
