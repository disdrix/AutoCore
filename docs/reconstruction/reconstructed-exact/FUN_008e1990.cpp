// =============================================================================
// FUN_008e1990
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1990
// Address:   0x008e1990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e1990 @ 0x008e1990
// Stable ID: aa_008e1990
// Embedded strings (evidence for future rename):
//   - "GRID_START"
//   - "GRID_UNIT_SIZE"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, goto×1.
//  - Notable callees: FUN_007a8b00×2, SysFreeString×2, _wcsicmp×2, FUN_007933a0, FUN_008e1990.
//  - Strings: "GRID_START"; "GRID_UNIT_SIZE".
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

void __thiscall FUN_008e1990(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  void *unaff_EBX;

  BSTR unaff_ESI;

  int *piVar3;

  float fVar4;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba487;

  local_c = ExceptionList;

  local_10 = 0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2,&local_10);

  iVar2 = _wcsicmp(L"GRID_START",unaff_ESI);

  if (iVar2 == 0) {

    piVar3 = (int *)(param_1 + 0x510);

    FUN_007a8b00(param_2,piVar3,param_1 + 0x514,0);

    iVar1 = *piVar3;

    iVar2 = DAT_00d1e818;

  }

  else {

    iVar2 = _wcsicmp(L"GRID_UNIT_SIZE",unaff_ESI);

    if (iVar2 != 0) {

      FUN_007933a0(param_2,param_3);

      goto LAB_008e1a86;

    }

    piVar3 = (int *)(param_1 + 0x518);

    FUN_007a8b00(param_2,piVar3,param_1 + 0x51c,0);

    iVar2 = *piVar3;

    iVar1 = DAT_00d1e818;

  }

  fVar4 = (float)piVar3[1] * (float)DAT_00d1e81c * DAT_00aaa678;

  *piVar3 = (int)((float)iVar1 * (float)iVar2 * DAT_00aaa67c);

  piVar3[1] = (int)fVar4;

LAB_008e1a86:

  local_c = (void *)0xffffffff;

  SysFreeString(unaff_ESI);

  ExceptionList = unaff_EBX;

  return;

}
