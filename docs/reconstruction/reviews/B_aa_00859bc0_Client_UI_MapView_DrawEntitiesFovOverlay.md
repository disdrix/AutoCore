# Review B (skeptical / adversarial): `Client_UI_MapView_DrawEntitiesFovOverlay` / `FUN_00859bc0` @ `0x00859bc0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00859bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/phases/constants; **needs-more-evidence** on list A/B English + product name |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | cdecl / stdcall with stack cleanup | **Falsified** — `mov ebx,ecx`; plain **`C3`** |
| 2 | Same body as `00851630` | **Falsified** — world list A/B first; different helpers; no sin-cone; different FOV scale chain |
| 3 | Requires `config+0x4fc` like sibling | **Falsified** — no `+0x4fc` gate; requires list heads A/B |
| 4 | Server AI entity tick | **Falsified** — client project/draw only |
| 5 | Draws entities without filters | **Falsified** — multiple vfunc + flag gates; skips local; ally tint optional |
| 6 | FOV radius = raw `+0x514` always | **Falsified** — optional scale when `+0x5b9==0`, then `* +0x50c * 0.5` |
| 7 | Code callers | **Falsified** — DATA vtbl only `@00a65a54` |
| 8 | List A/B product English sealed | **Open** — structure only |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall plain ret | **Confirmed** | Stack imbalance |
| this+0x488 config | **Confirmed** | Wrong host |
| World list A/B offsets | **Confirmed** | Wrong entity set drawn |
| Entity filters exist | **Confirmed** | Draw hidden/self |
| FOV *0.5 final | **Confirmed** | Wrong radius |
| Map overlay role | **High** | Mis-port to sim |
| List A/B English | **Low** | Docs only |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// client-only UI overlay
// __thiscall
void Client_UI_MapView_DrawEntitiesFovOverlay(MapView* self):
  cfg = self->config  // +0x488
  if !cfg or !local or !world or !world.listHost: return
  if !listA_head or !listB_head: return

  // 1) world list A: filter → lazy ensure or draw entity icon (FUN_00859260)
  // 2) bump layer
  // 3) world list B: filter + ally tint → draw
  // 4) markers type 0..8 tex +0x624
  // 5) patrol / mission(0x65) / special(100) / squad(1) via FUN_00859a90
  // 6) FOV: radius = f(cfg+0x514, optional scale, *0.5); draw quad FUN_00757890

// NOT markers-only sibling (0x00851630) — no sin-cone here.
// NOT server authoritative entity iteration for gameplay.
```

---

## 4. Falsification notes

### 4.1 “Unfiltered world dump”

List A skips null, hidden (`+0x198`), flag bit3, `FUN_005134e0`, and local entity. List B requires owner and clear clonebase flag bit3. Ports that draw every entity invent clutter and may self-icon.

### 4.2 “Identical to markers overlay”

Different vtbl, different enable gates, different draw helpers, entity lists present, FOV math different (no 300/viewport; uses +0x514 chain * 0.5). Merging breaks both UIs.

### 4.3 Ally tint

Low byte set only when `world+0xf6` OR (party flag and matching ca8/cac). Default is untinted path.

### 4.4 Decompiler float/ptr punning

`fStack_114 = (float)(iVar6 + 0x28)` is pointer-as-float for null checks — treat as **pointer** to list header, not a float magnitude.

---

## 5. Open questions

1. Product names for list A vs B (e.g. dynamic objects vs vehicles).  
2. Full filter bit dictionary.  
3. PDB map panel subclass for vtbl `@00a65a54`.  
4. Runtime golden frames.

---

## 6. Verdict

Sealed contract survives adversarial review. Residual gaps are entity-set English and nested leaves → **accept-with-gaps**.
