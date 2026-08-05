// =============================================================================
// FUN_008c47c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c47c0
// Address:   0x008c47c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c47c0 @ 0x008c47c0
// Stable ID: aa_008c47c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, do×1, while×1, return×1.
//  - Notable callees: FUN_008c47c0.
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

void FUN_008c47c0(byte *param_1)



{

  byte bVar1;

  char cVar2;

  int in_EAX;

  byte *pbVar3;

  int iVar4;

  byte *pbVar5;

  bool bVar6;

  

  if ((*(int *)(in_EAX + 0x510) != 0) && (param_1 != (byte *)0x0)) {

    pbVar3 = *(byte **)(*(int *)(in_EAX + 0x510) + 0x4c8);

    pbVar5 = param_1;

    do {

      bVar1 = *pbVar3;

      bVar6 = bVar1 < *pbVar5;

      if (bVar1 != *pbVar5) {

LAB_008c480b:

        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);

        goto LAB_008c4810;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar3[1];

      bVar6 = bVar1 < pbVar5[1];

      if (bVar1 != pbVar5[1]) goto LAB_008c480b;

      pbVar3 = pbVar3 + 2;

      pbVar5 = pbVar5 + 2;

    } while (bVar1 != 0);

    iVar4 = 0;

LAB_008c4810:

    if (iVar4 != 0) {

      (**(code **)(**(int **)(in_EAX + 0x510) + 0x3ac))(param_1);

      (**(code **)(**(int **)(in_EAX + 0x510) + 0x34c))();

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x510) + 0xd8))();

      (**(code **)(**(int **)(in_EAX + 0x510) + 0xd4))(1);

      if (cVar2 == '\0') {

        (**(code **)(**(int **)(in_EAX + 0x510) + 0xd4))(0);

      }

    }

  }

  return;

}
