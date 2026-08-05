# Review A (reconstruction fidelity): `aa_005710c0` InventoryGrid_FindItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005710c0` |
| **VA** | `0x005710c0` |
| **Canonical name** | `InventoryGrid_FindItemByCbid` |
| **Prior names** | `FUN_005710c0`, `Named_CalleeOf_Client_QuickBar_ActivateSlot_005710c0` |
| **Review date** | `2026-07-29` (dual A/B + residual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005710c0_InventoryGrid_FindItemByCbid.md` |
| **Residual scratch** | `reviews/a_005710c0.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B + residual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**First matching cargo/grid item by clonebase CBID**, optionally gated by stack room.

1. Traversal-lock the grid item list; walk every object.
2. Match `*(item[+0xA8] + 0x34) == cbid` (clonebase CBID — **not** instance COID).
3. If `skipStackGate != 0`: return that item immediately (Broken ignored).
4. Else: skip **Broken** (bit 19 @ `item+0x17C`); accept if  
   `qty(vtbl+0x25c) + addQty ≤ (maxStack & 0xFFFF)`.
5. Exhaust → unlock → `NULL`.

**Calling convention:** MSVC `__thiscall` — grid in `ECX`; `ret 0x0C` (3 stack args).

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `InventoryGrid*` | `lea ebp,[ecx+0x2c]`; unlock `+0x30`/`+0x54` |
| stack0 | `int cbid` | `cmp [clonebase+0x34], edx` |
| stack1 | `char skipStackGate` | non-zero → early accept at match |
| stack2 | `uint16_t addQty` | zero-extended; capacity headroom |

**Returns:** `Item*` / object pointer, or `NULL`.

**Side effects:** TraversalLock + LeaveCriticalSection unlock; **no** inventory mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005710c0_FUN_005710c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005710c0_FUN_005710c0.annotated.md` |
| Clean (refined) | `docs/reconstruction/reconstructed-exact/InventoryGrid_FindItemByCbid.cpp` |
| Function record | `docs/reconstruction/functions/aa_005710c0_InventoryGrid_FindItemByCbid.md` |
| Residual | `docs/reconstruction/reviews/a_005710c0.md` |
| Sibling CountByCbid | `aa_005711c0` dual + clean |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x005710c0` (2026-07-29) ≡ raw |
| Bytes | Ghidra MCP `read_memory` 256 B @ entry |
| Callees | `FUN_004294f0` (TraversalLock), `FUN_004022a0` (IterateNext), `LeaveCriticalSection` |
| Callers (sample) | `0x005714e0`, `0x0052aae0`, `0x00587c00`, `0x005879e0`, `0x008134d0`, `0x008e40f0`, `0x0060d460`, QuickBar |

**Not performed:** `disassemble_bytes`, Launcher, live memory tests, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `local_iter = 0`; TraversalLock | **Yes** |
| IterateNext → done≠0 → unlock → NULL | **Yes** |
| null object skip | **Yes** |
| clonebase `@item+0xA8`; CBID `@+0x34` | **Yes** (asm `mov eax,[edi+0xa8]` / `cmp [eax+0x34]`) |
| `skipStackGate≠0` → unlock → return item | **Yes** |
| Broken bit19 skip when gate on | **Yes** (`shr 0x13; test 1`) |
| type `@clonebase+0x38==4` → max 999999 | **Yes** (`mov esi, 0xF423F`) |
| else max `*(clonebase+0x3c)+0x4ba` ushort; 0→200 | **Yes** |
| qty vtbl `+0x25c`; compare `qty+addQty ≤ (max&0xFFFF)` | **Yes** (`movzx edx,si`) |
| Infinite do/while until done | **Yes** |
| No grid cell stamp / qty write | **Yes** |

### 3.1 Max-stack effective width (SEALED)

Type-4 loads **999999** (`0x000F423F`) then capacity compare uses **low 16 bits only** (`movzx edx, si` ≡ `max & 0xFFFF` → **16959 / `0x423F`**). Non-type-4 ushort path is already 16-bit; default **200** if field zero.

### 3.2 List embed (SEALED vs sibling “Probable”)

`lea ebp, [ecx+0x2c]` + `mov ecx, ebp` into TraversalLock seals **list subobject at grid+0x2C**. Unlock uses grid+0x54 / +0x30 which equal list+0x28 / +0x04 (same as CountItemsByCbid).

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| grid `+0x2C` | subobj | locked list | `lea ebp,[ecx+0x2c]` |
| grid `+0x30` | CS | LeaveCriticalSection | body + list+4 |
| grid `+0x54` | u8 | traversal held flag | clear then Leave |
| item `+0xA8` | ptr | clonebase (`object[0x2a]`) | asm + sibling |
| item `+0x17C` | u32 | flags (`object[0x5f]`) | bit19 Broken |
| clonebase `+0x34` | i32 | **CBID** | match key |
| clonebase `+0x38` | i32 | type; `4` → huge max path | cmp |
| clonebase `+0x3C` | ptr | def blob | base for +0x4BA |
| def `+0x4BA` | u16 | max stack (0→200) | load |
| vtbl `+0x25C` | method | current quantity | call |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Not instance-COID find | **High / Sealed** — match is CBID |
| Sibling of `InventoryGrid_CountItemsByCbid` | **High** |
| Canonical `InventoryGrid_FindItemByCbid` | **Probable** (behavior); PDB unknown |
| Task label “find-by-COID” | **Rejected** — confuses with `FUN_00571010` / item TFID |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / `ret 0x0C` | **High** |
| Signature (thiscall + cbid, gate, addQty) | **High** |
| Control flow | **High** (live ≡ raw) |
| CBID match key | **High / Sealed** |
| Broken bit19 filter (gated path) | **High** (cross-seal CountByCbid) |
| Max-stack formula + `& 0xFFFF` | **High / Sealed** (bytes) |
| List `@+0x2C` | **High / Sealed** (bytes) |
| `param_3` product name | **Probable** |
| Original symbol | **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

- Runtime golden / differential pack tests
- Original PDB name
- Full type enum for `clonebase+0x38` beyond branch `==4`
- Whether any caller relies on `skipStackGate=1` (CF exists; rarity unenumerated exhaustively)
- QuickBar clean comment still says “COID” — documentation debt outside this dual’s seal scope unless updated
