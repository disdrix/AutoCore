// =============================================================================
// FUN_0079c260
// -----------------------------------------------------------------------------
// Stable ID: aa_0079c260
// Address:   0x0079c260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079c260 @ 0x0079c260
// Stable ID: aa_0079c260
// Embedded strings (evidence for future rename):
//   - "_over"
//   - "_on_over"
//   - "_on_down"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×2.
//  - Notable callees: FUN_0079bf80×6, FUN_0079c260.
//  - Strings: "_over"; "_on_over"; "_on_down".
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

void __thiscall FUN_0079c260(int param_1,char *param_2)



{

  char cVar1;

  uint8_t uVar2;

  char *pcVar3;

  

  if (*(void **)(param_1 + 0x4c8) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x4c8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c8) = 0;

  if (param_2 != (char *)0x0) {

    pcVar3 = param_2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    if ((int)pcVar3 - (int)(param_2 + 1) != 0) {

      pcVar3 = operator_new__(((int)pcVar3 - (int)(param_2 + 1)) + 1);

      *(char **)(param_1 + 0x4c8) = pcVar3;

      do {

        cVar1 = *param_2;

        *pcVar3 = cVar1;

        param_2 = param_2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar2 = FUN_0079bf80(&DAT_00a98034);

      *(uint8_t *)(param_1 + 0x491) = uVar2;

      uVar2 = FUN_0079bf80("_over");

      *(uint8_t *)(param_1 + 0x492) = uVar2;

      uVar2 = FUN_0079bf80(&DAT_00a98024);

      *(uint8_t *)(param_1 + 0x493) = uVar2;

      uVar2 = FUN_0079bf80(&DAT_00a98020);

      *(uint8_t *)(param_1 + 0x494) = uVar2;

      uVar2 = FUN_0079bf80("_on_over");

      *(uint8_t *)(param_1 + 0x495) = uVar2;

      uVar2 = FUN_0079bf80("_on_down");

      *(uint8_t *)(param_1 + 0x496) = uVar2;

      return;

    }

  }

  *(uint8_t *)(param_1 + 0x491) = 0;

  *(uint8_t *)(param_1 + 0x494) = 0;

  *(uint8_t *)(param_1 + 0x495) = 0;

  *(uint8_t *)(param_1 + 0x492) = 0;

  *(uint8_t *)(param_1 + 0x493) = 0;

  return;

}
