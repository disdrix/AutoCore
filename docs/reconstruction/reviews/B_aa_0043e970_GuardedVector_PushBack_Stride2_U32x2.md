# Review B (skeptical / adversarial): `aa_0043e970` GuardedVector_PushBack_Stride2_U32x2

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e970` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-J) |
| **Counterpart** | `reviews/A_aa_0043e970_GuardedVector_PushBack_Stride2_U32x2.md` |
| **Scratch** | `tmp/a_0043e970.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EAX** (`MOV EBX,EAX`) |
| 2 | Same as dword `GuardedVector_PushBack` (`0043c830`) | **Falsified** — `&1`/`>>1`/`*8` vs `&3`/`>>2`/dword |
| 3 | Push_front polarity | **Falsified** — write at `begin+size`; **no** begin update |
| 4 | No page wrap | **Falsified** — `if capacity <= page: page -= capacity` |
| 5 | Flat `vector::push_back` | **Falsified** — page map + absolute index |
| 6 | Store is inline MOV | **Falsified** — call `FUN_0043ece0` (null-safe 8 B) |
| 7 | Product name retail | **Overstated** — inferred structural name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + RET 0x4 | **High** | Wrong object |
| Back polarity | **High** | Corrupts ring order |
| Stride-2 page wrap | **High** | Map OOB |
| Map-grow gate vs GrowBlockMap_Stride2 | **High** | Map thrash |
| 8-byte POD write | **High** | Truncates element |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if ((begin+size)&1)==0 && cap <= (size+2)>>1: GrowBlockMap_Stride2(1)
  abs = begin+size; page wrap >>1; store via 0043ece0; size++

bytes:
  MOV EBX,EAX
  TEST CL,1 / JNZ
  … CALL 0043ea60
  abs = begin+size; page = abs>>1; SUB if cap<=page
  new(0x10); LEA [base+(abs&1)*8]; CALL 0043ece0
  ADD [EBX+0x10],1; RET 4   // no write to [EBX+0xC]
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 110 B hex sealed.

Polarity vs dword PushBack W29-B: same back polarity; different stride/POD. Twin `0043e9e0` shares body except store helper.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_back (stride-2, 8-byte POD):
//   EAX = container; stack = const {u32,u32}*; RET 0x4
//   may GrowBlockMap_Stride2(1) with EBX=container
//   write at begin+size with >>1 page wrap; size++; begin unchanged
// Do not reuse dword PushBack (>>2) or invent thiscall.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity/POD width; product residual only → **accept**.
