// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Dri_005a7180
// -----------------------------------------------------------------------------
// Stable ID: aa_005a7180
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle
// Address:   0x005a7180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00581c70, FUN_005a7180.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Dri_005a7180(int param_1,int param_2,float param_3)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  

  FUN_00581c70(param_3);

  cVar3 = *(char *)(param_1 + 0xb0);

  iVar5 = 0;

  if ('\0' < cVar3) {

    do {

      if (((*(int *)(param_1 + 0xe8) != 0) && (cVar4 = (char)iVar5, -1 < cVar4)) && (cVar4 < cVar3))

      {

        piVar1 = (int *)(*(int *)(param_1 + 0xe8) + cVar4 * 0x14c);

        if (piVar1 != (int *)0x0) {

          fVar2 = param_3 * *(float *)(param_2 + 0x600 + cVar4 * 4);

          (**(code **)(*piVar1 + 0x1c))(fVar2 + fVar2);

        }

      }

      cVar3 = *(char *)(param_1 + 0xb0);

      iVar5 = iVar5 + 1;

    } while (iVar5 < cVar3);

  }

  return;

}
