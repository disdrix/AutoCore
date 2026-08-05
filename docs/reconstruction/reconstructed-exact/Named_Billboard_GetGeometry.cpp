// =============================================================================
// Named_Billboard_GetGeometry
// -----------------------------------------------------------------------------
// Stable ID: aa_005b5490
// Address:   0x005b5490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Billboard_GetGeometry @ 0x005b5490
// Stable ID: aa_005b5490
// Embedded strings (evidence for future rename):
//   - "RenderBillboards"
//   - "Billboard::GetGeometry"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0076cef0×2, FUN_0076cf00×2, Named_Billboard_GetGeometry, FUN_0068a4d0, FUN_00752a00, FUN_0096f5d0, FUN_0096fdf0.
//  - Strings: "RenderBillboards"; "Billboard::GetGeometry".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Billboard::GetGeometry"
 * Domain alias of FUN_005b5490 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_Billboard_GetGeometry(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a691d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("RenderBillboards");

  local_4 = 0;

  FUN_0076cf00("Billboard::GetGeometry");

  local_4._0_1_ = 1;

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),8,0xffffffff,0xffffffff,0xffffffff);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0076cef0();

  if (*(char *)(*(int *)(param_1 + 0x50) + 0xf0) == '\0') {

    *(uint8_t *)(*(int *)(param_1 + 0x18) + 0xcc) = 0;

  }

  else {

    *(uint8_t *)(*(int *)(param_1 + 0x18) + 0xcc) = 1;

    iVar3 = *(int *)(param_1 + 0x50);

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0xd8);

    cVar2 = FUN_0096fdf0();

    iVar3 = FUN_00752a00(uVar1,iVar3 + 0xfc);

    if ((iVar3 == -1) && (cVar2 != '\0')) {

      FUN_0096f5d0();

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 1;

}
