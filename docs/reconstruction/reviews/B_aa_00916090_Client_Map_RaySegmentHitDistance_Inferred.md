# Review B (skeptical / adversarial): `aa_00916090` Client_Map_RaySegmentHitDistance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916090` |
| **VA** | `0x00916090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is VOG_DEBUG_STOP–only | Second caller `FUN_009168d0` multi-probe camera path | **Falsified** — shared camera/map helper |
| 2 | Returns hit **fraction** not distance | CF does lerp then SQRT of delta from start | **Falsified if fraction claimed** — returns **length** |
| 3 | Same as `CVOGMap_CastTerrainHeight` | Terrain is vertical HF+cast Y recipe with filter 5/18 | **Distinct** — general segment, filter **7**, returns distance not Y |
| 4 | cdecl / thiscall on map | Epilogue `C2 18 00`; ECX loaded only for cast callee | **Falsified** — **stdcall** free function; map via global |
| 5 | Decompiler `FUN_0055e530(&ray,res)` is complete ABI | Bytes load ECX from `map+0xe4a4` | **Decompiler incomplete** — sealed by `read_memory` |
| 6 | `unaff_ESI` is noise | Explicit `test esi` / stores on both hit and miss | **Real optional out-param** |
| 7 | Always hits / never returns 0 | Miss path `fld g_flZero` + clear ESI | **Miss sealed** |
| 8 | Product name recovered | No body string | **False** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall 6-float / ST0 / ESI | **Confirmed** | ABI break in ports |
| Map ctx cast path | **High** | Wrong collision world |
| Distance = \|hit−start\| | **High** | Camera push-out wrong scale |
| Filter=7 literal | **High** | Wrong collision layer |
| Filter English | Open | Mis-doc only |
| Result blob fields | Partial | Advanced hit normal ports |
| Product name | Tentative | Cosmetic |

---

## 3. Surviving contract

```
// stdcall RET 0x18
// ESI: optional int *hitOut (0 if miss / null ESI ignored)
// ST0: float distance
float Client_Map_RaySegmentHitDistance_Inferred(
    float sx, float sy, float sz,
    float ex, float ey, float ez)
{
  // pack ray; filter=7; t=1; hit=0
  // FUN_0055e530(*(DAT_00d1b644 + 0xe4a4), &ray, &result);
  // hit ? (*hitOut=hit, return length(lerp(start,end,t)-start))
  //     : (*hitOut=0, return 0);
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product / camera class method name | No |
| R2 | Filter 7 English | No |
| R3 | Full result struct | No (token + fraction enough for distance) |
| R4 | Null map | Mild (retail assumes map live in camera paths) |
| R5 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x00916090` — matches scaffold raw CF.
2. `read_memory` entry: `DAT_00d1b644` load; stack frame `sub esp,0x80`.
3. `read_memory` cast site: `mov ecx,[edx+0xe4a4]; call 0055e530; test hit; ESI stores`.
4. `read_memory` epilogue: miss zero + `fld g_flZero` + `ret 0x18`.
5. Constants: `g_flOne=1.0`, `g_flZero=0.0`.
6. Callers: two camera-side functions; reject VOG_DEBUG-only name.
7. Peer `fn_004cfe60_castTerrain.md` confirms `0055e530` / `+0xe4a4` meaning.

---

## 6. Falsifications locked in

- **Reject** `Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090` as primary role name.
- **Reject** reading return as hit fraction or terrain Y.
- **Reject** treating decompiler two-arg `0055e530` as complete without ECX ctx.
- **Reject** claiming this is Havok wheel `TtPhantom::castRay` (different entry `0x580ed0`).

---

## 7. Verdict

**accept-with-gaps** — segment cast → distance ABI, map wiring, filter literal, and hit/miss CF sealed High/Confirmed. Keep `Client_Map_RaySegmentHitDistance_Inferred`. Residual: product name, filter English, result-blob layout, runtime/diff.
