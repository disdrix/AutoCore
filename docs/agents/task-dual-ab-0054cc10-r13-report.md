# Dual A/B report — R13-038 OWN-ONLY (`0x0054cc10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-038**  
**Scope:** VA `0x0054cc10` (`aa_0054cc10`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-038**.  
**Work item:** Residual dual seal — skills-abilities skill-staging payload mid-field zero (partition parent dual `0x0054cbb0`).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0054cc10` SkillStaging_ZeroPayloadFields_Inferred | **accept-with-gaps** — CF + thiscall bare-RET + range `+0x28..+0x534` + leaf + sole CALL sealed; role English Inferred; per-slot names + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): factory-merge / full-object memset / multi-CALL / RET4 / non-leaf / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0054cc10` — sealed facts

1. **Body:** `0x0054cc10`–`0x0054d43f` inclusive (**2096 B** / `0x830`); terminal **`C3`**; next function `0x0054d440`.
2. **ABI:** **thiscall** (ECX = self); **0** stack args; bare **`RET`**; void (EAX not a result).
3. **Semantics:** **Skill-staging payload mid-field zero**:
   - `XORPS xmm0,xmm0`; `MOV EAX,ECX`.
   - Store 0 to every dword/float slot **`this+0x28` … `this+0x534`** inclusive (**324** / `0x144` dwords; span `0x510` B).
   - Interleaved `MOVSS` / integer `MOV`; no branches; no SEH; **0** callees.
4. **Does not** clear `this+0x00..+0x27` (header left intact by this leaf alone).
5. **Code xrefs:** **1** UNCONDITIONAL_CALL — `0x0054a2d1` in `FUN_0054a290` (`SkillDef_InstallLoadedRecord`).
6. **Call site:** `LEA ECX,[ESP+0x1a0]` then `CALL`; after return caller `REP STOSD` **`0x14e`** dwords on same buffer (full staging size **`0x538`** B).
7. **DATA xrefs:** **0**.
8. **Name:** `SkillStaging_ZeroPayloadFields_Inferred` (Ghidra `FUN_0054cc10`).
9. **Decompile ≡ raw CF**; range/ret sealed via `read_memory` + function body bounds (no `disassemble_bytes`).
10. **Not** PossessCreature DefaultFactory (`0x0054cbb0`): adjacent only; no alloc/vtbl.

### Gaps

- Product English for each slot in `+0x28..+0x534`.  
- Rationale for mid-zero before full `0x14e` clear on sole path (subset).  
- Indirect reachability beyond single CALL.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.md` |
| Annotated | `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillStaging_ZeroPayloadFields_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0054cc10.cpp` |
| Function | `docs/reconstruction/functions/aa_0054cc10_FUN_0054cc10.md` |
| Function named | `docs/reconstruction/functions/aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0054cc10.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0054a290  SkillDef_InstallLoadedRecord  [caller dual elsewhere]
  ├─ if skill-element count short == 0:
  │     log "Skill %d had no skill elements - it won't work."
  │     return
  ├─ LEA ECX, [ESP+0x1a0]          // stack staging (0x538 B / 0x14e dwords)
  ├─ CALL FUN_0054cc10             [OWN R13-038]
  │     └─ zero staging[+0x28 .. +0x534]
  ├─ REP STOSD 0x14e dwords        // full staging clear (includes header)
  ├─ pack class/flags from skill blob
  ├─ FUN_005495f0 / FUN_0054d9a0 / map insert-or-overwrite
  └─ Skill_InitializeRuntimeObject + ExactFind path …

FUN_0054cbb0  PossessCreature DefaultFactory  [partition parent dual R12-023]
  └─ adjacent leaf only — not a caller of 0054cc10
```

Do **not** merge with:
- `CVOGHBSkill_PossessCreature_DefaultFactory` (`0x0054cbb0`)
- full-arg PossessCreature ctor (`0x00626240`)
- full staging `REP STOSD` (caller-owned)
- skill-map insert helpers (`FUN_0054e9a0` / `FUN_0054ea60`)

---

## AutoCore impact

| Port note |
|-----------|
| Port as **pure mid-field zero**: write 0 to dwords `[self+0x28, self+0x538)`. Preserve thiscall/void. Do **not** treat as full staging memset (header `0x00..0x27` is caller’s job). Do **not** merge with skill HB factories. Staging record size remains **`0x538`** bytes (`0x14e` dwords) at the install call site. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs/callers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended**.  
- Name uses `_Inferred` (role English); CF/ABI/range **High** — **never Runtime Confirmed**.  
- Avoid bare `undefined4` in clean (`uint32_t` / `void *`).

---

## This report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0054cc10-r13-report.md` |
