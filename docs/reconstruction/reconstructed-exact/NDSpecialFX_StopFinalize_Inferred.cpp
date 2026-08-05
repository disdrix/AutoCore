// =============================================================================
// NDSpecialFX_StopFinalize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba0a0
// Address:   0x004ba0a0 – 0x004ba26d  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W27-D dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004ba0a0.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Manager-facing stop/finalize for an NDSpecialFX host:
//     - re-entry guard on host+8
//     - type-gated early clear (case 4 via List1e0_AnyFlag10; cases 5/6/C-E/14/15)
//     - mark +8=1; tear down lists +0x1E0/+1EC/+204/+210/+21C
//     - clear host+0x10; return keep polarity (1 = manager may free)
//
// ABI:
//   ECX = fx host; no stack formals; plain RET (C3); AL 0|1.
//
// RELATED (sealed peers):
//   FUN_004b6a80 = NDSpecialFX_List1e0_AnyFlag10
//   FUN_004b7150 = NDSpecialFX_DeactivateClear_Inferred (distinct path)
//   FUN_004b8ed0 = NDSpecialFX_HostTick_Inferred
//   FUN_00723b20 = CSoundManager_StopMatchingSounds_Inferred
//
// REJECTED ALIAS:
//   Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0 (keyword-only)
// =============================================================================

#include <cstdint>

char FUN_004b6a80(void);
void FUN_004b9af0(uint32_t a);
void FUN_004b9270(void *host);
void FUN_005b8340(void);
void Client_GetMissionCompleteAudioTable(uint32_t a, uint32_t b, unsigned int c, int d, int e);
void FUN_00723b20(uint32_t a, uint32_t b, unsigned int c, uint32_t d, uint32_t e);
void FUN_00593e10(uint32_t a, char keep);
void FUN_00498a90(void);
void FUN_00498ab0(int zero);

uint8_t __fastcall NDSpecialFX_StopFinalize_Inferred(void *fx_host)
{
  auto *base = static_cast<uint8_t *>(fx_host);
  int *host = reinterpret_cast<int *>(fx_host);
  char local_8 = 1;
  char keep = 1;

  if (base[8] != 0) {
    return 1;
  }

  int *linked = *reinterpret_cast<int **>(base + 0x10);
  if (linked != nullptr) {
    switch (*reinterpret_cast<uint32_t *>(base + 0x28)) {
    case 4:
      if (FUN_004b6a80() != 0) {
        break;
      }
      // fallthrough
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x14:
    case 0x15:
      if (base[0xb] != 0) {
        keep = 0;
        auto **vt = *reinterpret_cast<void ***>(linked);
        using Vfn = uint32_t(__thiscall *)(int *);
        uint32_t ent = reinterpret_cast<Vfn>(vt[0x1cc / 4])(linked);
        FUN_004b9af0(ent);
        FUN_004b9270(fx_host);
        local_8 = 0;
      }
      break;
    default:
      break;
    }
  }

  base[8] = 1;

  // +0x1E0
  {
    int *head = *reinterpret_cast<int **>(base + 0x1e0);
    int *node = *reinterpret_cast<int **>(head);
    if (node != head) {
      do {
        int payload = node[2];
        if (keep != 0) {
          *reinterpret_cast<uint8_t *>(payload + 0x7f9) = 1;
        }
        FUN_005b8340();
        int ring = payload + 0x14;
        do {
          FUN_005b8340();
          ring = *reinterpret_cast<int *>(ring + 0x2f4);
        } while (ring != payload + 0x14);
        *reinterpret_cast<uint32_t *>(payload + 4) = 0;
        node = *reinterpret_cast<int **>(node);
        local_8 = keep;
      } while (node != *reinterpret_cast<int **>(base + 0x1e0));
    }
  }

  // +0x1EC sound-active
  {
    int *head = *reinterpret_cast<int **>(base + 0x1ec);
    int *node = *reinterpret_cast<int **>(head);
    if (node != head) {
      do {
        if (*reinterpret_cast<char *>(node[2] + 0x10b) != 0) {
          int linked2 = *reinterpret_cast<int *>(base + 0x10);
          if (linked2 != 0) {
            unsigned int b168 = *reinterpret_cast<uint8_t *>(linked2 + 0x168);
            uint32_t a160 = *reinterpret_cast<uint32_t *>(linked2 + 0x160);
            uint32_t a164 = *reinterpret_cast<uint32_t *>(linked2 + 0x164);
            Client_GetMissionCompleteAudioTable(a160, a164, b168, 0, 0);
            FUN_00723b20(a160, a164, b168, 0, 0);
          }
        }
        node = *reinterpret_cast<int **>(node);
      } while (node != *reinterpret_cast<int **>(base + 0x1ec));
    }
  }

  // +0x204
  {
    int *head = *reinterpret_cast<int **>(base + 0x204);
    int *node = *reinterpret_cast<int **>(head);
    if (node != head) {
      do {
        FUN_00593e10(*reinterpret_cast<uint32_t *>(base + 0x2c), keep);
        node = *reinterpret_cast<int **>(node);
      } while (node != *reinterpret_cast<int **>(base + 0x204));
    }
  }

  // +0x210
  {
    int *head = *reinterpret_cast<int **>(base + 0x210);
    int *node = *reinterpret_cast<int **>(head);
    if (node != head) {
      do {
        if (local_8 != 0) {
          *reinterpret_cast<uint32_t *>(node[2] + 0x178) |= 0x100u;
        }
        FUN_005b8340();
        *reinterpret_cast<uint32_t *>(node[2]) = 0;
        node = *reinterpret_cast<int **>(node);
      } while (node != *reinterpret_cast<int **>(base + 0x210));
    }
  }

  // +0x21C
  {
    int *head = *reinterpret_cast<int **>(base + 0x21c);
    int *node = *reinterpret_cast<int **>(head);
    if (node != head) {
      do {
        FUN_00498a90();
        FUN_00498ab0(0);
        node = *reinterpret_cast<int **>(node);
      } while (node != *reinterpret_cast<int **>(base + 0x21c));
    }
  }

  *reinterpret_cast<uint32_t *>(base + 0x10) = 0;
  return static_cast<uint8_t>(local_8);
}
