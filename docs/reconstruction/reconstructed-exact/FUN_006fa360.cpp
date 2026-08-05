// =============================================================================
// FUN_006fa360
// -----------------------------------------------------------------------------
// Stable ID: aa_006fa360
// Address:   0x006fa360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fa360 @ 0x006fa360
// Stable ID: aa_006fa360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×10, goto×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370×3, FUN_006f84b0, FUN_006f8590, FUN_006f8640, FUN_006f8720, FUN_006f87d0, FUN_006f8b10, FUN_006f8c00.
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

void __thiscall FUN_006fa360(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  ushort uVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  ushort *puVar5;

  int local_dc;

  uint16_t *local_d8;

  uint8_t local_d3;

  uint8_t local_d2;

  uint8_t local_d1;

  uint8_t local_d0 [56];

  ushort local_98;

  ushort local_96;

  uint8_t local_90 [64];

  uint8_t local_50 [76];

  

  local_dc = 0;

  if (0 < *(int *)(param_2 + 0x54)) {

    local_d8 = (uint16_t *)(param_2 + 0x24);

    puVar5 = (ushort *)(param_2 + 0x20);

    do {

      uVar1 = *puVar5;

      if (uVar1 < 3) {

        FUN_006f84b0(local_90,puVar5);

        pcVar4 = (char *)FUN_006f8b10(&local_d2,local_90);

        if (*pcVar4 == '\0') goto LAB_006fa501;

        piVar2 = *(int **)param_1[4];

        if (piVar2[1] == (piVar2[2] & 0x7fffffffU)) {

          FUN_005b3370(piVar2,0x30);

        }

        iVar3 = piVar2[1];

        piVar2[1] = iVar3 + 1;

        FUN_006f8590(iVar3 * 0x30 + *piVar2,puVar5,local_90);

LAB_006fa47b:

        local_dc = local_dc + 1;

        puVar5 = puVar5 + 3;

        local_d8 = local_d8 + 3;

      }

      else {

        if (5 < uVar1) {

          local_96 = puVar5[1];

          local_98 = uVar1;

          pcVar4 = (char *)FUN_006f9f90(&local_d1,local_d0);

          if (*pcVar4 == '\0') goto LAB_006fa501;

          piVar2 = *(int **)param_1[4];

          if (piVar2[1] == (piVar2[2] & 0x7fffffffU)) {

            FUN_005b3370(piVar2,0x30);

          }

          iVar3 = piVar2[1];

          piVar2[1] = iVar3 + 1;

          FUN_006f87d0(iVar3 * 0x30 + *piVar2,puVar5,local_d0);

          goto LAB_006fa47b;

        }

        FUN_006f8640(local_50,puVar5);

        pcVar4 = (char *)FUN_006f8c00(&local_d3,local_50);

        if (*pcVar4 != '\0') {

          piVar2 = *(int **)param_1[4];

          if (piVar2[1] == (piVar2[2] & 0x7fffffffU)) {

            FUN_005b3370(piVar2,0x30);

          }

          iVar3 = piVar2[1];

          piVar2[1] = iVar3 + 1;

          FUN_006f8720(iVar3 * 0x30 + *piVar2,puVar5,local_50);

          goto LAB_006fa47b;

        }

LAB_006fa501:

        if (*puVar5 < 6) {

          *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + -1;

        }

        (**(code **)(*(int *)param_1[3] + 8))(*local_d8);

        FUN_006fb090(local_dc,*param_1,param_1[1]);

      }

    } while (local_dc < *(int *)(param_2 + 0x54));

  }

  return;

}
