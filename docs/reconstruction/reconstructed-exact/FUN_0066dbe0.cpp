// =============================================================================
// FUN_0066dbe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066dbe0
// Address:   0x0066dbe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066dbe0 @ 0x0066dbe0
// Stable ID: aa_0066dbe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_00507210, FUN_005ffdb0, FUN_0066dbe0.
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

void __fastcall FUN_0066dbe0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  

  iVar5 = 0;

  puVar1 = param_1 + 6;

  *param_1 = &PTR_FUN_009e7b70;

  param_1[2] = &PTR_LAB_009e7b6c;

  param_1[3] = &PTR_LAB_009e7b64;

  param_1[4] = &PTR_LAB_009e7b5c;

  param_1[5] = &PTR_LAB_009e7ae8;

  *puVar1 = &PTR_LAB_009e7b4c;

  if (0 < (int)param_1[8]) {

    do {

      iVar2 = *(int *)(param_1[7] + iVar5 * 4);

      iVar3 = *(int *)(iVar2 + 0x80);

      iVar4 = 0;

      if (0 < iVar3) {

        piVar6 = *(int **)(iVar2 + 0x7c);

        do {

          if ((uint32_t /* width from decompiler */ *)*piVar6 == puVar1) {

            if (-1 < iVar4) {

              FUN_00507210(puVar1);

            }

            break;

          }

          iVar4 = iVar4 + 1;

          piVar6 = piVar6 + 1;

        } while (iVar4 < iVar3);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)param_1[8]);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);

  }

  *puVar1 = &PTR_LAB_009e3a68;

  param_1[4] = &PTR_LAB_009d278c;

  param_1[3] = &PTR_LAB_009d2784;

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
