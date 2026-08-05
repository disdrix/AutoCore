// =============================================================================
// FUN_00571920
// -----------------------------------------------------------------------------
// Stable ID: aa_00571920
// Address:   0x00571920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00571920 @ 0x00571920
// Stable ID: aa_00571920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004022a0, FUN_004294f0, FUN_00571920, LeaveCriticalSection.
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

longlong __fastcall FUN_00571920(int param_1)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  int *local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a4f10;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd0;

  lVar1 = 0;

  local_8 = 0;

  local_18 = 0;

  ExceptionList = &local_10;

  FUN_004294f0();

  while( true ) {

    iVar2 = FUN_004022a0(&local_18,&local_1c);

    if (iVar2 != 0) break;

    if (local_1c != (int *)0x0) {

      lVar3 = (**(code **)(*local_1c + 0x16c))();

      lVar1 = lVar3 + lVar1;

    }

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    *(uint8_t *)(param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  }

  ExceptionList = local_10;

  return lVar1;

}
