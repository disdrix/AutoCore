// =============================================================================
// Named_CalleeOf_Client_RecvCreateCharacter_004dea70
// -----------------------------------------------------------------------------
// Stable ID: aa_004dea70
// Callee of Client_RecvCreateCharacter
// Address:   0x004dea70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_004bb040, FUN_004de760, FUN_004dea70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvCreateCharacter
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

void __fastcall Named_CalleeOf_Client_RecvCreateCharacter_004dea70(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (((*(int *)(param_1 + 0xe8a0) != 0) &&

      (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe864), puVar3 != (uint32_t /* width from decompiler */ *)0x0)) &&

     (*(int *)(param_1 + 0xe868) - (int)puVar3 >> 3 != 0)) {

    if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xe868)) {

      do {

        iVar1 = FUN_004bb040(0,*puVar3,puVar3[1]);

        if (iVar1 != 0) {

          uVar2 = (**(code **)(**(int **)(param_1 + 0xe8a0) + 0x1dc))(iVar1);

          FUN_004de760(uVar2,iVar1);

        }

        puVar3 = puVar3 + 2;

      } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xe868));

    }

    if (*(void **)(param_1 + 0xe864) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0xe864));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe864) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe868) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe86c) = 0;

  }

  return;

}
