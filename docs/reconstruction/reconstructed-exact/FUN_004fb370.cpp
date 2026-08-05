// =============================================================================
// FUN_004fb370
// -----------------------------------------------------------------------------
// Stable ID: aa_004fb370
// Address:   0x004fb370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004fb370 @ 0x004fb370
// Stable ID: aa_004fb370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1.
//  - Notable callees: FUN_0040d2a0, FUN_004cd220, FUN_004fb370, FUN_0053e600.
//  - Return sites: 2.

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

void __thiscall FUN_004fb370(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float10 fVar3;

  int local_28;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if ((*(char *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) + 0x7e) !=

       '\0') || (*(char *)(param_1 + -0x56d) != '\0')) {

    FUN_0053e600(param_2);

    iVar1 = 0;

    if ((*(int *)(param_1 + -0x668) != 0) &&

       (((*(int *)(param_1 + -0x4d0) != 0 && (*(int *)(*(int *)(param_1 + -0x4d0) + 4) != 0)) &&

        ('\0' < *(char *)(*(int *)(param_1 + -0x418) + 0xb0))))) {

      local_28 = 0;

      while( true ) {

        puVar2 = (uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4d0) + 4) + 0xc) + 0x80) +

                 local_28);

        fVar3 = (float10)FUN_004cd220(*puVar2,puVar2[2]);

        if ((float)puVar2[1] - (float)fVar3 < DAT_00aaa6d4) break;

        local_28 = local_28 + 0xc0;

        iVar1 = iVar1 + 1;

        if (*(char *)(*(int *)(param_1 + -0x418) + 0xb0) <= iVar1) {

          return;

        }

      }

      if (*(int *)(param_1 + -0x668) == 0) {

        iVar1 = *(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5ec + param_1;

      }

      else {

        iVar1 = *(int *)(*(int *)(param_1 + -0x668) + 0x3c) + 0xb0;

      }

      if (*(int *)(param_1 + -0x668) == 0) {

        puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5ec + param_1);

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x668) + 0x3c) + 0xb0);

      }

      local_18 = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

      local_20 = *puVar2;

      local_1c = (float)fVar3 + g_flOne;

      local_14 = 0;

      FUN_0040d2a0(&local_20);

    }

  }

  return;

}
