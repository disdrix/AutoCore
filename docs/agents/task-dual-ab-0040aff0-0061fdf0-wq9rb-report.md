# Dual A/B report — WQ9R-B OWN-ONLY (`aa_0040aff0`, `aa_0061fdf0`)

**Date:** 2026-08-04  
**Agent:** WQ9R-B OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0040aff0`, `0x0061fdf0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 residual dual seal (skills-abilities, priority 93).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040aff0` Object_CopyTfid16At228_Inferred | **accept** — 16 B TFID out-copy @ +0x228 / `ret 4` / leaf sealed |
| `aa_0061fdf0` CVOGHBSkill_Virus_OnHeartBeat | **accept-with-gaps** — RTTI Virus + OnHeartBeat + ally multi-spread CF sealed; nested helper English residual |

Path A (fidelity): both **accept** / **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; mode-vs-maxTargets confusion closed; product skill English open on Virus.

---

## Sealed facts — `0x0040aff0`

1. **Body:** `0x0040aff0`–`0x0040b016` (**38 B** exclusive; `CC` pad after `ret 4`).

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = object with TFID layout at **`+0x228`**  
   - stack `TFID_16 *out`  
   - **`ret 4`**  
   - **EAX = out** (entry load preserved)

3. **Algorithm:** four dword copies  
   `out[0..3] ← *(this+0x228), +0x22c, +0x230, +0x234`  
   **No branches, no callees, no stores to `this`.**

4. **Role:** Leaf **TFID_16 extract** for identity compare / resolve chains.  
   Callers include `Skill_FilterTargetForResolveList_Inferred` (×3), `CVOGHBAIBase_FindTargetToAttack`, combat/net/mission helpers (**23** UNCONDITIONAL_CALL sites).

5. **Name:** `Object_CopyTfid16At228_Inferred` — role High; product English **Inferred**.  
   Supersedes scaffold `Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_0040aff0`.

6. **Peers:** `TFID_EqualsObjectId` / `TFID_NotEquals`; sibling shape skill-HB copy `FUN_0061b960` (offset `+0x668`).

7. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `0040aff0`

1. Product/PDB symbol.  
2. Exact RTTI of `this` without per-caller cast.  
3. Runtime / bit-exact open.

---

## Sealed facts — `0x0061fdf0`

1. **Body:** `0x0061fdf0`–`0x00620186`; **`ret 4`** (out-status).

2. **Identity (Confirmed):**  
   - RTTI **`.?AVCVOGHBSkill_Virus@@`** (type_info `0x00af2b08`, COL `0x00aae0b8`)  
   - Vtbl **`PTR_FUN_009d14bc`** installed by ctor **`FUN_0061f940`**  
   - This unit = **vtbl[+0x0c]**; base **`CVOGHBBase_TryFire`** at **+0x08** dispatches OnHeartBeat here  
   - **DATA-only** xref @ `0x009d14c8` (no direct CALL)

3. **Name:** `CVOGHBSkill_Virus_OnHeartBeat` — class **Confirmed**, method role **High**.

4. **High-level CF:**  
   1. Shared pulse `FUN_0061b6f0` → status  
   2. Resolve primary target `FUN_00578270`; require `vtbl+0x198()==0`  
   3. Else fail: `this.vtbl+0x18(1,1)`; `*out=0`  
   4. Gates: `*(char*)(world+0x7e)!=0` and `this+0x10 != 0` (`world = this+0x688`)  
   5. RNG: `(u16 % 100) > 0x19` (~**75%**)  
   6. Owner RTTI: **CVOGCreature** with `+0x250!=0` **OR** **CVOGPhysicsBase**  
   7. Origin via `Object_GetWorldPositionPtr` (`FUN_00404c90`)  
   8. **`Skill_GatherTargetsInArea`**: **mode=1** (ally), **filterA=-1**,  
      maxTargets = `*(u8*)(this+0x102)` else **4**,  
      radius = `this+0x5c` else **`DAT_00a0f524` = 50.0f**  
   9. If list non-null TFID and budget `this+0x6d0 > 0`:  
      random pad (`CVOGReaction_RandomUnitScalar` + `FUN_0051b720`);  
      decrement `+0x6d0` / `+0x6d4`;  
      for each TFID: `Object_ResolveFromTFID` → `new(0x6e0)` → Virus ctor →  
      if owner set: **`CVOGHBList_Enqueue(world+0xe4ec)`** + **`CVOGHBBase_Start`**; else scalar dtor  
   10. Success: `*out = pulseStatus`

5. **Null TFID sentinel** `DAT_009e2df0`: `FFFFFFFF FFFFFFFF 00000000 00000000`.

6. **Gather call** sealed vs residual `a_0058d330` caller inventory (`FUN_0061fdf0` @ `0x0061ff9d`, mode **1**, filterA **-1**). Note: decompiler arg order can mislead — **4 is maxTargets default**, not gather mode.

7. **Decompile ≡ raw CF** (live re-verify append 2026-08-04).

### Gaps — `0061fdf0`

1. Product design English for “Virus” beyond RTTI.  
2. Field English for `+0x7e` / `+0x102` / budget dwords.  
3. Dual of ctor `FUN_0061f940` / pulse `FUN_0061b6f0` (not OWN).  
4. `FUN_0051b720` owned by WQ9R-A — pad consumer residual.  
5. Decompiler may sticky-show `outList[0]` on resolve; loop advances `pA` (Probable).  
6. Runtime / stacking / bit-exact open.

---

## Files

### `aa_0040aff0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0040aff0_Object_CopyTfid16At228_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0040aff0_FUN_0040aff0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CopyTfid16At228_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0040aff0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040aff0_FUN_0040aff0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040aff0_FUN_0040aff0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_0040aff0.md` |

### `aa_0061fdf0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| Function record | `docs/reconstruction/functions/aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0061fdf0_FUN_0061fdf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Virus_OnHeartBeat.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0061fdf0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0061fdf0_FUN_0061fdf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0061fdf0_FUN_0061fdf0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_0061fdf0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040aff0-0061fdf0-wq9rb-report.md` |

---

## AutoCore impact

### `0040aff0`

- Port identity extract as **`memcpy`-style 16 B** from object **`+0x228`**, not a pointer-return getter.  
- Keep callers feeding **`TFID_EqualsObjectId` / `TFID_NotEquals` / resolve helpers**.  
- Skill filter related-TFID paths depend on this leaf.

### `0061fdf0`

- Implement **Virus** skill HB as **periodic ally multi-spread**: gather mode **1**, default range **50**, default max targets **4**, ~**75%** RNG, remaining-budget counters, child HBs on **`world+0xe4ec`**.  
- Invalid primary target → **hard stop** (`vtbl+0x18(1,1)`), not silent no-op.  
- Do not confuse with cast entry managers (RequestCast / LocalCastValidate) — this is **post-cast HB tick residual**.  
- Parent merge should register RTTI-confirmed name + matrix row (out of agent scope).

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md`  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
