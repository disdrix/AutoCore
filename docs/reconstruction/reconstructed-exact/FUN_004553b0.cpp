// =============================================================================
// FUN_004553b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004553b0
// Address:   0x004553b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004553b0 @ 0x004553b0
// Stable ID: aa_004553b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_004553b0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_004553b0(uint32_t /* width from decompiler */ *param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  byte *pbVar6;

  byte *pbVar7;

  bool bVar8;

  bool bVar9;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {

    puVar1 = puVar2;

    puVar4 = (uint32_t /* width from decompiler */ *)puVar2[1];

    do {

      puVar2 = puVar4;

      iVar3 = 0xc;

      bVar8 = false;

      iVar5 = 0;

      bVar9 = true;

      pbVar6 = (byte *)puVar2[3];

      pbVar7 = (byte *)*param_1;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar8 = *pbVar6 < *pbVar7;

        bVar9 = *pbVar6 == *pbVar7;

        pbVar6 = pbVar6 + 1;

        pbVar7 = pbVar7 + 1;

      } while (bVar9);

      if (!bVar9) {

        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

      }

      if (iVar5 < 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)puVar2[2];

        puVar2 = puVar1;

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)*puVar2;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar4 + 0x15) == '\0');

  }

  return puVar2;

}
