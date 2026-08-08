# Review A (reconstruction fidelity): `aa_00627be0` Skill_ComputeEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627be0` |
| **VA** | `0x00627be0`–`0x00627eb3` |
| **Canonical name (Ghidra)** | `FUN_00627be0` |
| **Proposed name** | `Skill_ComputeEffectPresenceFlags_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-E OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **presence scan** of ranked skill-runtime effect fields. Builds a bitmask of which effect banks are non-zero, ORs with base dword **`skill+0xc`**, returns the combined mask. Rank-reeval residual: called immediately after `Skill_EvaluateRankedElements` inside `Skill_ReevaluateForCurrentRank`; result written to **`skill+0x624`**.

Not a rank table lookup, not Evaluate itself, not targeting gather.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00627be0` |
| Bytes | `read_memory` entry + tail (`0x00627e80`) — epilogue `mov eax,[ecx+0xc]; or eax,edi; pop edi; ret` |
| Call sites | `read_memory` @ `0x005533b0` (`mov ecx,esi; call`), `0x0054fec0` (`mov esi,ecx; call`) |
| Callers/xrefs | `Skill_ReevaluateForCurrentRank`, `FUN_0054fec0`, `FUN_00627ec0` (3 sites) |
| Parent plate | `Skill_ReevaluateForCurrentRank` — “updates targeting flags +0x624” |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00627be0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature

```c
uint32_t __fastcall Skill_ComputeEffectPresenceFlags_Inferred(void *pSkill);
// ECX = skill; EAX = *(skill+0xc) | presenceBits; plain ret
```

| Item | Evidence |
|---|---|
| Convention | prologue `push edi`; epilogue `pop edi; ret`; no stack formals |
| ECX = skill | call-site `mov ecx,esi` after Evaluate; twin `FUN_0054fec0` keeps ECX=this |
| Leaf | callees empty in analyze |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| 6-slot short bank `+0x60` → bit `0x1` | **Yes** |
| 6-slot short bank `+0x6c` → bit `0x8` | **Yes** |
| 6-slot float bank `+0xa8` → bit `0x80` | **Yes** |
| Paired shorts `+0x78/+0x90` → bit `0x100` | **Yes** |
| Paired shorts `+0x84/+0x9c` → bit `0x200` | **Yes** |
| Misc float group → bit `0x400` (incl. second pair `+0x12c/+0x130`) | **Yes** |
| i16 `+0xd0..+0xd8` → bit `0x40` | **Yes** |
| f32 `+0x38/+0x13c` → `0x20`; char `+0xda` → `0x10`; f32 `+0x3c` → `0x2`; f32 `+0x40` → `0x8000` | **Yes** |
| f32 `+0x10c..+0x118` → `0x10000` | **Yes** |
| f32 `+0x124/+0x128` or (`+0x134` & `+0x138`) → `0x20000` | **Yes** |
| return `*(+0xc) \| flags` | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Presence bit map (offsets + masks) | **High** | decompile ≡ bytes |
| Skill runtime in ECX | **High** | sealed call sites |
| Feeds `skill+0x624` (caller, not body) | **High** | Reevaluate / FUN_0054fec0 |
| Name role “effect presence flags” | **High** | behavior; `_Inferred` for product word |
| Per-bank combat English (dmg/heat/…) | **Open** | no strings in body |
| Full `+0x624` targeting enum | **Open** | consumer residual |

---

## 6. Gaps / open

1. Product/PDB symbol.  
2. English labels for each effect bank.  
3. Base dword `skill+0xc` origin (def static flags vs runtime).  
4. Dual of consumers `FUN_0054fec0` / `FUN_00627ec0` (not OWN).  
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/bit map High; product bank English open.
