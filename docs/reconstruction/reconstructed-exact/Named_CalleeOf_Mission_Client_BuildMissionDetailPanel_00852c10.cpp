// =============================================================================
// Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_00852c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00852c10
// Callee of Mission_Client_BuildMissionDetailPanel
// Address:   0x00852c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Client_BuildMissionDetailPanel: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, goto×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00852c10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Client_BuildMissionDetailPanel
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

int Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_00852c10(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int unaff_ESI;

  uint8_t auStack_58 [4];

  int local_54;

  int iStack_50;

  int iStack_4c;

  float fStack_48;

  int iStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float local_30 [2];

  uint8_t local_28 [4];

  uint8_t auStack_24 [12];

  uint8_t auStack_18 [4];

  uint8_t auStack_14 [16];

  

  piVar5 = *(int **)(unaff_ESI + 0x500);

  local_54 = 0;

  if (piVar5 == (int *)0x0) {

LAB_00852d4f:

    if (*(int *)(unaff_ESI + 0x504) == 0) goto LAB_00852d76;

  }

  else {

    if (*(int *)(unaff_ESI + 0x504) == 0) {

      if (piVar5 != (int *)0x0) {

        iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x124))(local_28);

        fStack_40 = (float)DAT_00d1e81c * *(float *)(iVar2 + 4) * DAT_00aaa678;

        iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(&fStack_34,1);

        local_54 = (int)fStack_3c + *(int *)(iVar2 + 4);

        goto LAB_00852d76;

      }

      goto LAB_00852d4f;

    }

    iVar2 = (**(code **)(*piVar5 + 0x124))(local_30);

    piVar5 = *(int **)(unaff_ESI + 0x504);

    fStack_40 = (float)DAT_00d1e81c * *(float *)(iVar2 + 4) * DAT_00aaa678;

    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(&fStack_3c,1);

    iVar4 = (int)fStack_48;

    iVar2 = *(int *)(iVar2 + 4);

    iVar3 = (**(code **)(*piVar5 + 0x140))(&iStack_50,1);

    if (*(int *)(iVar3 + 4) < iVar4 + iVar2) {

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x124))(&iStack_4c);

      fStack_40 = (float)DAT_00d1e81c * *(float *)(iVar2 + 4) * DAT_00aaa678;

      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x140))(auStack_58,1);

      local_54 = (int)fStack_3c + *(int *)(iVar2 + 4);

      goto LAB_00852d76;

    }

  }

  iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x504) + 0x140))(local_28,1);

  local_54 = *(int *)(iVar2 + 4);

LAB_00852d76:

  iVar2 = local_54;

  if (*(int *)(unaff_ESI + 0x510) != 0) {

    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x140))(local_28,1);

    local_54 = iVar2 + *(int *)(iVar3 + 4);

  }

  iVar2 = local_54;

  if (*(int *)(unaff_ESI + 0x508) != 0) {

    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x508) + 0x140))(local_28,1);

    local_54 = iVar2 + *(int *)(iVar3 + 4);

  }

  iVar2 = local_54;

  if (*(int *)(unaff_ESI + 0x50c) != 0) {

    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x50c) + 0x140))(local_28,1);

    local_54 = iVar2 + *(int *)(iVar3 + 4);

  }

  iVar2 = local_54;

  if (*(int *)(unaff_ESI + 0x514) != 0) {

    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x514) + 0x140))(local_28,1);

    local_54 = iVar2 + *(int *)(iVar3 + 4);

  }

  iVar2 = local_54;

  if (*(int *)(unaff_ESI + 0x518) != 0) {

    iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x140))(local_28,1);

    local_54 = iVar2 + *(int *)(iVar3 + 4);

  }

  iVar2 = 0;

  fStack_3c = 0.0;

  piVar5 = (int *)(unaff_ESI + 0x51c);

  do {

    iStack_4c = (int)fStack_3c / *(int *)(unaff_ESI + 0x568);

    if ((*piVar5 != 0) && (cVar1 = (**(code **)(*(int *)*piVar5 + 0xd0))(), cVar1 != '\0')) {

      iVar3 = (**(code **)(*(int *)*piVar5 + 0x124))(local_28);

      fStack_48 = (float)(iStack_50 + 1);

      fStack_3c = (float)DAT_00d1e81c *

                  ((float)(*(int *)(unaff_ESI + 0x564) * iStack_50) + *(float *)(iVar3 + 4)) *

                  DAT_00aaa678;

      iVar3 = (**(code **)(*(int *)*piVar5 + 0x140))(auStack_24,1);

      if (iVar2 < *(int *)(iVar3 + 4) * iStack_44 + (int)fStack_38) {

        iVar2 = (**(code **)(*(int *)*piVar5 + 0x124))(auStack_18);

        fStack_34 = (float)DAT_00d1e81c *

                    ((float)(*(int *)(unaff_ESI + 0x564) * iStack_50) + *(float *)(iVar2 + 4)) *

                    DAT_00aaa678;

        iVar2 = (**(code **)(*(int *)*piVar5 + 0x140))(auStack_14,1);

        iVar2 = *(int *)(iVar2 + 4) * iStack_44 + (int)local_30[0];

      }

    }

    fStack_3c = (float)((int)fStack_3c + 1);

    piVar5 = piVar5 + 1;

  } while ((int)fStack_3c < 4);

  return iVar2 + local_54;

}
