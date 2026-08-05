// =============================================================================
// CVOGFlairGenerator
// -----------------------------------------------------------------------------
// Stable ID: aa_00497d60
// Address:   0x00497d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CVOGFlairGenerator for FUN_00497d60 @ 0x00497d60
// Stable ID: aa_00497d60
// Embedded strings (evidence for future rename):
//   - "CVOGFlairGenerator"
//   - "m_iWidth"
//   - "m_iHeight"
//   - "m_iMaximumObjectCountPerGlomSector"
//   - "m_iObjectCount"
//   - "bInlineDensityMap"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00498740×4, FUN_00497b70, FUN_00497bf0, CVOGFlairGenerator, FUN_00498980, FUN_007874b0, FUN_00787530, FUN_0079d1e0.
//  - Strings: "CVOGFlairGenerator"; "m_iWidth"; "m_iHeight"; "m_iMaximumObjectCountPerGlomSector".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGFlairGenerator"
 * Domain alias of FUN_00497d60 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall CVOGFlairGenerator(uint8_t *param_1,uint param_2)



{

  int *piVar1;

  uint uVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  int local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0dd3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0079d290(1,"CVOGFlairGenerator");

  FUN_00498740("m_iWidth",param_1 + 4);

  FUN_00498740("m_iHeight",param_1 + 8);

  FUN_00498740("m_iMaximumObjectCountPerGlomSector",param_1 + 0xc);

  piVar1 = (int *)(param_1 + 0x10);

  FUN_00498740("m_iObjectCount",piVar1);

  local_14 = 0;

  if (0 < *piVar1) {

    piVar5 = (int *)(param_1 + 0x14);

    do {

      if (*piVar5 == 0) {

        pvVar3 = operator_new(0x20b0);

        local_4 = 0;

        if (pvVar3 == (void *)0x0) {

          iVar4 = 0;

        }

        else {

          iVar4 = FUN_00497b70();

        }

        local_4 = 0xffffffff;

        *piVar5 = iVar4;

      }

      FUN_00497bf0(uVar2);

      local_14 = local_14 + 1;

      piVar5 = piVar5 + 1;

    } while (local_14 < *piVar1);

  }

  param_2 = param_2 & 0xffffff00;

  FUN_00498980("bInlineDensityMap",&param_2);

  if ((char)param_2 == '\0') {

    if (*(char *)(uVar2 + 5) != '\0') {

      FUN_007874b0(0,0);

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

      *param_1 = 1;

    }

  }

  else if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) != 0)) {

    FUN_00787530(uVar2);

    *param_1 = 0;

  }

  FUN_0079d1e0();

  ExceptionList = local_c;

  return;

}
