# Review B (skeptical / adversarial): `aa_004a6390` FxMaster_LoadMasterFromXML_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6390` |
| **VA** | `0x004a6390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004a6390_FxMaster_LoadMasterFromXML_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `NDSpecialFX_LoadFromScriptName` | both open `_nfx.xml` | **Distinct** — this fills catalog map multi-node; LoadFromScriptName parses **first** node + `004a0b90` instance |
| 2 | Conditional `_nfx.xml` like LoadFromScriptName | `strstr` | **Falsified for this VA** — **always** appends `_nfx.xml` |
| 3 | Open non-zero = success | `if (iVar7 == 0)` | **Falsified** — 0 is success branch |
| 4 | Clear loop aborts at first free (`operator_delete` noreturn) | decompiler WARNING | **Rejected as truth** — same mislabel family; reset tree after walk proves clear continues |
| 5 | Returns live FX* | return constants | **Falsified** — returns **1/0** status; templates stay in map |
| 6 | Role is only `VOG_DEBUG_STOP` | scaffold name | **Falsified** — plate LoadMasterFromXML; VOG is missing-node assert |
| 7 | Path uses POSIX `../scripts/` | memory | **Falsified** — `..\scripts\` backslashes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Catalog multi-entry load | **High** | Single-FX load leaves map empty for events |
| Always-append `_nfx.xml` | **High** | Double-suffix if callers pass full filename |
| Map insert by event id | **High** | Event variant miss |
| Return bool 1/0 | **High** | Callers treating as pointer |
| Duplicate path free of `fx` only | **High** CF | Leak nodes if insert half-done |
| `DAT_00b035fc` session English | **Tentative** | Wrong global gate in port |

---

## 3. Cross-check against raw / live

```
profile("LoadMasterFromXML")
if !DAT_00b035fc: return 0
host[+6]=1
clear map values (004b85d0/004b99c0/delete) + empty tree
path = "..\\scripts\\" + name + "_nfx.xml"   // always suffix
if OpenTaggedDocument(path,"NDSpecialFX") != 0: return 0
for each child:
  parse → insert map[eventId]=fx
  dup → log + free fx
close; return 1
```

Live ≡ raw ≡ clean on CF. Contrast `004a61b0`: first-only + instantiate + (decompiler) free template.

---

## 4. Surviving contract for AutoCore

```
// After FxMasterCatalog_Ctor:
ok = LoadMasterFromXML(host, baseName)  // bool
// Map now eventId → NDSpecialFX template*
// Dispatch: FxMaster_LoadEventVariant(host, eventId, mode, slot)
```

**Port guidance:** client-only. Do not implement conditional suffix unless evidence appears; prefer callers pass base names without `_nfx.xml`. Do not return FX pointer from this VA.

---

## 5. Attack scenarios that must not pass review

1. **Merge with LoadFromScriptName** — wrong multi vs first, wrong return, wrong post-parse (`004a0b90` absent here).
2. **Treat Open non-zero as OK** — inverts all loads.
3. **Skip map clear** — stale event templates after reload.
4. **Assume optional `_nfx.xml`** — breaks when name already has suffix (double) OR when modernizing to match LoadFromScriptName strstr without re-checking this VA.

---

## 6. Open questions

1. Does any caller pass a name already containing `_nfx.xml`?
2. `FUN_004a7580` exact insert / “duplicate” flag polarity.
3. Ownership of FX in map: only teardown on clear/reload via `004b99c0`.

**Verdict:** **accept-with-gaps**
