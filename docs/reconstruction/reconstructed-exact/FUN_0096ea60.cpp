// =============================================================================
// FUN_0096ea60
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ea60
// Address:   0x0096ea60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096ea60 @ 0x0096ea60
// Stable ID: aa_0096ea60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×20, do×10, while×10, for×2, return×2, goto×1.
//  - Notable callees: FUN_007a69d0×2, NDResourceCache_LookupOrCreate×2, _atexit×2, EnterCriticalSection, FUN_0096bcf0, FUN_0096ea60, FUN_00989e00, LeaveCriticalSection.
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



int FUN_0096ea60(int *param_1,uint *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint8_t uVar1;

  undefined *puVar2;

  char cVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  uint uVar8;

  int iVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint8_t local_4 [4];

  

  piVar10 = (int *)0x0;

  iVar4 = FUN_007a69d0();

  if (*(int *)(iVar4 + 0x2c) != 0) {

    iVar4 = 0;

    do {

      pcVar5 = (char *)*param_1;

      if ((char *)*param_1 == (char *)0x0) {

        pcVar5 = PTR_DAT_00afa2bc;

      }

      pcVar5 = strstr(pcVar5,(&PTR_DAT_00b01cb0)[iVar4]);

      puVar2 = PTR_DAT_00afa2bc;

      if (pcVar5 != (char *)0x0) {

        pcVar5 = (char *)*param_1;

        if ((char *)*param_1 == (char *)0x0) {

          pcVar5 = PTR_DAT_00afa2bc;

        }

        iVar9 = (int)&DAT_00d20c78 - (int)pcVar5;

        do {

          cVar3 = *pcVar5;

          pcVar5[iVar9] = cVar3;

          pcVar5 = pcVar5 + 1;

        } while (cVar3 != '\0');

        pcVar5 = (char *)*param_1;

        if ((char *)*param_1 == (char *)0x0) {

          pcVar5 = puVar2;

        }

        pcVar7 = pcVar5 + 1;

        do {

          cVar3 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar3 != '\0');

        pcVar6 = (&PTR_DAT_00b01cb0)[iVar4];

        pcVar12 = pcVar6 + 1;

        do {

          cVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar3 != '\0');

        (&DAT_00d20c74)[(int)(pcVar5 + (-((int)pcVar6 - (int)pcVar12) - (int)pcVar7))] = 0;

        iVar9 = FUN_007a69d0();

        iVar9 = *(int *)(iVar9 + 0x2c);

        if (iVar9 == 1) {

          puVar11 = (uint32_t /* width from decompiler */ *)0xd20c77;

          do {

            pcVar5 = (char *)((int)puVar11 + 1);

            puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

          } while (*pcVar5 != '\0');

          *puVar11 = DAT_00a9d99c;

        }

        else if (iVar9 == 2) {

          puVar11 = (uint32_t /* width from decompiler */ *)0xd20c77;

          do {

            pcVar5 = (char *)((int)puVar11 + 1);

            puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

          } while (*pcVar5 != '\0');

          *puVar11 = DAT_00a9d998;

        }

        else if (iVar9 == 3) {

          puVar11 = (uint32_t /* width from decompiler */ *)0xd20c77;

          do {

            pcVar5 = (char *)((int)puVar11 + 1);

            puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

          } while (*pcVar5 != '\0');

          *puVar11 = DAT_00a9d9a0;

        }

        pcVar5 = (&PTR_DAT_00b01cb0)[iVar4];

        pcVar7 = pcVar5;

        do {

          cVar3 = *pcVar7;

          pcVar7 = pcVar7 + 1;

        } while (cVar3 != '\0');

        pcVar12 = (char *)0xd20c77;

        do {

          pcVar6 = pcVar12 + 1;

          pcVar12 = pcVar12 + 1;

        } while (*pcVar6 != '\0');

        pcVar6 = pcVar5;

        for (uVar8 = (uint)((int)pcVar7 - (int)pcVar5) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar6;

          pcVar6 = pcVar6 + 4;

          pcVar12 = pcVar12 + 4;

        }

        for (uVar8 = (int)pcVar7 - (int)pcVar5 & 3; uVar1 = DAT_00a2c540, uVar8 != 0;

            uVar8 = uVar8 - 1) {

          *pcVar12 = *pcVar6;

          pcVar6 = pcVar6 + 1;

          pcVar12 = pcVar12 + 1;

        }

        puVar11 = (uint32_t /* width from decompiler */ *)0xd20c77;

        do {

          puVar13 = puVar11;

          puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

        } while (*(char *)((int)puVar13 + 1) != '\0');

        *(uint32_t /* width from decompiler */ *)((int)puVar13 + 1) = DAT_00a2c53c;

        *(uint8_t *)((int)puVar13 + 5) = uVar1;

        FUN_00989e00(local_4);

        if ((_DAT_00d1f7e8 & 1) == 0) {

          _DAT_00d1f7e8 = _DAT_00d1f7e8 | 1;

          _DAT_00d1f7e4 = &PTR_FUN_00a9ef54;

          _atexit((_func_4879 *)&LAB_009c3370);

        }

        piVar10 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,local_4,&DAT_00d1f7e4,param_3);

        if (piVar10 == (int *)0x0) {

          uVar8 = 0xffffffff;

        }

        else {

          cVar3 = (**(code **)(*piVar10 + 4))();

          uVar8 = (uint)(cVar3 != '\0');

        }

        *param_2 = uVar8;

        if (-1 < (int)uVar8) break;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < 5);

    if (iVar4 != 5) goto LAB_0096ecc7;

  }

  if ((_DAT_00d1f7e8 & 1) == 0) {

    _DAT_00d1f7e8 = _DAT_00d1f7e8 | 1;

    _DAT_00d1f7e4 = &PTR_FUN_00a9ef54;

    _atexit((_func_4879 *)&LAB_009c3370);

  }

  uVar8 = 0;

  piVar10 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_1,&DAT_00d1f7e4,param_3);

  if (piVar10 == (int *)0x0) {

    uVar8 = 0xffffffff;

  }

  else {

    cVar3 = (**(code **)(*piVar10 + 4))();

    if (cVar3 != '\0') {

      uVar8 = 1;

    }

  }

  *param_2 = uVar8;

LAB_0096ecc7:

  if (-1 < (int)*param_2) {

    iVar4 = NDResource_AcquireInnerObject();

    if (iVar4 != 0) {

      FUN_0096bcf0();

    }

    if ((char)piVar10[0xe] != '\0') {

      EnterCriticalSection((LPCRITICAL_SECTION)(piVar10 + 8));

    }

    if (piVar10[4] != 0) {

      piVar10[4] = piVar10[4] + -1;

    }

    if ((char)piVar10[0xe] != '\0') {

      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar10 + 8));

    }

    return iVar4;

  }

  return 0;

}
