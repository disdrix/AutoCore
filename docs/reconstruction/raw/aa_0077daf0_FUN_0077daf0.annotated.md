# Annotated low-level: `aa_0077daf0` BitStream_readString

| Field | Value |
|---|---|
| Stable ID | `aa_0077daf0` |
| VA | `0x0077daf0`–`0x0077dc13` |
| Canonical name | `BitStream_readString` |
| Prior aliases | `FUN_0077daf0`, `Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_0077daf0` |
| System | net / TNL BitStream string (Huffman + raw) |
| Date | 2026-07-29 (W20-K dual seal) |
| Tools | `decompile_function` + `read_memory` only (no `disassemble_bytes`) |

---

## Purpose (sealed structural)

Decode a length-prefixed **C-string** from a TNL-style **BitStream** into `out`:

1. Lazy-init global Huffman tables once (`DAT_00d17a28 == 0` → `FUN_0077d520`).
2. Consume **1 flag bit** from the stream:
   - **flag=1 (Huffman):** read **u8 length**; for each char walk tree at `DAT_00d1eab0` (bit0 → child@+4, bit1 → child@+6); leaf (negative index) maps via alphabet `DAT_00d1eabc` (stride `0xc`, char at node+5 ≡ formula `base + i*-0xc - 7`); write bytes; NUL-terminate; return `1`.
   - **flag=0 or bitPos overflow:** set error@`+0x1c` on overflow; read **u8 length**; `BitStream_readBits(len*8, out)`; NUL-terminate; return `1`.

**Not** the cache layer — that is `BitStream_readStringCached` (`0x0042ba90`), which calls this helper for the residual / full payload.

---

## ABI — sealed

| Fact | Evidence |
|---|---|
| `BitStream* this` in **ESI** | all field accesses via unaff_ESI; no ESI load in prolog; callers in `FUN_0042ba90` keep stream in ESI |
| Stack arg0 = `char* out` | `MOV EBX,[ESP+0C]` after PUSH ECX/EBX |
| Epilogue | plain **`RET`** (`C3`) — **caller cleans 4** (cdecl-like) |
| Return | always **`1`** in AL on both arms (`B0 01`) |
| Body | `0x0077daf0`–`0x0077dc13` |

```c
// ESI = BitStream* this (implicit register convention)
// stack: char* out
// return: uint8_t / bool always 1; caller cleans 4
uint32_t BitStream_readString(char* out /* ESI = BitStream* */);
```

---

## BitStream offsets (this unit)

| Rel | Role | Conf |
|---:|---|---|
| `+0x0c` | bit buffer base (`byte*`) | **High** |
| `+0x18` | bit position (bit index) | **High** |
| `+0x1c` | error / overflow flag (set to 1) | **High** |
| `+0x2c` | bit capacity / max bit index | **High** |

---

## Globals (Huffman)

| Symbol | Role | Conf |
|---|---|---|
| `DAT_00d17a28` | once-init flag (set inside `FUN_0077d520`) | **High** |
| `DAT_00d1eab0` | Huffman tree nodes, **8 B** each: children shorts at `+4` / `+6` | **High** |
| `DAT_00d1eabc` | alphabet / leaf table, **0xc** stride; char byte at **+5** | **High** |
| `DAT_00a1ea68` | frequency seed array consumed by builder `FUN_0077d520` (256 entries) | **High** role / **Open** full table values at runtime |
| `FUN_0077d520` | builds tree + alphabet once | **High** role (not owned) |

**Static image note:** `DAT_00d17a28` / tree / alphabet are BSS (zeros) until first call; builder allocates runtime buffers.

Leaf index math (builder emits `short = -1 - leafIndex`):

```
iVar5 < 0  →  char = *(DAT_00d1eabc + iVar5 * -0xc - 7)
           ≡  *(DAT_00d1eabc + 0xc * (-1 - iVar5) + 5)
```

---

## Control flow map

```
if !DAT_00d17a28: FUN_0077d520()          // build tables once
bitPos = this+0x18
if bitMax < bitPos:
  error@+0x1c = 1
  → RAW path
else:
  consume 1 flag bit; bitPos++
  if flag == 1:
    len = readBits(8) & 0xff
    for i in 0..len-1:
      node = 0
      while node >= 0:
        if bit overflow: error=1; take left child (+4)
        else consume bit:
          bit0 → child@+4; bit1 → child@+6
      out[i] = alphabet_char(node)
    out[len] = 0
    return 1
  else:
    → RAW path
RAW:
  len = readBits(8) & 0xff
  readBits(len*8, out)
  out[len] = 0
  return 1
```

---

## Annotated pseudocode

```c
// BitStream_readString @ 0x0077daf0
// ESI = BitStream*; stack char* out; RET (caller cleans 4); always returns 1

uint32_t BitStream_readString(char* out /* ESI = BitStream* this */)
{
  BitStream* bs = (BitStream*)/*ESI*/;

  if (DAT_00d17a28 == 0)
    FUN_0077d520(); // HuffmanBuildTables

  uint32_t bitPos = bs->bitPos; // +0x18
  if (bs->bitMax /*+0x2c*/ < bitPos) {
    bs->error /*+0x1c*/ = 1;
    goto raw;
  }

  uint8_t b = bs->buf /*+0xc*/[bitPos >> 3];
  bs->bitPos = bitPos + 1;
  if ((b & (1u << (bitPos & 7))) == 0)
    goto raw;

  // Huffman path
  uint32_t len = 0;
  BitStream_readBits(8, &len);
  len &= 0xff;
  for (uint32_t i = 0; i < len; i++) {
    int node = 0;
    do {
      uint32_t p = bs->bitPos;
      if (bs->bitMax < p) {
        bs->error = 1;
        node = *(int16_t*)(DAT_00d1eab0 + 4 + node * 8); // left
      } else {
        uint8_t bb = bs->buf[p >> 3];
        bs->bitPos = p + 1;
        if ((bb & (1u << (p & 7))) == 0)
          node = *(int16_t*)(DAT_00d1eab0 + 4 + node * 8);
        else
          node = *(int16_t*)(DAT_00d1eab0 + 6 + node * 8);
      }
    } while (node >= 0);
    out[i] = *(uint8_t*)(DAT_00d1eabc + node * -0xc - 7);
  }
  out[len] = 0;
  return 1;

raw:
  len = 0;
  BitStream_readBits(8, &len);
  len &= 0xff;
  BitStream_readBits(len * 8, out);
  out[len] = 0;
  return 1;
}
```

---

## Callers / callees

| Dir | Target | Notes |
|---|---|---|
| caller | `BitStream_readStringCached` `0x0042ba90` | two sites: residual into `this+0x38+prefix`, full into `out` |
| callee | `FUN_0077d520` | once-init tables |
| callee | `BitStream_readBits` | length + raw payload / per-tree bits inline |

---

## Gaps

1. Full product / PDB symbol (TNL `BitStream::readString` is structural inference).
2. Exact max string length / whether `out` buffer size is enforced (not in this unit).
3. Runtime values of tree/alphabet (built at first call).
4. Twin write helper `FUN_0077d960` not owned here.
