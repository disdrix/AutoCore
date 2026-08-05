// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceIB_00988c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00988c70
// Callee of Named_CalleeOf_Named_gfxDeviceIB
// Address:   0x00988c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceIB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×2.
//  - Notable callees: FUN_0044b8b0, FUN_00988c70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceIB
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceIB_00988c70(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int unaff_EBX;

  int *unaff_EBP;

  int unaff_EDI;

  int *piVar6;

  int local_4;

  

  piVar1 = *(int **)(unaff_EBX + 0x10);

  if (piVar1 != (int *)0x0) {

    if (param_2 < 1) {

      param_2 = *(int *)(unaff_EBX + 0x1c);

    }

    local_4 = param_2;

    if (param_2 < 1) {

      local_4 = *(int *)(unaff_EBX + 0x1c);

    }

    piVar2 = (int *)*piVar1;

    if (piVar2 != (int *)0x0) {

      piVar6 = &local_4;

      iVar3 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar1[4] * *(int *)(unaff_EBX + 0x18),piVar1[4] * local_4,piVar6,

                         0x800);

      if (-1 < iVar3) {

        piVar1[3] = piVar1[3] + 1;

        if (piVar6 != (int *)0x0) {

          uVar4 = *(int *)(unaff_EBX + 0x14) * unaff_EDI;

          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

            *piVar6 = *unaff_EBP;

            unaff_EBP = unaff_EBP + 1;

            piVar6 = piVar6 + 1;

          }

          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

            *(char *)piVar6 = (char)*unaff_EBP;

            unaff_EBP = (int *)((int)unaff_EBP + 1);

            piVar6 = (int *)((int)piVar6 + 1);

          }

          FUN_0044b8b0();

          return 0;

        }

      }

    }

  }

  return 0xffffffff;

}
