// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_004b6fc0, FUN_00720670, FUN_00720d40, FUN_007a4480.
//  - Strings: "Requesting play %s\n".
//  - Return sites: 1.

// =============================================================================
// Mission_Requesting_play_s_004b6fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6fc0
// Address:   0x004b6fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Requesting play %s
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_Requesting_play_s_004b6fc0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ auStack_dc [46];

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  char *pcStack_1c;

  uint32_t /* width from decompiler */ *puStack_18;

  

  if ((*(int *)(param_1 + 0x1fc) != 0) &&

     (piVar3 = (int *)**(int **)(param_1 + 0x1f8), piVar3 != *(int **)(param_1 + 0x1f8))) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)piVar3[2];

      puVar4 = puVar1;

      puVar5 = auStack_dc;

      for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      FUN_00720d40();

      FUN_00720670();

      pcStack_1c = "Requesting play %s\n";

      uStack_20 = 0xffffffff;

      uStack_24 = 0x4b700d;

      puStack_18 = puVar1;

      FUN_007a4480();

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0x1f8));

  }

  return;

}
