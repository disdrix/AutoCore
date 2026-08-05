# Review B (skeptical / adversarial): `aa_004a1620` FxMasterCatalog_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a1620` |
| **VA** | `0x004a1620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004a1620_FxMasterCatalog_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full FX object ctor (`0x240`) | body size / fields | **Falsified** — only 8-byte host + map header; no particle lists |
| 2 | `__thiscall` with stack args | register use | **Falsified** — `__fastcall` ECX-only host; returns host |
| 3 | Always succeeds | `operator_new` | **Partial** — null map stored if alloc fails; host still returned |
| 4 | Re-inits globals every call | `DAT_00b03628` gate | **Falsified** — once-only when flag was 0 |
| 5 | Same as LoadFromScriptName | callers | **Distinct** — this is empty container; load is `004a6390` |
| 6 | Scaffold “VOG_DEBUG_STOP callee” is product role | string in body | **Falsified** — no debug string here; alias is chain-only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty map + 3 flag bytes | **High** | Wrong catalog type for event lookup |
| Host size 8 | **High** | Over/under-alloc at `obj+0x88` |
| Map header size `0xc` | **High** | Leak / corrupt tree |
| Global block purpose | **Tentative** | Shared FX state side effects |
| Product name | **Tentative** | Naming only |

---

## 3. Cross-check against raw / live

```
host[+4]=host[+5]=host[+6]=0
map = new(0xc) or null
if map:
  sentinel = FUN_00439770()
  map[+4]=sentinel; nil-flag; self-links; size=0
*host = map
if !DAT_00b03628: init globals; DAT_00b03628=1
return host
```

Live ≡ raw ≡ clean. Callers: EnsureFxMaster / Clonebase preload / mission-adjacent FX ensure.

---

## 4. Surviving contract for AutoCore

```
host = operator_new(8)
FxMasterCatalog_Ctor_Inferred(host)  // empty map
// then LoadMasterFromXML(host, scriptName)
// then LoadEventVariant(host, eventId, ...)
```

Do **not** treat as NDSpecialFX instance. Do **not** skip map alloc null-check if porting to non-throwing new.

---

## 5. Attack scenarios that must not pass review

1. **Confuse with `004ba310` / `0x240` FX ctor** — wrong size and fields.
2. **Assume this loads XML** — load is sibling `004a6390`.
3. **Assume re-zero of global FX tables every attach** — only first ctor in process.

---

## 6. Open questions

1. English meaning of host `+4` (unused after ctor?).
2. Owners of `DAT_00b035e4..f8` readers.
3. Whether map key type is always int event id (consumer `004a16d0` says yes).

**Verdict:** **accept-with-gaps**
