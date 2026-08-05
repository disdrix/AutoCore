# Review A (reconstruction fidelity): `aa_004368b0` stoChunkStreamWindow_ReadHeader16

| Field | Value |
|---|---|
| **Stable ID** | `aa_004368b0` |
| **VA** | `0x004368b0`–`0x004368f9` |
| **Canonical name** | `stoChunkStreamWindow_ReadHeader16` |
| **Prior scaffold** | `FUN_004368b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W17-R |
| **Counterpart** | `reviews/B_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — ESI/EDI ABI, 16 B copy, ensure gate, returns sealed; ensure body + product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + OpenChunk call site) + `get_function_by_address` / callers / callees / xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Read the next **16-byte binary chunk header** from a stoChunk **stream window** into a caller-provided `u32[4]`:

1. Ensure at least 16 bytes remain from the current cursor (refill via `FUN_00435df0` if short).
2. Copy four little-endian dwords from the window buffer.
3. Advance cursor by 16.
4. Return `0` or `−1`.

Used exclusively on the **binary** path of `stoChunkReader_OpenChunk` (`reader+0x4044 == 0`). Text mode never calls this unit.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004368b0_FUN_004368b0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004368b0_FUN_004368b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_ReadHeader16.cpp` |
| Function record | `docs/reconstruction/functions/aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| Live decompile | Ghidra `decompile_function` `0x004368b0` — **≡** raw |
| Live bytes | `read_memory` `0x004368b0` length 128 (body ends `C3` @ `0x004368f9`) |
| Call site | `read_memory` `0x0076a2e0` — `lea esi,[ebp+0x14]; lea edi,[esp+0x18]; call` |
| Sibling context (not owned) | OpenChunk dual `A/B_aa_0076a2c0`; ensure `FUN_00435df0` `0x00435df0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Window | **ESI** |
| Out header | **EDI** (`u32[4]`) |
| Stack args to this unit | **none** |
| Epilogue | plain **`RET`** (`C3`) |
| Return | **0** success; **`0xffffffff`** fail |
| Body | `0x004368b0`–`0x004368f9` |

```c
int32_t stoChunkStreamWindow_ReadHeader16(
    /* ESI */ StoStreamWindow* window,
    /* EDI */ uint32_t out[4]);
```

**Caller proof (OpenChunk binary):**

```
8D 75 14           lea  esi, [ebp+0x14]     ; window = reader + 0x14
8D 7C 24 18        lea  edi, [esp+0x18]     ; 16 B stack header
E8 …               call FUN_004368b0
09 85 2C 40 00 00  or   [ebp+0x402c], eax   ; sticky status
0F 8C …            jl   fail                 ; signed sticky < 0
```

### 3.2 Ensure gate — **SEALED** (call shape); ensure body **out of scope**

```
if (available < cursor + 0x10) {
  push (base + cursor);
  mov  ecx, esi;          // thiscall window
  call FUN_00435df0;
  if (eax < 0 || available < 0x10) return -1;
}
```

| Fact | Confidence |
|---|---|
| Trigger: `available < cursor+16` (signed `jle` enough when `available >= cursor+16`) | **High** |
| Ensure arg = `base + cursor` | **High** |
| Ensure thiscall ECX = window | **High** |
| Fail if `eax < 0` **or** `available < 16` after | **High** |
| Full refill semantics of `FUN_00435df0` | **Not owned** |

### 3.3 Copy + advance — **SEALED**

```
src = (u32*)(window + 0x18 + cursor)
out[0..3] = src[0..3]
cursor += 0x10
return 0
```

Four discrete dword moves (not `rep movsd`) — same effect.

### 3.4 Window offsets — **SEALED**

| Rel | Role | Reader abs (via OpenChunk `+0x14` base) |
|---:|---|---:|
| `+0x04` | cursor | `+0x18` |
| `+0x08` | base | `+0x1c` |
| `+0x0c` | available | `+0x20` |
| `+0x18` | buffer | `+0x2c` |

Matches OpenChunk dual stream-window map.

### 3.5 Header word order — **High**; English names **Probable**

| Index | Plate (OpenChunk) |
|---:|---|
| 0 | tag |
| 1 | size |
| 2 | version |
| 3 | reserved |

Width/order sealed by 16-byte copy; product field names from sibling plate.

### 3.6 Three-rep CF fidelity

| Pass | Source | Match |
|---|---|---|
| Raw 2026-07-23 | `raw/aa_004368b0_FUN_004368b0.md` | baseline |
| Live re-decompile 2026-07-29 | `decompile_function` | **≡** raw |
| Bytes | `read_memory` full body | ABI + gates + copy + RET sealed |
| Call site | OpenChunk @ `0x0076a2ee` | ESI=window, EDI=header |

---

## 4. Call graph (inventory)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | `FUN_00435df0` | `0x00435df0` | ensure/refill |
| Caller | `stoChunkReader_OpenChunk` | `0x0076a2c0` | sole; binary only |

---

## 5. Gaps / open

1. Product English name for this helper.
2. Full `FUN_00435df0` contract (separate OWN VA).
3. Post-ensure cursor value distribution (this unit only re-checks `available >= 16`).
4. Runtime / bit-exact image diff not run.

---

## 6. Verdict

**accept-with-gaps** — binary 16-byte header read contract sealed at High CF; ensure internals and product naming remain open.
