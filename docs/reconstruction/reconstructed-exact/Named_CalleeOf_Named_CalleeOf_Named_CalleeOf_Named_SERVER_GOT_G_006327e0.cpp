// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_006327e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006327e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x006327e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006327e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_G_006327e0(int *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  param_3[1] = 0;

  iVar1 = (**(code **)(*param_1 + 0x24))();

  if (0 < iVar1) {

    do {

      iVar2 = (**(code **)(*param_1 + 0x20))(iVar3);

      if (*(short *)(iVar2 + 8) == 0x13) {

        if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

          FUN_005b3370(param_3,4);

        }

        *(int *)(*param_3 + param_3[1] * 4) = iVar3;

        param_3[1] = param_3[1] + 1;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar1);

  }

  *(bool *)param_2 = 0 < param_3[1];

  return;

}
