// =============================================================================
// FUN_00891da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00891da0
// Address:   0x00891da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00891da0 @ 0x00891da0
// Stable ID: aa_00891da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_008904a0, FUN_00891480, FUN_00891da0.
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

void FUN_00891da0(int param_1,int param_2,char *param_3)



{

  bool bVar1;

  char cVar2;

  int *in_EAX;

  char *pcVar3;

  

  bVar1 = false;

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if ((cVar2 != '\0') && (in_EAX[0x16b] != 0)) {

    bVar1 = true;

  }

  in_EAX[0x16c] = param_1;

  in_EAX[0x16d] = param_2;

  in_EAX[0x16b] = 0;

  FUN_008904a0();

  if ((void *)in_EAX[0x147] != (void *)0x0) {

    operator_delete__((void *)in_EAX[0x147]);

  }

  in_EAX[0x147] = 0;

  if (param_3 != (char *)0x0) {

    pcVar3 = param_3;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)(param_3 + 1))));

    in_EAX[0x147] = (int)pcVar3;

    do {

      cVar2 = *param_3;

      *pcVar3 = cVar2;

      param_3 = param_3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

  }

  if ((int *)in_EAX[0x146] != (int *)0x0) {

    (**(code **)(*(int *)in_EAX[0x146] + 0x1d8))(in_EAX[0x147],1,1);

    (**(code **)(*(int *)in_EAX[0x146] + 0x34c))();

  }

  if (bVar1) {

    FUN_00891480(in_EAX);

  }

  return;

}
