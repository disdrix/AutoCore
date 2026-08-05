# Review B (skeptical / adversarial): `Client_DismissProgressBar_Inferred` @ `0x007fb640`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fb640_Client_DismissProgressBar_Inferred.md` |
| **Verdict** | **accept-with-gaps** — dismiss leaf + ESI ABI sealed; skill-only and “jumptable” claims **falsified** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `void FUN_007fb640(void)` with phantom `unaff_ESI` means no real `this` | **Falsified as “no client”** — live body is entirely `[ESI+…]`; ShowTimedProgressBar does `MOV ESI,EAX` then `CALL`; case-3 path does `MOV ESI,EDI` then `CALL` |
| 2 | This is only a RecvSkillStatusEffect helper | **Falsified** — 5 xrefs: show bar, skill status, UseItem path, switch case 3, “Contact Interrupted!” |
| 3 | Scaffold name `Named_CalleeOf_Client_RecvSkillStatusEffect_*` is product name | **Overstated** — parent-seed only; multi-use dismiss leaf |
| 4 | Decompiler “Could not recover jumptable at 0x007fb681” | **Misleading** — single `JMP [EAX+0x440]` tail-call; not a multi-way switch table |
| 5 | Final dismiss is a normal `CALL` that returns into this frame | **Falsified** — `JMP` tail; when taken, callee returns to **caller of 007fb640** |
| 6 | Function always hides the bar | **Falsified** — null `+0x1120` or false `+0x3d8` → plain `RET` no-op |
| 7 | Host detach always runs | **Falsified** — gated on `bar+0x2b0 != 0` |
| 8 | Same host object as ShowTimedProgressBar attach (`+0xf40`) | **Not sealed** — this body uses `client+0xf38`; show uses `+0xf40` for adopt. May be related managers; **not proven identical** |
| 9 | Body sends packets / mutates skill cast state | **Falsified** — pure UI vcalls; no net send in body |
| 10 | `+0x440` is “reset” (`+0x43c` sibling slot) | **Open English** — complementary dismiss/hide role **High**; exact product synonym open |
| — | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI client + 0-arg plain RET | **Confirmed** | Wrong AutoCore UI glue ABI |
| Gate `+0x1120` | **Confirmed** | Dismiss wrong widget / silent miss |
| Probe `vtbl+0x3d8` bool | **High** | Dismiss when bar “inactive” or skip when visible |
| Conditional `+0xf38` / `+0xb0` detach | **High** structural | Orphan UI parent links |
| Tail JMP `vtbl+0x440` | **Confirmed** | Wrong stack / missed side-effect if rewritten as CALL+RET |
| Multi-caller shared dismiss | **High** | Over-specializing status-effect path |
| Product / RTTI names | Medium/Open | Doc-only |
| `+0xf38` vs `+0xf40` identity | **Open** | Wrong host object on port |
| Clean compile-ready types | Low | Intentional scaffold |

---

## 3. Surviving contract for AutoCore

```
// client in ESI
Client_DismissProgressBar_Inferred():
  bar = client.progressBar(+0x1120)
  if bar == null: return
  if !bar.vtbl[+0x3d8](): return          // bool probe
  if bar[+0x2b0] != 0:
       client.host(+0xf38).vtbl[+0xb0](bar)  // detach
  goto bar.vtbl[+0x440]                    // tail-call hide/dismiss
// no packet, no skill SM, no stack args
```

ShowTimedProgressBar spine (caller-owned): `CALL 007fb640` then dual-gate show path on `+0x1120` and `+0xf40`.

---

## 4. Residual disposition

| Topic | Disposition |
|---|---|
| `unaff_ESI` decompiler artifact | **Sealed** — ESI client convention |
| Jumptable warning | **Sealed misleading** — tail JMP |
| Skill-status-only naming | **Sealed overstated** — multi-use |
| `+0x1120` bar role | **Sealed High** (product class open) |
| `+0xf38` vs show `+0xf40` | **Open** — do not collapse without proof |
| Vtbl product symbols | Open |
| Runtime hide timing / focus | Open |

**Verdict:** Safe as **generic client progress-bar dismiss leaf**. Port with ESI client, 0 stack args, preserve optional detach + **tail** dismiss. Keep `_Inferred` until widget RTTI/PDB names land. Do not treat as netcode.
