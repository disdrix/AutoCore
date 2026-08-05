# Review A (reconstruction fidelity): `aa_0085e890` Client_UI_InventoryWindow_ClearBoundItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e890` |
| **VA** | `0x0085e890` |
| **Canonical name** | `Client_UI_InventoryWindow_ClearBoundItem` |
| **Aliases** | `FUN_0085e890`, DropToGrid pre-send clear of `window[0x15d]` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Drop callee residual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live bytes) |
| **Counterpart** | `reviews/B_aa_0085e890_Client_UI_InventoryWindow_ClearBoundItem.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

If inventory UI window has a **bound item pointer** at `window+0x574` (`[0x15d]`) and that item has non-zero field `+0x2b0`, invoke window vtable **`+0xb0(item)`** — the same pre-send clear DropToGrid inlines before packing C2S Drop.

```
item = *(window + 0x574)
if item != 0 && *(item + 0x2b0) != 0:
  window.vtbl[+0xb0](item)
```

---

## 2. Calling convention — SEALED (bytes)

```text
; 0x0085e890
mov eax, [ecx+0x574]      ; window+0x574
test eax, eax
jz  ret
cmp dword ptr [eax+0x2b0], 0
jz  ret
mov edx, [ecx]
push eax                  ; item
call dword ptr [edx+0xb0]
ret
```

| Slot | Role |
|------|------|
| **ECX** | Inventory UI window* (`this`) |
| stack | none (`ret` not `ret N`) |
| return | void |

`read_memory` @ `0x0085e890`: `8B 81 74 05 00 00 85 C0 74 12 83 B8 B0 02 00 00 00 74 09 8B 11 50 FF 92 B0 00 00 00 C3`.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0085e890_*`, `reconstructed-exact/FUN_0085e890.cpp` |
| Live decompile | ≡ raw |
| Live bytes | sealed above |
| Parent Drop | `raw/aa_00860a50` lines 69–72 identical CF (inlined) |
| Callers (xrefs) | `0x007fc1ed`, `0x007fc214` (cursor clear family), `0x008109ce`, `0x00813bc4`, `0x0085fc5d` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `window+0x574` | **Yes** — dword index `0x15d` |
| Null item → no-op | **Yes** |
| Zero `item+0x2b0` → no-op | **Yes** |
| vcall `+0xb0(item)` | **Yes** |
| No return value / no other side effects in body | **Yes** |

---

## 5. Offsets

| Offset | Role | Confidence |
|--------|------|------------|
| window `+0x574` (`[0x15d]`) | bound / selected item* | **High** |
| item `+0x2b0` | validity / “has inventory binding” gate | **High** as gate; English open |
| vtbl `+0xb0` | window method clearing/detaching bound item | **High** as call; product name open |

---

## 6. Gaps

1. Product name of vtbl `+0xb0` and field `+0x2b0`.
2. Whether Drop inlines this vs always calls the helper (Drop body shows **inline** equivalent).
3. Runtime / bit-exact open.

**Verdict:** Leaf clear helper. **accept-with-gaps.**
