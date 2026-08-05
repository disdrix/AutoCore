// =============================================================================
// FUN_0048e2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048e2c0
// Address:   0x0048e2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048e2c0 @ 0x0048e2c0
// Stable ID: aa_0048e2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×16, return×12, while×1.
//  - Notable callees: FUN_0048cea0×3, FUN_0048d0a0×2, CONCAT31, FUN_0048aa20, FUN_0048ac80, FUN_0048cb50, FUN_0048cca0, FUN_0048cf60.
//  - Return sites: 12.

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

char * __thiscall

FUN_0048e2c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  uint16_t *puVar5;

  

  uVar1 = param_4;

  pcVar3 = (char *)FUN_0048cea0(param_2,param_4);

  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {

    return (char *)0x0;

  }

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_0048cca0(pcVar3,uVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *param_3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = param_3[1];

  }

  pcVar4 = (char *)FUN_0048cf60(pcVar3,param_1 + 0x14,uVar1);

  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {

    pcVar3 = (char *)FUN_0048cea0(pcVar4,uVar1);

    if ((pcVar3 == (char *)0x0) || ((*pcVar3 == '\0' || (*pcVar3 != '=')))) {

      if (*(int *)(param_1 + 0x10) == 0) {

        return (char *)0x0;

      }

      FUN_0048d0a0(7,pcVar3,param_3,uVar1);

      return (char *)0x0;

    }

    pcVar3 = (char *)FUN_0048cea0(pcVar3 + 1,uVar1);

    if ((pcVar3 != (char *)0x0) && (cVar2 = *pcVar3, cVar2 != '\0')) {

      if (cVar2 == '\'') {

        puVar5 = (uint16_t *)&DAT_00a2e3d0;

      }

      else {

        if (cVar2 != '\"') {

          FUN_0048ac80(&DAT_00a1419b);

          while( true ) {

            if (*pcVar3 == '\0') {

              return pcVar3;

            }

            cVar2 = FUN_0048cb50(*pcVar3);

            if (cVar2 != '\0') {

              return pcVar3;

            }

            cVar2 = *pcVar3;

            if (cVar2 == '\n') {

              return pcVar3;

            }

            if (cVar2 == '\r') break;

            if (cVar2 == '/') {

              return pcVar3;

            }

            if (cVar2 == '>') {

              return pcVar3;

            }

            param_4 = CONCAT31(param_4._1_3_,cVar2);

            FUN_0048aa20(&param_4,1);

            pcVar3 = pcVar3 + 1;

            if (pcVar3 == (char *)0x0) {

              return (char *)0x0;

            }

          }

          return pcVar3;

        }

        puVar5 = &DAT_00a2faa8;

      }

      pcVar3 = (char *)FUN_0048d970(pcVar3 + 1,param_1 + 0x18,0,puVar5,0,uVar1);

      return pcVar3;

    }

  }

  if (*(int *)(param_1 + 0x10) != 0) {

    FUN_0048d0a0(7,pcVar3,param_3,uVar1);

  }

  return (char *)0x0;

}
