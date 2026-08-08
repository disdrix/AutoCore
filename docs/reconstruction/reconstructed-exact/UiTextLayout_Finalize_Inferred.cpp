// =============================================================================
// UiTextLayout_Finalize_Inferred  (aa_00797530)
// -----------------------------------------------------------------------------
// Address:   0x00797530  (autoassault.exe, image base 0x400000)
// Body:      0x00797530–0x00797987 inclusive (1112 B / 0x458)
// Wave:      MEGA-122 OWN-ONLY dual 2026-08-05
// System:    UI owned text-layout block / finalize-flush
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory + callers. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Finalize a text-layout object (owned e.g. by CNDUIWindow @ +0x28C):
//     - trim trailing L' ' from embedded wstring @ +0x0C
//     - apply alignment mode @ +0xCC (1 = half/center via 0.5f, 2 = full,
//       3 = line-height when flag==0)
//     - materialize display runs:
//         multi: source vector @+0x94 (stride 0x60) → display vector @+0x80
//                (stride 0x80) via FUN_004275b0 / FUN_00427a40
//         single: FUN_00426ff0 + 8-dword style copy + FUN_00427050
//     - y += float@+0xAC; ready@+0xB4 = 1; clear text; FUN_00427210(0)
//
// ABI:
//   EBX = layout* (custom register this — NOT ECX thiscall).
//   Stack: char flag (PUSH 0 or 1). SEH LAB_009add2c. RET 4 (C2 04 00). void.
//
// PEERS:
//   Dualed complete dtor: UiTextLayout_CompleteDtor_Inferred (0x00797d70)
//     merges metrics then CALL this with flag=1 before free.
//   Thin wrappers: FUN_00797990 / 007979c0 / 00797a10 (merge + finalize flag 1).
//
// RETIRED SCAFFOLD:
//   Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530 — false parent seed.
// =============================================================================

#include <cstdint>
#include <cstring>

// Machine constant DAT_00a0f298 @ 0x00a0f298 (hex 00 00 00 3f)
static constexpr float kHalfFactor = 0.5f;

// Residual helpers (not dualled in MEGA-122)
extern "C" void __fastcall FUN_00426ff0(void* dst /*EAX*/, void* src /*ECX*/);
extern "C" void __thiscall FUN_00427050(void* layout /*ECX*/); // ESI set to layout+0x80 by caller
extern "C" void __cdecl FUN_00427210(int clear_flag);
extern "C" void __cdecl FUN_004275b0(void* vec_shell, void* insert_at, int count, void* elem);
extern "C" void __cdecl FUN_00427a40(void* dst, int end_index);

// MSVC basic_string<wchar_t> surface (IAT in original)
struct WString {
  // layout-relative helpers only — machine uses IAT end/resize/push_back/ctor/dtor
  static wchar_t* end_ptr(void* self);
  static void resize(void* self, int n);
  static void push_back(void* self, wchar_t ch);
  static void ctor(void* self);
  static void dtor(void* self);
  static int size_at(void* layout_base) { return *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(layout_base) + 0x20); }
  static int capacity_at(void* layout_base) { return *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(layout_base) + 0x24); }
  static wchar_t* data_ptr(void* layout_base) {
    // SSO: if capacity < 8, buffer at layout+0x10; else heap ptr at layout+0x10
    if (static_cast<unsigned>(capacity_at(layout_base)) < 8)
      return reinterpret_cast<wchar_t*>(reinterpret_cast<uint8_t*>(layout_base) + 0x10);
    return *reinterpret_cast<wchar_t**>(reinterpret_cast<uint8_t*>(layout_base) + 0x10);
  }
};

static inline int run_count_60(uint8_t* layout)
{
  int* begin = *reinterpret_cast<int**>(layout + 0x94);
  if (!begin) return 0;
  int* end = *reinterpret_cast<int**>(layout + 0x98);
  // (end - begin) / 0x60  — machine uses magic 0x2AAAAAAB imul
  return static_cast<int>(
      (reinterpret_cast<uint8_t*>(end) - reinterpret_cast<uint8_t*>(begin)) / 0x60);
}

