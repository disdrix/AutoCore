# Review B (skeptical / adversarial): `aa_0044b5c0` Object_WriteComposedMatrix

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b5c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-C OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_0044b5c0_Object_WriteComposedMatrix.md` |
| **System** | graphics / xform |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on ABI + flag gates + compose call shape; **reject** "thiscall-only one stack param with unaff_EDI noise" and "second path is 1-arg FUN_00412d40" |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `unaff_EDI` is decompiler garbage | **Falsified** — both arms read `[edi+0xbc]`; parent supplies scaleSrc in EDI |
| 2 | Second `FUN_00412d40` is 1-arg | **Falsified** — `push esi; push eax/edi; push ebx; call; add esp,0x0C` |
| 3 | stdcall / ret 4 | **Falsified** — bare `ret` (`C3`) |
| 4 | Always rebuilds matrix | **Falsified** — bit1 clear → `lea esi,[ecx+0x40]` |
| 5 | Always refreshes companion | **Falsified** — bit0 clear skips `FUN_00972e50` |
| 6 | Product name proven | **Fail** — inferred English only |
| 7 | Needs `disassemble_bytes` | **Falsified** — 80 B fully recovered via `read_memory` |

---

## 2. Decisive evidence

### Companion bit0 test

```text
f6 87 bc 00 00 00 01   ; test byte [edi+0xbc], 1
74 17                 ; jz compose_raw
8b cf                 ; mov ecx, edi
e8 …                  ; call FUN_00972e50
```

### Compose arity

```text
56 50 53 e8 … 83 c4 0c
```

three pushes + stack cleanup 12.

### Parent residual closed

W21-O Bounds dual listed `FUN_0044b5c0` matrix as open gap — this dual seals that callee for owned VA.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX/EDI/stack ABI | **High** | Bounds matrix wrong |
| Flag bit meanings 0/1 | **High** (body + callee clears) | Stale matrix |
| Compose 3-arg | **High** | Wrong stack |
| Compose math order | **Open** (callee) | Visual/bounds offset |
| Product name | **Tentative** | Naming only |

---

## 4. What would falsify accept-with-gaps

1. A second caller that does not set EDI (would imply optional companion — not seen; only xref is Bounds).
2. Bytes showing ret 4 or missing third push.
3. Proof `@+0x40` is not a 4×4 float matrix (callee `FUN_00412d40` copies 16 dwords — consistent).

None observed for (1)/(2).

---

## 5. Verdict

**accept-with-gaps.** Matrix helper dual complete for bounds stack. Residuals: product symbol, `FUN_00412d80` multiply order, runtime golden.
