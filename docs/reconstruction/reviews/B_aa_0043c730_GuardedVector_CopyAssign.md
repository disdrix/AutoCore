# Review B (skeptical / adversarial): `aa_0043c730` GuardedVector_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-G) |
| **Counterpart** | `reviews/A_aa_0043c730_GuardedVector_CopyAssign.md` |
| **Scratch** | `tmp/a_0043c730.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Standard thiscall ECX=this | **Falsified** — EAX=src, EDI=dst; no ECX object contract |
| 2 | Stack formals for src/dst | **Falsified** — plain RET; sole caller only loads registers |
| 3 | Always grows | **Falsified** — empty clear + size≤dest fit branch |
| 4 | Locks CS itself | **Falsified** — no Enter/Leave; lock is parent `0043c5f0` |
| 5 | Decompiler invents unaff_EDI | **Survives as naming only** — EDI is real dest from caller |
| 6 | Product name retail string | **Overstated** — inferred from parent dual family |
| 7 | Nested fit/grow bit-exact | **Survives** — out of scope residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/EDI ABI | **High** | Snapshot factories corrupt |
| Self / empty / size branch CF | **High** | Wrong list contents |
| +0x0c / +0x10 fields | **High** | Off-by-layout |
| Nested helper free | **Medium** | Element copy wrong |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (dst != src)
    if (src.size == 0) clear(dst)
    else if (src.size <= dst.size) fit
    else grow

bytes:
  MOV EBX, EAX
  CMP EDI, EBX / JE out
  MOV EDX, [EBX+0x10] / TEST / JZ clear
  MOV ECX, [EDI+0x10] / CMP EDX,ECX / JA grow
  … fit …
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Sole xref `FUN_0043c5f0` @ `0x0043c62c`.

---

## 4. Surviving contract for AutoCore

```
// Unlocked assign used under GuardedVector_AssignTo lock:
//   EAX = source (often cache+0x28 factory list)
//   EDI = dest snapshot
GuardedVector_CopyAssign(src, dst)
// Port must preserve ring header +0x04/+0x08/+0x0c/+0x10 semantics
// or replace with equivalent container snapshot under the same CS rules.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF; nested free + product name residual → **accept-with-gaps**.
