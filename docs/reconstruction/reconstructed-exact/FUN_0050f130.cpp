// =============================================================================
// FUN_0050f130
// -----------------------------------------------------------------------------
// Stable ID: aa_0050f130
// Address:   0x0050f130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0050f130 @ 0x0050f130
// Stable ID: aa_0050f130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_0050f130, rand.
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

void FUN_0050f130(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  uint uVar9;

  

  uVar9 = 2;

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  do {

    if (puVar5 == param_2) {

      return;

    }

    uVar8 = 0x7fff;

    uVar6 = rand();

    uVar6 = uVar6 & 0x7fff;

    if (0x7fff < uVar9) {

      do {

        if (uVar8 == 0xffffffff) break;

        uVar8 = uVar8 << 0xf | 0x7fff;

        uVar6 = uVar6 << 0xf | 0x7fff;

      } while (uVar8 < uVar9);

    }

    uVar6 = uVar6 % uVar9;

    uVar1 = *puVar5;

    uVar2 = puVar5[1];

    uVar3 = puVar5[2];

    uVar4 = puVar5[3];

    uVar9 = uVar9 + 1;

    puVar7 = (uint32_t /* width from decompiler */ *)(uVar6 * 0x10 + param_1);

    *puVar5 = *puVar7;

    puVar5[1] = puVar7[1];

    puVar5[2] = puVar7[2];

    puVar5[3] = puVar7[3];

    *puVar7 = uVar1;

    puVar7[1] = uVar2;

    puVar7[2] = uVar3;

    puVar7[3] = uVar4;

    puVar5 = puVar5 + 4;

  } while( true );

}
