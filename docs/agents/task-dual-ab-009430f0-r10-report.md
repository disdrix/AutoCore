# Dual A/B report — R10-017 OWN-ONLY (`0x009430f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-017**  
**Scope:** VA `0x009430f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent dual body `0x00942e20`).  
**Ghidra:** `decompile_function` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` / `get_xrefs_to` + `read_memory` + `get_function_by_address` + `get_function_signature` + `get_function_hash` + caller/callee decompiles. **No** `disassemble_bytes`. `analyze_function_complete` returned `Function not found: null` on this Ghidra instance — sealed via disasm+hash+xrefs.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual — partition skills-abilities; parent dual adjacency `0x00942e20` (frame tick ends exclusive at this VA).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009430f0` Client_OnLocalCharacterReady_EnterWorldSetup_Inferred | **accept-with-gaps** — CF/ABI/ESI-host/bare-RET/508B/callers/floats/`//rejoinchat`/stages sealed; product English + undualed helper depth open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): freestanding-void / ECX-client thiscall / stack-args / CreateCharacter-only / parent-body / integer-zoom claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x009430f0` — sealed facts

1. **Body:** `0x009430f0`–`0x009432eb` inclusive (**508 B** / `0x1FC`).
2. **ABI:** **ESI** = client/session host; no stack args; void; **bare `RET`** (`C3`).
3. **Semantics:** multi-stage local-character-ready / enter-world setup:
   - world-root scan (`004d9f00`)
   - env flag `+0x8c=1`
   - camera mode **6** + zoom **10.0f** / **~6.7f**
   - first-time tips 0x19/0x17/0x31/(0x30)
   - UI panel refresh (`009301b0`)
   - optional `//rejoinchat` (`00941fb0` modes 3 then 1)
   - session flags (`DAT_00d1ad1c`, `+0xb6/0xb7`)
4. **Callees:** `004d9f00`, `004962b0`, `00923c50`, `Client_MaybeShowFirstTimeTip`×4, `00541a80`, `CNDHash_LookupByKey` (`005b0920`), `009301b0`, `0066e9c0`, `00941fb0`×2, camera vfuncs.
5. **Callers / xrefs:** **3** UNCONDITIONAL_CALL:
   - `Client_RecvCreateCharacter` @ `0x00814959`
   - `FUN_00946c00` @ `0x00946ceb` (case 3)
   - `FUN_00946c00` @ `0x009477ae` (type 0x1e)
6. **Floats:** `DAT_00a110d8` = 10.0f; `DAT_00aaaccc` ≈ 6.7f (`read_memory`).
7. **String:** `"//rejoinchat"` @ `0x00a2cff8`.
8. **Name:** `Client_OnLocalCharacterReady_EnterWorldSetup_Inferred` (Ghidra `FUN_009430f0`). Product English open → `_Inferred`. Scaffold `Named_CalleeOf_Client_RecvCreateCharacter_009430f0` **retired**.
9. **Decompile ≡ raw CF**; ABI from disasm + call-site context (decompiler `unaff_ESI` promoted to sealed ESI host).
10. **Hash:** `1ad832af581bdcc60c4b4a75caf7bcfa85e02bf1830345b6fdc33c2df2316299`.

### Gaps

- Product English for camera class, worldRoot fields, tip ID table, case-3 / 0x1e event names.  
- Undualed helper internals (`004d9f00`, `00923c50`, `009301b0`, `00941fb0`).  
- FUN_00941fb0 param_1 string at `0x00a1419b`.  
- Runtime / bit-exact / differential.  
- Partition tag `skills-abilities` is residual adjacency to dualed parent `0x00942e20`, not a call edge.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_009430f0_FUN_009430f0.md` |
| Annotated | `docs/reconstruction/raw/aa_009430f0_FUN_009430f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009430f0.cpp` |
| Function | `docs/reconstruction/functions/aa_009430f0_FUN_009430f0.md` |
| Function named | `docs/reconstruction/functions/aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RecvCreateCharacter  0x008146b0
  local-player + extended (in_AL):
    quickbar restore ×100
    FUN_0094c2d0 / 0094c350 / 0094c2a0
    Client_OnLocalCharacterReady_EnterWorldSetup_Inferred  [OWN R10-017]

FUN_00946c00  0x00946c00  (client message/state dispatcher)
  switch(msg[7]) case 3:
    Client_OnLocalCharacterReady_EnterWorldSetup_Inferred  [OWN R10-017]
  queue walk type==0x1e:
    Client_OnLocalCharacterReady_EnterWorldSetup_Inferred  [OWN R10-017]

Client_FrameTick_EnvDayCycleAndSystems_Inferred  0x00942e20
  body ends exclusive @ 0x009430f0   [dualed parent; adjacency only — not a caller]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-009430f0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009430f0` | Port as **ESI-host enter-world setup**: no stack args, bare RET. Stages: world scan → env flag → camera mode 6 + float zoom (10.0 / 6.7) → tips → UI refresh → optional `//rejoinchat` → flags. Do **not** model as freestanding void or as CreateCharacter packet parser. |
| Pair with | `Client_RecvCreateCharacter` `008146b0`; residual dispatcher `FUN_00946c00`; dualed adjacent frame tick `00942e20` (not a caller). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when integrating R10-017  
- retire residual `Named_CalleeOf_*_009430f0` index rows in favor of `Client_OnLocalCharacterReady_EnterWorldSetup_Inferred`  
- systems residual tables (partition skills-abilities / client enter-world)

**Terminal:** false (runtime open; dual seal complete for OWN VA).
