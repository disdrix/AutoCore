// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Starting_Shu_0048ab30
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ab30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Starting_ShutDown_on_Client
// Address:   0x0048ab30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Starting_ShutDown_on_Client: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: for×6, if×5, return×2.
//  - Notable callees: CloseHandle, DeviceIoControl, FUN_0048aa70, FUN_0048ab30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Starting_ShutDown_on_Client
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Starting_Shu_0048ab30(uint32_t /* width from decompiler */ *param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *lpInBuffer;

  HANDLE hDevice;

  BOOL BVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  DWORD local_4;

  

  lpInBuffer = operator_new(param_2 + 0x2c);

  if (lpInBuffer != (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = param_1;

    puVar5 = lpInBuffer;

    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    if ((param_3 != (uint32_t /* width from decompiler */ *)0x0) && (0 < (int)param_2)) {

      puVar4 = param_3;

      puVar5 = lpInBuffer + 0xb;

      for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      }

    }

    hDevice = (HANDLE)FUN_0048aa70();

    if (hDevice != (HANDLE)0xffffffff) {

      BVar1 = DeviceIoControl(hDevice,0x22209c,lpInBuffer,param_2 + 0x2c,lpInBuffer,param_2 + 0x2c,

                              &local_4,(LPOVERLAPPED)0x0);

      CloseHandle(hDevice);

      if (BVar1 != 0) {

        puVar4 = lpInBuffer;

        for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {

          *param_1 = *puVar4;

          puVar4 = puVar4 + 1;

          param_1 = param_1 + 1;

        }

        if ((param_3 != (uint32_t /* width from decompiler */ *)0x0) && (0 < (int)param_2)) {

          puVar4 = lpInBuffer + 0xb;

          for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

            *param_3 = *puVar4;

            puVar4 = puVar4 + 1;

            param_3 = param_3 + 1;

          }

          for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {

            *(uint8_t *)param_3 = *(uint8_t *)puVar4;

            puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

            param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + 1);

          }

        }

      }

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(lpInBuffer);

  }

  return 0;

}
