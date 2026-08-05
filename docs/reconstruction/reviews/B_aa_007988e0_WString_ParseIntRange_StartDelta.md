# Review B (skeptical / adversarial): `aa_007988e0` WString_ParseIntRange_StartDelta

| Field | Value |
|---|---|
| **Stable ID** | `aa_007988e0` |
| **VA** | `0x007988e0` |
| **Canonical name** | `WString_ParseIntRange_StartDelta` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007988e0_WString_ParseIntRange_StartDelta.md` |
| **System** | missions-progression / XML attribute helpers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Outputs `(start, end)` | Bytes: after success `*p3 -= *p2` | **Falsified** end retained — becomes **delta** |
| 2 | Always sets success flag | Requires `i==2` **and** non-null `param_4` | **Falsified** always-set |
| 3 | Failure zeros outs | Only optional ok cleared; no wipe of `*p2/*p3` | **Falsified** wipe-on-fail |
| 4 | Takes `wchar_t*` directly | Body loads `*[param_1]` | **Falsified** direct — is **pointer-to-pointer** |
| 5 | Mission-only API | Also `FUN_00798e50` (map text range) | **Falsified** mission-only |
| 6 | Scaffold invents CF | Live decompile ≡ clean | **Attack fails** |
| 7 | Inclusive end in delta | Arithmetic is plain subtract; inclusive/exclusive **Open** | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `%d;%d` + need 2 matches | **Confirmed** | Wrong parse gate |
| end → delta rewrite | **Confirmed** | Off-by-one ports of ranges |
| optional ok polarity (0→1) | **Confirmed** | Sticky true flags |
| `wchar_t**` first arg | **High** | Wrong string source |
| Product range meaning | **Open** | |
| Null `param_3` on success | **Open** | Would AV; callers must pass real ints |

---

## 3. Cross-check against raw / live / bytes

```
decompile ≡ raw/clean
bytes: test edi; mov byte [edi],0
       call swscanf("%d;%d")
       cmp eax,2 / jnz skip
       mov edx,[ebx]; sub [esi],edx   ; *p3 -= *p2
       test edi; mov byte [edi],1
string @ 0x00a983a4 = UTF-16 "%d;%d"
```

### Delta trap

Do **not** treat `*param_3` as the second scanned end after return. Successful path stores **end − start**.

### Pointer-to-pointer trap

First formal is **not** the wide buffer; it is an object/slot whose first dword is the `wchar_t*`.

---

## 4. Surviving contract for AutoCore

```
WString_ParseIntRange_StartDelta(ppWcs, &start, &endOrDelta, okOpt?):
  if okOpt: *okOpt = 0
  if swscanf(*ppWcs, L"%d;%d", &start, &endOrDelta) == 2:
    endOrDelta -= start
    if okOpt: *okOpt = 1

AutoCore must NOT:
  - keep "end" after success without subtract
  - require okOpt non-null
  - treat partial scanf as success
  - pass LPCWSTR where wchar_t** expected
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Format + i==2 gate | **Agree Confirmed** |
| Delta rewrite | **Agree Confirmed** |
| Optional ok | **Agree Confirmed** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Inclusive vs exclusive span in product.
2. Re-type MissionDef CoreMission call formals (stack noise).
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block end-not-delta and direct-LPCWSTR mistakes.
