// =============================================================================
// FUN_004b67d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b67d0
// Address:   0x004b67d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b67d0 @ 0x004b67d0
// Stable ID: aa_004b67d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: FUN_004b67d0.
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

void __thiscall FUN_004b67d0(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = param_4[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = param_4[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = param_4[3];

  if (*(void **)(param_1 + 0x3c) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    if (param_3 != 0) {

      *(int *)(param_1 + 0x40) = param_3;

      puVar1 = operator_new__(param_3 << 5);

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) = puVar1;

      for (uVar2 = (uint)(param_3 << 5) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar1 = *param_2;

        param_2 = param_2 + 1;

        puVar1 = puVar1 + 1;

      }

      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

        *(uint8_t *)puVar1 = *(uint8_t *)param_2;

        param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

        puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

      }

    }

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x3c));

}
