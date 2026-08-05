// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, return×2, do×1.
//  - Notable callees: QueryPerformanceCounter×2, FUN_00480970, FUN_0071e820, FUN_0071f760, FUN_0071f810, FUN_00720290, FUN_00720f40, FUN_007212b0.
//  - Strings: "Requesting PlayBackgroundMusic on %s".
//  - Return sites: 2.

// =============================================================================
// Mission_Requesting_PlayBackgroundMusic_on_s_00721d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00721d30
// Address:   0x00721d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Requesting PlayBackgroundMusic on %s"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_Requesting_PlayBackgroundMusic_on_s_00721d30(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int iVar2;

  int unaff_EBX;

  int *piVar3;

  int iVar4;

  char *_Str1;

  int local_8c;

  LARGE_INTEGER local_88;

  char acStack_80 [128];

  

  local_8c = 0;

  piVar3 = (int *)(unaff_EBX + 0x88);

  do {

    if ((*piVar3 != 0) && (iVar1 = FUN_0071f760(1), iVar1 != 0)) {

      local_88.s.LowPart = 0;

      local_88.s.HighPart = 0;

      iVar1 = FUN_0071e820(0);

      if (iVar1 == 0) {

        QueryPerformanceCounter(&local_88);

        iVar1 = *piVar3;

        *(DWORD *)(iVar1 + 0x2f8) = local_88.s.LowPart;

        *(LONG *)(iVar1 + 0x2fc) = local_88.s.HighPart;

        iVar1 = *piVar3;

        if (*(char *)(iVar1 + 0x38) == '\0') {

          *(float *)(iVar1 + 0x1b0) = *(float *)(iVar1 + 0x2e4) * *(float *)(unaff_EBX + 0x24);

        }

        else if (*(float *)(iVar1 + 0x1a4) <= *(float *)(iVar1 + 0x1b0)) {

          FUN_00720290(local_8c,1);

        }

        iVar1 = *piVar3;

        if ((iVar1 != 0) && (*(float *)(iVar1 + 0x1a4) != *(float *)(iVar1 + 0x1b0))) {

          FUN_00720f40(param_1);

        }

      }

      else {

        QueryPerformanceCounter(&local_88);

        iVar1 = *piVar3;

        *(DWORD *)(iVar1 + 0x2f8) = local_88.s.LowPart;

        *(LONG *)(iVar1 + 0x2fc) = local_88.s.HighPart;

        FUN_0071f810();

        if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

        }

        *piVar3 = 0;

      }

    }

    local_8c = local_8c + 1;

    piVar3 = piVar3 + 1;

  } while (local_8c < 2);

  if (((*(int *)(unaff_EBX + 0x44) != 0) &&

      (iVar1 = (*(int *)(unaff_EBX + 0x48) - *(int *)(unaff_EBX + 0x44)) / 200, iVar1 != 0)) &&

     (*(char *)(unaff_EBX + 0x12) == '\0')) {

    iVar2 = FUN_007212b0();

    iVar4 = *(int *)(unaff_EBX + 0x44) + iVar2 * 200;

    sprintf(acStack_80,"Requesting PlayBackgroundMusic on %s",iVar4);

    iVar4 = FUN_007217c0(unaff_EBX,iVar4,0);

    if ((iVar4 != 0) &&

       (_Str1 = *(char **)(unaff_EBX + 0x44), _Str1 != *(char **)(unaff_EBX + 0x48))) {

      while (iVar4 = _stricmp(_Str1,(char *)(*(int *)(unaff_EBX + 0x44) + iVar2 * 200)), iVar4 != 0)

      {

        _Str1 = _Str1 + 200;

        if (_Str1 == *(char **)(unaff_EBX + 0x48)) {

          return;

        }

      }

      FUN_00480970(_Str1 + 200,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x48),_Str1,iVar1);

      *(int *)(unaff_EBX + 0x48) = *(int *)(unaff_EBX + 0x48) + -200;

    }

  }

  return;

}
