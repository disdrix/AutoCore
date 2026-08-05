# Review B (skeptical / adversarial): `aa_008a0210` QuickBar_CycleSelectValidColumn

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-T) |
| **Counterpart** | `reviews/A_aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX-thiscall member on host | Body uses **EBX** as host; frame `lea ebp,[ebx+0x63c]`; call sites `MOV EBX,[DAT_00d1b8f0]` / `MOV EBX,EDI` | **Falsified** as ECX-thiscall |
| 2 | Returns useful success boolean | Every exit `xor al,al` / mask to AL=0 | **Falsified** if claimed true success |
| 3 | Activates skill / sends QuickBarUpdate | Callees are SetSelected + RTTI/peer-clear only; no sector opcodes | **Falsified** |
| 4 | Direction 0 = next (or opposite) | Live: `cmp [esp+dir],0` → je **prev** path; `009116a4` PUSH 0 vs `00911676` PUSH 1 on sibling binds | **Falsified** if inverted |
| 5 | Decompiler's single-this SetSelected(0)/SetSelected(1) | Bytes rewrite ECX between calls (current then target) | **Decompiler incomplete** — must not port raw as-is |
| 6 | PollBoundActions-only helper | 8 xrefs including SelectPage, skill-train, input binds | **Overstated** residual auto-seed |
| 7 | Kind 6 is a valid filled slot | Both this body and SetSelected reject `+0x548 == 6` | **Falsified** |
| 8 | Bare `ret` (no stack cleanup) | Final `ret 4` both exits | **Falsified** |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX host + stack direction + ret 4 | **High** | Wrong ABI wrapper |
| 10-col +0x63c / +0x4fc / +0x548 layout | **High** | Breaks selection walk |
| Pair deselect→select with **two** this pointers | **High** | Deselect wrong column |
| Direction 0=prev / ≠0=next | **High** | Inverted key binds |
| Structural cycle role | **High** | — |
| Product method spelling | **Low–Med** | Naming only |
| Return-value consumers | **Med** | AL always 0; callers mostly ignore |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** (modulo documented ECX gap) |
| Body hex via `read_memory` | **Yes** — starts `55 56 8d ab 3c 06…`, ends `…32 c0 5d c2 04 00` |
| SetSelected sibling sealed | **Yes** `aa_00826780` same gates / DAT_00d1da38 |
| SelectPage caller dir=1 | **Yes** assembly context `PUSH 1; CALL` |
| Input bind both directions | **Yes** `00911676` push 1 / `009116a4` push 0 |
| RTTI CDlgQuickBar on bootstrap | **Yes** imm `00afe3b4` / `00afe190` |

**Attack on “this is a skill-cast or wire update”:** **Fails** — pure UI selection chrome via SetSelected.

**Attack on “decompiler is bit-complete for port”:** **Fails** — must restore dual-ECX SetSelected pair from bytes.

---

## 4. Surviving contract for AutoCore

```
// EBX = CDlgQuickBar* host
// stack: char direction  (0=prev wrap, !=0=next wrap)
// ret 4; AL always 0
// cols = host+0x63c [10]
// selected: col+0x4fc; fill gate: col+0x548 ∉ {0,6}
// hit: SetSelected(cols[cur],0); SetSelected(cols[target],1)
// no selection: first filled → inline select (RTTI, peer clear, highlight, DAT_00d1da38, +0x4fc=1)
```

**Falsified port mistakes:**

- Using ECX as host thiscall without EBX.
- Porting decompiler's two SetSelected calls without switching this to current then target.
- Treating kind 6 as filled.
- Expecting non-zero return / `ret` without stack cleanup.
- Wiring this into skill cast or QuickBarUpdate packets.

---

## 5. Open questions

1. Product/PDB method name on `CDlgQuickBar`.
2. Exact English of sentinel kind **6** (empty/disabled shared with SetSelected).
3. Whether any caller inspects AL (all observed paths ignore).
4. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/layout; reject ECX-host / wire / inverted-direction / single-this myths.
