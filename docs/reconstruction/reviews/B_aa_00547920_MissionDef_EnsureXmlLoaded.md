# Review B (skeptical / adversarial): `aa_00547920` MissionDef_EnsureXmlLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00547920` |
| **VA** | `0x00547920` |
| **Canonical name** | `MissionDef_EnsureXmlLoaded` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00547920_MissionDef_EnsureXmlLoaded.md` |
| **System** | missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free function `FUN_00547920(1)` / `(0)` with no object | Callers `MOV ECX, def`; body uses `*param_1` and `+0x168` | **Falsified** free-fn framing |
| 2 | Flag at dword index 0x5a is “field 0x5a” bytes | `int*` index → **byte 0x168** | **Falsified** dword-index-as-byte misread |
| 3 | Reloads XML every call | Outer gate returns if flag set | **Falsified** every-call reload |
| 4 | Failed open clears flag for retry | Flag set **before** open; failure path does not clear | **Attack fails** — sticky loaded bit (may block retry) |
| 5 | Stack 0/1 is fully understood force mode | Not in decompiler formals; residual Tentative | **Agree Open** — do not overclaim |
| 6 | All garbled L"…" strings are real log text | Stack noise / bad decompile; real English: path fmt + "Mission lacking child nodes %s" + HashError-style elsewhere | **Falsified** trust garbled strings |
| 7 | Parses only Title | Full tag matrix Objective…FailText | **Falsified** title-only |
| 8 | Returns HRESULT success | void; no sealed EAX contract | **Falsified** HRESULT API |
| 9 | GiveMission-only | 19 xrefs across UI/journal/interact/create | **Falsified** exclusivity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ensure-load role + +0x168 gate | **High** | Double-parse / skip hydrate |
| ECX = mission def | **High** | Crash / wrong def |
| Tag matrix English names | **Confirmed** | Missing objective hydrate |
| Sticky flag before open | **High** | Infinite retry loops or permanent fail |
| Stack 0/1 meaning | **Tentative** | Wrong force-reload API |
| snprintf path operands | **Open** | Wrong file path |
| COM vcall details | **Open** | Incomplete exact port |
| Runtime | **Open** | |

---

## 3. Cross-check

```
raw/clean scaffold ≡ live large-body CF (2026-07-29).

Gate:
  if ((char)def[0x5a] == 0) {  // byte def+0x168
    def[0x5a] = 1;
    ... open + parse ...
  }

Tags (_wcsicmp):
  Objective, CoreMission, Title, Internal, Description,
  OneLineAccept, OneLineReject, NotCompleteText, CompleteText, FailText

Xrefs: 19 (GiveMission dual call pattern PUSH 1 / conditional PUSH 0;
  CompleteObjective; ApplyCreateFromPacket; journal/UI; interact eval; …)

Residual (a_005327c0): role MissionDef_EnsureXmlLoaded High; stack 0/1 Tentative.
```

### Traps

1. **Do not** port as `void Ensure(int mode)` without `MissionDef* this`.
2. **Do not** map `param_1[0x5a]` to offset 0x5a.
3. **Do not** clear-and-retry on open fail without product proof — sticky `+0x168=1` means second call is no-op.
4. **Do not** treat dual GiveMission calls as two different free-function modes without ECX.
5. Ignore decompiler mojibake wide strings for documentation.

---

## 4. Surviving contract for AutoCore

```
MissionDef_EnsureXmlLoaded(def /*, mode? */)
  if def->xmlLoaded(+0x168): return
  def->xmlLoaded = 1
  open path "%s%S.xml" via NDXml
  if fail: log; cleanup; return   // flag stays 1
  find matching mission id entry (*def)
  parse children tags → objectives + text fields
  CoreMission path touches +0x169
  cleanup

AutoCore must NOT:
  - call without mission def this
  - re-enter expecting reload while +0x168 stays set
  - invent HRESULT return
  - document garbled decompiler L"…" as retail strings
  - claim stack 0/1 semantics as Confirmed
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Ensure-load role | **Agree High** |
| +0x168 gate math | **Agree High** |
| Tag matrix | **Agree Confirmed** |
| Sticky flag before open | **Agree High** |
| Stack 0/1 Tentative | **Agree** |
| ECX=def not free fn | **Agree Confirmed** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed CF. B emphasizes sticky-flag failure mode and free-fn decompiler trap.

---

## 6. Open questions

1. Stack mode 0 vs 1 (why GiveMission may call twice).
2. snprintf `%s` / `%S` sources (global path prefix + mission stem).
3. Whether open-fail sticky flag is a retail bug or intentional.
4. Dual units for each text setter + Objective parser.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; **block free-function framing, offset 0x5a misread, and Confirmed claims on stack mode**.
