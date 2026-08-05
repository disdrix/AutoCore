// =============================================================================
// FUN_00495130
// -----------------------------------------------------------------------------
// Stable ID: aa_00495130
// Address:   0x00495130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00495130 @ 0x00495130
// Stable ID: aa_00495130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00494700, FUN_00495130, FUN_004bdf80, FUN_004beb10.
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

void __thiscall FUN_00495130(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint uVar1;

  uint uVar2;

  

  FUN_00494700(param_2);

  uVar2 = *(uint *)(param_1 + 100);

  if (uVar2 < *(uint *)(param_1 + 0x6c)) {

    do {

      uVar1 = *(uint *)(param_1 + 0x68);

      if (uVar1 < *(uint *)(param_1 + 0x70)) {

        do {

          if (*(int *)(*(int *)(param_1 + 0x28) + (*(int *)(param_1 + 4) * uVar1 + uVar2) * 0x28 +

                      0x24) != 0) {

            FUN_004bdf80(0x41200000);

            FUN_004beb10(99999);

          }

          *param_3 = *param_3 + 1;

          uVar1 = uVar1 + 1;

        } while (uVar1 < *(uint *)(param_1 + 0x70));

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < *(uint *)(param_1 + 0x6c));

  }

  return;

}
