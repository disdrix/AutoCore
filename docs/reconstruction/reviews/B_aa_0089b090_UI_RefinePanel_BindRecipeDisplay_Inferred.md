# Review B (skeptical / adversarial): `aa_0089b090` UI_RefinePanel_BindRecipeDisplay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089b090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0089b090_UI_RefinePanel_BindRecipeDisplay_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (string-sealed role; widget types residual) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is S2C inventory demux | No packet parse; only UI vtbls + hash | **Falsified** as demux |
| 2 | Always paints 5 ingredients | Wipe path when both selects = −1; pad loop only when `iStack_22c < 5` | **Falsified** as always-5 |
| 3 | Mode always multi-input | `host[0x14a]` set to **2** on single-product branch, **1** on multi | **Falsified** as always-1 |
| 4 | Reverse path uses same coid | Flag `host[0x14e]` re-lookups via `+0x4d0` | **Sealed** — separate product key |
| 5 | `%s_key_i.dds` always | Only when entry type `== 0xe` | **Falsified** as always-key |
| 6 | Clean plate renames are sealed | Scaffold only; FUN names in clean | **Gap** — keep `_Inferred` |
| 7 | Hidden callers outside 0089c6c0 | 4 xrefs, all same parent | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI rebind for refine/recipe panel | **High** | Wrong system bucket |
| Strings Recipe/Refines/Reverse | **High** | Doc only |
| Mode byte `+0x14a` 0/1/2 | **High** | Wrong UI state machine |
| Reverse flag `+0x14e` | **High** | Broken reverse refine UI |
| 5-slot strip around `+0x169` | **High** | Slot overflow / ghost icons |
| Commodity `+0x4d0` / `+0x4c9` | **High** | Wrong product / tech gate |
| Widget vtbl English | **Open** | Port UI only |
| Runtime | **Open** | Live desync |

---

## 3. Surviving contract

```c
// cdecl-ish: this on stack (caller PUSH refine_ui)
void UI_RefinePanel_BindRecipeDisplay(RefineUiHost* host);
```

- Requires host visible probe `vtbl+0x3d8` and global client `DAT_00d1b6d8`.
- Resolves coid from dual selectors; empty → clear chrome + return.
- Binds icons/labels/qty from clone catalog hash; reverse mode optional.
- Ends with Recipe / Refines label widgets; no network.

---

## 4. Verdict

**accept-with-gaps** — adversarial checks seal string-backed role and mode/reverse branches against scaffold noise. Do not promote PDB name without symbol.
