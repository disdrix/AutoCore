# Review B (skeptical / adversarial): `Client_ShowTimedProgressBar_Inferred` @ `0x007fb690`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fb690_Client_ShowTimedProgressBar_Inferred.md` |
| **Verdict** | **accept-with-gaps** — ABI/CF sealed; skill-only naming and 3-arg decompile **falsified** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler signature `(param_1, param_2, param_3)` is complete | **Falsified** — `RET 0x20` = 8 stack dwords; decompiler collapsed colors/rate into phantoms (`2.8026e-45` = int 2 as float) |
| 2 | This is a skill-only RequestCast helper | **Falsified** — 11 xrefs; strings `"Working.."`, `"Contacting INC..."`, `"Training Discipline"`, `"Crafting"` |
| 3 | Scaffold name `Named_CalleeOf_Client_RequestCastSkill_*` is product name | **Overstated** — parent-seed only; claim `_Inferred` multi-use |
| 4 | `in_EAX` is phantom garbage | **Falsified** — live client; prologue `MOV ESI,EAX`; all `client+disp` use ESI |
| 5 | Rate formula uses broken float/pointer mix from decompile | **Falsified as retail CF** — asm is `(g_flOne - [arg0]) / [arg1]` pure float |
| 6 | Function sends cast packet / starts HB | **Falsified** — UI only; RequestCast sends `0x2030` after this call |
| 7 | Always shows bar | **Falsified** — dual gate on `+0x1120` and `+0xf40`; silent no-op if null |
| 8 | `FUN_007fb640` is unrelated | **Falsified** — always called first; same `+0x1120` dismiss path |
| 9 | Color `0xFF400000` is a float duration | **Falsified** — dword color formal; decompiler float alias only |
| — | Runtime verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 8-arg stdcall + EAX client | **Confirmed** | Wrong AutoCore UI glue ABI |
| Gate offsets `+0x1120` / `+0xf40` | High | Wrong widget / silent no-op |
| Rate = (1−start)/duration | **Confirmed** | Wrong bar speed on port |
| RequestCast status string + charge duration | High | Missing optimistic cast UX |
| Multi-caller shared chrome | High | Over-specializing skill path |
| Vtbl English / product class | Medium/Open | Doc-only |
| Clean compile-ready types | Low | Intentional scaffold |

---

## 3. Surviving contract for AutoCore

```
// client in EAX
Client_ShowTimedProgressBar_Inferred(
    startOrMode,      // often 0
    durationSec,      // chargeMs * 0.001 on cast path
    titleSrc,         // skill+0x184 on cast path
    statusText,       // "...Activating Skill..." / other op strings
    colorCh1,         // often *DAT_00afdf08
    colorCh0,         // cast: 0xFF400000
    colorCh2,         // often 0
    extra)            // often 0
  → if client.progressBar(+0x1120) && client.uiHost(+0xf40):
       dismiss prior (007fb640)
       optional host.adopt(bar)
       bar.reset; setTitle; setStatus; setColors[3];
       setStart; setMax(1); setRate((1-start)/duration);
       setExtra; show(1); refresh()
  → else: no-op
// no packet, no skill state machine
```

RequestCast spine (caller-owned): only when `skill+0x14 > 0` and active-cast binding invalid → optimistic bar, then pack/send `0x2030`.

---

## 4. Residual disposition

| Topic | Disposition |
|---|---|
| Decompiler 3-arg signature | **Sealed wrong** — use asm 8-arg |
| Skill-only naming | **Sealed overstated** — multi-use |
| Rate formula | **Sealed High** |
| `+0x1120` / `+0xf40` roles | **Sealed High** (product names open) |
| Vtbl product symbols | Open |
| Runtime bar pixels / timing | Open |

**Verdict:** Safe as **generic client timed progress-bar programmer**. Do not treat as cast netcode. Port with 8-arg stdcall + EAX client; keep `_Inferred` until PDB/widget RTTI names land.
