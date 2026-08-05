// =============================================================================
// FUN_005abba0
// -----------------------------------------------------------------------------
// Stable ID: aa_005abba0
// Address:   0x005abba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005abba0 @ 0x005abba0
// Stable ID: aa_005abba0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×5, do×4, while×4, for×3, return×1.
//  - Notable callees: block×16, FUN_0076cec0×3, vog_LogMessage×3, SysFreeString×2, CONCAT31, FUN_005a9e70, FUN_005aa5c0, FUN_005aa890.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp".
//  - Return sites: 1.

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

/* WARNING: Removing unreachable block (ram,0x005abd1b) */

/* WARNING: Removing unreachable block (ram,0x005abd20) */

/* WARNING: Removing unreachable block (ram,0x005abd58) */

/* WARNING: Removing unreachable block (ram,0x005abe55) */

/* WARNING: Removing unreachable block (ram,0x005abe70) */

/* WARNING: Removing unreachable block (ram,0x005abe9f) */

/* WARNING: Removing unreachable block (ram,0x005abece) */

/* WARNING: Removing unreachable block (ram,0x005abee9) */

/* WARNING: Removing unreachable block (ram,0x005abeb6) */

/* WARNING: Removing unreachable block (ram,0x005abe87) */

/* WARNING: Removing unreachable block (ram,0x005abd6f) */

/* WARNING: Removing unreachable block (ram,0x005abdc3) */

/* WARNING: Removing unreachable block (ram,0x005abdcf) */

/* WARNING: Removing unreachable block (ram,0x005abdda) */

/* WARNING: Removing unreachable block (ram,0x005abde4) */

/* WARNING: Removing unreachable block (ram,0x005abde8) */



void __fastcall FUN_005abba0(int param_1)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  char *pcVar9;

  int *piStack_1d8;

  int local_1cc;

  int iStack_1c8;

  int local_1b0;

  char cStack_1a9;

  char local_1a8 [2];

  uint32_t /* width from decompiler */ uStack_1a6;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a6543;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  FUN_005ab110();

  FUN_005a9e70();

  FUN_005aa5c0();

  FUN_00799940();

  local_1a8[0] = '\0';

  local_1a8[1] = '\0';

  puVar8 = &uStack_1a6;

  for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  local_c = 0;

  *(uint16_t *)puVar8 = 0;

  pcVar2 = (char *)(*(int *)(param_1 + 8) + 0xb4);

  local_c = CONCAT31(local_c._1_3_,1);

  pcVar3 = pcVar2;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar9 = &cStack_1a9;

  do {

    pcVar7 = pcVar9 + 1;

    pcVar9 = pcVar9 + 1;

  } while (*pcVar7 != '\0');

  pcVar7 = pcVar2;

  for (uVar6 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar7;

    pcVar7 = pcVar7 + 4;

    pcVar9 = pcVar9 + 4;

  }

  for (uVar6 = (int)pcVar3 - (int)pcVar2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *pcVar9 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    pcVar9 = pcVar9 + 1;

  }

  pcVar3 = &cStack_1a9;

  do {

    pcVar2 = pcVar3;

    pcVar3 = pcVar2 + 1;

  } while (pcVar2[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar2 + 1) = DAT_00a9eaf0;

  pcVar2[5] = DAT_00a9eaf4;

  iVar5 = NDXml_OpenTaggedDocument();

  if (iVar5 == 0) {

    FUN_005aa890();

    local_1cc = 0;

    if (0 < local_1b0) {

      do {

        piVar4 = (int *)FUN_00799900();

        if (piVar4 == (int *)0x0) {

          FUN_0076cec0();

          vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp");

          break;

        }

        iVar5 = (**(code **)(*piVar4 + 0x44))();

        if ((iVar5 != 0) || (iStack_1c8 == 0)) {

          (**(code **)(*piVar4 + 8))();

          FUN_0076cec0();

          vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp");

          break;

        }

        (**(code **)(*piVar4 + 0x30))();

        if (piStack_1d8 == (int *)0x0) {

          (**(code **)(*piVar4 + 8))();

          FUN_0076cec0();

          vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMapText.cpp");

          break;

        }

        (**(code **)(*piStack_1d8 + 0x20))();

        (**(code **)(*piStack_1d8 + 8))(piStack_1d8);

        (**(code **)(*piVar4 + 8))(piVar4);

        local_1cc = local_1cc + 1;

      } while (local_1cc < local_1b0);

    }

    SysFreeString((BSTR)0x0);

  }

  else {

    SysFreeString((BSTR)0x0);

  }

  local_c = 0xffffffff;

  FUN_007989b0();

  ExceptionList = local_14;

  return;

}
