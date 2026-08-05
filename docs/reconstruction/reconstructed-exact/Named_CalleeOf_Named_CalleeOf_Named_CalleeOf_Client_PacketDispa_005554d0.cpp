// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_005554d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005554d0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x005554d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper. Evidence string: "Failed to load weather FX: %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Failed to load weather FX: %s"
//   - "env_time_midday"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004b8dc0×4, NDSpecialFX_LoadFromScriptName×2, FUN_004b9270, FUN_005554d0, FUN_007a4480.
//  - Strings: "Failed to load weather FX: %s"; "env_time_midday".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_005554d0(int param_1)



{

  char *pszName;

  void *pvVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  

  iVar2 = 0;

  for (uVar3 = 0;

      (*(int *)(param_1 + 0x434) != 0 &&

      (uVar3 < (uint)((*(int *)(param_1 + 0x438) - *(int *)(param_1 + 0x434)) / 0x134)));

      uVar3 = uVar3 + 1) {

    if (*(int *)(*(int *)(param_1 + 0x434) + 0x104 + iVar2) != 0) {

      FUN_004b8dc0(0,0);

    }

    iVar2 = iVar2 + 0x134;

  }

  if (*(int *)(param_1 + 0x544) != 0) {

    pszName = (char *)(param_1 + 0x440);

    if ((*(int *)(param_1 + 0x544) == 0) && (*pszName != '\0')) {

      pvVar1 = NDSpecialFX_LoadFromScriptName(pszName,0,0);

      *(void **)(param_1 + 0x544) = pvVar1;

      if (pvVar1 == (void *)0x0) {

        FUN_007a4480(1,"Failed to load weather FX: %s",pszName);

        pvVar1 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

        *(void **)(param_1 + 0x544) = pvVar1;

      }

      if (*(int *)(param_1 + 0x544) != 0) {

        *(uint8_t *)(*(int *)(param_1 + 0x544) + 9) = 1;

        FUN_004b8dc0(0,0);

        FUN_004b9270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x544));

      }

    }

    FUN_004b8dc0(0,0);

  }

  piVar4 = (int *)(param_1 + 0x104);

  iVar2 = 4;

  do {

    if (*piVar4 != 0) {

      FUN_004b8dc0(0,0);

    }

    piVar4 = piVar4 + 0x43;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
