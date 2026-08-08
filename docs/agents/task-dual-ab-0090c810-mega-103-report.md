# Dual A/B report — MEGA-103 OWN-ONLY (`0x0090c810`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-103**  
**Scope:** VA `0x0090c810` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `inspect_memory_content` + `get_function_callers` / `get_function_callees` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-103**.  
**Work item:** residual dual seal — **Medal UI query/count** (displayable entry total for parent rebuild / gate peers).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090c810` MedalUI_CountDisplayableEntries_Inferred | **accept-with-gaps** — CF/ABI/EBX-character/vector+hash count/MedalDef lookup/3 call sites sealed; product character/hash English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG-halt / button-alloc / medal-grant / ECX-thiscall / phantom-EBX / RET4 / vector-lookup-filter / sole-caller / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090c810` — sealed facts

1. **Body:** `0x0090c810`–`0x0090c8c9` inclusive (**186 B** / `0xBA`); pad `CC×6` then gap twin @ `0x0090c8d0`; named `FUN_0090c920` @ `0x0090c920`.
2. **ABI:** **EBX** = character / medal-state object (callers `MOV EBX,[DAT_00d1b6d8]`); no stack formals; **EAX** = int count; bare **`RET`** (`C3`).
3. **Semantics:** displayable-entry **count query**:
   - Null EBX → 0.
   - Seed count = dword vector size at **`+0x574/+0x578`** (`(end-begin)>>2`; null begin → 0).
   - Hash at **`+0x540`**: set lock `@+0x1d`; walk chain (`hash+0x14` / `node+0x14`); payload `@node+8`; id `@payload+0x100`.
   - On each payload: `FUN_0051a0e0` (**MedalDef_LookupById**) → count++ if non-null.
   - Clear lock; return count.
   - Lock-warn paths log `"HashError:…"` + `"VOG_DEBUG_STOP"` only (no abort).
4. **Static callees:** `FUN_0051a0e0` (MedalDef_LookupById); `FUN_007a4480` ×4.
5. **Callers (3 sites):**
   - `FUN_0090cbc0` @ `0x0090cbfa` — after prep clear; EAX → page math.
   - `FUN_0090c920` @ `0x0090c938` — visibility gate when count ≤ `0x18`.
   - Gap twin body @ `0x0090c8d0` call `@0x0090c8ed` — same gate pattern (`RET 8`).
6. **Xrefs:** 3× UNCONDITIONAL_CALL.
7. **Name:** `MedalUI_CountDisplayableEntries_Inferred` (Ghidra `FUN_0090c810`). Scaffold `Named_VOG_DEBUG_STOP_0090c810` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `missions-progression` (partition + MedalDef lookup + achievement button peer chain).

### Gaps

- Product English for character class at `DAT_00d1b6d8`.  
- Product English for hash container.  
- Vector raw-size vs display lookup asymmetry (CF fact; validation policy open).  
- Parent `0x0090cbc0` / bind sibling `0x0090c9a0` residual (other MEGA units).  
- Partition hint says "query/**alloc**" — this unit is **query only**.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_CountDisplayableEntries_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090c810.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0090c810.cpp` |
| Function | `docs/reconstruction/functions/aa_0090c810_FUN_0090c810.md` |
| Function named | `docs/reconstruction/functions/aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0090cbc0  Medal UI rebuild host  [residual parent partition]
  ├─ gate: DAT_00d1b6d8 != 0 && host.vtbl[+0x3d8]()
  ├─ FUN_0090c700  MedalUI_PrepClearButtonSlots_Inferred  [dualed MEGA-102]
  ├─ FUN_0090c810  MedalUI_CountDisplayableEntries_Inferred  [OWN MEGA-103]
  ├─ page math @ host+0x5A4 / +0x50C  (threshold 0x18 / 0x19)
  ├─ owned medals walk (vector @ char+0x574) + hash traverse
  │     └─ FUN_0051a0e0  MedalDef_LookupById  [dualed]
  └─ FUN_0090c9a0  bind button "i_d_a_2d_btn_achievement.xml"  [MEGA-095 residual]

FUN_0090c920 / gap@0090c8d0  count-threshold visibility gates
  └─ FUN_0090c810  (shared count)  [OWN MEGA-103]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090c810-mega-103-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090c810` | Port as **medal UI displayable-entry count**. ABI: **EBX=character** (from local-player global), bare RET, **EAX=int**. Count = owned-id vector size (`+0x574/+0x578`) + hash (`+0x540`) entries with valid `MedalDef_LookupById(payload+0x100)`. Hash lock `@+0x1d` warn-only. Do **not** treat as alloc, grant, ECX-thiscall, or VOG halt. |
| Pair with | dualed prep clear `FUN_0090c700`; dualed `MedalDef_LookupById` `0051a0e0`; residual parent `FUN_0090cbc0`; residual bind `FUN_0090c9a0`; gate peers `FUN_0090c920` / gap `0090c8d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / inventory / NAMING_REGISTRY as applicable  
- Do **not** claim runtime Confirmed without Launcher evidence.

**Terminal:** **false**
