# Dual A/B report — MEGA-083 OWN-ONLY (`0x00402ae0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-083**  
**Scope:** VA `0x00402ae0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — Named_CalleeOf **SendRespawnInSector** → shared map find.  
**System:** `interaction-activation`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402ae0` StdMap_Find_Tfid_Isnil29_EaxMap_Inferred | **accept-with-gaps** — CF/ABI/RET4/EAX-map/EDI-key/equality find/5 xrefs sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-merge / RET8 / pure-lower_bound / insert / respawn-only / CNDHash claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402ae0` — sealed facts

1. **Body:** `0x00402ae0`–`0x00402b2f` inclusive (**80 B** / `0x50`); next fn @ `0x00402b30`.
2. **ABI:** **EAX** = map (`head@+4`); **EDI** = TFID-shaped key*; stack `Node** outIt`; **EAX** = outIt after store; **`RET 4`** both exits.
3. **Semantics:** MSVC-style **map::find**:
   - `lb = FUN_00403e50(map, key)` residual lower_bound (isnil@**+0x29**, key lo@**+0x10** / hi@**+0x14**).
   - If `lb != head` and `node.key <= *key` (hi **signed**, lo **unsigned**) → `*outIt = lb`.
   - Else `*outIt = head` (end / miss).
   - Read-only; no insert/erase/color.
4. **Callees:** `FUN_00403e50` only (residual — not dualled).
5. **Callers / xrefs:** **5** UNCONDITIONAL_CALL:
   - `Client_SendRespawnInSector` @ `0x00935340` (map `client+0xd24`, key TFID `+0x164`)
   - `FUN_00944d50` @ `0x00944e4b` (payload `@node+0x20`)
   - `Client_Input_OnKeyDown_MatchAction` @ `0x0091120a` (global map `0x00d1b564`)
   - `FUN_0091da70` @ `0x0091df4e`
   - site `0x00957e3a`
6. **Twin (ABI-different):** dualed `StdMap_Find_Tfid_Isnil29_Inferred` `0x004cba00` (ECX thiscall, RET 8, lower_bound `004cb4b0`).
7. **Name:** `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` (Ghidra `FUN_00402ae0`). Product map English open → `_Inferred`. Retired `Named_CalleeOf_Client_SendRespawnInSector_00402ae0`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product map host / value_type English (`node+0x20`).
- Residual lower_bound `FUN_00403e50` (OWN of a future residual if partitioned).
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402ae0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendRespawnInSector_00402ae0.cpp` |
| Function | `docs/reconstruction/functions/aa_00402ae0_FUN_00402ae0.md` |
| Function named | `docs/reconstruction/functions/aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00402ae0  StdMap_Find_Tfid_Isnil29_EaxMap_Inferred  [OWN MEGA-083]
  └─ FUN_00403e50  lower_bound isnil29 pair-key  [residual]

Callers (evidence):
  Client_SendRespawnInSector @ 00935300
    map = client+0xd24; key = entity TFID @ +0x164
    gate: *outIt == client+0xd28 before packing C2S 0x2073
  FUN_00944d50 / Client_Input_OnKeyDown_MatchAction / FUN_0091da70 / 00957e3a
    same find; payload often @ node+0x20

ABI twin (dualed elsewhere, different convention):
  004cba00  StdMap_Find_Tfid_Isnil29_Inferred  [WQ9G-G]
    └─ 004cb4b0  StdMap_LowerBound_Tfid_Isnil29  [W31-N]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402ae0-mega-083-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402ae0` | Port as **map::find** for TFID-shaped pair keys on isnil@**+0x29** nodes. **EAX=map**, **EDI=key**, stack outIt, **RET 4**. Equality after lower_bound; miss → head. |
| Do not | Use thiscall RET 8 twin `004cba00` ABI; treat as respawn-only; invent insert. |
| Pair with | residual lower_bound `00403e50`; dualed twin find `004cba00` / lower_bound `004cb4b0`; parent `Client_SendRespawnInSector` (consumer only). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / system map `interaction-activation` entry refresh
- retire Named_CalleeOf inventory rows if present
