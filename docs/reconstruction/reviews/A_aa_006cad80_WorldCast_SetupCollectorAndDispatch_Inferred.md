# Review A (reconstruction fidelity): `aa_006cad80` WorldCast_SetupCollectorAndDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad80` |
| **VA** | `0x006cad80` |
| **Body** | `0x006cad80`–`0x006cae18` (excl. `0x006cae19`) |
| **Canonical name** | `WorldCast_SetupCollectorAndDispatch_Inferred` |
| **Prior / alias** | `FUN_006cad80`; parent-seed `Named_CalleeOf_Named_CalleeOf_CVOGMap_CastTerrainHeight_006cad80` |
| **Review date** | `2026-07-29` (W19-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| **System** | world / map collision cast |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Collector setup + world cast dispatch.** Fills a cast-collector (`this`) from ray / optional filter / result, builds a stack ray packet (16-byte ray head copy + flags + mid pointer + extra), then invokes:

```
(*world->vtbl[0x30/4])(world /*ECX*/, &packet, collector, /*zero*/0);
```

Sole CODE caller: **`MapCollisionCtx_CastRay`** (`FUN_0055e530`) — which itself is used by map terrain height (`CVOGMap_CastTerrainHeight`). Not the vehicle phantom cast path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.md` |
| Annotated | `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldCast_SetupCollectorAndDispatch_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_006cad80.cpp` |
| Function record | `docs/reconstruction/functions/aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| Live decompile | Ghidra @ `0x006cad80` ≡ raw |
| Bytes | epilogue `c2 14 00`; vcall `ff 52 30`; ray flag `8a 50 20` |
| Parent dual | `aa_0055e530` MapCollisionCtx_CastRay |
| Verified parent | `physics/verified/fn_004cfe60_castTerrain.md` |

---

## 3. Byte / ABI seal

```
prologue: 55 8b ec 83 e4 f0 83 ec 2c   ; ebp frame, 16-align, sub esp,0x2c
...
epilogue: 5e 8b e5 5d c2 14 00         ; pop esi; mov esp,ebp; pop ebp; ret 0x14
pad:      cc…
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = collector | stores via `[ecx+…]`; call sites pass stack collector as this | **High** |
| 5 stack args; **`ret 0x14`** | `c2 14 00` | **Confirmed** |
| Args = world, ray, filter, extra, result | parent wrapper + stack `[ebp+8..+18]` | **High** |
| Collector `+4/+8/+c/+34` map | decompile ≡ stores in body | **High** |
| Ray flag at **byte +0x20** | `mov dl,[eax+0x20]` (decomp `param_3+8` as dword*) | **Confirmed** |
| Filter offsets `+0x14` / `+0x10` | `lea edx,[esi+14h]` / `lea edx,[esi+10h]` | **Confirmed** |
| Dispatch `vtbl+0x30` with packet, collector, 0 | `call [edx+0x30]`; pushes | **Confirmed** |
| Sole CODE xref `0055e530` | `get_function_xrefs` | **High** |
| Not phantom cast | different VA / parent verified contrast | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Store ray / result on collector | Yes |
| Null-safe filter → `+8` / `+0x34` | Yes |
| Pack 4 dwords + flags + mid ptr + extra | Yes |
| World vcall +0x30 | Yes |
| `ret 0x14` | Yes |

### Recovered CF

```c
// void __thiscall WorldCast_SetupCollectorAndDispatch(
//   Collector* this, World* world, Ray* ray, void* filter, uint32 extra, void* result)
// RET 0x14
this->ray = ray;            // +4
this->result = result;      // +0xc
this->filterOfs14 = filter ? filter+0x14 : 0;  // +8
this->filterOfs10 = (ray->flag_at_0x20 && filter) ? filter+0x10 : 0; // +0x34
Packet p = { ray[0..3], 1, &ray[4], 0x10, extra };
world->vtbl.castAt30(&p, this, 0);
```

---

## 5. Callers / callees

| Direction | Target | Notes |
|---|---|---|
| **Caller** | `MapCollisionCtx_CastRay` `0x0055e530` | sole UNCONDITIONAL_CALL |
| **Callee** | `world->vtbl[+0x30]` | indirect; product English open |
| **Not callee** | CRT / grow helpers | none |

---

## 6. Gaps / open

1. Product / PDB symbols for Collector, World cast vfunc, ray/result POD.
2. Exact semantics of filter `+0x10` / `+0x14` (shape / material filter slices).
3. Ray field English for dwords[0..3] and flag at +0x20 (start/end vs origin/dir).
4. Implementation behind vtbl+0x30 (other dual).
5. Runtime / bit-exact / differential — open.

**Verdict:** CF + ABI + collector map + dispatch sealed. Product English open. **accept-with-gaps.**
