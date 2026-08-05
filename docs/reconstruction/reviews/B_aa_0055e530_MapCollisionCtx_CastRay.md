# Review B (skeptical / adversarial): `aa_0055e530` MapCollisionCtx_CastRay

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e530` |
| **VA** | `0x0055e530` |
| **Canonical name** | `MapCollisionCtx_CastRay` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0055e530_MapCollisionCtx_CastRay.md` |
| **System** | world / terrain collision |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** `CVOGMap_CastTerrainHeight` | Parent samples HF + builds ray; this only dispatches cast | **Falsified** |
| 2 | This is vehicle wheel `TtPhantom::castRay` | Different VA `0x00580ed0`; verified contrast | **Falsified** |
| 3 | Decompiler one-liner is complete | Bytes construct stack object + vtbl before `6cad80` | **Overstated** decompiler |
| 4 | `ret` without stdcall cleanup | **`C2 08 00`** ret 8 | **Falsified** bare-ret |
| 5 | `this` is `CVOGMap*` | Parent loads `*(map+0xE4A4)` into ECX | **Falsified** map-as-this |
| 6 | Zero stack args | Two stack pointers (ray, result) | **Falsified** |
| 7 | Exclusive to CastTerrainHeight | 3 xrefs including client helpers | **Falsified** exclusive |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 / two args | **Confirmed** | Stack imbalance |
| ctx+0xC4 / +0xD0 wiring | **Confirmed** | Cast into null/wrong world |
| Role = map collision cast wrapper | **High** | Mis-wire as HF sample |
| Collector vtbl identity product | **Open** | Naming / type registry only |
| Ray POD English fields | **Tentative** (parent) | Wrong pack → silent miss |

---

## 3. Cross-check against raw / live / bytes

```
read_memory @ 0x0055e530:
  mov eax,[ebp+0xc]          ; result
  mov edx,[ecx+0xd0]
  mov ecx,[ecx+0xc4]
  push result; push 0; push edx; push ray; push world
  lea ecx,[esp+0x14]
  mov [esp+0x14], 0x009d27d4 ; collector vtbl
  call FUN_006cad80
  mov esp,ebp; pop ebp; ret 8
```

Parent `fn_004cfe60_castTerrain.md` already sealed:

```
ctx = *(map + 0xE4A4)
FUN_0055e530(ctx, &ray, &result)
```

### Traps

- **Do not** call with `ECX = CVOGMap*` — need collision context.
- **Do not** skip packing ray start/end/filter that parent prepares; this wrapper does not build the ray.
- Decompiler of `55e530` omits stack collector — ports must still match `6cad80` thiscall shape or call a higher-level API.

---

## 4. Surviving contract for AutoCore

```
MapCollisionCtx_CastRay(ctx, ray, result) -> void   // thiscall, ret 8
  // ctx from map+0xE4A4
  // uses ctx+0xC4 world vtbl cast @ +0x30 via FUN_006cad80
  // hardcoded shape arg 0
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| Wrapper ABI / offsets / dispatch | **Sealed Confirmed** |
| Parent terrain height algorithm | Sealed in verified parent doc |
| Collector / world type product names | Open |
| Runtime | Open |

**Verdict:** accept-with-gaps. Safe to call from map height / client cast ports as **context cast wrapper only**.
