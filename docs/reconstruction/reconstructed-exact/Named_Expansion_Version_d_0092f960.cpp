// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×9, while×1, for×1, return×1.
//  - Notable callees: sscanf×8, fgets×2, FUN_0092f960, fclose, fopen.
//  - Strings: "..\\versions.txt"; "Major_Version=%d;"; "Release_Version=%d;"; "Expansion_Version=%d;".
//  - Return sites: 1.

// =============================================================================
// Named_Expansion_Version_d_0092f960
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f960
// Address:   0x0092f960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Expansion_Version=%d;"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Expansion_Version_d_0092f960(void)



{

  FILE *_File;

  char *pcVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_424;

  uint32_t /* width from decompiler */ local_420 [8];

  char local_400 [1023];

  uint8_t local_1;

  

  local_420[0] = 0;

  local_420[1] = 0;

  local_420[2] = 0;

  local_420[3] = 0;

  local_420[4] = 0;

  local_420[5] = 0;

  local_420[6] = 0;

  local_420[7] = 0;

  _File = fopen("..\\versions.txt","r");

  if (_File != (FILE *)0x0) {

    pcVar1 = fgets(local_400,0x400,_File);

    while (pcVar1 != (char *)0x0) {

      local_1 = 0;

      iVar2 = sscanf(local_400,"Major_Version=%d;",&local_424);

      if (iVar2 == 0) {

        iVar2 = sscanf(local_400,"Release_Version=%d;",&local_424);

        if (iVar2 == 0) {

          iVar2 = sscanf(local_400,"Expansion_Version=%d;",&local_424);

          if (iVar2 == 0) {

            iVar2 = sscanf(local_400,"Episode_Version=%d;",&local_424);

            if (iVar2 == 0) {

              iVar2 = sscanf(local_400,"Build_Year=%d;",&local_424);

              if (iVar2 == 0) {

                iVar2 = sscanf(local_400,"Build_Month=%d;",&local_424);

                if (iVar2 == 0) {

                  iVar2 = sscanf(local_400,"Build_Day=%d;",&local_424);

                  if (iVar2 == 0) {

                    iVar2 = sscanf(local_400,"Build_Hour=%d;",&local_424);

                    if (iVar2 != 0) {

                      local_420[7] = local_424;

                    }

                  }

                  else {

                    local_420[6] = local_424;

                  }

                }

                else {

                  local_420[5] = local_424;

                }

              }

              else {

                local_420[4] = local_424;

              }

            }

            else {

              local_420[2] = local_424;

            }

          }

          else {

            local_420[1] = local_424;

          }

        }

        else {

          local_420[0] = local_424;

        }

      }

      else {

        local_420[3] = local_424;

      }

      pcVar1 = fgets(local_400,0x400,_File);

    }

    fclose(_File);

    puVar3 = local_420;

    puVar4 = &DAT_00b047e0;

    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

  }

  return;

}
