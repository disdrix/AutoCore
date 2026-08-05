// =============================================================================
// WeatherHost_ApplyEnvTime_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005575c0
// Address:   0x005575c0–0x005579be  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005575c0
// System:    client weather / env-time transition + nfx preload
// Dual:      W36-F 2026-07-29
// Exactness: Behavior-preserving control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: __thiscall; ECX = weather host; stack uint8_t env_time_slot; RET 0x4.
// Resolve weather for env-time slot; cooperatively preload nfx rings
// (fill @ host+0x190 mode0, activate @ host+0x1a4 mode1) via AssPreloader;
// blend transition over 5000.0f ms; swap prev/cur weather; apply helper.
// Name structural Inferred (weather strings + sealed nfx/AssPreloader callees).
// =============================================================================

#include <cstdint>

extern "C" void*   FUN_00558eb0(void* out_entry, const uint8_t* slot);
extern "C" void    FUN_007a4480(int level, const char* msg);
extern "C" void    FUN_00556a60();
extern "C" void    FUN_00556da0(int a, void* env_time_blob);
extern "C" void    Weather_NfxListFillOrActivate_Inferred(
    void* host /*ECX*/, void* outList, void* weatherObj, int mode);
extern "C" uint8_t AssPreloader_ProcessKeyRingStep_Inferred(
    void* ring, char* progress_flag, uint32_t* cursor);
extern "C" uint32_t AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(
    void* preloader /*ECX*/, void* source_ring);
extern "C" void    FUN_005554d0(/* weather this via ECX in retail */);
extern "C" void    FUN_00555f10(void* host /*ECX*/, uint32_t arg);
extern "C" uint32_t __stdcall GetTickCount();

extern "C" uint8_t* DAT_00d1f050;
extern "C" float    _DAT_00af2ce8; // 5000.0f @ 0x00af2ce8
extern "C" float    _DAT_00aaa5dc; // 2^32 @ 0x00aaa5dc
extern "C" float    g_flOne;
extern "C" char     DAT_00b03e64;

// Offsets sealed by use-sites (product class English open).
struct WeatherHost {
  uint8_t   _pad[0x174];
  uint32_t  current_key;   // +0x174
  uint32_t  enable_gate;   // +0x178
  uint8_t*  weather_cur;   // +0x17c ; slot byte at weather+0x54c
  uint8_t*  weather_prev;  // +0x180
  uint32_t  _pad184;
  uint32_t  apply_arg;     // +0x188
  uint32_t  tick_base;     // +0x18c
  // +0x190 GuardedVector nfx fill ring
  // +0x1a4 GuardedVector nfx activate ring
  // +0x1b8 uint cached_slot
  // +0x1bc char fill_ready
  // +0x1bd char act_ready
  // +0x1c0 uint ring_cursor
};

static void* HostAt(WeatherHost* h, uint32_t off)
{
  return reinterpret_cast<uint8_t*>(h) + off;
}

static void* AssPreloader()
{
  return *reinterpret_cast<void**>(DAT_00d1f050 + 0x6c);
}

