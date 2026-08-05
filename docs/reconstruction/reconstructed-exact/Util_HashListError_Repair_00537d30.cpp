// =============================================================================
// Util_HashListError_Repair_00537d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00537d30
// Address:   0x00537d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Util_HashListError_Repair_00537d30 @ 0x00537d30
// Stable ID: aa_00537d30
// Embedded strings (evidence for future rename):
//   - "HashListError: Went to node we already touched! Attempting repair!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×2, while×2, for×1.
//  - Notable callees: Util_HashListError_Repair_00537d30, FUN_007a4480.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "HashListError: Went to node we already touched! Attempting repair!"
 * Domain alias of FUN_00537d30 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Util_HashListError_Repair_00537d30(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  if (*(int *)(param_1 + 4) != 0) {

    do {

      iVar1 = iVar2;

      *(uint8_t *)(iVar1 + 4) = 1;

      iVar2 = *(int *)(iVar1 + 0xc);

      if (iVar2 == 0) {

        for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {

          *(uint8_t *)(iVar2 + 4) = 0;

        }

        return;

      }

    } while (*(char *)(iVar2 + 4) == '\0');

    FUN_007a4480(1,"HashListError: Went to node we already touched! Attempting repair!");

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

    iVar2 = *(int *)(param_1 + 4);

    if (iVar2 != 0) {

      do {

        *(uint8_t *)(iVar2 + 4) = 0;

        iVar2 = *(int *)(iVar2 + 0xc);

      } while (iVar2 != 0);

      return;

    }

  }

  return;

}
