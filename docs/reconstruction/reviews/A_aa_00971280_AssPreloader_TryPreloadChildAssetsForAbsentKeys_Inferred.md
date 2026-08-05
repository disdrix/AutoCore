# Review A (reconstruction fidelity): `aa_00971280` AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971280` |
| **VA** | `0x00971280`–`0x00971472` (**498 B**) |
| **Canonical name** | `AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred` |
| **Ghidra name** | `FUN_00971280` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-J) |
| **Counterpart** | `reviews/B_aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` / `batch_decompile` + `read_memory` (full 498 B) + `analyze_function_complete` + caller @ `009722cd` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

For keys absent from AssPreloader membership tree, try virtual child-asset preload; on success record stride-2 pair + tree mark; on failure log product PRELOAD line and push key to fail ring.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971280_FUN_00971280.md` (+ W32-J hex append) |
| Annotated | `docs/reconstruction/raw/aa_00971280_FUN_00971280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971280.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971280_FUN_00971280.md` |
| Named record | `docs/reconstruction/functions/aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` |
| Live | decompile CF + full body hex; `RET 8`; product path `assPreloader.cpp` |

---

## 3. Signature (sealed)

```c
// stack (AssPreloader* host, KeyVec* keys); RET 8; void
void AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred(
    void* host /*stack*/,
    void* key_vec /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | Stack; `MOV EBP,[ESP+…]`; caller `push host` | **High** |
| key_vec | Stack; `MOV EDI,[ESP+…]`; loop `[+4]→[+8]` | **High** |
| cleanup | **`RET 8`** | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
for key* in [vec.begin, vec.end):
  FUN_00970fc0()  // EAX=host
  it = lower_bound(host+0xDC, key)   // FUN_0044a860
  if it != end_hdr(host+0xE0): continue
  snapshot children: FUN_0043c5f0(*(host+0x110)+0x28 → local)
  for child in local:
    r = child->vtbl[+0x0C](key*)
    if r:
      push_stride2(host+0x4C, {*key, r})  // optional CS +0x60
      *find_or_insert(host+0xDC, key) = 1
      goto join
  log PRELOAD unable…; push_back(host+0x7C, key)  // optional CS +0x90
join:
  Sleep(0); destroy local
```

| Stage | Match | Conf |
|---|---|---|
| Flat vec iterate + RET 8 | **Yes** | **High** |
| Absent-tree gate (`+0xDC` / `+0xE0`) | **Yes** | **High** |
| Child snapshot + vtbl+0xC | **Yes** | **High** |
| Success: +0x4C stride-2 + tree=1 | **Yes** | **High** |
| Fail: product log + +0x7C push | **Yes** | **High** |

---

## 5. Gaps (explicit)

- Product/PDB method English (name **Inferred**).
- Nested bodies: `FUN_00970fc0`, `FUN_0043c5f0`/`0043c730`, child vtbl, `FUN_0043d700` product plates (not owned).
- Exact element type of key / child result beyond dword POD.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, CF, host offsets, product log path, and success/fail polarity. Residual nested product + runtime → **accept-with-gaps**.
