// =============================================================================
// Named_CalleeOf_Client_RecvBroadcast_008f8200
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8200
// Callee of Client_RecvBroadcast (+15 other named callers)
// Address:   0x008f8200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvBroadcast (+15 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×15, goto×4, return×3, do×2, while×2.
//  - Notable callees: FUN_00573af0, FUN_0079d560, FUN_008f6100, FUN_008f62a0, FUN_008f6800, FUN_008f7cf0, FUN_008f8200, FUN_0095ab00.
//  - Strings: "%s%s".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_RecvBroadcast (+15 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Client_RecvBroadcast_008f8200(int param_1,int param_2,char *param_3,char *param_4,char param_5)



{

  int *piVar1;

  byte bVar2;

  char cVar3;

  uint8_t *puVar4;

  int iVar5;

  char *pcVar6;

  char *_Dest;

  char local_18 [20];

  uint8_t local_4;

  

  if ((param_2 < 0) || (0x18 < param_2)) {

    param_2 = 0;

  }

  if ((DAT_00af9218 & 1 << ((byte)param_2 & 0x1f)) == 0) {

    return;

  }

  local_4 = 0;

  puVar4 = &DAT_00a36c9c;

  if (param_5 == '\0') {

    puVar4 = &DAT_00a1419b;

  }

  _snprintf(local_18,0x14,"%s%s",puVar4,param_3);

  iVar5 = FUN_00573af0(param_3);

  if (iVar5 != 0) {

    return;

  }

  pcVar6 = param_4;

  do {

    cVar3 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar3 != '\0');

  _Dest = operator_new__((uint)(pcVar6 + (1 - (int)(param_4 + 1))));

  strncpy(_Dest,param_4,(size_t)(pcVar6 + (1 - (int)(param_4 + 1))));

  if ((DAT_00d1d8c8 != 0) && (DAT_00d1b225 != '\0')) {

    FUN_0079d560(DAT_00d1d8c8,_Dest);

  }

  if (((char)_DAT_00d1775c == '\0') || ((0xf < param_2 && (param_2 < 0x19)))) {

    if ((char)((ushort)_DAT_00d1775c >> 8) == '\0') goto LAB_008f82f1;

    if (0xf < param_2) {

      if (param_2 < 0x19) goto LAB_008f82e6;

      goto LAB_008f82f1;

    }

  }

  else {

LAB_008f82e6:

    FUN_008f6800(param_2,_Dest);

LAB_008f82f1:

    if ((0xf < param_2) && (param_2 < 0x19)) {

      bVar2 = 1;

      goto LAB_008f8301;

    }

  }

  bVar2 = 0;

LAB_008f8301:

  piVar1 = *(int **)(param_1 + 0x540 + (uint)bVar2 * 4);

  if (piVar1 != (int *)0x0) {

    FUN_0095ab00(_Dest);

    piVar1[0x147] = piVar1[0x147] + 1;

    piVar1[0x143] = piVar1[0x146];

    iVar5 = piVar1[0x146] + 1;

    piVar1[0x146] = iVar5;

    if (0x95 < iVar5) {

      *(uint8_t *)(piVar1 + 0x140) = 1;

      piVar1[0x146] = 0;

    }

    if ((char)piVar1[0x140] != '\0') {

      piVar1[0x142] = piVar1[0x146];

    }

    cVar3 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar3 != '\0') {

      FUN_008f7cf0(piVar1,piVar1[0x143],1,1,1,0);

      FUN_008f62a0(piVar1);

      FUN_008f6100(1);

    }

  }

  if ((param_2 == 2) && (DAT_00d1b978 != 0)) {

    pcVar6 = (char *)(DAT_00d1b978 + 0x924);

    do {

      cVar3 = *param_3;

      *pcVar6 = cVar3;

      param_3 = param_3 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar3 != '\0');

  }

  operator_delete__(_Dest);

  return;

}
