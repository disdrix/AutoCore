# Review A (reconstruction fidelity): `aa_00413920` CNDHash_Insert_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413920` |
| **VA** | `0x00413920` |
| **Body** | `0x00413920`–`0x00413a56` (**~311** bytes; `ret 0x14`) |
| **Canonical name** | `CNDHash_Insert_u64` (string family + 64-bit key; leave registry if name collides) |
| **Prior alias** | `Named_VOG_DEBUG_STOP_00413920` (string-weak; superseded for product role) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00413920_CNDHash_Insert_u64.md` |
| **System** | container / inventory-transfer (InventorySheet widget map) |
| **Live tools** | Ghidra `batch_decompile`, `force_decompile`, callees `0x00419b40`/`0x00419bd0`/`0x00419ad0`, `read_memory`, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**64-bit-key CNDHash insert** (inventory sheet widget host). Stack stdcall-like:

`HRESULT Insert(hash*, uint keyLo, uint keyHi, void *value, char softIfExists)` — **`ret 0x14`**.

1. Null `value` → **`0x80004003`** (`E_POINTER`).
2. If `hash+0x1d` lock set → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
3. If `softIfExists != 0` and lookup hits live payload (`node+0xc != 0`) → return **1** (no insert).
4. Else if lookup hits live payload → log `"Duplicate hash insert %u, failing out"` → **`0x80004005`**.
5. Alloc node via freelist helper `FUN_00419bd0` (EDI = `hash+0x20`); node size **0x28** (10 dwords).
6. Init node: vtbl **`PTR_FUN_00a64758`**, flag byte `+8=0`, value `+0xc`, keyLo `+0x18`, keyHi `+0x1c`, list links `+0x20/+0x24`, bucket next `+0x10`.
7. Bucket: `keyLo & *(hash+8)` into table `*(hash+0x10)`; head-insert at sentinel `+4`; `FUN_00419ad0` touch-repair walk.
8. Append ordered list head `+0x14` / tail `+0x18`; `count++` at `+0xc`; return **0**.

Primary sealed caller: `Client_UI_InventorySheet_AddItemWidget` `FUN_008605b0` — key = item `+0x160/+0x164` (COID pair), value = new 0x514 widget.

Twin CF of mission `CNDHash_Insert` `0x0053c360` but **u64 key + 0x28 node + different vtbl**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Pass A/B decompile | `batch_decompile` / `force_decompile` @ `0x00413920` — **identical** |
| Machine | `read_memory` length 320 |
| Lookup | `FUN_00419b40` — chain walk keyLo@+0x18 keyHi@+0x1c |
| Alloc | `FUN_00419bd0` — freelist `* (hash+0x20)`, slab 0x18 nodes × 0x28 |
| Repair | `FUN_00419ad0` — `"HashListError: Went to node we already touched!"` |
| Caller | `FUN_008605b0` @ `0x008605b0` |
| Raw / clean | `raw/aa_00413920_*`, `reconstructed-exact/FUN_00413920.cpp` |

---

## 3. Authoritative body (dual A≡B)

```c
undefined4 FUN_00413920(int param_1, uint param_2, undefined4 param_3, int param_4, char param_5)
{
  // param_1=hash, param_2=keyLo, param_3=keyHi, param_4=value, param_5=softIfExists
  if (param_4 == 0) return 0x80004003;
  if (*(char *)(param_1 + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:insert, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (param_5 != 0) {
    iVar1 = FUN_00419b40(param_2, param_3);  // EDI/EAX bucket context from caller frame
    if (iVar1 != 0 && *(int *)(iVar1 + 0xc) != 0) return 1;
  }
  iVar1 = FUN_00419b40(param_2, param_3);
  if (iVar1 != 0 && *(int *)(iVar1 + 0xc) != 0) {
    FUN_007a4480(0, "Duplicate hash insert %u, failing out", param_2, param_3);
    return 0x80004005;
  }
  // alloc + init + bucket head-insert + list append + count++ → 0
  ...
}
```

Decompiler omits explicit freelist `this` on helpers — machine uses **EDI** = hash / `hash+0x20` per call site.

---

## 4. Layout (this variant)

### Hash object

| Offset | Role |
|---|---|
| `+0x08` | bucket mask |
| `+0x0c` | count |
| `+0x10` | bucket table* |
| `+0x14` | ordered list head |
| `+0x18` | ordered list tail |
| `+0x1d` | traversal lock byte |
| `+0x20` | node freelist head* |

### Node (0x28)

| Offset | Role |
|---|---|
| `+0x00` | vtbl `PTR_FUN_00a64758` |
| `+0x08` | touch flag (byte) |
| `+0x0c` | value* |
| `+0x10` | bucket next |
| `+0x18` / `+0x1c` | keyLo / keyHi |
| `+0x20` / `+0x24` | list next / prev |

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw | **Confirmed** |
| Null → E_POINTER; dup → E_FAIL; soft → 1 | **Confirmed** |
| u64 key + 0x28 node | **High** |
| InventorySheet add is primary consumer | **High** |
| Exact product symbol vs mission CNDHash class | **Probable** (shared HashError) |
| Runtime multi-page insert stress | **Open** |

**Verdict:** **accept-with-gaps.**
