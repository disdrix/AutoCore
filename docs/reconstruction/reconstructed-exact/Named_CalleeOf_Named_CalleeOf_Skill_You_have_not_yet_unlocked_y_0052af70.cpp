// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_You_have_not_yet_unlocked_y_0052af70
// -----------------------------------------------------------------------------
// Stable ID: aa_0052af70
// Callee of Named_CalleeOf_Skill_You_have_not_yet_unlocked_your_skill_in
// Address:   0x0052af70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_You_have_not_yet_unlocked_your_skill_in: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×1.
//  - Notable callees: CONCAT22×2, FUN_00418b80, FUN_0052af70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_You_have_not_yet_unlocked_your_skill_in
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Skill_You_have_not_yet_unlocked_y_0052af70(int param_1,short param_2)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *in_EAX;

  uint16_t uVar5;

  short sVar6;

  int *piVar7;

  int local_8;

  int *local_4;

  

  piVar3 = DAT_00b045b4;

  uVar5 = (uint16_t)((uint)in_EAX >> 0x10);

  piVar7 = (int *)*DAT_00b045b4;

  sVar6 = 0;

  while (piVar7 != piVar3) {

    in_EAX = (int *)CONCAT22((short)((uint)in_EAX >> 0x10),param_2);

    if ((short)piVar7[0xe] == param_2) {

      local_8 = piVar7[4];

      FUN_00418b80(&local_4,&local_8);

      in_EAX = local_4;

      if ((local_4 != *(int **)(param_1 + 0x588)) && (0 < local_4[5])) {

        sVar6 = sVar6 + 1;

      }

    }

    if (*(char *)((int)piVar7 + 0x20d) == '\0') {

      piVar2 = (int *)piVar7[2];

      if (*(char *)((int)piVar2 + 0x20d) == '\0') {

        cVar1 = *(char *)(*piVar2 + 0x20d);

        in_EAX = (int *)*piVar2;

        while (piVar7 = piVar2, cVar1 == '\0') {

          cVar1 = *(char *)(*in_EAX + 0x20d);

          piVar2 = in_EAX;

          in_EAX = (int *)*in_EAX;

        }

      }

      else {

        cVar1 = *(char *)(piVar7[1] + 0x20d);

        piVar4 = (int *)piVar7[1];

        piVar2 = piVar7;

        while ((in_EAX = piVar4, piVar7 = in_EAX, cVar1 == '\0' && (piVar2 == (int *)in_EAX[2]))) {

          cVar1 = *(char *)(in_EAX[1] + 0x20d);

          piVar4 = (int *)in_EAX[1];

          piVar2 = in_EAX;

        }

      }

    }

    uVar5 = (uint16_t)((uint)in_EAX >> 0x10);

  }

  return CONCAT22(uVar5,sVar6);

}
