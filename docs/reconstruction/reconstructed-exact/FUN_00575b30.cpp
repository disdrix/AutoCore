// =============================================================================
// FUN_00575b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00575b30
// Address:   0x00575b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00575b30 @ 0x00575b30
// Stable ID: aa_00575b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00575b30, rand.
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

void FUN_00575b30(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  

  uVar6 = 2;

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

  do {

    if (puVar4 == param_2) {

      return;

    }

    uVar7 = 0x7fff;

    uVar5 = rand();

    uVar5 = uVar5 & 0x7fff;

    if (0x7fff < uVar6) {

      do {

        if (uVar7 == 0xffffffff) break;

        uVar7 = uVar7 << 0xf | 0x7fff;

        uVar5 = uVar5 << 0xf | 0x7fff;

      } while (uVar7 < uVar6);

    }

    uVar5 = uVar5 % uVar6;

    uVar2 = *puVar4;

    *puVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + uVar5 * 8);

    uVar6 = uVar6 + 1;

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + uVar5 * 8);

    uVar3 = puVar4[1];

    puVar4[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + uVar5 * 8);

    *puVar1 = uVar2;

    puVar1[1] = uVar3;

    puVar4 = puVar4 + 2;

  } while( true );

}
