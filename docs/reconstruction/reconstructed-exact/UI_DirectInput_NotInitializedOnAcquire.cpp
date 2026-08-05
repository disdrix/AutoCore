// =============================================================================
// UI_DirectInput_NotInitializedOnAcquire
// -----------------------------------------------------------------------------
// Stable ID: aa_00796040
// Address:   0x00796040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_DirectInput_NotInitializedOnAcquire @ 0x00796040
// Stable ID: aa_00796040
// Embedded strings (evidence for future rename):
//   - "DIERR_NOTACQUIRED on m_parrDIDevicesBuffered[dwDevice]->Poll()\n"
//   - "DIERR_NOTINITIALIZED on m_parrDIDevicesBuffered[dwDevice]->Poll()\n"
//   - "DIERR_INPUTLOST on m_parrDIDevicesBuffered[dwDevice]->Poll()\n"
//   - "DIERR_OTHERAPPHASPRIO on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n"
//   - "DIERR_NOTINITIALIZED on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n"
//   - "DIERR_INVALIDPARAM on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: return×7, if×6, while×1, goto×1, switch×1.
//  - Notable callees: OutputDebugStringA×4, Acquire×3, Poll×3, UI_DirectInput_NotInitializedOnAcquire.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "DIERR_NOTINITIALIZED on m_parrDIDevicesBuffered[dwDevice]->Acquire()
"
 * Domain alias of FUN_00796040 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ UI_DirectInput_NotInitializedOnAcquire(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piVar5;

  char *lpOutputString;

  uint32_t /* width from decompiler */ uStack_1404;

  uint8_t auStack_1400 [5116];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x79604a;

  iVar4 = 0;

  piVar5 = param_1 + 3;

  if (param_1[3] == 0) {

    return 1;

  }

  while (iVar2 = (**(code **)(*(int *)*piVar5 + 100))((int *)*piVar5), -1 < iVar2) {

    iVar2 = (**(code **)(*(int *)*piVar5 + 0x28))

                      ((int *)*piVar5,0x14,&uStack_1404,&stack0xffffebf8,0);

    if ((-1 < iVar2) &&

       (cVar1 = (*(code *)*param_1)(uStack_1404,auStack_1400,param_2), cVar1 == '\0')) {

      return 0;

    }

    piVar5 = piVar5 + 1;

    iVar4 = iVar4 + 1;

    if (*piVar5 == 0) {

      return 1;

    }

  }

  if (iVar2 == -0x7ff8fff4) {

    lpOutputString = "DIERR_NOTACQUIRED on m_parrDIDevicesBuffered[dwDevice]->Poll()\n";

  }

  else if (iVar2 == -0x7ff8ffeb) {

    lpOutputString = "DIERR_NOTINITIALIZED on m_parrDIDevicesBuffered[dwDevice]->Poll()\n";

  }

  else {

    if (iVar2 != -0x7ff8ffe2) goto LAB_00796102;

    lpOutputString = "DIERR_INPUTLOST on m_parrDIDevicesBuffered[dwDevice]->Poll()\n";

  }

  OutputDebugStringA(lpOutputString);

LAB_00796102:

  uVar3 = (**(code **)(*(int *)param_1[iVar4 + 3] + 0x1c))((int *)param_1[iVar4 + 3]);

  switch(uVar3) {

  case 0x80070005:

    OutputDebugStringA("DIERR_OTHERAPPHASPRIO on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n");

    return 1;

  case 0x80070015:

    OutputDebugStringA("DIERR_NOTINITIALIZED on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n");

    return 1;

  case 0x8007001e:

    (**(code **)(*(int *)param_1[iVar4 + 3] + 0x1c))((int *)param_1[iVar4 + 3]);

    return 1;

  case 0x80070057:

    OutputDebugStringA("DIERR_INVALIDPARAM on m_parrDIDevicesBuffered[dwDevice]->Acquire()\n");

  }

  return 1;

}
