// =============================================================================
// FUN_0059a940
// -----------------------------------------------------------------------------
// Stable ID: aa_0059a940
// Address:   0x0059a940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059a940 @ 0x0059a940
// Stable ID: aa_0059a940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×2, while×2.
//  - Notable callees: fread×9, FUN_0041c140×2, CONCAT31, FUN_0041a570, FUN_0041aa40, FUN_0059a940, FUN_0059c8f0, FUN_006903b0.
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

void __thiscall FUN_0059a940(int param_1,FILE *param_2)



{

  int iVar1;

  void *_DstBuf;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char *unaff_EDI;

  uint8_t local_7d;

  size_t local_7c;

  int local_78;

  int local_74;

  int local_70;

  int local_6c;

  int local_68;

  uint8_t local_64 [8];

  uint8_t local_5c [4];

  void *local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint8_t local_4c;

  uint8_t local_48 [4];

  void *local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_38 [8];

  void *local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24 [24];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5b68;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_74 = param_1;

  fread((void *)(param_1 + 4),0x3b4,1,param_2);

  fread((void *)(param_1 + 0x3b8),0x108,1,param_2);

  fread((void *)(param_1 + 0x4c0),0x5c,1,param_2);

  local_7c = 0;

  fread(&local_7c,4,1,param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0;

  if (0 < (int)local_7c) {

    _DstBuf = operator_new__(local_7c * 2 + 2);

    *(void **)(param_1 + 0x518) = _DstBuf;

    fread(_DstBuf,2,local_7c,param_2);

    *(uint16_t *)(*(int *)(param_1 + 0x518) + local_7c * 2) = 0;

  }

  fread(&local_6c,4,1,param_2);

  local_70 = 0;

  if (0 < local_6c) {

    do {

      fread(&local_7d,1,1,param_2);

      local_58 = (void *)0x0;

      local_54 = 0;

      local_50 = 0;

      local_4 = 0;

      local_78 = 0;

      fread(&local_78,4,1,param_2);

      iVar3 = 0;

      if (0 < local_78) {

        do {

          fread(local_24,0x18,1,param_2);

          FUN_0041aa40(local_24);

          iVar3 = iVar3 + 1;

        } while (iVar3 < local_78);

      }

      Map_LowerBoundFindByCharKey((void *)(local_74 + 0x51c),&local_68,&local_7d,unaff_EDI);

      iVar3 = local_68;

      if (local_68 == *(int *)(local_74 + 0x520)) {

        local_4c = local_7d;

        FUN_0041c140(local_5c);

        local_38[0] = local_4c;

        local_4._0_1_ = 1;

        FUN_0041c140(local_48);

        local_4 = CONCAT31(local_4._1_3_,2);

        FUN_0041a570(local_64,local_38);

        if (local_30 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_30);

        }

        local_30 = (void *)0x0;

        local_2c = 0;

        local_28 = 0;

        if (local_44 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_44);

        }

        local_44 = (void *)0x0;

        local_40 = 0;

        local_3c = 0;

      }

      else {

        iVar1 = *(int *)(local_68 + 0x18);

        if (*(int *)(local_68 + 0x14) != iVar1) {

          uVar2 = FUN_006903b0(iVar1,iVar1,*(int *)(local_68 + 0x14),local_68);

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = uVar2;

        }

        FUN_0059c8f0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x14),local_58,local_54,local_68);

      }

      local_4 = 0xffffffff;

      if (local_58 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_58);

      }

      local_70 = local_70 + 1;

      local_58 = (void *)0x0;

      local_54 = 0;

      local_50 = 0;

    } while (local_70 < local_6c);

  }

  ExceptionList = local_c;

  return;

}
