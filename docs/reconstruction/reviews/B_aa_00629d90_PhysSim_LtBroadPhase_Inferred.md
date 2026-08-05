# Review B (skeptical / adversarial): `aa_00629d90` PhysSim_LtBroadPhase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00629d90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-S) |
| **Counterpart** | `reviews/A_aa_00629d90_PhysSim_LtBroadPhase_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is island integrate / applyActions | **Falsified** — profile `"LtBroadPhase"`; callees are AABB/sweep/commit/narrowphase; applyAction lives in `FUN_00628f70` |
| 2 | Zero or one stack arg (cdecl/thiscall single) | **Falsified** — epilogue **`ret 8`** ⇒ two stack formals |
| 3 | Decompiler `(param_1, param_2)` fully describes call site | **Weakened** — ECX=subIsland sealed by caller bytes; two pushes (ctx + stepBlock); decompiler collapses map |
| 4 | Multi-caller shared utility | **Falsified** — **sole** CODE caller `FUN_00561910` |
| 5 | `DAT_00a0f298` is aero-only constant | **Falsified risk** — shared float pool **0.5f**; used here as AABB margin scale only |
| 6 | Product name without `_Inferred` | **Open** — structural / profile evidence only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Collide-only role | **High** | wrong sim half → missing forces / double integrate |
| ABI ret 8 | **High** | stack smash |
| Stage order + pair commit | **High** | pair leaks / missed contacts |
| Stack formal English | Med | wrong arg order in ports |
| Nested narrowphase | Med | continuous path residual |

---

## 3. Cross-check against raw + bytes

```
sub esp,0x44; mov ebp,ecx          // thiscall subIsland
profile "LtBroadPhase"
FUN_0062d960(world+0x238) x2
alloc AABBs (n*0x20) + ptrs
margin = *(world.agent+8) * 0.5f
"StCalcAabbs" loop shape vtbl+0x18
"St3AxisSweep" step vtbl+0x14
"StExamine" + optional +0x74/+0x78 merge
FUN_006297e0(...); sub+0x30 = 1
narrow: 00629c40 if !(world+0x23e) else 00629990
ret 8
```

Clean must **not** claim integrate/applyAction, **not** omit ret 8, **not** invent multi-kill/aero meaning for `0.5f`.

---

## 4. Surviving contract for AutoCore

Port as **sub-island broadphase+narrowphase** under `LtSimulate` collide half only. Keep dual narrowphase branch on `parentWorld+0x23e`. Keep pair commit via existing `Phys_CommitPairListStorage_Inferred`.

---

## 5. Open questions

1. Exact layout of `*(island+0xc4)` vs `island+0x140` under decompiler residual.  
2. Product English for sub-island class.  
3. Runtime / bit-exact open.

**Verdict:** **accept**
