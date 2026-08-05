# Review B (skeptical / adversarial): `aa_0076cec0` Util_VsnprintfToStaticBuf4k

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cec0` |
| **VA** | `0x0076cec0` |
| **Canonical name** | `Util_VsnprintfToStaticBuf4k` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076cec0_Util_VsnprintfToStaticBuf4k.md` |
| **System** | logging / string format |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Writes into first argument pointer | Bytes never load `[esp+4]`; always `DAT_00d19530` | **Falsified** first-arg-out |
| 2 | Dynamic heap allocation | Fixed global + size 0x1000 only | **Falsified** |
| 3 | Returns HRESULT / status | Returns buffer pointer in EAX | **Falsified** |
| 4 | Truncation silent vs assert | `_vsnprintf` only; no post-check | **Attack fails** — silent truncate possible |
| 5 | Auth-only helper | 50+ callers across subsystems | **Falsified** ownership |
| 6 | Format string is first arg | Format is **second** stack arg (`[esp+8]`) | **Falsified** mis-order |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Static 4k buffer + return | **Confirmed** | Port uses wrong buffer |
| First formal unused | **Confirmed** | Wrong ABI in stubs |
| Cross-cutting log utility | **Confirmed** | Domain mis-tag |
| Reentrancy safe | **Open / false** | Nested format clobbers |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw ≡ clean.
bytes: push 1000; push d19530; call _vsnprintf; mov eax,d19530
No call to vog_LogMessage inside this VA — parents log.
```

### Merge trap

Do **not** fold this into `vog_LogMessage` or auth-only formatters. Many duals already cite it as a shared format step.

### Caller trap

Sites pass `&local` as first arg then use **return** value. Emulating "write to first arg" is wrong.

---

## 4. Surviving contract for AutoCore

```
Util_VsnprintfToStaticBuf4k(_unused, fmt, ...):
  _vsnprintf(g_static_4k, 0x1000, fmt, va)
  return g_static_4k

AutoCore must NOT:
  - write into the first pointer argument
  - allocate per call
  - assume reentrant nesting is safe without copy
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Static buf + vsnprintf + return | **Agree Confirmed** |
| First formal unused | **Agree Confirmed** |
| accept | **Agree** |

---

## 6. Open questions

1. Inventory all hot nested call pairs that share the buffer.
2. Product symbol name from PDB if ever available.

**Verdict:** **accept** — agree with A; block first-arg-out and reentrancy assumptions.
