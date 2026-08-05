// =============================================================================
// FUN_004d08c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d08c0
// Address:   0x004d08c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d08c0 @ 0x004d08c0
// Stable ID: aa_004d08c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004cf120, FUN_004d08c0, FUN_00513de0, FUN_0052b350, FUN_0052dac0.
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

void FUN_004d08c0(short *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piVar4;

  int local_8;

  

  if ((param_1 != (short *)0x0) &&

     ((*(int *)((int)param_1 + 0xb0) != -1 ||

      (((*(int *)((int)param_1 + 0xc0) != -1 || (*(short *)((int)param_1 + 0xac) == -1)) &&

       (*(int *)((int)param_1 + 0xc0) != -1)))))) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_0052dac0(*(uint32_t /* width from decompiler */ *)param_1,1);

    piVar4 = (int *)((int)param_1 + 0xc0);

    local_8 = 4;

    param_1 = (short *)((int)param_1 + 0xe0);

    do {

      iVar1 = *piVar4;

      iVar3 = FUN_004cf120(piVar4[-4],iVar1);

      if (iVar3 != 0) {

        if ((*param_1 != 0) && (iVar1 == -1)) {

          FUN_00513de0(1);

        }

        *(uint *)(iVar3 + 0x17c) = *(uint *)(iVar3 + 0x17c) | 4;

        *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x160);

        puVar2[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164);

        puVar2 = puVar2 + 2;

        FUN_0052b350(iVar3);

      }

      param_1 = param_1 + 1;

      piVar4 = piVar4 + 1;

      local_8 = local_8 + -1;

    } while (local_8 != 0);

  }

  return;

}
