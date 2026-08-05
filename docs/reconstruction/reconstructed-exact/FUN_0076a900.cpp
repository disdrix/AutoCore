// =============================================================================
// FUN_0076a900  (scaffold alias → stoChunkReader_PeekChunkTag)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a900
// Address:   0x0076a900–0x0076aac9  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; **sealed 2026-07-29** dual A/B W19-R
// Canonical: docs/reconstruction/reconstructed-exact/stoChunkReader_PeekChunkTag.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes:
 * - Peek next stoChunk FOURCC; restore cursor + pending string at +0x404c.
 * - this = ESI (unaff_ESI). Mode +0x4044: 0=binary OpenChunk path, 1=text CHUNK.
 * - See named clean + raw v2026-07-29 for bytes and call-site seals.
 */

#include <cstdint>
#include <string>

extern "C" void *ExceptionList;
extern "C" void *LAB_009b1357;
extern "C" int stoChunkReader_OpenChunk(void);
extern "C" std::uint32_t *FUN_00436220(void);
extern "C" int FUN_00767840(void *self, int a);
extern "C" int FUN_00769b70(void *self);
extern "C" bool std_string_ne_chunk(void *str); // operator!= (local, "CHUNK")
extern "C" void std_string_ctor_copy(void *dst, void *src);
extern "C" void std_string_ctor_default(void *dst);
extern "C" void std_string_dtor(void *s);
extern "C" void std_string_assign(void *dst, void *src);

// Decompiler-shaped: no C args; this in ESI.
extern "C" std::uint32_t FUN_0076a900(void)
{
  std::uint32_t **ppuVar1;
  bool bVar2;
  int iVar3;
  std::uint32_t *puVar4;
  int iVar5;
  int unaff_ESI; // this
  std::uint32_t local_4c;
  // basic_string local_44 / local_28 and SSO locals omitted as opaque blobs
  std::uint8_t local_44[0x20];
  std::uint8_t local_28[0x20];
  void *local_c;
  std::uint8_t *puStack_8;
  int local_4;
  int local_30;
  std::uint32_t local_2c;
  void *local_40[4];

  local_4 = -1;
  puStack_8 = reinterpret_cast<std::uint8_t *>(&LAB_009b1357);
  local_c = ExceptionList;
  iVar5 = *reinterpret_cast<int *>(unaff_ESI + 0x1c) +
          *reinterpret_cast<int *>(unaff_ESI + 0x18);
  local_4c = 0;
  ExceptionList = &local_c;

  std_string_ctor_copy(local_28,
                       reinterpret_cast<void *>(unaff_ESI + 0x404c));
  local_4 = 0;

  if (*reinterpret_cast<int *>(unaff_ESI + 0x4044) == 0) {
    iVar3 = stoChunkReader_OpenChunk();
    if (iVar3 >= 0) {
      puVar4 = FUN_00436220();
      local_4c = *puVar4;
      if (*reinterpret_cast<int *>(unaff_ESI + 0x4040) != 0) {
        iVar3 = *reinterpret_cast<int *>(unaff_ESI + 0x4040) - 1;
        *reinterpret_cast<int *>(unaff_ESI + 0x4040) = iVar3;
        if (iVar3 == 0) {
          *reinterpret_cast<int *>(unaff_ESI + 0x403c) = 0;
        }
      }
    }
  } else if (*reinterpret_cast<int *>(unaff_ESI + 0x4044) == 1) {
    std_string_ctor_default(local_44);
    // local_4 low byte = 1 (EH state)
    iVar3 = FUN_00767840(reinterpret_cast<void *>(unaff_ESI), 1);
    if (iVar3 < 0) {
      std_string_dtor(local_44);
    } else {
      bVar2 = std_string_ne_chunk(local_44);
      if (bVar2) {
        std_string_dtor(local_44);
      } else {
        iVar3 = FUN_00769b70(reinterpret_cast<void *>(unaff_ESI));
        if (iVar3 < 0) {
          std_string_dtor(local_44);
        } else if (local_30 == 4) {
          if (local_2c < 0x10) {
            local_40[0] = local_40; // SSO: data inline
          }
          ppuVar1 = reinterpret_cast<std::uint32_t **>(*local_40);
          // Byte-swap / pack four characters into FOURCC dword (decomp CONCAT).
          {
            auto w = reinterpret_cast<std::uintptr_t>(ppuVar1);
            local_4c =
                (std::uint32_t)((w & 0xff) << 24) |
                (std::uint32_t)(((w >> 8) & 0xff) << 16) |
                (std::uint32_t)(((w >> 16) & 0xff) << 8) |
                (std::uint32_t)((w >> 24) & 0xff);
          }
          std_string_dtor(local_44);
        } else {
          std_string_dtor(local_44);
        }
      }
    }
  }

  if (iVar5 >= 0 && iVar5 <= *reinterpret_cast<int *>(unaff_ESI + 0x28)) {
    iVar3 = *reinterpret_cast<int *>(unaff_ESI + 0x1c);
    if (iVar5 < iVar3 ||
        *reinterpret_cast<int *>(unaff_ESI + 0x20) + iVar3 <= iVar5) {
      *reinterpret_cast<int *>(unaff_ESI + 0x1c) = iVar5;
      *reinterpret_cast<int *>(unaff_ESI + 0x20) = 0;
      *reinterpret_cast<int *>(unaff_ESI + 0x18) = 0;
    } else {
      *reinterpret_cast<int *>(unaff_ESI + 0x18) = iVar5 - iVar3;
    }
  }

  std_string_assign(reinterpret_cast<void *>(unaff_ESI + 0x404c), local_28);
  local_4 = -1;
  std_string_dtor(local_28);
  ExceptionList = local_c;
  return local_4c;
}
