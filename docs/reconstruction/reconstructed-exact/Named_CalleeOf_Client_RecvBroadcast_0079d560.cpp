// =============================================================================
// Named_CalleeOf_Client_RecvBroadcast_0079d560
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d560
// Callee of Client_RecvBroadcast
// Address:   0x0079d560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Embedded strings (evidence):
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×13, while×7, goto×4, return×2, do×2, for×1.
//  - Notable callees: FUN_00788d20, FUN_00793890, FUN_007939c0, FUN_00793aa0, FUN_0079d430, FUN_0079d560, builtin_strncpy.
//  - Strings: "****".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvBroadcast
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_CalleeOf_Client_RecvBroadcast_0079d560(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  int local_8;

  int local_4;

  

  cVar1 = *param_2;

  pcVar2 = param_2;

  while (cVar1 != '\0') {

    pcVar2 = pcVar2 + 1;

    cVar1 = *pcVar2;

  }

  iVar3 = (int)pcVar2 - (int)param_2;

  if (iVar3 == 0) {

    return 0;

  }

  uVar8 = iVar3 + 1;

  pvVar4 = operator_new__(uVar8);

  pcVar2 = operator_new__(uVar8);

  FUN_00793aa0(pvVar4,param_2,uVar8);

  if (*(char *)(param_1 + 4) != '\0') {

    FUN_00793890();

  }

  iVar9 = 0;

  local_8 = 0;

  local_4 = 0;

  if (0 < iVar3) {

    do {

      if (*(char *)(iVar9 + (int)pvVar4) != ' ') goto joined_r0x0079d5e5;

      iVar9 = iVar9 + 1;

    } while (iVar9 < iVar3);

  }

LAB_0079d6cf:

  operator_delete__(pcVar2);

  operator_delete__(pvVar4);

  return local_8;

joined_r0x0079d5e5:

  while (iVar9 < iVar3) {

    iVar5 = FUN_007939c0(&DAT_00a2a000);

    if (iVar5 == -1) {

      cVar1 = *(char *)((int)pvVar4 + iVar9);

      pcVar6 = pcVar2;

      if (cVar1 != '\0') {

        do {

          if (pcVar2 + iVar3 <= pcVar6) break;

          *pcVar6 = cVar1;

          cVar1 = pcVar6[(int)((char *)((int)pvVar4 + iVar9) + (1 - (int)pcVar2))];

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

      }

      *pcVar6 = '\0';

    }

    else {

      FUN_00788d20();

      pcVar2[iVar5] = '\0';

    }

    cVar1 = FUN_0079d430(param_1,&local_4);

    if ((cVar1 != '\0') && (1 < local_4)) {

      iVar5 = iVar9 + 1;

      if (iVar5 < iVar9 + local_4) {

        uVar7 = (iVar9 + local_4) - iVar5;

        uVar8 = uVar7 >> 2;

        pcVar6 = param_2 + iVar5;

        while (uVar8 != 0) {

          uVar8 = uVar8 - 1;

          builtin_strncpy(pcVar6,"****",4);

          pcVar6 = pcVar6 + 4;

        }

        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *pcVar6 = '*';

          pcVar6 = pcVar6 + 1;

        }

      }

      iVar9 = iVar9 + local_4;

      local_8 = local_8 + local_4;

    }

    while( true ) {

      if (iVar3 <= iVar9) goto LAB_0079d6cf;

      if (*(char *)(iVar9 + (int)pvVar4) == ' ') break;

      iVar9 = iVar9 + 1;

    }

    while( true ) {

      if (iVar3 <= iVar9) goto LAB_0079d6cf;

      if (*(char *)(iVar9 + (int)pvVar4) != ' ') break;

      iVar9 = iVar9 + 1;

    }

  }

  goto LAB_0079d6cf;

}
