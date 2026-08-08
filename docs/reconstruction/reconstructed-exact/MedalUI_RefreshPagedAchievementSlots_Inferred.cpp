// =============================================================================
// MedalUI_RefreshPagedAchievementSlots_Inferred  (aa_0090cbc0)
// -----------------------------------------------------------------------------
// Address:   0x0090cbc0–0x0090cdfe inclusive (575 B / 0x23F)
// Wave:      MEGA-063 OWN-ONLY dual 2026-08-05
// System:    missions-progression / Medal UI refresh (post force-complete)
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + callers/xrefs + assembly_context. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Rebuild the paged medal / achievement button grid on the MedalUI host:
//     1) Gate on DAT_00d1b6d8 manager + host vtbl[+0x3d8] visible.
//     2) Clear 24 slots (MedalUI_PrepClearButtonSlots_Inferred).
//     3) Count displayable medals (vector + hash).
//     4) Compute/clamp page index; update scrollbar widget.
//     5) Fill up to 24 buttons from current page (row stride 3):
//        vector entries flag=1, then hash-table entries flag=0, via
//        MedalUi_ApplyAchievementSlotButton (XML i_d_a_2d_btn_achievement.xml).
//
// ABI:
//   EAX = MedalUI host*. No stack formals. void. Bare RET (C3).
//   Callers seed EAX immediately before CALL/JMP (e.g. *(client+0x1034)+0x514).
//
// CALLERS (6 xrefs):
//   Client_RecvCompleteDynamicObjective @ 0081015f  (S2C 0x2070 force complete)
//   FUN_0080ce50 @ 0080ce87 (JMP tail)
//   FUN_0090d0d0 @ 0090d364 (achievements window)
//   FUN_00946c00 @ 009473a5
//   sites 0090ce73, 00952bb1
//
// RETIRED SCAFFOLD:
//   Named_VOG_DEBUG_STOP_0090cbc0 — misnamed from embedded HashError/VOG_DEBUG_STOP
//   strings used only on hash traversal lock faults; this is not the debug-stop helper.
// =============================================================================

#include <cstdint>

// Host layout fragments (not a full class def):
//   +0x000  vtbl*
//   +0x50c  pageIndex          (dword; decompiler index 0x143)
//   +0x540  buttonSlots[24]    // managed by prep/apply siblings
//   +0x5a0  scrollbarWidget*   (dword; decompiler index 0x168)
//   +0x5a4  maxPage            (dword; decompiler index 0x169)
//
// Manager (DAT_00d1b6d8) fragments:
//   +0x540  hash table*        (lock byte at hash+0x1d; head at +0x14)
//   +0x574  vector begin*      (dword*)
//   +0x578  vector end*

extern int DAT_00d1b6d8;
extern float g_flOne; // DAT / float 1.0f @ 0x00a0f2a0

// Sibling duals / shared helpers (names when sealed; Ghidra FUN_* otherwise)
extern "C" void FUN_0090c700(void);                 // MedalUI_PrepClearButtonSlots_Inferred (EDI=host)
extern "C" int  FUN_0090c810(void);                 // count; EBX=manager
extern "C" int  FUN_0051a0e0(unsigned id);          // resolve medal def (cdecl, +4)
extern "C" void FUN_0090c9a0(void);                 // apply slot; ESI=host, EBX=slot, stack medal+flag
extern "C" void FUN_007a4480(int level, const char* msg);

using VFunc0_RetChar = char(__thiscall*)(void* self);
using VFunc1_Int     = void(__thiscall*)(void* self, int arg);
using VFunc1_Float   = void(__thiscall*)(void* self, float arg);
using VFunc0_Void    = void(__thiscall*)(void* self);

// EAX-this custom convention (not MSVC thiscall ECX).
extern "C" void MedalUI_RefreshPagedAchievementSlots_Inferred(void /* EAX = host */)
{
  void* host;
  int manager;
  int filled;
  int count;
  int maxPage;
  int walkIndex;
  uint32_t* it;
  uint32_t* itEnd;
  int medal;
  int* hash;
  int node;
  int payload;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov host, eax
  }
#else
  host = nullptr; // non-MSVC rebuilds must pass host explicitly; retail ABI is EAX
