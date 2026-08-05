// =============================================================================
// FUN_00983f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00983f80
// Address:   0x00983f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983f80 @ 0x00983f80
// Stable ID: aa_00983f80
// Embedded strings (evidence for future rename):
//   - "Listing Files in pack file\n"
//   - "---------------------------------------------\n"
//   - "    Deleted at %d size %d\n"
//   - "Listed %d files. Used: %dK Empty: %dK Total: %dK (%2.1f%% empty)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, for×1, while×1.
//  - Notable callees: block×14, printf×6, FUN_00983350, FUN_00983eb0, FUN_00983f80, SUB84, dK.
//  - Strings: "Listing Files in pack file\n"; "---------------------------------------------\n"; "    Deleted at %d size %d\n".
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

/* WARNING: Removing unreachable block (ram,0x00983ff2) */

/* WARNING: Removing unreachable block (ram,0x00983ff9) */

/* WARNING: Removing unreachable block (ram,0x00983fff) */

/* WARNING: Removing unreachable block (ram,0x0098403f) */

/* WARNING: Removing unreachable block (ram,0x00984018) */

/* WARNING: Removing unreachable block (ram,0x00984037) */

/* WARNING: Removing unreachable block (ram,0x0098402f) */

/* WARNING: Removing unreachable block (ram,0x00984027) */

/* WARNING: Removing unreachable block (ram,0x0098401f) */

/* WARNING: Removing unreachable block (ram,0x00984041) */

/* WARNING: Removing unreachable block (ram,0x00984048) */

/* WARNING: Removing unreachable block (ram,0x0098404e) */

/* WARNING: Removing unreachable block (ram,0x00984096) */

/* WARNING: Removing unreachable block (ram,0x00984197) */

/* WARNING: Recovered jumptable eliminated as dead code */



uint32_t /* width from decompiler */ FUN_00983f80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int local_54;

  float local_4c;

  uint8_t local_38 [4];

  int *local_34;

  int *local_30;

  int local_28 [7];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af684;

  local_c = ExceptionList;

  local_54 = 0;

  ExceptionList = &local_c;

  printf("Listing Files in pack file\n");

  printf("---------------------------------------------\n");

  local_4 = 0;

  FUN_00983eb0(param_2,0);

  printf("---------------------------------------------\n");

  FUN_00983350(param_1,local_38);

  piVar3 = local_34;

  if (local_34 != local_30) {

    do {

      piVar4 = piVar3;

      piVar5 = local_28;

      for (iVar2 = 7; iVar1 = local_28[1], iVar2 != 0; iVar2 = iVar2 + -1) {

        *piVar5 = *piVar4;

        piVar4 = piVar4 + 1;

        piVar5 = piVar5 + 1;

      }

      printf("    Deleted at %d size %d\n",local_28[0],local_28[1]);

      local_54 = local_54 + iVar1;

      piVar3 = piVar3 + 7;

    } while (piVar3 != local_30);

  }

  printf("---------------------------------------------\n");

  local_4c = 0.0;

  if (local_54 != 0) {

    local_4c = ((float)local_54 / ((float)local_54 + 0.0)) * DAT_00aaa7ac;

  }

  printf("Listed %d files. Used: %dK Empty: %dK Total: %dK (%2.1f%% empty)\n",0,0,

         (int)(local_54 + (local_54 >> 0x1f & 0x3ffU)) >> 10,

         (int)(local_54 + (local_54 >> 0x1f & 0x3ffU)) >> 10,SUB84((double)local_4c,0),

         (int)((ulonglong)(double)local_4c >> 0x20));

  if (local_34 == (int *)0x0) {

    ExceptionList = local_c;

    return 0;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_34);

}
