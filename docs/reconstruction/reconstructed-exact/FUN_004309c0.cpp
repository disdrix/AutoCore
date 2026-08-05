// =============================================================================
// StdMap_StringKey_InsertOrFind  (Ghidra: FUN_004309c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004309c0
// Address:   0x004309c0 – 0x00430a96  (autoassault.exe, image base 0x400000)
// System:    stl-map
// Generated: 2026-07-29 W21-P dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + register ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: reconstructed-exact/StdMap_StringKey_InsertOrFind.cpp
// =============================================================================

// PURPOSE:
//   MSVC map<string,T> insert-or-find. Walk by basic_string operator<;
//   miss → FUN_00430b60; hit → {existing, inserted=0}.

struct InsertPair {
  void*   it;
  unsigned char inserted;
};

extern InsertPair* FUN_00430b60(void* parentHint, int addleft, const void* keyString);
extern void FUN_004313d0(void** pNode);
extern bool basic_string_operator_lt(const void* a, const void* b);

// ABI: stack map*; EAX key*; EBX out*; return EBX; RET 4
InsertPair* FUN_004309c0(void* map /*stack*/)
{
  void* keyString /*EAX*/ = 0;   // filled by caller convention
  InsertPair* out /*EBX*/ = 0;   // filled by caller convention

  void* header = *(void**)((char*)map + 4);
  void* cur = *(void**)((char*)header + 4);
  void* parent = header;
  bool goLeft = true;

  while (*(char*)((char*)cur + 0x2D) == 0) {
    goLeft = basic_string_operator_lt(keyString, (char*)cur + 0x0C);
    parent = cur;
    cur = goLeft ? *(void**)cur : *(void**)((char*)cur + 8);
  }

  if (goLeft) {
    if (parent == **(void***)((char*)map + 4)) {
      InsertPair* r = FUN_00430b60(parent, 1, keyString);
      out->it = r->it;
      out->inserted = 1;
      return out;
    }
    FUN_004313d0(&parent);
  }

  if (basic_string_operator_lt((char*)parent + 0x0C, keyString)) {
    InsertPair* r = FUN_00430b60(parent, goLeft ? 1 : 0, keyString);
    out->it = r->it;
    out->inserted = 1;
    return out;
  }

  out->it = parent;
  out->inserted = 0;
  return out;
}