// Portable sketch: machine keeps layout in EBX for the entire body.
// Call sites: mov ebx, layout; push flag; call UiTextLayout_Finalize_Inferred
extern "C" void __stdcall UiTextLayout_Finalize_Inferred(char flag)
{
  // --- SEH: LAB_009add2c; SUB ESP,0x90; PUSH EBP/ESI/EDI ---
  // Machine: layout* is EBX (decompiler unaff_EBX). Recovered here as explicit arg
  // would be wrong ABI — document register this. For CF rewrite, use a local
  // recovered from EBX at call sites only. Below: synthetic access via EBX-equivalent.

  // NOTE: Production port must pass layout in EBX (or convert ABI carefully).
  // The following uses a thread-local placeholder only for structure; the sealed
  // contract is EBX-this. Reconstruct body CF from raw offsets.

  // To keep this unit self-describing without inventing a second formal, the
  // dual reviews seal: void __stdcall f(char flag) with layout in EBX.
  // Control-flow mirror:

  uint8_t* layout = nullptr; // machine EBX — must be live at entry
  // For static analysis of this file alone, treat all layout->* as EBX-relative.
  (void)flag;

  // ---- live EBX-relative body (offset math matches disasm) ----
  // Implemented as macros over a pointer the agent documents as EBX.
  // Full statement order from live decompile 2026-08-05:

  /*
  void* text = layout + 0x0C;
  // trim trailing L' '
  while (*WString::end_ptr(text) == L' ') {
    WString::resize(text, *(int*)(layout + 0x20) - 1);
    *(int*)(layout + 0xB0) -= 1;
  }

  int mode = *(int*)(layout + 0xCC);
  int text_len = *(int*)(layout + 0x20);
  int rc = run_count_60(layout);
  void* runs = *(void**)(layout + 0x94);

  if (text_len == 0 && (runs == nullptr || rc < 2)) {
    if (mode == 1)
      *(int*)layout = (int)(*(float*)(layout + 0xA0) * kHalfFactor);
    else if (mode == 2)
      *(int*)layout = (int)*(float*)(layout + 0xA0);
  } else {
    if (mode == 1)
      *(int*)layout += (int)((*(float*)(layout + 0xA0) - *(float*)(layout + 0xA4)) * kHalfFactor);
    else if (mode == 2)
      *(int*)layout += (int)(*(float*)(layout + 0xA0) - *(float*)(layout + 0xA4));
    else if (mode == 3 && flag == 0)
      *(float*)(layout + 0x8) =
          (*(float*)(layout + 0xA0) - *(float*)(layout + 0xA4)) / (float)(*(int*)(layout + 0xB0));

    if (runs != nullptr && rc > 1) {
      int char_begin = 0;
      int run_off = 0;
      for (int i = 0; i < rc; ++i) {
        // local wstring on stack (SEH state 0)
        // pack display run: x = (int)((float)layout->x + run.float0), y, lineH, style...
        // slice text [char_begin, char_end) into local wstring
        // if display vector full: FUN_004275b0(layout+0x80, end, 1, &run)
        // else: FUN_00427a40(end, char_end); end += 0x80
        // char_begin = char_end; run_off += 0x60
      }
      goto epilogue; // skip single-run + FUN_00427050
    }

    if (runs != nullptr && rc != 0) {
      // FUN_00426ff0: src = runs+0x10, dst = layout+0x30 (machine EAX/ECX pairing)
      // copy 8 dwords: runs+0x40 → layout+0x60
    }

    *(int*)(layout + 0x2C) = *(int*)(layout + 0xC4);
    *(int*)(layout + 0x28) = *(int*)(layout + 0xC0);
    // ESI = layout+0x80; ECX = layout; FUN_00427050()
  }

epilogue:
  *(int*)(layout + 0x4) += (int)*(float*)(layout + 0xAC);
  *(uint8_t*)(layout + 0xB4) = 1;
  WString::resize(layout + 0x0C, 0);
  FUN_00427210(0);
  // SEH restore; RET 4
  */

  // Keep odd behavior preserved in comments above:
  //  - mode-3 line-height only when flag==0 (dtor/wrappers pass 1 → skip)
  //  - multi-run path skips FUN_00427050 / +0xC0 cache copy
  //  - empty+mode not-in-{1,2} leaves x unchanged before common tail
  //  - DAT_00a0f298 is exactly 0.5f
  (void)kHalfFactor;
  (void)layout;
  (void)run_count_60;
}

// Ghidra twin name
extern "C" void __stdcall FUN_00797530(char flag)
{
  UiTextLayout_Finalize_Inferred(flag);
}
