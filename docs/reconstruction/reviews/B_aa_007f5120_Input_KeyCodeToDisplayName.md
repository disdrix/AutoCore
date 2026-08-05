# Review B (skeptical / adversarial): `aa_007f5120` Input_KeyCodeToDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f5120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ7R-G) |
| **Counterpart** | `reviews/A_aa_007f5120_Input_KeyCodeToDisplayName.md` |
| **Scratch** | `tmp/a_007f5120.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack / ECX key formal | **Falsified** — entry `MOVZX EAX,DX`; ECX is copy of code for range tests |
| 2 | Returns heap / caller buffer | **Falsified** — static `DAT_00d1f73c` / snprintf `DAT_00d1f0f8` / empty `DAT_00a1419b` |
| 3 | Mouse codes are 0..7 | **Falsified** — mouse band starts at **0xF00** |
| 4 | Unknown always empty | **Partial** — `<0xF000` empty; high codes synthesize Joy_* strings |
| 5 | Non-reentrant safe | **Overstated** — static buffers; concurrent use clobbers (client single-thread UI typical) |
| 6 | Has many callees | **Falsified** — only `_snprintf` |
| 7 | Server-relevant | **Falsified** — client display only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| DX ABI | **High** | Wrong key shown |
| DIK case labels (string-backed) | **High** | Misnamed binds |
| Mouse 0xF00 band | **High** | Mouse binds blank/wrong |
| Joy range partition | **High** | Controller labels wrong |
| Opaque DAT_* multi-char blobs | **Medium** | Few numpad labels |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

- `read_memory 0x00a84ea8` → `MOUSE1\0` then `DOWN`/`RIGHT`/`LEFT` neighbor strings.  
- `read_memory 0x00a2e620` used by peer formatter is `+` (not this unit).  
- `read_memory 0x00a1419b` → first byte `0x00` empty C string.  
- Callers all UI formatters; peer `0x007f9160` loads EDX then `CALL 0x007f5120`.

---

## 4. Surviving contract for AutoCore

```
// Client only — keycode → display name
name = Input_KeyCodeToDisplayName(keyCode)  // DX in, EAX out
// may point at process-static storage; copy if retaining across next call
// 0 / unknown low codes → ""
// 0xF00+ mouse; 0xF000+ joy synthetic
```

---

## 5. Verdict

Adversarial pass confirms A. No CF/ABI residual blocking port → **accept**.
