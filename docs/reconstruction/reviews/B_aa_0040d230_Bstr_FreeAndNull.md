# Review B (skeptical / adversarial): `aa_0040d230` Bstr_FreeAndNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d230` |
| **VA** | `0x0040d230` |
| **Canonical name** | `Bstr_FreeAndNull` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d230_Bstr_FreeAndNull.md` |
| **System** | OLE/COM string hygiene |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Only SysFreeString (no null) | Bytes write `0` after free | **Falsified** free-only |
| 2 | `free()` / `operator delete` | IAT is SysFreeString | **Falsified** CRT free |
| 3 | Takes BSTR by value in EAX only | ECX = pointer-to-BSTR | **Falsified** by-value |
| 4 | Mission-only helper | NDUI + many domains | **Falsified** mission-only |
| 5 | Scaffold invents CF | Live ≡ clean (3 lines) | **Attack fails** |
| 6 | Same as free-without-store sibling | This unit always stores 0 | **Agree distinct** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free + null | **Confirmed** | Double-free if not nulled at call sites — this unit prevents |
| ECX slot pointer | **Confirmed** | Wrong ABI |
| void / no stack | **Confirmed** | |
| Domain-universal helper | **High** | Over-specializing ports |

---

## 3. Cross-check against raw / live / bytes

```
mov esi, ecx
mov eax, [esi]
push eax
call dword ptr [SysFreeString]
mov dword ptr [esi], 0
ret
```

Body size end `0x0040d243`. Clean/raw match live decompile.

### Double-free trap

Callers that also `SysFreeString` the same slot without reading null afterward are bugs **outside** this unit. This helper’s job is exactly free+null.

### ABI trap

Not `SysFreeString(bstr)` wrapper with BSTR in EAX alone — **pointer in ECX**.

---

## 4. Surviving contract for AutoCore

```
Bstr_FreeAndNull(BSTR* slot):
  SysFreeString(*slot)
  *slot = 0

AutoCore must NOT:
  - omit the null store
  - use free/delete on BSTR
  - pass BSTR by value as ECX
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Free + null | **Agree Confirmed** |
| ECX BSTR* | **Agree Confirmed** |
| accept-with-gaps | **Agree** (gaps are naming only) |

---

## 6. Open questions

1. Product helper name if any.
2. None on control flow.

**Verdict:** **accept-with-gaps** — agree with A; block free-only and CRT-free mistakes.
