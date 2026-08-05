# Review B (skeptical / adversarial): `aa_008a16b0` CDlgQuickBar_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a16b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-R OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md` |
| **System** | `skills-abilities` / client QuickBar UI |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + role; **reject** overclaims (full 10-column ctor, cast/network, narrow hazard-only name) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Builds all 10 page-column skill buttons here | **Falsified / overclaim** — only **two** `CreateSlotButton` sites (labels 1/2); columns via `FUN_008a1110`/`FUN_008a0e10` |
| 2 | Is slot activate / skill cast | **Falsified** — no cast callees; tail is rebind + select chrome |
| 3 | Sends network packets | **Falsified** — UI ctor/load only |
| 4 | Only builds hazard gauge (seed name) | **Falsified as primary role** — many children + page buttons + rebind; hazard is one subsystem |
| 5 | Direct callers in .text | **Falsified** — data/vtable xref only (`0x00a4d320`) |
| 6 | Selection gate matches SelectPage empty mask | **Falsified equality** — this unit gates on `+0x548 == 0 or 6`; SelectPage uses `(+0x550 & +0x554)==-1` |
| 7 | Product symbol proven | **Fail** — `_Inferred`; does not block accept-with-gaps |
| 8 | Needs `disassemble_bytes` | **Falsified** — decompile + `read_memory` sufficient for seal |

---

## 2. Decisive evidence

### CreateSlotButton dual sites only

Sealed dual on `0x00825bf0`: **sole** callers are the two `operator_new(0x554)` sites in this function. Confirms page-button chrome, not 10-column factory.

### String plate

Five `i_d_qb_2d_*` skins + vtable-adjacent `Show Quick Menu` / `Hide Quick Menu` place this firmly on Quick Menu / QuickBar host, not CharSheet residual alone (despite shared helpers like `FUN_008a0370`).

### Live ≡ raw

Full 2026-07-29 decompile matches 2026-07-23 raw capture — no CF drift.

### Tail branch

```text
if prevCol bad OR col+0x548 null/6 → FUN_008a0210(1)
else → FUN_00826780(1)
```

Do **not** silently rewrite gate to SelectPage's empty-mask CF.

### Decompiler SEH noise

`ExceptionList = pcVar9` after string assignment is **not** real control flow — classic ExceptionList clobber; do not invent cleanup based on that.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Child alloc order + slots | **High** | Wrong host layout |
| Page buttons 0/1 only | **High** | Over-implement 10 columns here |
| Hazard XML load | **High** | Missing chrome |
| Tail rebind/select | **High** CF | Wrong first-show selection |
| Host class name | **Probable** | Naming |
| Method name CreateChildWidgets | **Inferred** | Naming |
| Early chrome product IDs | **Open** | Incomplete UI port |

---

## 4. What would falsify accept-with-gaps

1. Additional direct call sites with different host type.
2. Proof body casts skills / sends packets.
3. Image where CreateSlotButton is called >2 times from this VA (would expand role).
4. Live decompile CF divergence from raw.

None observed.

---

## 5. Verdict

**accept-with-gaps.** Role and major CF sealed. Prefer `CDlgQuickBar_CreateChildWidgets_Inferred` over narrow `UI_qb_hazard_gauge`. Residual: product symbol, unnamed early children, SetSelected ECX, sibling `FUN_008a1110` ownership, runtime golden.
