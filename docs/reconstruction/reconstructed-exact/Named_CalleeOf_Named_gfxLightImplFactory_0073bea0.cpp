// =============================================================================
// Named_CalleeOf_Named_gfxLightImplFactory_0073bea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bea0
// Callee of Named_gfxLightImplFactory
// Address:   0x0073bea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxLightImplFactory: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, while×2, return×2.
//  - Notable callees: FUN_0073bea0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxLightImplFactory
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_CalleeOf_Named_gfxLightImplFactory_0073bea0(int *param_1,byte *param_2)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  int iVar4;

  byte *pbVar5;

  byte *pbVar6;

  bool bVar7;

  

  iVar4 = 0;

  if (0 < *param_1) {

    pbVar6 = (byte *)(param_1 + 2);

    do {

      pbVar2 = pbVar6;

      pbVar5 = param_2;

      if (0xf < *(uint *)(pbVar6 + 0x14)) {

        pbVar2 = *(byte **)pbVar6;

      }

      do {

        bVar1 = *pbVar2;

        bVar7 = bVar1 < *pbVar5;

        if (bVar1 != *pbVar5) {

LAB_0073bee4:

          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

          goto LAB_0073bee9;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar2[1];

        bVar7 = bVar1 < pbVar5[1];

        if (bVar1 != pbVar5[1]) goto LAB_0073bee4;

        pbVar2 = pbVar2 + 2;

        pbVar5 = pbVar5 + 2;

      } while (bVar1 != 0);

      iVar3 = 0;

LAB_0073bee9:

      if (iVar3 == 0) {

        return iVar4;

      }

      iVar4 = iVar4 + 1;

      pbVar6 = pbVar6 + 0x2c;

    } while (iVar4 < *param_1);

  }

  return -1;

}
