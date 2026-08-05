// =============================================================================
// FUN_007a6890
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6890
// Address:   0x007a6890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a6890 @ 0x007a6890
// Stable ID: aa_007a6890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: do×3, if×3, while×3, return×1.
//  - Notable callees: FUN_007a6890.
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

void __fastcall FUN_007a6890(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int local_4;

  

  *param_1 = &PTR_FUN_00a96f88;

  iVar4 = 10;

  puVar2 = param_1;

  do {

    puVar2 = puVar2 + 1;

    if ((void *)*puVar2 != (void *)0x0) {

      operator_delete__((void *)*puVar2);

    }

    *puVar2 = 0;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  puVar2 = param_1 + 0xc;

  piVar1 = param_1 + 0x16;

  local_4 = 5;

  do {

    iVar4 = 0;

    puVar3 = puVar2;

    if (0 < *piVar1) {

      do {

        if ((void *)*puVar3 != (void *)0x0) {

          operator_delete__((void *)*puVar3);

        }

        *puVar3 = 0;

        iVar4 = iVar4 + 1;

        puVar3 = puVar3 + 1;

      } while (iVar4 < *piVar1);

    }

    piVar1 = piVar1 + 1;

    puVar2 = puVar2 + 2;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return;

}
