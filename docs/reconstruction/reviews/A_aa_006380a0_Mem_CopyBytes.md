# Review A (reconstruction fidelity): `aa_006380a0` Mem_CopyBytes

| Field | Value |
|---|---|
| **Stable ID** | `aa_006380a0` |
| **VA** | `0x006380a0` |
| **Body span** | `006380a0`–`006380be` (31 B through bare `ret`) |
| **Canonical name** | `Mem_CopyBytes` (structural) |
| **Ghidra name** | `FUN_006380a0` |
| **Review date** | `2026-07-29` (W21-K dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_006380a0_Mem_CopyBytes.md` |
| **System** | `util` / memory |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Generic **forward-only byte copy** (memcpy semantics): copy `n >> 2` dwords from `src` to `dst`, then `n & 3` residual bytes. Leaf helper used by grow/realloc paths and many buffer movers.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006380a0_FUN_006380a0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_006380a0_FUN_006380a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_CopyBytes.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_006380a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006380a0_Mem_CopyBytes.md` |
| Live decompile | Ghidra @ `0x006380a0` — **≡ raw** |
| Bytes | `read_memory` 128 B @ `0x006380a0` |
| Parent duals | `A_aa_005b3370_GrowableArray_DoubleGrow`, `A_aa_005b3300_HBBuffer_GrowRealloc_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x006380a0`)

Hex (31 B through `C3`):

```
8b4c240c568b74240c8bc1578b7c240cc1e902f3a58bc883e103f3a45f5ec3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **31 bytes** through bare `ret` | hex + pad | **Confirmed** |
| `__cdecl` three stack args | bare `C3`; loads from `[esp+…]` | **Confirmed** |
| Arg order **dst, src, n** | after pushes: EDI←`[esp+0xC]` was arg1, ESI←src arg2, ECX←n arg3 | **Confirmed** |
| Dword phase `n>>2` | `shr ecx,2` + `rep movsd` | **Confirmed** |
| Residual `n&3` | `and ecx,3` + `rep movsb` | **Confirmed** |
| Leaf (no call) | no `E8`/`FF 15` in body | **Confirmed** |
| Forward-only (not memmove) | ESI/EDI only increase | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Dword loop `n>>2` | **Yes** (decompile for-loop ≡ `rep movsd`) |
| Byte loop `n&3` | **Yes** (≡ `rep movsb`) |
| Arg order dst/src/n | **Yes** |
| No return value | **Yes** |
| No callees | **Yes** |

---

## 5. Caller usage (context only)

| Parent | Role of this unit |
|---|---|
| `FUN_005b3370` GrowableArray_DoubleGrow | copy `count * elemSize` old→new |
| `FUN_005b3300` HB grow | same pattern |
| `FUN_00640010` / `00640580` / string helpers | copy `len+1` style ranges |
| 40+ other sites | generic POD relocate into fresh buffers |

---

## 6. Gaps

1. Product/PDB English symbol — open (`Mem_CopyBytes` structural).
2. Runtime / bit-exact differential — open (standard memcpy).
3. Exhaustive caller semantic catalog — not required for leaf seal.

**Verdict:** **accept**
