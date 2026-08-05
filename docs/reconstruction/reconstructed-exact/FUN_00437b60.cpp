// =============================================================================
// FUN_00437b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00437b60
// Address:   0x00437b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00437b60 @ 0x00437b60
// Stable ID: aa_00437b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×11, return×8, for×1.
//  - Notable callees: FUN_00437b60, FUN_00439db0, FUN_0043bdb0, FUN_0044ea70.
//  - Return sites: 8.

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

int __fastcall FUN_00437b60(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  

  if (param_1 == in_EAX) {

    return param_1;

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

    uVar7 = (int)puVar1 - (int)puVar3 >> 2;

    if (uVar7 != 0) {

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

      if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(int *)(param_1 + 8) - (int)puVar6 >> 2;

      }

      if (uVar7 <= uVar5) {

        for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {

          *puVar6 = *puVar3;

          puVar6 = puVar6 + 1;

        }

        if (*(int *)(in_EAX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             *(int *)(param_1 + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2) * 4;

        return param_1;

      }

      if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(int *)(param_1 + 0xc) - (int)puVar6 >> 2;

      }

      if (uVar5 < uVar7) {

        if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar6);

        }

        cVar2 = FUN_0043bdb0();

        if (cVar2 == '\0') {

          return param_1;

        }

      }

      else {

        FUN_00439db0();

      }

      uVar4 = FUN_0044ea70(param_1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

      return param_1;

    }

  }

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return param_1;

}
