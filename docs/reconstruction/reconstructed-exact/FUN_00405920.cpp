// =============================================================================
// FUN_00405920  (machine twin of CsSList_RemoveFirstByPredicate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00405920
// Address:   0x00405920  (autoassault.exe, image base 0x400000)
// System:    client containers / CS-protected singly-linked list
// Generated: 2026-08-05 MEGA-042 dual refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical: CsSList_RemoveFirstByPredicate_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
struct CRITICAL_SECTION {};
inline void EnterCriticalSection(CRITICAL_SECTION*) {}
inline void LeaveCriticalSection(CRITICAL_SECTION*) {}
inline long InterlockedDecrement(long volatile* p) { return --(*p); }
typedef long LONG;
#endif

// Ghidra signature shape (param names from decompiler).
// ABI sealed: thiscall ECX=list; stack pred*, cookie; RET 8.
void __thiscall FUN_00405920(int param_1, void* param_2, std::uint32_t param_3)
{
  std::uint32_t* puVar1;
  std::uint32_t* puVar2;
  std::uint32_t* puVar3;
  char cVar4;

  EnterCriticalSection((CRITICAL_SECTION*)(param_1 + 0x28));
  EnterCriticalSection((CRITICAL_SECTION*)(param_1 + 0x10));
  puVar3 = *(std::uint32_t**)(param_1 + 4);
  puVar2 = (std::uint32_t*)0x0;
  do {
    puVar1 = puVar3;
    if (puVar1 == (std::uint32_t*)0x0) {
LAB_0040599d:
      LeaveCriticalSection((CRITICAL_SECTION*)(param_1 + 0x10));
      LeaveCriticalSection((CRITICAL_SECTION*)(param_1 + 0x28));
      return;
    }
    // (*pred)(payload, cookie)
    cVar4 = ((char(__cdecl*)(std::uint32_t, std::uint32_t))param_2)(puVar1[1], param_3);
    if (cVar4 != '\0') {
      if (puVar2 == (std::uint32_t*)0x0) {
        *(std::uint32_t*)(param_1 + 4) = puVar1[2];
      } else {
        puVar2[2] = puVar1[2];
      }
      if (puVar1[2] == 0) {
        *(std::uint32_t**)(param_1 + 8) = puVar2;
      }
      puVar1[1] = 0;
      // scalar deleting dtor thiscall: ECX=node, arg=1
      ((void(__thiscall*)(std::uint32_t*, int))*(void**)(*puVar1))(puVar1, 1);
      InterlockedDecrement((LONG*)(param_1 + 0xc));
      goto LAB_0040599d;
    }
    puVar3 = (std::uint32_t*)puVar1[2];
    puVar2 = puVar1;
  } while (true);
}