void __thiscall WeatherHost_ApplyEnvTime_Inferred(WeatherHost* host, uint8_t slot)
{
  if (host->enable_gate == 0) {
    return;
  }

  // --- Resolve weather entry for slot (FUN_00558eb0) -----------------------
  // Retail: out entry key compared to host->current_key (+0x174).
  // If equal, retry slot 0; if still equal:
  //   FUN_007a4480(0, "Somewhere on the map, someone forgot a weather.\n");
  //   FUN_00556a60(); seed env_time_{dawn,midday,sunset,night} blobs;
  //   FUN_00556da0(0, dawn_blob); re-lookup slot 0.
  // weather_obj = lookup_entry + 0x10  (decompiler: (int)fVar7 + 0x10).
  uint8_t* weather_obj = nullptr;
  {
    uint32_t entry_key = 0;
    FUN_00558eb0(&entry_key, &slot);
    // full default-seed path: see raw aa_005575c0 (SEH temps) — CF preserved in raw.
    // After resolution, entry_key holds entry pointer bits; weather at +0x10:
    weather_obj = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(entry_key) + 0x10);
    (void)entry_key;
  }

  uint8_t* cur = host->weather_cur;
  if (cur != nullptr) {
    if (cur[0x54c] == slot) {
      return;
    }

    bool just_filled = false;
    uint32_t* cached = reinterpret_cast<uint32_t*>(HostAt(host, 0x1b8));
    char* fill_ready = reinterpret_cast<char*>(HostAt(host, 0x1bc));
    char* act_ready = reinterpret_cast<char*>(HostAt(host, 0x1bd));
    uint32_t* cursor = reinterpret_cast<uint32_t*>(HostAt(host, 0x1c0));
    void* fill_ring = HostAt(host, 0x190);
    void* act_ring = HostAt(host, 0x1a4);

    if (static_cast<uint32_t>(slot) != *cached) {
      *cached = slot;
      Weather_NfxListFillOrActivate_Inferred(host, fill_ring, weather_obj, 0);
      char flag0 = 0;
      *fill_ready = static_cast<char>(
          AssPreloader_ProcessKeyRingStep_Inferred(fill_ring, &flag0, cursor));
      just_filled = true;
      if (*fill_ready == 0) {
        AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(AssPreloader(), fill_ring);
        return;
      }
    }

    if (*fill_ready == 0) {
      char flag1 = 1;
      *fill_ready = static_cast<char>(
          AssPreloader_ProcessKeyRingStep_Inferred(fill_ring, &flag1, cursor));
      if (*fill_ready == 0) {
        return;
      }
      // LAB_00557843 — activate after fill becomes ready
      goto activate;
    } else if (just_filled) {
      goto activate;
    }
    goto check_act_retry;

  activate:
    Weather_NfxListFillOrActivate_Inferred(host, act_ring, weather_obj, 1);
    {
      char flag0 = 0;
      *act_ready = static_cast<char>(
          AssPreloader_ProcessKeyRingStep_Inferred(act_ring, &flag0, cursor));
      if (*act_ready == 0) {
        AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(AssPreloader(), act_ring);
        return;
      }
    }

  check_act_retry:
    if (*act_ready == 0) {
      char flag1 = 1;
      *act_ready = static_cast<char>(
          AssPreloader_ProcessKeyRingStep_Inferred(act_ring, &flag1, cursor));
      if (*act_ready == 0) {
        return;
      }
    }
  }

  // --- Transition clock ----------------------------------------------------
  uint32_t tick;
  if (host->weather_prev == nullptr) {
    tick = GetTickCount();
  } else if (host->weather_prev[0x54c] != slot) {
    if (DAT_00b03e64 == 0) {
      return;
    }
    goto commit;
  } else {
    tick = GetTickCount();
    int32_t dt = static_cast<int32_t>(tick - host->tick_base);
    float fdt = static_cast<float>(dt);
    if (dt < 0) {
      fdt += _DAT_00aaa5dc;
    }
    float t = fdt / _DAT_00af2ce8;
    if (!(t < g_flOne)) {
      t = g_flOne;
    }
    float remain = (g_flOne - t) * _DAT_00af2ce8;
    // retail ROUND then subtract from tick
    tick = tick - static_cast<uint32_t>(remain);
  }
  host->tick_base = tick;

commit:
  {
    uint8_t* old_cur = host->weather_cur;
    host->weather_prev = old_cur;
    host->weather_cur = weather_obj;
    if (DAT_00b03e64 != 0) {
      if (old_cur != nullptr) {
        FUN_005554d0();
      }
      host->weather_prev = nullptr;
      host->tick_base = 0;
    }
    FUN_00555f10(host, host->apply_arg);
  }
}
