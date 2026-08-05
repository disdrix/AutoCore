# Review B (skeptical / adversarial): `aa_0043d670` GuardedVector_PushBack_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-I) |
| **Counterpart** | `reviews/A_aa_0043d670_GuardedVector_PushBack_Thiscall.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | EAX container (like W29-B PushBack) | **Falsified** — entry `MOV ESI,ECX`; true thiscall |
| 2 | Push_front polarity | **Falsified** — write at `begin+size`; **no** begin update |
| 3 | Uses EBX GrowBlockMap `0043c9b0` | **Falsified** — calls `0043d990` thiscall grow with `MOV ECX,ESI` |
| 4 | Flat `vector::push_back` | **Falsified** — page map + absolute end index + wrap |
| 5 | Inline store like EAX twin | **Partial** — uses `FUN_0043d420` (null-checked assign); same effect |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_PushBack_Thiscall` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + RET 0x4 | **High** | Wrong object / stack corrupt |
| Back polarity (end write) | **High** | Corrupts ring order |
| Page wrap | **High** | Map OOB |
| Map-grow gate + thiscall grow | **High** | Map thrash / wrong grow ABI |
| begin left alone | **High** | Front shifts wrongly |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if ((begin+size)&3)==0 && cap <= (size+4)>>2: FUN_0043d990(1)
  abs = begin+size; page wrap; new(0x10)?; FUN_0043d420; size++

bytes:
  MOV ESI, ECX
  … TEST (begin+size)&3 / JNZ
  PUSH 1; MOV ECX,ESI; CALL 0043d990
  abs = begin+size; page = abs>>2; SUB if cap<=page
  page alloc; CALL FUN_0043d420; ADD [ESI+0x10],1
  RET 4   // no write to [ESI+0xC]
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 119 B hex sealed.

Polarity vs sibling `0043e3d0`: back leaves begin; front rewinds begin — sealed thiscall pair both calling W30-A grow.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_back (thiscall body):
//   ECX = container; stack = const dword* value; RET 0x4
//   may GrowBlockMap_Thiscall(1) with ECX=container
//   write at begin+size with page wrap; size++; begin unchanged
// Do not reuse EAX/EBX W29-B PushBack ABI on thiscall sites.
// Do not invent plain vector::push_back without page map + absolute end index.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity/grow ABI; product residual only → **accept**.
