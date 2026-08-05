// =============================================================================
// FUN_009864e0  (twin of GfxVertexBufferFactory_PreResetReleaseAll_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009864e0
// Address:   0x009864e0–0x00986560 inclusive (129 B / 0x81)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W38-AD (2026-08-04)
// Exactness: Behavior-preserving rewrite; Ghidra name twin.
// =============================================================================

extern "C" void FUN_007465c0(void /* ESI */);

void FUN_009864e0(/* EAX */ void *factory)
{
  auto *sentinel = *reinterpret_cast<void ***>(reinterpret_cast<char *>(factory) + 0x14);
  auto *node = *reinterpret_cast<void **>(sentinel);

  while (node != sentinel) {
    if ((*(unsigned char *)(reinterpret_cast<char *>(node) + 0xE) & 0x28) == 0) {
      auto *range_end = *reinterpret_cast<char **>(reinterpret_cast<char *>(node) + 0x18);
      for (auto *slot = *reinterpret_cast<char **>(reinterpret_cast<char *>(node) + 0x14);
           slot != range_end;
           slot += 0x20) {
        void *vb = *reinterpret_cast<void **>(slot);
        (void)vb;
        FUN_007465c0();
      }
    }

    if (*(char *)(reinterpret_cast<char *>(node) + 0x21) == 0) {
      auto *right = *reinterpret_cast<void **>(reinterpret_cast<char *>(node) + 8);
      if (*(char *)(reinterpret_cast<char *>(right) + 0x21) == 0) {
        auto *p = right;
        auto *left = *reinterpret_cast<void **>(p);
        while (*(char *)(reinterpret_cast<char *>(left) + 0x21) == 0) {
          p = left;
          left = *reinterpret_cast<void **>(p);
        }
        node = p;
      } else {
        auto *p = *reinterpret_cast<void **>(reinterpret_cast<char *>(node) + 4);
        auto *cur = node;
        while (*(char *)(reinterpret_cast<char *>(p) + 0x21) == 0 &&
               cur == *reinterpret_cast<void **>(reinterpret_cast<char *>(p) + 8)) {
          cur = p;
          p = *reinterpret_cast<void **>(reinterpret_cast<char *>(p) + 4);
        }
        node = p;
      }
    }
  }
}
