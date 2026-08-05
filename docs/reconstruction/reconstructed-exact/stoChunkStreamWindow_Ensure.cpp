// =============================================================================
// stoChunkStreamWindow_Ensure
// -----------------------------------------------------------------------------
// Stable ID: aa_00435df0
// Address:   0x00435df0–0x00435f24  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00435df0; dual A/B seal 2026-07-29 (W18-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: __thiscall; ECX = StoStreamWindow*; stack arg = absolute stream position.
 *   Epilogue ret 4 (c2 04 00) on all three exit paths.
 * - Re-anchors the sliding window so buffer[0] corresponds to absPos, cursor=0,
 *   then fills via source Seek (vtbl+4) + Read (vtbl+0x14).
 * - Three arms: forward-slide inside window, backward-slide within capacity,
 *   full reposition. CRT memmove used for buffer shift.
 * - Return: EAX = last Source Read status (callers treat <0 as fail). Decompiler
 *   shows void; faithful plate returns the Read result.
 * - Callers (context): stoChunkStreamWindow_ReadHeader16, stoChunkReader_OpenChunk,
 *   readF32Array / typed readers — typically pass base+cursor.
 *
 * Layout (sibling-sealed + this unit):
 *   +0x00 pSource*, +0x04 cursor, +0x08 base, +0x0c available,
 *   +0x10 capacity, +0x14 streamEnd, +0x18 buffer[]
 */

#include <cstdint>
#include <cstring>

struct StoStreamSource;
struct StoStreamSourceVtbl {
  void* slot0;
  int (__thiscall *Seek)(StoStreamSource* self, int absPos, int origin); // +0x04 INFERRED
  // ...
  // +0x14:
  // int (__thiscall *Read)(StoStreamSource* self, void* dst, int size);
};

struct StoStreamWindow {
  StoStreamSource* pSource; // +0x00
  int32_t cursor;           // +0x04
  int32_t base;             // +0x08
  int32_t available;        // +0x0c
  int32_t capacity;         // +0x10
  int32_t streamEnd;        // +0x14
  // uint8_t buffer[] at +0x18
};

static inline uint8_t* WinBuf(StoStreamWindow* w)
{
  return (uint8_t*)w + 0x18;
}

static inline StoStreamSourceVtbl* SrcVtbl(StoStreamSource* src)
{
  return *(StoStreamSourceVtbl**)src;
}

// Ghidra: void __thiscall FUN_00435df0(undefined4 *param_1, size_t param_2)
// Machine: ret 4; EAX = last Read.
int32_t __thiscall stoChunkStreamWindow_Ensure(StoStreamWindow* win, int32_t absPos)
{
  int32_t oldBase = win->base;
  int32_t target = absPos;
  int32_t keep;
  int32_t rem;
  int32_t avail;
  int32_t bound;
  int32_t* pSize;

  if (oldBase <= target) {
    if (target < win->available + oldBase) {
      // Arm A — forward inside current window
      keep = win->available - (target - oldBase);
      memmove(WinBuf(win), WinBuf(win) + (target - oldBase), (size_t)keep);
      win->base = target;
      rem = win->streamEnd - target;
      avail = (rem <= win->capacity) ? rem : win->capacity;
      win->available = avail;
      win->cursor = 0;
      // Seek(keep + target, 0); result discarded
      SrcVtbl(win->pSource)->Seek(win->pSource, keep + target, 0);
      // Read into tail; return status
      return ((int32_t(__thiscall*)(StoStreamSource*, void*, int32_t))(
                  *(void**)((uint8_t*)SrcVtbl(win->pSource) + 0x14)))(
          win->pSource, WinBuf(win) + keep, avail - keep);
    }
    if (oldBase <= target) {
      goto full_reposition;
    }
  }

  if (oldBase <= win->capacity + target) {
    // Arm B — backward slide within capacity
    bound = (win->capacity - oldBase) + target;
    pSize = &win->available;
    if (bound < win->available) {
      pSize = &bound;
    }
    memmove(WinBuf(win) + (oldBase - target), WinBuf(win), (size_t)*pSize);
    win->base = target;
    rem = win->streamEnd - target;
    avail = (rem <= win->capacity) ? rem : win->capacity;
    win->available = avail;
    win->cursor = 0;
    SrcVtbl(win->pSource)->Seek(win->pSource, target, 0);
    return ((int32_t(__thiscall*)(StoStreamSource*, void*, int32_t))(
                *(void**)((uint8_t*)SrcVtbl(win->pSource) + 0x14)))(
        win->pSource, WinBuf(win), oldBase - target);
  }

full_reposition:
  // Arm C — full reposition
  win->base = target;
  win->cursor = 0;
  SrcVtbl(win->pSource)->Seek(win->pSource, target, 0);
  rem = win->streamEnd - win->base;
  avail = (rem <= win->capacity) ? rem : win->capacity;
  win->available = avail;
  return ((int32_t(__thiscall*)(StoStreamSource*, void*, int32_t))(
              *(void**)((uint8_t*)SrcVtbl(win->pSource) + 0x14)))(
      win->pSource, WinBuf(win), avail);
}

// Legacy Ghidra name (scaffold)
void __thiscall FUN_00435df0(uint32_t* param_1, size_t param_2)
{
  (void)stoChunkStreamWindow_Ensure((StoStreamWindow*)param_1, (int32_t)param_2);
}
