// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_00723f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00723f70
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x00723f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper. Evidence string: "Sound file had invalid group : %d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Sound file had invalid group : %d"
//   - "PlaySound Called: No Free channel of <= priority than %d found"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×13, return×4, do×3, while×3.
//  - Notable callees: FUN_007a4480×3, FUN_00723ea0, FUN_00723f70, SQRT.
//  - Strings: "Sound file had invalid group : %d".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
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

int Named_CalleeOf_Client_PlayNamedInterfaceSound_00723f70(float *param_1,int param_2)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int unaff_ESI;

  uint uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  uint local_30;

  int *local_2c;

  

  local_30 = *(uint *)(unaff_ESI + 0x210);

  iVar2 = 0;

  if (0 < (int)local_30) {

    piVar5 = (int *)(unaff_ESI + 0x31c);

    do {

      iVar4 = *piVar5;

      if (iVar4 == 0) {

        return iVar2;

      }

      if ((*(char *)(iVar4 + 0x1c5) == '\0') && (*(char *)(iVar4 + 0x3a) == '\0')) {

        return iVar2;

      }

      iVar2 = iVar2 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar2 < (int)local_30);

  }

  iVar2 = *(int *)(unaff_ESI + 0x260 + (param_2 / 10) * 4);

  uVar6 = 0;

  if (local_30 != 0) {

    local_2c = (int *)(unaff_ESI + 0x31c);

    iVar4 = iVar2;

    do {

      iVar3 = 0;

      if (*local_2c != 0) {

        iVar3 = *(int *)(*local_2c + 0x2c) / 10;

        if (iVar3 < 9) {

          iVar3 = *(int *)(unaff_ESI + 0x260 + iVar3 * 4);

        }

        else {

          FUN_007a4480(1,"Sound file had invalid group : %d",iVar3);

          iVar3 = 0;

        }

      }

      if (iVar4 < iVar3) {

        iVar4 = iVar3;

        local_30 = uVar6;

      }

      local_2c = local_2c + 1;

      uVar6 = uVar6 + 1;

    } while (uVar6 < *(uint *)(unaff_ESI + 0x210));

  }

  if (*(uint *)(unaff_ESI + 0x210) <= local_30) {

    fVar9 = param_1[2] - *(float *)(unaff_ESI + 0x228);

    fVar8 = param_1[1] - *(float *)(unaff_ESI + 0x224);

    fVar7 = *param_1 - *(float *)(unaff_ESI + 0x220);

    uVar6 = 0;

    local_2c = (int *)0x0;

    if (*(uint *)(unaff_ESI + 0x210) != 0) {

      piVar5 = (int *)(unaff_ESI + 0x31c);

      do {

        iVar4 = 0;

        if (*piVar5 != 0) {

          iVar4 = *(int *)(*piVar5 + 0x2c) / 10;

          if (iVar4 < 9) {

            iVar4 = *(int *)(unaff_ESI + 0x260 + iVar4 * 4);

          }

          else {

            FUN_007a4480(1,"Sound file had invalid group : %d",iVar4);

            iVar4 = 0;

          }

        }

        if (((iVar2 <= iVar4) &&

            (fVar1 = *(float *)(*piVar5 + 0x194),

            SQRT(fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9) < fVar1)) &&

           ((float)local_2c < fVar1)) {

          local_30 = uVar6;

          local_2c = (int *)fVar1;

        }

        uVar6 = uVar6 + 1;

        piVar5 = piVar5 + 1;

      } while (uVar6 < *(uint *)(unaff_ESI + 0x210));

    }

    if (*(uint *)(unaff_ESI + 0x210) <= local_30) {

      FUN_007a4480(0,"PlaySound Called: No Free channel of <= priority than %d found",iVar2);

      return -1;

    }

  }

  iVar2 = FUN_00723ea0(unaff_ESI);

  return iVar2;

}
