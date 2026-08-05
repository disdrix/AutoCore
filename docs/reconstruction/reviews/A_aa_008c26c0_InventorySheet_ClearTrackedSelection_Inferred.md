# Review A (reconstruction fidelity): `aa_008c26c0` InventorySheet_ClearTrackedSelection (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c26c0` |
| **VA** | `0x008c26c0` |
| **Canonical name** | `InventorySheet_ClearTrackedSelection` (**INFERRED**) |
| **Ghidra symbol** | `FUN_008c26c0` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_008c26c0_InventorySheet_ClearTrackedSelection_Inferred.md` |
| **System** | `inventory-transfer` (Equip cursor clear nested) |
| **Parent batch** | Equip → `Client_ClearInventoryCursor` `0x007fc150` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**If inventory sheet host tracks a selection object with a non-null subptr, invoke sheet vfunc `+0xb0` to clear it.**

```c
// EAX = sheet/host*
void InventorySheet_ClearTrackedSelection(void) {
  int* win = *(int**)(host + 0x580);
  if (!win) return;
  int tracked = win[0x15d];           // offset 0x574
  if (!tracked) return;
  if (*(int*)(tracked + 0x2b0) == 0) return;
  (*(code**)(*win + 0xb0))(tracked);  // clear selection vfunc
}
```

Mirrors the same `win[0x15d]` / `+0x2b0` / vtbl `+0xb0` pattern already used in DropToGrid pre-send selection clear.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ raw |
| Live bytes | `8B 88 80 05 00 00` (`[eax+0x580]`) … `83 B8 B0 02 00 00 00` (`[tracked+0x2b0]`) |
| Xrefs | **2** — both inside `Client_ClearInventoryCursor` `0x007fc150` (`0x007fc1a1`, `0x007fc1c6`) |
| Parent dual | `A_aa_007fc150_Client_ClearInventoryCursor` |
| Sibling pattern | Drop `0x00860a50` uses `in_EAX[0x15d]` + `+0x2b0` + vtbl `+0xb0` |

---

## 3. Control flow

| Stage | Match |
|---|---|
| Load window from `host+0x580` | **Yes** |
| Null window / null tracked → return | **Yes** |
| Require `tracked+0x2b0 != 0` | **Yes** |
| `window->vtbl+0xb0(tracked)` | **Yes** |
| No other side effects | **Yes** |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Clear tracked selection helper | **High** |
| Equip cursor-clear path consumer | **High** |
| Same offsets as Drop selection clear | **High** |
| Product name of `+0x2b0` field | **Open** |
| Vtbl `+0xb0` English | **Open** (role sealed) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — Equip UI selection clear leaf sealed.
