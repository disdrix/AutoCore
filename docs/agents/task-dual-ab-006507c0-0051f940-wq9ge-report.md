# Dual A/B report — WQ9G-E OWN-ONLY (`0x006507c0`, `0x0051f940`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-E**  
**Scope:** VAs `0x006507c0`, `0x0051f940` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-E**.  
**Work item:** WQ-009 depth-4 residual dual seal (escort ctor + class display leaf).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006507c0` CVOGHBMissionEscort_ctor | **accept-with-gaps** — Escort RTTI + ctor CF/ABI/vtable/field seed sealed; reqHost English + gap call site residual |
| `aa_0051f940` LookupClassDisplayName_Inferred | **accept-with-gaps** — class×race product table + cdecl leaf sealed; method English Inferred |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; Outpost / 3-arg / race-first / void-return / ring-owning claims falsified.

---

## VA `0x006507c0` — sealed facts

1. **Body:** `0x006507c0`–`0x006508c8` exclusive (**264 B** / `0x108`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = this; stack `ownerCtx`, `reqHost`; **RET 8**; returns **this**.
3. **Class:** **`CVOGHBMissionEscort`** — COL `0x00ab1e9c` → TD `0x00af4a10` `.?AVCVOGHBMissionEscort@@`.
4. **Role:** **ctor** — `CVOGHBBase_ctor` then install `PTR_FUN_009e52c4`; OnHB @ vtable **+0x0C** = dualed `0x006508d0`.
5. **Seeds:** missionKey / matchRef / matchMode / maxRange / complete-zone dual from `reqHost`; default TFID pad `{−1,−1,0,0}` @ +0x38; tag `0x0b` @ +0x1C; period **1000** @ +0x08; tick @ +0x70.
6. **Callees:** `CVOGHBBase_ctor`, `FUN_0060c3c0` (req match resolve), `CVOGHBBase_SetPeriodAndCounter`, `CVOGHBBase_AttachOwnerObject`.
7. **Factory:** `FUN_0060c860` @ `0x0060c95a` — `operator_new(0x78)` → this → Enqueue → Start. Raw second site `0x00613e62` (Ghidra function gap).
8. **Name:** `CVOGHBMissionEscort_ctor` (Ghidra `FUN_006507c0`). RTTI Confirmed — no `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/vtable/pad sealed via `read_memory`.

### Gaps

- Product English for full reqHost field dictionary (partial via OnHB dual).  
- Enclosing FUN for call site `0x00613e62`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006507c0_CVOGHBMissionEscort_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006507c0_CVOGHBMissionEscort_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006507c0_FUN_006507c0.md` |
| Annotated | `docs/reconstruction/raw/aa_006507c0_FUN_006507c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionEscort_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006507c0.cpp` |
| Function | `docs/reconstruction/functions/aa_006507c0_FUN_006507c0.md` |
| Function named | `docs/reconstruction/functions/aa_006507c0_CVOGHBMissionEscort_ctor.md` |

---

## VA `0x0051f940` — sealed facts

1. **Body:** `0x0051f940`–`0x0051f9f9` exclusive (**185 B** / `0xb9`); pad `CC`.
2. **ABI:** **cdecl**; stack `classId`, `raceId`; plain **`RET`**; returns **const char\*** (static rodata).
3. **Semantics:** pure leaf switch on classId 0..3 with race sub-branches; default `"Unknown"`. **No callees.**
4. **Product table (Confirmed strings):**

| classId | race0 | race1 | race2 | else |
|---|---|---|---|---|
| 0 | Commando | Champion | Terminator | Commando |
| 1 | Engineer | Shaman | Constructor | Engineer |
| 2 | Lieutenant | Archon | MasterMind | Officer |
| 3 | Bounty Hunter | Avenger | Agent | Ranger |
| other | Unknown | | | |

5. **Callers (6):** `Character_GetClassDisplayName_Inferred` (`0x00521900`), `FUN_00521970`, `FUN_00845360`, `FUN_00846820`, `FUN_008967b0`, `FUN_008a3510`.
6. **Xrefs:** 12 UNCONDITIONAL_CALL.
7. **Name:** `LookupClassDisplayName_Inferred` (Ghidra `FUN_0051f940`). Role High; product symbol English open → `_Inferred`.
8. **Closes residual** of dualed wrapper `aa_00521900` (table was unowned callee evidence).
9. **Decompile ≡ raw CF** (2026-07-23 scaffold ≡ 2026-08-04 live); strings sealed via `read_memory`.

### Gaps

- Product/PDB method English.  
- Race id dictionary labels (peer race dual).  
- Runtime golden matrix / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f940_LookupClassDisplayName_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051f940_LookupClassDisplayName_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051f940_FUN_0051f940.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f940_FUN_0051f940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LookupClassDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f940.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f940_FUN_0051f940.md` |
| Function named | `docs/reconstruction/functions/aa_0051f940_LookupClassDisplayName_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006507c0-0051f940-wq9ge-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006507c0` Escort ctor | Port as **CVOGHBMissionEscort** factory body: size **0x78**, vtable **`PTR_FUN_009e52c4`**, period **1000**, field map shared with dualed OnHB. Pair with `CVOGHBMissionEscort_OnHeartBeat` / `FUN_0060c860` enqueue path. Do not confuse with Outpost (nearby string litter). |
| `0051f940` class lookup | Port as **pure (classId, raceId) → static English** table for `[$class]` and UI. **Do not** free return; ring is wrapper-side. Keep argument order **(class, race)**. |
| Pair with | Escort OnHB `006508d0`; class wrapper `00521900`; race display `00521800`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/missions-progression.md` (escort ctor + class leaf residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x006507c0`, `0x0051f940`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw for `0051f940` preserved; re-verify **appended** only. New raw for `006507c0`.  
- Clean sources use meaningful names (not Ghidra iVar paste).  
- Odd behavior preserved: SetPeriod(−1000) then force period=1000; case0/1 race fold asymmetry vs case2/3; gap call site at `00613e62`.  
- `_Inferred` only where English unproven; RTTI ctor not Inferred. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
