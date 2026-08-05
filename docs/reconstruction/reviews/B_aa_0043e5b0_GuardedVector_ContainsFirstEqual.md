# Review B (skeptical / adversarial): `aa_0043e5b0` GuardedVector_ContainsFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e5b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-B) |
| **Counterpart** | `reviews/A_aa_0043e5b0_GuardedVector_ContainsFirstEqual.md` |
| **Scratch** | `tmp/a_0043e5b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EAX** (`MOV EDI,EAX`) |
| 2 | Mutating find / erase-in-place | **Falsified** — AL only; no write to pages/size/begin |
| 3 | Flat linear buffer | **Falsified** — page map `+0x04`, wrap by `+0x08`, 4 dwords/page |
| 4 | Always locks CS | **Falsified** — gated on `+0x2c`; leave uses `[ESI+0x18]` ≡ same flag |
| 5 | Product name retail string | **Overstated** — inferred `GuardedVector_ContainsFirstEqual`; family from deque-shaped map |
| 6 | Safe under null page | **Survives as residual** — load without null check (bytes) |
| 7 | Return void (Ghidra sig) | **Falsified** — `MOV AL,BL` + `RET 4`; analyze warns undefined return |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + RET 0x4 + AL | **High** | Wrong object / stack smash |
| First-equal linear scan | **High** | Misses / false hits |
| Page wrap math | **High** | OOB page index |
| CS flag +0x2c / CS +0x14 | **High** | Race / deadlock with parents |
| Product English | **Inferred** | Naming only |
| Null-page residual | **Open** | AV on hole |
| Runtime | **Open** | Multi-caller races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if cs_flag: EnterCS
  for idx in [begin, begin+size):
    page map load; if *slot==*key: found=1; break
  if cs_flag: LeaveCS
  return found

bytes:
  MOV EDI,EAX
  CMP BYTE [EDI+0x2C],0 / LEA ESI,[EDI+0x14] / optional Enter
  MOV EDX,[EDI+0xC]; MOV EBP,[EDI+0x10]; XOR BL,BL; ADD EBP,EDX
  loop: CMP EDX,EBP / page>>2 / wrap / load / CMP *key / INC EDX
  hit: MOV BL,1
  optional Leave; MOV AL,BL; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 123 B hex sealed.

Pair check: parent `AssManager_RemoveResolver` treats return as membership before `EraseFirstEqual` — consistent with non-mutating contains.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector contains first-equal (may take own CS when flag set):
//   EAX = container (+0x04 pages, +0x08 cap, +0x0c begin, +0x10 size,
//                    +0x14 CS, +0x2c flag)
//   stack = const dword* key; RET 0x4; AL = found
//   linear scan ring; stop at first equal; no mutate
// Do not invent std::vector::find or always-locked map without page wrap.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/non-mutate; product name + null-page + runtime residual → **accept-with-gaps**.
