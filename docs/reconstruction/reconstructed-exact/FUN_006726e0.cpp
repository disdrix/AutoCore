// =============================================================================
// FUN_006726e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006726e0
// Address:   0x006726e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006726e0 @ 0x006726e0
// Stable ID: aa_006726e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: DeleteCriticalSection, FUN_005b2ba0, FUN_006726e0, FUN_00673b30.
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

void __fastcall FUN_006726e0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9238;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009e8274;

  local_4 = 1;

  if ((uint32_t /* width from decompiler */ *)param_1[0x57] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x57])(1);

  }

  param_1[0x57] = 0;

  piVar1 = (int *)param_1[0x27];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x27] = 0;

  piVar1 = (int *)param_1[0x26];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x26] = 0;

  piVar1 = (int *)param_1[0x25];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  param_1[0x25] = 0;

  if ((void *)param_1[0x58] != (void *)0x0) {

    operator_delete__((void *)param_1[0x58]);

    param_1[0x58] = 0;

  }

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x261));

  *(uint8_t *)(param_1 + 0x267) = 0;

  FUN_005b2ba0();

  local_4 = 0xffffffff;

  FUN_00673b30();

  ExceptionList = pvStack_c;

  return;

}
