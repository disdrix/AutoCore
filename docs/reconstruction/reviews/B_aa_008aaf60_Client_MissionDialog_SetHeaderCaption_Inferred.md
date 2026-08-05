# Review B (skeptical / adversarial): `Client_MissionDialog_SetHeaderCaption_Inferred` / `FUN_008aaf60` @ `0x008aaf60`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aaf60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/CF/order; **needs-more-evidence** on product English and nested callees |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Pure `__fastcall` with only ECX | **Partial** — ECX is dialog; **EDI** is required second register formal (decompiler `unaff_EDI`) |
| 2 | `vtbl+0x1d8(0)` single-arg | **Falsified** — bytes push **1,1,0** both branches |
| 3 | Always formats via `FUN_005465c0` | **Falsified** — only when `DAT_00d1b6d8 != 0` and EDI≠0 |
| 4 | Always shows widget (`+0x1fc`) | **Falsified** — gated by `DAT_00d1b21c` and state 2/3 |
| 5 | Rebuilds full mission journal panels | **Falsified** — header widget only; journal panels are parent |
| 6 | stdcall / stack caption arg | **Falsified** — caption in **EDI**; plain `C3` |
| 7 | Scaffold “CalleeOf_UpdateMissionJournal” is full call surface | **Falsified** — also ShowNpc×3 and FUN_0093e450 |
| 8 | Nested chrome helpers dualed here | **Rejected scope** — OWN only this VA |
| 9 | Runtime Confirmed | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dialog / EDI key | **Confirmed** | Wrong caption / wrong host |
| Widget `+0x6e0` null gate | **Confirmed** | Crash or silent skip mismatch |
| Clear vs set branch | **Confirmed** | Stuck header text |
| `+0x1d8` arity (0,1,1) | **Confirmed** | Stack smash if ported as 1-arg |
| Call order set path | **Confirmed** | Missing format/chrome |
| Cond `+0x1fc` | **Confirmed** | Wrong visibility in abandon/journal |
| Nested 005465c0/008aab00/008aa610 semantics | **Low** (out of OWN) | Incomplete header pipeline port |
| Product names | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// ECX = dialogCtx, EDI = captionKey (0 = clear)
Client_MissionDialog_SetHeaderCaption_Inferred(dialogCtx, captionKey):
  widget = *(dialogCtx + 0x6e0)
  if !widget: return
  if captionKey == 0:
    widget->vtbl+0x1d8(0, 1, 1)
    widget->vtbl+0x34c()
  else:
    text = resolve(captionKey)           // 007a69d0 / 007a6de0
    string s(text)
    if DAT_00d1b6d8: FUN_005465c0(DAT_00d1b6d8, &s)
    widget->vtbl+0x1d8(0, 1, 1)
    FUN_008aab00(widget)
    widget->vtbl+0x1f0()
    widget->vtbl+0x34c()
    if DAT_00d1b21c==0 OR state(+0x648) in {2,3}:
      widget->vtbl+0x1fc()
  widget->vtbl+0x214(0)
  FUN_008aa610()

// NOT journal panel rebuild. NOT mission grant/complete.
// Preserve three-arg +0x1d8 even though decompiler shows (0).
```

---

## 4. Falsification notes

### 4.1 “unaff_EDI is decompiler noise”

Bytes: `85 ff` / `0f 84 …` then non-zero path `57` (`push edi`) into `007a6de0`. EDI is a real register formal; callers must set it.

### 4.2 Single-arg SetText fantasy

Both clear and set branches execute `6a 01 6a 01 6a 00 ff 92/90 d8 01 00 00`. Ports that call one-arg SetText invent ABI.

### 4.3 Journal-only helper

Six xrefs span ShowNpc, journal, and a generic choice-dialog case. Naming as journal-only understates reuse; “header caption” is safer.

### 4.4 Nested dual claim

WQ7R-A does **not** seal `005465c0` / `008aab00` / `008aa610`. Adversarial residual: full header pipeline port still depends on those duals.

---

## 5. Open questions

1. Product widget class / vtable English.
2. EDI key domain (name id table).
3. `DAT_00d1b21c` meaning.
4. Nested residual OWN results from sibling agents.
5. Runtime golden for clear vs set paths.

**Verdict:** **accept-with-gaps** — structural seal holds; nested product semantics residual.
