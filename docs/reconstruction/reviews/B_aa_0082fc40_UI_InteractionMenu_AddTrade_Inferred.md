# Review B (skeptical / adversarial): `aa_0082fc40` UI_InteractionMenu_AddTrade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fc40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082fc40_UI_InteractionMenu_AddTrade_Inferred.md` |
| **Agent** | MEGA-077 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast / ability-activate logic | **Falsified as cast** — pure UI button create + range disable; residual of interaction-menu pack under skills-abilities partition |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — body uses **EBX** target + **ESI** host; entry is frame-setup not `MOV REG,ECX`; `ret` not `ret 4` |
| 3 | Disable means destroy / free button | **Falsified** — `vtbl+0xD4(0)` disable/hide; pointer still stored at `+0x550` |
| 4 | Distance check enables button when far | **Falsified** — `COMISS dist², 1600; JBE skip` → disable only when **greater** than threshold |
| 5 | Threshold is 1600 units linear | **Falsified** — float is **1600.0** on **squared** sum; linear range **40** |
| 6 | Target is EDX like convoy sibling | **Falsified** — Trade uses **EBX** (`MOV EBX,EBP`); convoy sibling uses **EDX** |
| 7 | Plate string proves full UI system class name | **Unproven for class** — only widget XML; role from `"Trade"` + parent pack |
| 8 | `+0x6B4` is definitely character level | **Unproven** — numeric gate only; English open |
| 9 | Product name retail-known | **Unproven** — `_Inferred` required |
| 10 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 11 | Direct callees exist | **Falsified** — `get_function_callees` empty; all vtbl indirect |
| 12 | Prior name `UI_int_btn_generic_*` is product | **Falsified as product** — plate-only scaffold; superseded by Trade role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trade string + id `0x11175` | **Confirmed** | Wrong net/UI id map |
| Slot `+0x550` | **Confirmed** | Host layout mismatch |
| Range gate dist² > 1600 | **Confirmed** | Trade available out of range |
| ESI host / EBX target | **Confirmed** | Port ABI break vs parent |
| Parent dual call sites ×2 | **Confirmed** | Miss pack order |
| `+0x6B4` product | Open | Gate edge cases |
| Host class demangle | Open | Naming only |

---

## 3. Cross-check

```
FUN_0082fe20  PopulateTargetButtons:
  resolves target TFID; if not self/local:
    builds packs including FUN_0082fc40 twice (order depends on vtbl+0x478)
    order-0 @ 0x0082fed7: … Tell → Trade → Clan → Convoy …
    order-≠0 @ 0x0082ff0b: … Clan → Trade → Tell …
  both sites: MOV EBX,EBP before CALL 0x0082fc40

aa_0082fb30  AddConvoyInviteOrKick (sibling dual):
  same +0x6B4 gate family; ESI host; target in EDX not EBX
  disable via same vtbl+0xD4(0) pattern (leader check, not range)

DAT_00aaa674:
  read_memory → 00 00 C8 44 → 0x44C80000 → 1600.0f
```

**Attack on “always create Trade for self”:** parent `FUN_0082fe20` skips pack when target owner is null or == local; this unit never runs for self-target paths.

**Attack on “Trade always enabled if created”:** squared-distance path can disable immediately after create when target is beyond 40 units.

**Attack on “thiscall this = menu”:** create call does `MOV ECX,ESI` before `CALL [EDX+0x444]` — host is this **for the vtbl helper only**, not a formal ECX entry for `FUN_0082fc40` itself.

---

## 4. Residual risks

- Parent register contract (ESI/EBX) is fragile if parent is rewritten — keep as menu-host + target from `FUN_0082fe20`.
- SharedBase position chain (`[obj+4]→[+4]→[+obj+4]+0x1A0`) is a recurring pattern; product English still open.
- Not skill-cast residual math — parent matrix should tag **UI / interaction menu** not cast manager.

**Verdict:** **accept-with-gaps** — no CF reject.
