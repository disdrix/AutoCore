# Review B (skeptical / adversarial): `aa_0082d2b0` UI_InteractionMenu_RebuildPopupShell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d2b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md` |
| **Agent** | MEGA-072 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast residual / HB math | **Falsified** — pure UI shell rebuild; blocker XML + dialog ctor; no skill/HP/heat |
| 2 | Skill-menu-only callee (Named_CalleeOf scaffold) | **Falsified** — 7 CALL sites incl. dualed interaction-menu populate + equip + DATA vtbl |
| 3 | This is the social button factory | **Falsified** — dualed parent `0082fe20` calls this **then** seven packs; this only rebuilds shell |
| 4 | Standard stdcall with stack args | **Falsified** — `MOV ESI,ECX`; bare `RET` not `RET N` |
| 5 | Always runs (no gate) | **Falsified** — early `CMP [ESI+0x4c0],0; JZ` |
| 6 | Reuses existing dialog without destroy | **Falsified** — `vtbl+0xbc` on prior `+0x538` before new |
| 7 | Layer is 7000 not 70000 | **Falsified** — `PUSH 0x11170` (=70000) |
| 8 | Float store is int-of-float as decompiler shows | **Falsified as CF** — asm `NEG; CVTSI2SS; MOVSS` stores float; decompiler presentation gap only |
| 9 | Product name retail-known | **Unproven** — `_Inferred` required |
| 10 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 11 | `+0x534` is free list / unrelated | **Falsified as free list** — peer dual `aa_0082ce20` seals CNDHash teardown at same offset; size `0x34` ctor matches |
| 12 | DATA xref is coincidence | **Falsified** — `read_memory` @ `0x00a733b8` is pointer to this VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host thiscall + `+0x4C0` gate | **Confirmed** | Wrong activation / null host |
| Shell rebuild role (not button packs) | **Confirmed** | Mis-port as pack factory |
| Dialog XML + layer | **Confirmed** | Wrong UI asset |
| Multi-caller shared | **Confirmed** | Skill-only rename trap |
| CNDHash product English @ `+0x534` | **Inferred** | Rename only if wrong type name |
| Vtbl method English | Open | Port comments |
| Product host class | **Inferred** | Rename only |

---

## 3. Cross-check

```
FUN_0082fe20 (dualed parent PopulateTargetButtons):
  CMP [ESI+0x4C0],0; CALL 0082d2b0  ← first action; then TFID resolve + packs

FUN_0082fb30 (dualed convoy pack):
  separate button pack — not this unit

FUN_0082ce20 (dualed CNDHash teardown At534):
  scalar-deletes hash @ +0x534 — complementary lifecycle to this rebuild

FUN_007b5dd0:
  0x488 NDUI dialog ctor — structural size match

String 0x00a4c5ec:
  i_d_pop_2d_wnd_blocker.xml — popup blocker chrome, not skill icon
```

**Attack on “Named_CalleeOf skill only”:** skill menu is one caller among many; scaffold retired.

**Attack on “this populates Tell/Trade/… buttons”:** no pack callees; only hash + dialog shell.

---

## 4. Residual risks

- `FUN_00416920` product type relies on peer dual offset contract; size/flag sealed, English open.
- Host may be a shared UI base, not exclusively “InteractionMenu” — name is role-inferred from primary dualed parent + partition hint.
- Null `dialog` after OOM still flows into `vtbl+0xa8` / dialog vtbl calls (matches binary; port must preserve crash-on-OOM behavior or document intentional harden).
- Not cast-manager residual — matrix should tag **UI / interaction menu shell**.

**Verdict:** **accept-with-gaps** — no CF reject; scaffold Named_CalleeOf retired.
