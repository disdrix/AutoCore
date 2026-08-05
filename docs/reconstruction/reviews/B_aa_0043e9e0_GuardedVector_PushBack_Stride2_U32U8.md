# Review B (skeptical / adversarial): `aa_0043e9e0` GuardedVector_PushBack_Stride2_U32U8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e9e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-J) |
| **Counterpart** | `reviews/A_aa_0043e9e0_GuardedVector_PushBack_Stride2_U32U8.md` |
| **Scratch** | `tmp/a_0043e9e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Identical to `0043e970` including store | **Falsified** — store is `0043ecf0` (u32+u8), not `0043ece0` (u32×2) |
| 2 | thiscall ECX | **Falsified** — EAX container |
| 3 | Element size is 5-byte *page stride* | **Nuanced** — **slots** are 8 B (`*8`); **write** is 5 B |
| 4 | Push_front | **Falsified** — end write; begin untouched |
| 5 | Locked body | **Falsified** — unlocked; lock is parent `0043e7f0` |
| 6 | Product name retail | **Overstated** — inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX + RET 4 | **High** | Wrong object |
| Twin grow/page/alloc | **High** | Map OOB |
| Pod width 5 vs 8 | **High** | Truncate / over-read |
| Unlocked body | **High** | Double-lock if mis-wrapped |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | CS races at wrapper |

---

## 3. Cross-check against raw + bytes

```
bodies 0043e970 vs 0043e9e0:
  identical opcode stream except three E8 rel32 displacements
  grow → both 0043ea60
  new  → both 00489892
  store → 0043ece0 vs 0043ecf0

0043ecf0 bytes:
  TEST EAX,EAX / JZ
  MOV EDX,[ECX]; MOV [EAX],EDX
  MOV CL,[ECX+4]; MOV [EAX+4],CL
  RET
```

Live ≡ raw. Parent `0043e7f0` decompile (context only): optional CS then this unit — confirms unlocked body.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector push_back (stride-2, dword+byte POD):
//   EAX = container; stack = const {u32,u8}*; RET 0x4
//   may GrowBlockMap_Stride2(1) with EBX=container
//   write u32+u8 at begin+size (8-byte slot); size++; begin unchanged
// Do not swap store helper with U32x2 sibling; do not invent thiscall.
// CS locking belongs to FUN_0043e7f0 wrapper, not this body.
```

---

## 5. Verdict

Adversarial pass **confirms** A; only product residual → **accept**.
