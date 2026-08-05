// =============================================================================
// FUN_004bef20
// -----------------------------------------------------------------------------
// Stable ID: aa_004bef20
// Address:   0x004bef20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bef20 @ 0x004bef20
// Stable ID: aa_004bef20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004073a0, FUN_004bef20.
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

void __thiscall FUN_004bef20(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 0x14);

  do {

    *(int *)(param_1 + 0x18) = iVar3;

    if ((iVar3 != 0) &&

       (puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + 4), *(int *)(*(int *)(iVar3 + 0xc) + 4) != 0

       )) {

      iVar3 = *(int *)(param_2 + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_2 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(param_2 + 8) - iVar3 >> 2)

         )) {

        FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,puVar1);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

        *puVar2 = *puVar1;

        *(uint32_t /* width from decompiler */ **)(param_2 + 8) = puVar2 + 1;

      }

    }

  } while ((*(int *)(param_1 + 0x18) != 0) &&

          (iVar3 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar3 != 0));

  return;

}
