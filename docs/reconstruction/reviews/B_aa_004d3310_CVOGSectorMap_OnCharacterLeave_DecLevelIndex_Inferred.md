# Review B (skeptical / adversarial): `aa_004d3310` CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3310` |
| **VA** | `0x004d3310` |
| **Canonical name** | `CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md` |
| **System** | sector-map / combat-pool level index |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is equip-slot mutator | Body only touches `+0xe818` / `+0xe81c`; no equip TFID | **Falsified** equip-mutator |
| 2 | Always notifies pool rescale | Gated by `param_3` / caller local-player flag | **Falsified** always |
| 3 | `+0xe818` is character spree | Spree is elsewhere (`+0x738` class of fields); this is sector-map dword shared with pool table index | **Survives as non-spree** |
| 4 | Removes character from `+0xe75c` vector | Vector erase is `004d9b50`; this only adjusts counters | **Falsified** remove role |
| 5 | Race from `param_2` raw `+0x532` | Dual-base walk required; raw offset on outer wrong | **Agree** walk |
| 6 | Static-only / no this | `MOV` thiscall pattern; CompletelyDestroyObject sets ECX from owner vfunc | **Falsified** static-only |
| 7 | Identical to `004d32c0` | Twin is **increment**; this is **decrement** | **Falsified** identity |

---

## 2. Live ≡ raw

```
Live decompile 0x004d3310 ≡ raw scaffold:
  [this+0xe818]--
  if flag: call 004d28c0(old, new)
  race = def+0x532
  [this+0xe81c+race*4]--
  return &counter
```

Parent seal (`FUN_009440e0`): after `004d9b50`, if `004024b0` count delta → `004d3310(char, localPresent)`.

---

## 3. Surviving contract

```
// void-ish thiscall; returns &raceCounter
// SectorMap leave: levelIndex--, optional pool-transition notify, raceHist[race]--
```

**Verdict:** **accept-with-gaps.**
