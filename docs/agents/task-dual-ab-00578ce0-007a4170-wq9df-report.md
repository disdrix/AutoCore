# Dual A/B report — WQ9D-F OWN-ONLY (`aa_00578ce0`, `aa_007a4170`)

**Date:** 2026-08-04  
**Agent:** WQ9D-F OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00578ce0`, `0x007a4170`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities nested skill/cast callees).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00578ce0` Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred | **accept-with-gaps** — OnEnd vtbl+0x10 + FireTail inverse polarity + CF sealed; product English open |
| `aa_007a4170` Rng_SampleUnitFloat_Inferred | **accept-with-gaps** — sequential/indexed unit float + scale + host layout sealed; product English open |

Path A (fidelity): both **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; OnHeartBeat-vs-OnEnd and 1/65536-vs-exact-scale confusions closed; product names remain Inferred.

---

## Sealed facts — `0x00578ce0`

1. **Body:** `0x00578ce0`–`0x00578de0` exclusive (**0x100 B**). Epilogue **tail-jmp** `CVOGHBBase_EmptyVFunc` `0x005081f0` (`E9 …`, not call).

2. **ABI:** MSVC **`__thiscall`**. ECX = skill HB; **no** stack args; plain register restore + jmp.

3. **Role (Confirmed):** skill HB **OnEnd** at **`vtbl+0x10`** (DATA e.g. `0x009d0e28`; matches `CVOGHBBase_Stop` → `jmp [vtbl+0x10]`). Shared body + thin subclass wrappers.

4. **Algorithm:**
   1. `(*PTR_FUN_00af31e0)(this, 0)` — static empty; runtime rebind to UI cleanup `FUN_00802b70`
   2. Resolve target: ECX = `*(*(this+0x688)+0xe4e8)`; TFID pack `+0x658/+0x65c/+0x660`
   3. `FUN_00578ac0` — destroy pointer vector `+0x6b0…+0x6b8`
   4. If owner `+0x18`: `owner->vtbl+0x238(1, skillId@+0x620, rank=i16(+0x61a)+i16(+0x198), 0, target, 0,0,0)`
   5. Flag `+0x639 & 0x10` → **`owner+0x26--`**
   6. If target: `vtbl+0x214`; if `+0x639 & 0x02` → **`Skill_ClearCastBindingAndMaybeRestartCd`** (skillId `+0x620`, TFID `+0x678…+0x684`)
   7. If `+0x140`: `vtbl+0x210(0)` → **`FUN_0051f880(0)`**
   8. Tail empty base OnEnd

5. **FireTail inverse** (`0x00578b30`): flag `0x10` ++ vs --; flag `0x02` insert vs clear; `FUN_0051f880` 1 vs 0; hooks `PTR_FUN_00af31e4` vs `00af31e0`.

6. **Name:** `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` — role High; product English **Inferred**.

7. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw 2026-07-23 CF; epilogue decomp call→actual jmp).

### Gaps — `00578ce0`

1. Product/PDB symbol.  
2. Owner `vtbl+0x238` product verb.  
3. Nested cast-owner type from `vtbl+0x214`.  
4. Runtime / bit-exact open.

---

## Sealed facts — `0x007a4170`

1. **Body:** `0x007a4170`–`0x007a41d4` exclusive (**0x64 B**); pad `CC`. Dual **`ret 4`**.

2. **ABI:** **`__thiscall`**. ECX = `RngHost*`; stack `uint index`; float return **ST0**.

3. **Host layout (shared):** `+0x08` table base (0x100000 ushorts); `+0x0C` cursor. Singleton via `CVOGReaction_RandomUnitScalar` → `&DAT_00d20c1c`.

4. **Algorithm:**
   - **Sequential** (`(int)index < 0`): if `cursor > 0xFFFFF` → 0; load `table[cursor]`; `cursor++`; return `u16 * DAT_00aaa638`
   - **Indexed** (`index >= 0`): `index &= 0x800FFFFF`; if still signed-neg → `(index-1|0xFFF00000)+1`; load `table[index]`; **no** cursor write; same scale

5. **Scale:** `DAT_00aaa638` bytes `80 00 80 37` = float **`0x37800080` ≈ 1/65535** (not exact 1/65536).

6. **Callers:** `FUN_00508a00` @ `0x00508a31` (getter → thiscall sample); second site `0x0057ed44`. **Leaf** (no callees).

7. **Name:** `Rng_SampleUnitFloat_Inferred` — role High; supersedes scaffold `Named_CalleeOf_CVOGReaction_Dispatch_007a4170`.

8. **Peers:** `Rng_CopyUnitTableWindow_Inferred` (`0x0051b720`), `Rng_CloneSeededTable_Inferred` (`0x0058ab60`).

9. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw).

### Gaps — `007a4170`

1. Product/PDB symbol.  
2. Exhaustive call-site index modes (sequential vs explicit).  
3. Runtime / bit-exact open.

---

## Files

### `aa_00578ce0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00578ce0_FUN_00578ce0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00578ce0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00578ce0.md` |

### `aa_007a4170`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007a4170_Rng_SampleUnitFloat_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007a4170_Rng_SampleUnitFloat_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_007a4170_Rng_SampleUnitFloat_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_007a4170_FUN_007a4170.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_SampleUnitFloat_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_007a4170.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.md` |
| Annotated | `docs/reconstruction/raw/aa_007a4170_FUN_007a4170.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_007a4170.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00578ce0-007a4170-wq9df-report.md` |

---

## AutoCore impact

### `00578ce0`

- Implement skill HB **OnEnd** as shared teardown: resolve target, clear HB vector `+0x6b0`, owner notify mode **1**, reverse FireTail counters/bindings (`0x10` dec, `0x02` clear cast, `f880(0)`).
- Wire from `CVOGHBBase_Stop` → virtual OnEnd; keep distinct from `EndOrDestroy` (`vtbl+0x18`).
- Client hook pointer `PTR_FUN_00af31e0` is runtime-rebound — ports may no-op static empty safely if UI cleanup is separate.

### `007a4170`

- Port unit float as **`u16 * 0x37800080`** from global table; sequential uses cursor wrap at `> 0xFFFFF` and `cursor++`.
- Do not merge into CopyWindow/CloneSeededTable; keep float ST0 / `ret 4` contract.
- Prefer index `(uint32_t)-1` for “next random unit” unless caller supplies explicit index.

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md`  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
