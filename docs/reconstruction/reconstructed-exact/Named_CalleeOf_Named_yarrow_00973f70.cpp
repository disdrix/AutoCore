// =============================================================================
// Named_CalleeOf_Named_yarrow_00973f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00973f70
// Callee of Named_yarrow
// Address:   0x00973f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_yarrow: callee helper. Evidence string: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"
//   - "cipher != NULL"
//   - "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\crypt\\crypt_register_cipher.c"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×2, do×1, for×1.
//  - Notable callees: FUN_00973f70, fprintf, raise.
//  - Strings: "LTC_ARGCHK \'%s\' failure on line %d of file %s\n"; "cipher != NULL".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_yarrow
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_CalleeOf_Named_yarrow_00973f70(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  char *pcVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (in_EAX == (uint32_t /* width from decompiler */ *)0x0) {

    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",

            "cipher != NULL",0x1b,

            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\crypt\\crypt_register_cipher.c"

           );

    raise(0x16);

  }

  iVar1 = 0;

  pcVar2 = &DAT_00d17a34;

  while ((*(int *)(pcVar2 + -4) == 0 || (*pcVar2 != *(char *)(in_EAX + 1)))) {

    pcVar2 = pcVar2 + 0x4c;

    iVar1 = iVar1 + 1;

    if (0xd183b3 < (int)pcVar2) {

      iVar1 = 0;

      piVar3 = &DAT_00d17a30;

      do {

        if (*piVar3 == 0) {

          puVar5 = &DAT_00d17a30 + iVar1 * 0x13;

          for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar5 = *in_EAX;

            in_EAX = in_EAX + 1;

            puVar5 = puVar5 + 1;

          }

          return iVar1;

        }

        piVar3 = piVar3 + 0x13;

        iVar1 = iVar1 + 1;

      } while ((int)piVar3 < 0xd183b0);

      return -1;

    }

  }

  return iVar1;

}
