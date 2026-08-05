# Review A (reconstruction fidelity): `aa_0089c330` UI_RefinePanel_SyncQtyControls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089c330` |
| **VA** | `0x0089c330` |
| **Canonical name** | `UI_RefinePanel_SyncQtyControls_Inferred` |
| **Prior names** | `FUN_0089c330`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0089c330` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0089c330_UI_RefinePanel_SyncQtyControls_Inferred.md` |
| **System** | `inventory-transfer` (refinery UI) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sync **quantity spinner / min-max chrome** on the refine panel for the currently selected coid:

```text
// ESI = refine UI host (decompiler unaff_ESI — thiscall-ish)
if (!DAT_00d1b6d8 || !DAT_00d1b570) return;

entry = CNDHash_LookupByKey(*(DAT_00d1b570+0xf10), *(host+0x5ec))
FUN_00522060(entry, &availQty, host+0x528, host+0x538)  // may leave avail=0

if (!entry || availQty==0):
  host+0x524 = 0
  blank qty text widget host+0x608 (set string empty / hide)
  hide buttons host+0x5f0, +0x5f4, +0x5f8, +0x5fc
  FUN_0089bf50(); return

// clamp selected qty host+0x524 into [1, availQty]
// show qty text "%d" on +0x608
// +0x5f0 / +0x5fc: hide when qty==1 else show   (decrement / min)
// +0x5f4: hide when qty==avail else show        (increment toward max)
// +0x5f8: hide when qty==avail else show        (max / +N)
FUN_0089bf50();  // residual refresh
```

Decompiler CF on the `==1` branches is messy (duplicate compares) but intent is **show/hide paired stepper buttons** from qty vs availability.

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | Refine UI host | Callers `MOV ESI,EDI` then `CALL 0x0089c330` (@ `0x0089c7b3`) |
| Return | `void` | |
| Stack | none | Prologue `sub esp,0x10; push edi` only |

Live prologue (`read_memory`):

```text
0089c330  sub  esp, 0x10
0089c333  push edi
0089c334  mov  edi, [DAT_00d1b6d8]
0089c33a  test edi, edi
0089c33c  jz   ret_far
0089c342  mov  eax, [DAT_00d1b570]
…
```

Uses ESI for host fields (`+0x5ec`, `+0x524`, widgets) — decompiler `unaff_ESI` is real ABI, not noise.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / record | `aa_0089c330_*` |
| Live decompile | Ghidra `batch_decompile` `0x0089c330` |
| Live bytes | `read_memory` `0x0089c330` length 32 |
| Callers | 8× all in `FUN_0089c6c0` (after bind / button paths) |
| Sibling | Bind `0x0089b090`, list `0x0089bc30`, residual `FUN_0089bf50` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Global null gates | **Yes** |
| Lookup coid `host+0x5ec` | **Yes** |
| Zero-avail → clear qty + hide all steppers | **Yes** |
| Clamp qty to `[1, avail]` | **Yes** |
| Qty text `sprintf("%d")` on `+0x608` | **Yes** |
| Button visibility by qty vs 1 / avail | **Yes** (noisy CF, same effect) |
| Terminal `FUN_0089bf50` | **Yes** |

### Offsets (byte)

| Offset | Role |
|--------|------|
| `+0x5ec` | selected coid |
| `+0x524` | selected quantity |
| `+0x528` / `+0x538` | flags into `FUN_00522060` |
| `+0x608` | qty text widget |
| `+0x5f0` / `+0x5fc` | low-side steppers (hide at qty 1) |
| `+0x5f4` / `+0x5f8` | high-side steppers (hide at max) |

Widget visibility via `vtbl+0xd8` (is-visible?) / `+0xd4(show)` / `+0x34c` refresh; text via `+0x3ac`.

---

## 5. Naming / gaps

| Claim | Confidence |
|---|---|
| Role = qty control sync | **High** |
| ESI this | **High** |
| Button product labels (min/max/−/+) | **Tentative** |
| Runtime | **Open** |

---

## 6. Verdict

**accept-with-gaps** — ESI ABI and clamp/visibility CF sealed; decompiler goto noise does not change outcomes.
