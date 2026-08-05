// =============================================================================
// FUN_005d5140
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5140
// Address:   0x005d5140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d5140 @ 0x005d5140
// Stable ID: aa_005d5140
// Embedded strings (evidence for future rename):
//   - "DoFullInit Anim"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076cef0×4, FUN_0076cf00×4, FUN_004e87d0, FUN_004e88e0, FUN_004f1c70, FUN_00516be0, FUN_0053d430, FUN_005d5140.
//  - Strings: "DoFullInit Anim".
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

void __fastcall FUN_005d5140(int param_1)



{

  int iVar1;

  char cVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a70f1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00();

  local_4 = 0;

  FUN_004f1c70();

  local_4 = 0xffffffff;

  FUN_0076cef0();

  FUN_0076cf00();

  local_4 = 1;

  (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + -0xe0))();

  FUN_0076cef0();

  FUN_0076cf00();

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 300))();

  FUN_004e87d0();

  FUN_004e88e0();

  cVar2 = (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + -0xa0))(1);

  if (cVar2 != '\0') {

    FUN_0076cf00("DoFullInit Anim");

    (**(code **)(*(int *)(param_1 + -0xa0) + 0x20))();

    FUN_0076cef0();

  }

  FUN_0076cef0();

  iVar1 = *(int *)(*(int *)(param_1 + -0xdc) + 4) + param_1;

  (**(code **)(*(int *)(iVar1 + -0xdc) + 0xb8))(*(uint32_t /* width from decompiler */ *)(iVar1 + -0x24));

  FUN_0053d430();

  FUN_00516be0();

  (**(code **)(*(int *)(param_1 + -0xe0) + 0x44))();

  ExceptionList = (void *)0x1;

  return;

}
