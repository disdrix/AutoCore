# Review A (reconstruction fidelity): `aa_00571b60` InventoryGrid_ContainsItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b60` |
| **VA** | `0x00571b60` |
| **Canonical name** | `InventoryGrid_ContainsItem` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw bytes) |
| **Counterpart** | `reviews/B_aa_00571b60_InventoryGrid_ContainsItem.md` |
| **Residual scratch** | `reviews/a_00571b60.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (byte-sealed thin wrapper) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**List-membership predicate** for an inventory grid: returns whether the given item pointer is already present in the grid's embedded item list at `grid+0x2c`.

This is **not** a cell-array occupancy / CanPlace test. Call sites (notably `Client_RecvInventoryDropResponse`) combine this with item position vfuncs `+0x250/+0x254` to decide whether `PlaceItemFootprint` is needed — that *role* is “already placed here?”; the **body** is only list contains.

```text
ContainsItem(grid, item):
  if item == NULL: return 0
  return List_Contains(grid + 0x2c, item)   // FUN_00415c00 tail
```

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Callee `RET 4` → **one** stack dword.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | `ADD ECX, 0x2C` before tail to list op |
| stack0 | `ItemObject*` | `MOV EAX,[ESP+4]`; null test; rewrite as callee arg |

**Returns:** `AL` bool — **1** found / **0** null or not in list. High bytes of EAX not meaningful on null path (`XOR AL,AL`).

**Side effects:** none of its own; may take/leave critical section inside `FUN_00415c00` (list TraversalLock).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571b60_FUN_00571b60.md` |
| Annotated | `docs/reconstruction/raw/aa_00571b60_FUN_00571b60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_ContainsItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571b60_InventoryGrid_ContainsItem.md` |
| Prior scaffold | `FUN_00571b60.cpp` / `aa_00571b60_FUN_00571b60.md` (2026-07-23) |
| Live bytes | Ghidra `read_memory` `0x00571b60` len 25 |
| Live decompile | `force_decompile` / `decompile_function` @ `0x00571b60` (thin; args lost) |
| Callee context | decompile + `read_memory` `FUN_00415c00` @ `0x00415c00` |
| Sibling place | `aa_00571620` stamps then `FUN_00566f00(grid+0x2c, item)` |
| Callers (xref) | `00813730`, `0080d570`, `0080d930`, `00810670`, `0084b770`, `008c03c0`, `0093d110`, `009440e0`, `00944d50` |

**Not performed:** `disassemble_bytes`, Launcher, CE live membership dump, bit-exact.

---

## 3. Byte body (sealed)

`read_memory` @ `0x00571b60` (25 B):

```text
8B 44 24 04     mov  eax, [esp+4]      ; item
85 C0           test eax, eax
75 05           jnz  +5                ; → 00571b6d
32 C0           xor  al, al            ; return 0
C2 04 00        ret  4
89 44 24 04     mov  [esp+4], eax      ; stack arg = item for callee
83 C1 2C        add  ecx, 0x2C         ; this = grid + 0x2c
E9 87 40 EA FF  jmp  FUN_00415c00      ; tail call (rel → 0x00415c00)
```

| Claim | Byte seal |
|-------|-----------|
| One stack arg, `RET 4` | `C2 04 00` |
| Null item → 0 | `TEST` / `XOR AL,AL` / `RET` |
| List base `grid+0x2c` | `83 C1 2C` |
| Tail to `0x00415c00` | `E9` rel: `0x00571b79 + 0xFFEA4087 = 0x00415c00` |
| No local loops / cell math | 25 B total; no `IMUL` / cell base |

### Callee role (supporting, not owned)

`FUN_00415c00(this=list, item)` (decompile + partial bytes): TraversalLock (`FUN_004294f0`), iterate via `FUN_004022a0`, compare node value to `item`, return **1** on match else **0**, unlock. Matches “list contains pointer”.

---

## 4. Control flow: clean ≡ bytes

| Stage | Match |
|---|---|
| Null stack item → `AL=0`, `RET 4` | **Yes** |
| Else ECX += 0x2C | **Yes** |
| Tail-call `FUN_00415c00(list, item)` | **Yes** |
| Return callee AL | **Yes** (tail) |

### Corrections vs scaffold decompiler

| Topic | Correction |
|-------|------------|
| Signature `FUN_00571b60(int only)` | **thiscall** grid + one item arg |
| `FUN_00415c00()` no args | `this=grid+0x2c`, stack item |
| “Occupancy” = cell COID | **No** — list membership only |
| Self-call in scaffold notes | Noise; not present |

---

## 5. Call-site role (DropResponse)

`Client_RecvInventoryDropResponse` non-swap path:

```c
already = ContainsItem(grid, dropItem);   // FUN_00571b60 — ECX = target grid
atX = dropItem.vtbl+0x250();
atY = dropItem.vtbl+0x254();
if (!already || atX != locX || atY != locY)
  PlaceItemFootprint(grid, dropItem, locX, locY, qty);
```

So partition-map phrase **“Occupancy check before place”** = **usage**. Body seal name = **ContainsItem**.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null → false, RET 4 | **Confirmed** | Bytes |
| thiscall + `ADD ECX,0x2C` | **Confirmed** | Bytes |
| Tail `FUN_00415c00` | **Confirmed** | Rel decode |
| Predicate = item in list at +0x2c | **High** | Callee decompile + Place list attach sibling |
| Not cell occupancy / CanPlace | **Confirmed** | No cell loads |
| Product name `ContainsItem` | **High** | Role; PDB open |
| Exact list node layout | **Open** | Owned by `00415c00` / `004022a0` |
| Runtime / bit-exact | **Open** | Deferred |

---

## 7. Gaps / open (do not block accept-with-gaps)

1. **Deep list type** — node offsets / CS layout inside `FUN_00415c00` not re-sealed here (out of unit).
2. **PDB / retail English name** — open.
3. **Runtime** — no live CE proof of true/false for known grid membership.
4. **Bit-exact / differential** — open.

---

## 8. Verdict

### **accept-with-gaps**

Thin wrapper is **byte-sealed**. Semantic role is list membership at `grid+0x2c`, used by place pipelines as “already on grid?”. Cell occupancy remains CanPlace / cell array (`+0x28`).

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Full body bytes decoded | **Pass** |
| ABI `RET 4` + thiscall | **Pass** |
| List base +0x2c | **Pass** |
| Distinguishes from CanPlace | **Pass** |
| Call-site Drop gate documented | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
