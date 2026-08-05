# Dual A/B report — W30-R OWN-ONLY (`0x005be310`, `0x004b0bd0`)

**Date:** 2026-07-29  
**Agent:** W30-R OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005be310`, `0x004b0bd0`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005be310` Emitter_ReleaseToFreelist_Inferred | **accept** — teardown (`FUN_005bbc50`) then freelist-push; `ret 4`; global head `DAT_00b454fc` |
| `aa_004b0bd0` ObjectMotion_SlotEmptyDtor_Inferred | **accept** — 1-byte empty thiscall stub; sole caller SlotRelease; closes W28-I gap |

---

## `aa_005be310` — Emitter_ReleaseToFreelist_Inferred

### Sealed facts

1. **Body:** `0x005be310`–`0x005be32e` exclusive (**30** B / `0x1e`). Final **`c2 04 00`** (`ret 4`); following `cc` pad; next fn `0x005be330`.

2. **ABI:** `__thiscall` ECX=freelist head*; stack `(Emitter *node)`; clean **4** B; void.

3. **Algorithm:**
   ```
   // bytes rebind ECX = node before teardown (decompiler omits this)
   FUN_005bbc50(this=node)     // heavy emitter body teardown (W30-S)
   if node:
     node->next@dword0 = *head
     *head = node
   ```

4. **Global freelist:** all known callers force **`mov ecx, 0x00B454FC`** (`DAT_00b454fc`) before call — not the NDSpecialFX host. Distinct from motion-slot freelist `DAT_00b036c0`.

5. **Callee:** `FUN_005bbc50` @ `0x005bbc50` — heavy teardown (nested resources, walk `+0xA24` motion slots via SlotRelease). Full dual is W30-S OWN — not sealed here.

6. **Callers (3 families, 9 sites):**
   - `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) @ `0x004b913b` — kill path after `Emitter_UpdateTick` returns 0 (list node already unlinked)
   - `NDSpecialFX_ClearChildLists_Inferred` (`FUN_004b85d0`) @ `0x004b85eb` — walk host `+0x1E0`, release each `node[2]`
   - `FUN_004a34f0` ×7 (`0x004a3674`, `0x004a3cfd`, `0x004a3df6`, `0x004a3ed3`, `0x004a3f00`, `0x004a3f2d`, `0x004a3f69`)

7. **Name:** `Emitter_ReleaseToFreelist_Inferred`. Reject scaffold `Named_CalleeOf_Named_missileExplosion_*` as product claim.

### Gaps

1. Product/PDB English.  
2. Nested teardown child `FUN_005bbc50` (W30-S).  
3. Null-node teardown reachability (gate only covers freelist push).  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005be310_Emitter_ReleaseToFreelist_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005be310_FUN_005be310.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Emitter_ReleaseToFreelist_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005be310.cpp` |
| Raw | `docs/reconstruction/raw/aa_005be310_FUN_005be310.md` |
| Annotated | `docs/reconstruction/raw/aa_005be310_FUN_005be310.annotated.md` |

---

## `aa_004b0bd0` — ObjectMotion_SlotEmptyDtor_Inferred

### Sealed facts

1. **Body:** `0x004b0bd0`–`0x004b0bd1` exclusive (**1** B / `0x1`). Single **`c3`** (`ret`); following `cc` pad.

2. **ABI:** thiscall shape at call sites; body **bare `ret`** (ignores ECX; no stack cleanup); void.

3. **Algorithm:** empty `return;` — no callees, no side effects.

4. **Caller (1):** `ObjectMotion_SlotReleaseToFreelist_Inferred` (`FUN_005be2b0`) @ `0x005be2bf` (child@+0x8) and `0x005be2da` (node).

5. **Name:** `ObjectMotion_SlotEmptyDtor_Inferred`. Distinct from mass-shared `EmptyRet` @ `0x0056f570` and `CVOGHBBase_EmptyVFunc` @ `0x005081f0`. Closes W28-I gap “why empty FUN_004b0bd0 remains” at the **behavior** level (empty by design/strip; do not invent teardown).

### Gaps

1. Product/PDB English.  
2. Compiler rationale for dedicated empty leaf vs inlined nop.  
3. Runtime — open (vacuous).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004b0bd0_ObjectMotion_SlotEmptyDtor_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004b0bd0_FUN_004b0bd0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotEmptyDtor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004b0bd0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004b0bd0_FUN_004b0bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b0bd0_FUN_004b0bd0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Emitter_ReleaseToFreelist_Inferred (`0x005be310`)

- Port as **emitter payload release**: teardown body then freelist-push — not `operator_delete` of the emitter.
- Preserve **`ret 4`** and freelist head **`DAT_00b454fc`** (do not reuse motion-slot freelist `DAT_00b036c0`).
- HostTick kill path: list-node unlink/delete first, then this unit for the payload.
- Teardown child is **`FUN_005bbc50`** (W30-S); call with **this = node**.
- Null gate covers freelist push only — do not assume teardown is null-safe without caller guarantees.

### ObjectMotion_SlotEmptyDtor_Inferred (`0x004b0bd0`)

- **Empty** — do not invent resource teardown inside it.
- SlotRelease must still call the hook (or elide only if proven equivalent) before freelist-push of child and node.
- Keep distinct from shared `EmptyRet` unless all xrefs are re-audited.

### Cross-links

| Related | VA / note |
|---|---|
| `Emitter_UpdateTick_Inferred` | `0x005bc3c0` — kill → HostTick → this release |
| `ObjectMotion_SlotReleaseToFreelist_Inferred` | `0x005be2b0` — sole caller of empty dtor |
| `FUN_005bbc50` | `0x005bbc50` — W30-S teardown dual |
| `NDSpecialFX_ClearChildLists_Inferred` | `0x004b85d0` — walks `+0x1E0` into this release |
| `NDSpecialFX_HostTick_Inferred` | `0x004b8ed0` — kill path |

---

## This report

`docs/agents/task-dual-ab-005be310-004b0bd0-w30r-report.md`
