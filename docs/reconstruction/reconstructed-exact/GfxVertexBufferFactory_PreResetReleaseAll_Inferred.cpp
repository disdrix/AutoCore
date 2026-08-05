// =============================================================================
// GfxVertexBufferFactory_PreResetReleaseAll_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009864e0
// Address:   0x009864e0–0x00986560 inclusive (129 B / 0x81)
// Module:    autoassault.exe (image base 0x400000)
// System:    client / gfxVertexBufferFactory pre-reset (Device Reset shutdown)
// Wave:      W38-AD (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ESI fix.
// Bit-for-bit / runtime / diff: OPEN (no Launcher).
// =============================================================================
//
// PURPOSE:
//   Walk VB factory tree (sentinel @ factory+0x14). For each non-flagged node,
//   iterate 0x20-byte slots [node+0x14, node+0x18) and release each GfxDeviceVB
//   via FUN_007465c0 (unlock-all + COM Release + stats).
//   Sole caller: GfxDevice Device Reset; EAX = *(GfxDevice+0x74C).
//
// ABI (bytes):
//   EAX = factory*; no stack formals; bare RET (C3); void.
//   Before FUN_007465c0: ESI = *(dword*)slot  (decompiler omits this).
//
// Reject scaffold: Named_CalleeOf_Named_gfxDevice_009864e0
// =============================================================================

// External (not OWN): gfxDeviceVB unlock-all + Release; ESI = GfxDeviceVB*
extern "C" void FUN_007465c0(void /* ESI */);

struct TreeNode {
  TreeNode *left;    // +0
  TreeNode *parent;  // +4
  TreeNode *right;   // +8
  // +0xC.. : value / flags; flag byte @ +0xE; range @ +0x14/+0x18; isnil @ +0x21
};

void GfxVertexBufferFactory_PreResetReleaseAll_Inferred(/* EAX */ void *factory)
{
  auto *sentinel = *reinterpret_cast<TreeNode **>(reinterpret_cast<char *>(factory) + 0x14);
  // leftmost: *sentinel (MSVC map head->left)
  auto *node = *reinterpret_cast<TreeNode **>(sentinel);

  while (node != sentinel) {
    if ((*(unsigned char *)(reinterpret_cast<char *>(node) + 0xE) & 0x28) == 0) {
      auto *range_end = *reinterpret_cast<char **>(reinterpret_cast<char *>(node) + 0x18);
      for (auto *slot = *reinterpret_cast<char **>(reinterpret_cast<char *>(node) + 0x14);
           slot != range_end;
           slot += 0x20) {
        // bytes: MOV ESI, [EBX]; CALL FUN_007465c0
        void *vb = *reinterpret_cast<void **>(slot);
        // retail: ESI = vb
        (void)vb;
        FUN_007465c0();
      }
    }

    // MSVC tree ++ (isnil @ +0x21)
    if (*(char *)(reinterpret_cast<char *>(node) + 0x21) == 0) {
      auto *right = *reinterpret_cast<TreeNode **>(reinterpret_cast<char *>(node) + 8);
      if (*(char *)(reinterpret_cast<char *>(right) + 0x21) == 0) {
        auto *p = right;
        auto *left = *reinterpret_cast<TreeNode **>(p);
        while (*(char *)(reinterpret_cast<char *>(left) + 0x21) == 0) {
          p = left;
          left = *reinterpret_cast<TreeNode **>(p);
        }
        node = p;
      } else {
        auto *p = *reinterpret_cast<TreeNode **>(reinterpret_cast<char *>(node) + 4);
        auto *cur = node;
        while (*(char *)(reinterpret_cast<char *>(p) + 0x21) == 0 &&
               cur == *reinterpret_cast<TreeNode **>(reinterpret_cast<char *>(p) + 8)) {
          cur = p;
          p = *reinterpret_cast<TreeNode **>(reinterpret_cast<char *>(p) + 4);
        }
        node = p;
      }
    }
  }
}
