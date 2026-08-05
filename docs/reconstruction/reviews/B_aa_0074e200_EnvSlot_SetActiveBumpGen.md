# Review B (skeptical / adversarial): `aa_0074e200` EnvSlot_SetActiveBumpGen

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-Q) |
| **Counterpart** | `reviews/A_aa_0074e200_EnvSlot_SetActiveBumpGen.md` |
| **Scratch** | `tmp/a_0074e200.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Free function `void f(uint enable)` only (W30-F clean stub) | **Falsified** — bytes use ECX (`8B 41 3C`); caller `mov ecx, DAT_00d1a54c` / `mov ecx, esi` + `push 0/1` + `RET 4` |
| 2 | This **stores** `DAT_00d1a54c` | **Falsified** — no write to global; caller stores after both toggles |
| 3 | Enable path skips gen bump | **Falsified** — both branches `ADD dword [eax+0xdc],1` |
| 4 | Flag set without global gate | **Falsified** — enable path requires `*(DAT_00d1f048+0xf) != 0` else falls to clear path |
| 5 | cdecl / bare RET | **Falsified** — `C2 04 00` |
| 6 | Multi-caller utility | **Falsified for static CODE** — only `FUN_004cda90` ×2; sibling `00442b90` is separate body |
| 7 | Scaffold Named_CalleeOf_Named_* product plate | **Reject** — structural name only |
| 8 | `+0xdc` is refcount (paired --) | **Unproven** — this unit only ++; no -- in body; leave English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + RET 4 | **High** | Wrong port call shape |
| related@+0x3c / flag@+0xd1 / gen@+0xdc | **High** | Wrong field writes |
| Gate byte DAT_00d1f048+0xf | **High** | Always-on active misread |
| Role in DAT_00d1a54c publish | **High** | Missed disable/enable order |
| Product class names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004cda90 publish tail (caller not owned):
slot = *(env + 4)
if (DAT_00d1a54c) EnvSlot_SetActiveBumpGen(DAT_00d1a54c, 0)
if (slot)         EnvSlot_SetActiveBumpGen(slot, 1)
DAT_00d1a54c = slot

// Sibling FUN_00442b90 (not owned) inlines same related offsets + global store
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 61 B hex seals dual RET 4 epilogues.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall helper — do NOT treat as free function enable-only:
void EnvSlot_SetActiveBumpGen(Slot* slot, bool enable) {
  auto* r = slot->related; // +0x3c
  if (!r) return;
  r->gen++;                // +0xdc
  r->active = enable && g_envState.gate_0xf; // +0xd1 / DAT_00d1f048+0xf
}
// Caller owns DAT_00d1a54c store order: disable old → enable new → publish.
// Reject Named_CalleeOf_* scaffold alias.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/offsets/caller contract. Product English residual → **accept-with-gaps**.
