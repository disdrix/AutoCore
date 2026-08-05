# Review B (skeptical / adversarial): `aa_0094b520` Client_AppFrameTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094b520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-A) |
| **Counterpart** | `reviews/A_aa_0094b520_Client_AppFrameTick.md` |
| **Verdict** | **accept-with-gaps** (agree with A; name structural) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is only frametime logger (`Named_frametime_txt`) | **Falsified** — log is nested under threshold; most body is subsystem ticks |
| 2 | Multiple static callers | **Falsified** — sole CODE xref from `FUN_0094b9c0` |
| 3 | Returns meaningful status other than 1 | **Falsified as observed CF** — final `return 1`; early paths still fall through to same return |
| 4 | Focus gate called with `1` (key path) | **Falsified for this site** — mode **0** (FocusGate dual sealed) |
| 5 | Always runs HB list tick | **Falsified** — requires `+0xb7` and `+0xa1==0` and earlier gates |
| 6 | `__stdcall` / stack client* | **Falsified** — `mov edi,ecx` |
| 7 | Product name “MainLoop” / “Idle” without evidence | **Overclaim** — pump is outer `FUN_0094b9c0`; this is the **frame body** only |
| 8 | Clean invents missing else-arms when gates fail | **Attack on bad ports** — early-outs skip large regions; must preserve nested structure |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pump-frame body role | **High** | wrong tick placement in server ports |
| Gate nesting `0x13 → 0xf40 → focus → body` | **High** | running sim while unfocused |
| Always EAX=1 | **High** | inventing failure codes |
| Frametime arm optional | **High** | treating I/O as mandatory per frame |
| Product flag names | **Open** | wrong documentation only if overclaimed |

---

## 3. Cross-check against raw + bytes

Prologue requires:

- FS SEH + large frame
- `client` in **ECX**
- first real gate `byte [client+0x13]`

Any plate that:

- drops the focus-gate early-out,
- runs `CVOGHBList_Tick` unconditionally,
- or renames the unit solely from `frametime.txt`

is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port skeleton (do not flatten gates)
uint32_t Client_AppFrameTick(Client *c) {
  // SEH / large frame omitted in ports as needed
  if (!c->flag_0x13) return 1;
  // timer nest A …
  if (!c->ptr_0xf40) { /* restore; */ return 1; }
  // timer nest B …
  if (Client_Input_FocusGateAndUiPoll(/*mode*/0) != 0) return 1;
  // ordered subsystem ticks under +0xa1 / +0xb7 / +0xe04 …
  // optional frametime log; Sleep(0);
  return 1;
}

// Outer pump (other VA): loop { Client_AppFrameTick(client); PeekMessage… }
```

---

## 5. Open questions

1. PDB / product symbol for this unit and pump parent.
2. English names for `+0x13`, `+0xa1`, `+0xb7`, `+0xf40`, `+0xe04`.
3. Whether AutoCore server has an analogue (likely **no** — client-only).

**Verdict:** **accept-with-gaps**
