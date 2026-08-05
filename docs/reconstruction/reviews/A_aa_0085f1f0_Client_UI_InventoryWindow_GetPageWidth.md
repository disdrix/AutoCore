# Review A (reconstruction fidelity): `aa_0085f1f0` Client_UI_InventoryWindow_GetPageWidth

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f1f0` |
| **VA** | `0x0085f1f0` |
| **Canonical name** | `Client_UI_InventoryWindow_GetPageWidth` |
| **Aliases** | `FUN_0085f1f0`, sibling of `Client_UI_InventoryWindow_GetPageHeight` (`0x0085f1d0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — DropHitTest callee residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0085f1f0_Client_UI_InventoryWindow_GetPageWidth.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **page-width getter** for inventory UI windows that host a type/layout object at `window+0x56c`:

```
typeHost = *(window + 0x56c)
return typeHost ? *(i32*)(typeHost + 0x18) : 0
```

Paired with GetPageHeight which loads **`typeHost+0x1c`**. Used by DropHitTest for cell-from-pointer and footprint clamp.

---

## 2. Calling convention — SEALED (bytes)

```text
; 0x0085f1f0
mov eax, [eax+0x56c]
test eax, eax
jz  → xor eax,eax; ret
mov eax, [eax+0x18]
ret
```

| Slot | Role |
|------|------|
| **EAX** (entry) | Inventory UI window* |
| **EAX** (exit) | page width dword, or 0 |
| stack | none |

`read_memory`: `8B 80 6C 05 00 00 85 C0 74 04 8B 40 18 C3 33 C0 C3`.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0085f1f0_*`, `reconstructed-exact/FUN_0085f1f0.cpp` |
| Sibling dual | `A_aa_0085f1d0_Client_UI_InventoryWindow_GetPageHeight` |
| Parent dual | `A_aa_0085f220_Client_UI_InventoryDropHitTest` §5.1 |
| Callers | `0x0085f323`, `0x0085f435`, `0x0085f445` (all in DropHitTest region) |
| Grab/Drop type host | same `window+0x56c` as `ucTypeFrom` source (`+4` on host) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `+0x56c` | **Yes** |
| Null → 0 | **Yes** |
| Else return `*(host+0x18)` | **Yes** |
| No side effects | **Yes** |

---

## 5. Offsets

| Offset | Object | Role | Confidence |
|--------|--------|------|------------|
| `+0x56c` | window | type/layout host* | **High** |
| `+0x18` | type host | page width (X cells) | **High** (role from DropHitTest use) |
| `+0x1c` | type host | page height (sibling) | Cross-unit sealed |

---

## 6. Gaps

1. Product type of host object (grid binder vs inventory-type descriptor).
2. Whether width is always in cells (High from hit-test usage, not English-named in body).
3. Runtime / bit-exact open.

**Verdict:** Trivial leaf sealed with sibling. **accept-with-gaps.**
