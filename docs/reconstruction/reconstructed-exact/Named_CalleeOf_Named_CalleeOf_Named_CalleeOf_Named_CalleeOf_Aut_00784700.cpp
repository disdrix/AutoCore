// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_00784700
// -----------------------------------------------------------------------------
// Stable ID: aa_00784700
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
// Address:   0x00784700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica: auth/session helper. Evidence string: "ipx:". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "ipx:"
//   - "broadcast"
//   - "broadcast:%d"
//   - "tcp:"
//   - "localhost"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, do×2, while×2.
//  - Notable callees: _stricmp×4, _strnicmp×3, htonl×3, sscanf×2, CONCAT22, FUN_007843e0, FUN_00784560, FUN_00784700.
//  - Strings: "ipx:"; "broadcast"; "broadcast:%d"; "%2x%2x%2x%2x:%2x%2x%2x%2x%2x%2x:%d".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_00784700(uint16_t *param_1,char *param_2)



{

  char cVar1;

  bool bVar2;

  u_short uVar3;

  int iVar4;

  char *pcVar5;

  hostent *phVar6;

  uint32_t /* width from decompiler */ local_12c;

  ulong local_128;

  uint local_124;

  uint local_120;

  uint16_t local_11c [2];

  int local_118;

  uint local_114;

  uint local_110;

  uint local_10c;

  int local_108;

  uint local_104;

  char local_100 [256];

  

  FUN_00784560();

  iVar4 = _strnicmp(param_2,"ipx:",4);

  if (iVar4 == 0) {

    *param_1 = 2;

    param_2 = param_2 + 4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 2) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 6) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0xffffffff;

    iVar4 = _stricmp(param_2,"broadcast");

    if (iVar4 == 0) {

      param_1[1] = 0;

      return 1;

    }

    iVar4 = sscanf(param_2,"broadcast:%d",local_11c);

    if (iVar4 == 1) {

      param_1[1] = local_11c[0];

      return 1;

    }

    iVar4 = sscanf(param_2,"%2x%2x%2x%2x:%2x%2x%2x%2x%2x%2x:%d",&local_12c,&local_128,&local_124,

                   &local_120,&local_118,&local_114,&local_110,&local_10c,&local_108,&local_104,

                   local_11c);

    if (iVar4 == 10) {

      local_11c[0] = 0;

    }

    else if (iVar4 != 0xb) {

      return 0;

    }

    *(ulong *)(param_1 + 2) = ((local_12c << 8 | local_128) << 8 | local_124) << 8 | local_120;

    *(uint *)(param_1 + 4) = ((local_118 << 8 | local_114) << 8 | local_110) << 8 | local_10c;

    *(uint *)(param_1 + 6) = local_108 << 8 | local_104;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    param_1[1] = local_11c[0];

  }

  else {

    bVar2 = false;

    iVar4 = _strnicmp(param_2,"ip:",3);

    if (iVar4 == 0) {

      param_2 = param_2 + 3;

    }

    else {

      iVar4 = _strnicmp(param_2,"tcp:",4);

      if (iVar4 == 0) {

        param_2 = param_2 + 4;

        bVar2 = true;

      }

    }

    pcVar5 = param_2;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    if (0xff < (uint)((int)pcVar5 - (int)(param_2 + 1))) {

      return 0;

    }

    iVar4 = -(int)param_2;

    do {

      cVar1 = *param_2;

      param_2[(int)(local_100 + iVar4)] = cVar1;

      param_2 = param_2 + 1;

    } while (cVar1 != '\0');

    pcVar5 = strchr(local_100,0x3a);

    if (pcVar5 != (char *)0x0) {

      *pcVar5 = '\0';

      pcVar5 = pcVar5 + 1;

    }

    iVar4 = _stricmp(local_100,"broadcast");

    if (iVar4 == 0) {

      local_128 = htonl(0xffffffff);

    }

    else {

      iVar4 = _stricmp(local_100,"localhost");

      if (iVar4 == 0) {

        local_128 = htonl(0x7f000001);

      }

      else {

        iVar4 = _stricmp(local_100,"any");

        if (iVar4 == 0) {

          local_128 = htonl(0);

        }

        else {

          local_128 = inet_addr(local_100);

          if (local_128 == 0xffffffff) {

            phVar6 = gethostbyname(local_100);

            if (phVar6 == (hostent *)0x0) {

              return 0;

            }

            local_128 = *(ulong *)*phVar6->h_addr_list;

          }

        }

      }

    }

    if (pcVar5 == (char *)0x0) {

      uVar3 = 0;

    }

    else {

      iVar4 = atoi(pcVar5);

      uVar3 = (u_short)iVar4;

    }

    uVar3 = htons(uVar3);

    local_12c = CONCAT22(uVar3,2);

    FUN_007843e0();

    if (bVar2) {

      *param_1 = 1;

      return 1;

    }

  }

  return 1;

}
