// =============================================================================
// FUN_007fa730
// -----------------------------------------------------------------------------
// Stable ID: aa_007fa730
// Address:   0x007fa730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fa730 @ 0x007fa730
// Stable ID: aa_007fa730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_0096efd0×3, FUN_00403450, FUN_007fa730, FUN_0096f3e0, FUN_00989e00, SysFreeString, free.
//  - Return sites: 4.

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

void FUN_007fa730(int param_1,int *param_2,char param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ unaff_EBP;

  BSTR pOVar4;

  int unaff_EDI;

  BSTR local_9c;

  uint8_t *puStack_98;

  uint8_t auStack_94 [4];

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b1528;

  local_c = ExceptionList;

  if (((-1 < unaff_EDI) && (unaff_EDI < 8)) && (param_2 != (int *)0x0)) {

    local_9c = (BSTR)0x0;

    local_4 = 0;

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

    local_9c = operator_new(4);

    if (local_9c == (BSTR)0x0) {

      pOVar4 = (BSTR)0x0;

    }

    else {

      local_9c[0] = L'\0';

      local_9c[1] = L'\0';

      pOVar4 = local_9c;

    }

    local_c = (void *)((uint)local_c & 0xffffff00);

    puStack_98 = auStack_94;

    uVar2 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(unaff_EBP,uVar2);

    local_4._0_1_ = 2;

    FUN_00989e00(auStack_94,puStack_90);

    iVar3 = FUN_0096f3e0(auStack_94,0);

    local_4 = (uint)local_4._1_3_ << 8;

    if (puStack_90 != auStack_8c) {

      free(puStack_90);

    }

    if (iVar3 < 0) {

      if (pOVar4 != (BSTR)0x0) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pOVar4);

      }

      puStack_98 = (uint8_t *)0x0;

    }

    if (param_3 == '\0') {

      pvVar1 = *(void **)(param_1 + 0x4f4 + unaff_EDI * 4);

      if (pvVar1 != (void *)0x0) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint8_t **)(param_1 + 0x4f4 + unaff_EDI * 4) = puStack_98;

    }

    else {

      pvVar1 = *(void **)(param_1 + 0x514 + unaff_EDI * 4);

      if (pvVar1 != (void *)0x0) {

        FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint8_t **)(param_1 + 0x514 + unaff_EDI * 4) = puStack_98;

    }

    local_4 = 0xffffffff;

    SysFreeString(local_9c);

  }

  ExceptionList = local_c;

  return;

}
