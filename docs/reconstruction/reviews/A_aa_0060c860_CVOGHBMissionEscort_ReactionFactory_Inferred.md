# Review A (reconstruction fidelity): `aa_0060c860` CVOGHBMissionEscort_ReactionFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c860` |
| **VA** | `0x0060c860` |
| **Body** | `0x0060c860`–`0x0060c991` (**306 B** / `0x132`); pad `CC` |
| **Canonical name** | `CVOGHBMissionEscort_ReactionFactory_Inferred` |
| **Prior alias** | `FUN_0060c860` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9H-E) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` |
| **System** | missions-progression / heartbeat |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-E** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reaction handler that **may factory-spawn** `CVOGHBMissionEscort`:

1. Gate on owner object enable flag (`+0x7e`) and key match (`req+0x40` vs `obj+0xfc`).
2. `CVOGReaction_ResolveSkillTargets` from req skill fields.
3. Optional `CVOGReaction_CastSkillOnTarget` if `req+0x20`.
4. Stamp score slot `scoreFloats[1+req[8]] = g_flOne`.
5. If range/flag gate + `targets[0x53] != -1`: `operator_new(0x78)` → **`CVOGHBMissionEscort_ctor`** → `CVOGHBList_Enqueue` → `CVOGHBBase_Start`.
6. `operator_delete(targets)`; return success bool.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x0060c860)` ≡ 2026-07-23 raw CF |
| Body bounds | `get_function_by_address` → `0060c860`–`0060c992` |
| Entry/exit | SEH prologue; success `B0 01` … `C2 08 00`; fail `32 C0` … `C2 08 00` |
| Factory | `6A 78; CALL operator_new`; `CALL 0x006507c0` with ECX=new |
| Ctor dual | `A_aa_006507c0_CVOGHBMissionEscort_ctor` — RTTI Escort, size 0x78 |
| Globals | `g_flOne` imm `0x00a0f2a0`; `g_flZero` imm `0x00a0f518` |
| Xrefs | `0060cab2` CALL stub; `0060cac0` JMP thunk |
| Clean | `reconstructed-exact/CVOGHBMissionEscort_ReactionFactory_Inferred.cpp` |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | reqHost | decomp `param_1` as thiscall; uses `EDI` after `mov edi,ecx` |
| **Stack[0x4]** | ownerCtx | `mov esi,[esp+…]` |
| **Stack[0x8]** | scoreFloats* | used for `movss` store |
| cleanup | **`ret 8`** | `C2 08 00` |
| return | **bool AL** | fail `xor al,al`; success `mov al,1` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Outer enable + key gate | **Yes** |
| ResolveSkillTargets | **Yes** |
| Optional cast + fail→delete→false | **Yes** |
| Score float = 1.0 | **Yes** |
| Spawn gate + new(0x78)+ctor+Enqueue+Start | **Yes** |
| Delete targets + true | **Yes** |

---

## 5. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = reaction factory path for Escort HB | **High** | new 0x78 + dualed Escort ctor |
| Class `CVOGHBMissionEscort` (via ctor) | **High** | RTTI on ctor dual |
| thiscall / ret 8 / bool AL | **High** | exit bytes |
| Alloc size 0x78 | **Confirmed** | imm push |
| Product reaction method English | **Open** | `_Inferred` |
| Enclosing type of call stubs | **Open** | gap region |
| Runtime / bit-exact | **Open** | |

**Verdict:** **accept-with-gaps**
