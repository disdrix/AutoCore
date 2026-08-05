// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00725a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00725a70
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00725a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: ABS, FUN_00480170, FUN_00480350, FUN_00480460, FUN_007249c0, FUN_00725a70, SQRT, strncpy.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00725a70(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  char *_Source;

  int iVar3;

  char *_Dest;

  

  if (*(char *)(param_1 + 600) == '\0') {

    return 0;

  }

  if ((g_flZero < SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3)) &&

     (fVar1 = *(float *)(param_1 + 0x220) - *param_3,

     fVar2 = *(float *)(param_1 + 0x228) - param_3[2],

     DAT_00aaa880 < ABS(fVar1 * fVar1 + fVar2 * fVar2))) {

    return 0;

  }

  _Source = (char *)FUN_007249c0(param_2,DAT_00d1a614);

  if (_Source == (char *)0x0) {

    return 0;

  }

  iVar3 = FUN_00480460();

  if (iVar3 == 0) {

    _Dest = (char *)0x0;

  }

  else {

    _Dest = (char *)FUN_00480170();

  }

  strncpy(_Dest,_Source,0x104);

  _Dest[0x120] = -1;

  _Dest[0x121] = -1;

  _Dest[0x122] = -1;

  _Dest[0x123] = -1;

  _Dest[0x124] = -1;

  _Dest[0x125] = -1;

  _Dest[0x126] = -1;

  _Dest[0x127] = -1;

  _Dest[0x128] = '\0';

  _Dest[0x10b] = '\0';

  _Dest[0x131] = '\0';

  _Dest[0x104] = '2';

  _Dest[0x105] = '\0';

  _Dest[0x106] = '\0';

  _Dest[0x107] = '\0';

  _Dest[0x150] = '\0';

  _Dest[0x151] = '\0';

  _Dest[0x152] = '\0';

  _Dest[0x153] = '\0';

  _Dest[0x118] = '\0';

  _Dest[0x119] = '\0';

  _Dest[0x11a] = '\0';

  _Dest[0x11b] = '\0';

  _Dest[0x154] = '\0';

  _Dest[0x155] = '\0';

  _Dest[0x156] = '\0';

  _Dest[0x157] = '\0';

  *(int *)(_Dest + 0x110) = g_nInferredThreatDefault;

  *(float *)(_Dest + 0x11c) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(_Dest + 0x114) = DAT_00aaa7ac;

  FUN_00480350(param_1 + 0x310);

  return 1;

}
