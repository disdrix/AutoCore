// =============================================================================
// FUN_00953150
// -----------------------------------------------------------------------------
// Stable ID: aa_00953150
// Address:   0x00953150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00953150 @ 0x00953150
// Stable ID: aa_00953150
// Embedded strings (evidence for future rename):
//   - "you are not allowed to choose a new name for yourself"
//   - "usage: //playerrename <newname>"
//   - "rename sent to servers"
//   - "//playerrename %s %s"
//   - "%s is not a valid name"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×3, while×3, for×1, goto×1.
//  - Notable callees: FUN_008f8200×4, sprintf×3, FUN_0079d430×2, FUN_00953150, __RTDynamicCast, isalnum, strchr, strtok.
//  - Strings: "you are not allowed to choose a new name for yourself"; "usage: //playerrename <newname>"; "rename sent to servers"; "//playerrename %s %s".
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_00953150(int param_1,int param_2,char *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  char acStack_78 [120];

  

  if (0 < *(int *)(*(int *)(param_1 + 0xe98) + 0x6b4)) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = 1;

    return 0;

  }

  uVar2 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                          &CDlgChatLog::RTTI_Type_Descriptor,0);

  iVar6 = 0x23;

  pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                        *(int *)(param_1 + 0xe98)) + 0x160))();

  pcVar3 = strchr(pcVar3,iVar6);

  if (pcVar3 == (char *)0x0) {

    sprintf(acStack_78,"you are not allowed to choose a new name for yourself");

    FUN_008f8200(uVar2,6,&DAT_00a1419b,acStack_78,0);

    return 0;

  }

  pcVar3 = strtok((char *)0x0,param_3);

  if (pcVar3 == (char *)0x0) {

    FUN_008f8200(uVar2,6,&DAT_00a1419b,"usage: //playerrename <newname>",0);

    return 0;

  }

  if (*pcVar3 != '\0') {

    iVar6 = 0;

    pcVar5 = pcVar3;

    do {

      iVar4 = isalnum((int)*pcVar5);

      if (((iVar4 == 0) && (*pcVar5 != '_')) || (0x10 < iVar6)) goto LAB_00953329;

      pcVar5 = pcVar5 + 1;

      iVar6 = iVar6 + 1;

    } while (*pcVar5 != '\0');

  }

  cVar1 = FUN_0079d430(DAT_00d1d8cc,0);

  if ((cVar1 == '\0') && (cVar1 = FUN_0079d430(DAT_00d1d8c8,0), cVar1 == '\0')) {

    FUN_008f8200(uVar2,6,&DAT_00a1419b,"rename sent to servers",0);

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0xe98)) + 0x160))(pcVar3);

    sprintf(acStack_78,"//playerrename %s %s",uVar2);

    pcVar5 = acStack_78;

    pcVar3 = (char *)(param_2 + 0x2e);

    iVar6 = (int)pcVar3 - (int)pcVar5;

    do {

      cVar1 = *pcVar5;

      pcVar5[iVar6] = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    *(short *)(param_2 + 0x2c) = (short)pcVar3 - ((short)param_2 + 0x2f);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = 1;

    return 0;

  }

LAB_00953329:

  sprintf(acStack_78,"%s is not a valid name",pcVar3);

  FUN_008f8200(uVar2,6,&DAT_00a1419b,acStack_78,0);

  return 0;

}
