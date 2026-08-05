// =============================================================================
// Snd_PlaySound_Called_available_memory_found
// -----------------------------------------------------------------------------
// Stable ID: aa_007238c0
// Address:   0x007238c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Snd_PlaySound_Called_available_memory_found @ 0x007238c0
// Stable ID: aa_007238c0
// Embedded strings (evidence for future rename):
//   - "PlaySound Called: No available memory found\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×2, while×2, goto×1.
//  - Notable callees: Snd_PlaySound_Called_available_memory_found, FUN_007a4480.
//  - Strings: "PlaySound Called: No available memory found\n".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PlaySound Called: No available memory found
"
 * Domain alias of FUN_007238c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Snd_PlaySound_Called_available_memory_found(uint param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int local_4;

  

  iVar3 = param_1;

  piVar5 = (int *)(param_1 + 0x70);

  iVar4 = 0;

  local_4 = 0;

  param_1 = *(uint *)(*(int *)(param_1 + 0x70) + 0x110);

  do {

    uVar1 = *(uint *)(*piVar5 + 0x110);

    if (uVar1 == 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x70 + iVar4 * 4) + 0x110) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3dc);

      return iVar4;

    }

    iVar6 = 0;

    if (0 < *(int *)(iVar3 + 0x210)) {

      piVar7 = (int *)(iVar3 + 0x31c);

      do {

        iVar2 = *piVar7;

        if (((iVar2 != 0) && (*(int *)(iVar2 + 0x30) == iVar4)) &&

           ((*(char *)(iVar2 + 0x1c5) != '\0' || (*(char *)(iVar2 + 0x3a) != '\0'))))

        goto LAB_00723935;

        iVar6 = iVar6 + 1;

        piVar7 = piVar7 + 1;

      } while (iVar6 < *(int *)(iVar3 + 0x210));

    }

    if (uVar1 < param_1) {

      param_1 = uVar1;

      local_4 = iVar4;

    }

LAB_00723935:

    iVar4 = iVar4 + 1;

    piVar5 = piVar5 + 1;

    if (99 < iVar4) {

      if (local_4 != -1) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x70 + local_4 * 4) + 0x110) =

             *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3dc);

        return local_4;

      }

      FUN_007a4480(0,"PlaySound Called: No available memory found\n");

      return -1;

    }

  } while( true );

}
