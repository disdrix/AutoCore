# Review B (skeptical / adversarial): `aa_0043e3d0` GuardedVector_PushFront_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-I) |
| **Counterpart** | `reviews/A_aa_0043e3d0_GuardedVector_PushFront_Thiscall.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | EAX container (like W29-B PushFront) | **Falsified** — entry `MOV ESI,ECX`; true thiscall |
| 2 | Push_back polarity | **Falsified** — rewinds begin; writes at `new_begin` |
| 3 | Missing begin==0 wrap | **Falsified** — `if begin==0: begin=capacity*4` then `begin-1` |
| 4 | Uses EBX GrowBlockMap `0043c9b0` | **Falsified** — calls `0043d990`; ECX preserved (no reload) |
| 5 | Page wrap-by-capacity like push_back | **Not present** — front path uses absolute `new_begin>>2` after wrap only |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_PushFront_Thiscall` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + RET 0x4 | **High** | Wrong object |
| Front polarity (begin rewound) | **High** | Corrupts ring order |
| begin==0 wrap | **High** | Front OOB / wrong slot |
| Map-grow gate + thiscall grow | **High** | Map thrash / wrong grow ABI |
| size++ + begin commit | **High** | Lost front |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (begin&3)==0 && cap <= (size+4)>>2: FUN_0043d990(1)
  if begin==0: begin = cap*4
  new_begin = begin-1; page alloc; FUN_0043d420; size++; begin=new_begin

bytes:
  MOV ESI, ECX
  TEST byte [ESI+0xC], 3 / JNZ
  … PUSH 1; CALL 0043d990   // no MOV ECX,ESI — ECX still this
  MOV EDI,[ESI+0xC]; if zero: EDI = [ESI+8]*4  (via ADD EDI,EDI after load cap)
  DEC EDI; page = EDI>>2; new?; CALL FUN_0043d420
  ADD [ESI+0x10],1; MOV [ESI+0xC],EDI
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 120 B hex sealed.

Polarity vs sibling `0043d670`: front rewinds begin; back leaves begin — sealed thiscall pair.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_front (thiscall body):
//   ECX = container; stack = const dword* value; RET 0x4
//   may GrowBlockMap_Thiscall(1) with ECX=container
//   if begin==0: begin = capacity*4; new_begin = begin-1
//   write at new_begin; size++; begin = new_begin
// Do not reuse EAX/EBX W29-B PushFront ABI on thiscall sites.
// Do not invent linear vector::push_front.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity/grow ABI; product residual only → **accept**.
