# Review A (reconstruction fidelity): `aa_00627ec0` Skill_ComputeEffectScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627ec0` |
| **VA** | `0x00627ec0`–`0x00628516` |
| **Canonical name (Ghidra)** | `FUN_00627ec0` |
| **Proposed name** | `Skill_ComputeEffectScore_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Score consumer** of dualed `Skill_ComputeEffectPresenceFlags_Inferred`. Presence bits gate which skill effect banks enter a weighted float sum; duration/charge scales apply; result is `(int)ceil(score)` for dual-skill priority compares (HB conflict).

Not a store to `+0x624`, not Evaluate, not presence scan itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00627ec0` |
| Bytes | `read_memory` entry `0x00627ec0` + tail `0x00628500` (`add esp,10; ret`) |
| Floats | `read_memory` on all DAT_/g_fl* used in body |
| Callers | xrefs: 11 UNCONDITIONAL_CALL; dual-score pattern sealed @ `0x00625b20` (`lea ecx,[esi+0x24]; call; mov ecx,ebx; call; cmp`) |
| Presence leaf | dual sealed `aa_00627be0` / WQ9D-E |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00627ec0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature

```c
int __fastcall Skill_ComputeEffectScore_Inferred(void *pSkill);
// ECX = skill; EAX = (int)ceil(score); plain ret
```

| Item | Evidence |
|---|---|
| Convention | no stack formals; call sites load ECX |
| ECX = skill | presence leaf + field banks match skill runtime |
| Int return | callers `cmp` EAX pairs; decompiler `return (int)ROUND(ceil)` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Call presence leaf first | **Yes** |
| Gate banks on bits `1/0x100/0x40/8/2/0x800/0x10/0x1000` | **Yes** |
| Pair weights 0.35/0.5, slot 1.2/+0.2 | **Yes** (sealed floats) |
| Duration / charge scales | **Yes** |
| Floor ≥ 1.0; ceil to int | **Yes** |
| Does not write `+0x624` | **Yes** (pure compute) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Score CF + bit gates | **High** | decompile ≡ raw |
| Float constant values | **High** | `read_memory` |
| Dual-score consumer role | **High** | 11 call sites pattern |
| Name role “effect score” | **High** | behavior; product noun open |
| Bank combat English | **Open** | no strings |
| Full host identity of every caller | **Open** | residual |

---

## 6. Gaps / open

1. Product/PDB symbol / score metric English.  
2. Exhaustive English for each effect bank.  
3. Named dual of all caller hosts (beyond compare pattern).  
4. Runtime / bit-exact / float ulp.

**Verdict:** **accept-with-gaps** — CF/ABI/constants/call-role High; product English open.
