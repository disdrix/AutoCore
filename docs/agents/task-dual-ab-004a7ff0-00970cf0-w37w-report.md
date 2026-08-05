# Dual A/B report — W37-W OWN `aa_004a7ff0` + `aa_00970cf0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-W  
**Scope:** VAs `0x004a7ff0`, `0x00970cf0` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `get_function_by_address` + callers/xrefs/callees + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-W).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004a7ff0` StdVector_InsertOne_RebindIt_BasicStringW | **accept-with-gaps** — thiscall insert-one RET 0x0C; stride 0x1c; count=1 rebind sealed; product demangle open |
| `aa_00970cf0` AssPreloader_Ctor_Inferred | **accept-with-gaps** — RET 8 / 0x114 / vtbl+event+trees+4×CS+host@+0x110 sealed; product English + bank roles open |

---

## VA `0x004a7ff0` — sealed facts

1. **Body:** `0x004a7ff0`–`0x004a8063` exclusive (**115 B** / `0x73`; pad `CC`).
2. **ABI:** **`__thiscall`**; ECX=`vector*`; stack **`outIt*`**, **`where*`**, **`value*`**; void; **`RET 0x0C`** (`C2 0C 00`).
3. **Semantics:** MSVC-style **insert-one + iterator rebind** for `basic_string<wchar_t>` (elem **0x1c**):
   - `index = empty ? 0 : (where - begin) / 0x1c` (magic `0x92492493`).
   - `StdVector_InsertN_BasicStringW(where, count=1, value)` — may realloc.
   - `*outIt = begin' + index * 0x1c` (re-read begin after call).
4. **Classification:** worker (thin insert-n wrapper).
5. **Callers (1):** `FUN_004a8100` @ `0x004a817d` — push_back slow path when size==capacity (fast path: `FUN_004a74f0` fill-one at end).
6. **Callees:** `FUN_004a7ad0` / `StdVector_InsertN_BasicStringW` (W34-R).
7. **Name:** `StdVector_InsertOne_RebindIt_BasicStringW` (Ghidra `FUN_004a7ff0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*attachmentRe*`. Twins: dword `0x0040dbf0`; RcElem28 `0x004612d0`.
8. **Decompile ≡ bytes** for CF/stride/count/RET. Full hex: raw W37-W append (115 B).

### Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact under realloc.  
- Parent `FUN_004a8100` dual not owned.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a7ff0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a7ff0_FUN_004a7ff0.md` |
| Function named | `docs/reconstruction/functions/aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md` |

---

## VA `0x00970cf0` — sealed facts

1. **Body:** `0x00970cf0`–`0x00970e4c` exclusive (**348 B** / `0x15C`; pad `CC` then retire `00970e50`).
2. **ABI:** stack **`self*`**, **`host*`**; returns **`self*`** in EAX; **`RET 0x08`** (`C2 08 00`). **Not** thiscall (parent: `push host; push mem; call`).
3. **Semantics:** AssPreloader **placement ctor** for object size **0x114**:
   - vtbl `PTR_FUN_00aa9a94` (vtbl[0] = scalar-deleting dtor `FUN_00481270`).
   - `CreateEventA(0,0,0,0)` → handle `@+0x04`.
   - Map head: `StdTree_AllocNode_0x1c` (`FUN_005ae2b0`) → `@+0x14` isnil/circular; size `@+0x18`.
   - Four GuardedVector+CS banks (CS `@+0x30/+0x60/+0x90/+0xC0`, lockEnable=1).
   - Seed ring header usable as GuardedVector `this` `@+0xAC` (CS `@+0xC0` = header+0x14; lockEnable `@+0xD8` = header+0x2c) — ensure seeds here.
   - Second tree: `RbTree_AllocEmptyNode` (`FUN_00439770`) → `@+0xE0`.
   - Host back-pointer `@+0x110` = param_2 (cache host for enqueue/worker family).
4. **Classification:** worker (constructor).
5. **Callers (1):** `AssManager_EnsureAssPreloader_Inferred` (`FUN_0075d3c0`, W33-O) @ `0x0075d405`.
6. **Callees:** IAT `CreateEventA` `[0x009c61fc]`; IAT `InitializeCriticalSection` `[0x009c61ec]` ×4; `FUN_005ae2b0`; `FUN_00439770`.
7. **Name:** `AssPreloader_Ctor_Inferred` (Ghidra `FUN_00970cf0`). **Reject** scaffold `Named_CalleeOf_*Client_InitI*`.
8. **Decompile ≡ bytes** for CF/layout/RET. Full hex: raw W37-W append (348 B).

### Gaps

- Product class/method English.  
- Exact product roles of GuardedVector banks A–C.  
- SEH partial-construction teardown plate.  
- Second tree element product type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970cf0_AssPreloader_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970cf0_AssPreloader_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970cf0_FUN_00970cf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00970cf0_FUN_00970cf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970cf0.cpp` |
| Function | `docs/reconstruction/functions/aa_00970cf0_FUN_00970cf0.md` |
| Function named | `docs/reconstruction/functions/aa_00970cf0_AssPreloader_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a7ff0` | Port as **`vector<wstring>::insert` one-element + rebind**: thiscall + **RET 0x0C**; stride **0x1c**; always `count=1`. Save index before insert-n; rebind from post-insert begin. Do **not** unify with dword twin `0040dbf0` or RcElem28 customcc twin `004612d0`. Used by push_back slow path when capacity full. |
| `00970cf0` | Port as **AssPreloader placement ctor** after `new(0x114)`: stack `(self, host)` **RET 8**; vtbl+event+map head+4×CS banks+second tree+`host@+0x110`. Ensure seeds ring `@+0xAC` **after** ctor returns. Do **not** fold seed list-walk into this VA. |
| Pair with | W34-R `StdVector_InsertN_BasicStringW` (`0x004a7ad0`); W33-O `AssManager_EnsureAssPreloader_Inferred` (`0x0075d3c0`); W32-N GuardedVector locked push; AssPreloader retire/enqueue/worker duals (cache `@+0x110`). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004a7ad0` | insert-n callee (W34-R) |
| `0x004a8100` | push_back parent of insert-one |
| `0x004a74f0` | uninit fill-n (push_back fast path) |
| `0x0075d3c0` | sole AssPreloader ensure parent (W33-O) |
| `0x005ae2b0` | map head alloc (W16-G dual) |
| `0x00439770` | second tree head alloc (W18-S) |
| `0x0043e7f0` | locked ring push used by ensure seed |
| `0x00970e50` | AssPreloader retire method (next function) |

Closes W37-W OWN pair: the insert-one rebind wrapper left open under W34-R insert-n, and the AssPreloader ctor left open under W33-O ensure.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004a7ff0-00970cf0-w37w-report.md` |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / `BasicStringW_0x1c` / explicit offsets).  
- Terminal coverage: **false** (no Launcher / runtime / bit-exact Confirmed).
