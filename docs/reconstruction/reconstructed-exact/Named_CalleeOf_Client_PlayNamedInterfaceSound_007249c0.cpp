// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_007249c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007249c0
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x007249c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper. Evidence string: "Sound file doesn\'t exist: %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Sound file doesn\'t exist: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, while×2, do×1.
//  - Notable callees: FUN_00724870×2, FUN_007a4480×2, strtok×2, CVOGReaction_RandomUnitScalar, FUN_00419880, FUN_00424830, FUN_00480390, FUN_007249c0.
//  - Strings: "Sound file doesn\'t exist: %s".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

undefined * __thiscall Named_CalleeOf_Client_PlayNamedInterfaceSound_007249c0(int param_1,char *param_2,char param_3)



{

  char cVar1;

  char *pcVar2;

  int *piVar3;

  void *pvVar4;

  uint8_t local_1c [4];

  void *local_18;

  int *local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b10ca;

  local_c = ExceptionList;

  pcVar2 = param_2;

  ExceptionList = &local_c;

  do {

    cVar1 = *pcVar2;

    pcVar2[(int)&DAT_00d20d98 - (int)param_2] = cVar1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar2 = strchr(&DAT_00d20d98,0x7c);

  if (pcVar2 == (char *)0x0) {

    cVar1 = FUN_00724870(param_1,0,0);

    if (cVar1 == '\0') {

      if (param_3 != '\0') {

        FUN_007a4480(0,"Sound file doesn\'t exist: %s",&DAT_00d20d98);

      }

      ExceptionList = local_c;

      return (undefined *)0x0;

    }

    ExceptionList = local_c;

    return &DAT_00d20d98;

  }

  local_18 = (void *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  local_4 = 0;

  FUN_00480390();

  pcVar2 = strtok(&DAT_00d20d98,"|");

  pvVar4 = local_18;

  piVar3 = local_14;

  while (param_2 = pcVar2, pcVar2 != (char *)0x0) {

    cVar1 = FUN_00724870(param_1,0,0);

    if (cVar1 == '\0') {

      if (param_3 != '\0') {

        FUN_007a4480(0,"Sound file doesn\'t exist: %s",pcVar2);

      }

    }

    else {

      if ((pvVar4 == (void *)0x0) ||

         ((uint)(local_10 - (int)pvVar4 >> 2) <= (uint)((int)piVar3 - (int)pvVar4 >> 2))) {

        FUN_00419880(local_1c,piVar3,&param_2);

        pvVar4 = local_18;

      }

      else {

        *piVar3 = (int)pcVar2;

        local_14 = piVar3 + 1;

      }

      piVar3 = local_14;

      if (((*(char *)(param_1 + 0x308) != '\0') && (pvVar4 != (void *)0x0)) &&

         (2 < (uint)((int)local_14 - (int)pvVar4 >> 2))) break;

    }

    pcVar2 = strtok((char *)0x0,"|");

  }

  if (pvVar4 == (void *)0x0) {

    ExceptionList = local_c;

    return (undefined *)0x0;

  }

  if ((int)piVar3 - (int)pvVar4 >> 2 == 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  CVOGReaction_RandomUnitScalar();

  FUN_00424830();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar4);

}
