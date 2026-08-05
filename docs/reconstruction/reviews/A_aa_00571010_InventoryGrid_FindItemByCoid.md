# Review A (reconstruction fidelity): `aa_00571010` InventoryGrid_FindItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571010` |
| **VA** | `0x00571010` |
| **Canonical name** | `InventoryGrid_FindItemByCoid` |
| **Prior names** | `FUN_00571010`, `Named_CalleeOf_Client_RecvInventoryEquip_00571010` |
| **Review date** | `2026-07-29` (dual A/B + residual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00571010_InventoryGrid_FindItemByCoid.md` |
| **Residual scratch** | `reviews/a_00571010.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B + residual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**First matching cargo/grid item by instance COID** (64-bit object id as lo/hi dwords).

1. Traversal-lock the grid item list; walk every object.
2. Match `item[+0x160] == coidLo && item[+0x164] == coidHi`.
3. On match: unlock → return item pointer.
4. Exhaust → unlock → `NULL`.

**No** CBID check, **no** Broken filter, **no** stack-capacity gate.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`; `ret 0x08` (2 stack args).

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | `lea esi,[ecx+0x2c]`; unlock `list+0x28`/`list+4` ≡ grid `+0x54`/`+0x30` |
| stack0 | `int coidLo` | `cmp [item+0x160], ebx` |
| stack1 | `int coidHi` | `cmp [item+0x164], ebp` |

**Returns:** `Item*` / object pointer, or `NULL`.

**Side effects:** TraversalLock + LeaveCriticalSection unlock; **no** inventory mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571010_FUN_00571010.md` |
| Annotated | `docs/reconstruction/raw/aa_00571010_FUN_00571010.annotated.md` |
| Clean (refined) | `docs/reconstruction/reconstructed-exact/InventoryGrid_FindItemByCoid.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00571010.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571010_InventoryGrid_FindItemByCoid.md` |
| Residual | `docs/reconstruction/reviews/a_00571010.md` |
| Sibling FindByCbid | `aa_005710c0` dual + clean (contrast) |
| Live re-decompile | Ghidra MCP `batch_decompile` @ `0x00571010` (2026-07-29) ≡ raw |
| Bytes | Ghidra MCP `read_memory` 176 B @ entry |
| Callees | `FUN_004294f0` (TraversalLock), `FUN_004022a0` (IterateNext), `LeaveCriticalSection` |
| Callers (sample) | Equip/Drop/Add/Use Recv handlers; `FUN_00571830` merge; `FUN_00571d80`; `FUN_0060d460`; modify-missing paths |

**Not performed:** `disassemble_bytes`, Launcher, live memory tests, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `iter = 0`; TraversalLock on list | **Yes** (`lea esi,[ecx+0x2c]`; `mov ecx,esi`) |
| IterateNext → done≠0 → unlock → NULL | **Yes** |
| null object skip | **Yes** |
| `item+0x160 == coidLo` | **Yes** (asm `mov edx,[edi+0x160]` / `cmp edx,ebx`) |
| `item+0x164 == coidHi` | **Yes** (asm `mov eax,[edi+0x164]` / `cmp eax,ebp`) |
| match → unlock → return item | **Yes** |
| Infinite while until done | **Yes** |
| No qty / CBID / Broken / place | **Yes** |

### 3.1 List embed (SEALED)

`lea esi, [ecx+0x2C]` + `mov ecx, esi` into TraversalLock seals **list subobject at grid+0x2C**. Unlock uses `cmp [esi+0x28]` / `add esi,4` / LeaveCS → grid+0x54 / +0x30 (same as FindItemByCbid / CountItemsByCbid).

### 3.2 Contrast seal vs `0x005710c0`

Sibling is **CBID** find with optional capacity/Broken. This unit is **COID-only** presence. Same lock/iterate skeleton; different match key and arity (`ret 8` vs `ret 0xC`).

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| grid `+0x2C` | subobj | locked list | `lea esi,[ecx+0x2c]` |
| grid `+0x30` | CS | LeaveCriticalSection | list+4 after `add esi,4` |
| grid `+0x54` | u8 | traversal held flag | `cmp [esi+0x28]` |
| item `+0x160` | i32 | **COID lo** (instance id) | match key |
| item `+0x164` | i32 | **COID hi** | match key |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Find by instance COID (not CBID) | **High / Sealed** |
| Sibling of `InventoryGrid_FindItemByCbid` | **High** (adjacent VA + shared list walk) |
| Canonical `InventoryGrid_FindItemByCoid` | **Probable** (behavior); PDB unknown |
| “COID” vs product “TFID” label for 64-bit pair | **Probable** — layout is the sealed object-id pair; docs/server often use TFID |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / `ret 0x08` | **High** |
| Signature (thiscall + coidLo, coidHi) | **High** |
| Control flow | **High** (live ≡ raw) |
| COID match key | **High / Sealed** |
| Absence of capacity/Broken | **High / Sealed** |
| List `@+0x2C` | **High / Sealed** (bytes) |
| Original symbol | **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

- Runtime golden / differential pack tests
- Original PDB name
- Exhaustive caller arg provenance (all COID sources)
- Multi-COID uniqueness / first-fit semantics if duplicates ever exist
