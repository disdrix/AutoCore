// =============================================================================
// Named_CalleeOf_Client_UpdateObjectiveDisplayHud_0051fc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0051fc80
// Callee of Client_UpdateObjectiveDisplayHud
// Address:   0x0051fc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateObjectiveDisplayHud: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Embedded strings (evidence):
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: do×11, while×11, if×10, for×8, return×4.
//  - Notable callees: sprintf×9, FUN_0051fb50×4, block×4, FUN_0051fc80.
//  - Strings: "0%s"; "0%s 0%s 0%s 0%s"; "1%s"; "0%s 0%s 0%s 1%s".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_UpdateObjectiveDisplayHud
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

/* WARNING: Removing unreachable block (ram,0x0051fed4) */

/* WARNING: Removing unreachable block (ram,0x0051fe0f) */

/* WARNING: Removing unreachable block (ram,0x0051fe78) */

/* WARNING: Removing unreachable block (ram,0x0051ff34) */



int Named_CalleeOf_Client_UpdateObjectiveDisplayHud_0051fc80(int param_1,int param_2,char *param_3,char param_4)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  longlong lVar10;

  longlong lVar11;

  longlong lVar12;

  longlong lVar13;

  char local_20 [32];

  

  if (param_3 == (char *)0x0) {

    return 0;

  }

  if (param_1 == 0 && param_2 == 0) {

    if (param_4 == '\0') {

      sprintf(param_3,"0%s",&DAT_00a2c768);

    }

    else {

      sprintf(param_3,"0%s 0%s 0%s 0%s",&DAT_009cefb4,&DAT_00a2c774,&DAT_009cefb8);

    }

    pcVar2 = param_3 + 1;

    do {

      cVar1 = *param_3;

      param_3 = param_3 + 1;

    } while (cVar1 != '\0');

    return (int)param_3 - (int)pcVar2;

  }

  if ((param_1 == 1) && (param_2 == 0)) {

    if (param_4 == '\0') {

      sprintf(param_3,"1%s",&DAT_00a2c768);

    }

    else {

      sprintf(param_3,"0%s 0%s 0%s 1%s",&DAT_009cefb4,&DAT_00a2c774,&DAT_009cefb8);

    }

    pcVar2 = param_3 + 1;

    do {

      cVar1 = *param_3;

      param_3 = param_3 + 1;

    } while (cVar1 != '\0');

    return (int)param_3 - (int)pcVar2;

  }

  *param_3 = '\0';

  lVar10 = FUN_0051fb50(3,param_1,param_2);

  uVar5 = (uint32_t /* width from decompiler */)((ulonglong)lVar10 >> 0x20);

  lVar11 = FUN_0051fb50(2,param_1,param_2);

  uVar6 = (uint32_t /* width from decompiler */)((ulonglong)lVar11 >> 0x20);

  lVar12 = FUN_0051fb50(1,param_1,param_2);

  uVar7 = (uint32_t /* width from decompiler */)((ulonglong)lVar12 >> 0x20);

  lVar13 = FUN_0051fb50(0,param_1,param_2);

  uVar8 = (uint32_t /* width from decompiler */)((ulonglong)lVar13 >> 0x20);

  if (param_4 == '\0') {

    if (0 < lVar10) {

      sprintf(local_20,"%I64i%s ",(int)lVar10,uVar5,&DAT_009cefb4);

      pcVar2 = local_20;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      uVar3 = (int)pcVar2 - (int)local_20;

      pcVar2 = param_3 + -1;

      do {

        pcVar9 = pcVar2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = local_20;

      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar2 = pcVar2 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar2 = pcVar2 + 1;

      }

    }

    if (0 < lVar11) {

      sprintf(local_20,"%I64i%s ",(int)lVar11,uVar6,&DAT_00a2c774);

      pcVar2 = local_20;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      uVar3 = (int)pcVar2 - (int)local_20;

      pcVar2 = param_3 + -1;

      do {

        pcVar9 = pcVar2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = local_20;

      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar2 = pcVar2 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar2 = pcVar2 + 1;

      }

    }

    if (0 < lVar12) {

      sprintf(local_20,"%I64i%s ",(int)lVar12,uVar7,&DAT_009cefb8);

      pcVar2 = local_20;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      uVar3 = (int)pcVar2 - (int)local_20;

      pcVar2 = param_3 + -1;

      do {

        pcVar9 = pcVar2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = local_20;

      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar2 = pcVar2 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar2 = pcVar2 + 1;

      }

    }

    if (0 < lVar13) {

      sprintf(local_20,"%I64i%s",(int)lVar13,uVar8,&DAT_00a2c768);

      pcVar2 = local_20;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      uVar3 = (int)pcVar2 - (int)local_20;

      pcVar2 = param_3 + -1;

      do {

        pcVar9 = pcVar2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = local_20;

      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar2 = pcVar2 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar2 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar2 = pcVar2 + 1;

      }

    }

  }

  else {

    sprintf(param_3,"%I64i%s %I64i%s %I64i%s %I64i%s",(int)lVar10,uVar5,&DAT_009cefb4,(int)lVar11,

            uVar6,&DAT_00a2c774,(int)lVar12,uVar7,&DAT_009cefb8,(int)lVar13,uVar8,&DAT_00a2c768);

  }

  pcVar2 = param_3 + 1;

  do {

    cVar1 = *param_3;

    param_3 = param_3 + 1;

  } while (cVar1 != '\0');

  return (int)param_3 - (int)pcVar2;

}
