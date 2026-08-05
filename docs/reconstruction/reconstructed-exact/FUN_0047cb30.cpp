// =============================================================================
// FUN_0047cb30
// -----------------------------------------------------------------------------
// Stable ID: aa_0047cb30
// Address:   0x0047cb30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047cb30 @ 0x0047cb30
// Stable ID: aa_0047cb30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, goto×2, do×1, while×1.
//  - Notable callees: FUN_0047a480×3, FUN_00476c70×2, FUN_00476e50×2, FUN_00470be0, FUN_004776d0, FUN_00477710, FUN_0047a420, FUN_0047cb30.
//  - Return sites: 5.

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

void __thiscall FUN_0047cb30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  byte *pbVar1;

  byte bVar2;

  int iVar3;

  byte *pbVar4;

  byte local_14 [8];

  void *local_c;

  

  if (((*(uint *)(param_1 + 0x68) & 4) != 0) && (*(int *)(param_1 + 0x11c) != DAT_00a265a0)) {

    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) | 8;

  }

  pbVar1 = (byte *)(param_1 + 0x11c);

  FUN_0047cc90();

  if ((((*pbVar1 & 0x20) == 0) && (iVar3 = FUN_00476c70(), iVar3 != 3)) &&

     (*(int *)(param_1 + 0x21c) == 0)) {

    FUN_00476e50();

    return;

  }

  if ((*(byte *)(param_1 + 0x6d) & 0x80) == 0) goto LAB_0047cc72;

  pbVar4 = pbVar1;

  do {

    bVar2 = *pbVar4;

    pbVar4[(int)(local_14 + -(int)pbVar1)] = bVar2;

    pbVar4 = pbVar4 + 1;

  } while (bVar2 != 0);

  local_c = (void *)FUN_004776d0();

  FUN_0047a420();

  if (*(code **)(param_1 + 0x21c) == (code *)0x0) {

LAB_0047cc1f:

    FUN_00470be0(param_1,param_2,local_14,1);

  }

  else {

    iVar3 = (**(code **)(param_1 + 0x21c))(param_1,local_14);

    if (iVar3 < 1) {

      if (((*pbVar1 & 0x20) == 0) && (iVar3 = FUN_00476c70(), iVar3 != 3)) {

        FUN_00477710();

        FUN_00476e50();

        return;

      }

      goto LAB_0047cc1f;

    }

  }

  if (local_c != (void *)0x0) {

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(local_c);

      FUN_0047a480();

      return;

    }

    (**(code **)(param_1 + 0x24c))(param_1);

    FUN_0047a480();

    return;

  }

LAB_0047cc72:

  FUN_0047a480();

  return;

}
