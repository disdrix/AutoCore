// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_is_prime_00773470
// -----------------------------------------------------------------------------
// Stable ID: aa_00773470
// Callee of Named_CalleeOf_Named_CalleeOf_Named_is_prime
// Address:   0x00773470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_is_prime: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×12, return×6, while×1.
//  - Notable callees: FUN_007703d0, FUN_00770540, FUN_007705f0, FUN_00770650, FUN_007707d0, FUN_00770820, FUN_00771f00, FUN_00772050.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_is_prime
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_is_prime_00773470(int *param_1,uint param_2,int param_3,uint *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  bool bVar5;

  uint64_t uVar6;

  int local_14;

  int local_10;

  int local_8;

  int local_4;

  

  if (param_2 == 0) {

    return -3;

  }

  if ((param_2 == 1) || (*param_1 == 0)) {

    if (param_4 != (uint *)0x0) {

      *param_4 = 0;

    }

    if (param_3 != 0) {

      iVar1 = FUN_00770650();

      return iVar1;

    }

  }

  else {

    iVar1 = FUN_007705f0(&local_14);

    if (iVar1 == 1) {

      if (param_4 != (uint *)0x0) {

        *param_4 = (1 << ((byte)local_14 & 0x1f)) - 1U & *(uint *)param_1[3];

      }

      if (param_3 != 0) {

        iVar1 = FUN_00772050(local_14,param_3,0);

        return iVar1;

      }

    }

    else {

      if (param_2 == 3) {

        iVar1 = FUN_00771f00(param_1,param_3,param_4);

        return iVar1;

      }

      iVar1 = FUN_007703d0();

      if (iVar1 != 0) {

        return iVar1;

      }

      local_10 = *param_1;

      local_8 = param_1[2];

      uVar4 = 0;

      iVar1 = 0;

      local_14 = local_10;

      while (local_14 = local_14 + -1, -1 < local_14) {

        uVar3 = iVar1 << 0x1c | uVar4 >> 4;

        uVar4 = *(uint *)(param_1[3] + local_14 * 4) | uVar4 << 0x1c;

        if ((uVar3 == 0) && (uVar4 < param_2)) {

          uVar2 = 0;

          iVar1 = 0;

        }

        else {

          uVar2 = __aulldiv(uVar4,uVar3,param_2,0);

          uVar6 = __allmul(uVar2,0,param_2,0);

          bVar5 = uVar4 < (uint)uVar6;

          uVar4 = uVar4 - (uint)uVar6;

          iVar1 = (uVar3 - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;

        }

        *(uint32_t /* width from decompiler */ *)(local_4 + local_14 * 4) = uVar2;

      }

      if (param_4 != (uint *)0x0) {

        *param_4 = uVar4;

      }

      if (param_3 != 0) {

        FUN_00770820();

        FUN_00770540();

      }

      FUN_007707d0();

    }

  }

  return 0;

}
