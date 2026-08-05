// =============================================================================
// FUN_004d0df0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0df0
// Address:   0x004d0df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d0df0 @ 0x004d0df0
// Stable ID: aa_004d0df0
// Embedded strings (evidence for future rename):
//   - "GenerateLootItem (id)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004d0df0, FUN_0050a7d0, FUN_0076cef0, FUN_0076cf00, GenerateLootItem.
//  - Strings: "GenerateLootItem (id)".
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

int * __thiscall FUN_004d0df0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *piVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1fa1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("GenerateLootItem (id)");

  local_4 = 0;

  iVar1 = FUN_0050a7d0(param_2,param_3);

  if (iVar1 == 0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 0x218))(param_1);

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return piVar2;

}
