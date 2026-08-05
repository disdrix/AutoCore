// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoL_0055fe50
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fe50
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoLogic
// Address:   0x0055fe50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoLogic: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0055eb80, FUN_0055efd0, FUN_0055fe50, FUN_006292a0, FUN_0062a3d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoLogic
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoL_0055fe50(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int unaff_EBX;

  int iVar3;

  int iVar4;

  uint8_t *local_1c;

  int local_18;

  uint32_t /* width from decompiler */ local_14;

  uint8_t local_10 [16];

  

  local_1c = local_10;

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;

  iVar3 = 0;

  local_18 = 0;

  local_14 = 0x80000004;

  (**(code **)(*param_2 + 0x18))(&local_1c);

  param_2[3] = param_1;

  iVar4 = 0;

  if (0 < (int)local_1c) {

    do {

      iVar1 = *(int *)(unaff_EBX + iVar4 * 4);

      iVar2 = *(int *)(iVar1 + 0x44);

      if (*(int *)(iVar2 + 0x24) != -1) {

        if (iVar3 == 0) {

          FUN_006292a0(param_2);

          iVar3 = iVar1;

          if (*(char *)(iVar2 + 0x29) == '\0') {

            FUN_0055eb80(iVar2);

          }

        }

        else if (*(int *)(iVar3 + 0x44) != iVar2) {

          FUN_0055efd0(iVar3,iVar1);

        }

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < (int)local_1c);

  }

  FUN_0062a3d0(param_1,param_2);

  if (-1 < local_18) {

    (**(code **)(*DAT_00b05060 + 0x14))(unaff_EBX,local_18 * 4,0x12);

  }

  return param_2;

}
