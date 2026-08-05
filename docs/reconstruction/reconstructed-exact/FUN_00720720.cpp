// =============================================================================
// FUN_00720720
// -----------------------------------------------------------------------------
// Stable ID: aa_00720720
// Address:   0x00720720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720720 @ 0x00720720
// Stable ID: aa_00720720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×12, while×2, return×2.
//  - Notable callees: CARRY4, FUN_006a3db0, FUN_00720720, QueryPerformanceCounter, QueryPerformanceFrequency, SQRT.
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

int FUN_00720720(void)



{

  float fVar1;

  float fVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int unaff_EDI;

  uint64_t uVar8;

  int local_20;

  float local_1c;

  int local_18;

  LARGE_INTEGER local_10;

  LARGE_INTEGER local_8;

  

  iVar6 = 0;

  local_1c = 0.0;

  local_20 = -1;

  bVar3 = false;

  iVar7 = 0;

  local_18 = 0;

  while( true ) {

    if (*(int *)(unaff_EDI + 0x54) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(unaff_EDI + 0x58) - *(int *)(unaff_EDI + 0x54)) / 200;

    }

    if (iVar4 <= iVar7) break;

    iVar4 = *(int *)(unaff_EDI + 0x54) + local_18;

    if (*(int *)(iVar4 + 0xb8) != 0) {

      if (*(int *)(iVar4 + 0xb8) == 4) {

        *(uint8_t *)(unaff_EDI + 0x18) = 1;

        return iVar7;

      }

      if ((*(char *)(iVar4 + 0xbc) != '\0') && (!bVar3)) {

        local_20 = iVar7;

      }

      fVar1 = *(float *)(unaff_EDI + 0x38) - *(float *)(iVar4 + 0x88);

      fVar2 = *(float *)(unaff_EDI + 0x30) - *(float *)(iVar4 + 0x80);

      fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2);

      if ((fVar1 < local_1c) || (local_1c <= 0.0)) {

        local_1c = fVar1;

        if (fVar1 <= *(float *)(iVar4 + 0x9c)) {

          local_10.s.LowPart = 0;

          local_10.s.HighPart = 0;

          local_8.s.LowPart = 0;

          local_8.s.HighPart = 0;

          QueryPerformanceCounter(&local_10);

          QueryPerformanceFrequency(&local_8);

          uVar8 = FUN_006a3db0();

          iVar5 = (int)((ulonglong)uVar8 >> 0x20) + *(int *)(iVar4 + 0xac) +

                  (uint)CARRY4((uint)uVar8,*(uint *)(iVar4 + 0xa8));

          if ((iVar5 <= local_10.s.HighPart) &&

             ((iVar5 < local_10.s.HighPart ||

              ((uint)uVar8 + *(uint *)(iVar4 + 0xa8) < local_10.s.LowPart)))) {

            local_20 = iVar7;

          }

          bVar3 = true;

        }

      }

    }

    iVar7 = iVar7 + 1;

    local_18 = local_18 + 200;

  }

  if ((local_20 == -1) && (*(char *)(unaff_EDI + 0x15) != '\0')) {

    iVar7 = 0;

    while( true ) {

      if (*(int *)(unaff_EDI + 0x54) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(unaff_EDI + 0x58) - *(int *)(unaff_EDI + 0x54)) / 200;

      }

      if (iVar4 <= iVar7) break;

      if (*(int *)(*(int *)(unaff_EDI + 0x54) + 0xb8 + iVar6) == 5) {

        local_20 = iVar7;

      }

      iVar7 = iVar7 + 1;

      iVar6 = iVar6 + 200;

    }

  }

  return local_20;

}
