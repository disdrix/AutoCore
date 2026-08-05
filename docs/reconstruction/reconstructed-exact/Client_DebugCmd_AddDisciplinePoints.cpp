// =============================================================================
// Client_DebugCmd_AddDisciplinePoints
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e530
// Address:   0x0094e530–0x0094e617 (231 B / 0xE7); ret 8
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_0094e530
// System:    missions-progression / client debug slash
// Dual:      2026-07-29 W31-T OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = Client*; stack = (unused, delim*); returns 1 fail / 0 ok; ret 8
//
// Slash command: "adddisciplinepoints"
// Help:          "Set discipline [x] to [y], [1] to set max as well"
// Registration:  Client_RegisterDebugSlashCommands (imm handler @ 0x00959294)
//
// CF (machine-sealed):
//   1. strtok continue → key (atoi); missing → 1
//   2. strtok continue → amount (atoi); missing → 1
//   3. optional strtok → flag = (atoi == 1)
//   4. char = *(client+0xe98); null → 1
//   5. CVOGCharacter_SetMissionCounter(char, key, amount)   // +0x14 absolute (W30-I)
//   6. if flag: FUN_0052ade0(char, key, amount)             // +0x10 max + dirty 0x40
//   7. if ui=*(client+0x1074) && ui->vtbl+0x3d8(): ui->vtbl+0x448()
//   8. return 0

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Nested (sealed elsewhere / not OWN)
extern "C" void __thiscall CVOGCharacter_SetMissionCounter(
    void *character /*ECX*/, uint32_t key, int32_t value); // 0x005305b0
extern "C" void __thiscall FUN_0052ade0(
    void *character /*ECX*/, uint32_t key, int32_t value); // set +0x10 clamp to +0x14

extern "C" uint32_t __thiscall Client_DebugCmd_AddDisciplinePoints(
    void *client /*ECX*/,
    void * /*unused_stack0*/,
    char *delim)
{
  char *tok = strtok(nullptr, delim);
  if (tok == nullptr) {
    return 1;
  }
  int key = atoi(tok);

  tok = strtok(nullptr, delim);
  if (tok == nullptr) {
    return 1;
  }
  int amount = atoi(tok);

  bool set_max = false;
  tok = strtok(nullptr, delim);
  if (tok != nullptr) {
    set_max = (atoi(tok) == 1);
  }

  void *character = *(void **)((uint8_t *)client + 0xe98);
  if (character == nullptr) {
    return 1;
  }

  CVOGCharacter_SetMissionCounter(character, (uint32_t)key, amount);
  if (set_max) {
    FUN_0052ade0(character, (uint32_t)key, amount);
  }

  void **ui = *(void ***)((uint8_t *)client + 0x1074);
  if (ui != nullptr) {
    using VFn0 = char(__thiscall *)(void *);
    using VFn1 = void(__thiscall *)(void *);
    void **vtbl = (void **)*ui;
    if (((VFn0)vtbl[0x3d8 / 4])(ui) != 0) {
      ((VFn1)vtbl[0x448 / 4])(ui);
    }
  }

  return 0;
}
