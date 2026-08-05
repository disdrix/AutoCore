// =============================================================================
// FUN_00828040
// -----------------------------------------------------------------------------
// Stable ID: aa_00828040
// Address:   0x00828040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00828040 @ 0x00828040
// Stable ID: aa_00828040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00411aa0×3, FUN_007916e0, FUN_00828040.
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

void __thiscall FUN_00828040(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  float fVar3;

  char cVar4;

  float10 fVar5;

  

  cVar4 = (**(code **)(*param_1 + 0xd0))();

  if ((cVar4 != (char)param_2) && (FUN_007916e0(param_2), (char)param_2 == '\x01')) {

    if ((param_1[0x15f] != 0) && (*(char *)((int)param_1 + 0x4fe) == '\x01')) {

      (**(code **)(*(int *)param_1[0x15f] + 0xcc))(0);

    }

    if ((((param_1[0x15c] != 0) && (param_1[0x152] == 1)) && (DAT_00d1b6d8 != 0)) &&

       ((iVar1 = param_1[0x156], iVar1 != 0 && (*(char *)(iVar1 + 0x628) != '\0')))) {

      fVar3 = (float)(int)*(short *)(iVar1 + 0x14) * g_flMsToSeconds_Inferred;

      fVar5 = (float10)FUN_00411aa0();

      if ((float10)fVar3 <= fVar5) {

        iVar2 = *(int *)param_1[0x15c];

        fVar5 = (float10)FUN_00411aa0();

        (**(code **)(iVar2 + 0x3b0))

                  ((float)((float10)g_flOne -

                          (fVar5 - (float10)fVar3) /

                          ((float10)*(int *)(iVar1 + 0x10) * (float10)g_flMsToSeconds_Inferred)));

      }

      else {

        iVar1 = *(int *)param_1[0x15c];

        fVar5 = (float10)FUN_00411aa0();

        (**(code **)(iVar1 + 0x3b0))((float)(fVar5 / (float10)fVar3));

      }

      iVar1 = *(int *)param_1[0x15c];

      fVar5 = (float10)(**(code **)(*(int *)param_1[0x15c] + 0x3c8))();

      (**(code **)(iVar1 + 0x3ac))((float)fVar5);

    }

    if (param_1[0x15b] != 0) {

      if ((char)param_1[0x13f] != '\0') {

        (**(code **)(*(int *)param_1[0x15b] + 4))(1);

        return;

      }

      (**(code **)(*(int *)param_1[0x15b] + 4))(0);

    }

  }

  return;

}
