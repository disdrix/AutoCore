# Review B (skeptical / adversarial): `aa_0043c830` GuardedVector_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-B) |
| **Counterpart** | `reviews/A_aa_0043c830_GuardedVector_PushBack.md` |
| **Scratch** | `tmp/a_0043c830.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EAX** |
| 2 | Push_front polarity | **Falsified** — write at `begin+size`; **no** begin update |
| 3 | No page wrap needed | **Falsified** — `if capacity <= page: page -= capacity` |
| 4 | Flat `vector::push_back` | **Falsified** — page map + absolute index |
| 5 | Only used by grow-assign core | **Falsified** — 5 callers incl. `0043c4f0`, `007b75b0`, `009668a0` |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_PushBack` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + RET 0x4 | **High** | Wrong object |
| Back polarity (end write) | **High** | Corrupts ring order |
| Page wrap | **High** | Map OOB |
| Map-grow gate | **High** | Map thrash |
| begin left alone | **High** | Front shifts wrongly |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if ((begin+size)&3)==0 && cap <= (size+4)>>2: GrowBlockMap(1)
  abs = begin+size; page wrap; store; size++

bytes:
  MOV EBX, EAX
  MOV EAX,[EBX+0x10]; MOV ECX,[EBX+0xC]; ADD ECX,EAX
  TEST CL,3 / JNZ
  … CALL 0043c9b0
  abs = begin+size; page = abs>>2; SUB if cap<=page
  page alloc; MOV from [ESP+8]; ADD [EBX+0x10],1
  RET 4   // no write to [EBX+0xC]
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 115 B hex sealed.

Polarity vs sibling `0043ce10`: back leaves begin; front rewinds begin — sealed pair used by `FUN_0043cf40` grow-assign arms.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_back (unlocked body):
//   EAX = container; stack = const dword* value; RET 0x4
//   may GrowBlockMap(1) with EBX=container
//   write at begin+size with page wrap; size++; begin unchanged
// Do not invent plain vector::push_back without page map + absolute end index.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity; product name + runtime residual → **accept-with-gaps**.
