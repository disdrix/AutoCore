# Dual A/B report — W29-G OWN-ONLY (`0x00496f70`, `0x00518ec0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-G  
**Scope:** VAs `0x00496f70`, `0x00518ec0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` → **W29-G**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00496f70` Class_009c7a1c_Ctor | **accept-with-gaps** — complete ctor CF/ABI/`ret 4`/list@+0x0C/floats sealed; product English open |
| `aa_00518ec0` Object_SharedBase_Dtor | **accept-with-gaps** — shared-base field dtor CF/ABI/CO-list safety/teardown order sealed; product English open |

---

## VA `0x00496f70` — sealed facts

1. **Body:** `0x00496f70`–`0x004970a8` exclusive (**312 B** / `0x138`). Final **`C2 04 00`** (`ret 4`); pad `CC`; next fn complete dtor `0x004970b0`.
2. **ABI:** **`__thiscall`**; ECX=`this`; one stack formal (parent/context*); returns **this** in EAX; clean **4** B.
3. **Semantics:** MSVC **complete-object constructor** for vtbl `PTR_FUN_009c7a1c`:
   - SEH frame `LAB_009a0d1e`.
   - Install vtbl; `+4/+8 = 0x40`.
   - `LEA` list @ `+0x0C`; `FUN_00457c60` → 0x18 self-linked sentinel at `+0x10`; size `+0x14=0`.
   - Zero buffer triples `{0x1C,0x30,0x40,0x9C,0xAC,0xBC}` + cookie-vector `@+0x28`.
   - Flags; `movss` **300.0f** (`DAT_00aaa8a8`) → `+0x54`; **25.0f** (`DAT_00aaa6fc`) → `+0x58`; copy `ctx+0x7d` → `+0x51`; mode `+0x5C=3`.
4. **Classification:** worker (complete ctor body).
5. **Callers (1):** `FUN_004cda90` — factory `operator_new(0xC8)` then this ctor; store @ `parent+0xE898`.
6. **Xrefs:** 1.
7. **Related:** complete dtor twin `Class_009c7a1c_CompleteDtor` `0x004970b0` (W28-M); scalar deleting `FUN_004975e0` (vtbl[0], W29-F).
8. **Name:** `Class_009c7a1c_Ctor` (Ghidra `FUN_00496f70`). Product demangle open; vtbl suffix disambiguates. Legacy Palantir seed is **narrow** — do not promote.
9. **Decompile ≡ raw CF**; ABI/list LEA/floats sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle.  
- Labels for 0x40 pair, mode=3, float fields, buffer payloads.  
- List first dword `this+0x0C` unwritten by body.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00496f70_Class_009c7a1c_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00496f70_Class_009c7a1c_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00496f70_FUN_00496f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00496f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00496f70_FUN_00496f70.md` |
| Function named | `docs/reconstruction/functions/aa_00496f70_Class_009c7a1c_Ctor.md` |

---

## VA `0x00518ec0` — sealed facts

1. **Body:** `0x00518ec0`–`0x005190b1` exclusive (**497 B** / `0x1F1`); pad `CC`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`this`; no stack formals; void; bare **`C3` RET**.
3. **Semantics:** MSVC **shared dual-base / virtual-base field destructor** for client object core:
   - If world@`+0xa4` gate: resolve TFID@`+0x160`; if still self → crash log string + `FUN_004bb970`.
   - Stop iface@`+0x14` (vcall +0x2C, arg 0); stamp `GetTickCount` → `+0x18`.
   - Predicate remove with `this & ~0xFF` pack via `CNDDoubleList_InvokePredicateAndRemove_Inferred` (raw: `FUN_004e2600`).
   - `FUN_0051b8a0`; scalar-delete CS helper@`+0xb0`.
   - `Object_TeardownOwnedFxLists_Inferred` (`FUN_005179e0`, W28-H).
   - Free owned `+0x15c/+0x6c/+0x68/+0x64/+0x70/+0x158` and buffer triples `+0x148/+0x138/+0x124`.
   - Ghidra **false noreturn** on `operator_delete` — fall-through zeros sealed.
4. **Classification:** worker (shared-base field dtor).
5. **Callers:** many complete-object dtors + SEH Unwind frames (**53** xrefs); includes tail-jmp from `Object_009d33c4_CompleteDtor` `0x00575350` (W28-M).
6. **Ctor twin:** `Object_SharedBase_Ctor` `0x00518940` (W22-B).
7. **Name:** `Object_SharedBase_Dtor` (Ghidra `FUN_00518ec0`). **Do not** merge with type-specific complete dtors or scalar wrappers.
8. **Decompile ≡ raw CF order**; list helper renamed live vs 2026-07-23 raw.

### Gaps

- Product English / MSVC demangle for shared base.  
- Full owned-subobject product types.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00518ec0_Object_SharedBase_Dtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00518ec0_Object_SharedBase_Dtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.md` |
| Annotated | `docs/reconstruction/raw/aa_00518ec0_FUN_00518ec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SharedBase_Dtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00518ec0.cpp` |
| Function | `docs/reconstruction/functions/aa_00518ec0_FUN_00518ec0.md` |
| Function named | `docs/reconstruction/functions/aa_00518ec0_Object_SharedBase_Dtor.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00496f70` | Port complete ctor: vtbl first; list sentinel via `00457c60` at +0x10; size 0xC8 from factory; **`ret 4`** + parent context. Pair with `Class_009c7a1c_CompleteDtor`. Keep scalar-deleting (`004975e0`) separate. |
| `00518ec0` | Port **shared-base field dtor** (not scalar). Preserve CO-list safety path; delete fall-through zeros; chain from derived complete dtors (e.g. `00575350`). Pair with `Object_SharedBase_Ctor` (`00518940`). |
| Pair with | `Class_009c7a1c_CompleteDtor` (`0x004970b0`), `Object_SharedBase_Ctor` (`0x00518940`), `Object_TeardownOwnedFxLists_Inferred` (`0x005179e0`), `FUN_00457c60` sentinel factory. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names use vtbl/SharedBase structural roles.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
