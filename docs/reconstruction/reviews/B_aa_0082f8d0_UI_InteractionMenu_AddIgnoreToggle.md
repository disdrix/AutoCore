# Review B (skeptical / adversarial): `aa_0082f8d0` UI_InteractionMenu_AddIgnoreToggle

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f8d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` |
| **Agent** | MEGA-074 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product host class remains open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast / ability residual math (partition nest) | **Falsified as cast** — pure UI button create; consumer of social list only |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — entry uses **EAX** target; **EDI** host; `ret` not `ret 4` |
| 3 | Always creates both Add and Remove buttons | **Falsified** — exclusive Remove **or** Add; Remove early-returns |
| 4 | `FUN_00573af0` this = target / menu | **Falsified** — asm `mov ecx,esi` after `mov esi,[DAT_00d1da2c]`; this = social-list host |
| 5 | Plate string proves full UI system / class name | **Unproven for class** — only widget XML; role from Add/Remove Ignore English |
| 6 | `+0x6B4` is definitely character level | **Unproven** — numeric gate only; English open |
| 7 | `in_EAX` is decompiler phantom (unused) | **Falsified** — entry `cmp [eax+0x6b4]` + parent `MOV EAX,EBP` |
| 8 | `unaff_EDI` is noise | **Falsified** — all host stores/calls use EDI; parent `MOV EDI,ESI` |
| 9 | Name should stay plate `UI_int_btn_generic_*` | **Falsified as best name** — plate is shared across Friends/Trade/Clan packs; role is Ignore toggle |
| 10 | Same function as Friends twin `0082f9a0` | **Falsified** — different ids (`0x11179`/`0x1117c` vs `0x11177`/`0x1117a`), slots (`+0x560`/`+0x56c` vs `+0x558`/`+0x564`), lookup (`FUN_00573af0` vs `FUN_00573a30`), strings |
| 11 | `DAT_00d1da2c` is ignore-only | **Unproven exclusive** — friends twin uses same global with different vector offsets; treat as shared social host |
| 12 | Runtime Confirmed / Terminal | **Rejected** — no Launcher; Terminal false |
| 13 | Return value meaningful in EAX | **Falsified** — void paths; epilogue does not set EAX for caller |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Add/Remove exclusive branch | **Confirmed** | Wrong menu UX |
| Button ids + strings | **Confirmed** | Wrong net/UI id map |
| Slots +0x560 / +0x56c | **Confirmed** | Host layout mismatch |
| Ignore membership via DAT_00d1da2c + FUN_00573af0 | **Confirmed** | Always-Add or always-Remove bug |
| EAX target / EDI host convention | **Confirmed** | Port must match parent |
| `FUN_00573af0` semantics (name search) | **High** | decompile shows `_stricmp` @ entry+0x10 |
| Distinct from Friends twin | **Confirmed** | ids/slots/callee sealed |
| `+0x6B4` product | Open | Gate edge cases |
| Product MSVC menu class | Open | Naming only |

---

## 3. Cross-check

```
FUN_0082fe20 (dualed PopulateTargetButtons):
  ESI = menu host (from ECX)
  EBP = owner from target.vtbl+0x210
  MOV EDI,ESI before pack branch
  order A: Ignore(0082f8d0) → Friends → Tell → Trade → Clan → Convoy → Name
  order B: Name → Convoy → Clan → Trade → Tell → Friends → Ignore(0082f8d0)

FUN_0082f9a0 (Friends twin, dualed MEGA-075):
  same EAX/EDI/gate/+0x6B4 shape; ids 0x11177/0x1117a; FUN_00573a30 peer lookup

FUN_0082fb30 (Convoy dual):
  same gate family; EDX=target ESI=host (different regs); Invite/Kick exclusive

FUN_00573af0:
  thiscall list walk; vector [+0x38,+0x3c); _stricmp(entry+0x10); not OWN dual
```

**Attack on “Remove when not ignored”:** Remove path only when list host non-null **and** lookup non-zero; otherwise falls through to Add.

**Attack on “creates button even when gate fails”:** early `JL` to `RET` before any create when both target.field ≥ 1 and local.field < 1.

**Attack on “thiscall menu”:** no `mov ecx, …` of host at entry; host is EDI throughout; parent is thiscall on menu but child packs use mixed register contracts (ESI/EDI/EDX/EAX).

**Attack on “merge with Friends”:** distinct button ids, host slots, lookup function, and UI strings — twin shape only.

---

## 4. Residual risks

- Parent register contract (EDI host, EAX target) is fragile if re-inlined differently — keep coupled to `FUN_0082fe20`.
- `FUN_00573af0` / `DAT_00d1da2c` layout not OWN; name-key field `+0x10` is structural from that decompile.
- Not skill-cast residual math — parent matrix should tag **UI / social** not cast manager.
- Scaffold plate name `UI_int_btn_generic_0082f8d0` must not re-enter as canonical.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial attacks on cast-role / thiscall / dual-button / friends-merge claims falsified.
