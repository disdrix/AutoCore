// =============================================================================
// PhysMgr_AttachBody_Inferred  (Ghidra: FUN_0055ff20)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ff20
// Address:   0x0055ff20 – 0x00560017  (autoassault.exe, image base 0x400000)
// Size:      248 bytes (0xF8); epilogue ret 4; pad CC after
// System:    phys / manager body attach
// Dual:      W29-R 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Attach a physics body to the manager: stamp owner, collect/install new link
//   pairs via worklist + SortedDiffWalk (new vs empty), assign serial, bump
//   short refcount, push onto manager body vector, notify host-action list,
//   release worklist. Twin detach is FUN_00560020 (W29-S).
//
// ABI (machine):
//   thiscall; ECX = manager; 1 stack formal (body*); returns body*; ret 4
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0062d960(std::uint32_t *desc /*ECX*/, std::uint32_t count);
extern "C" void __fastcall FUN_0055f4c0(std::uint32_t *desc /*ECX*/);
extern "C" void FUN_006cad30(void *pairs, int count);
extern "C" void __thiscall FUN_006caaa0(
    int handler_table /*ECX*/,
    void *left_pairs, int left_count,
    void *right_pairs, int right_count,
    int predicate_or_ctx);
extern "C" void FUN_0062a4d0(int manager, int *body);
extern "C" void FUN_005b3370(int *vec_desc /*ptr,count,cap*/, int stride);

// Ghidra: FUN_0055ff20
int *__thiscall PhysMgr_AttachBody_Inferred(int manager /*ECX*/, int *body /*stack*/)
{
  int *slot;
  int serial;
  int pred;
  int pair_count; // decompiler unaff_EDI — filled by vcall outs
  std::uint8_t *pair_buf;
  std::uint8_t work_scratch[44];
  std::uint8_t out_a[4];
  std::uint32_t wl[5];

  body[2] = manager; // body+0x8 = manager

  FUN_0062d960(wl, *reinterpret_cast<std::uint32_t *>(manager + 0x234));

  pair_buf = work_scratch;
  (**(void (***)(std::uint8_t *))(*body + 0x18))(pair_buf);

  // Null-this safe body+0x1c (MSVC: body == (T*)-0xC ? 0 : body+0x1C)
  if (body == reinterpret_cast<int *>(-0xc)) {
    slot = nullptr;
  } else {
    slot = body + 7; // +0x1c
  }

  (**(void (***)(int *, void *, void *))(
      **reinterpret_cast<int **>(manager + 0xc4) + 4))(
      slot, out_a, /*stack out for count/buf*/ &pair_count);
  // pair_count / pair_buf filled by vcall (decompiler residual unaff_EDI)

  serial = *reinterpret_cast<int *>(manager + 0x130);
  *reinterpret_cast<int *>(manager + 0x130) = serial + 1;
  body[8] = serial; // body+0x20

  if (pair_count != 0) {
    FUN_006cad30(pair_buf, pair_count);
    if (*reinterpret_cast<int *>(manager + 0xd0) == 0) {
      pred = 0;
    } else {
      pred = *reinterpret_cast<int *>(manager + 0xd0) + 8;
    }
    // Machine ECX = *(manager+0x138); right side empty (attach = left-only adds)
    FUN_006caaa0(*reinterpret_cast<int *>(manager + 0x138), pair_buf, pair_count,
                 nullptr, 0, pred);
  }

  *reinterpret_cast<std::int16_t *>(reinterpret_cast<char *>(body) + 6) =
      static_cast<std::int16_t>(
          *reinterpret_cast<std::int16_t *>(reinterpret_cast<char *>(body) + 6) +
          1);

  // Body pointer vector at manager+0x120 {ptr, count@+4, cap@+8}
  if (*reinterpret_cast<std::uint32_t *>(manager + 0x124) ==
      (*reinterpret_cast<std::uint32_t *>(manager + 0x128) & 0x7fffffffu)) {
    FUN_005b3370(reinterpret_cast<int *>(manager + 0x120), 4);
  }
  *reinterpret_cast<int **>(
      *reinterpret_cast<int *>(manager + 0x120) +
      *reinterpret_cast<int *>(manager + 0x124) * 4) = body;
  *reinterpret_cast<int *>(manager + 0x124) =
      *reinterpret_cast<int *>(manager + 0x124) + 1;

  FUN_0062a4d0(manager, body);
  FUN_0055f4c0(wl);
  return body;
}
