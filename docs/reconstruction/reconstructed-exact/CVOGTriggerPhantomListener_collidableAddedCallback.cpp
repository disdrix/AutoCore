// =============================================================================
// CVOGTriggerPhantomListener_collidableAddedCallback
// -----------------------------------------------------------------------------
// Stable ID: aa_00642b70
// Address:   0x00642b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGTriggerPhantomListener_collidableAddedCallback @ 0x00642b70
// Stable ID: aa_00642b70
// Embedded strings (evidence for future rename):
//   - "CVOGTriggerPhantomListener::collidableAddedCallback"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040afb0, CVOGTriggerPhantomListener_collidableAddedCallback, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CVOGTriggerPhantomListener::collidableAddedCallback".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGTriggerPhantomListener::collidableAddedCallback"
 * Domain alias of FUN_00642b70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall CVOGTriggerPhantomListener_collidableAddedCallback(int param_1,int *param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8e88;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGTriggerPhantomListener::collidableAddedCallback");

  local_4 = 0;

  if (*(char *)(*(int *)(param_2[1] + 0x20) + 0x40) == '\0') {

    FUN_0040afb0(&param_2,1);

    if (param_2 != (int *)0x0) {

      iVar1 = (**(code **)(*param_2 + 0x1c8))();

      if (iVar1 != 0) {

        (**(code **)(**(int **)(param_1 + 4) + 0x6c))(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1)

        ;

      }

    }

  }

  else {

    param_2[3] = 1;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
