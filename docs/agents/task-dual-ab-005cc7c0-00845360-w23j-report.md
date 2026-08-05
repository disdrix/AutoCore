# Dual A/B report — W23-J OWN-ONLY (`0x005cc7c0`, `0x00845360`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x005cc7c0`, `0x00845360`. Dual A/B + artifacts.  
**Agent:** W23-J OWN-ONLY  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Verdict |
|------|---------|
| `aa_005cc7c0` EntityHost_ApplyNestedLocalPosition_Inferred | **accept-with-gaps** — **thiscall host + ret 8**, nested **`+0x64`**, dirty **byte `+0x304`**, prep `0053d970(0)` → gated set-pos `004c3a40`; vtable-only DATA ×5; product name / arg2 open |
| `aa_00845360` UI_AppendItemRequirements | **accept-with-gaps** — **EAX item** + UI text + show flag; **Requires** block (Level/race/class/Combat/Tech/Theory/Perception); colors + getters sealed; reject `Named_Combat`; type `0x1a` English / runtime open |

---

## Sealed facts — `aa_005cc7c0` (0x005cc7c0)

1. **ABI:** `__thiscall` — host in **ECX**, stack **arg1** = `float* vec4`, stack **arg2** present but **unread**, **`ret 8`**.

2. **Body:** `0x005cc7c0`–`0x005cc7e7` (**40 B**); epilogue `C2 08 00`.

3. **Nested object:** `object = *(host + 0x64)` — all work targets nested, not host.

4. **Algorithm (order sealed):**
   - `FUN_0053d970(object, 0)` — thiscall + stack formal **0**; callee **`ret 4`** (may tail to `FUN_005d4440` when body path needs update; arg0 → rewrite code **1**).
   - `*(u8*)(object + 0x304) = 1` — dirty byte (same offset DCT uses).
   - `FUN_004c3a40(object, vec)` — `CVOGObject_SetLocalPosition4_Gated_Inferred`.

5. **Dispatch:** DATA vtable slots only — `0x009da9d0`, `0x009daf58`, `0x009db0d8`, `0x009db138`, `0x009db198`. **No** UNCONDITIONAL_CALL xrefs.

6. **Decompiler hazards sealed:** free-call typing of callees; single formal vs **`ret 8`**; dword vs **byte** dirty store.

7. **Name:** `EntityHost_ApplyNestedLocalPosition_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_005cc7c0`.

### Gaps (`005cc7c0`)

1. Product/PDB host class + method English.  
2. Unread arg2 semantic.  
3. Vtable type inventory / slot index English.  
4. Runtime / null-nested / differential — open.

---

## Sealed facts — `aa_00845360` (0x00845360)

1. **ABI:** item/template in **EAX** (`mov esi,eax`); stack UI text* + char show; frame `sub esp,0x8c`; **plain `ret`**.

2. **Body:** `0x00845360`–`0x00845871` (**~1298 B**).

3. **Gates → return 0:** `show==0` OR nested type `+0x38 == 0x1a` OR `DAT_00d1b6d8==0` OR all requirements empty.

4. **Layout (item):** nested via `+0xa8`; race vfunc def`+0x14`; class def`+0x3e0`; level shorts `+0xe8/+0xea`; Combat `+0xec`; Perception `+0xee`; Tech `+0xf0`; Theory `+0xf2`.

5. **Product strings:** `"Requires:"`, `"Level"`, `"Combat"`, `"Tech"` @ `0x00a2e4fc`, `"Theory"`, `"Perception"`; race `FUN_0051f8e0`; class `FUN_0051f940`.

6. **Colors:** header `0xffbbbbbb`; met `0xffffffff`; fail `0xffff2020`; race/class met uses text vfunc **`+0x250`**.

7. **Stat getters:** Combat `004c4070`, Tech `Character_GetTechForPoolCalcs`, Theory `004c4140`, Perception `004c41c0`; level helper `FUN_0040f540` (cap **80**).

8. **Return:** line count (header counts as 1 when content drawn). Perception-tail `unaff_EBP+1` is decomp hazard for **lines+1**.

9. **Name:** `UI_AppendItemRequirements` — role **High**. **Reject** `Named_Combat_00845360` as primary. Ghidra: `FUN_00845360`.

10. **Callers:** `FUN_00843a60` ×1, `FUN_0084b890` ×1, `FUN_0088d980` ×2.

### Gaps (`00845360`)

1. Product C++ method / UI text class English.  
2. Category **`0x1a`** product meaning.  
3. Runtime tooltip golden / differential — open.  
4. Level short pair English (sum sealed; base/bonus open).

---

## Files

### `aa_005cc7c0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005cc7c0_FUN_005cc7c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EntityHost_ApplyNestedLocalPosition_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_005cc7c0.cpp` |
| Raw (authoritative + W23-J re-verify) | `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.annotated.md` |

### `aa_00845360`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00845360_UI_AppendItemRequirements.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00845360_UI_AppendItemRequirements.md` |
| Function record | `docs/reconstruction/functions/aa_00845360_FUN_00845360.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_AppendItemRequirements.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00845360.cpp` |
| Rejected scaffold | `docs/reconstruction/reconstructed-exact/Named_Combat_00845360.cpp` |
| Raw (authoritative + W23-J re-verify) | `docs/reconstruction/raw/aa_00845360_FUN_00845360.md` |
| Annotated | `docs/reconstruction/raw/aa_00845360_FUN_00845360.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005cc7c0-00845360-w23j-report.md` |

---

## Port notes

- **`005cc7c0`:** client host→nested pose apply + dirty coupling. Sector should keep managed pose writers; seal documents retail dirty offset `+0x304` and call order only.
- **`00845360`:** client presentation only. Server req checks should use data fields / sealed getters, not this UI path. Confirms product English for Theory/Combat/Tech/Perception requirement lines used by prior duals.
