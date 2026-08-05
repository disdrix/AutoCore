// =============================================================================
// AssManager_ReleaseOwnedResolvers_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007b65d0
// Address:   0x007b65d0  (autoassault.exe, image base 0x400000)
// System:    assManager / asset resolver teardown
// Generated: 2026-07-29 W29-D from live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Destructor body for an object that owns two optional resolver interfaces
//   at +0x08 and +0x0c. Removes each from the global assManager resolver
//   GuardedVector (and prunes a related string vector on arm A), scalar-deletes
//   the interfaces, and nulls the slots.
//
// ABI (bytes):
//   this in **EBX**; no stack formals; plain ret.
//   Body: 0x007b65d0–0x007b66a3 exclusive (211 B)
//
// STRINGS:
//   "C:\vog\1_code\palantir\palantir\assets\assManager.cpp" @ 0x00a9e930
//   "Removing resolver not found" @ 0x00a9e888
//   line 0x27b, severity 3
//

#include <cstdint>

struct IResolverVtable {
  void(__thiscall* ScalarDeletingDtor)(void* self, uint32_t flags);
};

struct IResolver {
  IResolverVtable* vtbl;
};

struct AssManagerResolverEntry {
  void* vtbl;           // +0x00  set by dtor wrappers
  uint32_t pad04;       // +0x04  not touched here
  IResolver* resolverA; // +0x08
  IResolver* resolverB; // +0x0c
};

struct StringVecShell {
  void* pad0;
  uint8_t* begin; // +0x04
  uint8_t* end;   // +0x08
  // element size 0x1c (std::string bag)
};

// Globals (retail)
extern "C" void* DAT_00d1f058; // assManager host*
extern "C" StringVecShell* DAT_00d1f1fc;

// Unowned callees
extern "C" void FUN_00423e00(void); // ECX=manager; key likely EAX
extern "C" uint8_t __cdecl FUN_0043e5b0(int* key); // EAX=GuardedVector container
extern "C" uint8_t __stdcall FUN_0043c550(int* key); // ESI=container; EraseFirstEqual
extern "C" void __cdecl FUN_0044d4e0(StringVecShell* v, int* out, uint8_t* at);
extern "C" void vog_LogMessage(const char* file, int line, int sev, const char* msg);

// Retail: EBX=this
extern "C" void AssManager_ReleaseOwnedResolvers_Inferred(AssManagerResolverEntry* self /*EBX*/)
{
  if (self->resolverA != nullptr) {
    // ECX = *DAT_00d1f058; EAX remains resolverA at call in retail
    FUN_00423e00();
    if (self->resolverA != nullptr) {
      self->resolverA->vtbl->ScalarDeletingDtor(self->resolverA, 1);
    }
    self->resolverA = nullptr;

    // Up to 20 first-element erases on *DAT_00d1f1fc (elem 0x1c)
    int remain = 0x14;
    do {
      StringVecShell* v = DAT_00d1f1fc;
      uint8_t* begin = v->begin;
      if (begin != nullptr) {
        int count = static_cast<int>((v->end - begin) / 0x1c);
        if (count != 0) {
          int tmp = count;
          FUN_0044d4e0(v, &tmp, begin);
        }
      }
      --remain;
    } while (remain != 0);
  }

  int key = reinterpret_cast<int>(self->resolverB);
  if (key != 0) {
    // ESI = *DAT_00d1f058 + 0x58  (GuardedVector); EAX = ESI for contains
    // FUN_0043e5b0 / FUN_0043c550 consume &key
    uint8_t found = FUN_0043e5b0(&key);
    if (found == 0) {
      vog_LogMessage(
          "C:\\vog\\1_code\\palantir\\palantir\\assets\\assManager.cpp",
          0x27b,
          3,
          "Removing resolver not found");
    } else {
      FUN_0043c550(&key); // GuardedVector_EraseFirstEqual
    }
    if (self->resolverB != nullptr) {
      self->resolverB->vtbl->ScalarDeletingDtor(self->resolverB, 1);
    }
    self->resolverB = nullptr;
  }
}
