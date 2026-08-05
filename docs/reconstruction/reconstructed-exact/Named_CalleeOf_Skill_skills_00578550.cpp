// =============================================================================
// Named_CalleeOf_Skill_skills_00578550
// -----------------------------------------------------------------------------
// Stable ID: aa_00578550
// Callee of Skill_skills
// Address:   0x00578550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_skills: skill/cast helper. Evidence string: "Remaining". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Remaining"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, for×2, return×1.
//  - Notable callees: FUN_007a6de0×8, FUN_00412c60×2, CVOGHBBase_GetRemainingSeconds, FUN_00578140, FUN_00578550, FUN_007a69d0, sprintf.
//  - Strings: "Remaining"; "%.0f %s %s\n"; "%g %s %s\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_skills
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint8_t __thiscall

Named_CalleeOf_Skill_skills_00578550(CVOGHBBase *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,char param_5)



{

  char cVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  float10 fVar8;

  float fVar9;

  char *pcVar10;

  double dVar11;

  char local_400 [1024];

  

  FUN_007a69d0();

  uVar2 = 0;

  if ((param_5 != '\0') && (param_1->nPeriodCounter != -1000)) {

    fVar9 = CVOGHBBase_GetRemainingSeconds(param_1);

    if (fVar9 <= _DAT_009d3fd0) {

      if (fVar9 <= _DAT_00aaaba4) {

        if (fVar9 <= DAT_00aaa9f0) {

          uVar3 = FUN_007a6de0("Remaining",0xffffffff);

          uVar4 = FUN_007a6de0();

          dVar11 = (double)fVar9;

          pcVar10 = "%.0f %s %s\n";

        }

        else {

          uVar3 = FUN_007a6de0("Remaining",0xffffffff);

          uVar4 = FUN_007a6de0();

          fVar8 = (float10)FUN_00412c60();

          dVar11 = (double)fVar8;

          pcVar10 = "%g %s %s\n";

        }

      }

      else {

        uVar3 = FUN_007a6de0("Remaining",0xffffffff);

        uVar4 = FUN_007a6de0();

        fVar8 = (float10)FUN_00412c60();

        dVar11 = (double)fVar8;

        pcVar10 = "%g %s %s\n";

      }

    }

    else {

      uVar3 = FUN_007a6de0("Remaining",0xffffffff);

      uVar4 = FUN_007a6de0();

      fVar8 = (float10)FUN_00578140();

      dVar11 = (double)fVar8;

      pcVar10 = "%g %s %s\n";

    }

    sprintf(local_400,pcVar10,dVar11,uVar4,uVar3);

    pcVar10 = local_400;

    do {

      cVar1 = *pcVar10;

      pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

    uVar5 = (int)pcVar10 - (int)local_400;

    pcVar10 = (char *)(param_2 + -1);

    do {

      pcVar7 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = local_400;

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar10 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar10 = pcVar10 + 1;

    }

    uVar2 = 1;

  }

  return uVar2;

}
