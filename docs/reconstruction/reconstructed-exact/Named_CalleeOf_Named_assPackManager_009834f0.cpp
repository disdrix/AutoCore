// =============================================================================
// Named_CalleeOf_Named_assPackManager_009834f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009834f0
// Callee of Named_assPackManager
// Address:   0x009834f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×8, goto×2, for×1, do×1, while×1, return×1.
//  - Notable callees: EnterCriticalSection, FUN_009834f0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPackManager
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

int Named_CalleeOf_Named_assPackManager_009834f0(void)



{

  byte bVar1;

  int iVar2;

  int in_EAX;

  byte *pbVar3;

  int iVar4;

  byte *unaff_EBX;

  byte *pbVar5;

  int *piVar6;

  bool bVar7;

  int local_c;

  

  if (*(char *)(in_EAX + 0x50) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x38));

  }

  local_c = 0;

  iVar2 = local_c;

  if (unaff_EBX == (byte *)0x0) {

    piVar6 = *(int **)(in_EAX + 0x2c);

    if ((piVar6 != (int *)0x0) && (*(int *)(in_EAX + 0x30) - (int)piVar6 >> 2 != 0)) {

      iVar2 = *piVar6;

    }

  }

  else {

    for (piVar6 = *(int **)(in_EAX + 0x2c); iVar2 = local_c, piVar6 != *(int **)(in_EAX + 0x30);

        piVar6 = piVar6 + 1) {

      pbVar5 = *(byte **)(*piVar6 + 0x28);

      pbVar3 = unaff_EBX;

      do {

        bVar1 = *pbVar3;

        bVar7 = bVar1 < *pbVar5;

        if (bVar1 != *pbVar5) {

LAB_00983574:

          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

          goto LAB_00983579;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar3[1];

        bVar7 = bVar1 < pbVar5[1];

        if (bVar1 != pbVar5[1]) goto LAB_00983574;

        pbVar3 = pbVar3 + 2;

        pbVar5 = pbVar5 + 2;

      } while (bVar1 != 0);

      iVar4 = 0;

LAB_00983579:

      iVar2 = *piVar6;

      if (iVar4 == 0) break;

    }

  }

  local_c = iVar2;

  if (*(char *)(in_EAX + 0x50) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x38));

  }

  return local_c;

}
