// =============================================================================
// FUN_004bd310
// -----------------------------------------------------------------------------
// Stable ID: aa_004bd310
// Address:   0x004bd310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bd310 @ 0x004bd310
// Stable ID: aa_004bd310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004921e0, FUN_004bd310, FUN_005b46a0, FUN_00763f60.
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

void __fastcall FUN_004bd310(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a1768;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009cb4d4;

  local_4 = 0;

  if (param_1[0x54] != 0) {

    iVar2 = *(int *)(param_1[0x54] + 0x174);

    FUN_005b46a0();

    if (iVar2 != 0) {

      piVar1 = (int *)(iVar2 + 0x128);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        FUN_004921e0(iVar2);

      }

    }

    param_1[0x54] = 0;

  }

  local_4 = 0xffffffff;

  FUN_00763f60();

  ExceptionList = local_c;

  return;

}
