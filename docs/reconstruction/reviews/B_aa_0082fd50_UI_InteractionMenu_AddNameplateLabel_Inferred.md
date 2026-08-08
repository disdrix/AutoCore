# Review B (skeptical / adversarial): `aa_0082fd50` UI_InteractionMenu_AddNameplateLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fd50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md` |
| **Agent** | MEGA-084 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast / ability residual math (skills-abilities partition) | **Falsified as cast** — pure UI button create; nameplate pack child of dualed populate; no cast/validate callees |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — EDI host + EBX target; `ret` not `ret 4`; parent sets regs |
| 3 | Label is a fixed English string ("Name", "Inspect", …) | **Falsified** — label is dynamic `vtbl+0x160` return; no string literal for caption in this unit |
| 4 | Button is an actionable social command like Tell/Trade | **Falsified** — always `vtbl+0xD4(0)` disable before color/finalize; nameplate/display role |
| 5 | Plate-only name `UI_int_btn_generic_0082fd50` is sufficient product name | **Rejected as canonical** — XML plate shared by all social packs; role is nameplate label |
| 6 | `+0x6B4` is definitely character level | **Unproven** — numeric gate only (shared with convoy pack); English open |
| 7 | Colors encode faction/PvP/hostile | **Unproven** — two ARGB immediates sealed; product mapping open |
| 8 | Decompiler `void FUN_0082fd50(void)` with 1-arg create is complete ABI | **Partially wrong** — CF OK, but create takes **4** stack args (asm sealed); regs not formals |
| 9 | Product name retail-known without `_Inferred` | **Unproven** — keep `_Inferred` |
| 10 | Runtime Confirmed | **Rejected** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Nameplate role (dynamic name + disable) | **Confirmed** | Wrong UI chrome |
| Button id `0x1117F` + slot `+0x53C` | **Confirmed** | Host layout / command map mismatch |
| Parent ×2 call sites + register contract | **Confirmed** | Port breaks pack order |
| Color branch on `+0x6B4` | **Confirmed** | Wrong tint edge |
| Leaf / no direct FUN callees | **Confirmed** | False dependency |
| `+0x6B4` product English | Open | Gate edge cases |
| Color semantic English | Open | Wrong theming |

---

## 3. Cross-check

```
FUN_0082fe20 UI_InteractionMenu_PopulateTargetButtons_Inferred [dualed]:
  resolves target TFID; owner = target.vtbl+0x210(0)
  if owner valid and not local:
    flag = host.vtbl+0x478()
    if flag != 0:
      mov ebx,ebp; call FUN_0082fd50   @ 0x0082FEC0  // Name first
      ... convoy/clan/trade/tell/friends/ignore
    else:
      ... ignore/friends/tell/trade/clan/convoy
      mov ebx,ebp; call FUN_0082fd50   @ 0x0082FF22  // Name last

Peer packs (shared plate, different ids):
  0x11171/2 Convoy, 0x11173/4 Clan, 0x11176 Tell, 0x11177/7A Friends,
  0x11179/7C Ignore, 0x1117F Nameplate (this unit)

Shell clear peer FUN_0082F850 writes host+0x53C = 0 (nameplate slot).
```

**Attack on “this is Tell/Trade misnamed”:** Tell pack uses fixed `"Send a Tell"` + id `0x11176`; this unit uses dynamic name + `0x1117F` + always-disable — distinct.

**Attack on “EBX is menu host”:** parent always `mov ebx,ebp` (owner) and `mov edi,esi` (host) before call; body reads `EBX+0x6B4` and writes `EDI+0x53C`.

**Attack on “enable after disable means clickable”:** `vtbl+0xD4(0)` then color + `vtbl+0x1E4(1)` — chrome finalize, not re-enable of social action; no command text path.

---

## 4. Residual risks

- Parent register contract (EDI/EBX) is fragile if parent is rewritten — keep as fragment of `FUN_0082fe20`.
- Decompiler drops create-args beyond the plate string — clean must use asm-sealed 4-arg form.
- Partition tags skills-abilities but unit is **UI nameplate**, not cast manager.
- Color/`+0x6B4` product English remains open (same residual family as convoy dual).

**Verdict:** **accept-with-gaps** — no CF reject; role sealed as nameplate label pack under `_Inferred`.
