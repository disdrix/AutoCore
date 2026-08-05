// =============================================================================
// Named_CalleeOf_Skill_Skill_Points_0083f160
// -----------------------------------------------------------------------------
// Stable ID: aa_0083f160
// Callee of Skill_Skill_Points
// Address:   0x0083f160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_Points: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_00552950, FUN_0083eff0, FUN_0083f160.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_Points
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

void Named_CalleeOf_Skill_Skill_Points_0083f160(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char local_a08 [512];

  uint16_t local_808;

  uint32_t /* width from decompiler */ local_806 [512];

  

  if ((param_3 != (char *)0x0) && (in_EAX != (int *)0x0)) {

    local_808 = 0;

    puVar4 = local_806;

    for (iVar3 = 0x1ff; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    iVar2 = 0;

    iVar3 = 0;

    if (*param_3 != '\0') {

      do {

        if ((param_3[iVar3] == '[') && (param_3[iVar3 + 1] == '$')) {

          if (0 < iVar2) {

            if (0x7ff < iVar2) {

              iVar2 = 0x7ff;

            }

            *(uint8_t *)((int)local_806 + iVar2 + -2) = 0;

            (**(code **)(*in_EAX + 0x250))(&local_808);

          }

          cVar1 = param_3[iVar3 + 2];

          iVar3 = iVar3 + 2;

          for (iVar2 = 0; ((cVar1 != '\0' && (cVar1 != ']')) && (iVar2 < 0x1fe)); iVar2 = iVar2 + 1)

          {

            iVar3 = iVar3 + 1;

            local_a08[iVar2] = cVar1;

            cVar1 = param_3[iVar3];

          }

          cVar1 = param_3[iVar3];

          local_a08[iVar2] = '\0';

          if ((cVar1 == '\0') || (0x1fe < iVar2)) goto LAB_0083f2c2;

          iVar3 = iVar3 + 1;

          local_808 = local_808 & 0xff00;

          cVar1 = FUN_0083eff0();

          if ((cVar1 == '\0') && (iVar2 = FUN_00552950(local_a08,&local_808), iVar2 != 0)) {

            (**(code **)(*in_EAX + 0x224))(&local_808,0xff22ccff);

          }

          iVar2 = 0;

          local_808 = local_808 & 0xff00;

        }

        else if (iVar2 < 0x7fe) {

          *(char *)((int)local_806 + iVar2 + -2) = param_3[iVar3];

          iVar2 = iVar2 + 1;

          iVar3 = iVar3 + 1;

        }

      } while (param_3[iVar3] != '\0');

      if (0 < iVar2) {

        if (0x7ff < iVar2) {

          iVar2 = 0x7ff;

        }

        *(uint8_t *)((int)local_806 + iVar2 + -2) = 0;

LAB_0083f2c2:

        (**(code **)(*in_EAX + 0x250))(&local_808);

      }

    }

  }

  return;

}
