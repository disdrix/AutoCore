# Review A (reconstruction fidelity): `aa_00571830` InventoryGrid_MergeStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571830` |
| **VA** | `0x00571830` |
| **Canonical name** | `InventoryGrid_MergeStackQty` |
| **Prior names** | `FUN_00571830`, `Named_VOG_DEBUG_STOP_00571830` (**reject** — string-only) |
| **Review date** | `2026-07-29` (dual A/B + residual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live bytes) |
| **Counterpart** | `reviews/B_aa_00571830_InventoryGrid_MergeStackQty.md` |
| **Residual scratch** | `reviews/a_00571830.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B + residual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Merge a quantity delta onto an existing cargo/grid stack identified by instance COID.**

1. Find item in `this` grid via `InventoryGrid_FindItemByCoid` (`0x00571010`) using `(coidLo, coidHi)`.
2. Miss → call debug helper with **disabled** flag + `"VOG_DEBUG_STOP"` → return **0**.
3. Hit → `cur = item.vtbl+0x25C()` (GetQty); `item.vtbl+0x260(cur + qtyDelta)` (SetQty).
4. Mark item dirty (`FUN_00512670` → `*(obj+0x17C) |= 0x20000`, walk children `@+0xAC`).
5. If `grid+0x24` (owner object) non-null → dirty owner the same way.
6. Set `grid+0x21 = 1` (grid dirty byte); return **1**.

**Not** footprint place, **not** free-slot search, **not** capacity clamp, **not** CBID/Broken filter.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`; `ret 0x0C` (3 stack args).

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | Prologue `mov edi, ecx`; owner/dirty at `EDI+0x24` / `EDI+0x21`; FindByCoid this |
| stack0 | `int qtyDelta` | `add eax, [esp+0x0C]` after ESI/EDI saved |
| stack1 | `int coidLo` | Pushed as first FindByCoid arg |
| stack2 | `int coidHi` | Entry `mov eax,[esp+0x0C]` then push |

**Returns:** `AL` / low byte **1** success / **0** not found. Epilogue: `B0 01` / `32 C0` + `C2 0C 00`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571830_FUN_00571830.md` |
| Annotated | `docs/reconstruction/raw/aa_00571830_FUN_00571830.annotated.md` |
| Clean (refined) | `docs/reconstruction/reconstructed-exact/InventoryGrid_MergeStackQty.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00571830.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571830_InventoryGrid_MergeStackQty.md` |
| Residual | `docs/reconstruction/reviews/a_00571830.md` |
| Live re-decompile | Ghidra MCP `force_decompile` @ `0x00571830` (2026-07-29) ≡ raw |
| Bytes | Ghidra MCP `read_memory` 128 B @ entry; string `"VOG_DEBUG_STOP"` @ `0x00A15844` |
| P-code | `get_function_pcode` high (vtbl `0x25C`/`0x260`, owner `+0x24`, dirty `+0x21`) |
| Callees | `FUN_00571010`, `FUN_00512670`, `FUN_007a4480` |
| Callers | Recv/Send AddItem, loot place `00945540`, `008012f0`, `00587c00`, `0052aae0` |

**Not performed:** `disassemble_bytes`, Launcher, live memory tests, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save `this` → EDI; load coidLo/Hi; call FindByCoid | **Yes** (bytes) |
| Null → push `"VOG_DEBUG_STOP"`, push `0`, call log helper, `xor al,al`, `ret 0xC` | **Yes** |
| GetQty `vtbl+0x25C` thiscall item | **Yes** (`FF 92 5C 02 00 00`) |
| `add eax, qtyDelta` then SetQty `vtbl+0x260` | **Yes** (`FF 92 60 02 00 00`) |
| `FUN_00512670(item)` | **Yes** (`mov ecx,esi` then call) |
| Load `ECX=[EDI+0x24]`; if non-null `FUN_00512670` | **Yes** (ECX preset — decompiler arg elided) |
| `[EDI+0x21]=1`; `mov al,1`; `ret 0xC` | **Yes** |
| Live decompile body ≡ raw 2026-07-23 | **Yes** |

### 3.1 Contrast: place vs merge

| | This unit `0x00571830` | `0x00571620` PlaceItemFootprint |
|--|--|--|
| Input key | COID lo/hi | item* + origin XY + qty |
| Mutates cells | **No** | Stamps COID per footprint cell |
| Qty path | Get + delta → Set | Set absolute qty |
| Capacity / CanPlace | **None** | CanPlace gate |
| `ret` | `0x0C` | `0x10` |

### 3.2 `"VOG_DEBUG_STOP"` is not the function purpose

Miss path only. `FUN_007a4480(0, …)` **never logs** (enable flag must be `1`). Scaffold alias `Named_VOG_DEBUG_STOP_*` is **wrong**.

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| grid `+0x21` | u8 | dirty / needs-refresh flag set to **1** on success | `mov [edi+0x21], al` |
| grid `+0x24` | ptr | owner object; optional second dirty mark | `mov ecx,[edi+0x24]`; cross-unit store via grid vfunc `+0x18` / CreateCargo |
| item vtbl `+0x25C` | fptr | **GetQty** (0-arg thiscall → EAX) | sealed across Count/FindByCbid/Place |
| item vtbl `+0x260` | fptr | **SetQty** (1 stack arg) | sealed Place / UseItem / Remove |
| item/obj `+0x17C` | u32 | dirty flags; `\| 0x20000` via `FUN_00512670` | callee body |
| item/obj `+0xAC` | ptr | child chain walked by dirty helper | callee body |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Role = stack quantity merge by COID | **High / Sealed** |
| `this` = InventoryGrid | **High / Sealed** (FindByCoid + grid offsets) |
| Canonical `InventoryGrid_MergeStackQty` | **Probable** (behavior); PDB unknown |
| Alias `InventoryGrid_AddQtyByCoid` | **Probable** |
| Scaffold `Named_VOG_DEBUG_STOP_*` | **Falsified** as purpose name |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / `ret 0x0C` | **High** (bytes both exits) |
| Signature (thiscall + delta + coidLo + coidHi) | **High** |
| Control flow | **High** (live ≡ raw ≡ bytes) |
| GetQty/SetQty vtbl slots | **High / Sealed** |
| No capacity clamp in body | **High / Sealed** |
| Owner dirty via `grid+0x24` | **High** (bytes); owner English name **Probable** |
| Grid dirty `@+0x21` | **High** (write); product name **Open** |
| Original symbol | **Open** |
| Runtime / bit-exact | **Open** |

---

## 7. Verdict

**accept-with-gaps.** Static CF, ABI (`ret 0xC`), COID find → qty add → dual dirty marks are **sealed**. No place/capacity path in this unit. Gaps: PDB name, dirty-flag product labels, runtime golden, signedness of `qtyDelta` at product layer.
