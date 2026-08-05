// =============================================================================
// FUN_007451b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007451b0
// Address:   0x007451b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007451b0 @ 0x007451b0
// Stable ID: aa_007451b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: while×5, if×4, return×1.
//  - Notable callees: FUN_00426f60×3, FUN_007451b0×2, FUN_0044d610, FUN_007450b0.
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

void __thiscall FUN_007451b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint local_18 [3];

  uint8_t local_c [12];

  

  FUN_00426f60();

  puVar4 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_3 + 0x14))[1];

  cVar1 = *(char *)((int)puVar4 + 0x25);

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_3 + 0x14);

  while (cVar1 == '\0') {

    if ((uint)puVar4[3] < local_18[0]) {

      puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

      puVar4 = puVar2;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

    }

    puVar2 = puVar4;

    puVar4 = puVar3;

    cVar1 = *(char *)((int)puVar3 + 0x25);

  }

  FUN_00426f60();

  param_2 = *(uint32_t /* width from decompiler */ **)(param_3 + 0x14);

  cVar1 = *(char *)((int)param_2[1] + 0x25);

  puVar4 = (uint32_t /* width from decompiler */ *)param_2[1];

  while (cVar1 == '\0') {

    if (local_18[0] < (uint)puVar4[3]) {

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

      param_2 = puVar4;

    }

    else {

      puVar3 = (uint32_t /* width from decompiler */ *)puVar4[2];

    }

    puVar4 = puVar3;

    cVar1 = *(char *)((int)puVar3 + 0x25);

  }

  while (puVar2 != param_2) {

    FUN_007451b0(puVar2 + 6,param_3);

    FUN_00426f60();

    FUN_0044d610();

    FUN_007450b0(param_1,local_c,local_18);

    if (*(char *)((int)puVar2 + 0x25) == '\0') {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar2[2];

      if (*(char *)((int)puVar4 + 0x25) == '\0') {

        cVar1 = *(char *)((int)*puVar4 + 0x25);

        puVar2 = puVar4;

        puVar4 = (uint32_t /* width from decompiler */ *)*puVar4;

        while (cVar1 == '\0') {

          cVar1 = *(char *)((int)*puVar4 + 0x25);

          puVar2 = puVar4;

          puVar4 = (uint32_t /* width from decompiler */ *)*puVar4;

        }

      }

      else {

        cVar1 = *(char *)((int)puVar2[1] + 0x25);

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[1];

        puVar4 = puVar2;

        while ((puVar2 = puVar3, cVar1 == '\0' && (puVar4 == (uint32_t /* width from decompiler */ *)puVar2[2]))) {

          cVar1 = *(char *)((int)puVar2[1] + 0x25);

          puVar3 = (uint32_t /* width from decompiler */ *)puVar2[1];

          puVar4 = puVar2;

        }

      }

    }

  }

  return;

}
