# Function record: phySkeleton_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096b930` |
| **Canonical name** | `phySkeleton_unserialize` |
| **Ghidra name** | `FUN_0096b930` |
| **Address** | `0x0096b930`–`0x0096ba79` exclusive (**329 B** / `0x149`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / phy asset I/O (`phySkeleton.cpp`) |
| **Completion status** | **Dual sealed** W38-K — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Unserialize one **phySkeleton** record from a **PSKE** chunk (`tag = 0x50534b45`; on-disk little-endian bytes `"EKSP"`), **chunk version 1 only**.

1. Enter chunk scope on the **stoChunkReader**.
2. Validate tag + version; on failure log (`phySkeleton.cpp` lines `0x3a` / `0x53`) and return **`0xffffffff`**.
3. On success: read bone count (binary vs text via **`reader+0x4044`**), `FUN_0096b150(self, count)`, loop bone pointer vector, `phyBone_unserialize` each, set **`bone+0x144 = index`**, bump **`self+0x1C`**, OR **`self+4 |= 3`**.
4. Leave chunk scope if scope flag set; return count-read status.

## Signature

```c
// stack (self*, reader*); RET 0x08
uint32_t phySkeleton_unserialize(phySkeleton* self, stoChunkReader* reader);
```

## Related

| VA | Role |
|---|---|
| `0x0096e280` | `phyBone_unserialize` — per-bone callee (dual sealed) |
| `0x0096b150` | apply count / prepare bone vector (unowned dual residual) |
| `0x00765740` | gfxBody unserialize parent — two call sites @ body+0x98 |
| `0x00437050` / `0x007689e0` | binary / text int32 readers |
| stoChunk enter / leave | `stoChunkReader_EnterChunkScope` / `FUN_00769e40` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096b930_FUN_0096b930.md` |
| Annotated | `docs/reconstruction/raw/aa_0096b930_FUN_0096b930.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phySkeleton_unserialize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096b930.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0096b930_FUN_0096b930.md` |
| A/B | `docs/reconstruction/reviews/A_aa_0096b930_phySkeleton_unserialize.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-0096b930-004a8100-w38k-report.md` |

## Confidence

| Claim | Level |
|---|---|
| PSKE tag / version 1 / fail `0xffffffff` | **Confirmed** |
| RET 8 / two stack formals | **Confirmed** |
| Bone loop + `+0x144` index | **Confirmed** |
| Binary/text via `reader+0x4044` | **Confirmed** |
| Product field English for `+4` / `+0x1C` | **Open** |
| Runtime / bit-exact | **Open** |
