// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×13, while×2, for×2, goto×2, return×2, do×1.
//  - Notable callees: FUN_007a4480×4, strtok×3, FUN_008f8200×2, sprintf×2, CNDHash_LookupByKey, FUN_00411180, FUN_00419880, FUN_00952ec0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "CBID:%d Name:%s".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00952ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00952ec0
// Address:   0x00952ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_00952ec0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  uint key;

  void *pvVar2;

  char *pcVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  char *local_424;

  uint8_t local_420 [4];

  int *local_41c;

  int *local_418;

  int local_414;

  int local_410;

  char local_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7ec4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_410 = param_1;

  local_424 = strtok((char *)0x0,param_3);

  if (local_424 != (char *)0x0) {

    key = atoi(local_424);

    if ((key == 0) ||

       (pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xd30) + 0xf10),key),

       pvVar2 == (void *)0x0)) {

      local_41c = (int *)0x0;

      local_418 = (int *)0x0;

      local_414 = 0;

      local_4 = 0;

      FUN_00411180();

      local_424 = strtok((char *)0x0,param_3);

      while (local_424 != (char *)0x0) {

        if ((local_41c == (int *)0x0) ||

           ((uint)(local_414 - (int)local_41c >> 2) <= (uint)((int)local_418 - (int)local_41c >> 2))

           ) {

          FUN_00419880(local_420,local_418,&local_424);

        }

        else {

          *local_418 = (int)local_424;

          local_418 = local_418 + 1;

        }

        local_424 = strtok((char *)0x0,param_3);

      }

      iVar6 = *(int *)(*(int *)(local_410 + 0xd30) + 0xf10);

      iVar4 = 0;

      if (*(char *)(iVar6 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar6 + 0x1d) = 1;

LAB_00953030:

      iVar1 = local_410;

      iVar6 = *(int *)(*(int *)(local_410 + 0xd30) + 0xf10);

      if (*(char *)(iVar6 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar6 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(iVar4 + 8);

      }

      if (iVar6 != 0) {

        if (local_41c != local_418) {

          piVar5 = local_41c;

          do {

            pcVar3 = strstr((char *)(iVar6 + 0x40),(char *)*piVar5);

            if (pcVar3 == (char *)0x0) goto LAB_00953030;

            piVar5 = piVar5 + 1;

          } while (piVar5 != local_418);

        }

        sprintf(local_40c,"CBID:%d Name:%s",*(uint32_t /* width from decompiler */ *)(iVar6 + 0x34),iVar6 + 0x40);

        if (DAT_00d1b8dc != 0) {

          FUN_008f8200(DAT_00d1b8dc,6,"System",local_40c,0);

        }

        goto LAB_00953030;

      }

      *(uint8_t *)(*(int *)(*(int *)(iVar1 + 0xd30) + 0xf10) + 0x1d) = 0;

      local_4 = 0xffffffff;

      if (local_41c != (int *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_41c);

      }

    }

    else {

      sprintf(local_40c,"CBID:%d Name:%s",*(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x34),(int)pvVar2 + 0x40);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,"System",local_40c,0);

      }

    }

  }

  ExceptionList = local_c;

  return 1;

}
