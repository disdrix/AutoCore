// =============================================================================
// Client_LoadKeymapIni
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f710
// Address:   0x0092f710–0x0092f91a  (523 B / 0x20B; pad CC @ 0x0092f91b)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; MEGA-022 OWN-ONLY dual seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + asm ABI corrections.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN. Terminal: false.
//
// Purpose:  Load keymap.ini into client ActionMap (client+0x116c).
//           Missing file → write default keymap.ini from current ActionMap.
//           Present → parse Description=primary;alt lines, resolve description
//           to (mode,slot), apply primary (BL=0) then alt (BL=1) binds.
//
// Convention (asm-sealed):
//   stack0 = client* (void*)
//   void return
//   RET 4
//
// Product surface:
//   fopen("keymap.ini","r") @ 0x00a2e624 / 0x00a152e4
//   InitInstance plate: "@@CoInitializeEx, Version, Ini, Keymap, colors"
//   Writer header (FUN_007f9480): "AUTO ASSAULT KEY MAPPING FILE"
//
// Related (evidence; not dualled here unless noted):
//   Client_InitInstance           0x0094a6a0  sole caller (dualed)
//   ActionMap_TrySetSlotBind      0x007f72e0  dualed — BL lane apply
//   FUN_007f9230                  find slot by description (mode 0..3)
//   FUN_007f9480                  write default keymap.ini
//   FUN_0092db30                  parse key token (+ modifiers)
//   Client_InitDefaultKeybinds    0x007f8720  dualed defaults peer
//
// Retired scaffolds:
//   Named_keymap_ini.cpp
//   Named_CalleeOf_Named_Client_InitInstance_0092f710.cpp
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// External callees (Ghidra names retained where undualed).
extern "C" {
  // ActionMap find-by-description: EAX=mode, ECX=map, stack=desc → AL slot or 0
  unsigned FUN_007f9230(const char* desc /* + ECX map, EAX mode */);
  // Write default keymap.ini: EAX=path, stack=ActionMap*
  unsigned FUN_007f9480(void* actionMap /* + EAX path */);
  // Parse key name token: EAX=string, EBX=&mod_out, stack=&key_out
  void FUN_0092db30(uint32_t* key_out /* + EAX str, EBX mod* */);
  // Dualed: AL=slot BL=lane SI=key DX=mod; stack map + mode; RET 8; AL success
  uint8_t ActionMap_TrySetSlotBind(uint8_t slotIndex, uint8_t bindLane,
                                   uint16_t keyCode, uint16_t modCode,
                                   void* actionMap, uint32_t mode);
}

// ---------------------------------------------------------------------------
// Client_LoadKeymapIni
// ---------------------------------------------------------------------------
// Clean reconstruction: control flow matches raw/live decompile; ABI and the
// primary/alt BL lane pair are corrected from disassemble_function.
// Register-mediated helper ABIs are documented; C formals approximate them.
// ---------------------------------------------------------------------------
void Client_LoadKeymapIni(void* client /* stack0; RET 4 */)
{
  char line[2048];
  char primary[512];
  char alt[512];
  // Stack copies of DAT_00a152dc / DAT_00a152e0
  char comment_delim[3] = {'/', '/', '\0'};
  char field_delim[3]   = {'=', ';', '\0'};

  FILE* file = std::fopen("keymap.ini", "r");
  if (file == nullptr) {
    // Asm: MOV EAX, "keymap.ini"; PUSH client+0x116c; CALL FUN_007f9480
    void* actionMap = static_cast<char*>(client) + 0x116c;
    FUN_007f9480(actionMap);
    return;
  }

  char* tok = std::fgets(line, 0x800, file);
  while (tok != nullptr) {
    // Strip // comments
    char* cut = std::strstr(line, comment_delim);
    if (cut != nullptr) {
      *cut = '\0';
    }

    tok = std::strtok(line, field_delim);
    if (tok != nullptr) {
      // Asm: strlen >= 2 (CMP EAX,2 / JC skip)
      const size_t descLen = std::strlen(tok);
      if (descLen >= 2) {
        void* actionMap = static_cast<char*>(client) + 0x116c;
        int mode = 0;
        unsigned slot = 0;
        do {
          // EAX=mode, ECX=actionMap, stack=description
          slot = FUN_007f9230(tok) & 0xffu;
          if (slot != 0) {
            break;
          }
          ++mode;
        } while (mode < 4);

        if (mode != 4 && slot != 0) {
          tok = std::strtok(nullptr, field_delim);
          if (tok != nullptr) {
            std::strncpy(primary, tok, 0x1ff);
            primary[0x1ff] = '\0'; // behavior-preserving bound; retail uses 0x1ff copy
            alt[0] = '\0';
            tok = std::strtok(nullptr, field_delim);
            if (tok != nullptr) {
              std::strncpy(alt, tok, 0x1ff);
              alt[0x1ff] = '\0';
            }

            uint32_t key = 0;
            uint32_t mod = 0;

            // Primary lane BL=0
            FUN_0092db30(&key /* EAX=primary, EBX=&mod */);
            ActionMap_TrySetSlotBind(static_cast<uint8_t>(slot),
                                     /*lane*/ 0,
                                     static_cast<uint16_t>(key),
                                     static_cast<uint16_t>(mod),
                                     actionMap,
                                     static_cast<uint32_t>(mode));

            // Alt lane BL=1
            key = 0;
            mod = 0;
            FUN_0092db30(&key /* EAX=alt */);
            ActionMap_TrySetSlotBind(static_cast<uint8_t>(slot),
                                     /*lane*/ 1,
                                     static_cast<uint16_t>(key),
                                     static_cast<uint16_t>(mod),
                                     actionMap,
                                     static_cast<uint32_t>(mode));
          }
        }
      }
    }

    tok = std::fgets(line, 0x800, file);
  }

  std::fclose(file);
}
