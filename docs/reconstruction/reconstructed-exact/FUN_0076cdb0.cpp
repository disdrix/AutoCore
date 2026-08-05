// =============================================================================
// FUN_0076cdb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cdb0
// Address:   0x0076cdb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076cdb0 @ 0x0076cdb0
// Stable ID: aa_0076cdb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00456960, FUN_0076c500, FUN_0076cdb0.
//  - Return sites: 2.

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

uint8_t * __thiscall FUN_0076cdb0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint8_t *puVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acdab;

  local_c = ExceptionList;

  piVar3 = *(int **)(param_1 + 0x40);

  while( true ) {

    if (piVar3 == *(int **)(param_1 + 0x44)) {

      ExceptionList = &local_c;

      puVar4 = operator_new(0x80);

      if (puVar4 == (uint8_t *)0x0) {

        puVar4 = (uint8_t *)0x0;

      }

      else {

        *puVar4 = 0;

        *(int *)(puVar4 + 4) = param_2;

        FUN_0076c500(1000000);

        *(int *)(puVar4 + 0x38) = param_1;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x44) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x48) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x4c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x50) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x54) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x58) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x5c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x60) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 100) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x68) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x6c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x70) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x74) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar4 + 0x78) = 0;

      }

      local_4 = 0xffffffff;

      iVar1 = *(int *)(param_1 + 0x40);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(param_1 + 0x48) - iVar1 >> 2) <=

          (uint)(*(int *)(param_1 + 0x44) - iVar1 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x44));

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x44);

        *puVar2 = puVar4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x44) = puVar2 + 1;

      }

      ExceptionList = local_c;

      return puVar4;

    }

    if (*(int *)(*piVar3 + 4) == param_2) break;

    piVar3 = piVar3 + 1;

  }

  return (uint8_t *)*piVar3;

}
