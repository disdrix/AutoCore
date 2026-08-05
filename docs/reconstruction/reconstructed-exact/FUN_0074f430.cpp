// =============================================================================
// FUN_0074f430
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f430
// Address:   0x0074f430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074f430 @ 0x0074f430
// Stable ID: aa_0074f430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, while×2, return×2.
//  - Notable callees: FUN_0074f430.
//  - Return sites: 2.

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

int FUN_0074f430(byte *param_1)



{

  byte bVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  byte *pbVar3;

  int iVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  bool bVar8;

  

  if (*(int *)(in_EAX + 0x30) == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = (*(int *)(in_EAX + 0x34) - *(int *)(in_EAX + 0x30)) / 0xd4;

  }

  iVar5 = 0;

  if (0 < iVar7) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x30);

    do {

      pbVar3 = (byte *)*puVar2;

      pbVar6 = param_1;

      do {

        bVar1 = *pbVar3;

        bVar8 = bVar1 < *pbVar6;

        if (bVar1 != *pbVar6) {

LAB_0074f48a:

          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

          goto LAB_0074f48f;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar3[1];

        bVar8 = bVar1 < pbVar6[1];

        if (bVar1 != pbVar6[1]) goto LAB_0074f48a;

        pbVar3 = pbVar3 + 2;

        pbVar6 = pbVar6 + 2;

      } while (bVar1 != 0);

      iVar4 = 0;

LAB_0074f48f:

      if (iVar4 == 0) {

        return iVar5;

      }

      iVar5 = iVar5 + 1;

      puVar2 = puVar2 + 0x35;

    } while (iVar5 < iVar7);

  }

  return -1;

}
