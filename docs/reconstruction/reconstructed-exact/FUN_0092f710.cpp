// =============================================================================
// FUN_0092f710  (machine twin of Client_LoadKeymapIni)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f710
// Address:   0x0092f710  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; MEGA-022 dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Prefer Client_LoadKeymapIni.cpp for named plate + ABI notes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: keymap.ini loader — see Client_LoadKeymapIni.cpp
// Stable ID: aa_0092f710
// Embedded strings:
//   - "keymap.ini"
// Delimiters: DAT_00a152dc="//", DAT_00a152e0="=;"
// ABI: stack client*; RET 4; ActionMap at client+0x116c
// Caller: Client_InitInstance (FUN_0094a6a0) @ 0x0094a83b

#include <cstdint>
#include <cstdio>
#include <cstring>

extern "C" {
  unsigned FUN_007f9230(const char* desc);
  unsigned FUN_007f9480(void* actionMap);
  void FUN_0092db30(uint32_t* key_out);
  uint8_t FUN_007f72e0(/* register-mediated ActionMap_TrySetSlotBind */);
}

void FUN_0092f710(int param_1)
{
  char cVar1;
  FILE* _File;
  char* pcVar2;
  char* pcVar3;
  int iVar4;
  uint16_t local_c18; // "=;" lo
  uint8_t  local_c16; // "=;" hi/null
  uint32_t local_c14;
  uint16_t local_c10; // "//" lo
  uint8_t  local_c0e; // "//" hi/null
  uint     local_c08;
  FILE*    local_c04;
  char     local_c00[512];
  char     local_a00[512];
  char     local_800[2048];

  _File = fopen("keymap.ini", "r");
  local_c04 = _File;
  if (_File == (FILE*)0x0) {
    // Asm: EAX = "keymap.ini"; PUSH param_1+0x116c
    FUN_007f9480((void*)(param_1 + 0x116c));
    return;
  }
  local_c16 = /* DAT_00a152e2 */ 0;
  local_c18 = /* DAT_00a152e0 */ 0x3b3d; // "=;"
  local_c10 = /* DAT_00a152dc */ 0x2f2f; // "//"
  local_c0e = /* DAT_00a152de */ 0;
  pcVar2 = fgets(local_800, 0x800, _File);
  do {
    if (pcVar2 == (char*)0x0) {
      fclose(_File);
      return;
    }
    pcVar2 = strstr(local_800, (char*)&local_c10);
    if (pcVar2 != (char*)0x0) {
      *pcVar2 = '\0';
    }
    local_c14 = 0;
    pcVar2 = strtok(local_800, (char*)&local_c18);
    if (pcVar2 != (char*)0x0) {
      pcVar3 = pcVar2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      // strlen >= 2
      if (1 < (unsigned)((int)pcVar3 - (int)(pcVar2 + 1))) {
        iVar4 = 0;
        do {
          // EAX=iVar4 mode; ECX=param_1+0x116c
          local_c08 = FUN_007f9230(pcVar2);
          local_c08 = local_c08 & 0xff;
          if (local_c08 != 0) break;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 4);
        _File = local_c04;
        if (((iVar4 != 4) && (local_c08 != 0)) &&
            (pcVar2 = strtok((char*)0x0, (char*)&local_c18), _File = local_c04,
             pcVar2 != (char*)0x0)) {
          strncpy(local_a00, pcVar2, 0x1ff);
          local_c00[0] = '\0';
          pcVar2 = strtok((char*)0x0, (char*)&local_c18);
          if (pcVar2 != (char*)0x0) {
            strncpy(local_c00, pcVar2, 0x1ff);
          }
          // Primary BL=0 then alt BL=1 (asm-sealed; decomp lost BL)
          FUN_0092db30(&local_c14);
          FUN_007f72e0(); // ActionMap_TrySetSlotBind primary
          FUN_0092db30(&local_c14);
          FUN_007f72e0(); // ActionMap_TrySetSlotBind alt
          _File = local_c04;
        }
      }
    }
    pcVar2 = fgets(local_800, 0x800, _File);
  } while (true);
}
