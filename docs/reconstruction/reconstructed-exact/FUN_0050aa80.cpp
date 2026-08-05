// =============================================================================
// FUN_0050aa80
// -----------------------------------------------------------------------------
// Stable ID: aa_0050aa80
// Address:   0x0050aa80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0050aa80 @ 0x0050aa80
// Stable ID: aa_0050aa80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×14, goto×4, return×2, do×1, while×1.
//  - Notable callees: FUN_004e1830×2, Object_GetRootRaceId×2, CNDHash_LookupByKey, CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, FUN_00404840, FUN_00418700, FUN_00508770.
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

uint32_t /* width from decompiler */ FUN_0050aa80(int param_1,int *param_2,RACE_ID_INFERRED param_3,int param_4)



{

  ushort uVar1;

  int iVar2;

  short sVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *pvVar5;

  int iVar6;

  int iVar7;

  int *pObject;

  RACE_ID_INFERRED RVar8;

  uint key;

  int local_10;

  int local_c;

  uint32_t /* width from decompiler */ local_8 [2];

  

  local_c = 0;

  local_10 = 0x50;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_0050eec0(param_1);

  if (puVar4[9] == 0) {

    (**(code **)*puVar4)(1);

    return 0;

  }

  key = param_2[0x3f];

  local_8[0] = 0;

  pvVar5 = (void *)FUN_00541a80();

  pvVar5 = CNDHash_LookupByKey(pvVar5,key);

  if (pvVar5 != (void *)0x0) {

    local_c = *(int *)((int)pvVar5 + 0x138);

    local_10 = *(int *)((int)pvVar5 + 0x13c);

  }

  FUN_00508770();

  iVar6 = FUN_004e1830(local_8,&param_1);

  iVar2 = param_4;

  do {

    if (iVar6 != 0) {

      if (*(char *)(puVar4 + 10) != '\0') {

        *(uint8_t *)(puVar4 + 10) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar4 + 1));

      }

      (**(code **)*puVar4)(1);

      return 1;

    }

    iVar7 = CVOGReaction_RandomUnitScalar();

    iVar6 = param_1;

    if (0xfffff < *(int *)(iVar7 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

    if ((int)((uint)uVar1 % 10000) <= (int)*(short *)(param_1 + 8)) {

      pObject = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_1 + 4));

      param_2 = pObject;

      (**(code **)(*pObject + 8))(*(uint32_t /* width from decompiler */ *)(iVar6 + 4),0,0);

      if (*(int *)(pObject[0x2a] + 0x3c) != 0) {

        FUN_00509c70(pObject,(int)*(short *)(*(int *)(pObject[0x2a] + 0x3c) + 0x3f0),0x80000000,1,0)

        ;

      }

      RVar8 = Object_GetRootRaceId(pObject);

      if ((RVar8 == param_3) ||

         (RVar8 = Object_GetRootRaceId(pObject), RVar8 == ~RACE_HUMAN_INFERRED)) {

        iVar6 = (int)*(short *)((int)pObject + 0xea) + (int)(short)pObject[0x3a];

        if (iVar6 < 0x51) {

          sVar3 = (short)iVar6;

          if (sVar3 != 0) {

            if (0x50 < iVar6) goto LAB_0050abde;

            goto LAB_0050abe7;

          }

LAB_0050ac0d:

          iVar6 = *(int *)(iVar2 + 4);

          iVar7 = FUN_00418700(iVar6,*(uint32_t /* width from decompiler */ *)(iVar6 + 4),&param_2);

          FUN_00404840(1);

          *(int *)(iVar6 + 4) = iVar7;

          **(int **)(iVar7 + 4) = iVar7;

          goto LAB_0050ac34;

        }

LAB_0050abde:

        sVar3 = 0x50;

LAB_0050abe7:

        if (sVar3 <= local_10) {

          if (0x50 < iVar6) {

            iVar6 = 0x50;

          }

          if (local_c <= (short)iVar6) goto LAB_0050ac0d;

        }

      }

      (**(code **)*pObject)(1);

    }

LAB_0050ac34:

    iVar6 = FUN_004e1830(local_8,&param_1);

  } while( true );

}
