# Dual A/B report — W23-T OWN-ONLY (`aa_00650d30`, `aa_004e1830`)

**Date:** 2026-07-29  
**Agent:** W23-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00650d30`, `0x004e1830`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00650d30` CVOGHBMissionPatrol_ctor | **accept-with-gaps** — **164 B** in-place patrol HB ctor; type `0xC`, pulse 1000, vftable sealed; product English name open |
| `aa_004e1830` LockedList_TryAdvanceIterator_Loot_Inferred | **accept-with-gaps** — **172 B** CS list iterate-next (no SEH); twin of `0x004022a0`; loot callers sealed |

---

## Sealed facts — `0x00650d30`

1. **ABI:** `__thiscall` — **ECX = this** (pre-alloc **0x40**), stack **owner**, **requirement**; epilogue **`ret 8`**. Body **`0x00650d30`–`0x00650dd4`** (**164 bytes**).

2. **Algorithm:** `CVOGHBBase_ctor` → install **`PTR_FUN_009e52e4`** → copy requirement fields (vtbl+0x58, nested +0x10, dword pair, field 7) → type **`0xC`** → `SetPeriodAndCounter(-1000, true)` → optional MI owner adjust → `AttachOwnerObject` → **`+0x08 = 1000`** → return this.

3. **Callees:** `CVOGHBBase_ctor` `0x00508200`, `CVOGHBBase_SetPeriodAndCounter` `0x005081a0`, `CVOGHBBase_AttachOwnerObject` `0x005083b0`.

4. **Caller (sole static):** `CVOGObjectiveRequirement_Patrol_InitActive` `0x0060e3d0` (new 0x40 → ctor → enqueue → Start).

5. **Family:** vftable slots include `CVOGHBMissionPatrol_Fn3` `0x00650e50`, `Fn6` `0x00650de0`.

6. **Name:** `CVOGHBMissionPatrol_ctor` — role-sealed **INFERRED** (family + parent). Ghidra: `FUN_00650d30`.

---

## Sealed facts — `0x004e1830`

1. **ABI:** `__thiscall` — **ECX = list**, stack **cursor\***, **outPayload\***; epilogue **`ret 8`**. Body **`0x004e1830`–`0x004e18dc`** (**172 bytes**).

2. **Algorithm:** require `list+0x28`; `TryEnterCriticalSection(list+4)`; seed from head `+0x1C` when cursor null; else follow `node+8`; write payload `node+4`; Leave on success; returns **0 / 1 / 0x80070005**.

3. **Callees:** Win32 `TryEnterCriticalSection` IAT `[0x009c61a0]`, `LeaveCriticalSection` IAT `[0x009c61b8]`.

4. **Callers:** `KillLoot_RollTableItems_Inferred` `0x0050aa80`, `FUN_0050a7d0`, `FUN_004d5c10`.

5. **Twin:** `List_IterateNext` / `LockedList_TryAdvanceIterator_Inferred` @ **`0x004022a0`** — same CF/offsets; twin has SEH, this copy does not.

6. **Name:** `LockedList_TryAdvanceIterator_Loot_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_004e1830`. Prior scaffold raw body preserved; W23-T re-verify **appended**.

---

## Gaps

### `00650d30`
1. Product/PDB English class name.  
2. Requirement field / `vtbl+0x58` product meaning.  
3. Runtime / bit-exact / differential — open.  
4. Full vftable slot map beyond Fn3/Fn6/Tick.

### `004e1830`
1. Product list/node type name.  
2. Why second copy without SEH vs `004022a0`.  
3. Runtime concurrent-walk golden.  
4. Shared vs distinct element types across three callers.

---

## Files

### `aa_00650d30`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00650d30_CVOGHBMissionPatrol_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00650d30_CVOGHBMissionPatrol_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00650d30_CVOGHBMissionPatrol_ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00650d30_FUN_00650d30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionPatrol_ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00650d30.cpp` |
| Raw (scaffold body + re-verify append) | `docs/reconstruction/raw/aa_00650d30_FUN_00650d30.md` |
| Annotated | `docs/reconstruction/raw/aa_00650d30_FUN_00650d30.annotated.md` |

### `aa_004e1830`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004e1830_FUN_004e1830.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LockedList_TryAdvanceIterator_Loot_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e1830.cpp` |
| Raw (scaffold body + re-verify append) | `docs/reconstruction/raw/aa_004e1830_FUN_004e1830.md` |
| Annotated | `docs/reconstruction/raw/aa_004e1830_FUN_004e1830.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00650d30-004e1830-w23t-report.md` |

---

## AutoCore impact

### `00650d30`
- Port as **in-place patrol HB constructor** (0x40, type 0xC, pulse 1000 ms, sentinel -1000).  
- Parent path: allocate → ctor → continent HB list enqueue → Start.  
- Do **not** put fail/complete mission logic in the ctor — that is Fn3/Fn6/Tick.

### `004e1830`
- Port as **non-blocking locked list iterate-next** (same math as `0x004022a0`). Prefer one shared C++ helper server-side.  
- Distinguish **END (1)** vs **LOCK_FAIL (0x80070005)** even if retail callers fold non-zero.  
- Use mem-safe cursor; Leave CS every step — do not hold CS across yield in a port unless matching retail re-enter pattern.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
