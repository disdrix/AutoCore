// =============================================================================
// FUN_004641d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004641d0
// Address:   0x004641d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004641d0 @ 0x004641d0
// Stable ID: aa_004641d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: block×3, FUN_004641d0, FUN_00464340, FUN_0046c1b0.
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

/* WARNING: Removing unreachable block (ram,0x00464242) */

/* WARNING: Removing unreachable block (ram,0x00464249) */

/* WARNING: Removing unreachable block (ram,0x00464252) */



int __fastcall FUN_004641d0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int *piVar1;

  int local_28;

  uint local_24;

  uint8_t local_20 [8];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be550;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0046c1b0();

  if (local_28 == *(int *)(param_2 + 8)) {

    local_24 = local_24 & 0xffffff00;

    local_18 = *param_1;

    local_14 = 0;

    local_10 = local_24;

    local_4 = 1;

    piVar1 = (int *)FUN_00464340(local_20,&local_18);

    ExceptionList = local_c;

    return *piVar1 + 0xc;

  }

  ExceptionList = local_c;

  return local_28 + 0xc;

}
