// =============================================================================
// FUN_005c7df0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7df0
// Address:   0x005c7df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c7df0 @ 0x005c7df0
// Stable ID: aa_005c7df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1, goto×1.
//  - Notable callees: FUN_004baf50, FUN_005c7cd0, FUN_005c7df0, FUN_0076c3c0, FUN_0076c4d0, FUN_0076c500.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_005c7df0(int param_1,float *param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e88;

  local_c = ExceptionList;

  iVar2 = *(int *)(param_1 + 0x10);

  ExceptionList = &local_c;

  if ((iVar2 == 0) && (ExceptionList = &local_c, iVar2 = FUN_004baf50(param_1 + 0x18), iVar2 == 0))

  {

    ExceptionList = local_c;

    return 1;

  }

  if ((DAT_00bc5558 & 1) == 0) {

    DAT_00bc5558 = DAT_00bc5558 | 1;

    local_4 = 0;

    FUN_0076c500(10000);

    local_4 = 0xffffffff;

  }

  uStack_10 = 0;

  FUN_0076c4d0();

  while( true ) {

    iVar3 = FUN_005c7cd0(iVar2,param_3);

    iVar4 = FUN_0076c3c0();

    fVar1 = (float)iVar4;

    if (iVar4 < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    fVar1 = fVar1 * DAT_00aaa664;

    if (iVar3 == 2) break;

    if ((iVar3 == 3) || (*param_2 <= fVar1)) goto LAB_005c7ed9;

  }

  uStack_10 = 0x1000000;

  *(uint8_t *)(param_1 + 0x53) = 1;

LAB_005c7ed9:

  *param_2 = *param_2 - fVar1;

  ExceptionList = local_c;

  return uStack_10 >> 0x18;

}
