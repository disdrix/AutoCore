# Review B (skeptical / adversarial): `aa_0093e120` Client_SelectTargetObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093e120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0093e120_Client_SelectTargetObject_Inferred.md` |
| **System** | `interaction-activation` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Also engages handbrake like stop packs | Cluster confusion with `00915670`/`0093a5c0` | **Falsified** — only `FUN_004f3700` when vehicle non-null; **no** `SetHandbrake` |
| 2 | Always applies `Object_SetSelectedTarget` | Missing gates | **Falsified** — `char+0x4f1` returns; `+0xd78`/`+0x6b9` branch |
| 3 | Skips highlight when select aborted mid-body | CF misread | **Partial** — `+0x4f1` **returns** before chrome; null char **goto** chrome |
| 4 | Sole caller InteractClick | Incomplete | **Falsified** — **27** sites / many systems |
| 5 | Sends UseObject / 0x2072 | Wire confusion | **Falsified** — no packet builders in callees list |
| 6 | Writes drive axes thr/steer/HB | Invent | **Falsified** — NoOp empty only |
| 7 | Raw `FUN_005172d0` ≠ live `Object_SetSelectedTarget` | Rename conflict | **Same call** — symbol rename; CF match |
| 8 | Product name sealed | No string | **Fail** |
| 9 | Runtime sealed | Matrix | **Fail** |

---

## 2. Decisive dataflow

```
// param_1 = target object* (nullable)
// ESI = client

// optional host vfunc +0x444 notify…

char = *(ESI+0xe98)
if char==0: goto chrome
if *(u8*)(char+0x4f1): return          // no chrome

if *(u8*)(char+0xd78)==0:
  if vehicle=*(char+0x250): CALL FUN_004f3700  // empty; NO HB
  Object_SetSelectedTarget(…)
elif *(u8*)(char+0x6b9) && alt_host: Object_SetSelectedTarget(…)

// UI refreshes + tips

chrome:
  if *(ESI+0x3048) != param_1: swap highlight; *(ESI+0x3048)=param_1
```

Live decompile 2026-07-29; xrefs count **27**.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Select + chrome role | **High** | Wrong interact UX |
| No HB on this path | **High** | Double-stop on click |
| `+0x4f1` hard return | **High** | Select during forbidden state |
| Call-graph breadth | **High** | Miss ports |
| Field English | **Open** | Naming |
| SetSelectedTarget full ABI | **Probable** | Extra EDI arg |

---

## 4. Surviving contract for AutoCore

```
SelectTargetObject(client, target):
  maybe notify interaction host
  if !char: update chrome only
  if char.busy(+0x4f1): return
  if normal mode: maybe DrivePathNoOp(vehicle); SetSelectedTarget(…)
  elif alt mode: SetSelectedTarget(alt_host, …)
  refresh UI panels; maybe first-time tips
  update selection chrome at client+0x3048
  // does NOT SetHandbrake; does NOT send UseObject
```

**Verdict:** **accept-with-gaps** — no-HB claim, suppress return, chrome end, multi-caller graph closed; product/runtime open.
