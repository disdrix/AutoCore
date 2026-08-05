# Review B (skeptical / adversarial): `NDSpecialFX_DeactivateClear_Inferred` / `FUN_004b7150` @ `0x004b7150`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/role; **needs-more-evidence** only on product symbol + nested callee product names |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is spawn / instantiate | **Falsified** — no allocation of children; only flags, clears, stops |
| 2 | stdcall / ret N | **Falsified** — epilogue plain **`C3`** |
| 3 | Does not flush multi-hits | **Falsified** — first gate calls `FUN_004b6980` when `+0x3c != 0` |
| 4 | Destroys children in-place (free objects) | **Falsified** — sets destroy bit + unlinks; free is caller's `"Destroy"` path in `FUN_004b8ed0` |
| 5 | Sound path is optional noise | **Falsified** — explicit list walk + sealed MarkStopByName |
| 6 | Decompiler list delete edges change happy path | **Partial** — noreturn warnings on residual `operator_delete`; empty-list happy path still returns |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| plain ret thiscall | **Confirmed** | stack imbalance |
| deactivate/clear role | **High** | mis-port as spawn |
| `+0x3c` flush linkage | **Confirmed** | missed multi-hit apply on teardown |
| destroy bit semantics | **High** | children never culled by FX walk |
| Product C++ name | **Open** | docs only |

---

## 3. Surviving contract for AutoCore

```
// thiscall, plain ret
void NDSpecialFX_DeactivateClear(void* fx):
  if fx.staged_hits: FlushStagedMultiHits(fx)
  if phys = resolve(fx.host):
    for child in fx.owned:
      if child.flags & PHYS_DETACH: Detach(phys)
  for child in fx.owned:
    child.flags |= DESTROY_PENDING
    UnlinkNotify(...); child.owner = null
  AuxClear()
  clear attachment list
  for name in sound_names: StopByName(name)
  clear sound list
  for aux in aux_list: AuxRelease()
```

---

## 4. Falsification notes

### 4.1 “Spawn helper”

No `new` of CVOG children; only teardown. Spawn lives elsewhere (e.g. NDSpecialFX instantiate duals).

### 4.2 “Deletes child objects”

Child free is in caller `FUN_004b8ed0` when `+0x90e & 1` already set (profile `"Destroy"`). This VA only **marks** bit0.

### 4.3 stdcall trap

Epilogue is `C3`, not `C2 xx 00`.

---

## 5. Open questions

1. Retail symbol.
2. Whether all four callers pass the same host type (likely yes — shared `+0x3c`/`+0x204` layout).
3. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed CF, ABI, deactivate/clear role. Reject spawn/free-children overclaims.
