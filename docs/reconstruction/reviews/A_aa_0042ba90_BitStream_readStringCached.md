# Review A (reconstruction fidelity): `aa_0042ba90` BitStream_readStringCached

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ba90` |
| **VA** | `0x0042ba90` |
| **Canonical name** | `BitStream_readStringCached` (inferred; Ghidra `FUN_0042ba90`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042ba90_BitStream_readStringCached.md` |
| **System** | net / TNL BitStream string |
| **Evidence pass** | Live `batch_decompile` + `read_memory`; write twin `0x0042bb40`; UnpackGhost caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Huffman / compressed string read** with **shared cache** at `this+0x38`:

1. If `bitPos > bitMax` → set error@+0x1c and fall through to full decode into out.
2. Else consume **1 flag bit**:
   - **flag=1 (compressed path):** read **u8 prefixLen**; `FUN_0077daf0(this+0x38+prefixLen)` continues Huffman tail into cache; copy C-string from `this+0x38` → `out`.
   - **flag=0 (full path):** `FUN_0077daf0(out)` full Huffman into out; also copy out → `this+0x38` (update cache).

Write twin `BitStream_writeStringCached` (`0x0042bb40`) uses prefix match threshold **>2** for compressed flag.

**Callers:** `VehicleNet_UnpackGhostVehicle` (multiple sites), `FUN_0060a820`, other net unpackers.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042ba90_FUN_0042ba90.md` |
| Annotated | `docs/reconstruction/raw/aa_0042ba90_FUN_0042ba90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0042ba90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042ba90_FUN_0042ba90.md` |
| Write twin | `0x0042bb40` |
| Live | epilogue `ret 4` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = BitStream*
// stack: char* out  (ret 4)
void BitStream_readStringCached(BitStream *this, char *out);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI | **High** |
| out | stack | **High** |
| Cache base | `this+0x38` | **High** |
| Huffman helper | `FUN_0077daf0` | **High role / Tentative name** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Overflow → error@+0x1c | **Yes** | **High** |
| Flag bit advance bitPos | **Yes** | **High** |
| Compressed: u8 + partial Huffman into cache | **Yes** | **High** |
| Full: Huffman into out + cache update | **Yes** | **High** |
| Null-terminated strcpy loops | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cached compressed string read | **High** | flag + prefix + cache |
| Twin of write helper | **High** | callers pack/unpack |
| Huffman alphabet details | **Open** | inside `FUN_0077daf0` |
| Product name | **Tentative** | TNL-style |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. `FUN_0077daf0` Huffman table not dual-sealed here.
2. Max string length / cache size of `this+0x38` region.
3. Error-path still calls full decode — confirm intentional TNL behavior.

**Verdict:** **accept-with-gaps**
