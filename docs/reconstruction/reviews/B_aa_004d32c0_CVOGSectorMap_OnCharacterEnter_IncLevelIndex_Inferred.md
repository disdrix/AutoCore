# Review B (skeptical / adversarial): `aa_004d32c0` CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d32c0` |
| **VA** | `0x004d32c0` |
| **Canonical name** | `CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d32c0_CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred.md` |
| **System** | sector-map / combat-pool level index |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is equip-slot / inventory mutator | Body only touches `+0xe818` / `+0xe81c` + optional `004d28c0` | **Falsified** equip role |
| 2 | Always notifies pool rescale | Gated by `param_3` / `cmp [esp+0xc],0` | **Falsified** always |
| 3 | Identical to leave twin `004d3310` | Twin is **decrement**; this is **increment**; notify (old,new) order differs | **Falsified** identity |
| 4 | Pushes character into `+0xe75c` vector | Vector push is `004d35c0` AddCharacter; this only adjusts counters | **Falsified** push role |
| 5 | Race from raw `param_2+0x532` | Dual-base walk required; bytes match leave twin | **Agree** walk required |
| 6 | `__cdecl` / static (no this) | `mov esi,ecx` + `ret 8` thiscall | **Falsified** static-only |
| 7 | Notify args are (new, old) | Push order: new first, then old-after-dec → stack (old,new) for thiscall callee | **Survives** as (old,new) |
| 8 | Product name sealed | Structural / `_Inferred` only | **Open** |
| 9 | Runtime / bit-exact verified | Static body only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0xe818 += 1` then optional notify | **Confirmed** | Wrong pool rescale timing |
| Race hist `+0xe81c[race]++` | **Confirmed** | Race census drift |
| `ret 8` thiscall | **Confirmed** | Stack imbalance |
| Dual-base `+0x532` race | **Confirmed** | Wrong hist bucket |
| Enter-path (not leave) | **Confirmed** | Port would invert census |
| Product English of index field | **Open** | Docs only |
| RecvCreateCharacter notify flag meaning | **Tentative** | May over/under-rescale |

---

## 3. Live ≡ raw

```
Live decompile 0x004d32c0 ≡ raw scaffold:
  [this+0xe818]++
  if flag: call 004d28c0(old=new-1, new)
  race = def+0x532 via dual-base
  [this+0xe81c+race*4]++
  return &counter
  ret 8
```

`read_memory` hex ends `…5ec20800` matching epilogue. Twin `004d3310` dual already names this VA as the **+1** sibling.

---

## 4. Surviving contract for AutoCore

```
// __thiscall; returns &raceCounter
// SectorMap enter: levelIndex++, optional pool-transition notify, raceHist[race]++
// NOT AddCharacter vector push. NOT CompletelyDestroyObject leave path.
// Callee when flag: CVOGSectorMap_NotifyLevelIndexChange_RescalePools (004d28c0).
// Twin leave: 004d3310.
```

---

## 5. Falsification notes

### 5.1 “Create-character exclusive domain logic”

Scaffold alias seeds from RecvCreateCharacter, but the body is **generic sector-map counter adjust**. Any enter path that needs the same census can call it; do not invent character-create-only side effects inside this VA.

### 5.2 Confusing with AddCharacter (`004d35c0`)

`AddCharacter` mutates the player pointer vector @ `+0xe75c`. This VA never touches that vector.

### 5.3 Confusing notify with always-on rescale

Ports that always call `004d28c0` invent work when `notifyPools == 0`.

---

## 6. Open questions

1. Retail symbol.
2. `+0xe818` English (level vs power-band).
3. Exact `notifyPools` at `0x008147ae`.
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, offsets, twin relationship. Reject equip/vector-push/always-notify overclaims. Product name open.
