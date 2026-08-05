# Dual A/B report — W21-E OWN-ONLY (`aa_0051b5f0`, `aa_005210b0`)

**Date:** 2026-07-29  
**Agent:** W21-E OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051b5f0`, `0x005210b0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b5f0` StdDeque_ThrowTooLong_0051b5f0 | **accept** — deque `"deque<T> too long"` noreturn throw sealed (112 B + plate + ThrowInfo) |
| `aa_005210b0` Character_ClearEquippedRaceItemTfId_Inferred | **accept** — race-item TFID teardown (resolve + deferred enqueue + null template) sealed (124 B) |

---

## Sealed facts — `0x0051b5f0`

1. **ABI:** no formals; SEH frame; **noreturn**. Body **`0x0051b5f0`–`0x0051b65f`** (**112 bytes**).

2. **Plate string:** `0x00a31520` = **`"deque<T> too long"`** (`read_memory`).

3. **Algorithm:** `basic_string` ctor → `exception::exception` (vftable `PTR_FUN_009c7628`) → message copy-construct (vftable `PTR_FUN_009c7634`) → `_CxxThrowException(&ex, &DAT_00acc388)`.

4. **ThrowInfo:** `DAT_00acc388` pushed as second throw arg (same family as vector `_Xlen` helpers).

5. **Role:** MSVC **`deque::_Xlen()`-class** overflow throw. Caller: `FUN_0051c3b0` (deque map grow overflow arm used by skill deferred-cast id queue).

6. **Name:** `StdDeque_ThrowTooLong_0051b5f0` — role-sealed **INFERRED** from plate + CF. Ghidra: `FUN_0051b5f0`. VA-qualified clean name avoids collision with sibling plate clones (`FUN_0040ff30`, `FUN_00436860`, `FUN_005b2a80`).

---

## Sealed facts — `0x005210b0`

1. **ABI:** `void Character_ClearEquippedRaceItemTfId_Inferred(void *self /*ECX*/)` — **no stack formals**, plain **`ret`**. Decomp surface `__fastcall`; bytes `mov edi,ecx`.

2. **Body:** `0x005210b0`–`0x0052112b` (**124 bytes**).

3. **Fields:** TFID_16 cache at **`this+0x518`**; host via `*( *(this+4)+4 + this + 0xa8 )`. Does **not** touch CBID `this+0x514`.

4. **Algorithm:** if TFID present and host non-null → `Object_ResolveFromTFID` (bytes: thiscall on `*(host+0xe4e8)`) → optional `Object_EnqueueDeferredOnce(host, obj)` → copy null template from `DAT_009cee98` (`{0xffffffff,0xffffffff,0,0}`).

5. **Callers:** `Character_SyncEquippedRaceItemFromCbid_Inferred` (`0x00522f70`), `FUN_0052f260`.

6. **Name:** `Character_ClearEquippedRaceItemTfId_Inferred` — role-sealed **INFERRED** from parent race-item dual + TFID/host CF. Ghidra: `FUN_005210b0`.

---

## Gaps

### `0051b5f0`
1. Product/PDB English (`std::deque<T>::_Xlen` or equivalent).  
2. Exact C++ exception type hierarchy (`PTR_FUN_009c7634` / ThrowInfo RTTI) — out of owned scope.  
3. Runtime / bit-exact / differential — open.  
4. Sibling same-string throw bodies at other VAs — not merged here.

### `005210b0`
1. Product/PDB symbol.  
2. Full type of `*(host+0xe4e8)` resolve context — out of owned scope.  
3. Runtime / bit-exact / differential — open.  
4. Full identity of second caller `FUN_0052f260`.

---

## Files

### `aa_0051b5f0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` |
| Function record | `docs/reconstruction/functions/aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0051b5f0_FUN_0051b5f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdDeque_ThrowTooLong_0051b5f0.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0051b5f0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0051b5f0_FUN_0051b5f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b5f0_FUN_0051b5f0.annotated.md` |
| Scratch | `tmp/a_0051b5f0.md` |

### `aa_005210b0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005210b0_FUN_005210b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_ClearEquippedRaceItemTfId_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005210b0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_005210b0_FUN_005210b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005210b0_FUN_005210b0.annotated.md` |
| Scratch | `tmp/a_005210b0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051b5f0-005210b0-w21e-report.md` |

---

## AutoCore impact

### `0051b5f0`
- Port deque map/size overflow arms as hard-fail / throw with message `"deque<T> too long"`.
- Used by skill deferred-cast id deque grow (`FUN_0051c3b0` family) among others.
- Do not silently grow past max map size.

### `005210b0`
- Port as: if race-item TFID live and host present → resolve → deferred enqueue prior object → write null TFID `{ -1,-1,0,0 }`.
- Preserve **deferred** teardown (not free-now) to match client lifecycle.
- Leave CBID `+0x514` to parent sync/setter.
- Pair with `Character_SyncEquippedRaceItemFromCbid` mismatch path.
