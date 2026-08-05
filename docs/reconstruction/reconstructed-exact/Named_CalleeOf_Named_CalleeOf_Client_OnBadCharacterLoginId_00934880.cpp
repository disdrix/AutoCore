// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_00934880
// -----------------------------------------------------------------------------
// Stable ID: aa_00934880
// Callee of Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x00934880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_007fca10×6, FUN_007fdcc0, FUN_007fddd0, FUN_007fe640, FUN_00934880, FUN_00997120.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_OnBadCharacterLoginId
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

void Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId_00934880(void)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  int *piVar4;

  

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fe640(in_EAX);

  FUN_007fdcc0(in_EAX);

  FUN_007fddd0();

  FUN_00997120(in_EAX);

  if (*(int **)(in_EAX + 0x1164) != (int *)0x0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1164) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x1164) + 4))(0);

    }

  }

  piVar4 = (int *)(in_EAX + 0x1030);

  iVar3 = 0;

  piVar2 = piVar4;

  do {

    *(uint8_t *)(in_EAX + 0x22 + iVar3) = 0;

    if (((((((int *)*piVar2 != (int *)0x0) && (iVar3 != 0x14)) && (iVar3 != 0x15)) &&

         ((iVar3 != 0xb && (iVar3 != 0xc)))) && ((iVar3 != 9 && ((iVar3 != 7 && (iVar3 != 6)))))) &&

       ((iVar3 != 0xf && ((iVar3 != 10 && (iVar3 != 0x10)))))) {

      cVar1 = (**(code **)(*(int *)*piVar2 + 0x3d8))();

      if (cVar1 != '\0') {

        *(uint8_t *)(in_EAX + 0x22 + iVar3) = 1;

      }

    }

    iVar3 = iVar3 + 1;

    piVar2 = piVar2 + 1;

  } while (iVar3 < 0x3a);

  iVar3 = 0x3a;

  do {

    if ((int *)*piVar4 != (int *)0x0) {

      cVar1 = (**(code **)(*(int *)*piVar4 + 0x3d8))();

      if (cVar1 != '\0') {

        FUN_007fca10();

      }

    }

    piVar4 = piVar4 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  *(uint8_t *)(in_EAX + 0x31d8) = 1;

  if (*(int **)(in_EAX + 0xf38) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0xf38) + 0x3c4))(1);

  }

  return;

}
