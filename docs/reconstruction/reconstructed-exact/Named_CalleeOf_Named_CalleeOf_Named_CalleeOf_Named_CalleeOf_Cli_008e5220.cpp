// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e5220
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5220
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x008e5220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005097b0×2, FUN_004ce940, FUN_00509410, FUN_008e5120, FUN_008e5220.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008e5220(void)



{

  uint16_t uVar1;

  int in_EAX;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (*(int *)(in_EAX + 0x7cc) != 0) {

    FUN_004ce940();

    iVar2 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x60))();

    if ((unaff_EDI < iVar2) &&

       (uVar3 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x5c))(), (uVar3 & 0xffff) != 0xffffffff))

    {

      uVar1 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x5c))();

      iVar4 = FUN_005097b0(uVar1);

      if ((iVar4 != 0) &&

         ((0 < iVar2 &&

          (uVar3 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x5c))(),

          (uVar3 & 0xffff) != 0xffffffff)))) {

        uVar1 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x5c))();

        iVar2 = **(int **)(in_EAX + 0x550 + unaff_EDI * 4);

        uVar7 = 1;

        uVar6 = 1;

        uVar5 = FUN_00509410(uVar1);

        (**(code **)(iVar2 + 0x1d8))(uVar5,uVar6,uVar7);

        uVar5 = 5;

        FUN_005097b0(uVar1);

        FUN_008e5120(uVar5);

        *(uint8_t *)(unaff_EDI + 0x7db + in_EAX) = 1;

        (**(code **)(**(int **)(in_EAX + 0x550 + unaff_EDI * 4) + 0xcc))(1);

        (**(code **)(**(int **)(in_EAX + 0x534 + unaff_EDI * 4) + 0xcc))(1);

        (**(code **)(**(int **)(in_EAX + 0x550 + unaff_EDI * 4) + 0x34c))();

        (**(code **)(**(int **)(in_EAX + 0x534 + unaff_EDI * 4) + 0x34c))();

      }

    }

  }

  return;

}
