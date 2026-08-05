# Dual A/B report — W24-C OWN-ONLY (`aa_004b8ed0`, `aa_004b1100`)

**Date:** 2026-07-29  
**Agent:** W24-C OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004b8ed0`, `0x004b1100`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b8ed0` NDSpecialFX_HostTick_Inferred | **accept-with-gaps** — 880 B host tick: rate/type gate, liveness → DeactivateClear or child Tick/Destroy; ret 4; AL 0/1 |
| `aa_004b1100` ObjectMotion_IntegrateStep_Inferred | **accept-with-gaps** — 2021 B motion integrate: free/attach/path branches; ret 0xC; constants sealed; nested force helpers residual |

---

## Sealed facts — `0x004b8ed0`

1. **ABI:** `__thiscall` on FX host (**ECX**); one stack formal (`ctx*`); epilogue **`ret 4`** (`C2 04 00`). Return **AL** `0` (still active) / `1` (deactivated).

2. **Body:** `0x004b8ed0`–`0x004b9240` (**880 bytes / `0x370`**). SEH frame `LAB_009a155d`.

3. **Profiler:** `*(DAT_00d17958 + 0x154)++`.

4. **Rate gate:** `cmp eax, 0x1388` + `jbe` ≡ `(now - stamp) < 0x1389` (5001 ms) against `this+0xd0`. Confirmed via `read_memory`.

5. **Type switch:** on `this+0x28`. Types `{2,3,5,6,0xC,0xD,0xE,0x13,0x14,0x15,0x17}` → deactivate; type `4` may re-enter via `FUN_004b6a80`; default → active.

6. **Active path:** stamp `+0xd0`; if `FUN_004b7330()` non-zero → `NDSpecialFX_DeactivateClear_Inferred` + return 1; else transforms + cull + walk lists.

7. **Owned list `+0x204`:** live children → sealed `CVOGObject_Tick`; destroy-pending (`+0x90e bit0`) → profile `"Destroy"` free path.

8. **Deactivate path:** sealed `FUN_004b7150` + return 1.

9. **Cull float:** `DAT_009cb2b0` = `0x358637bd` ≈ **1e-6** (Confirmed).

10. **Name:** `NDSpecialFX_HostTick_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_004b8ed0`.

---

## Sealed facts — `0x004b1100`

1. **ABI:** `__thiscall` on motion slot (**ECX**); three stack formals; epilogue **`ret 0xC`** (`C2 0C 00`); void.

2. **Body:** `0x004b1100`–`0x004b18e5` (**2021 bytes / `0x7E5`**).

3. **Entry:** `sub esp,0x3C; push ebx/ebp/esi; mov esi,ecx`; loads pos from `esi+0x178`.

4. **Branches:** path-null free integrate (nested basis + attach OR force helpers + optional heightfield Y) vs path-sample; post modes host`+0x984` ∈ {2,4}; optional host lin-vel.

5. **Callee dual:** `FUN_004e8590` = `Math_QuatInverseRotateDelta_Inferred` (W23-O). Rel32 **Confirmed** via decompile.

6. **Constants (Confirmed `read_memory`):** `1.0@00a0f2a0`, `2.0@00a10e74`, `≈0.01@00a0f718`, `0.5@00a0f298`, `6.0@00aaa8dc`, `-1.0@00aaa668`.

7. **Callers:** `FUN_004b4620` @ `0x004b48e8`; `FUN_005bc120` @ `0x005bc2ba`.

8. **Name:** `ObjectMotion_IntegrateStep_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_004b1100`.

---

## Gaps

### `004b8ed0`
1. Product English plate spelling / PDB symbol.  
2. Full event-type enum for `+0x28`.  
3. Dual of `FUN_004b7330` / `FUN_004b6a80` / residual free helpers.  
4. Runtime / bit-exact / differential — open.

### `004b1100`
1. Product class name of motion slot.  
2. Full dual of force helpers `005c*`.  
3. Product meaning of host`+0x984` modes.  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x004b8ed0` | `reviews/A_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` | `reviews/B_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` | **accept-with-gaps** |
| `0x004b1100` | `reviews/A_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` | `reviews/B_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_004b8ed0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004b8ed0_FUN_004b8ed0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDSpecialFX_HostTick_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004b8ed0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b8ed0_FUN_004b8ed0.annotated.md` |

### `aa_004b1100`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004b1100_FUN_004b1100.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ObjectMotion_IntegrateStep_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004b1100.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004b1100_FUN_004b1100.md` |
| Annotated | `docs/reconstruction/raw/aa_004b1100_FUN_004b1100.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004b8ed0-004b1100-w24c-report.md` |

---

## AutoCore impact

### `004b8ed0`
- Client FX host tick must implement **5s stamp** + **event-type** policy; do not always DeactivateClear.
- Return **0/1** is load-bearing for callers.
- Child free only when destroy-pending; marking is DeactivateClear's job (W23-H).
- Port must use **`ret 4`** / one stack ctx pointer.

### `004b1100`
- Motion integrate is a **slot** method, not a pure math leaf — preserve free/attach/path branching.
- Stack: three formals + **`ret 0xC`**.
- Honor early abort (`slot[0x5c] = -1.0`) on force-D fail.
- Constants 2.0 / 0.5 / 6.0 / 0.01 must match image.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b7150` | `NDSpecialFX_DeactivateClear_Inferred` (W23-H) |
| `0x004b75d0` | `NDSpecialFX_UpdateParamMapTransforms_Inferred` |
| `0x00595230` | `CVOGObject_Tick` (W23-H) |
| `0x004b7330` | liveness gate |
| `0x004e8590` | `Math_QuatInverseRotateDelta_Inferred` (W23-O) |
| `0x004b4620` | caller entity tick |
| `0x005bc120` | caller spawn loop |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
