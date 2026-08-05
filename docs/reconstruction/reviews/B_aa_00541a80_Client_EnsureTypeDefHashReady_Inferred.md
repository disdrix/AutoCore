# Review B (skeptical / adversarial): `aa_00541a80` Client_EnsureTypeDefHashReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00541a80_Client_EnsureTypeDefHashReady_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is an audio/play function | Wave partition “mission/audio” label | **Falsified as play** — returns hash; used for **`CNDHash_LookupByKey`** suppress gate, not playback |
| 2 | Always reloads | | **Falsified** — only when `*(hash+0xC) < 1` |
| 3 | Returns `host+0xF20` buffer | | **Falsified** — returns **`+0xF1C`** table/hash object |
| 4 | Null-safe if `+0xF1C` is null | | **Falsified** — derefs `*(hash+0xC)` with no null check |
| 5 | Same as `CSoundManager_GetInstance` | | **Falsified** — different VA/family |
| 6 | Insert-only pure getter | | **Falsified** — may call reload with side effects |
| 7 | `__fastcall` host in ECX | | **Sealed** — uses `param_1` only as host |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Return `+0xF1C` | **High** | Wrong map |
| Empty → reload | **High** | Stale/empty suppress |
| Not a sound play API | **High** | Mis-wire FX audio |
| Reload completeness | **Medium** | Partial defs |
| Host type identity | **Medium** | Doc |

---

## 3. Cross-check against raw

```text
// raw ≡ live
if (*(int*)(*(int*)(host+0xf1c)+0xc) < 1)
  FUN_00541950();
return *(host+0xf1c);
```

---

## 4. Surviving contract for AutoCore

```
CNDHash* EnsureTypeDefHashReady(host):
  h = host.typeDefHash  // +0xF1C
  if h.count < 1:       // +0xC
    ReloadTypeDefs(host)
  return host.typeDefHash
```

**Port tests:**

* Must not play audio.
* Lookup sites must use returned pointer with `CNDHash_LookupByKey`.
* Null `+0xF1C` may crash — matching retail.

---

## 5. Open questions

1. Data file / provider behind `FUN_007dbce0`.
2. Whether connection-terminated path expects reload empty→full.

**Verdict:** **accept-with-gaps**
