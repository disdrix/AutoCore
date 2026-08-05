// =============================================================================
// FUN_005756a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005756a0
// Address:   0x005756a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005756a0 @ 0x005756a0
// Stable ID: aa_005756a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00418e60, FUN_005756a0.
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

void __fastcall FUN_005756a0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = 0;

  if (*(char *)(param_1 + 0x1d8) != '\0') {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x198);

    do {

      if ((iVar4 < 0) || (3 < iVar4)) {

        local_8 = 0xffffffff;

        local_4 = 0xffffffff;

      }

      else {

        local_8 = *puVar3;

        local_4 = puVar3[1];

      }

      iVar1 = *(int *)(param_1 + 0x1f8);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(param_1 + 0x200) - iVar1 >> 3) <=

          (uint)(*(int *)(param_1 + 0x1fc) - iVar1 >> 3))) {

        FUN_00418e60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc),1,&local_8);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1fc);

        *puVar2 = local_8;

        puVar2[1] = local_4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x1fc) = puVar2 + 2;

      }

      puVar3 = puVar3 + 4;

      iVar4 = iVar4 + 1;

    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x1d8));

  }

  return;

}
