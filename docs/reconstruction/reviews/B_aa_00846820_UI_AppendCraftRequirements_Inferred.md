# Review B (skeptical / adversarial): `aa_00846820` UI_AppendCraftRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00846820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00846820_UI_AppendCraftRequirements_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Primary name is Combat (`Named_Required_Combat_00846820`) | Headers are **INGREDIENTS** / **ENHANCEMENT INGREDIENTS**; Combat is one optional Required line among Faction/Class/stats/Level | **Falsified as exclusive role** |
| 2 | Standard thiscall on item in ECX | Entry loads stack arg to EBP; **ESI** is UI text; item not in ECX at entry | **Custom register+stack ABI** |
| 3 | Same layout as `UI_AppendItemRequirements` | Item sibling uses **item-root** shorts `+0xec..+0xf2` and `"Requires:"` header; this unit uses **def** shorts `+0x3fe..` + ingredients | **Distinct craft block** |
| 4 | Always draws ingredients | Only if `FUN_00599dd0` count > 0; enhancement only if vfunc `+0x60` > 0 | **Conditional sections** |
| 5 | `unaff_retaddr` is return address used as item | Assembly reloads item from stack / EBX; decomp bleed | **Decomp hazard** — item is stack param |
| 6 | `operator_delete` never returns (decomp warning) | Standard CRT delete; path continues to faction lines | **False positive** |
| 7 | Server must port this UI block | Pure client presentation with local player compares | **Doc only** for AutoCore sector |
| 8 | Empty Ghidra xrefs ⇒ dead code | Large non-trivial body + exclusive product strings; likely unrecovered relative CALLs | **Not proven dead** — callers open |
| 9 | "Required Faction" is faction reputation system | Uses race id path `FUN_0051f8e0` + player `+0x532` (same race byte as item Requires) | **Race/display table** under Faction label |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Craft UI role + multi-section strings | **High** | Wrong rename |
| ESI text + stack item ABI | **High** | Wrong call sites |
| Def ingredient / req offset map | **High** | Wrong schema docs |
| Color constants | **High** | Wrong UI theme notes |
| Enhancement recipe path | **High–Medium** | FUN_005097b0 multi-case; sealed as used |
| Product method name | **Probable** | Doc only |
| Caller set | **Open** | Missing integration map |
| Runtime | **Open** | Visual mismatch |

---

## 3. Cross-check against raw / bytes

```
raw ≡ live decompile CF for product stages
entry: push -1; push 009ac516; FS SEH; sub esp,0x19c; cmp DAT_00d1b6d8; mov ebp,[esp+0x1b0]
ESI: used as UI text this; not in push/pop save set
strings: INGREDIENTS / ENHANCEMENT INGREDIENTS / Discipline / Required *
colors: 0xff20ff20 / 0xffff2020 / 0xffff0000 / 0xffffffff
epilogue: pop edi/ebx/ebp; add esp,0x1a8; ret
callers: none recovered (gap)
sibling contrast: 00845360 item Requires vs this craft ingredients block
```

Reject any claim that this is a Combat-only helper, a pure ECX-thiscall on the item, or a bit-identical twin of `UI_AppendItemRequirements`.

---

## 4. Surviving contract for AutoCore

```
// Client UI only — not a sector authority check
int UI_AppendCraftRequirements_Inferred(ItemOrCraft* item /*stack*/, UIText* text /*ESI*/):
  if no local player: return 0
  if ingredient slots present:
    append green "\nINGREDIENTS\n" + resolved ingredient lines
  if enhancement count > 0:
    append green "\nENHANCEMENT INGREDIENTS\n" + recipe-row lines
  optional Discipline / Required Faction / Class / Combat / Perception / Tech / Theory / Level
  color red on player fail else plain append
  return lineCount

// Server ports: use data-driven craft req checks, not this presentation path.
// Reuse dualed getters (class name, Combat/Theory/Perception/Tech) for compare semantics only.
```

Do **not** use `Named_Required_Combat_00846820` as primary. Keep Ghidra `FUN_00846820` as twin.

---

## 5. Open questions

1. Who calls this (tooltip path vs craft panel vs both)?
2. UI class / vtable for text append styles `+0x224` / `+0x250` / `+0x22c`.
3. Whether `DAT_00d1b6d8+0x6b4` is a developer "show item ids/qty" flag.
4. Live: does line count drive layout height in unrecovered callers?
5. Relationship of inline ingredients formatting inside `UI_BuildItemTooltipStats` (`0x00847ad0`) — duplicate or alternate path?

**Verdict:** **accept-with-gaps** — adversarial kills Combat-primary and ECX-item misreads; craft-requirements contract stands with caller inventory and runtime open.
