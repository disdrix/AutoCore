# Review B (skeptical / adversarial): `aa_00799460` XmlAttr_FetchAndParseLong

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799460` |
| **VA** | `0x00799460` |
| **Canonical name** | `XmlAttr_FetchAndParseLong` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00799460_XmlAttr_FetchAndParseLong.md` |
| **System** | XML / NDUI / mission-def attribute parse |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Return means parse fully consumed | endptr never checked; junk suffix still returns fetch ok | **Falsified** full-parse claim |
| 2 | Always writes `*out` | Write gated on fetch success | **Falsified** always-write |
| 3 | `param_4` is max length | Passed as `wcstol` base | **Falsified** length |
| 4 | Inlines SysAllocString itself | Delegates to `FUN_00798bb0` | **Falsified** inline-alloc |
| 5 | Mission-only helper | NDUI + map + FX xrefs | **Falsified** mission-only |
| 6 | Scaffold wrong CF | Live ≡ clean | **Attack fails** |
| 7 | 64 wchar enough always | Truncation risk if 00798bb0 copies long text | **Open residual** (callee) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fetch gate then wcstol | **Confirmed** | Skip numbers on missing attr |
| Return == fetch flag | **High** | Treating as parse-ok accepts garbage |
| base = param_4 | **High** | Wrong radix |
| No out write on fail | **Confirmed** | Stale out values |
| Product attr map | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
call 00798bb0
test bl / jz skip
push base (param_4)
lea end; lea buf; call wcstol
mov [out], eax
mov al, bl; ret
stack frame 0x84 matches 64 wchar + end + alignment
```

### Stale-out trap

On fetch failure, `*param_3` is **not** zeroed. Callers must pre-init (MissionDef often uses `-1` sentinels on sibling helpers).

### Partial-parse trap

`wcstol` of `"12abc"` yields `12` with fetch success still true. Do not claim strict full-string integer validation in this unit.

---

## 4. Surviving contract for AutoCore

```
ok = XmlAttr_FetchAndParseLong(node, attrName, &value, base):
  ok = XmlAttr_FetchWide(node, attrName, buf64)
  if ok: value = wcstol(buf64, &end, base)
  return ok   // not (end==EOS)

AutoCore must NOT:
  - zero value on failed fetch inside this helper (callers own init)
  - treat return as full-string parse validation
  - confuse base with buffer size
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Fetch then optional wcstol | **Agree Confirmed** |
| Return fetch flag | **Agree High** |
| base param | **Agree High** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Dual `FUN_00798bb0`.
2. Base usage census.
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block full-parse and always-write mistakes.
