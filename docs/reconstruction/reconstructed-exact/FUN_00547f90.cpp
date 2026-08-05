// =============================================================================
// FUN_00547f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00547f90
// Address:   0x00547f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00547f90 @ 0x00547f90
// Stable ID: aa_00547f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: fread×3, FUN_00547f90, FUN_00548210, FUN_0059dcc0.
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

void __thiscall FUN_00547f90(void *param_1,FILE *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int local_15c;

  int local_158;

  void *local_154;

  void *local_150;

  uint8_t local_14c [320];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a43bd;

  local_c = ExceptionList;

  local_15c = 0;

  ExceptionList = &local_c;

  local_150 = param_1;

  fread(param_1,0x138,1,param_2);

  fread(&local_15c,4,1,param_2);

  local_158 = 0;

  pvVar3 = param_1;

  if (0 < local_15c) {

    do {

      fread(local_14c,0x140,1,param_2);

      local_154 = operator_new(0x168);

      local_4 = 0;

      if (local_154 == (void *)0x0) {

        local_154 = (void *)0x0;

      }

      else {

        local_154 = (void *)FUN_0059dcc0(local_14c,pvVar3);

      }

      iVar1 = *(int *)((int)param_1 + 0x13c);

      local_4 = 0xffffffff;

      if ((iVar1 == 0) ||

         ((uint)(*(int *)((int)param_1 + 0x144) - iVar1 >> 2) <=

          (uint)(*(int *)((int)param_1 + 0x140) - iVar1 >> 2))) {

        FUN_00548210(*(uint32_t /* width from decompiler */ *)((int)param_1 + 0x140),1,&local_154);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x140);

        *puVar2 = local_154;

        *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x140) = puVar2 + 1;

      }

      local_158 = local_158 + 1;

      pvVar3 = local_150;

    } while (local_158 < local_15c);

  }

  ExceptionList = local_c;

  return;

}
