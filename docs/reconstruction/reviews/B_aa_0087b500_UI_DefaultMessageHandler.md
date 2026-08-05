# Review B (skeptical / adversarial): `UI_DefaultMessageHandler` @ `0x0087b500`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b500` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0087b500_UI_DefaultMessageHandler.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is a generic “do nothing” stub | **Falsified** — three distinct outcomes (swallow / bubble / 0) with real virtuals |
| 2 | Decomp `param_1[0xac]` is wrong offset | **Falsified** — `0xac * 4 = 0x2B0` matches `[esi+0x2B0]` |
| 3 | Range is exclusive / off-by-one | **Falsified** — machine `cmp 7`/`jl` + `cmp 0x0F`/`jg` ⇒ inclusive 7..15 |
| 4 | Always forwards to parent | **Falsified** — gated by `vtbl+0xD8` and null parent |
| 5 | cdecl / no stack cleanup | **Falsified** — `ret 8` seals thiscall + 2 stack args |
| 6 | Name is product-accurate | **Overstated** — **INFERRED** from role; no plate string on body |
| 7 | Return is always bool 0/1 | **Partially falsified** — band returns 1 and zero-path 0, but parent path returns full EAX from virtual |
| 8 | Scaffold clean invented CF | **Falsified** — CF matches raw; dual clean only renames/annotates |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 8 | **High** | Wrong dialog dispatch in ports |
| msg 7..15 swallow | **High** | Event double-handling / missed swallow |
| Parent `+0x2B0` + `vtbl+0x338` bubble | **High** | Broken dialog host chain |
| Predicate `vtbl+0xD8` | **High** slot / **Tentative** meaning | Over-forward when window “should not” |
| Product name | **Low** | Registry churn only |
| Clean bit-exact | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
uint UI_DefaultMessageHandler(UiWindow* self, int msg, uint controlId)
{
  if (msg >= 7 && msg <= 15) return 1;
  if (!self->VtblMayForward()) return 0;          // vtbl+0xD8
  if (self->Parent == null) return 0;             // +0x2B0
  return self->Parent->VtblOnMessage(msg, controlId); // vtbl+0x338
}
```

**Port guidance:**

- Keep this as the **shared default** for dialog OnMessage fallthroughs — do not copy per-dialog.
- Mid-band swallow must stay **inclusive 7..15** (matches attribute-point / other duals that return 1 for 7,8,0xD,0xE before default).
- Parent bubble uses the same `vtbl+0x338` message slot already sealed on peer UI duals.

---

## 4. What would change the verdict

1. Product string / RTTI naming the method (would lock name).
2. Decompile/read of a concrete `vtbl+0xD8` implementation proving different gate (focus vs visible).
3. Counterexample caller that passes non-message args into this entry (would rewrite ABI — none seen).

---

## 5. Open questions

1. Full message enum outside the swallow band.
2. Whether any caller relies on non-0/1 return from parent virtual through this path.
3. Layout doc for UI window `+0x2B0` field name.

**Verdict:** **accept-with-gaps** — CF/ABI High; naming + predicate semantic residual.
