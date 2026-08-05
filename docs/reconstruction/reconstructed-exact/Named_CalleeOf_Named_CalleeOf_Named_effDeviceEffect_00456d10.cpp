// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00456d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00456d10
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00456d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×10, return×7.
//  - Notable callees: FUN_00447ce0×2, FUN_0044ea70×2, FUN_0043bdb0, FUN_00456d10.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00456d10(int param_1)



{

  void *pvVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_1 != in_EAX) {

    if ((*(int *)(in_EAX + 4) == 0) ||

       (uVar4 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2, uVar4 == 0)) {

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      return param_1;

    }

    pvVar1 = *(void **)(param_1 + 4);

    if (pvVar1 == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

    }

    if (uVar4 <= uVar5) {

      FUN_00447ce0();

      if (*(int *)(in_EAX + 4) == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

        return param_1;

      }

      *(int *)(param_1 + 8) =

           *(int *)(param_1 + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2) * 4;

      return param_1;

    }

    if (pvVar1 == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = *(int *)(param_1 + 0xc) - (int)pvVar1 >> 2;

    }

    if (uVar4 <= uVar5) {

      FUN_00447ce0();

      uVar3 = FUN_0044ea70(param_1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

      return param_1;

    }

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    cVar2 = FUN_0043bdb0();

    if (cVar2 != '\0') {

      uVar3 = FUN_0044ea70(param_1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    }

  }

  return param_1;

}
