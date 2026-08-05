// =============================================================================
// FUN_0064fb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0064fb60
// Address:   0x0064fb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064fb60 @ 0x0064fb60
// Stable ID: aa_0064fb60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005d6ae0, FUN_0064fb60.
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

void __fastcall FUN_0064fb60(int param_1)



{

  int iVar1;

  float fVar2;

  float fVar3;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  iVar1 = *(int *)(param_1 + 8);

  fVar2 = *(float *)(*(int *)(iVar1 + 0x14) + 0x14) * *(float *)(param_1 + 0x24);

  FUN_005d6ae0(*(int *)(*(int *)(iVar1 + 0x30) + 0x3c) + 0x80,*(int *)(iVar1 + 0x10) + 0x10);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c);

  fVar3 = *(float *)(iVar1 + 0x48) * local_18 + *(float *)(iVar1 + 0x44) * local_1c +

          *(float *)(iVar1 + 0x40) * local_20;

  if (*(float *)(param_1 + 0x28) <= fVar3) {

    fVar3 = *(float *)(param_1 + 0x28) / fVar3;

    fVar2 = fVar3 * fVar3 * fVar2;

  }

  iVar1 = 0;

  *(float *)(param_1 + 0x10) = fVar2;

  fVar2 = DAT_00af50c8;

  fVar3 = DAT_00af50c4;

  if (0 < *(int *)(param_1 + 0x20)) {

    do {

      if (*(char *)(iVar1 + *(int *)(param_1 + 0x2c)) == '\0') {

        if (iVar1 < 4) {

          *(float *)(*(int *)(param_1 + 0x14) + iVar1 * 4) =

               0.0 - *(float *)(param_1 + 0x10) * fVar2;

        }

        else {

          *(float *)(*(int *)(param_1 + 0x14) + iVar1 * 4) =

               0.0 - *(float *)(param_1 + 0x10) * fVar3;

        }

      }

      else {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < *(int *)(param_1 + 0x20));

  }

  return;

}
