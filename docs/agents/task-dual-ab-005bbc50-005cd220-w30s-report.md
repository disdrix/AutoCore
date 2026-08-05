# Dual A/B report — W30-S OWN-ONLY (`0x005bbc50`, `0x005cd220`)

**Date:** 2026-07-29  
**Agent:** W30-S OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005bbc50`, `0x005cd220`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005bbc50` ObjectMotion_HostTeardown_Inferred | **accept-with-gaps** — host buffer free + `+0xa24` slot freelist walk + list/sentinel free; Ghidra noreturn truncation residual |
| `aa_005cd220` CVOGHBAICreatureBase_PathlessIdleRoam_Inferred | **accept-with-gaps** — pathless idle roam (cooldown + 1/3 + local offset); product field English residual |

---

## `aa_005bbc50` — ObjectMotion_HostTeardown_Inferred

### Sealed facts

1. **Body:** Ghidra `0x005bbc50`–`0x005bbd96` exclusive (**326** B / `0x146`). `operator_delete` marked noreturn → listed end truncates; `read_memory` shows SEH tail ending **`c3`** ≈ `0x005bbdc0` + `cc` pad.

2. **ABI:** `__thiscall` ECX=host; no stack args; plain **`ret`**; void.

3. **Caller (1):** `FUN_005be310` @ `0x005be310` (W30-R OWN) — calls this then optional freelist push of host.

4. **Stages (CF):**
   ```
   SEH prolog
   FUN_005b8340 + free primary heap buffer if +0x308 ≠ inline +0x14
   if +0x7fc: same for secondary +0x6ec / inline +0x3f8
   walk list +0xa24:
     ObjectMotion_SlotReleaseToFreelist(DAT_00b036c0, node[2])
   empty list nodes; free sentinel; host+0xa24=0; count+0xa28=0
   SEH epilog; ret
   ```

5. **Slot freelist site bytes:** `50 B9 C0 36 B0 00 E8 …` — push payload; **`mov ecx, 0x00B036C0`**; call `FUN_005be2b0` (W28-I sealed).

6. **Name:** `ObjectMotion_HostTeardown_Inferred`. Reject missileExplosion scaffold chain.

### Gaps

1. Product/PDB English.  
2. Exact `FUN_005b8340` ECX buffer headers (not OWN).  
3. Decompiler list-free vs bytes free-loop.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005bbc50_FUN_005bbc50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_HostTeardown_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005bbc50.cpp` |
| Raw | `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.md` |
| Annotated | `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.annotated.md` |

---

## `aa_005cd220` — CVOGHBAICreatureBase_PathlessIdleRoam_Inferred

### Sealed facts

1. **Body:** `0x005cd220`–`0x005cd3ad` exclusive (**397** B / `0x18D`). Final **`c3`** (`ret`); following `cc` pad.

2. **ABI:** `__thiscall` ECX=AI self; no stack args; plain **`ret`**; uint return **ignored** by caller.

3. **Caller (2 sites):** `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0310` — xrefs `0x005d0667`, `0x005d0769`.

4. **Stages (CF):**
   ```
   if owner+0x279 == 0: return
   if !(AI[0x1d] < g_dwClientTickMs - AI[0x1c]): return
   AI[0x1e] = 1
   u = rand_u16; if u % 3 != 0: return
   r = table+0x4d4; if r < 3.0f: r += 3.0f
   off.x = u16 * r * 2.0f * (~1/65536) - r
   off.y = 0
   off.z = u16 * r * 2.0f * (~1/65536) - r
   quat = FUN_0053e0b0; pack vtbl+0x1a4; Math_QuatTransformPoint; AI vtbl+0x4c(dest, 0)
   ```

5. **Constants (`read_memory`):**

   | VA | Bytes | Value | Role |
   |---|---|---|---|
   | `0x00a1330c` | `00 00 40 40` | **3.0f** | radius floor-add (symbol misnomer) |
   | `0x00a10e74` | `00 00 00 40` | **2.0f** | scale (misnamed `g_flLevelUpUiBase_Inferred`) |
   | `0x00aaa638` | `80 00 80 37` | **≈1.525902e-5** | ~1/65536 |
   | `0x00b041cc` | — | `g_dwClientTickMs` | cooldown |

6. **Name:** `CVOGHBAICreatureBase_PathlessIdleRoam_Inferred`. Aligns with `docs/NPC.md` pathless idle roam.

### Gaps

1. Product/PDB English for radius/flags.  
2. Exact multi-inherit ECX for object vtbl+0x1a4.  
3. Nested helpers not OWN.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005cd220_FUN_005cd220.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005cd220.cpp` |
| Raw | `docs/reconstruction/raw/aa_005cd220_FUN_005cd220.md` |
| Annotated | `docs/reconstruction/raw/aa_005cd220_FUN_005cd220.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### ObjectMotion_HostTeardown_Inferred (`0x005bbc50`)

- Port as **host content teardown** called from `FUN_005be310` before optional host freelist push — not a tick, not slot tick.
- Preserve freelist release of **payloads** via global `DAT_00b036c0`; do not `operator_delete` slots here.
- SSO-or-heap: free only when heap pointer ≠ inline storage (`+0x14` / `+0x3f8`).
- Do not trust Ghidra “noreturn” on `operator_delete` for control end.

### CVOGHBAICreatureBase_PathlessIdleRoam_Inferred (`0x005cd220`)

- Fills Ambient **pathless idle roam** gap (`docs/NPC.md`): random local destination, not player seek.
- Preserve gates (owner `+0x279`, cooldown, 1/3) — most heartbeats no-op.
- Radius floor-add is **+3.0 when r < 3**, not clamp-to-3.
- Ignore Ghidra names `g_flLevelUpUiBase_Inferred` / `g_flVehicleHpTechCoeff` semantics; use values **2.0f** / **3.0f**.
- Distinct from terrain helper `FUN_004cd220` (`CVOGMap_SampleHeightfieldY`).

---

## Related non-OWN VAs (reference only)

| VA | Role |
|---|---|
| `0x005be310` | W30-R — teardown wrapper caller |
| `0x005be2b0` | W28-I — `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| `0x004b0bd0` | W30-R — empty dtor stub |
| `0x005d0310` | `CVOGHBAICreatureBase_OnHeartBeat` |
| `0x004e8bf0` | `Math_QuatTransformPoint_Inferred` |
| `0x005b8340` | buffer/list clear helper |
| `0x004cd220` | **different** heightfield sample |

---

## Tools used

- Ghidra HTTP `http://127.0.0.1:8089`: `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_callees`, `get_function_xrefs`, `force_decompile` (bbc50 only)
- **No** `disassemble_bytes`, **no** Launcher, **no** parent ledger edits
