# Review A (reconstruction fidelity): `aa_004321b0` NDAssetImage_ReleaseOwnedBuffers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004321b0` |
| **VA** | `0x004321b0`–`0x00432254` (**165 B** / `0xA5`) |
| **Canonical name** | `NDAssetImage_ReleaseOwnedBuffers_Inferred` |
| **Ghidra name** | `FUN_004321b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-A) |
| **Counterpart** | `reviews/B_aa_004321b0_NDAssetImage_ReleaseOwnedBuffers_Inferred.md` |
| **System** | NDAssetImage buffer ownership release |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` full body; sibling TransferFields dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Release owned heap payloads** on an image object held in **ESI**, unless a busy gate at **`+0x38`** is set. Used as create/transfer/decode pre-clear so old buffers do not leak before new ownership is installed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004321b0_FUN_004321b0.md` (+ W24-A append) |
| Annotated | `docs/reconstruction/raw/aa_004321b0_FUN_004321b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDAssetImage_ReleaseOwnedBuffers_Inferred.cpp` |
| Clean Ghidra | `docs/reconstruction/reconstructed-exact/FUN_004321b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004321b0_*.md` |
| Sibling | `aa_00432580` TransferFields (moves same slots) |
| Live | `decompile_function` `0x004321b0`; `read_memory` 256 B; `analyze_function_complete`; IAT `0x009C6524` |

**Not performed:** Launcher, runtime golden, bit-exact image diff.

---

## 3. Signature

```c
// Ghidra: undefined4 FUN_004321b0(void)
// Bytes:  push ebx; xor ebx,ebx; cmp [esi+0x38],ebx; ...
//         mov al,1 / xor al,al; pop ebx; ret
// ESI = image*; no stack formals; return AL bool
```

| Item | Evidence | Conf |
|---|---|---|
| ESI object | all loads `[esi+…]`; callers `mov esi, dest` | **High** |
| No stack formals / plain `ret` | `C3` epilogue both paths | **High** |
| Return 0/1 in AL | `32 C0` fail; `B0 01` success | **High** |
| free via IAT `0x009C6524` | `8B 2D 24 65 9C 00` / `FF D5` | **High** |

---

## 4. Control flow (sealed from bytes + decompile)

```
if *(ESI+0x38) != 0: return 0
if *(ESI+0x1b4) != 0:
  for i = 0 .. *(ESI+0x1a4)-1:
    p = *(*(ESI+0x1b4) + 4*i)
    if p: vtbl[0](p, 1)
  free(*(ESI+0x1b4)); *(ESI+0x1b4) = 0
if *(ESI+0x1ac): free; null
if *(ESI+0x1b0): free; null
if *(ESI+4):     free; null
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Busy gate `+0x38` | **Yes** (`39 5E 38` / `jnz fail`) | **High** |
| Array walk + vtbl(1) | **Yes** (`6A 01 FF 12`) | **High** |
| free array / three blobs | **Yes** (`50 FF D5 83 C4 04`) ×4 sites | **High** |
| Count `+0x1a4` not cleared | **Yes** (no store to +0x1a4) | **High** |
| AL 0/1 + plain ret | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex in raw W24-A append. Spot checks:

| Offset | Bytes | Decode |
|---|---|---|
| +0 | `53 33 DB 39 5E 38` | frame; gate on +0x38 |
| +6 | `0F 85 96 00 00 00` | jnz fail (AL=0) |
| +0x14 | `8B 2D 24 65 9C 00` | EBP = free IAT |
| loop | `6A 01 FF 12` | push 1; call [vtbl] |
| +0x9D | `B0 01 5B C3` | success |
| +0xA1 | `32 C0 5B C3` | fail |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA / note |
|---|---|
| `FUN_004323e0` | create precheck |
| `FUN_00432580` | TransferFields dest pre-clear |
| `FUN_00432b30` | image helper |
| `FUN_00432cb0` | decode-by-format (many internal sites) |

Xrefs: **13**. Callee: **`free`** only.

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / offsets / free order / ABI | **High** |
| Role = release owned image buffers | **High** |
| Family name NDAssetImage | **Probable** (sibling dual; no string here) |
| `+0x38` product English | **Tentative** |
| Sub-object type in `+0x1b4[]` | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for busy gate `+0x38`.
2. Concrete type of `+0x1b4[i]` (only vtbl[0](1) sealed).
3. Whether callers ever rely on stale `+0x1a4` after array free.
4. Live capture during decode/transfer — open.

**Verdict:** **accept-with-gaps** — ABI and release CF sealed; product English remains inferred.
