# Review B (skeptical / adversarial): `aa_0043d940` GuardedVector_Resize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-L) |
| **Counterpart** | `reviews/A_aa_0043d940_GuardedVector_Resize_Thiscall.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same ABI as W28-D `GuardedVector_Resize` | **Falsified** — W28-D is EAX container / ECX new_size / plain RET; this unit is **ECX thiscall + RET 8** |
| 2 | Decompiler 1-stack-arg signature complete | **Falsified** — both epilogues `C2 08 00`; fill is second stack formal |
| 3 | Grow uses W29-A InsertN (ECX=N) | **Falsified** — rel32 → `0043e080` thiscall InsertN; ECX remains container |
| 4 | Shrink uses sealed `GuardedVector_EraseRange` `0043c8c0` | **Falsified** — rel32 → `0043df90` (parallel thiscall erase family) |
| 5 | Always mutates size | **Falsified** — equal path is pure no-op (`JBE` then `JNB`) |
| 6 | Product name retail string | **Overstated** — inferred `GuardedVector_Resize_Thiscall` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + stack (n, fill) + RET 8 | **High** | Stack imbalance / wrong object |
| Grow end-insert math | **High** | Wrong insert_at / count |
| Shrink range ends | **High** | Leaves tail elements |
| Nested `0043df90` free | **Medium** | Port invents flat erase |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  size = [param_1+0x10]
  if size < n: InsertN(begin+size, n-size, &fill_slot)
  if n < size: erase [begin+n, begin+size)

bytes:
  MOV EAX,[ESP+4]; MOV ESI,[ECX+0x10]; CMP EAX,ESI / JBE
  grow: LEA fill*; SUB EAX,ESI; ADD EDX,ESI; CALL 0043e080; RET 8
  equal skip via JNB after JBE
  shrink: CALL 0043df90; RET 8
```

Sole caller `0043d650`: seeds fill dword `0`, pushes new_size, ECX preserved as container; confirms fill formal.

Live decompile 2026-07-29 ≡ raw 2026-07-23 for trichotomy CF; **bytes win** on fill/RET 8.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector thiscall resize:
//   ECX = container (+0x0c begin, +0x10 size)
//   stack new_size, fill (by value); RET 8
//   grow: InsertN_Thiscall end-insert of (new-size) fill copies
//   shrink: FUN_0043df90 erase [begin+new, begin+old)
// Do NOT reuse W28-D EAX/ECX Resize ABI or W29-A InsertN (ECX=N).
// Do NOT drop fill formal — RET 8 requires it even when caller seeds 0.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets and rejects ABI-mix with W28-D Resize; nested erase free is residual only → **accept**.
