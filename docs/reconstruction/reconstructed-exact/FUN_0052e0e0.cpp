// =============================================================================
// FUN_0052e0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052e0e0
// Address:   0x0052e0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052e0e0 @ 0x0052e0e0
// Stable ID: aa_0052e0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: FUN_00418b80×2, FUN_0052d280, FUN_0052e0e0, FUN_00537c90, FUN_00538ab0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_0052e0e0(int param_1,uint *param_2)



{

  uint *puVar1;

  int *piVar2;

  uint *puVar3;

  char cVar4;

  int *piVar5;

  uint *local_8;

  int local_4;

  

  puVar3 = param_2;

  piVar5 = (int *)FUN_00538ab0(&local_4,&param_2);

  piVar2 = DAT_00b045b4;

  if ((int *)*piVar5 == DAT_00b045b4) {

    return 0;

  }

  param_2 = puVar3;

  FUN_00418b80(&local_8,&param_2);

  if ((local_8 != *(uint **)(param_1 + 0x588)) && (0 < (int)local_8[5])) {

    param_2 = (uint *)*piVar2;

    if (param_2 != (uint *)piVar2) {

      do {

        if (((int *)param_2 + 4 != (int *)0x0) &&

           (puVar1 = (uint *)((int *)param_2)[4], puVar1 != puVar3)) {

          local_8 = puVar1;

          FUN_00418b80(&local_4,&local_8);

          if ((local_4 != *(int *)(param_1 + 0x588)) && (0 < *(int *)(local_4 + 0x14))) {

            cVar4 = FUN_0052d280(puVar1,0xffffffff,puVar3);

            if (cVar4 == '\0') {

              return 0;

            }

          }

        }

        FUN_00537c90();

      } while (param_2 != (uint *)DAT_00b045b4);

    }

  }

  return 1;

}
