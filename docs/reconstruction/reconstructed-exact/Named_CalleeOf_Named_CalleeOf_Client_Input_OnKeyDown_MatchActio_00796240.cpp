// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00796240
// -----------------------------------------------------------------------------
// Stable ID: aa_00796240
// Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
// Address:   0x00796240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_OnKeyDown_MatchAction: input/binding helper. Evidence string: "DIERR_NOTACQUIRED on m_parrDIDevicesImmediate[%i]->Poll()\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DIERR_NOTACQUIRED on m_parrDIDevicesImmediate[%i]->Poll()\n"
//   - "DIERR_NOTINITIALIZED on m_parrDIDevicesImmediate[%i]->Poll()\n"
//   - "DIERR_INPUTLOST on m_parrDIDevicesImmediate[%i]->Poll()\n"
//   - "DIERR_OTHERAPPHASPRIO on m_parrDIDevicesImmediate[%i]->Poll()\n"
//   - "DIERR_INVALIDPARAM on m_parrDIDevicesImmediate[%i]->Poll()\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, for×3, goto×3, do×1, switch×1, while×1.
//  - Notable callees: Poll×6, sprintf×6, OutputDebugStringA×4, FUN_00796240.
//  - Strings: "DIERR_NOTACQUIRED on m_parrDIDevicesImmediate[%i]->Poll()\n"; "DIERR_INPUTLOST on m_parrDIDevicesImmediate[%i]->Poll()\n"; "DIERR_INVALIDPARAM on m_parrDIDevicesImmediate[%i]->Poll()\n".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00796240(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uStack_734;

  uint32_t /* width from decompiler */ uStack_730;

  uint32_t /* width from decompiler */ uStack_72c;

  uint32_t /* width from decompiler */ uStack_728;

  uint32_t /* width from decompiler */ uStack_724;

  uint32_t /* width from decompiler */ auStack_720 [64];

  uint32_t /* width from decompiler */ auStack_620 [67];

  char acStack_514 [4];

  char local_510;

  uint32_t /* width from decompiler */ local_50f [322];

  

  local_510 = '\0';

  puVar4 = local_50f;

  for (iVar3 = 0x140; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  iVar3 = 0;

  do {

    if (*(int *)(in_EAX + 0x70 + iVar3 * 4) != 0) {

      piVar1 = *(int **)(in_EAX + 0x70 + iVar3 * 4);

      iVar2 = (**(code **)(*piVar1 + 100))(piVar1);

      if (iVar2 < 0) {

        if (iVar2 == -0x7ff8fff4) {

          sprintf(&local_510,"DIERR_NOTACQUIRED on m_parrDIDevicesImmediate[%i]->Poll()\n",iVar3);

        }

        else if (iVar2 == -0x7ff8ffeb) {

          sprintf(&local_510,"DIERR_NOTINITIALIZED on m_parrDIDevicesImmediate[%i]->Poll()\n",iVar3)

          ;

        }

        else {

          if (iVar2 != -0x7ff8ffe2) goto LAB_007963e5;

          sprintf(&local_510,"DIERR_INPUTLOST on m_parrDIDevicesImmediate[%i]->Poll()\n",iVar3);

        }

        OutputDebugStringA(&local_510);

LAB_007963e5:

        piVar1 = *(int **)(in_EAX + 0x70 + iVar3 * 4);

        uVar5 = (**(code **)(*piVar1 + 0x1c))(piVar1);

        switch(uVar5) {

        case 0x80070005:

          sprintf(acStack_514,"DIERR_OTHERAPPHASPRIO on m_parrDIDevicesImmediate[%i]->Poll()\n",

                  iVar3);

          OutputDebugStringA(acStack_514);

          return 0;

        case 0x80070015:

          sprintf(acStack_514,"DIERR_NOTINITIALIZED on m_parrDIDevicesImmediate[%i]->Poll()\n",iVar3

                 );

          OutputDebugStringA(acStack_514);

          return 0;

        case 0x8007001e:

          piVar1 = *(int **)(in_EAX + 0x70 + iVar3 * 4);

          (**(code **)(*piVar1 + 0x1c))(piVar1);

          return 0;

        case 0x80070057:

          sprintf(acStack_514,"DIERR_INVALIDPARAM on m_parrDIDevicesImmediate[%i]->Poll()\n",iVar3);

          OutputDebugStringA(acStack_514);

        }

        return 0;

      }

      if (iVar3 == 0) {

        puVar4 = auStack_720;

        for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        iVar2 = (**(code **)(**(int **)(in_EAX + 0x70) + 0x24))

                          (*(int **)(in_EAX + 0x70),0x100,auStack_720);

        if (-1 < iVar2) {

          puVar4 = auStack_720;

          uVar5 = 0;

LAB_0079634a:

          iVar2 = (**(code **)(in_EAX + 4))(uVar5,puVar4,param_1);

          if (iVar2 < 0) {

            return 0x80004005;

          }

        }

      }

      else if (iVar3 == 1) {

        uStack_734 = 0;

        uStack_730 = 0;

        uStack_72c = 0;

        uStack_728 = 0;

        uStack_724 = 0;

        iVar2 = (**(code **)(**(int **)(in_EAX + 0x74) + 0x24))

                          (*(int **)(in_EAX + 0x74),0x14,&uStack_734);

        if (-1 < iVar2) {

          puVar4 = &uStack_734;

          uVar5 = 1;

          goto LAB_0079634a;

        }

      }

      else if (iVar3 == 2) {

        puVar4 = auStack_620;

        for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar4 = 0;

          puVar4 = puVar4 + 1;

        }

        iVar2 = (**(code **)(**(int **)(in_EAX + 0x78) + 0x24))

                          (*(int **)(in_EAX + 0x78),0x110,auStack_620);

        if (-1 < iVar2) {

          puVar4 = auStack_620;

          uVar5 = 2;

          goto LAB_0079634a;

        }

      }

    }

    iVar3 = iVar3 + 1;

    if (2 < iVar3) {

      return 0;

    }

  } while( true );

}
