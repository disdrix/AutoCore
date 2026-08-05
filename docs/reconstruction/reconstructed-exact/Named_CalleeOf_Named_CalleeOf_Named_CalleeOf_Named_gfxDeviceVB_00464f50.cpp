// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00464f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00464f50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00464f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_00438d60×2, FUN_00456160×2, FUN_00465160×2, FUN_004380f0, FUN_00462600, FUN_00464f50.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00464f50(int param_1)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  

  if (param_1 == in_EAX) {

    return param_1;

  }

  if (*(int *)(in_EAX + 4) != 0) {

    uVar5 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 3;

    if (uVar5 != 0) {

      iVar4 = *(int *)(param_1 + 4);

      if (iVar4 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 8) - iVar4 >> 3;

      }

      if (uVar5 <= uVar3) {

        FUN_00465160(*(int *)(in_EAX + 8),param_1);

        FUN_00438d60();

        if (*(int *)(in_EAX + 4) != 0) {

          *(int *)(param_1 + 8) =

               *(int *)(param_1 + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 3) * 8;

          return param_1;

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

        return param_1;

      }

      if (iVar4 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 0xc) - iVar4 >> 3;

      }

      if (uVar3 < uVar5) {

        if (iVar4 != 0) {

          FUN_00438d60();

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 4));

        }

        cVar1 = FUN_00462600();

        if (cVar1 == '\0') {

          return param_1;

        }

        uVar2 = FUN_00456160(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

        return param_1;

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - iVar4 >> 3;

      }

      FUN_00465160(*(int *)(in_EAX + 4) + iVar4 * 8,param_1);

      uVar2 = FUN_00456160(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

      return param_1;

    }

  }

  FUN_004380f0();

  return param_1;

}
