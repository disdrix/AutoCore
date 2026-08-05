// =============================================================================
// FUN_004315c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004315c0
// Address:   0x004315c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004315c0 @ 0x004315c0
// Stable ID: aa_004315c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×9, return×6.
//  - Notable callees: FUN_00426f20×2, FUN_00431520×2, FUN_00431550, FUN_004315c0, FUN_00431980, FUN_00465cc0, FUN_0046a860.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall FUN_004315c0(int param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_1 != in_EAX) {

    if ((*(int *)(in_EAX + 4) == 0) ||

       (uVar5 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 4, uVar5 == 0)) {

      FUN_0046a860();

      return param_1;

    }

    iVar1 = *(int *)(param_1 + 4);

    if (iVar1 == 0) {

      uVar4 = 0;

    }

    else {

      uVar4 = *(int *)(param_1 + 8) - iVar1 >> 4;

    }

    if (uVar5 <= uVar4) {

      FUN_00431520();

      FUN_00426f20(param_1);

      if (*(int *)(in_EAX + 4) == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

        return param_1;

      }

      *(int *)(param_1 + 8) =

           (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 4) * 0x10 + *(int *)(param_1 + 4);

      return param_1;

    }

    if (iVar1 == 0) {

      uVar4 = 0;

    }

    else {

      uVar4 = *(int *)(param_1 + 0xc) - iVar1 >> 4;

    }

    if (uVar5 <= uVar4) {

      FUN_00431520();

      uVar3 = FUN_00431980(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,param_1)

      ;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

      return param_1;

    }

    if (iVar1 != 0) {

      FUN_00426f20(param_1);

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    cVar2 = FUN_00465cc0();

    if (cVar2 != '\0') {

      uVar3 = FUN_00431550(*(uint32_t /* width from decompiler */ *)(in_EAX + 4),*(uint32_t /* width from decompiler */ *)(in_EAX + 8));

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    }

  }

  return param_1;

}
