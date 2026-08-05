# Review B (skeptical / adversarial): `aa_0043ce10` GuardedVector_PushFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ce10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-B) |
| **Counterpart** | `reviews/A_aa_0043ce10_GuardedVector_PushFront.md` |
| **Scratch** | `tmp/a_0043ce10.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EAX** (`MOV EBX,EAX`) |
| 2 | Push_back polarity | **Falsified** — writes at `begin-1` and **updates begin** |
| 3 | Decompiler hides grow ABI | **Survives nuance** — decompile shows `FUN_0043c9b0(1)` only; bytes prove EBX=container before call |
| 4 | Flat linear buffer | **Falsified** — page map `+0x04`, 4 dwords/page (`>>2` / `&3`) |
| 5 | Product name retail string | **Overstated** — inferred `GuardedVector_PushFront`; map overflow uses `deque` English |
| 6 | Null page after failed new is safe | **Survives as residual** — store skipped but size/begin still advance (bytes) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + RET 0x4 | **High** | Wrong object / stack smash |
| Front polarity (begin--) | **High** | Corrupts ring order |
| begin==0 wrap to cap*4 | **High** | Underflow off map |
| Map-grow gate | **High** | Map OOB or thrash |
| Nested GrowBlockMap | **High** (sealed W28-B) | Wrong capacity |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (begin&3)==0 && cap <= (size+4)>>2: GrowBlockMap(1)
  if begin==0: begin = cap*4
  new_begin = begin-1; page map store; size++; begin=new_begin

bytes:
  MOV EBX, EAX
  TEST BYTE [EBX+0xC], 3 / JNZ
  CMP [EBX+8], (size+4)>>2 / JA
  PUSH 1; CALL 0043c9b0
  MOV EDI,[EBX+0xC]; TEST/wrap *4; SUB 1
  page alloc; MOV from [ESP+0xC]; ADD [EBX+0x10],1; MOV [EBX+0xC],EDI
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 118 B hex sealed.

Polarity vs sibling `0043c830`: front updates begin; back does not — sealed pair.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_front (unlocked body; parents hold CS when flag set):
//   EAX = container (+0x04 pages, +0x08 cap, +0x0c begin, +0x10 size)
//   stack = const dword* value; RET 0x4
//   may GrowBlockMap(1) with EBX=container
//   wrap begin 0 → capacity*4; write at begin-1; size++; begin = new
// Do not invent plain vector::push_front without page map + begin wrap.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity; product name + runtime residual → **accept-with-gaps**.
