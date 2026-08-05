// =============================================================================
// FUN_006549b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006549b0
// Address:   0x006549b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006549b0 @ 0x006549b0
// Stable ID: aa_006549b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, do×5, while×5, return×1.
//  - Notable callees: FUN_006549b0.
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

void __fastcall FUN_006549b0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_8;

  

  iVar1 = *(int *)(param_1 + 0xc);

  local_8 = 0;

  if (0 < *(int *)(iVar1 + 0xc)) {

    do {

      iVar3 = *(int *)(*(int *)(iVar1 + 8) + local_8 * 4);

      iVar2 = 0;

      if (0 < *(int *)(iVar3 + 0x40)) {

        do {

          (**(code **)(*(int *)(param_1 + 0x14) + 0xc))

                    (*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x3c) + iVar2 * 4));

          iVar2 = iVar2 + 1;

        } while (iVar2 < *(int *)(iVar3 + 0x40));

      }

      local_8 = local_8 + 1;

    } while (local_8 < *(int *)(iVar1 + 0xc));

  }

  iVar1 = *(int *)(param_1 + 0xc);

  local_8 = 0;

  if (0 < *(int *)(iVar1 + 0x18)) {

    do {

      iVar3 = *(int *)(*(int *)(iVar1 + 0x14) + local_8 * 4);

      iVar2 = 0;

      if (0 < *(int *)(iVar3 + 0x40)) {

        do {

          (**(code **)(*(int *)(param_1 + 0x14) + 0xc))

                    (*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x3c) + iVar2 * 4));

          iVar2 = iVar2 + 1;

        } while (iVar2 < *(int *)(iVar3 + 0x40));

      }

      local_8 = local_8 + 1;

    } while (local_8 < *(int *)(iVar1 + 0x18));

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x2c);

  iVar3 = 0;

  if (0 < *(int *)(iVar1 + 0x40)) {

    do {

      (**(code **)(*(int *)(param_1 + 0x14) + 0xc))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x3c) + iVar3 * 4));

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(iVar1 + 0x40));

  }

  return;

}
