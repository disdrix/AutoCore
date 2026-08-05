# Review A (reconstruction fidelity): `aa_00629d90` PhysSim_LtBroadPhase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00629d90` |
| **VA** | `0x00629d90` |
| **Body** | `0x00629d90`–`0x0062a160` exclusive (**2000** B / `0x7D0`) |
| **Canonical name** | `PhysSim_LtBroadPhase_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00629d90` |
| **Review date** | `2026-07-29` (W28-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00629d90_PhysSim_LtBroadPhase_Inferred.md` |
| **System** | physics sub-island broadphase + narrowphase |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Run the per-sub-island collision pipeline timed as `"LtBroadPhase"`: AABB expand → 3-axis sweep pairs → examine/merge static pairs → commit pair list → narrowphase. Explicitly **not** VehicleAction apply / integrate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00629d90_FUN_00629d90.md` (+ W28-S append) |
| Annotated | `docs/reconstruction/raw/aa_00629d90_FUN_00629d90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_LtBroadPhase_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_00629d90.cpp` |
| Function records | `functions/aa_00629d90_{FUN_00629d90,PhysSim_LtBroadPhase_Inferred}.md` |
| Live decompile | ≡ raw CF 2026-07-29 |
| Verified parent | `physics/verified/fn_00561910_islandStep.md` §4 |
| Peer commit | `aa_006297e0` Phys_CommitPairListStorage_Inferred (W27-M) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `83 ec 44 55 8b e9` — frame `0x44`, thiscall `mov ebp,ecx` |
| Epilogue | `5d 83 c4 44 c2 08 00` — **`ret 8`** @ `0x0062a15d` |
| Next fn | `0x0062a160` (`83 ec 3c`) — no pad |
| `DAT_00a0f298` | `00 00 00 3f` = **0.5f** |
| `"LtBroadPhase"` | `0x009e335c` (after `"StCalcAabbs\0"` @ `0x009e3350`) |
| End profile | `DAT_009d282c` = `"lt"` |
| Sole CODE xref | `0x00561a21` in `FUN_00561910` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw surface CF | **pass** |
| Body size / epilogue ret 8 | **pass** |
| Profile stages present | **pass** |
| Calls `FUN_006297e0` then narrowphase | **pass** |
| No applyAction / integrate callees | **pass** |
| Clean avoids bare `undefined4` | **pass** |
| Call-site this = subIsland documented | **pass** (residual on stack formal names) |

---

## 5. Surviving contract for AutoCore

```csharp
// Sub-island collide half (LtBroadPhase)
void PhysSim_LtBroadPhase(SubIsland sub, object ctx, StepBlock step)
{
    // expand AABBs with margin = agent.field8 * 0.5f
    // 3-axis sweep → pairs; merge static pairs if any
    Phys_CommitPairListStorage(sub, pairs...);
    sub.Flag30 = true;
    if (!sub.ParentWorld.ContinuousFlag_23e)
        SimpleNarrowPhase(...);
    else
        ContinuousNarrowPhase(...);
}
// Do NOT call VehicleAction.applyAction here.
```

---

## 6. Gaps (non-blocking)

1. Exact product demangle for sub-island / stepBlock types.  
2. Full semantics of `FUN_0062d960` / narrowphase (not OWN).  
3. Decompiler stack-arg labeling residual vs call-site push order.  
4. Runtime / bit-exact open.

**Verdict:** **accept**
