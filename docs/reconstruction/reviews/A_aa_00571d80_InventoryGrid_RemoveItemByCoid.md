# Review A (reconstruction fidelity): `aa_00571d80` InventoryGrid_RemoveItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571d80` |
| **VA** | `0x00571d80` |
| **Canonical name** | `InventoryGrid_RemoveItemByCoid` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ sealed bytes) |
| **Counterpart** | `reviews/B_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (WQ8R-D; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin **thiscall** wrapper on an `InventoryGrid*`:

1. `InventoryGrid_FindItemByCoid(this, coidLo, coidHi)` — first list item with COID match.
2. `InventoryGrid_RemoveItem(this, item, **1**, forceFull)` — sealed peel/unstamp/detach.
3. Return Remove's pointer (item\* or null).

**Calling convention:** MSVC `__thiscall` — grid in `ECX`. Callee `RET 0x0C` → **three** stack dwords.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Prologue `MOV ESI, ECX`; both callees re-load ECX from ESI |
| stack0 | `coidLo` | `MOV EDX, [ESP+4]` → push before Find |
| stack1 | `coidHi` | `MOV ECX, [ESP+10]` after staging pushes |
| stack2 | `forceFull` | `MOV EAX, [ESP+0xC]` staged under Find args |

**Returns:** `EAX` from `InventoryGrid_RemoveItem`. Epilogue: `POP ESI; RET 0x0C`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.md` (+ WQ8R-D append) |
| Annotated | `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemByCoid.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| Live decompile | Ghidra MCP ≡ raw 2026-07-23 |
| Live bytes | `read_memory` 64 B @ `0x00571d80` |
| Sealed callees | `aa_00571010` FindByCoid; `aa_00571b80` RemoveItem |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Stage forceFull, save this | **Yes** |
| `push 1; push coidHi; push coidLo; call Find` | **Yes** |
| Rel32 → `0x00571010` | **Confirmed** |
| `push eax; call Remove` | **Yes** |
| Rel32 → `0x00571b80` | **Confirmed** |
| `ret 0x0C` | **Confirmed** (`C2 0C 00`) |
| removeQty always 1 | **Confirmed** (`6A 01`) |

Decompiler corrections:

| Topic | Correction |
|-------|------------|
| `void` return | **ItemObject\*** (EAX from Remove) |
| Free/stdcall 3-arg only | **thiscall** + 3 stack; this in ECX |
| `uVar2 = 1` as generic | **removeQty** imm for RemoveItem |

---

## 4. Evidence table

| Claim | Evidence | Conf |
|---|---|---|
| Body 39 B | Ghidra body `00571d80–00571da6` | **Confirmed** |
| Find + Remove composition | decompile + rel32 | **Confirmed** |
| qty=1 fixed | `push 1` before Find's coid pushes (staged under) | **Confirmed** |
| forceFull pass-through | first load `[esp+0xC]`, still on stack at Remove | **Confirmed** |
| Callers inventory paths | UseItemResponse / sell / reaction handlers | **High** |
| Name `…RemoveItemByCoid` | composition of dualed names | **High** |

---

## 5. Gaps (non-blocking)

1. PDB symbol string unknown.  
2. Runtime peel vs full across all forceFull sites.  
3. Bit-exact / image diff open.

---

## 6. Verdict

**accept** — wrapper is fully byte-sealed; behavior is the sealed Find+Remove composition with qty=1.
