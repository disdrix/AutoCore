// =============================================================================
// Client_DismissModalPrompt (FUN_007fc360)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc360
// Address:   0x007fc360–0x007fc487  (autoassault.exe, image base 0x400000)
// System:    client UI modal / message panel
// Generated: 2026-07-29 W17-M dual seal (decompile_function + force_decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Name:      Client_DismissModalPrompt — INFERRED from ShowModalPrompt / ESC / abandon
//            call sites; Ghidra symbol remains FUN_007fc360.
// =============================================================================
//
// PURPOSE
//   Shared client helper to dismiss the message-panel modal host:
//   - notify host (vtbl+0xb0), hide panel (vtbl+0x440)
//   - optional pending C2S opcode 0x8006 (size 0x18) when client+0x30f4 set
//   - restore dual-id host+0x498/0x49c from backups +0x514/+0x518
//   - optionally restore secondary UI (+0xf38 vtbl+0x3c4) unless a slot blocks
//   - always clear panel+0x4fd when panel and host holders exist
//
// ABI (sealed)
//   EAX = ClientGame *
//   void; plain RET; no stack args
//

#include <cstdint>
#include <cstring>

extern "C" std::uint32_t FUN_008073b0(std::int16_t size, void *packet); // ESI=client at call

// Ghidra: void FUN_007fc360(void) with in_EAX client
void Client_DismissModalPrompt(void)
{
  int client; // = EAX at entry; kept in ESI across body
  int *panel;
  int *host_holder;
  char active;
  int *host;
  int i;
  int *slot;
  std::uint8_t packet[0x18];

  panel = *reinterpret_cast<int **>(client + 0x1118);
  host_holder = *reinterpret_cast<int **>(client + 0xf40);

  if (panel == nullptr || host_holder == nullptr) {
    return;
  }

  active = reinterpret_cast<char (*)(int *)>(
      (*reinterpret_cast<void **>(*reinterpret_cast<void **>(panel)))[0x3d8 / 4])(panel);

  if (active != 0) {
    if (*host_holder != 0) {
      host = reinterpret_cast<int *>(*host_holder);
      reinterpret_cast<void (*)(int *, int *)>(
          (*reinterpret_cast<void **>(*reinterpret_cast<void **>(host)))[0xb0 / 4])(
          host, panel);
    }

    reinterpret_cast<void (*)(int *)>(
        (*reinterpret_cast<void **>(*reinterpret_cast<void **>(panel)))[0x440 / 4])(panel);

    if (*reinterpret_cast<char *>(client + 0x30f4) != 0) {
      *reinterpret_cast<char *>(client + 0x30f4) = 0;
      std::memset(packet, 0, sizeof(packet));
      *reinterpret_cast<std::uint32_t *>(packet + 0x00) = 0x8006;
      packet[0x11] = 0;
      *reinterpret_cast<std::uint32_t *>(packet + 0x14) = 9;
      FUN_008073b0(0x18, packet);
    }

    if (*host_holder != 0) {
      host = reinterpret_cast<int *>(*host_holder);
      *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(host) + 0x498) =
          *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(host) + 0x514);
      *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(host) + 0x49c) =
          *reinterpret_cast<std::uint32_t *>(reinterpret_cast<char *>(host) + 0x518);
    }

    if (*reinterpret_cast<int *>(client + 0xf38) != 0) {
      i = 0;
      int **slots = reinterpret_cast<int **>(client + 0x1030);
      do {
        if (i != 0x16) {
          slot = slots[i];
          if (slot != nullptr) {
            char slot_active = reinterpret_cast<char (*)(int *)>(
                (*reinterpret_cast<void **>(*reinterpret_cast<void **>(slot)))[0x3d8 / 4])(slot);
            if (slot_active != 0 && slot[0x140] == 1) {
              goto clear_panel_flag;
            }
          }
        }
        i = i + 1;
      } while (i < 0x3a);

      {
        int *ctrl = *reinterpret_cast<int **>(client + 0xf38);
        reinterpret_cast<void (*)(int *, std::uint8_t)>(
            (*reinterpret_cast<void **>(*reinterpret_cast<void **>(ctrl)))[0x3c4 / 4])(
            ctrl, *reinterpret_cast<std::uint8_t *>(client + 0x31d8));
      }
    }
  }

clear_panel_flag:
  *reinterpret_cast<std::uint8_t *>(*reinterpret_cast<int *>(client + 0x1118) + 0x4fd) = 0;
}

// Ghidra export name
void FUN_007fc360(void)
{
  Client_DismissModalPrompt();
}
