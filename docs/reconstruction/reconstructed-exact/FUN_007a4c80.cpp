// =============================================================================
// FUN_007a4c80
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4c80
// Address:   0x007a4c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4c80 @ 0x007a4c80
// Stable ID: aa_007a4c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, return×2, while×2.
//  - Notable callees: strncpy×2, FUN_007a4c80, time.
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

void __fastcall FUN_007a4c80(int *param_1)



{

  char *_Dest;

  char cVar1;

  void *pvVar2;

  int iVar3;

  char *pcVar4;

  time_t tVar5;

  uint32_t /* width from decompiler */ *local_20;

  char local_14 [20];

  

  tVar5 = time((time_t *)0x0);

  iVar3 = (int)tVar5;

  local_20 = (uint32_t /* width from decompiler */ *)param_1[2];

  if (local_20 != (uint32_t /* width from decompiler */ *)param_1[3]) {

    do {

      pvVar2 = (void *)*local_20;

      if ((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x21c) <= iVar3)) {

        if (((*(int *)((int)pvVar2 + 0x1ec) < 1) &&

            (((*(int *)((int)pvVar2 + 0x1ec) < 0 || (*(int *)((int)pvVar2 + 0x1e8) == 0)) &&

             ((*(uint *)((int)pvVar2 + 0x1f0) & *(uint *)((int)pvVar2 + 500)) == 0xffffffff)))) ||

           ((*(int *)((int)pvVar2 + 0x210) == *(int *)((int)pvVar2 + 0x208) &&

            (*(int *)((int)pvVar2 + 0x214) == *(int *)((int)pvVar2 + 0x20c))))) {

          (**(code **)(*param_1 + 0x44))(pvVar2);

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar2);

        }

        _Dest = (char *)((int)pvVar2 + 0x1c2);

        pcVar4 = _Dest;

        do {

          cVar1 = *pcVar4;

          pcVar4[(int)(local_14 + -(int)_Dest)] = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar4 = (char *)((int)pvVar2 + 0x1d3);

        *_Dest = '\0';

        if (pcVar4 != (char *)0x0) {

          strncpy(_Dest,pcVar4,0x10);

          *(uint8_t *)((int)pvVar2 + 0x1d2) = 0;

        }

        *pcVar4 = '\0';

        strncpy(pcVar4,local_14,0x10);

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x214) = *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x20c);

        *(int *)((int)pvVar2 + 0x218) = iVar3;

        *(uint8_t *)((int)pvVar2 + 0x1e3) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x210) = *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x208);

        *(int *)((int)pvVar2 + 0x21c) = iVar3 + 0x278d00;

        (**(code **)(*param_1 + 0x3c))(pvVar2);

      }

      local_20 = local_20 + 1;

    } while (local_20 != (uint32_t /* width from decompiler */ *)param_1[3]);

  }

  return;

}
