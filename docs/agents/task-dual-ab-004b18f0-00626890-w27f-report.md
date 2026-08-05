# Dual A/B report — W27-F OWN `aa_004b18f0` + `aa_00626890`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-F  
**Scope:** VAs `0x004b18f0`, `0x00626890` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b18f0` ObjectMotion_SyncChildPoseHF_Inferred | **accept-with-gaps** — CF + ABI + HF/constants sealed; nested matrix English + basis triple runtime open |
| `aa_00626890` Object_ActivatePlayerEnqueueHB_Inferred | **accept-with-gaps** — CF + ABI + TFID sole-caller + HB chain sealed; product class + nested helper English open |

---

## VA `0x004b18f0` — sealed facts

1. **Body:** `0x004b18f0`–`0x004b1a56` (**358 B / `0x166`**; pad `CC` after `RET 4`).
2. **ABI:** **`__thiscall`** ECX = motion slot; stack `(flag)`; epilogue **`ret 4`** (`C2 04 00`); void.
3. **Entry:** `56 57 8B 7C 24 0C 85 FF 8B F1` — flag→EDI; this→ESI; early-out on flag==0.
4. **Exit:** `5F 5E C2 04 00`.
5. **Classification:** worker (4 callees).
6. **Callers (2):** `ObjectMotion_SlotTick_Inferred` (`FUN_004b4620`) @ `0x004b48f7`; `FUN_005bc120` @ `0x005bc335`.
7. **Callees:** `FUN_00973820`, `FUN_00973690`, `FUN_006a3db0`, `FUN_004cd220` (`CVOGMap_SampleHeightfieldY`).
8. **Data / constants (`read_memory`):**
   - imm `0x3f400000` = **0.75f**
   - `DAT_00aaa8f4` ≈ **0.04f** (`0AD7233D`)
   - `DAT_00afdef0` = `0xFF000000`
   - `DAT_00b03530/34/38` image static **0** (runtime OPEN)
9. **CF:** flag gate → matrix helpers on child `*(slot+8)+0x34` → copy `+0x10/+0x18/+0x2c` → HF Y → basis scale → add slot pos → Y+=0.04.
10. **Name:** `ObjectMotion_SyncChildPoseHF_Inferred` (Ghidra `FUN_004b18f0`).
11. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Nested `FUN_00973820` / `FUN_00973690` / `FUN_006a3db0` (not OWN).  
- Runtime basis triple at `DAT_00b03530` — open.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b18f0_ObjectMotion_SyncChildPoseHF_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b18f0_ObjectMotion_SyncChildPoseHF_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b18f0_FUN_004b18f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b18f0_FUN_004b18f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_SyncChildPoseHF_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b18f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004b18f0_FUN_004b18f0.md` |
| Function named | `docs/reconstruction/functions/aa_004b18f0_ObjectMotion_SyncChildPoseHF_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004b18f0.md` |

---

## VA `0x00626890` — sealed facts

1. **Body:** `0x00626890`–`0x00626a46` (**438 B / `0x1B6`**; pad `CC` after plain `RET`).
2. **ABI:** **thiscall** ECX = host (Ghidra surface `__fastcall`); MSVC SEH (`LAB_009a8b27`); plain **`RET`** (`C3`); void.
3. **Entry:** `6A FF 68 27 8B 9A 00 … 51 55 8B E9` (SEH + `mov ebp,ecx`).
4. **Exit:** `83 C4 10 C3`.
5. **Classification:** worker (vtable method).
6. **Callers:** **0 code xrefs**; DATA vtable `@ 0x009d1ba8` = `0x00626890`.
7. **Callees:** `FUN_0053d970`, `FUN_00578270`×2, vfunc `+0x210`, `FUN_004c4880` (`Object_SetTFID_ApplyPhysMode_Rebind`), `FUN_0051f890`, `Object_SetSelectedTarget`, `operator_new`, `FUN_006264e0`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, `FUN_00578b30`.
8. **CF stages:** related resolve → phys-type → player resolve → TFID rebind → flags/phys-sub → SetSelectedTarget → new HB `0x2c` → enqueue+Start → always fire-tail.
9. **Name:** `Object_ActivatePlayerEnqueueHB_Inferred` (Ghidra `FUN_00626890`).
10. **Decompile ≡ raw CF** (live 2026-07-29 ≡ 2026-07-23; surface renames + `unaff_ESI` residual).

### Gaps

- Product class / PDB method name (vtable-only).  
- Nested `FUN_006264e0` / `FUN_0051f890` / `FUN_00578270` English (not OWN).  
- `unaff_ESI` third arg; null-`pAction` surface residual.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00626890_Object_ActivatePlayerEnqueueHB_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00626890_Object_ActivatePlayerEnqueueHB_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00626890_FUN_00626890.md` |
| Annotated | `docs/reconstruction/raw/aa_00626890_FUN_00626890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ActivatePlayerEnqueueHB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00626890.cpp` |
| Function | `docs/reconstruction/functions/aa_00626890_FUN_00626890.md` |
| Function named | `docs/reconstruction/functions/aa_00626890_Object_ActivatePlayerEnqueueHB_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00626890.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b18f0` | After integrate / spawn, when flag≠0, sync **child** (`*(slot+8)`) pose — not the slot. Preserve **ret 4**, **0.75** helper arg, ≈**0.04** Y lift, HF sample on slot XZ. Do not invert flag gate. |
| `00626890` | Vtable activate: **TFID rebind before** HB Start; **always** `FUN_00578b30`. Preserve `operator_new(0x2c)` + `FUN_006264e0(host+0x24, player, host)` and store at `host+0x6c4` only when owner non-null. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b4620` | `ObjectMotion_SlotTick_Inferred` (W26-H) — primary caller of `004b18f0` |
| `0x004b1100` | `ObjectMotion_IntegrateStep_Inferred` (W24-C) — precedes `004b18f0` in SlotTick |
| `0x004cd220` | `CVOGMap_SampleHeightfieldY` |
| `0x004c4880` | `Object_SetTFID_ApplyPhysMode_Rebind` (W26-F) — sole-called by `00626890` |
| `0x0053d970` | `Object_SetPhysBodyTypeIfNotReady_Inferred` |
| `0x005172d0` | `Object_SetSelectedTarget` |
| `0x006264e0` | HB action ctor helper (0x2c) |
| `0x00578b30` | Skill HB fire-tail |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; structural `_Inferred` only.  
- Avoid bare `undefined4` in clean (use `uint32_t` / `uint8_t`).
