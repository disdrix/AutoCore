# Review B (skeptical / adversarial): `aa_004024b0` StdVector_DwordSize

| Field | Value |
|---|---|
| **Stable ID** | `aa_004024b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004024b0_StdVector_DwordSize.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Capacity = `(cap-begin)>>2` | **Falsified** — only reads +4/+8 |
| 2 | Stride 0x38 / 0x18 | **Falsified** — `sar 2` only |
| 3 | Mutates vector | **Falsified** — pure read |
| 4 | Same as SkillSet_GetEntryCount | **Falsified** — different VA, different stride |
| 5 | Null begin undefined | **Falsified** — explicit 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size formula | High | Off-by-factor loop bounds |
| Null-safe | High | Spurious empty |
| Domain-agnostic helper | High | Over-specializing name |

---

## 3. Cross-check

```
bytes: mov edx,[ecx+4]; test; jz→0; mov eax,[ecx+8]; sub; sar 2; ret
raw ≡ live ≡ clean.
```

---

## 4. Surviving contract for AutoCore

```
StdVector_DwordSize(vec) → n:
  begin==0 ? 0 : (end-begin)/4
```

---

## 5. Open questions

None for this leaf.

**Verdict:** **accept**
