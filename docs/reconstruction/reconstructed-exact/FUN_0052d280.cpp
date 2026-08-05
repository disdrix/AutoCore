// =============================================================================
// FUN_0052d280
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d280
// Address:   0x0052d280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052d280 @ 0x0052d280
// Stable ID: aa_0052d280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, for×1.
//  - Notable callees: FUN_0052d280×6, FUN_0052ad60×5, FUN_00418b80, FUN_00538ab0.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_0052d280(int param_1,uint param_2,int param_3,int param_4)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  uint *puVar4;

  uint *puVar5;

  uint local_210;

  uint local_20c;

  uint local_208 [4];

  int local_1f8;

  int local_1f4;

  int local_1f0;

  short local_1ec;

  short local_1ea;

  short local_1e8;

  short local_1e6;

  short local_1e4;

  

  if (param_2 != 0xffffffff) {

    local_210 = param_2;

    piVar2 = (int *)FUN_00538ab0(&local_20c,&local_210);

    if (*piVar2 != DAT_00b045b4) {

      puVar4 = (uint *)(*piVar2 + 0x10);

      puVar5 = local_208;

      for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      local_210 = param_2;

      FUN_00418b80(&local_20c,&local_210);

      if ((local_20c != *(uint *)(param_1 + 0x588)) && (0 < *(int *)(local_20c + 0x14))) {

        if ((((local_208[2] != -1) ||

             (((local_208[3] != -1 || (local_1f8 != -1)) || (local_1f4 != -1)))) ||

            (local_1f0 != -1)) &&

           (((param_4 == local_208[2] || (param_3 == local_208[2])) ||

            ((iVar3 = FUN_0052ad60(local_208[2]), iVar3 < local_1ec ||

             (cVar1 = FUN_0052d280(local_208[2],param_2,param_4), cVar1 == '\0')))))) {

          if (((param_4 != local_208[3]) && (param_3 != local_208[3])) &&

             ((iVar3 = FUN_0052ad60(local_208[3]), local_1ea <= iVar3 &&

              (cVar1 = FUN_0052d280(local_208[3],param_2,param_4), cVar1 != '\0')))) {

            return 1;

          }

          if (((((param_4 == local_1f8) || (param_3 == local_1f8)) ||

               (iVar3 = FUN_0052ad60(local_1f8), iVar3 < local_1e8)) ||

              (cVar1 = FUN_0052d280(local_1f8,param_2,param_4), cVar1 == '\0')) &&

             (((param_4 == local_1f4 || (param_3 == local_1f4)) ||

              ((iVar3 = FUN_0052ad60(local_1f4), iVar3 < local_1e6 ||

               (cVar1 = FUN_0052d280(local_1f4,param_2,param_4), cVar1 == '\0')))))) {

            if (param_4 == local_1f0) {

              return 0;

            }

            if (param_3 == local_1f0) {

              return 0;

            }

            iVar3 = FUN_0052ad60(local_1f0);

            if (iVar3 < local_1e4) {

              return 0;

            }

            cVar1 = FUN_0052d280(local_1f0,param_2,param_4);

            if (cVar1 == '\0') {

              return 0;

            }

          }

        }

        return 1;

      }

    }

  }

  return 0;

}
