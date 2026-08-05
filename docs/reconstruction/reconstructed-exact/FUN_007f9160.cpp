// =============================================================================
// ActionMap_FormatSlotBindDisplay
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9160
// Address:   0x007f9160–0x007f9227  (autoassault.exe, image base 0x400000)
// System:    input-drive-control / UI keybind display
// Generated: 2026-07-23 scaffold; dual seal refine 2026-08-04 WQ7R-G
// Exactness: Behavior-preserving rewrite from decompile + entry/body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Purpose:  Format one ActionMap slot bind (primary or alt lane) as
//           "KEY" or "MOD+KEY" into a caller buffer.
//
// Convention (asm-sealed):
//   EAX = ActionMap* base
//   ECX = char* outBuf
//   EDX = mode (0..3)
//   stack0 = slotIndex (u8)
//   stack1 = lane (0 = primary key/mod, nonzero = alt)
//   return AL = 1 success / 0 fail; RET 8
//
// GetSlot (FUN_007f7240): returns pointer at primary-key field:
//   mode0 base+6, mode1 +0x10A, mode2 +0x242, mode3 +0x1AA2; + index*0x34
// Relative: key0@+0, key1@+2, mod0@+0x2A, mod1@+0x2C
//
// Related:
//   Input_KeyCodeToDisplayName   0x007f5120
//   ActionMap_TrySetSlotBind     0x007f72e0
//   FUN_007f7240 GetSlotPtr      0x007f7240
//   reviews/A|B_aa_007f9160_ActionMap_FormatSlotBindDisplay.md
// =============================================================================

/*
 * Behavioral notes:
 * - Display order is MOD then KEY when both present (e.g. SHIFT+A).
 * - Separator is u16 at DAT_00a2e620 = '+' '\0'.
 * - Fail if GetSlot null, out null, or both codes zero.
 * - Client UI only — no network.
 */

#include <stdint.h>
#include <string.h>

extern void* ActionMap_GetSlotPtr(void* actionMap, uint32_t mode, uint8_t index); // FUN_007f7240
extern const char* Input_KeyCodeToDisplayName(uint16_t keyCode /* DX */);         // FUN_007f5120

static void append_cstr(char* dst, const char* src)
{
  size_t n = strlen(dst);
  // retail uses byte/dword copy loops; strcpy-equivalent
  strcpy(dst + n, src);
}

uint8_t ActionMap_FormatSlotBindDisplay(
    char*    outBuf,      // ECX
    uint8_t  slotIndex,   // stack0
    uint8_t  lane,        // stack1
    void*    actionMap,   // EAX
    uint32_t mode)        // EDX
{
  int16_t* slot = (int16_t*)ActionMap_GetSlotPtr(actionMap, mode, slotIndex);
  if (slot == nullptr || outBuf == nullptr) {
    return 0;
  }

  outBuf[0] = '\0';

  uint16_t key;
  uint16_t mod;
  if (lane == 0) {
    key = (uint16_t)slot[0];
    mod = (uint16_t)slot[0x15]; // +0x2A bytes
  } else {
    key = (uint16_t)slot[1];    // +2
    mod = (uint16_t)slot[0x16]; // +0x2C
  }

  if (key == 0 && mod == 0) {
    return 0;
  }

  if (key != 0 && mod == 0) {
    append_cstr(outBuf, Input_KeyCodeToDisplayName(key));
    return 1;
  }

  // mod present (key may be zero — edge yields "MOD+" + empty)
  append_cstr(outBuf, Input_KeyCodeToDisplayName(mod));
  append_cstr(outBuf, "+");
  append_cstr(outBuf, Input_KeyCodeToDisplayName(key));
  return 1;
}
