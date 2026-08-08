# Dual A/B report — MEGA-102 OWN-ONLY (`0x0090c700`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-102**  
**Scope:** VA `0x0090c700` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_xrefs_to` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-102**.  
**Work item:** residual dual seal — **Medal UI prep** (clear 24 achievement button slots before parent rebuild).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090c700` MedalUI_PrepClearButtonSlots_Inferred | **accept-with-gaps** — CF/ABI/EDI-host/slot+0x540×24/vcall offsets/sole-caller prep role sealed; product host/widget English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): medal-grant / full-rebuild / ECX-thiscall / byte-offset-0x150 / always-detach / flags=0 / host-dtor / scaffold-product / multi-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090c700` — sealed facts

1. **Body:** `0x0090c700`–`0x0090c74c` inclusive (**77 B** / `0x4D`); pad `CC×3` then `FUN_0090c750` @ `0x0090c750`.
2. **ABI:** **EDI** = medal UI host (caller `MOV EDI,ESI` @ `0x0090cbed`); no stack formals; void; bare **`RET`** (`C3`).
3. **Semantics:** prep **clear** of 24 button slots at **`host+0x540`**:
   - Skip null slots.
   - Host `vtbl[+0x3d8]()` (ECX=host) → if AL ≠ 0, host `vtbl[+0xb0](slot*)`.
   - If slot still non-null: scalar-deleting dtor `(*slot)->vtbl[0](slot, 1)`.
   - Always `slot = 0`.
4. **Static callees:** none (virtual only). Analyze "leaf" = no static FUN_* edges.
5. **Callers (1):** `FUN_0090cbc0` @ `0x0090cbef` UNCONDITIONAL_CALL — after global `DAT_00d1b6d8` + host visibility gate; before `FUN_0090c810` count and `FUN_0090c9a0` bind.
6. **Xrefs:** 1× UNCONDITIONAL_CALL.
7. **Name:** `MedalUI_PrepClearButtonSlots_Inferred` (Ghidra `FUN_0090c700`). Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `missions-progression` (partition + achievement button XML peer).

### Gaps

- Product English for medal UI host class.  
- Product names for host vtbl `+0x3d8` / `+0xb0`.  
- Slot widget RTTI (sibling XML `i_d_a_2d_btn_achievement.xml` only).  
- Parent `0x0090cbc0` / siblings `0x0090c810` / `0x0090c9a0` residual (other MEGA units).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_PrepClearButtonSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090c700.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700.cpp` |
| Function | `docs/reconstruction/functions/aa_0090c700_FUN_0090c700.md` |
| Function named | `docs/reconstruction/functions/aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0090cbc0  Medal UI rebuild host  [residual parent partition]
  ├─ gate: DAT_00d1b6d8 != 0 && host.vtbl[+0x3d8]()
  ├─ FUN_0090c700  MedalUI_PrepClearButtonSlots_Inferred  [OWN MEGA-102]
  ├─ FUN_0090c810  medal count for UI                     [MEGA-103 residual]
  ├─ page math @ host+0x5A4 / +0x50C
  ├─ owned medals walk (vector @ char+0x574) + hash traverse
  │     └─ FUN_0051a0e0  MedalDef_LookupById  [dualed elsewhere]
  └─ FUN_0090c9a0  bind button "i_d_a_2d_btn_achievement.xml"  [MEGA-095 residual]
        └─ stores widget* into host slots @ +0x540 family

FUN_0090c750  zero slots + related fields (no dtor)  [sibling; not owned]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090c700-mega-102-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090c700` | Port as **medal UI prep clear** of **24** button slots at **`host+0x540`**. ABI: **EDI=host**, bare RET, no stack args. Per non-null slot: optional host detach (`vtbl+0x3d8` gate → `vtbl+0xb0`), then scalar-delete flags=**1**, null slot. Call from rebuild path **before** count/bind. Do **not** treat as medal grant, host dtor, or ECX-thiscall. |
| Pair with | residual parent `FUN_0090cbc0`; residual count `FUN_0090c810`; residual bind `FUN_0090c9a0`; dualed `MedalDef_LookupById` `0051a0e0`; sibling zero-init `FUN_0090c750` (no dtor — keep distinct). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / inventory / NAMING_REGISTRY as applicable  
- Do **not** claim runtime Confirmed without Launcher evidence.

**Terminal:** **false**
