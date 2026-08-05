// =============================================================================
// FUN_004ca760
// -----------------------------------------------------------------------------
// Stable ID: aa_004ca760
// Address:   0x004ca760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ca760 @ 0x004ca760
// Stable ID: aa_004ca760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_0040aff0×2, Object_ResolveFromTFID×2, FUN_004ca760, FUN_004cb4b0, FUN_004cc400, TFID_NotEquals.
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

void __thiscall

FUN_004ca760(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)



{

  int *piVar1;

  void *pA;

  TFID_16 *pTfid;

  int iVar2;

  uint8_t *puVar3;

  uint32_t /* width from decompiler */ *pB;

  int local_18;

  int local_14;

  uint8_t auStack_10 [12];

  uint32_t /* width from decompiler */ local_4;

  

  local_18 = FUN_004cb4b0(&param_3);

  if (((local_18 == *(int *)(param_1 + 0x158)) || ((int)param_4 < *(int *)(local_18 + 0x14))) ||

     (((int)param_4 <= *(int *)(local_18 + 0x14) && (param_3 < *(uint *)(local_18 + 0x10))))) {

    local_14 = *(int *)(param_1 + 0x158);

    piVar1 = &local_14;

  }

  else {

    piVar1 = &local_18;

  }

  iVar2 = param_2;

  if (*piVar1 != *(int *)(param_1 + 0x158)) {

    iVar2 = param_2 + *(int *)(*piVar1 + 0x20);

  }

  piVar1 = (int *)FUN_004cc400(&param_3);

  *piVar1 = iVar2;

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x50);

  if (((((*(uint *)(iVar2 + 0x44) & *(uint *)(iVar2 + 0x48)) == 0xffffffff) &&

       ((char)*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c) == '\0')) && (*(int *)(iVar2 + 0xa8) != 0)) &&

     ((*(int *)(*(int *)(iVar2 + 0xa8) + 0xe4e8) != 0 &&

      (piVar1 = Object_ResolveFromTFID((TFID_16 *)&param_3), piVar1 != (int *)0x0)))) {

    iVar2 = (**(code **)(*piVar1 + 0x1d8))();

    if (iVar2 != 0) {

      pB = &DAT_009cb8c0;

      puVar3 = auStack_10;

      (**(code **)(*piVar1 + 0x1d8))(puVar3);

      pA = (void *)FUN_0040aff0(puVar3);

      iVar2 = TFID_NotEquals(pA,pB);

      if ((char)iVar2 != '\0') {

        puVar3 = auStack_10;

        (**(code **)(*piVar1 + 0x1d8))(puVar3);

        pTfid = (TFID_16 *)FUN_0040aff0(puVar3);

        piVar1 = Object_ResolveFromTFID(pTfid);

        if (piVar1 == (int *)0x0) {

          return;

        }

        param_3 = piVar1[0x58];

        param_4 = piVar1[0x59];

        param_5 = piVar1[0x5a];

        param_6 = piVar1[0x5b];

      }

    }

    iVar2 = (**(code **)(*piVar1 + 0x210))(0);

    if (iVar2 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 600))

                (param_2,param_3,param_4,param_5);

    }

  }

  return;

}