#endif

  manager = DAT_00d1b6d8;
  if (manager == 0) {
    return;
  }

  {
    void** hostVtbl = *reinterpret_cast<void***>(host);
    char visible = reinterpret_cast<VFunc0_RetChar>(hostVtbl[0x3d8 / 4])(host);
    if (visible == 0) {
      return;
    }
  }

  // Prep: EDI = host (caller seeds via MOV EDI,ESI before CALL in retail)
#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov edi, host
    call FUN_0090c700
  }
#else
  FUN_0090c700();
#endif

  filled = 0;

  // Count: EBX = manager
#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov ebx, manager
    call FUN_0090c810
    mov count, eax
  }
#else
  count = FUN_0090c810();
#endif

  auto* hostDw = reinterpret_cast<int*>(host);
  // dword indices: 0x143 → +0x50c, 0x168 → +0x5a0, 0x169 → +0x5a4
  int& pageIndex = hostDw[0x143];
  int& maxPageField = hostDw[0x169];
  int* scrollbar = reinterpret_cast<int*>(hostDw[0x168]);

  if (count <= 0) {
    pageIndex = 0;
    if (scrollbar != nullptr) {
      void** sbVtbl = *reinterpret_cast<void***>(scrollbar);
      reinterpret_cast<VFunc1_Int>(sbVtbl[0x4 / 4])(scrollbar, 0);
    }
    return;
  }

  // maxPage = (count - 25) / 3 + 1  (signed; retail uses 0x55555556 magic)
  maxPage = (count - 0x19) / 3 + 1;
  maxPageField = maxPage;
  if (count <= 0x18) {
    maxPageField = 0;
    pageIndex = 0;
  } else if (pageIndex > maxPageField) {
    pageIndex = maxPageField;
  }

  if (scrollbar != nullptr) {
    void** sbVtbl = *reinterpret_cast<void***>(scrollbar);
    if (maxPageField == 0) {
      reinterpret_cast<VFunc1_Int>(sbVtbl[0xcc / 4])(scrollbar, 0);
    } else {
      reinterpret_cast<VFunc1_Int>(sbVtbl[0xcc / 4])(scrollbar, 1);
      reinterpret_cast<VFunc1_Float>(sbVtbl[0x460 / 4])(
          scrollbar, g_flOne / static_cast<float>(maxPageField));
    }
    reinterpret_cast<VFunc0_Void>(sbVtbl[0x34c / 4])(scrollbar);
  }

  it = *reinterpret_cast<uint32_t**>(manager + 0x574);
  itEnd = *reinterpret_cast<uint32_t**>(manager + 0x578);
  walkIndex = -1;

  // Loop A — vector medals, apply flag=1
  while (it != itEnd && filled < 0x18) {
    medal = FUN_0051a0e0(*it);
    if (medal != 0) {
      walkIndex += 1;
      if (walkIndex >= pageIndex * 3) {
        // Retail: PUSH 1; PUSH medal; MOV EBX,filled; ESI=host; CALL FUN_0090c9a0
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
        filled += 1;
      }
    }
    it += 1;
  }

  // Loop B — hash traverse for remaining slots, apply flag=0
  hash = *reinterpret_cast<int**>(manager + 0x540);
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(hash) + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(hash) + 0x1d) = 1;

  node = 0;
  while (filled < 0x18) {
    hash = *reinterpret_cast<int**>(manager + 0x540);
    if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(hash) + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (node == 0) {
      node = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(hash) + 0x14);
    } else {
      node = *reinterpret_cast<int*>(node + 0x14);
    }
    if (node == 0) {
      payload = 0;
    } else {
      payload = *reinterpret_cast<int*>(node + 8);
    }
    if (payload == 0) {
      break;
    }
    medal = FUN_0051a0e0(*reinterpret_cast<unsigned*>(payload + 0x100));
    if (medal != 0) {
      walkIndex += 1;
      if (walkIndex >= pageIndex * 3) {
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
        filled += 1;
      }
    }
  }

  hash = *reinterpret_cast<int**>(manager + 0x540);
  *reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(hash) + 0x1d) = 0;
}
