// =============================================================================
// FUN_0090cbc0  — twin of MedalUI_RefreshPagedAchievementSlots_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090cbc0
// Address:   0x0090cbc0–0x0090cdfe (575 B / 0x23F)
// Wave:      MEGA-063 OWN-ONLY dual 2026-08-05
// System:    missions-progression
// Exactness: Ghidra-name twin; prefer named clean for port notes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical: MedalUI_RefreshPagedAchievementSlots_Inferred
// Retired:   Named_VOG_DEBUG_STOP_0090cbc0
// =============================================================================

#include <cstdint>

extern int DAT_00d1b6d8;
extern float g_flOne;

extern "C" void FUN_0090c700(void);
extern "C" int  FUN_0090c810(void);
extern "C" int  FUN_0051a0e0(unsigned id);
extern "C" void FUN_0090c9a0(void);
extern "C" void FUN_007a4480(int level, const char* msg);

// Retail ABI: EAX = host*; void; bare RET
extern "C" void FUN_0090cbc0(void /* EAX = host */)
{
  // See MedalUI_RefreshPagedAchievementSlots_Inferred.cpp for full annotated port.
  // Control flow authority: raw aa_0090cbc0 + MEGA-063 disasm re-verify.

  void* host;
#if defined(_MSC_VER) && defined(_M_IX86)
  __asm { mov host, eax }
#else
  host = nullptr;
#endif

  int manager = DAT_00d1b6d8;
  if (manager == 0) return;

  void** vtbl = *reinterpret_cast<void***>(host);
  using V0c = char(__thiscall*)(void*);
  if (reinterpret_cast<V0c>(vtbl[0x3d8 / 4])(host) == 0) return;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov edi, host
    call FUN_0090c700
  }
#else
  FUN_0090c700();
#endif

  int filled = 0;
  int count;
#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov ebx, manager
    call FUN_0090c810
    mov count, eax
  }
#else
  count = FUN_0090c810();
#endif

  int* h = reinterpret_cast<int*>(host);
  if (count <= 0) {
    h[0x143] = 0;
    if (h[0x168] != 0) {
      void** sb = *reinterpret_cast<void***>(h[0x168]);
      using V1i = void(__thiscall*)(void*, int);
      reinterpret_cast<V1i>(sb[1])(reinterpret_cast<void*>(h[0x168]), 0);
    }
    return;
  }

  int maxPage = (count - 0x19) / 3 + 1;
  h[0x169] = maxPage;
  if (count <= 0x18) {
    h[0x169] = 0;
    h[0x143] = 0;
  } else if (h[0x143] > h[0x169]) {
    h[0x143] = h[0x169];
  }

  if (h[0x168] != 0) {
    void* sb = reinterpret_cast<void*>(h[0x168]);
    void** sbv = *reinterpret_cast<void***>(sb);
    using V1i = void(__thiscall*)(void*, int);
    using V1f = void(__thiscall*)(void*, float);
    using V0  = void(__thiscall*)(void*);
    if (h[0x169] == 0) {
      reinterpret_cast<V1i>(sbv[0xcc / 4])(sb, 0);
    } else {
      reinterpret_cast<V1i>(sbv[0xcc / 4])(sb, 1);
      reinterpret_cast<V1f>(sbv[0x460 / 4])(sb, g_flOne / static_cast<float>(h[0x169]));
    }
    reinterpret_cast<V0>(sbv[0x34c / 4])(sb);
  }

  uint32_t* it = *reinterpret_cast<uint32_t**>(manager + 0x574);
  uint32_t* itEnd = *reinterpret_cast<uint32_t**>(manager + 0x578);
  int walkIndex = -1;
  while (it != itEnd && filled < 0x18) {
    int medal = FUN_0051a0e0(*it);
    if (medal != 0) {
      walkIndex++;
      if (walkIndex >= h[0x143] * 3) {
#if defined(_MSC_VER) && defined(_M_IX86)
        __asm {
          mov esi, host
          mov ebx, filled
          push 1
          push medal
          call FUN_0090c9a0
        }
#else
        FUN_0090c9a0();
#endif
        filled++;
      }
    }
    it++;
  }

  int* hash = *reinterpret_cast<int**>(manager + 0x540);
  if (*(char*)((uint8_t*)hash + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(char*)((uint8_t*)hash + 0x1d) = 1;

  int node = 0;
  while (filled < 0x18) {
    hash = *reinterpret_cast<int**>(manager + 0x540);
    if (*(char*)((uint8_t*)hash + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    node = (node == 0) ? *(int*)((uint8_t*)hash + 0x14) : *(int*)(node + 0x14);
    int payload = (node == 0) ? 0 : *(int*)(node + 8);
    if (payload == 0) break;
    int medal = FUN_0051a0e0(*(unsigned*)(payload + 0x100));
    if (medal != 0) {
      walkIndex++;
      if (walkIndex >= h[0x143] * 3) {
#if defined(_MSC_VER) && defined(_M_IX86)
        __asm {
          mov esi, host
          mov ebx, filled
          push 0
          push medal
          call FUN_0090c9a0
        }
#else
        FUN_0090c9a0();
#endif
        filled++;
      }
    }
  }

  hash = *reinterpret_cast<int**>(manager + 0x540);
  *(char*)((uint8_t*)hash + 0x1d) = 0;
}
