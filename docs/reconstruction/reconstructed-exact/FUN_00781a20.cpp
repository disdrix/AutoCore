// =============================================================================
// FUN_00781a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00781a20
// Address:   0x00781a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00781a20 @ 0x00781a20
// Stable ID: aa_00781a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1, goto×1.
//  - Notable callees: FUN_00781a20, FUN_009755d0.
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

void __thiscall FUN_00781a20(int param_1,int param_2)



{

  uint *puVar1;

  uint *puVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  

  FUN_009755d0(param_2);

  puVar1 = *(uint **)(param_2 + 0x18);

  if (puVar1 == (uint *)0x0) {

    return;

  }

  uVar4 = *puVar1;

  uVar5 = puVar1[1];

  for (puVar2 = (uint *)puVar1[5]; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[5]) {

    if (uVar4 == 0 && uVar5 == 0) goto LAB_00781ae0;

    uVar4 = uVar4 & ~*puVar2;

    uVar5 = uVar5 & ~puVar2[1];

  }

  if (uVar4 != 0 || uVar5 != 0) {

    uVar3 = puVar1[3];

    if (*(int *)(uVar3 + 8) == 0 && *(int *)(uVar3 + 0xc) == 0) {

      *(uint *)(uVar3 + 8) = uVar4;

      *(uint *)(uVar3 + 0xc) = uVar5;

      uVar4 = puVar1[3];

      if (*(int *)(uVar4 + 0x34) != *(int *)(param_1 + 0x20c)) {

        *(int *)(*(int *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x20c) * 4) + 0x34) =

             *(int *)(uVar4 + 0x34);

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x208) + *(int *)(uVar4 + 0x34) * 4) =

             *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x20c) * 4);

        *(uint *)(*(int *)(param_1 + 0x208) + *(int *)(param_1 + 0x20c) * 4) = uVar4;

        *(uint32_t /* width from decompiler */ *)(uVar4 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20c);

      }

      *(int *)(param_1 + 0x20c) = *(int *)(param_1 + 0x20c) + 1;

    }

    else {

      *(uint *)(uVar3 + 8) = *(uint *)(uVar3 + 8) | uVar4;

      *(uint *)(uVar3 + 0xc) = *(uint *)(uVar3 + 0xc) | uVar5;

    }

  }

LAB_00781ae0:

  if (*(uint **)(puVar1[3] + 0x10) == puVar1) {

    *(uint32_t /* width from decompiler */ *)(puVar1[3] + 0x10) = 0;

  }

  if ((puVar1[2] & 8) == 0) {

    if ((puVar1[2] & 0x20) != 0) {

      *(uint *)(puVar1[3] + 0x28) = *(uint *)(puVar1[3] + 0x28) | 0x10;

      *(uint *)(puVar1[3] + 0x28) = *(uint *)(puVar1[3] + 0x28) & 0xffffffdf;

    }

  }

  else {

    *(uint *)(puVar1[3] + 0x28) = *(uint *)(puVar1[3] + 0x28) | 4;

    *(uint *)(puVar1[3] + 0x28) = *(uint *)(puVar1[3] + 0x28) & 0xfffffff7;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar1);

}
