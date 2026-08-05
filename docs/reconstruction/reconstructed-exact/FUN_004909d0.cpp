// =============================================================================
// FUN_004909d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004909d0
// Address:   0x004909d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004909d0 @ 0x004909d0
// Stable ID: aa_004909d0
// Embedded strings (evidence for future rename):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, while×1, return×1.
//  - Notable callees: FUN_00746270×3, FUN_004909d0, FUN_00970140.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground".
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

void FUN_004909d0(uint32_t /* width from decompiler */ param_1,int param_2,char param_3,char param_4,char param_5)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  short local_c;

  short local_a;

  short local_8;

  short local_6;

  int local_4;

  

  iVar2 = param_2;

  if (param_2 != 0) {

    FUN_00746270(&param_2,"SkyBox");

    FUN_00746270(&local_c,"SkyBoxCloud");

    FUN_00746270(&local_8,"SkyBoxForeground");

    cVar3 = param_5;

    iVar6 = 0;

    while( true ) {

      iVar1 = *(int *)(local_4 + 0x94);

      if (*(int *)(iVar1 + 0xc0) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar1 + 0xc4) - *(int *)(iVar1 + 0xc0) >> 2;

      }

      if (iVar4 <= iVar6) break;

      piVar5 = (int *)(*(int *)(*(int *)(iVar1 + 0xc0) + iVar6 * 4) + 0x20);

      if (cVar3 == '\0') {

LAB_00490a88:

        if (((param_4 != '\0') &&

            ((*(short *)(*piVar5 + 0x1c) == local_c && (*(short *)(*piVar5 + 0x1e) == local_a)))) ||

           ((param_3 != '\0' &&

            ((*(short *)(*piVar5 + 0x1c) == local_8 && (*(short *)(*piVar5 + 0x1e) == local_6))))))

        goto LAB_00490acc;

      }

      else {

        if ((*(short *)(*piVar5 + 0x1c) != (short)param_2) ||

           (*(short *)(*piVar5 + 0x1e) != param_2._2_2_)) goto LAB_00490a88;

LAB_00490acc:

        FUN_00970140(param_1,iVar2);

      }

      iVar6 = iVar6 + 1;

    }

  }

  return;

}
