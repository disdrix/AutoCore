// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics_007b6450
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6450
// Callee of Named_CalleeOf_CVOGCreature_SetupGraphics
// Address:   0x007b6450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×7, do×7, while×7, return×4, for×4.
//  - Notable callees: PathFileExistsA×3, FUN_007b6420, FUN_007b6450.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCreature_SetupGraphics
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

bool __fastcall Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics_007b6450(int param_1,LPCSTR param_2)



{

  char cVar1;

  int in_EAX;

  BOOL BVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  uint uVar8;

  char *pcVar9;

  char local_104 [260];

  

  if ((*(byte *)(in_EAX + 4) & 1) != 0) {

    if (((param_1 == -2) || (param_1 == -1)) && (BVar2 = PathFileExistsA(param_2), BVar2 != 0)) {

      return true;

    }

    if (param_1 != -2) {

      pcVar3 = (char *)FUN_007b6420();

      if ((-1 < param_1) && (param_1 < 0x14)) {

        if ((uint)(&DAT_00d1e588)[param_1 * 7] < 0x10) {

          pcVar7 = (char *)(&DAT_00d1e574 + param_1 * 7);

        }

        else {

          pcVar7 = (char *)(&DAT_00d1e574)[param_1 * 7];

        }

        pcVar9 = local_104;

        do {

          cVar1 = *pcVar7;

          *pcVar9 = cVar1;

          pcVar7 = pcVar7 + 1;

          pcVar9 = pcVar9 + 1;

          pcVar4 = pcVar3;

        } while (cVar1 != '\0');

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        uVar5 = (int)pcVar4 - (int)pcVar3;

        pcVar7 = &stack0xfffffefb;

        do {

          pcVar9 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar9 != '\0');

        for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar3;

          pcVar3 = pcVar3 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar7 = *pcVar3;

          pcVar3 = pcVar3 + 1;

          pcVar7 = pcVar7 + 1;

        }

        BVar2 = PathFileExistsA(local_104);

        return BVar2 != 0;

      }

      pcVar7 = (char *)&DAT_00d1e574;

      do {

        pcVar9 = pcVar7;

        if (0xf < *(uint *)(pcVar7 + 0x14)) {

          pcVar9 = *(char **)pcVar7;

        }

        pcVar4 = local_104;

        do {

          cVar1 = *pcVar9;

          *pcVar4 = cVar1;

          pcVar9 = pcVar9 + 1;

          pcVar4 = pcVar4 + 1;

          pcVar6 = pcVar3;

        } while (cVar1 != '\0');

        do {

          cVar1 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar1 != '\0');

        uVar5 = (int)pcVar6 - (int)pcVar3;

        pcVar9 = &stack0xfffffefb;

        do {

          pcVar4 = pcVar9 + 1;

          pcVar9 = pcVar9 + 1;

        } while (*pcVar4 != '\0');

        pcVar4 = pcVar3;

        for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar4;

          pcVar4 = pcVar4 + 4;

          pcVar9 = pcVar9 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar9 = *pcVar4;

          pcVar4 = pcVar4 + 1;

          pcVar9 = pcVar9 + 1;

        }

        BVar2 = PathFileExistsA(local_104);

        if (BVar2 != 0) {

          return true;

        }

        pcVar7 = pcVar7 + 0x1c;

      } while ((int)pcVar7 < 0xd1e7a4);

    }

  }

  return false;

}
