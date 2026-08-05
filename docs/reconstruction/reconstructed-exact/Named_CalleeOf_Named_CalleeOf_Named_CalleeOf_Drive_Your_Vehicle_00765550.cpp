// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_00765550
// -----------------------------------------------------------------------------
// Stable ID: aa_00765550
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
// Address:   0x00765550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, return×2.
//  - Notable callees: FUN_007633d0, FUN_007647c0, FUN_00765550.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_00765550(int param_1,int param_2,int param_3,char param_4,char param_5)



{

  int *piVar1;

  byte bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  

  if (*(int *)(param_1 + 0x94) == 0) {

    bVar2 = 0;

    if (param_4 != '\0') {

      piVar1 = *(int **)(param_3 + 0xc4);

      for (piVar5 = *(int **)(param_3 + 0xc0); piVar5 != piVar1; piVar5 = piVar5 + 1) {

        if (((int *)*piVar5)[0x23] == param_2) {

          bVar2 = 1;

          uVar4 = (**(code **)(*(int *)*piVar5 + 0x7c))();

          FUN_007647c0(uVar4);

        }

      }

    }

    if (param_5 != '\0') {

      piVar1 = *(int **)(param_3 + 0xd4);

      for (piVar5 = *(int **)(param_3 + 0xd0); piVar5 != piVar1; piVar5 = piVar5 + 1) {

        if (((int *)*piVar5)[0x23] == param_2) {

          bVar2 = 1;

          uVar4 = (**(code **)(*(int *)*piVar5 + 0x7c))();

          FUN_007633d0(param_1,uVar4);

        }

      }

    }

    return bVar2 - 1;

  }

                    /* WARNING: Could not recover jumptable at 0x00765565. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  iVar3 = (**(code **)(**(int **)(param_1 + 0x94) + 0x3c))();

  return iVar3;

}
