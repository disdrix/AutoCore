// =============================================================================
// FUN_00606790
// -----------------------------------------------------------------------------
// Stable ID: aa_00606790
// Address:   0x00606790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00606790 @ 0x00606790
// Stable ID: aa_00606790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_00606790.
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

void __fastcall FUN_00606790(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  

  if ((-1 < *(int *)(param_1 + 0x234)) && (*(int *)(param_1 + 0x234) < 4)) {

    uVar4 = 0;

    while( true ) {

      iVar2 = *(int *)(param_1 + 0xc4 + *(int *)(param_1 + 0x234) * 0x48);

      if ((iVar2 == 0) ||

         ((uint)(*(int *)(param_1 + *(int *)(param_1 + 0x234) * 0x48 + 200) - iVar2 >> 3) <= uVar4))

      break;

      puVar3 = operator_new(0x10);

      *puVar3 = 0x20b7;

      *(uint8_t *)(puVar3 + 1) = 1;

      puVar1 = (uint32_t /* width from decompiler */ *)

               (*(int *)(param_1 + 0xc4 + *(int *)(param_1 + 0x234) * 0x48) + uVar4 * 8);

      puVar3[2] = *puVar1;

      puVar3[3] = puVar1[1];

      uVar4 = uVar4 + 1;

    }

  }

  return;

}
