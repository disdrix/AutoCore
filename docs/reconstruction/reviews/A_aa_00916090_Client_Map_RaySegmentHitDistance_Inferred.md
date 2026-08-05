# Review A (reconstruction fidelity): `aa_00916090` Client_Map_RaySegmentHitDistance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916090` |
| **VA** | `0x00916090` |
| **Body span** | `00916090` – `00916225` (**405** bytes; `ret 0x18` @ `00916223`) |
| **Canonical name (Ghidra)** | `FUN_00916090` |
| **Proposed name** | `Client_Map_RaySegmentHitDistance_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090` — **too narrow** |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W23-O) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |
| **System** | client camera / map collision query |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client helper: **cast a world segment through the map collision context and return the distance from the start point to the hit**, or **0** if the cast misses. Optionally publishes the hit token via **ESI**.

```
distance = hit ? |lerp(start, end, t) - start| : 0
```

Uses the **same** map collision wrapper path as `CVOGMap_CastTerrainHeight` (`FUN_0055e530` with `this = *(map+0xe4a4)`), but with a **general start→end segment** and filter **7** (not the vertical terrain 5/18 recipe).

**Calling convention:** MSVC **stdcall** — six stack `float`s, **`ret 0x18`**, return in **x87 ST0**. Optional **ESI** = `int* hitOut`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00916090_FUN_00916090.md` |
| Annotated | `docs/reconstruction/raw/aa_00916090_FUN_00916090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00916090.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Map_RaySegmentHitDistance_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |
| Cast peer | `docs/reconstruction/physics/verified/fn_004cfe60_castTerrain.md` |
| Copy sibling | `Math_CopyFloat3ToFloat4_Inferred` @ `0x004e9530` |

**This pass (live):** `decompile_function` @ `0x00916090` + `0x0055e530` + `0x004e9530`; callers `0x009168d0` / `0x0091b1c0`; `get_function_by_address` / callers / xrefs; `read_memory` entry, cast site (`mov ecx,[edx+0xe4a4]; call 0055e530`), epilogue, constants. **Not performed:** Launcher, runtime, bit-exact, ledgers. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 0x18` | **High** | epilogue bytes `C2 18 00` |
| Six float stack args (start+end XYZ) | **High** | decompile + `RET 0x18` |
| ST0 float return | **High** | `fld g_flZero` miss; `SQRT` hit |
| Optional ESI hitOut | **High** | `test esi` / `mov [esi],eax` / store 0 |
| `DAT_00d1b644` = client map object | **High** | entry `mov edx,[00d1b644]`; same global in camera callers |
| Cast this = `*(map+0xe4a4)` | **Confirmed** | `8B 8A A4 E4 00 00` then `call 0055e530` |
| Filter constant **7** | **High** | `local_4c = 7` / store imm |
| Hit fraction init 1.0 / token 0 | **High** | `g_flOne` + zero dword |
| Hit path: lerp then \|Δ\| from start | **High** | decompile CF + `004e9530` copy |
| Miss path: 0.0 + clear ESI | **High** | |
| `FUN_0055e530` role (map cast wrapper) | **High** | peer verified note + decompile → `006cad80` |
| Product method name | **Tentative** | `_Inferred` |
| Filter-7 English | Open | differ from terrain 5/18 |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Pack ray start/end + filter 7 + t=1 + hit=0 | **Yes** |
| Load map; cast via `0055e530` | **Yes** (ECX from bytes) |
| Hit: optional ESI store; lerp; distance | **Yes** |
| Miss: optional ESI=0; return 0 | **Yes** |
| No invented normalize of segment dir | **Yes** |

### 4.1 Sealed contract

```
// stdcall RET 0x18; ST0 out; ESI optional int* hitOut
float Client_Map_RaySegmentHitDistance_Inferred(
    float sx, float sy, float sz,
    float ex, float ey, float ez);

// map = DAT_00d1b644; ctx = *(map+0xe4a4); filter=7
// on hit: *hitOut=token (if ESI); return length(lerp(start,end,t) - start)
// on miss: *hitOut=0 (if ESI); return 0
```

### 4.2 Caller samples

| Caller | Segment shape |
|---|---|
| `FUN_0091b1c0` | `(p1, p2+ε, p3) → (p1, p2, p3)` near-vertical camera ground probe |
| `FUN_009168d0` | multi-direction probes from camera look math (8× loop) |

---

## 5. Callers / callees (live)

**Callers (2):**

| VA | Function | Site |
|---|---|---|
| `0x009168d0` | `FUN_009168d0` | `0x00916e3d` |
| `0x0091b1c0` | `FUN_0091b1c0` | `0x0091b6bd` |

**Callees:**

| VA | Role |
|---|---|
| `0x0055e530` | map collision cast wrapper |
| `0x004e9530` | float3→float4 copy of start |

---

## 6. Gaps

1. Product / PDB camera method name.
2. Collision filter **7** English meaning.
3. Full cast result blob layout (`local_40`).
4. Null-map safety if `DAT_00d1b644 == 0`.
5. Runtime / bit-exact / diff open.

**Verdict:** **accept-with-gaps** — ABI, map cast wiring, filter, and distance CF sealed; keep `_Inferred`.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile matches raw/clean CF | **Pass** |
| `ret 0x18` + ESI out via `read_memory` | **Pass** |
| `map+0xe4a4` → `0055e530` sealed | **Pass** |
| VOG_DEBUG_STOP-only name rejected | **Pass** |
| Product name without `_Inferred` | **Fail** (expected) |
| Verdict | **accept-with-gaps** |
