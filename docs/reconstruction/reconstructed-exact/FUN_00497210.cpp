// =============================================================================
// FUN_00497210
// -----------------------------------------------------------------------------
// Stable ID: aa_00497210
// Address:   0x00497210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497210 @ 0x00497210
// Stable ID: aa_00497210
// Embedded strings (evidence for future rename):
//   - "Direction"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_00497210, FUN_00497490, FUN_00972f10.
//  - Strings: "Direction".
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

void __thiscall FUN_00497210(int param_1,int *param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float unaff_EBX;

  float unaff_ESI;

  int iVar6;

  float unaff_EDI;

  uint8_t *puVar7;

  uint8_t *puVar8;

  uint8_t auStack_18 [8];

  uint8_t auStack_10 [12];

  int iStack_4;

  

  if (((param_2 != (int *)0x0) && (DAT_00aefa54 != '\0')) && (*(char *)(DAT_00d1f048 + 0xf) != '\0')

     ) {

    uVar2 = (**(code **)(*param_2 + 0x40))("Direction");

    (**(code **)(*param_2 + 0x5c))(uVar2,auStack_10);

    puVar8 = auStack_18;

    puVar7 = &stack0xffffffdc;

    (**(code **)(*param_2 + 0x1c))(puVar7,puVar8);

    FUN_00972f10(puVar7,puVar8);

    FUN_00497490(iStack_4);

    fVar1 = DAT_00a110ac;

    iVar6 = 0;

    iVar5 = 0;

    while( true ) {

      if (*(int *)(iStack_4 + 4) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iStack_4 + 8) - *(int *)(iStack_4 + 4) >> 4;

      }

      if (iVar3 <= iVar6) break;

      iVar3 = *(int *)(param_1 + 0x40);

      pfVar4 = (float *)(iVar3 + iVar5);

      if (0.0 < *(float *)(iVar3 + 4 + iVar5) * unaff_ESI +

                *(float *)(iVar3 + 8 + iVar5) * unaff_EBX + *pfVar4 * unaff_EDI) {

        pfVar4[3] = pfVar4[3] -

                    (pfVar4[1] * (0.0 - unaff_ESI) * fVar1 + pfVar4[2] * (0.0 - unaff_EBX) * fVar1 +

                    *pfVar4 * (0.0 - unaff_EDI) * fVar1);

      }

      iVar6 = iVar6 + 1;

      iVar5 = iVar5 + 0x10;

    }

  }

  return;

}
