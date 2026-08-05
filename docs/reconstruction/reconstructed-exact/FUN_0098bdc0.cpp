// =============================================================================
// FUN_0098bdc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098bdc0
// Address:   0x0098bdc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098bdc0 @ 0x0098bdc0
// Stable ID: aa_0098bdc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×18, goto×7, return×1.
//  - Notable callees: ABS, FUN_0098bdc0.
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

void __thiscall FUN_0098bdc0(int *param_1,float param_2)



{

  bool bVar1;

  bool bVar2;

  float fVar3;

  char cVar4;

  float fVar5;

  float fVar6;

  

  fVar3 = DAT_00aaa7dc;

  if (((char)param_1[0x122] == '\0') ||

     (ABS((float)param_1[0x125] - (float)param_1[0x123]) <= DAT_00aaa664)) goto LAB_0098be9a;

  bVar1 = (float)param_1[0x125] != (float)param_1[0x123];

  bVar2 = (float)param_1[0x123] <= (float)param_1[0x125];

  fVar5 = (float)param_1[0x123] - (float)param_1[0x125];

  fVar6 = 0.0;

  if (0.0 <= fVar5) {

    fVar6 = DAT_00aaa7dc;

  }

  fVar6 = fVar6 - fVar5;

  if (fVar5 < 0.0) {

    fVar5 = fVar5 + DAT_00aaa7dc;

  }

  if (fVar6 <= fVar5) {

    fVar6 = (float)param_1[0x125] - (float)param_1[0x124] * param_2;

    param_1[0x125] = (int)fVar6;

    if (0.0 <= fVar6) {

      if (bVar2 && bVar1) goto LAB_0098bf70;

LAB_0098be7b:

      if ((float)param_1[0x123] <= fVar6 && fVar6 != (float)param_1[0x123]) goto LAB_0098be84;

    }

    else {

      fVar6 = fVar6 + fVar3;

      param_1[0x125] = (int)fVar6;

      if (bVar2 && bVar1) {

        if ((float)param_1[0x123] <= fVar6 && fVar6 != (float)param_1[0x123]) goto LAB_0098bf57;

      }

      else if (fVar6 < (float)param_1[0x123]) {

LAB_0098bf57:

        param_1[0x125] = param_1[0x123];

      }

    }

  }

  else {

    fVar6 = (float)param_1[0x124] * param_2 + (float)param_1[0x125];

    param_1[0x125] = (int)fVar6;

    if (fVar6 <= fVar3) {

      if (bVar2 && bVar1) {

        if (fVar6 < (float)param_1[0x123]) {

LAB_0098bef3:

          param_1[0x125] = param_1[0x123];

        }

      }

      else if ((float)param_1[0x123] <= fVar6 && fVar6 != (float)param_1[0x123]) goto LAB_0098bef3;

    }

    else {

      fVar6 = fVar6 - fVar3;

      param_1[0x125] = (int)fVar6;

      if (bVar2 && bVar1) goto LAB_0098be7b;

LAB_0098bf70:

      if ((float)param_1[0x123] <= fVar6) goto LAB_0098be90;

LAB_0098be84:

      param_1[0x125] = param_1[0x123];

    }

  }

LAB_0098be90:

  (**(code **)(*param_1 + 0x34c))();

LAB_0098be9a:

  (**(code **)(*param_1 + 500))(param_2);

  cVar4 = (**(code **)(*param_1 + 0xf8))();

  if (cVar4 != '\0') {

    (**(code **)(*param_1 + 0x348))(param_2);

  }

  if ((int *)param_1[0xad] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(param_2);

  }

  return;

}
