# Review A (reconstruction fidelity): `aa_007fbb70` FUN_007fbb70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbb70` |
| **VA** | `0x007fbb70` |
| **Body** | `0x007fbb70`–`0x007fbba7` (**~56** bytes; `ret`) |
| **Canonical name** | `FUN_007fbb70` (**leave-FUN**) |
| **Human alias** | `Named_CalleeOf_Client_UI_InventorySheet_RemoveByCoid_007fbb70` — clear selection when removed matches selected |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_007fbb70_FUN_007fbb70.md` |
| **System** | inventory-transfer / client UI |
| **Live tools** | Ghidra dual decompile A/B, `read_memory`, callers |
| **Verdict** | **accept-with-gaps** / **leave-FUN** |

---

## 1. Purpose

**Client host selection clear** when the removed/compared id matches the currently selected object (or selection is empty / id is 0).

Calling convention (machine): **EAX** = client host; **EDX** = compare id (COID/key half or object id — English open).

1. If `EDX == 0` **OR** `*(EAX+0x309c) == 0` **OR** `EDX == *(*(EAX+0x309c)+0x518)` → take clear path; else return.
2. Clear path:
   - `*(byte*)(EAX+0x30b4) = 1`
   - `*(byte*)(EAX+0x30b5) = 0`
   - If `selected = *(EAX+0x309c) != 0`: `selected->vtbl+4(0)` (scalar release / deselect notify).

Sibling context: Grab-path clear helper `aa_007fbbb0` is a different body (held-item UI). This VA is the **small selection-match clear**.

Callers: `FUN_0085fcc0` (InventorySheet RemoveByCoid, after hash remove out-value), `FUN_0088f410`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Pass A/B | `batch_decompile` / `force_decompile` — **identical** |
| Machine | `read_memory` length 60 — `test edx,edx`; loads `+0x309c`, compare `+0x518`; stores `+0x30b4/+0x30b5`; `call [edx+4]` |
| Parent | `FUN_0085fcc0` decompile — calls after out-value retrieve |
| Sibling | `A/B_aa_007fbbb0_*` (do not merge) |
| Raw / clean | `raw/aa_007fbb70_*`, `reconstructed-exact/FUN_007fbb70.cpp` |

---

## 3. Authoritative body (dual A≡B)

```c
void __fastcall FUN_007fbb70(undefined4 param_1, int param_2)
{
  int in_EAX; // host
  // param_2 = EDX compare id
  if (param_2 == 0 || *(int *)(in_EAX + 0x309c) == 0
      || param_2 == *(int *)(*(int *)(in_EAX + 0x309c) + 0x518)) {
    *(undefined1 *)(in_EAX + 0x30b4) = 1;
    *(undefined1 *)(in_EAX + 0x30b5) = 0;
    if (*(int **)(in_EAX + 0x309c) != 0) {
      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
    }
  }
}
```

Decompiler `__fastcall` / `param_1` is noise for unused ECX; live contract is **EAX host + EDX id**.

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B | **Confirmed** |
| Offsets 0x309c / 0x518 / 0x30b4 / 0x30b5 | **Confirmed** |
| Match-or-null → clear flags + optional vtbl+4(0) | **Confirmed** |
| Non-match → pure no-op | **Confirmed** |
| Compare field is COID low dword | **Probable** (RemoveByCoid context) |
| Product name | **None** — leave-FUN |

**Verdict:** **leave-FUN** / **accept-with-gaps.**
