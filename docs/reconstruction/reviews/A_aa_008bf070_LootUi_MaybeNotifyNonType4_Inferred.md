# Review A (reconstruction fidelity): `aa_008bf070` LootUi_MaybeNotifyNonType4 (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bf070` |
| **VA** | `0x008bf070` |
| **Canonical name** | `LootUi_MaybeNotifyNonType4` (**INFERRED**) |
| **Ghidra symbol** | `FUN_008bf070` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_008bf070_LootUi_MaybeNotifyNonType4_Inferred.md` |
| **System** | `inventory-transfer` (AddItem/loot UI) |
| **Parent batch** | AddItem → `Inv_lootpickup` sole xref `0x009457f7` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Conditional loot/UI side-notify after place** — only when global gates pass and item clone type ≠ 4:

```c
// EAX = item*; ESI = ui/host* (register)
void LootUi_MaybeNotifyNonType4(void) {
  if (DAT_00d1a8f0 == 0) return;
  if (item == 0) return;
  if (*(int*)(*(item + 0xA8) + 0x38) == 4) return;  // type-4 skip (currency-class family)
  if (DAT_00d1a8dd != 0) return;
  FUN_004104f0(*(ESI + 0x510));
  FUN_008bee80();
}
```

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ raw |
| Live bytes | `83 EC 08  80 3D F0 A8 D1 00 00  …  83 79 38 04  …  80 3D DD A8 D1 00 00` |
| Xrefs | **1** — `0x009457f7` lootpickup |
| Raw | `raw/aa_008bf070_FUN_008bf070.md` |

---

## 3. Control flow

| Gate | Effect | Confidence |
|---|---|---|
| `DAT_00d1a8f0 == 0` | no-op | **High** |
| item (EAX) null | no-op | **High** |
| `clonebase+0x38 == 4` | no-op | **High** |
| `DAT_00d1a8dd != 0` | no-op | **High** |
| else `FUN_004104f0(host+0x510)` + `FUN_008bee80()` | UI notify chain | **High** CF; names open |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Type-4 suppressed notify | **High** |
| Lootpickup-only | **High** |
| Global flag product names | **Open** |
| `FUN_004104f0` / `FUN_008bee80` roles | **Open** (call-through) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — loot UI notify gate sealed; callee product names open.
