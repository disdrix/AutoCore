// =============================================================================
// FUN_0092abc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092abc0
// Address:   0x0092abc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092abc0 @ 0x0092abc0
// Stable ID: aa_0092abc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, while×3, do×2, goto×2, return×2.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_005134e0, FUN_0092abc0, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ FUN_0092abc0(float *param_1,int *param_2,float *param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *unaff_EDI;

  float fVar5;

  float fVar6;

  float fVar7;

  int local_20;

  int *piStack_1c;

  int *local_18;

  uint32_t /* width from decompiler */ local_14 [4];

  

  iVar2 = *(int *)(*(int *)(*unaff_EDI + 0xd34) + 0x18);

  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + (*(uint *)(iVar2 + 8) & 0xe) * 4) + 4);

  if (iVar2 == 0) {

LAB_0092ac09:

    local_20 = 0;

  }

  else {

    do {

      if (*(int *)(iVar2 + 0x10) == 0xe) {

        if (iVar2 == 0) goto LAB_0092ac09;

        local_20 = *(int *)(iVar2 + 8);

        goto LAB_0092ac1a;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    local_20 = 0;

  }

LAB_0092ac1a:

  if (local_20 == 0) {

    return 0;

  }

  local_14[0] = 0;

  local_18 = (int *)0x0;

  FUN_004294f0();

  iVar2 = FUN_004022a0(local_14,&local_18);

  while (iVar2 == 0) {

    iVar2 = (**(code **)(*local_18 + 0x1d4))();

    iVar4 = 0;

    if (0 < unaff_EDI[0x20]) {

      piStack_1c = unaff_EDI + 0x21;

      do {

        if ((((*(int *)(iVar2 + 0x14c) == *piStack_1c) && (cVar1 = FUN_005134e0(), cVar1 == '\0'))

            && ((*(uint *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x180 + iVar2) >> 3 & 1) == 0)) &&

           (((unaff_EDI[0x42] == -1 ||

             (iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))

                                (), unaff_EDI[0x42] <= iVar3)) &&

            ((unaff_EDI[0x43] == -1 ||

             (iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))

                                (), iVar3 <= unaff_EDI[0x43])))))) {

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x144))();

          iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

          fVar6 = *(float *)(iVar3 + 0x84 + iVar2) - *param_1;

          fVar5 = *(float *)(iVar3 + 0x8c + iVar2) - param_1[2];

          fVar7 = *(float *)(iVar3 + 0x88 + iVar2) - param_1[1];

          fVar5 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;

          if (fVar5 < *param_3) {

            *param_3 = fVar5;

            *param_2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

          }

        }

        piStack_1c = piStack_1c + 1;

        iVar4 = iVar4 + 1;

      } while (iVar4 < unaff_EDI[0x20]);

    }

    iVar2 = FUN_004022a0(local_14,&local_18);

  }

  if (*(char *)(local_20 + 0x28) != '\0') {

    *(uint8_t *)(local_20 + 0x28) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(local_20 + 4));

  }

  return 1;

}
