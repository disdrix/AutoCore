// =============================================================================
// FUN_0046c450
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c450
// Address:   0x0046c450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046c450 @ 0x0046c450
// Stable ID: aa_0046c450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×9, return×7, goto×1.
//  - Notable callees: FUN_0043c2e0×6, FUN_0044aa90, FUN_00457cc0, FUN_0046c450, FUN_0046c5c0.
//  - Return sites: 7.

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

void __thiscall FUN_0046c450(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint local_8 [2];

  

  piVar1 = *(int **)(param_1 + 4);

  if (*(int *)(param_1 + 8) == 0) {

    FUN_0043c2e0(unaff_ESI,1,piVar1,in_EAX);

    return;

  }

  if (param_2 == (int *)*piVar1) {

    if ((*in_EAX << 0x10 | in_EAX[1]) < (param_2[3] << 0x10 | param_2[4])) {

LAB_0046c499:

      FUN_0043c2e0(unaff_ESI,1,param_2,in_EAX);

      return;

    }

  }

  else if (param_2 == piVar1) {

    iVar2 = piVar1[2];

    if ((int)(*(int *)(iVar2 + 0xc) << 0x10 | *(uint *)(iVar2 + 0x10)) <

        (*in_EAX << 0x10 | in_EAX[1])) {

      FUN_0043c2e0(unaff_ESI,0,iVar2,in_EAX);

      return;

    }

  }

  else {

    local_8[0] = *in_EAX << 0x10 | in_EAX[1];

    if (((int)local_8[0] < (param_2[3] << 0x10 | param_2[4])) &&

       (FUN_0044aa90(), (param_2[3] << 0x10 | param_2[4]) < (int)local_8[0])) {

      if (*(char *)(param_2[2] + 0x19) != '\0') {

        FUN_0043c2e0(unaff_ESI,0,param_2,in_EAX);

        return;

      }

      goto LAB_0046c499;

    }

    if (((param_2[3] << 0x10 | param_2[4]) < (int)local_8[0]) &&

       ((FUN_00457cc0(), param_2 == *(int **)(param_1 + 4) ||

        ((int)local_8[0] < (param_2[3] << 0x10 | param_2[4]))))) {

      if (*(char *)(param_2[2] + 0x19) == '\0') {

        FUN_0043c2e0(unaff_ESI,1,param_2,in_EAX);

        return;

      }

      FUN_0043c2e0(unaff_ESI,0,param_2,in_EAX);

      return;

    }

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0046c5c0(local_8);

  *unaff_ESI = *puVar3;

  return;

}
