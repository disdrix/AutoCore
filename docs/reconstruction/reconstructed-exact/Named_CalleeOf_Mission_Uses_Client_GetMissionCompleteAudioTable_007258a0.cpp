// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_007258a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007258a0
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x007258a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: ABS, FUN_00480170, FUN_00480350, FUN_00480460, FUN_00722b80, FUN_007249c0, FUN_007258a0, SQRT.
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_007258a0(int param_1,int param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  char cVar3;

  char *_Source;

  int iVar4;

  char *_Dest;

  

  if (*(char *)(param_1 + 600) == '\0') {

    return 0;

  }

  iVar4 = *(int *)(param_2 + 0x104);

  if ((iVar4 == 0xc) || (iVar4 == 0xd)) {

    cVar3 = FUN_00722b80(*(uint32_t /* width from decompiler */ *)(param_2 + 0x120),*(uint32_t /* width from decompiler */ *)(param_2 + 0x124),iVar4);

    if (cVar3 != '\0') {

      return 0;

    }

  }

  if ((SQRT(param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3) <= g_flZero) ||

     (fVar1 = *(float *)(param_1 + 0x220) - *param_3,

     fVar2 = *(float *)(param_1 + 0x228) - param_3[2],

     ABS(fVar1 * fVar1 + fVar2 * fVar2) <= *(float *)(param_2 + 0x114) * *(float *)(param_2 + 0x114)

     )) {

    _Source = (char *)FUN_007249c0(param_2,DAT_00d1a614);

    if (_Source != (char *)0x0) {

      iVar4 = FUN_00480460();

      if (iVar4 == 0) {

        _Dest = (char *)0x0;

      }

      else {

        _Dest = (char *)FUN_00480170();

      }

      strncpy(_Dest,_Source,0x104);

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x120) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x120);

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x124) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x124);

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x128) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x128);

      *(uint32_t /* width from decompiler */ *)(_Dest + 300) = *(uint32_t /* width from decompiler */ *)(param_2 + 300);

      _Dest[0x10b] = *(char *)(param_2 + 0x10b);

      _Dest[0x131] = *(char *)(param_2 + 0x109) == '\0';

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x104) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x104);

      _Dest[0x150] = '\0';

      fVar1 = g_flOne;

      _Dest[0x151] = '\0';

      _Dest[0x152] = '\0';

      _Dest[0x153] = '\0';

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x118) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x118);

      *(float *)(_Dest + 0x154) = fVar1;

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x110) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x110);

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x11c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x11c);

      *(uint32_t /* width from decompiler */ *)(_Dest + 0x114) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x114);

      _Dest[0x10c] = *(char *)(param_2 + 0x10c);

      FUN_00480350(param_1 + 0x310);

      return 1;

    }

  }

  return 0;

}
