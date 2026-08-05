// =============================================================================
// NDUIWindow_ReloadInterface
// -----------------------------------------------------------------------------
// Stable ID: aa_00792980
// Address:   0x00792980 – 0x00792a41  (autoassault.exe, image base 0x400000)
// System:    client UI / NDUI chrome leaf
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A|B_aa_00792980_NDUIWindow_ReloadInterface.md — accept-with-gaps
// =============================================================================

/*
 * Behavioral notes:
 * - Always calls NDUIWindow_LoadInterfaceFile(path) first (path may be null).
 * - Clears companion dwords this+0x4B8 / +0x4BC; releases owned sub-object at +0x4B4
 *   via virtual call with flag 1, then nulls the pointer.
 * - Only when path == null: if vtbl[+0x3d8]() and hash at +0x4C0 non-null, lock-traverse
 *   the hash and call each child vtbl[+0x28](0), unlock, then vtbl[+0x34c]().
 * - Dword indices in decompiler: [0x12d..0x130] == byte offs +0x4B4..+0x4C0.
 * - LoadInterfaceFile body is out of unit (0x007b0ef0).
 * - Runtime / differential verification: OPEN.
 */

// Forward decls (Ghidra names; bodies elsewhere)
void __thiscall NDUIWindow_LoadInterfaceFile(void* this_, const char* path);
void FUN_00411e10(void);   // hash lock for traversal (Probable)
void FUN_007a4480(int level, const char* msg);

void __thiscall NDUIWindow_ReloadInterface(void* this_, const char* pathOrNull)
{
  int* self = (int*)this_;

  NDUIWindow_LoadInterfaceFile(this_, pathOrNull);

  // Companion slots zeroed before releasing cache
  self[0x12e] = 0;  // this+0x4B8
  self[0x12f] = 0;  // this+0x4BC

  if ((void*)self[0x12d] != nullptr) {  // this+0x4B4
    // MSVC-style virtual release / deleting-dtor with flag 1
    void** cached = (void**)self[0x12d];
    ((void (*)(void*, int))**cached)(cached, 1);
  }
  self[0x12d] = 0;

  if (pathOrNull != nullptr) {
    return;
  }

  // Null path: optional hide-all children via hash at this+0x4C0
  char mayWalk = (*(char (**)(void*))(*(int*)self + 0x3d8))();
  if (mayWalk != 0 && self[0x130] != 0) {
    int iVar4 = 0;
    FUN_00411e10();
    while (true) {
      int hash = self[0x130];
      if (*(char*)(hash + 0x1d) == 0) {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      if (iVar4 == 0) {
        iVar4 = *(int*)(hash + 0x14);
      } else {
        iVar4 = *(int*)(iVar4 + 0x14);
      }
      int* child;
      if (iVar4 == 0) {
        child = nullptr;
      } else {
        child = *(int**)(iVar4 + 8);
      }
      if (child == nullptr) {
        break;
      }
      (*(void (**)(void*, int))(*child + 0x28))(child, 0);
    }
    *(unsigned char*)(self[0x130] + 0x1d) = 0;
    (*(void (**)(void*))(*(int*)self + 0x34c))();
  }
}
