# Review B (skeptical / adversarial): `aa_00637750` TNL_ByteBuffer_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` / single-arg helper | Epilogue **`RET` (`C3`)** + `ADD ESP,0x164`; two stack params in decompile; caller path passes out + buffer | **Falsified** — **cdecl two-arg** |
| 2 | Inline entry blob in ByteBuffer data (`tag‖count‖entries[]`) | Consumer `FUN_0080a810` loads **`*(buf+8)` as pointer** and `delete[]`s it; unpacker `operator_new[]` | **Falsified** — **heap Entry\* at +8** |
| 3 | Opcode is generic “any ByteBuffer” | Caller only when `param_2 == 0x804D`; header constant `0x804D`; enum `MapInstanceListResponse` | **Falsified exclusive-generic** — **opcode-specific unpack** |
| 4 | Flags via `BitStream_readFlag` call | No callee `BitStream_readFlag`; inlined bit test / advance matching writeFlag shape | **Confirmed** — **inlined** |
| 5 | Count is u32 on wire | First read is **8 bits**; `movzx` from byte | **Falsified u32-wire** — **u8 count** |
| 6 | Entry size 0x10 (u64+u16+u16 only) | Loop `add edi, 0x18`; flags at +0x10/+0x11; consumer copies 6 dwords | **Falsified** — **0x18** |
| 7 | Name `TNL_ByteBuffer_UnpackData` means generic TNL API for all opcodes | Sibling unpackers (`FUN_006374f0` `0x206C`, `FUN_00637990` `0x2005`) are separate functions | **Confirmed limitation** — name is **mechanism**, unit is **0x804D-specific** |
| 8 | Runtime / bit-exact verified | No live capture in this dual | **Open** — not sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + out**/in\* + RET | **High** | Wrong wrappers smash stack |
| Opcode `0x804D` sole caller | **High** | Mis-route other special messages |
| Wire u8 + (u64,u16,u16,flag×2)×N | **High** | Map list desync / truncated UI |
| Entry stride 0x18 offsets | **High** | Corrupt instance table |
| ByteBuffer vtable/size/owns/refcount | **High** | Leaks / double-free |
| Data prefix `{0x804D, count, Entry*}` | **High** | Consumer crash on +8 |
| u64 / u16 / flag English meaning | **Low–Medium** | Wrong server pack field order labels |
| size field semantics vs 12-byte header | **Medium** | Over-copy ports if treating size as deep-copy length of entries |
| Clean ≡ raw flag bit extract | **Medium** | Clean abstracts flags — use raw for bit-exact |

---

## 3. Cross-check against raw + bytes

```
raw:
  local_150[0] = 0x804d;
  FUN_0042b3a0(param_2[3], param_2[4]);
  BitStream_readBits(8, …);  count; new[](count*0x18);
  loop: readBits(0x40), (0x10), (0x10), flag, flag; stride +0x18
  size = count*0x18+8; new(0x18) ByteBuffer; vtable 009d7b00; malloc; owns=1
  *param_1 = bb; bb[2]++; release param_2

bytes @ 00637750 (read_memory):
  6A FF 68 9E8D9A00 64A1… 81EC58010000 …          ; SEH + sub esp,0x158
  C744242C4D800000 …                               ; tag 0x804D
  E8… FUN_0042b3a0
  6A08 … E8… BitStream_readBits(8)
  8D2C76 03ED 03ED 03ED …                          ; count*0x18
  … 83C508 …                                       ; size += 8
  C706007B9D00 896E10 … C6461401                   ; vtable, size, owns
  … F3A5 …                                         ; dword copy to malloc data
  834108FF … FF5208                                ; refcount-- / release
  81C464010000 C3                                  ; add esp,0x164; ret

consumer 0080a810:
  count = *(param+4); entries = *(param+8); copy count*0x18; delete[] entries
```

≡ same CF. No evidence of min-distance search, inventory, or mission logic in this unit.

---

## 4. Surviving contract for AutoCore

```csharp
// S2C MapInstanceListResponse (0x804D) special-message unpack (client).
// Wire on BitStream:
//   byte count;
//   for i in 0..count-1:
//     u64 id; u16 a; u16 b; bool f0; bool f1;  // flags are 1-bit each
// Rebuild (client heap):
//   ByteBuffer.data -> { uint tag=0x804D, uint count, Entry* entries }
//   Entry[0x18]: idLo,idHi, fieldA, fieldB, flag0, flag1, pad

public sealed class MapInstanceEntry
{
    public ulong Id;      // wire u64 — English name Tentative
    public ushort A;      // Tentative
    public ushort B;      // Tentative
    public bool Flag0;    // Tentative
    public bool Flag1;    // Tentative
}

// Server pack must match wire bit layout; client rebuild pointer form is client-local.
```

**Port rules:**

- Do **not** deep-copy using ByteBuffer.size as if entries were inline after the 8-byte header without the pointer — consumer expects **`Entry*` at +8**.
- Count is **u8** on wire (max 255).
- Keep opcode **`0x804D`** / `MapInstanceListResponse` coupling.
- Field English names remain open; preserve **order and widths**.

---

## 5. Open questions

1. Map-instance field dictionary (what A/B/flags mean in UI).
2. u64 domain (instance id vs other).
3. Server encoder location / parity test.
4. Whether size `count*0x18+8` is read by any other consumer.

**Verdict:** **accept-with-gaps** — safe behavioral map for AutoCore `MapInstanceListResponse` wire + client rebuild; do not treat entry field names or size-as-inline-blob as sealed.
