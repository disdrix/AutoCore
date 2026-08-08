# Review A (reconstruction fidelity): `aa_00522000` Character_GetEquipTfidTableCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522000` |
| **VA** | `0x00522000`–`0x00522016` |
| **Body** | **23 B** / `0x17` |
| **Canonical name** | `Character_GetEquipTfidTableCount_Inferred` |
| **Ghidra symbol** | `FUN_00522000` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00522000` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-100 dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent dual / context** | `0x008e5ce0` Client_UI_CraftHost_BindObjectByTfid_Inferred |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` + `read_memory` (entry + 7 call sites). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Character equip-TFID table count** leaf:

```text
EAX = min(8, (*(uint8_t*)(ECX + 0x59a) >> 1) + 3)
```

Callers use the return as the exclusive upper bound when scanning the equip TFID array at **`character+0x5a0`** (8-byte `lo`/`hi` pairs). Does not read the table itself.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` / `force_decompile` @ `0x00522000` |
| Bytes | `read_memory` 32 B @ entry → `0fb6819a050000d1e883c00383f8087c05b808000000c3` + `CC` pad |
| Disasm | `disassemble_function` — MOVZX/SHR/ADD/CMP/JL/MOV/RET |
| Bounds | `get_function_by_address` body `00522000`–`00522016` |
| Callers | `get_function_callers` → 5 named + `get_xrefs_to` → 7 UNCONDITIONAL_CALL |
| Callees | none |
| Call-site ECX | `read_memory` @ `008e5d70`, `008e61b4`, `008b2f11`, `008b342c`, `008b368d`, `008b31e7`, `008e83b8` — all `mov ecx,[DAT_00d1b6d8]` |
| Parent dual | `A_aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` |
| Raw / annotated / clean | `aa_00522000_*`, `Character_GetEquipTfidTableCount_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **23 B** `00522000`–`00522016` | **Confirmed** | bounds + byte count + pad `CC` |
| ECX = Character* / bare RET | **Confirmed** | `movzx … [ecx+0x59a]`; `C3`; 7 call sites load `DAT_00d1b6d8` into ECX |
| Formula `(byte>>1)+3` clamp 8 | **Confirmed** | decompile ≡ disasm ≡ hex |
| Leaf (no callees) | **Confirmed** | `get_function_callees` empty; no xrefs-from |
| Role = equip TFID table count | **High** | every named caller walks `+0x5a0` with returned bound |
| Base 3 / max 8 semantics | **High** | UI null-char path hardcodes **8**; formula base **+3** |
| Product English of `+0x59a` | **Inferred** | also written by SetLevelWithFlags; name open |
| Mission-UI scaffold name | **Falsified** | deep Named_CalleeOf chain only |
| Stack formals / RET n | **Falsified** | bare RET; no stack traffic |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `*(uint8*)(this+0x59a)` zero-extend | Yes |
| `>> 1` | Yes |
| `+ 3` | Yes |
| Clamp at 8 (`cmp 8` / `jl` / `mov 8`) | Yes (decompiler `7 < bVar1`) |
| Return in EAX | Yes |
| No side effects / no callees | Yes |

### Body

| Field | Value |
|---|---|
| Start | `0x00522000` |
| End inclusive | `0x00522016` |
| Size | **23 B** (`0x17`) |
| Pad | `CC` → sibling `FUN_00522020` @ `0x00522020` |

### Offsets

| Off | Role | Confidence |
|----:|------|------------|
| `this+0x59a` | uint8 equip-slot budget | **Confirmed** load |
| `this+0x5a0` | equip TFID table base (callers) | **High** |

---

## 5. Callers (context, not owned)

| Function | Call site | Pattern |
|---|---|---|
| `FUN_008e5ce0` (dualed craft bind) | `008e5d80` | ECX=local char; loop `+0x5a0` match TFID |
| `FUN_008e5e00` | `008e61c4` | same table resolve-all |
| `FUN_008b2f00` | `008b2f21` | resolve + tally occupied |
| `FUN_008b3400` | `008b343c` | UI fill; null → store 8 |
| `FUN_008b3670` | `008b369d` | UI fill; null → store 8 |
| (range) | `008b31f7`, `008e83c8` | same ECX load + call |

---

## 6. Gaps / open

1. Product/PDB method English and field name for `+0x59a`.
2. Full gameplay meaning of the low bit of `+0x59a` (ignored by `>>1`).
3. Runtime / bit-exact / differential.
4. Unbounded function ranges for xrefs `008b31f7` / `008e83c8` (bytes still show same ABI).

**Verdict:** **accept**
