// =============================================================================
// FUN_00717630
// -----------------------------------------------------------------------------
// Stable ID: aa_00717630
// Address:   0x00717630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717630 @ 0x00717630
// Stable ID: aa_00717630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00717630.
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

void FUN_00717630(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  int iVar5;

  

  iVar5 = 1;

  uVar2 = (int)param_3 >> 1;

  if (1 < (int)(param_3 - 1)) {

    puVar3 = param_2;

    do {

      puVar3 = puVar3 + 1;

      uVar4 = param_3;

      if ((int)uVar2 < iVar5) {

        uVar1 = *(uint32_t /* width from decompiler */ *)((param_1 - (int)param_2) + (int)puVar3);

        *(uint32_t /* width from decompiler */ *)((param_1 - (int)param_2) + (int)puVar3) =

             *(uint32_t /* width from decompiler */ *)(param_1 + uVar2 * 4);

        *(uint32_t /* width from decompiler */ *)(param_1 + uVar2 * 4) = uVar1;

        uVar1 = *puVar3;

        *puVar3 = param_2[uVar2];

        param_2[uVar2] = uVar1;

      }

      do {

        uVar4 = (int)uVar4 >> 1;

        uVar2 = uVar2 ^ uVar4;

      } while ((int)uVar2 < (int)uVar4);

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)(param_3 - 1));

  }

  return;

}
