# Dual A/B report — W29-P OWN `aa_00626210` + `aa_006261e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-P  
**Scope:** VAs `0x00626210`, `0x006261e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_by_address` / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00626210` CVOGHBActivatePlayer_OnEnd_Inferred | **accept-with-gaps** — CF + ABI + vtbl `+0x14` + host `+0x6c8`/vcall sealed; product + host-vfunc English open |
| `aa_006261e0` CVOGHBActivatePlayer_EndOrDestroy_Inferred | **accept-with-gaps** — CF + ABI + vtbl `+0x18` + pre-OnEnd policy + base chain sealed; product English open |

---

## VA `0x00626210` — sealed facts

1. **Body:** `0x00626210`–`0x0062623a` (**43 B** / `0x2B`); pad `CC` after.
2. **ABI:** **`__thiscall`** ECX = activate-player HB; **no stack args**; exit **tail-jmp** empty `FUN_005081f0` (`C3`). Ghidra surface `__fastcall` = ECX-only noise.
3. **Entry:** `56 8B F1 8B 46 24…` (this→ESI; host from `+0x24`).
4. **Exit:** `8B CE 5E E9 … → 0x005081f0`.
5. **Classification:** worker (virtual OnEnd; **1** callee = empty tail).
6. **Code xrefs:** **0**; **DATA** vtbl `0x009e3168 + 0x14` @ `0x009e317c`.
7. **Callees:** tail-jmp `FUN_005081f0` (empty); nested host `vtbl+0x18` (not OWN).
8. **CF:** if host≠0 and `*(this+0x28)==0` → `*(host+0x6c8)=1` then `host.vtbl+0x18(1,1)`; always empty tail.
9. **Fields (with W28-G ctor):** `+0x24` host; `+0x28` skip-host-notify byte (ctor 0).
10. **Name:** `CVOGHBActivatePlayer_OnEnd_Inferred` (Ghidra `FUN_00626210`).
11. **Decompile ≡ raw ≡ bytes** (live 2026-07-29 ≡ raw 2026-07-23 CF; tail is jmp not call).

### Gaps

- Product/PDB OnEnd spelling.  
- Host `vtbl+0x18` body English (args `(1,1)` sealed).  
- Full `host+0x6c8` reader catalog.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00626210_FUN_00626210.md` |
| Annotated | `docs/reconstruction/raw/aa_00626210_FUN_00626210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_OnEnd_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00626210.cpp` |
| Function | `docs/reconstruction/functions/aa_00626210_FUN_00626210.md` |
| Function named | `docs/reconstruction/functions/aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00626210.md` |

---

## VA `0x006261e0` — sealed facts

1. **Body:** `0x006261e0`–`0x00626202` (**35 B** / `0x23`); pad `CC` through pre-`00626210`.
2. **ABI:** **`__thiscall`** ECX = HB; stack `(flag_onEnd, flag_hard)`; epilogue **`ret 8`** (`C2 08 00`); void.
3. **Entry:** `53 8B 5C 24 08 84 DB 56 8B F1…`.
4. **Exit:** `5E 5B C2 08 00`.
5. **Classification:** worker (virtual EndOrDestroy override; **1** direct callee + optional OnEnd vcall).
6. **Code xrefs:** **0**; **DATA** vtbl `0x009e3168 + 0x18` @ `0x009e3180`.
7. **Callees:** `CVOGHBBase_EndOrDestroy` (`FUN_005083f0`); when flag0==0 also own OnEnd via `vtbl+0x14` (`FUN_00626210`).
8. **CF:** if `flag_onEnd==0` → OnEnd; **always** base EndOrDestroy(flag0, flag1). Prevents missed host notify on soft paths where base skips OnEnd.
9. **Name:** `CVOGHBActivatePlayer_EndOrDestroy_Inferred` (Ghidra `FUN_006261e0`).
10. **Decompile ≡ raw ≡ bytes** (live 2026-07-29 ≡ raw 2026-07-23 CF).

### Gaps

- Product/PDB method spelling.  
- Exhaustive `(flag0,flag1)` call-site catalog.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_EndOrDestroy_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006261e0.cpp` |
| Function | `docs/reconstruction/functions/aa_006261e0_FUN_006261e0.md` |
| Function named | `docs/reconstruction/functions/aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006261e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00626210` | Port as activate-HB **OnEnd**: gate host/`+0x28`, stamp **`host+0x6c8=1`**, then host virtual `+0x18(1,1)`. Empty tail is a no-op. Do **not** set `this+0x28` here; host-driven teardown may set it first to suppress re-notify. |
| `006261e0` | Port as activate-HB **EndOrDestroy** override: **if flag0==0 pre-call OnEnd**, always base EndOrDestroy. Preserve **ret 8** and two flags. Do not reimplement base hard/soft SEH teardown in this leaf. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x006264e0` | `CVOGHBActivatePlayer_ctor_Inferred` (W28-G) — installs vtbl; sets `+0x24`/`+0x28` |
| `0x00626890` | `Object_ActivatePlayerEnqueueHB_Inferred` (W27-F) — sole factory / Enqueue+Start |
| `0x005083f0` | `CVOGHBBase_EndOrDestroy` — always chained from `006261e0` |
| `0x005081d0` | `CVOGHBBase_Stop` — dispatches OnEnd via `vtbl+0x10` path on base types |
| `0x005081f0` | empty `RET` — OnEnd nop tail |
| `0x009e3168` | activate-player HB vtbl (`+0x14`/`+0x18` = OWN pair) |
| `0x00626160` | host-side teardown sibling (sets `HB+0x28=1`, calls HB `+0x18(1,1)`) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; structural `_Inferred` only.  
- Avoid bare `undefined4` in clean (use `uint32_t` / `uint8_t` / `void*`).

---

## This report

`docs/agents/task-dual-ab-00626210-006261e0-w29p-report.md`
