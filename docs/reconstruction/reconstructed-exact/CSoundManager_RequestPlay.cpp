// =============================================================================
// CSoundManager_RequestPlay  (probable product role; plate method name open)
// -----------------------------------------------------------------------------
// Stable ID: aa_00720670
// Address:   0x00720670  (autoassault.exe, image base 0x400000)
// Body:      0x00720670 – 0x0072071a  (ret 0xC8)
// Twin file: FUN_00720670.cpp
// System:    client audio / CSoundManager
// Generated: 2026-07-29 W18-G dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Singleton storage: DAT_00d20070 via CSoundManager_GetInstance (0x00720d40).
// Request size: 0xC8 (200) bytes — matches vector element stride in FUN_004804d0
// and NDSpecialFX list payload copies (0x32 dwords).
// mode @ +0xB8; compactFlag @ +0xBC of request.
// =============================================================================

#include <stdint.h>
#include <windows.h>

struct SoundPlayRequest {
  uint8_t data[0xC8];
};

// Accessors for sealed tail fields (remainder of POD open).
inline int SoundPlayRequest_Mode(const SoundPlayRequest *r) {
  return *(const int *)(r->data + 0xB8);
}
inline uint8_t SoundPlayRequest_CompactFlag(const SoundPlayRequest *r) {
  return r->data[0xBC];
}

extern "C" void __thiscall FUN_00720090(void *self);           // compact dead queue elems
extern "C" void __thiscall FUN_004804d0(void *vec, void *req); // push 200-byte element

extern "C" void __thiscall CSoundManager_RequestPlay(void *self /* ECX */,
                                                     SoundPlayRequest req /* stack */)
{
  const int mode = SoundPlayRequest_Mode(&req);
  const uint8_t compactFlag = SoundPlayRequest_CompactFlag(&req);

  EnterCriticalSection((LPCRITICAL_SECTION)((char *)self + 0x170));

  if (compactFlag != 0) {
    if (mode == 1) {
      FUN_00720090(self);
      *((uint8_t *)self + 0x13) = 1;
      goto enqueue;
    }
    if (mode == 2) {
      FUN_00720090(self);
      *((uint8_t *)self + 0x14) = 1;
      goto enqueue;
    }
  }

  if (mode == 1) {
    *((uint8_t *)self + 0x13) = 1;
  } else if (mode == 2) {
    *((uint8_t *)self + 0x14) = 1;
  } else if (mode == 5) {
    *((uint8_t *)self + 0x15) = 1;
  }

enqueue:
  FUN_004804d0((char *)self + 0x70, &req);
  LeaveCriticalSection((LPCRITICAL_SECTION)((char *)self + 0x170));
}
