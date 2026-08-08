# Dual A/B report — WQ9E-D OWN-ONLY (`0x0082fe20`, `0x00520330`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9E-D**  
**Scope:** VAs `0x0082fe20`, `0x00520330` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md` → **WQ9E-D**.  
**Work item:** WQ-009 depth-2 residual dual seal (convoy menu parent + crew back-link setter).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082fe20` UI_InteractionMenu_PopulateTargetButtons_Inferred | **accept-with-gaps** — CF/ABI/pack orders/convoy child/vtbl sealed; product host class + vtbl English open |
| `aa_00520330` Object_SetCrewHostBackLink_Inferred | **accept** — leaf store `+0xCB0` / `ret 4` / 7 callers sealed; product demangle residual only |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; decompiler this-arg trap on setter closed; “convoy-only parent” rejected (seven packs).

---

## VA `0x0082fe20` — sealed facts

1. **Body:** `0x0082fe20`–`0x0082ff3f` exclusive (**287 B** / `0x11F`); pad `CC`. Epilogues **`ret`** (`C3`).

2. **ABI:** MSVC **`__thiscall`** (entry `push esi; mov esi, ecx`).  
   - `ECX` / `ESI` = interaction **menu host***  
   - **No** stack cleanup (`ret 0`)  
   - Sole xref: **DATA** vtbl slot `@ 0x00a720e0` (virtual method)

3. **Semantics — populate target social buttons:**
   - Gate: host **`+0x4C0`** non-zero.
   - **`FUN_0082d2b0`**: rebuild popup shell (blocker path).
   - Resolve target TFID at host **`+0x578`** via `Object_ResolveFromTFID`.
   - Skip pack if no local (`DAT_00d1b6d8`), resolve fail, or local SharedBase **`vtbl+0x298(target)`** non-zero.
   - Target **`vtbl+0x210(0)`**: owner/parent; skip if null or == local.
   - Optional close: if host **`+0x2B0`** set → `FUN_0090d400`.
   - Host **`vtbl+0x478()`** selects pack order:
     - **0:** Ignore → Friends → Tell → Trade → Clan → **Convoy** → Name  
     - **≠0:** reverse (Name → Convoy → … → Ignore)

4. **Dualed child:** `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`0x0082fb30`) at call sites **`0x0082fec7`**, **`0x0082ff1b`**.

5. **Sibling packs (strings sealed via child decompiles, not OWN dual):**  
   Tell (`0x11176`), Ignore add/remove, Friends add/remove, Trade (`0x11175`), Clan invite/kick (`0x11173`/`0x11174`), nameplate button (`0x1117f`).

6. **Name:** `UI_InteractionMenu_PopulateTargetButtons_Inferred` (Ghidra `FUN_0082fe20`). Product menu class **Inferred**.

7. **Decompile ≡ raw CF**; body span sealed via `read_memory` + function meta.

### Gaps

- Product / MSVC demangle for menu host class.  
- English for `+0x4C0`, `+0x2B0`, affinity/owner/order vtbl slots.  
- Dual of sibling packs / `FUN_0082d2b0` / `FUN_0090d400` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082fe20_FUN_0082fe20.md` |
| Annotated | `docs/reconstruction/raw/aa_0082fe20_FUN_0082fe20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_PopulateTargetButtons_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082fe20.cpp` |
| Function | `docs/reconstruction/functions/aa_0082fe20_FUN_0082fe20.md` |
| Function named | `docs/reconstruction/functions/aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md` |

---

## VA `0x00520330` — sealed facts

1. **Body:** `0x00520330`–`0x0052033d` exclusive (**13 B**); pad `CC`.

2. **Bytes:** `8B 44 24 04  89 81 B0 0C 00 00  C2 04 00`  
   → `eax=[esp+4]`; `*(ecx+0xCB0)=eax`; **`ret 4`**.

3. **ABI:** **`__thiscall`**; ECX = object*; stack = host* or null; void.

4. **Semantics:** leaf **crew-host back-link** store at **`+0xCB0`**.  
   - Insert (`VehicleCrew_InsertMember_Inferred`): **member+0xCB0 = host**  
   - Clear/wipe/leave: **member+0xCB0 = 0**  
   - Convoy dual reads `*(local+0xCB0)` as Contains host.

5. **Callers (7):** `FUN_00574a30`, `FUN_00574a90` (Clear), `FUN_005750e0`, `FUN_00575200`, `FUN_005752c0`, `FUN_005755b0` (Insert), `FUN_0094dab0`.

6. **Callees:** none.

7. **Name:** `Object_SetCrewHostBackLink_Inferred` (Ghidra `FUN_00520330`). Supersedes scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_00520330`.

8. **Decompile ≡ raw CF** with call-site this-arg sealed by bytes (prior Insert dual + this OWN).

### Gaps

- Product demangle for field/class.  
- Whether non-crew systems share `+0xCB0` outside this caller set.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00520330_Object_SetCrewHostBackLink_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00520330_Object_SetCrewHostBackLink_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00520330_FUN_00520330.md` |
| Annotated | `docs/reconstruction/raw/aa_00520330_FUN_00520330.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetCrewHostBackLink_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00520330.cpp` |
| Function | `docs/reconstruction/functions/aa_00520330_FUN_00520330.md` |
| Function named | `docs/reconstruction/functions/aa_00520330_Object_SetCrewHostBackLink_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082fe20-00520330-wq9ed-report.md` |
| Scratch | `docs/reconstruction/tmp/a_0082fe20_00520330_wq9ed_notes.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082fe20` | Port as **interaction-menu social button populate**, not cast residual. Gate `+0x4C0`; target TFID `+0x578`; dual pack order via `vtbl+0x478`. Keep convoy child `0082fb30` as one pack among seven. Dispatch via **vtbl** (`0x00a720e0`), not a direct CALL graph. |
| `00520330` | Port as **4-byte leaf**: `object.crewHost@+0xCB0 = arg`. Insert sets host; Clear/wipe set null. Pair with Contains/Insert/Clear duals and convoy `*(local+0xCB0)` read. |
| Pair with | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred`, `VehicleCrew_InsertMember_Inferred`, `VehicleCrew_ClearMemberObject_Inferred`, `VehicleCrew_ContainsMember_Inferred` |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (crew back-link) + UI/interaction notes as appropriate  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0082fe20`, `0x00520330`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: reverse pack order; decompiler Insert this-arg corrected for setter; DATA-only vtbl parent.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
