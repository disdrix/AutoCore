# Dual A/B report — W18-R OWN VAs `0x00725a70` + `0x00521310`

**Date:** 2026-07-29  
**Agent:** W18-R OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00725a70`, `0x00521310`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image base:** `0x400000` (`autoassault.exe`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00725a70` CSoundManager_TryQueueMissionCompleteSound_Inferred | **accept-with-gaps** — enable + fixed XZ radius + hardcoded type-0x32 queue sealed |
| `aa_00521310` CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred | **accept-with-gaps** — CurrentVehicle resolve → SetVehicle → AddCharacter sealed |

---

## Sealed facts — `0x00725a70`

1. **ABI:** `__thiscall` on `CSoundManager` (`mov ebp,ecx`); stack `(pathOrKey, float* pos)`; **`ret 8`**; body **`0x00725a70`–`0x00725bcd`** (349 B); returns **1/0**.
2. **Enable:** `this+0x258 == 0` → 0.
3. **Proximity:** fail only if `||pos|| > 0` **and** XZ dist² vs `this+0x220/+0x228` **> 10000.0** (`DAT_00aaa880`).
4. **Path:** `FUN_007249c0` → freelist `FUN_00480460` → `FUN_00480170` → `strncpy` 0x104 → `FUN_00480350(this+0x310)`.
5. **Hardcoded slot:** type **`0x32`**, TFID **`-1`**, `+0x110=20.f`, `+0x114=100.f`, `+0x11c=1.f` (byte-sealed; decompiler `g_nInferredThreatDefault` **wrong**).
6. **Caller:** sole xref `FUN_004b0f80` (mission-complete audio + `Client_GetMissionCompleteAudioTable`).
7. **Sibling:** `0x007258a0` TryQueueProximity — descriptor radius + field copy; this unit is fixed-radius hardcoded.

---

## Sealed facts — `0x00521310`

1. **ABI:** `__thiscall` on character **subobject** `this_adj`; **`ret 0x18`**; body **`0x00521310`–`0x00521430`** (288 B).
2. **Vehicle:** resolve COID at `this_adj-0xb90/-0xb8c` via `FUN_004bafe0` → **`Creature::SetVehicle`** `FUN_004c49d0`.
3. **If vehicle:** `FUN_0053d970(0)`; `vehicle+0x101 = (this_adj-0xa94 == 0)`.
4. **Map:** unconditional `CVOGSectorMap_AddCharacter(this_adj - 0xda0)`.
5. **LOD:** if `*param_2 == 0x2016` and RTTI cast to `gfxLODHandler_AutoAssault` → `FUN_00760fe0(0, 999.0f)`.
6. **GFX:** if host object `+0xe898` → `FUN_004962b0`.
7. **Caller:** `CVOGCharacter_CreateFromPacket` @ `0x005238c7` (+ orphan xref `0x0053bed3`).
8. **Alias fix:** not a callee of AddCharacter — it **calls** AddCharacter.

---

## Gaps

### `00725a70`
1. Product/PDB English name.  
2. Null freelist strncpy residual.  
3. Runtime / differential open.

### `00521310`
1. `param_3..6` semantics (flag-forward only).  
2. `vehicle+0x101` product meaning.  
3. Orphan xref `0x0053bed3`.  
4. Runtime / differential open.

---

## Files

### `aa_00725a70`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00725a70_CSoundManager_TryQueueMissionCompleteSound_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00725a70_FUN_00725a70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_TryQueueMissionCompleteSound_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00725a70.cpp` |
| Raw | `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.md` |
| Annotated | `docs/reconstruction/raw/aa_00725a70_FUN_00725a70.annotated.md` |
| Scratch | `tmp/a_00725a70.md` |

### `aa_00521310`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00521310_FUN_00521310.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00521310.cpp` |
| Raw | `docs/reconstruction/raw/aa_00521310_FUN_00521310.md` |
| Annotated | `docs/reconstruction/raw/aa_00521310_FUN_00521310.annotated.md` |
| Scratch | `tmp/a_00521310.md` |

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00725a70-00521310-w18r-report.md` |

---

## AutoCore impact

- **Mission-complete audio:** client queues type-`0x32` UI/mission SFX with **fixed 100-unit XZ hear radius**; server need not replicate this helper unless matching client-side mission SFX.
- **Character create:** ensure **CurrentVehicleCoid** is present on create so client `SetVehicle` runs (player vehicle HP / owner framing). Always **AddCharacter** after attach attempt.
- No Launcher started; no parent ledger edits.
