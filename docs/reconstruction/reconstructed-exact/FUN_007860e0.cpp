// =============================================================================
// FUN_007860e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007860e0
// Address:   0x007860e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007860e0 @ 0x007860e0
// Stable ID: aa_007860e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×6, while×4, do×3, return×1.
//  - Notable callees: QueryPerformanceCounter×3, EnterCriticalSection×2, LeaveCriticalSection×2, FUN_00780690, FUN_00785d10, FUN_00785d40, FUN_00785d70, FUN_00785f50.
//  - Return sites: 1.

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

void FUN_007860e0(uint32_t /* width from decompiler */ *param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int *piVar1;

  int iVar2;

  DWORD *pDVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int extraout_EDX;

  int iVar7;

  uint64_t uVar8;

  LARGE_INTEGER local_8;

  

  if (*(char *)((int)param_1 + 0x175) != '\0') {

    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x16);

    EnterCriticalSection(lpCriticalSection);

    iVar7 = param_1[0x13];

    if (iVar7 != param_1[0x14]) {

      do {

        iVar2 = *(int *)(iVar7 + 4);

        FUN_00780690();

        iVar6 = *(int *)(iVar2 + 4);

        iVar6 = __alldiv(*(uint32_t /* width from decompiler */ *)(iVar6 + 8),*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc),

                         *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14));

        piVar1 = (int *)(iVar2 + 0x28);

        *piVar1 = *piVar1 + iVar6;

        iVar2 = *(int *)(iVar7 + 4);

        piVar1 = (int *)(iVar2 + 0x3c);

        *piVar1 = *piVar1 + 1;

        pDVar3 = *(DWORD **)(iVar2 + 4);

        pDVar3[2] = 0;

        pDVar3[3] = 0;

        pDVar3[8] = 0;

        pDVar3[6] = 0;

        pDVar3[7] = 0;

        pDVar3[9] = 0;

        pDVar3[10] = 0;

        QueryPerformanceCounter(&local_8);

        *pDVar3 = local_8.s.LowPart;

        pDVar3[1] = local_8.s.HighPart;

        FUN_00785d70();

        iVar7 = iVar7 + 0xc;

      } while (iVar7 != param_1[0x14]);

    }

    LeaveCriticalSection(lpCriticalSection);

    if (*(char *)(param_1 + 0x1c) != '\0') {

      FUN_0079ac20();

      if (((float)param_1[5] == 0.0) || ((float)param_1[4] / (float)param_1[5] <= 0.0)) {

        FUN_00785f50(*param_1);

        EnterCriticalSection(lpCriticalSection);

        iVar7 = param_1[0x13];

        if (iVar7 != param_1[0x14]) {

          do {

            iVar2 = *(int *)(iVar7 + 4);

            iVar6 = *(int *)(iVar2 + 0x10);

            iVar4 = *(int *)(iVar2 + 0x14);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = 0;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30) = 0;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x50) = 0;

            while (iVar6 != iVar4) {

              FUN_00785d40();

              iVar6 = extraout_EDX + 4;

            }

            iVar2 = *(int *)(iVar7 + 4);

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38) = 0;

            if (*(int *)(iVar2 + 0x10) != *(int *)(iVar2 + 0x14)) {

              do {

                uVar8 = FUN_00785d10();

              } while ((int)uVar8 + 4 != (int)((ulonglong)uVar8 >> 0x20));

            }

            iVar7 = iVar7 + 0xc;

          } while (iVar7 != param_1[0x14]);

        }

        LeaveCriticalSection(lpCriticalSection);

        QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 6));

        QueryPerformanceCounter((LARGE_INTEGER *)(param_1 + 8));

        uVar5 = DAT_00aaa688;

        param_1[4] = DAT_00aaa688;

        *(uint8_t *)(param_1 + 2) = 1;

        param_1[5] = uVar5;

      }

    }

  }

  return;

}
