# Review B (skeptical / adversarial): `aa_00845360` UI_AppendItemRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_00845360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00845360_UI_AppendItemRequirements.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Primary name is Combat (`Named_Combat_00845360`) | Header string is **`"Requires:"`**; Combat is one optional line among Level/race/class/Tech/Theory/Perception | **Falsified as exclusive role** — rename to Requires/Requirements |
| 2 | Standard thiscall on item in ECX | Entry is **`mov esi,eax`** — item in **EAX** | **Custom register ABI** |
| 3 | Always draws the block | Three hard gates + empty-req cascade return **0** with no header | **Conditional** |
| 4 | Level uses raw short sum for display | `FUN_0040f540` **caps at 0x50 (80)** for the printed/compare value path | **Capped** level helper |
| 5 | Race/class always red/white via `+0x224` | Met race/class uses vfunc **`+0x250`** (different append) | **Two append styles** |
| 6 | `return unaff_EBP+1` is stack-frame dependent | Counter `iVar7` tracks lines; EBP is decomp bleed on Perception exit | **Line count +1**, not real EBP |
| 7 | `FUN_007a69d0` is dead | Result moved to **EDI**; drives localize | **Live** string-table init/get |
| 8 | Server must port this UI block | Pure client presentation | **Doc only** for AutoCore sector |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Requires UI role + strings | **High** | Wrong rename |
| EAX item + show flag | **High** | Wrong call sites |
| Offset map for reqs | **High** | Wrong item schema docs |
| Color constants | **High** | Wrong UI theme notes |
| Class fail flag coupling race | **Medium–High** | Complex branch; sealed as decomp+structure, not redesign |
| Product method name | **Probable** | Doc only |
| Type `0x1a` meaning | **Open** | Wrong suppress rule English |
| Runtime | **Open** | Visual mismatch |

---

## 3. Cross-check against raw / bytes

```
raw ≡ live decompile CF
entry: sub esp,0x8c; push ebx/esi/edi; mov esi,eax; xor ebx,ebx; call 007a69d0
gates: cmp [esp+0xa0],bl; cmp [item+0xa8]+0x38, 0x1a; cmp DAT_00d1b6d8, 0
strings: Requires / Level / Combat / Tech@00a2e4fc / Theory / Perception
colors: 0xffbbbbbb / 0xffffffff / 0xffff2020
epilogue family: add esp,0x8c; ret (multiple exits)
callers: 0084412d, 0084c40e, 0088da8f, 0088db44
```

Reject any claim that this is a Combat-only helper or a pure ECX-thiscall on the item.

---

## 4. Surviving contract for AutoCore

```
// Client UI only — not a sector authority check
int UI_AppendItemRequirements(UIText* text, bool show, Item* item /*in EAX*/):
  if !show or item.category==0x1A or no local player: return 0
  if no active requirements: return 0
  append "Requires:" (gray)
  for each active req line:
    append formatted line
    color red if player fails else white (or alt append for race/class met)
  return lineCount

// Server ports should use data-driven req checks, not this presentation path.
// Stat getters used here are already sealed elsewhere (Theory/Combat/Tech/Perception).
```

Do **not** use `Named_Combat_00845360` as primary. Keep Ghidra `FUN_00845360` as twin.

---

## 5. Open questions

1. UI class / vtable for text append `+0x224` vs `+0x250`.
2. Category `0x1a` product English (quest item? recipe? hidden?).
3. Whether both `FUN_0040f540` calls are intentional dual-eval or decomp duplication of one leaf.
4. Live: does line count drive layout height in callers?
5. Class line: when class id valid but race -1, race-for-table falls back to player race byte — confirm design.

**Verdict:** **accept-with-gaps** — adversarial kills Combat-primary and ECX-item misreads; Requires-block contract stands with known decomp hazards documented.
