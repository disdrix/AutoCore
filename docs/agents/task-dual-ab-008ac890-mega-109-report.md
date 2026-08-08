# Dual A/B report — MEGA-109 OWN-ONLY (`0x008ac890`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-109**  
**Scope:** VA `0x008ac890` only. Dual A/B + trio raw/annotated/clean + function records.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` (P77, missions-progression, peer `0x008ac110`, hint *Response chrome rebuild peer*).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_xrefs_to` + `get_function_callees` + `get_function_signature` + `read_memory` / `inspect_memory_content`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ac890` `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` | **accept-with-gaps** — CF/ABI/EAX-count/ECX-this/`+0x510`/max-8/peer rebuild sealed; product plate open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): columns-merge / stack-thiscall / min-clamp / packet-send / Named_CalleeOf-columns claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008ac890` — sealed facts

1. **Body:** `0x008ac890`–`0x008ac8af` exclusive (**31** B / `0x1F`); pad `CC` before `FUN_008ac8b0`.
2. **ABI:** **ECX** = `MissionDialogUi*` this; **EAX** = requested response count; void; bare **`RET`** (`C3`).
3. **Semantics:**
   - `dialog+0x510 = EAX`
   - if `EAX > 8` → `dialog+0x510 = 8`
   - `MOV EDI, ECX`; call **`FUN_008ac110`** (`UI_MissionDialog_BuildResponseButtons_Inferred`, EDI-this)
4. **Callees:** `FUN_008ac110` only.
5. **Callers / xrefs (3 UNCONDITIONAL_CALL):**
   - `FUN_008ac8b0` @ `0x008acb02` — after `NUM_RESPONSES` + `swscanf("%d;%d")` → `EAX=[esp+0x20]`, `ECX=EDI`
   - `0x008ad224` — ASCII `"NUM_RESPONSES"` @ `0x00a4adc0` parse path → `ECX=EBX`
   - `FUN_0093e450` @ `0x0093e6e9` — `EAX = FUN_005795b0` vector size `(end-begin)>>2`, `ECX=EBX`
6. **analyze_function_complete:** classification **wrapper**; 9 insns; 3 BBs; immediate **8**.
7. **Name:** `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` (Ghidra `FUN_008ac890`). Product open → `_Inferred`. Scaffold `Named_CalleeOf_Named_NUM_RESPONSE_COLUMNS_*` **retired** (wrong field attribution).
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / PDB English.  
- Full dual of producers `FUN_008ac8b0` / `FUN_0093e450` (not OWN).  
- Design rationale for max **8** beyond chrome capacity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionDialog_SetResponseCountAndRebuild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ac890.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_NUM_RESPONSE_COLUMNS_008ac890.cpp` |
| Function | `docs/reconstruction/functions/aa_008ac890_FUN_008ac890.md` |
| Function named | `docs/reconstruction/functions/aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008ac8b0  XML prop dispatch (RESPONSE_WINDOW / NUM_RESPONSES / NUM_ITEM_COLUMNS /
              NUM_RESPONSE_COLUMNS / ITEM_*)
  ├─ NUM_RESPONSES → FUN_008ac890  [OWN MEGA-109]
  │                    └─ FUN_008ac110 BuildResponseButtons  [dualed WQ7R-B]
  └─ NUM_RESPONSE_COLUMNS → store dialog+0x640 only (no 008ac890)

ASCII key path @ 0x008ad224
  └─ "NUM_RESPONSES" → FUN_008ac890  [OWN]

FUN_0093e450  mission UI flow
  ├─ early: [dialog+0x510]=1; CALL FUN_008ac110   (bypass wrapper)
  └─ multi: FUN_005795b0 size → FUN_008ac890      [OWN]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008ac890-mega-109-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ac890` | Port as **set response count + rebuild buttons**. **ECX=dialog, EAX=count, bare RET**. Clamp **max 8** at `+0x510`. Always call dualed BuildResponseButtons after. |
| Do not | Treat as NUM_RESPONSE_COLUMNS (`+0x640`); do not invent stack thiscall count; do not claim C2S. |
| Pair with | dualed `UI_MissionDialog_BuildResponseButtons_Inferred` (`0x008ac110`); residual parent `FUN_008ac8b0` NUM_* props. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA only in allowed ledgers (not touched by this agent):

- `VERIFICATION_MATRIX.md` / coverage / naming when parent merges MEGA residual wave.
