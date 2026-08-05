# Dual A/B report — W19-M OWN-ONLY (`0x006cad80`, `0x00561320`)

**Date:** 2026-07-29  
**Agent:** W19-M OWN-ONLY  
**Scope:** OWN ONLY VAs `0x006cad80`, `0x00561320`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_006cad80` WorldCast_SetupCollectorAndDispatch_Inferred | **accept-with-gaps** — **thiscall+ret14h collector setup + world vtbl+0x30 dispatch sealed; product English open** |
| `aa_00561320` PhysSim_FlushPendingBodyPairs_Inferred | **accept-with-gaps** — **pair drain/host compare/merge call+count clear sealed; merge body dual open** |

---

## `aa_006cad80` — WorldCast_SetupCollectorAndDispatch_Inferred

### Sealed facts

1. **ABI:** `void __thiscall Setup(Collector* this, World* world, Ray* ray, void* filter, uint32 extra, void* result)` — **ECX=collector**, **5 stack args**, epilogue **`ret 0x14`**. Body `0x006cad80`–`0x006cae18`.

2. **Collector map:** `+4` ray*; `+8` = filter? filter+0x14 : 0; `+0xc` result*; `+0x34` = (ray byte +0x20 && filter)? filter+0x10 : 0.

3. **Ray packet:** copy ray dwords[0..3]; flag `1`; mid ptr `ray+0x10`; const `0x10`; `extra`.

4. **Dispatch:** `(*world->vtbl[+0x30])(world /*ECX*/, packet, collector, 0)` — `call [edx+0x30]`.

5. **Ray flag offset:** byte **`ray+0x20`** (`8a 50 20`); decompiler `param_3+8` as `undefined4*` is correct dword math.

6. **Callees:** indirect world cast only. **Callers:** sole CODE `MapCollisionCtx_CastRay` `0x0055e530`.

7. **Not** `TtPhantom::castRay` `0x00580ed0`.

8. **Name:** structural `WorldCast_SetupCollectorAndDispatch_Inferred`. Parent-seed CastTerrain-only name **narrow**.

### Gaps

1. Product/PDB symbol.  
2. Filter +0x10/+0x14 English; full ray/result POD.  
3. World cast vfunc body.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldCast_SetupCollectorAndDispatch_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_006cad80.cpp` |
| Raw | `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.md` |
| Annotated | `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.annotated.md` |

---

## `aa_00561320` — PhysSim_FlushPendingBodyPairs_Inferred

### Sealed facts

1. **ABI:** `void __thiscall Flush(World* this)` — **ECX=world**, **0 stack args**, bare **`ret` (`c3`)**. Body `0x00561320`–`0x00561360`.

2. **Pair vector:** data `this+0x20`, count `this+0x24`, element **8 bytes** `(bodyA*, bodyB*)` — matches producer `PhysSim_PushBodyPair_Inferred`.

3. **Loop:** for each pair load `body+0x44` hosts; if unequal call **`FUN_00560a30`**.

4. **Merge call ABI (bytes fix decomp):** `push hostB; push hostA; mov ecx, world; call 00560a30`.

5. **Always** `*(this+0x24) = 0` after loop (buffer not freed).

6. **Callee:** `FUN_00560a30` host merge only. **Callers:** `00561450`, `005614f0`, `00561910`×3, `00561b60`, `00562680`.

7. **Name:** structural `PhysSim_FlushPendingBodyPairs_Inferred`. Parent-seed SetObjectActiveState name **misleading**.

### Gaps

1. Product/PDB symbol.  
2. Full dual of `FUN_00560a30` merge.  
3. Host English (island vs sim-host) — pointer identity sealed.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_FlushPendingBodyPairs_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00561320.cpp` |
| Raw | `docs/reconstruction/raw/aa_00561320_FUN_00561320.md` |
| Annotated | `docs/reconstruction/raw/aa_00561320_FUN_00561320.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### WorldCast (`0x006cad80`)

- Port as **collector fill + world vtbl cast**, not a free-standing 5-arg C function with world as first stack arg alone.
- Preserve **null filter** and **ray+0x20** gated shape ofs at `+0x34`.
- Map terrain height stays on **MapCollisionCtx_CastRay → this**; do not route through phantom cast.

### FlushPendingBodyPairs (`0x00561320`)

- Port as **drain** of the pair vector produced by PushBodyPair; clear count only.
- Merge is **`HostMerge(world, hostA, hostB)`** when hosts differ — must pass **world as this**.
- Island step may call flush multiple times per tick when `+0x24 > 0`.

---

## Report path

`docs/agents/task-dual-ab-006cad80-00561320-w19m-report.md`
