# Review B (skeptical / adversarial): `aa_004f1e20` Clonebase_EnsureDefLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_004f1e20_Clonebase_EnsureDefLoaded_Inferred.md` |
| **System** | `inventory-transfer` / item def load |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on ensure role + ABI + flags; **reject** free-function framing and “always reloads def” |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Free function `FUN_004f1e20(0,1)` | Store sites set **ECX=clonebase** first | **Falsified** |
| 2 | Always reloads def from disk | Heavy path only when `*(this+0x29)==0` | **Falsified** |
| 3 | `param_2` is “force” sole switch | Both params gate different subpaths; phy also post-flag | **Falsified** single-switch |
| 4 | `this` is Item* | Callers pass `*(item+0xA8)`; body has CS at `+0x10`, def at `+0x3c` | **Falsified** |
| 5 | String `"VOG_DEBUG_STOP"` means this is debug-only | Fired on `FUN_0059c000` failure in retail path | **Partial** — error path, not debug-only unit |
| 6 | Name load uses ASCII def name | `wcslen` + `%S` wide stem + `"_nfx.xml"` | **Clarify** — wide stem |
| 7 | Success always returns prior err | Success returns **0**; fail returns loader err | **Clarify** |
| 8 | Product name sealed | `_Inferred` role only | **Open** |

---

## 2. Decisive dataflow (SEALED)

```text
// Store / vendor preflight (most common for OWN batch peers):
Clonebase* cb = *(Clonebase**)(item + 0xA8);
if (*(void**)(cb + 0x3C) == nullptr)
    Clonebase_EnsureDefLoaded(cb, /*doPhyReload*/0, /*doNameLoad*/1);
// re-read *(cb+0x3C) for def fields
```

```text
// Inside ensure when first-time (flag +0x29 == 0):
//   release old def, FUN_0059c000, optional name/nfx, set flag=1
// Always (after first-time block):
//   if doPhyReload: Phy_Preload_ReloadRigidBody
//   refcount++
//   leave CS; return 0 (or early err)
```

Live ≡ raw. Cross-seals: `Item_IsWantedByStore` `aa_00513770`, sell price dual `aa_005142a0`, phy sibling `aa_004f1c70`.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + CS + flag | **High** | Race / double-load bugs |
| Args (0,1) semantics split | **High** | Spurious phy reload |
| def at `+0x3c` | **High** | Wrong gate peers |
| nfx string path | **High** | Wrong asset suffix |
| Loader `FUN_0059c000` English | **Open** | Incomplete ensure story |
| Product symbol | **Open** | Rename residual |

---

## 4. Surviving contract for AutoCore

```text
// Before reading item def fields from clonebase:
if (!cb->def)
    Clonebase_EnsureDefLoaded(cb, doPhyReload, doNameLoad);
// Prefer (0,1) for pure UI/store def field reads; (1,1) when callers also need rigid/nfx.
```

Do **not** model as global free function. Do **not** assume every call reloads.

**Verdict:** **accept-with-gaps**
