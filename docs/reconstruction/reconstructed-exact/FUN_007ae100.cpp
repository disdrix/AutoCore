// =============================================================================
// FUN_007ae100
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae100
// Address:   0x007ae100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ae100 @ 0x007ae100
// Stable ID: aa_007ae100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00423f40×2, FUN_00424060, FUN_004294f0, FUN_007ae100, LeaveCriticalSection.
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

void FUN_007ae100(void)



{

  int iVar1;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  local_8 = 0;

  FUN_004294f0();

  iVar2 = FUN_00423f40(&local_8);

  iVar1 = local_8;

  while (local_8 = iVar1, iVar2 == 0) {

    if (iVar1 != 0) {

      if (*(void **)(iVar1 + 8) != (void *)0x0) {

        operator_delete__(*(void **)(iVar1 + 8));

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

    }

    iVar2 = FUN_00423f40(&local_8);

    iVar1 = local_8;

  }

  if (DAT_00d1e848 != '\0') {

    DAT_00d1e848 = '\0';

    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00d1e824);

  }

  FUN_00424060();

  DAT_00d17950 = 1;

  DAT_00afa138 = DAT_00afa13c;

  return;

}
