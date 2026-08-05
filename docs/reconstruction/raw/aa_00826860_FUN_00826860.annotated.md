# Annotated low-level: UI_QuickBarSlotButton_AssignSkill_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00826860` |
| VA | `0x00826860` |
| Body | `0x00826860`–`0x00826ad9` (0x27A bytes) |
| Canonical name | `UI_QuickBarSlotButton_AssignSkill_Inferred` |
| Prior scaffold | `FUN_00826860` |
| System | client UI / quickbar / skills-abilities |
| Date | 2026-07-29 (W23-D dual seal) |

## Machine-level notes

- **ABI:** skill object in **EAX**; QuickBar slot-button pointer on stack; **`ret 4`**; returns `0` (null skill) or `1` (bound).
- **Layout (button):**

| Offset | Field | Role |
|---:|---|---|
| `+0x4fc` | `fSelected` | clear-selection gate |
| `+0x4fe` | icon-state byte | cleared; selects `-on.dds` vs `-off.dds` suffix |
| `+0x500` | columnIndex | slot = page*10+col |
| `+0x504` | pageIndex | |
| `+0x548` | payloadKind | set to **1** (skill) |
| `+0x550`/`+0x554` | skillId lo/hi | from `skill+0x5fc` via cdq |
| `+0x558` | pSkill | skill object* |
| `+0x55c` | flatSlot | page*10+col |
| `+0x564` | pIconWidget | texture path + invalidate |
| `+0x574`/`+0x578` | chrome widgets | vtbl+0x1d8 / +0x34c |
| `+0x57c` | owned child | destroy via vtbl+4(1) |

- **Skill object:** id at `+0x5fc`; icon stem string at `+0x5a6`.
- **rel32 sealed:** SetQuickBarItem `00520890`, SetQuickBarSkill `005208c0`, SetSelected `00826780`.
- **Strings:** `i_d_s_2d_wnd_icon_`, `-off.dds`, `-on.dds`.
- Prefer bytes over decompiler `in_EAX` awkwardness — retail is EAX-skill + stack-button.

## Control flow (annotated)

```
if skill==null: return 0
bChanged = !(kind==1 && pSkill==skill)
button.skillId = skill->id          // +0x5fc -> +0x550/+0x554
button.pSkill = skill               // +0x558
button.kind = 1                     // +0x548
button.flatSlot = page*10+col       // +0x55c
SetQuickBarItem(localChar, slot, -1, -1)   // clear item COID
SetQuickBarSkill(localChar, slot, skillId)
if bChanged && fSelected: SetSelected(button, 0)
button+0x4fe = 0
destroy child +0x57c if any
if pIconWidget:
  path = "i_d_s_2d_wnd_icon_" + skillName + ("-on.dds" if +0x4fe else "-off.dds")
  set texture / invalidate icon
refresh chrome widgets; vfunc +0x448; return 1
```
