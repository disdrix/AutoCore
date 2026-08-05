# Dual A/B report — W20-P OWN-ONLY (`0x005995a0`, `0x004e15a0`)

**Date:** 2026-07-29  
**Agent:** W20-P OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005995a0`, `0x004e15a0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis / assembly context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005995a0` Host_ScreenToTerrainHitNotify_Inferred | **accept-with-gaps** — **CF + host offsets + maxSteps 400 + vtbl+0x5c sealed; product class residual** |
| `aa_004e15a0` CsSList_ContainsPayload_Inferred | **accept** — **dual-CS list contains + ret 4 + layout twin of Append sealed** |

---

## `aa_005995a0` — Host_ScreenToTerrainHitNotify_Inferred

### Sealed facts

1. **Body:** sealed **209** B to pad (exclusive end `0x00599671`); Ghidra meta `005995a0`–`00599670`. Final bare `c3`; following `cc` pad.

2. **ABI:** **ECX = host***; bare **`ret`**. Returns **0** (no map / no hit) or **1** (hit + notify).

3. **Host layout:** `+0x24` notify target*; `+0x38`/`+0x3c` screen int XY; `+0x40` `CVOGMap*`.

4. **Algorithm:** map null → 0; unproject screen via `*(map+0xe890)` (`FUN_0075c340`); pack origin/dir float4 with **w=0**; `FUN_004cff70(map, origin, dir, hit, 400)`; on hit call `*(host+0x24)->vtbl[+0x5c](hit)`; return 1 else 0.

5. **Callees:** `GfxView_UnprojectScreenToWorldRay_Inferred` (`0x0075c340`); `CVOGMap_MarchDirToTerrain_Inferred` (`0x004cff70`). Decompiler surface drops callee **this** — bytes restore.

6. **Callers:** no direct code CALL; **DATA** vtbl slot `@0x009d55bc` = `0x005995a0`.

7. **maxSteps:** imm **`0x190` (400)** — matches other MarchDir sites.

8. **Name:** structural `Host_ScreenToTerrainHitNotify_Inferred` (product class spelling residual).

### Gaps

1. Product host / notify-target class names; English for vtbl+0x5c.  
2. Hit buffer fields beyond MarchDir float4 (28 B stack residual).  
3. Owning type of vtbl region.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005995a0_FUN_005995a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ScreenToTerrainHitNotify_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005995a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.annotated.md` |

---

## `aa_004e15a0` — CsSList_ContainsPayload_Inferred

### Sealed facts

1. **Body:** sealed **89** B to pad (exclusive end `0x004e15f9`); Ghidra meta `004e15a0`–`004e15f8`. Final `c2 04 00`; following `cc` pad.

2. **ABI:** **ECX = list***; stack **payload***; **`ret 4`**. AL **0** miss / **1** hit.

3. **Layout (twin of Append):** head `@list+4`; CS `@+0x10` and `@+0x28`; node payload `@+4`, next `@+8`.

4. **Algorithm:** Enter outer CS (`+0x28`) then inner (`+0x10`) **always** (no count gate); walk head for payload match; leave reverse order; return bool. No allocate/mutate.

5. **Callees:** `EnterCriticalSection` / `LeaveCriticalSection` (IAT `@0x009c61bc` / `@0x009c61b8`).

6. **Callers (2):**  
   - `Object_EnqueueDeferredOnce` (`0x004d0e90` @ `004d0ea8`) — queue `*(host+0xe5fc)`  
   - `Object_QueueDelete` (`0x004d4790` @ `004d4840`) — queue `*(host+0xe648)`

7. **Distinct from** Append (`0x004024d0`) — membership only; always dual CS vs Append’s gated outer.

8. **Name:** `CsSList_ContainsPayload_Inferred` (product spelling residual).

### Gaps

1. Product/PDB symbol spelling.  
2. Why Contains always takes outer CS while Append gates on `count≤3`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004e15a0_FUN_004e15a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CsSList_ContainsPayload_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e15a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Host_ScreenToTerrainHitNotify (`0x005995a0`)

- Client-side **screen → terrain hit → notify** path; not sector physics.
- Preserve **map** this for MarchDir and **gfxView** this from `map+0xe890` for Unproject — do not trust decompiler surface alone.
- maxSteps **400** shared with DCT / click-pick MarchDir sites.
- Notify is **virtual** on `*(host+0x24)` at vtbl **+0x5c**; do not invent free-function callbacks.
- Distinct unit from DriveControlTick / InteractClickPick (shared callees only).

### CsSList_ContainsPayload (`0x004e15a0`)

- Port as **list membership** on the CS list object (ECX), not a host-embedded search.
- Layout must match Append: head+4, payload node+4, next+8, dual CS.
- **Always** enter outer CS (`+0x28`) — do not copy Append’s `count≤3` gate.
- Callers use different host queue fields (`+0xe5fc` deferred vs `+0xe648` delete path).
- `ret 4`; return AL 0/1 only.

---

## This report

`docs/agents/task-dual-ab-005995a0-004e15a0-w20p-report.md`
