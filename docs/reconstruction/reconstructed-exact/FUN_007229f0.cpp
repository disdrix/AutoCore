// =============================================================================
// FUN_007229f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007229f0
// Address:   0x007229f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007229f0 @ 0x007229f0
// Stable ID: aa_007229f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_007229f0, strstr.
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

uint FUN_007229f0(int param_1,uint param_2,uint param_3,char *param_4)



{

  uint in_EAX;

  char *pcVar1;

  uint *puVar2;

  int iVar3;

  

  if ((param_4 == (char *)0x0) || (in_EAX = param_2 & param_3, in_EAX == 0xffffffff)) {

    return in_EAX & 0xffffff00;

  }

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x210)) {

    puVar2 = (uint *)(param_1 + 0x31c);

    do {

      in_EAX = *puVar2;

      if ((((in_EAX != 0) && (pcVar1 = (char *)(in_EAX + 0x48), pcVar1 != (char *)0x0)) &&

          (*(uint *)(in_EAX + 0x40) == param_2)) &&

         (in_EAX = *(uint *)(in_EAX + 0x44), in_EAX == param_3)) {

        pcVar1 = strstr(param_4,pcVar1);

        in_EAX = 0;

        if ((pcVar1 != (char *)0x0) &&

           ((in_EAX = *puVar2, *(char *)(in_EAX + 0x1c5) != '\0' ||

            (*(char *)(in_EAX + 0x3a) != '\0')))) {

          return CONCAT31((int3)(in_EAX >> 8),1);

        }

      }

      iVar3 = iVar3 + 1;

      puVar2 = puVar2 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x210));

  }

  return in_EAX & 0xffffff00;

}
