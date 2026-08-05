# Review A (reconstruction fidelity): `aa_00561320` PhysSim_FlushPendingBodyPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561320` |
| **VA** | `0x00561320` |
| **Body** | `0x00561320`–`0x00561360` (excl. `0x00561361`) |
| **Canonical name** | `PhysSim_FlushPendingBodyPairs_Inferred` |
| **Prior / alias** | `FUN_00561320`; parent-seed `Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_00561320` (**misleading sole role**) |
| **Review date** | `2026-07-29` (W19-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| **System** | physics / island pair glue |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Flush pending cross-host body pairs** queued on the world/sim object.

1. Iterate `i = 0 .. count-1` over pair vector at **`this+0x20`** (element size **8**: `bodyA*`, `bodyB*`), count at **`this+0x24`**.
2. For each pair, load **`body+0x44`** (host pointers) for both bodies.
3. If hosts differ, **`FUN_00560a30(world, hostA, hostB)`** — host/island merge (activate, splice lists, destroy merged host).
4. **Always** set **`this+0x24 = 0`** (drain count; data buffer retained).

Producer: **`PhysSim_PushBodyPair_Inferred`** (`0x0055efd0`). Island step (`FUN_00561910`) calls this when `+0x24 > 0` at multiple points in the step.

Not an action-list push, not pair enqueue, not host activate alone.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00561320_FUN_00561320.md` |
| Annotated | `docs/reconstruction/raw/aa_00561320_FUN_00561320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_FlushPendingBodyPairs_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00561320.cpp` |
| Function record | `docs/reconstruction/functions/aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| Live decompile | Ghidra @ `0x00561320` ≡ raw |
| Bytes | `8b f1` this in ESI; loop; `e8 …` → `00560a30`; `c7462400000000; 5e c3` |
| Producer dual | `aa_0055efd0` PhysSim_PushBodyPair_Inferred |
| Callee decompile | `FUN_00560a30` (host merge — context only) |
| Verified island step | `physics/verified/fn_00561910_islandStep.md` |

---

## 3. Byte / ABI seal

```
56 57 8b f1 33 ff     push esi/edi; mov esi,ecx; xor edi,edi
39 7e 24 7e …         cmp [esi+0x24], edi; jle skip
… i*8 pair loads …
8b 49 44 / 8b 42 44   host = body+0x44
3b c8 74 09           if hostA == hostB skip merge
50 51 8b ce e8 …      push hostB; push hostA; mov ecx,esi; call 00560a30
…
c7 46 24 00 00 00 00  *[esi+0x24] = 0
5e c3                 pop esi; ret
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = world/sim; **0 stack args**; bare **`ret`** | `mov esi,ecx`; epilogue `c3` | **Confirmed** |
| Pair data `+0x20`, count `+0x24` | loads / store | **Confirmed** |
| Element stride **8** | `i*8` / `+4` second ptr | **Confirmed** |
| Host field **body+0x44** | `+0x44` loads | **Confirmed** |
| Merge only if hosts unequal | `je` skip | **Confirmed** |
| `00560a30` is thiscall with **ECX=world** | `mov ecx,esi` before call | **Confirmed** (decomp omits this) |
| Count cleared unconditionally | store 0 after loop | **Confirmed** |
| Role = drain of PushBodyPair queue | producer dual + island step | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early path when count ≤ 0 | Yes (still clears count) |
| Loop pairs | Yes |
| Host compare | Yes |
| Conditional merge | Yes |
| Clear count | Yes |
| Bare ret | Yes |

### Recovered CF

```c
// void __thiscall PhysSim_FlushPendingBodyPairs(World *world)
void PhysSim_FlushPendingBodyPairs_Inferred(void *world)
{
  int i = 0;
  if (*(int *)((char *)world + 0x24) > 0) {
    do {
      void **pair = (void **)(*(char **)((char *)world + 0x20) + i * 8);
      void *hostA = *(void **)((char *)pair[0] + 0x44);
      void *hostB = *(void **)((char *)pair[1] + 0x44);
      if (hostA != hostB)
        FUN_00560a30(world, hostA, hostB); // thiscall ECX=world
      i++;
    } while (i < *(int *)((char *)world + 0x24));
  }
  *(int *)((char *)world + 0x24) = 0;
}
```

---

## 5. Callers / callees

| Direction | Target | Notes |
|---|---|---|
| **Callee** | `FUN_00560a30` | host merge; conditional |
| **Callers** | `FUN_00561450`, `FUN_005614f0`, `FUN_00561910` (×3 sites), `FUN_00561b60`, `FUN_00562680` | island step + remove/defer family |

Island step verified doc: flush when `island+0x24 > 0` before sub-island work, after post-collide, and after deferred deletes.

---

## 6. Gaps / open

1. Product / PDB symbol for flush API.
2. Full dual of `FUN_00560a30` merge semantics (only sealed as callee here).
3. Whether `body+0x44` English is “island”, “sim host”, or “group” — structural host pointer sealed.
4. Capacity field `+0x28` unused here (grow is producer-side).
5. Runtime / bit-exact / differential — open.

**Verdict:** CF + ABI + pair layout + host compare + clear sealed. Merge body product English open. **accept-with-gaps.**
