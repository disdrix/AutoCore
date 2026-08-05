// =============================================================================
// FUN_00865a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00865a40
// Address:   0x00865a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00865a40 @ 0x00865a40
// Stable ID: aa_00865a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×9, return×9, goto×4, do×2, while×2, switch×1.
//  - Notable callees: FUN_007900e0×2, FUN_00865a40, GetKeyState.
//  - Return sites: 9.

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

uint8_t __thiscall FUN_00865a40(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  bool bVar1;

  char cVar2;

  uint8_t uVar3;

  byte bVar4;

  SHORT SVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  

  if ((char)param_1[0x68a8] != '\0') {

    *(uint8_t *)(param_1 + 0x68a8) = 0;

    return 0;

  }

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 == '\0') {

LAB_00865c56:

    uVar3 = FUN_007900e0(param_2,param_3);

    return uVar3;

  }

  if ((param_1[0x12f] != 0) && (param_1[0x12f] == param_1[0x68ad])) {

    uVar3 = FUN_007900e0(param_2,param_3);

    iVar6 = (**(code **)(*(int *)param_1[0x68ad] + 0x1dc))();

    if (iVar6 != 0) {

      pcVar7 = (char *)(**(code **)(*(int *)param_1[0x68ad] + 0x1dc))();

      pcVar8 = pcVar7 + 1;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      if (pcVar7 != pcVar8) {

        pcVar7 = (char *)(**(code **)(*(int *)param_1[0x68ad] + 0x1dc))();

        pcVar8 = (char *)((int)param_1 + 0x515);

        do {

          cVar2 = *pcVar7;

          *pcVar8 = cVar2;

          pcVar7 = pcVar7 + 1;

          pcVar8 = pcVar8 + 1;

        } while (cVar2 != '\0');

        return uVar3;

      }

    }

    *(uint8_t *)((int)param_1 + 0x515) = 0;

    return uVar3;

  }

  if (param_2 != 9) goto LAB_00865c56;

  SVar5 = GetKeyState(0x10);

  bVar4 = ~(byte)((ushort)SVar5 >> 0xf) & 1;

  if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

    bVar1 = false;

  }

  else {

    bVar1 = true;

  }

  switch(param_1[0x144]) {

  case 1:

    iVar6 = (-(uint)(bVar4 != 0) & 0xfffffffb) + 10;

    break;

  case 2:

    iVar6 = (-(uint)(bVar4 != 0) & 6) + 4;

    goto LAB_00865c40;

  case 3:

    iVar6 = (-(uint)(bVar4 != 0) & 0xfffffff7) + 0xd;

    goto LAB_00865c40;

  case 4:

    iVar6 = 3 - (uint)(bVar4 != 0);

    break;

  case 5:

    if (bVar4 != 0) {

      param_1[0x144] = 0xe;

      (**(code **)(*param_1 + 0x444))();

      return 1;

    }

    param_1[0x144] = (-(uint)bVar1 & 0xfffffff7) + 10;

    (**(code **)(*param_1 + 0x444))();

    return 1;

  default:

    if (bVar4 == 0) {

      iVar6 = 2;

    }

    else {

      iVar6 = (uint)!bVar1 * 4 + 1;

    }

    goto LAB_00865c40;

  case 8:

    param_1[0x144] = (uint)(bVar4 != 0) * 4 + 9;

    (**(code **)(*param_1 + 0x444))();

    return 1;

  case 9:

    iVar6 = (-(uint)(bVar4 != 0) & 0xfffffff9) + 0xf;

    break;

  case 0xd:

    iVar6 = (-(uint)(bVar4 != 0) & 0xfffffffb) + 8;

    break;

  case 0xe:

    iVar6 = (-(uint)(bVar4 != 0) & 10) + 5;

    break;

  case 0xf:

    iVar6 = (-(uint)(bVar4 != 0) & 0xfffffffb) + 0xe;

LAB_00865c40:

    param_1[0x144] = iVar6;

    (**(code **)(*param_1 + 0x444))();

    return 1;

  }

  param_1[0x144] = iVar6;

  (**(code **)(*param_1 + 0x444))();

  return 1;

}
