// =============================================================================
// FUN_005ec6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec6e0
// Address:   0x005ec6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ec6e0 @ 0x005ec6e0
// Stable ID: aa_005ec6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_005ec6e0.
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

void __thiscall FUN_005ec6e0(int param_1,int param_2)



{

  uint uVar1;

  uint uVar2;

  

  uVar2 = 0;

  if (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2 != 0) {

    do {

      uVar1 = 0;

      if (*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2 != 0) {

        do {

          if (*(int *)(*(int *)(param_1 + 0x50) + uVar2 * 4) ==

              *(int *)(*(int *)(param_2 + 0x50) + uVar1 * 4)) {

            if ((uint)(*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2) < 2) {

              *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x50);

            }

            else {

              if (uVar1 != (*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2) - 1U) {

                *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x50) + uVar1 * 4) =

                     *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x54) + -4);

              }

              *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + -4;

            }

          }

          else {

            uVar1 = uVar1 + 1;

          }

        } while (uVar1 < (uint)(*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2));

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < (uint)(*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2));

  }

  return;

}
