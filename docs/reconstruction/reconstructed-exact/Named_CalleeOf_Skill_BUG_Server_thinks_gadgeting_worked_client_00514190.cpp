// =============================================================================
// Named_CalleeOf_Skill_BUG_Server_thinks_gadgeting_worked_client_00514190
// -----------------------------------------------------------------------------
// Stable ID: aa_00514190
// Callee of Skill_BUG_Server_thinks_gadgeting_worked_client_can_t_
// Address:   0x00514190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_BUG_Server_thinks_gadgeting_worked_client: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_0040f540×2, FUN_00413f00×2, CONCAT22, FUN_00513400, FUN_00514190.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Skill_BUG_Server_thinks_gadgeting_worked_client_can_t_
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Skill_BUG_Server_thinks_gadgeting_worked_client_00514190(int *param_1,int *param_2)



{

  short sVar1;

  short sVar2;

  int iVar3;

  int iVar4;

  

  if ((param_2 != (int *)0x0) && (*(int *)(param_2[0x2a] + 0x38) == 8)) {

    iVar3 = (**(code **)(*param_2 + 0x1fc))();

    if (iVar3 != 0) {

      iVar4 = FUN_00513400(iVar3);

      if (iVar4 == 0) {

        iVar4 = *(int *)(*(int *)(iVar3 + 4) + 4);

        sVar2 = *(short *)((int)param_1 + 0xea);

        (**(code **)(*param_1 + 0x78))

                  (CONCAT22((short)((uint)iVar4 >> 0x10),

                            *(uint16_t *)(*(int *)(iVar4 + 0xac + iVar3) + 0x34)));

        (**(code **)(*param_1 + 0x68))(*(uint32_t /* width from decompiler */ *)(param_2[0x2a] + 0x34),0);

        sVar1 = FUN_0040f540();

        if ((int)sVar2 <= (int)sVar1) {

          sVar2 = FUN_0040f540();

          FUN_00413f00(sVar2 - (short)param_1[0x3a]);

          return 1;

        }

        FUN_00413f00((int)sVar2);

        return 1;

      }

    }

    return 0;

  }

  return 0;

}
