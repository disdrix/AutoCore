// =============================================================================
// FUN_0081e0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e0f0
// Address:   0x0081e0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081e0f0 @ 0x0081e0f0
// Stable ID: aa_0081e0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: return×6, if×5, while×3, for×3, do×2.
//  - Notable callees: FUN_007f6080, FUN_0081e0f0, _stricmp.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_0081e0f0(int param_1,char *param_2)



{

  char cVar1;

  int *piVar2;

  char *in_EAX;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  int iVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  char *pcVar10;

  char cStack_111;

  uint32_t /* width from decompiler */ local_110;

  uint8_t local_10c;

  uint32_t /* width from decompiler */ local_10b;

  

  iVar7 = 0;

  while (iVar3 = _stricmp((&PTR_s_Fire1_00af9400)[iVar7],in_EAX), iVar3 != 0) {

    iVar7 = iVar7 + 1;

    if (0x12 < iVar7) {

      return 0;

    }

  }

  if (0x12 < iVar7) {

    return 0;

  }

  local_110 = DAT_00a77ae0;

  local_10c = DAT_00a77ae4;

  puVar9 = &local_10b;

  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar9 = 0;

    puVar9 = puVar9 + 1;

  }

  *(uint16_t *)puVar9 = 0;

  *(uint8_t *)((int)puVar9 + 2) = 0;

  pcVar4 = param_2;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar10 = &cStack_111;

  do {

    pcVar8 = pcVar10 + 1;

    pcVar10 = pcVar10 + 1;

  } while (*pcVar8 != '\0');

  pcVar8 = param_2;

  for (uVar6 = (uint)((int)pcVar4 - (int)param_2) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar8;

    pcVar8 = pcVar8 + 4;

    pcVar10 = pcVar10 + 4;

  }

  for (uVar6 = (int)pcVar4 - (int)param_2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *pcVar10 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar10 = pcVar10 + 1;

  }

  uVar5 = FUN_007f6080();

  if ((short)uVar5 == 0) {

    return 0;

  }

  piVar2 = *(int **)(param_1 + 0x1088 + iVar7 * 4);

  if ((short)piVar2[0x206] == 0) {

    (**(code **)(*piVar2 + 0x444))(uVar5);

    return 1;

  }

  if (*(short *)((int)piVar2 + 0x81a) != 0) {

    return 0;

  }

  (**(code **)(**(int **)(param_1 + 0x1088 + iVar7 * 4) + 0x448))(uVar5);

  return 1;

}
