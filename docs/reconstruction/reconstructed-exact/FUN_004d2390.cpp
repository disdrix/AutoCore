// =============================================================================
// FUN_004d2390
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2390
// Address:   0x004d2390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2390 @ 0x004d2390
// Stable ID: aa_004d2390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_004d2390.
//  - Return sites: 1.

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

void __fastcall FUN_004d2390(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x144);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x148)) {

    do {

      piVar1 = (int *)*puVar3;

      iVar2 = (**(code **)(*piVar1 + 0x20))();

      if ((iVar2 != 0) && ((**(code **)(*piVar1 + 0x78))(), *(char *)(param_1 + 0x7d) != '\0')) {

        (**(code **)(*piVar1 + 0x84))();

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x148));

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x144);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x148)) {

    do {

      piVar1 = (int *)*puVar3;

      iVar2 = (**(code **)(*piVar1 + 0x20))();

      if ((iVar2 == 0) && ((**(code **)(*piVar1 + 0x78))(), *(char *)(param_1 + 0x7d) != '\0')) {

        (**(code **)(*piVar1 + 0x84))();

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x148));

  }

  return;

}
