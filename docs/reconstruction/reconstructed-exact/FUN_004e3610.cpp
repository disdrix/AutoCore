// =============================================================================
// FUN_004e3610 / CNDHash_Remove_009cc1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3610
// Address:   0x004e3610  (autoassault.exe, image base 0x400000)
// Body:      0x004e3610–0x004e36d7 (200 B); RET 8
// System:    container / CNDHash
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W27-K (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + machine notes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: CNDHash remove by u32 key with optional out-value ownership transfer.
// Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP"
// Sibling family: CNDHash_Remove @ 0x00538b20 (vtbl 009cf024); CNDHash_Remove_u64 @ 0x00413a60
// Freelist node vtbl disambiguator: PTR_FUN_009cc1f0

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *msg);
extern "C" uint32_t *FUN_004e2ca0(uint32_t key); // ECX = bucket chain; find+bucket-unlink
extern "C" void operator_delete(void *p);
extern "C" uint32_t PTR_FUN_009cc1f0[];

// ECX = hash this; stack key + outOpt; RET 8
// Returns 0 on hit, 0x80004005 (E_FAIL) on miss.
uint32_t __thiscall FUN_004e3610(void *hash, uint32_t key, void **outOpt)
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

  // Machine: bucket = *(hash+0x10)[key & *(hash+8)]; ECX=bucket; CALL FUN_004e2ca0
  node = FUN_004e2ca0(key);

  if (node == nullptr) {
    return 0x80004005u;
  }

  if (outOpt != nullptr) {
    *outOpt = reinterpret_cast<void *>(node[2]); // node+0x08 value*
  }
  node[2] = 0; // clear before freelist; suppresses payload free when out transferred

  // Unlink from ordered doubly-linked list (head hash+0x14, tail hash+0x18)
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
  // Dead when outOpt transferred (node[2] already 0); live only if out was null and value remained.
  if (reinterpret_cast<void *>(node[2]) != nullptr) {
    operator_delete(reinterpret_cast<void *>(node[2]));
  }
  node[2] = 0;

  // Freelist push: dword0 = next freelist node
  *node = *reinterpret_cast<uint32_t *>(h + 0x20);
  *reinterpret_cast<uint32_t **>(h + 0x20) = node;
  *reinterpret_cast<int32_t *>(h + 0xc) -= 1;
  return 0;
}
