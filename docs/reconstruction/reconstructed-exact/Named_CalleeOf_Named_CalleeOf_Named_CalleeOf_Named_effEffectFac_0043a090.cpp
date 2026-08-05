// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effEffectFac_0043a090
// -----------------------------------------------------------------------------
// Stable ID: aa_0043a090
// Callee of Named_CalleeOf_Named_CalleeOf_Named_effEffectFactory
// Address:   0x0043a090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_effEffectFactory: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×11, return×9.
//  - Notable callees: FUN_0040c7c0×2, FUN_00439dd0, FUN_0043a090, FUN_0043bdb0, memmove.
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_effEffectFactory
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effEffectFac_0043a090(int param_1)



{

  void *_Src;

  void *_Dst;

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  

  if (param_1 == in_EAX) {

    return param_1;

  }

  _Src = *(void **)(in_EAX + 4);

  if (_Src != (void *)0x0) {

    uVar4 = *(int *)(in_EAX + 8) - (int)_Src >> 2;

    if (uVar4 != 0) {

      _Dst = *(void **)(param_1 + 4);

      if (_Dst == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 8) - (int)_Dst >> 2;

      }

      if (uVar4 <= uVar3) {

        memmove(_Dst,_Src,(*(int *)(in_EAX + 8) - (int)_Src >> 2) * 4);

        if (*(int *)(in_EAX + 4) != 0) {

          *(int *)(param_1 + 8) =

               *(int *)(param_1 + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2) * 4;

          return param_1;

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

        return param_1;

      }

      if (_Dst == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 0xc) - (int)_Dst >> 2;

      }

      if (uVar3 < uVar4) {

        if (_Dst != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(_Dst);

        }

        cVar1 = FUN_0043bdb0();

        if (cVar1 == '\0') {

          return param_1;

        }

        uVar2 = FUN_0040c7c0(*(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

        return param_1;

      }

      FUN_00439dd0(_Dst);

      uVar2 = FUN_0040c7c0(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

      return param_1;

    }

  }

  if (*(void **)(param_1 + 4) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    return param_1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
