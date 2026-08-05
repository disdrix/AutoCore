// =============================================================================
// CNDHash_Remove_009cc1f0  (named twin of FUN_004e3610)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3610
// Address:   0x004e3610  (autoassault.exe, image base 0x400000)
// Body:      200 B; RET 8
// System:    container / CNDHash
// Refined:   2026-07-29 W27-K
// =============================================================================
//
// Remove entry by 32-bit key. Optional out-param receives value pointer and
// takes ownership (node value cleared before freelist). Miss → E_FAIL.
// Traversal lock at hash+0x1d is warn-only.

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *msg);
extern "C" uint32_t *FUN_004e2ca0(uint32_t key);
extern "C" void operator_delete(void *p);
extern "C" uint32_t PTR_FUN_009cc1f0[];

uint32_t __thiscall CNDHash_Remove_009cc1f0(void *hash, uint32_t key, void **outOpt)
{
  uint32_t *node;
  uint8_t *h = reinterpret_cast<uint8_t *>(hash);

  if (outOpt != nullptr) {
    *outOpt = nullptr;
  }

  if (*reinterpret_cast<char *>(h + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:remove, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  node = FUN_004e2ca0(key);
  if (node == nullptr) {
    return 0x80004005u;
  }

  if (outOpt != nullptr) {
    *outOpt = reinterpret_cast<void *>(node[2]);
  }
  node[2] = 0;

  if (node == *reinterpret_cast<uint32_t **>(h + 0x14)) {
    *reinterpret_cast<uint32_t *>(h + 0x14) = node[5];
  } else {
    *reinterpret_cast<uint32_t *>(node[6] + 0x14) = node[5];
  }

  if (node == *reinterpret_cast<uint32_t **>(h + 0x18)) {
    *reinterpret_cast<uint32_t *>(h + 0x18) = node[6];
  } else {
    *reinterpret_cast<uint32_t *>(node[5] + 0x18) = node[6];
  }

  *node = reinterpret_cast<uint32_t>(&PTR_FUN_009cc1f0);
  if (reinterpret_cast<void *>(node[2]) != nullptr) {
    operator_delete(reinterpret_cast<void *>(node[2]));
  }
  node[2] = 0;

  *node = *reinterpret_cast<uint32_t *>(h + 0x20);
  *reinterpret_cast<uint32_t **>(h + 0x20) = node;
  *reinterpret_cast<int32_t *>(h + 0xc) -= 1;
  return 0;
}
