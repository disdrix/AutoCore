# Review A (reconstruction fidelity): `aa_0042bb40` BitStream_writeStringCached

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042bb40` |
| **VA** | `0x0042bb40` |
| **Canonical name** | `BitStream_writeStringCached` (inferred; Ghidra `FUN_0042bb40`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042bb40_BitStream_writeStringCached.md` |
| **System** | net / TNL BitStream string |
| **Evidence pass** | Live `batch_decompile` + `read_memory`; read twin `0x0042ba90`; PackUpdate caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Huffman / compressed string write** with shared cache at `this+0x38`:

1. Null `in` → substitute `DAT_00a1419b` (empty/default string).
2. Compute **common prefix length** vs cache `this+0x38` (stop at mismatch or NUL), capped by `len` (u8).
3. `strncpy` residual into cache; NUL-terminate at `len`.
4. `useCompressed = (prefixLen > 2)`.
5. Ensure capacity for +1 flag bit (grow `+0x5dc` page via realloc if owns); else set error@+0x1c.
6. Write **flag bit**:
   - **compressed:** write flag=1, **u8 prefixLen**, Huffman residual `FUN_0077d960(len - prefixLen)`.
   - **full:** write flag=0, Huffman full `FUN_0077d960(len)`.

**Callers:** `VehicleNet_PackUpdate` (`0x005f5de0`), `FUN_0060a230`, other pack helpers.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042bb40_FUN_0042bb40.md` |
| Annotated | `docs/reconstruction/raw/aa_0042bb40_FUN_0042bb40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0042bb40.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042bb40_FUN_0042bb40.md` |
| Read twin | `0x0042ba90` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = BitStream*
// stack: const char* in, uint len  (len used as u8)
void BitStream_writeStringCached(BitStream *this, const char *in, unsigned len);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI | **High** |
| in | stack; null → `DAT_00a1419b` | **High** |
| len | stack low byte | **High** |
| Compress threshold | **prefixLen > 2** | **High** |
| Grow constant | `+0x5dc` bytes | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Null → default string | **Yes** | **High** |
| Prefix scan vs +0x38 | **Yes** | **High** |
| Cache update via strncpy | **Yes** | **High** |
| Threshold >2 | **Yes** | **High** |
| Capacity / realloc / error | **Yes** | **High** |
| Flag + optional u8 + Huffman | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cached compressed string write | **High** | CF |
| Threshold prefixLen>2 | **High** | `cmp bl,2` / setg |
| Twin of read helper | **High** | pack/unpack pair |
| Huffman table | **Open** | `FUN_0077d960` |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. `FUN_0077d960` alphabet dual.
2. Exact max len vs cache buffer size.
3. Interaction with non-owning streams (error@+0x1c when cannot grow).

**Verdict:** **accept-with-gaps**
