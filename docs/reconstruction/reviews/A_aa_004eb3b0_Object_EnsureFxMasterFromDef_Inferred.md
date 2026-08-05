# Review A (reconstruction fidelity): `aa_004eb3b0` Object_EnsureFxMasterFromDef_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb3b0` |
| **VA** | `0x004eb3b0` |
| **Canonical name (Ghidra)** | `FUN_004eb3b0` |
| **Proposed name** | `Object_EnsureFxMasterFromDef_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004eb3b0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004eb3b0_Object_EnsureFxMasterFromDef_Inferred.md` |
| **System** | `client-fx` / clonebase-def lazy FX master attach |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lazy-ensure an FX master catalog host at `this+0x88`**, populated from the clonebase/def wide name at `def+0x316` via `LoadMasterFromXML`.

Gate (all must hold):

1. `*(this+0x88) == 0` (not already attached)
2. `def = *(this+0x3c) != 0`
3. `def != -0x316` (sentinel so `def+0x316` is not null-ish)
4. `*(short*)(def+0x316) != 0` and `*(short*)(def+0x318) != 0` (name present / length ≥ 1 wchar — same field family as `Clonebase_EnsureDefLoaded` `wcslen(def+0x316)`)

Then:

```
host = operator_new(8)
if (host) FUN_004a1620(host)   // map container ctor (empty std::map-like + flags)
else host = 0
*(this+0x88) = host
str = FUN_00402d50(def+0x316)  // local string from wide name
FUN_004a6390(host, *str)       // "LoadMasterFromXML" — thiscall on catalog
// free SSO/heap of local string if spilled
```

Thin ensure used by event trigger `FUN_004ec010` (then `FUN_004a16d0`), preload/clone paths, weapons, creatures, load nodes.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004eb3b0` |
| Raw / annotated / clean | `aa_004eb3b0` three-rep |
| Function record | `docs/reconstruction/functions/aa_004eb3b0_FUN_004eb3b0.md` |
| Consumer dual | `A_aa_004ec010_FUN_004ec010.md` — ensure then event dispatch |
| Sibling note | `A_aa_004f1e20_Clonebase_EnsureDefLoaded_Inferred.md` — same `new(8)+004a1620` / `00402d50(def+0x316)` / `004a6390` pattern |
| Callees live | `004a1620`, `004a6390` (`LoadMasterFromXML`), `00402d50` |

**This pass:** live decompile; 37 xrefs; callee CF. **Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// ECX = object with +0x3C def* and +0x88 FX master host*
void __fastcall Object_EnsureFxMasterFromDef_Inferred(void *obj /* ECX */);
```

SEH (`LAB_009a2770`). Local 128-byte string buffer + optional heap free.

---

## 4. Callers (sample) / callees

| Callee | Role |
|---|---|
| `operator_new(8)` | Catalog host allocation |
| `FUN_004a1620` | Catalog ctor (map root + flags) |
| `FUN_00402d50` | Build local string from `def+0x316` |
| `FUN_004a6390` | `LoadMasterFromXML` into catalog |
| `free` | Release spilled string buffer |

Callers include: `FUN_004ec010`, `FUN_004ec7b0`, `FUN_00512a20`, `FUN_00581dd0`, `FUN_0056bab0`, `FUN_004f1ff0` / preload family, many equip/weapon sites.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Already-has-`+0x88` early out | Yes |
| Def null / sentinel / empty-name gates | Yes |
| `new(8)` + ctor or null | Yes |
| Store `+0x88` | Yes |
| Stringize def name → LoadMasterFromXML | Yes |
| Free local string if not SSO | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Lazy ensure of `+0x88` | **High** | gate + store |
| `+0x3C` is def pointer | **High** | shared with clonebase load; name at `+0x316` |
| `004a6390` = LoadMasterFromXML | **Confirmed** | plate string in callee |
| Catalog object size 8 + map via `004a1620` | **High** | decompile |
| Wide name at `def+0x316` | **High** | sibling EnsureDefLoaded + short non-zero checks |
| Exact host class English (entity vs clonebase vs weapon wrapper) | **Probable** | many call sites; field pair `+0x3C`/`+0x88` common |
| Product name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Product type owning `+0x88` (may be shared base of creature/vehicle/weapon).
2. Whether `LoadMasterFromXML` keys map by event id consumed by `004a16d0` (Probable chain via `004ec010`).
3. Failure path when XML load fails leaves non-null empty host — residual.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — ensure CF + offsets High.
