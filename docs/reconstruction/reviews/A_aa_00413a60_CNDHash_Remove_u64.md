# Review A (reconstruction fidelity): `aa_00413a60` CNDHash_Remove_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413a60` |
| **VA** | `0x00413a60` |
| **Body** | `0x00413a60`–`0x00413b22` (**~195** bytes; `ret 0x0c`) |
| **Canonical name** | `CNDHash_Remove_u64` |
| **Prior alias** | `Named_VOG_DEBUG_STOP_00413a60` (string-weak) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00413a60_CNDHash_Remove_u64.md` |
| **System** | container / inventory-transfer |
| **Live tools** | Ghidra dual decompile A/B, `read_memory`, callee `FUN_00419b80`, caller `FUN_0085fcc0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**64-bit-key CNDHash remove** with optional **out-value** ownership transfer.

Signature (machine): hash in **EDI**; stack `keyLo`, `keyHi`, `void **outValueOpt`; **`ret 0x0c`**.

1. If `outValue != 0` → `*outValue = 0` first.
2. If lock `hash+0x1d` set → log `"HashError:remove, already locked for traversal"` + `"VOG_DEBUG_STOP"`; continue.
3. Unlink from bucket via `FUN_00419b80(keyLo, keyHi)` (find + splice bucket chain).
4. On miss → **`0x80004005`**.
5. On hit:
   - If `outValue` → `*outValue = node.value` (`+0xc`) then **clear** `node+0xc` (**transfer**, no dtor).
   - Unlink ordered list using head `hash+0x14` / tail `hash+0x18` and node links `+0x20/+0x24`.
   - Reset node vtbl to `PTR_FUN_00a64758`.
   - If payload still non-null (out was null path) → scalar dtor `value->vtbl[0](1)`.
   - Push node onto freelist `hash+0x20`; `count--`; return **0**.

Primary caller: `Client_UI_InventorySheet_RemoveByCoid` `FUN_0085fcc0` — always passes out-value, then clears selection via `FUN_007fbb70` and detaches widget.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Pass A/B | `batch_decompile` / `force_decompile` — **identical** |
| Machine | `read_memory` length 200 — seals early payload clear before freelist |
| Unlink helper | `FUN_00419b80` → `FUN_00419b40` + bucket splice + `FUN_00419ad0` |
| Sibling insert | `aa_00413920` |
| Caller | `FUN_0085fcc0` (`Client_UI_InventorySheet_RemoveByCoid`) |
| Raw / clean | `raw/aa_00413a60_*`, `reconstructed-exact/FUN_00413a60.cpp` |

---

## 3. Authoritative body (dual A≡B)

```c
undefined4 FUN_00413a60(undefined4 param_1, undefined4 param_2, undefined4 *param_3)
{
  // unaff_EDI = hash; param_1=keyLo; param_2=keyHi; param_3=outValue*
  if (param_3) *param_3 = 0;
  if (*(char *)(unaff_EDI + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:remove, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  puVar1 = (undefined4 *)FUN_00419b80(param_1, param_2);
  if (puVar1 == 0) return 0x80004005;
  if (param_3) *param_3 = puVar1[3];   // value @ +0xc
  puVar1[3] = 0;                        // clear BEFORE later dtor check
  // unlink list head/tail via [8]/[9] (= +0x20/+0x24)
  *puVar1 = &PTR_FUN_00a64758;
  if ((undefined4 *)puVar1[3] != 0) {   // only live if out was null
    (*(code *)**(undefined4 **)puVar1[3])(1);
  }
  puVar1[3] = 0;
  *puVar1 = *(undefined4 *)(unaff_EDI + 0x20);  // freelist push (vtable slot reused as next)
  *(undefined4 **)(unaff_EDI + 0x20) = puVar1;
  *(int *)(unaff_EDI + 0xc) += -1;
  return 0;
}
```

**Machine note:** freelist reuses node dword0 as next pointer after vtbl reset — matches `read_memory` store order.

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B | **Confirmed** |
| Miss → E_FAIL; hit → 0 | **Confirmed** |
| Out-value transfer suppresses dtor | **High** (asm clear before dtor) |
| List/bucket unlink | **High** |
| EDI = hash calling convention | **High** (body + caller) |
| Product English | **Probable** |

**Verdict:** **accept-with-gaps.**
