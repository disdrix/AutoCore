# Dual A/B report — WQ9D-E OWN-ONLY (`aa_00627be0`, `aa_0040c700`)

**Date:** 2026-08-04  
**Agent:** WQ9D-E OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00627be0`, `0x0040c700`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (rank reeval callee residual; skills-abilities priority 93).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00627be0` Skill_ComputeEffectPresenceFlags_Inferred | **accept-with-gaps** — leaf presence bit map + `*(+0xc)\|flags` + skill ECX sealed; bank English open |
| `aa_0040c700` List_TraversalUnlock | **accept** — exact inverse of string-sealed `List_TraversalLock`; 21 B leaf sealed |

Path A (fidelity): both **accept** / **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; store-vs-return and lock/unlock confusions closed; product bank English open on presence flags.

---

## Sealed facts — `0x00627be0`

1. **Body:** `0x00627be0`–`0x00627eb3` (**211 B** / `0xD3` exclusive; `CC` pad after `pop edi; ret`).

2. **ABI:** MSVC **`__fastcall` / `__thiscall`**.  
   - `ECX` = skill runtime  
   - no stack formals  
   - **EAX** = `*(uint*)(skill+0xc) | presenceBits`  
   - plain **`ret`**

3. **Algorithm (leaf):** scan ranked effect fields for non-zero presence; OR bit masks; return with base dword `skill+0xc`.  
   | Bit | Non-zero source |
   |----:|---|
   | `0x1` | 6× i16 @ `+0x60` |
   | `0x8` | 6× i16 @ `+0x6c` |
   | `0x80` | 6× f32 @ `+0xa8` |
   | `0x100` | pairs i16 @ `+0x78` / `+0x90` |
   | `0x200` | pairs i16 @ `+0x84` / `+0x9c` |
   | `0x400` | misc f32 group A **or** `+0x12c/+0x130` |
   | `0x40` | 5× i16 @ `+0xd0..+0xd8` |
   | `0x20` | f32 `+0x38` or `+0x13c` |
   | `0x10` | char `+0xda` |
   | `0x2` | f32 `+0x3c` |
   | `0x8000` | f32 `+0x40` |
   | `0x10000` | f32 `+0x10c..+0x118` |
   | `0x20000` | f32 `+0x124/+0x128` **or** (`+0x134!=0` && f32 `+0x138`) |

4. **Role in rank reeval:**  
   - `Skill_ReevaluateForCurrentRank` (`0x00553390`): after `Skill_EvaluateRankedElements`, `mov ecx,esi` → this unit → store EAX to `skill+0x624` (with `|4` when `skill+0x620!=0`).  
   - Twin store helper `FUN_0054fec0` (`0x0054fec0`).  
   - Score consumer `FUN_00627ec0` (`0x00627ec0`) uses returned bits.

5. **Name:** `Skill_ComputeEffectPresenceFlags_Inferred` — role **High**; product bank English **Inferred**.  
   Supersedes scaffold `Named_CalleeOf_Skill_ReevaluateForCurrentRank_00627be0`.

6. **Callers (3):** `Skill_ReevaluateForCurrentRank`, `FUN_0054fec0`, `FUN_00627ec0`. **Callees: none.**

7. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw 2026-07-23 + re-verify append).

### Gaps — `00627be0`

1. Product/PDB symbol.  
2. Combat English for each effect bank.  
3. Semantics of base dword `skill+0xc`.  
4. Full `skill+0x624` targeting enum glossary (caller residual).  
5. Dual of `FUN_0054fec0` / `FUN_00627ec0` (not OWN).  
6. Runtime / bit-exact open.

---

## Sealed facts — `0x0040c700`

1. **Body:** `0x0040c700`–`0x0040c715` (**21 B** exclusive; `CC` pad after `ret`).

2. **ABI:** MSVC **`__fastcall` / `__thiscall`**.  
   - `ECX` = list manager  
   - void; plain **`ret`**

3. **Algorithm:**  
   ```
   if (*(char*)(list+0x28) != 0) {
     *(list+0x28) = 0;
     LeaveCriticalSection(list+4);
   }
   ```

4. **Role:** **`List_TraversalUnlock`** — exact inverse of string-sealed `List_TraversalLock` (`0x004294f0`: EnterCS(`+4`) then flag=1; re-lock logs `"List Error!  TraversalLock Call Stack"`).  
   Layout match: CS @ `+4`, flag @ `+0x28`. Safe no-op when unlocked.

5. **Name:** `List_TraversalUnlock` — role **High** (pair of sealed TraversalLock).  
   Supersedes scaffold `Named_CalleeOf_Client_RecvSkillStatusEffect_0040c700`.

6. **Callers (17):** includes `Client_RecvSkillStatusEffect` (×2), `FUN_0057ade0`, `FUN_008e5e00` (×2), `FUN_008fdb60`, `FUN_008ff5a0` (×2), `FUN_00920a50`, `FUN_0092c080`, plus sites in `0x0057cc03..0x0057d6ea`.  
   **Callee:** `LeaveCriticalSection` (Win32 IAT).

7. **Not** InventoryGrid-local unlock (different CS/flag offsets). **Not** skill-only.

8. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw + re-verify append).

### Gaps — `0040c700`

1. Product RTTI / list class English.  
2. Exhaustive audit of inline LeaveCS sites vs this helper.  
3. Runtime / bit-exact open.

---

## Files

### `aa_00627be0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00627be0_FUN_00627be0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ComputeEffectPresenceFlags_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00627be0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00627be0_FUN_00627be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00627be0_FUN_00627be0.annotated.md` |

### `aa_0040c700`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0040c700_List_TraversalUnlock.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040c700_List_TraversalUnlock.md` |
| Function record | `docs/reconstruction/functions/aa_0040c700_List_TraversalUnlock.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0040c700_FUN_0040c700.md` |
| Clean | `docs/reconstruction/reconstructed-exact/List_TraversalUnlock.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0040c700.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040c700_FUN_0040c700.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c700_FUN_0040c700.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00627be0-0040c700-wq9de-report.md` |

---

## AutoCore impact

### `00627be0`

- After rank materialize (`Skill_EvaluateRankedElements` / `Skill_ReevaluateForCurrentRank`), recompute presence flags via this **pure leaf** before assigning **`skill+0x624`**.  
- Do **not** implement `+0x624` store inside this function — callers apply `|4` when `skill+0x620 != 0`.  
- Port bit map as non-zero tests on the sealed offsets; OR with `skill+0xc`.  
- Consumer `FUN_00627ec0` weights score by returned bits — keep mask stable.

### `0040c700`

- Pair every `List_TraversalLock` success with **`List_TraversalUnlock`** (or equivalent clear flag + LeaveCS on `+4`).  
- Unlock must be **idempotent** (flag already 0 → no LeaveCS).  
- Skill status-effect receive is one of many consumers — implement as shared list util, not skill-only.  
- Do not confuse with InventoryGrid CS offsets (`+0x30` / `+0x54`).

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (and list util note for TraversalUnlock)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
