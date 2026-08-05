// =============================================================================
// FUN_0075d9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d9c0
// Address:   0x0075d9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d9c0 @ 0x0075d9c0
// Stable ID: aa_0075d9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0040d9c0×2, FUN_0043c5f0, FUN_0075d9c0.
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

int FUN_0075d9c0(uint32_t /* width from decompiler */ param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint8_t local_20 [4];

  int local_1c;

  uint local_18;

  uint local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009afe39;

  pvStack_c = ExceptionList;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_0043c5f0(local_20);

  uVar3 = local_14;

  while( true ) {

    if (uVar3 == local_10 + local_14) {

      FUN_0040d9c0();

      ExceptionList = pvStack_c;

      return 0;

    }

    uVar1 = uVar3 >> 2;

    iVar2 = uVar1 * -4;

    if (local_18 <= uVar1) {

      uVar1 = uVar1 - local_18;

    }

    iVar2 = (**(code **)(**(int **)(*(int *)(local_1c + uVar1 * 4) + (uVar3 + iVar2) * 4) + 0x10))

                      (param_1);

    if (iVar2 != 0) break;

    uVar3 = uVar3 + 1;

  }

  FUN_0040d9c0();

  ExceptionList = pvStack_c;

  return iVar2;

}
