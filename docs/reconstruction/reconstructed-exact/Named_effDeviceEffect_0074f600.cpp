// READABILITY (auto CF):
//  - Body size: ~209 non-empty decompiler lines.
//  - Control keywords: if×25, goto×16, do×3, while×3, return×3, switch×1, for×1.
//  - Notable callees: _strnicmp×18, atoi×3, vog_LogMessage×2, FUN_00445fa0, FUN_0045f220, FUN_00747180, FUN_0074eeb0, FUN_0074f600.
//  - Strings: ",

                   0x7b9,3,"; "positiontl"; "float"; "d3dcolor".
//  - Return sites: 3.

// =============================================================================
// Named_effDeviceEffect_0074f600
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f600
// Address:   0x0074f600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effDeviceEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_effDeviceEffect_0074f600(char *param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  char *_Str1;

  byte local_d;

  uint16_t local_8;

  ushort local_6;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (param_1 == (char *)0x0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0x7b9,3,"Failure to find Vertex Decleration element in SFX.");

    return 0xffffffff;

  }

  local_d = 0;

  _Str1 = param_1;

  do {

    if ((int)pcVar2 - (int)(param_1 + 1) <= (int)_Str1 - (int)param_1) break;

    local_8 = 0;

    local_6 = (ushort)local_d;

    local_3 = 0;

    local_1 = 0;

    iVar3 = _strnicmp(_Str1,"positiontl",10);

    if (iVar3 == 0) {

      _Str1 = _Str1 + 10;

      local_2 = 9;

LAB_0074f7fb:

      iVar3 = atoi(_Str1);

      local_1 = (uint8_t)iVar3;

      do {

        _Str1 = _Str1 + 1;

LAB_0074f808:

        cVar1 = *_Str1;

        if ((((cVar1 != ' ') && (cVar1 != ',')) && (cVar1 != '\n')) && (cVar1 != '\r'))

        goto LAB_0074f820;

      } while (cVar1 != '\0');

      _Str1 = (char *)0x0;

LAB_0074f820:

      iVar3 = _strnicmp(_Str1,"float",5);

      if (iVar3 == 0) {

        iVar3 = atoi(_Str1 + 5);

        switch(iVar3) {

        case 1:

          local_4 = 0;

LAB_0074f8f6:

          local_d = local_d + 4;

          break;

        case 2:

          local_d = local_d + 8;

          local_4 = 1;

          break;

        case 3:

          local_d = local_d + 0xc;

          local_4 = 2;

          break;

        case 4:

          local_d = local_d + 0x10;

          local_4 = 3;

        }

switchD_0074f846_default:

        _Str1 = _Str1 + 6;

      }

      else {

        iVar3 = _strnicmp(_Str1,"d3dcolor",8);

        if (iVar3 == 0) {

          _Str1 = _Str1 + 8;

          local_d = local_d + 4;

          local_4 = 4;

        }

        else {

          iVar3 = _strnicmp(_Str1,"ubyte4",6);

          if (iVar3 == 0) {

            local_d = local_d + 4;

            local_4 = 5;

            _Str1 = _Str1 + 7;

          }

          else {

            iVar3 = _strnicmp(_Str1,"short",5);

            if (iVar3 == 0) {

              iVar3 = atoi(_Str1 + 5);

              if (iVar3 == 2) {

                local_4 = 6;

                goto LAB_0074f8f6;

              }

              if (iVar3 == 4) {

                local_d = local_d + 8;

                local_4 = 7;

              }

              goto switchD_0074f846_default;

            }

          }

        }

      }

      iVar3 = *(int *)(param_2 + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_2 + 0xc) - iVar3 >> 3) <= (uint)(*(int *)(param_2 + 8) - iVar3 >> 3)

         )) {

        FUN_00445fa0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&local_8);

      }

      else {

        iVar3 = *(int *)(param_2 + 8);

        FUN_0045f220(param_2);

        *(int *)(param_2 + 8) = iVar3 + 8;

      }

      for (; ((cVar1 = *_Str1, cVar1 == ' ' || (cVar1 == ',')) ||

             ((cVar1 == '\n' || (cVar1 == '\r')))); _Str1 = _Str1 + 1) {

        if (cVar1 == '\0') goto LAB_0074f9ab;

      }

    }

    else {

      iVar3 = _strnicmp(_Str1,"position",8);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 8;

        local_2 = 0;

        goto LAB_0074f7fb;

      }

      iVar3 = _strnicmp(_Str1,"normal",6);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 6;

        local_2 = 3;

        goto LAB_0074f7fb;

      }

      iVar3 = _strnicmp(_Str1,"tex",3);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 3;

        local_2 = 5;

        goto LAB_0074f7fb;

      }

      iVar3 = _strnicmp(_Str1,"binormal",8);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 8;

        local_2 = 7;

        local_1 = 0;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"tangent",7);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 7;

        local_2 = 6;

        local_1 = 0;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"bitangent",9);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 9;

        local_2 = 6;

        local_1 = 1;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"psize",5);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 5;

        local_2 = 4;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"blendweight",0xb);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 0xb;

        local_2 = 1;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"blendindices",0xc);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 0xc;

        local_2 = 2;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"diffuse",7);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 7;

        local_2 = 10;

        local_1 = 0;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"specular",8);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 8;

        local_2 = 10;

        local_1 = 1;

        goto LAB_0074f808;

      }

      iVar3 = _strnicmp(_Str1,"color",5);

      if (iVar3 == 0) {

        _Str1 = _Str1 + 5;

        local_2 = 10;

        goto LAB_0074f7fb;

      }

      iVar3 = _strnicmp(_Str1,";",1);

      if (iVar3 != 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"

                       ,0x771,3,"Unknown usage in Vertex Decleration.");

        return 0xffffffff;

      }

      _Str1 = (char *)FUN_0074eeb0();

    }

  } while (_Str1 != (char *)0x0);

LAB_0074f9ab:

  FUN_00747180();

  return 0;

}
