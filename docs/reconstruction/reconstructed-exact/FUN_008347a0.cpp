// =============================================================================
// FUN_008347a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008347a0
// Address:   0x008347a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008347a0 @ 0x008347a0
// Stable ID: aa_008347a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00758460, FUN_008347a0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_008347a0(int *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  float fVar11;

  float fVar12;

  

  fVar11 = (float)DAT_00d1e81c * _DAT_00aaa86c;

  fVar12 = (float)DAT_00d1e818 * _DAT_00aaa7d8;

  piVar4 = (int *)param_1[0x124];

  piVar7 = (int *)*piVar4;

  if (piVar7 != piVar4) {

    do {

      piVar1 = (int *)*piVar7;

      if (piVar1 != piVar4) {

        iVar5 = piVar1[2];

        iVar2 = piVar7[2];

        if ((iVar5 == iVar2) || (piVar1[3] == piVar7[3])) {

          iVar8 = piVar7[3];

          iVar3 = piVar1[3];

          iVar9 = iVar8;

          if (iVar8 <= iVar3) {

            iVar9 = iVar3;

          }

          iVar10 = iVar2;

          if (iVar2 <= iVar5) {

            iVar10 = iVar5;

          }

          if (iVar3 <= iVar8) {

            iVar8 = iVar3;

          }

          if (iVar2 < iVar5) {

            iVar5 = iVar2;

          }

          puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x164))(0);

          FUN_00758460((float)(iVar5 - (int)fVar12),(float)(iVar8 - (int)fVar11),

                       (float)(iVar10 + (int)fVar12),(float)(iVar9 + (int)fVar11),&DAT_00d1ec78,0,

                       *puVar6,1,0,0,&DAT_00d1ecac);

        }

      }

      piVar7 = (int *)*piVar7;

      piVar4 = (int *)param_1[0x124];

    } while (piVar7 != piVar4);

  }

  return;

}
