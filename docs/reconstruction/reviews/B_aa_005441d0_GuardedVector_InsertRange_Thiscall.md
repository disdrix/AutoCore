# Review B (skeptical / adversarial): `aa_005441d0` GuardedVector_InsertRange_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_005441d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-I) |
| **Counterpart** | `reviews/A_aa_005441d0_GuardedVector_InsertRange_Thiscall.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `GuardedVector_InsertN` (`0043cb00`) | **Falsified** — InsertN uses ECX=N + fill value; this unit ECX=dest + source **range** + thiscall push pair |
| 2 | EAX/stdcall InsertN ABI | **Falsified** — `MOV ESI,ECX`; `RET 0x1C` |
| 3 | Flat `vector::insert` memcpy | **Falsified** — page-map push_front/back + ring assign |
| 4 | EraseRange polarity | **Falsified** — grows via push; no size shrink path |
| 5 | Uses EAX W29-B push | **Falsified** — callees `0043e3d0`/`0043d670` thiscall (W31-I) |
| 6 | Product name retail | **Overstated** — inferred structural only |
| 7 | Exactly 6 stack formals | **Partial** — decompiler 6+ECX but machine `RET 0x1C` (7 dwords); copy-ctor has 7 pushes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dest + RET 0x1C | **High** | Stack corrupt |
| Shorter-side insert CF | **High** | Wrong element order |
| Thiscall push pair callees | **High** | Wrong grow ABI |
| Layout family | **High** | Field OOB |
| 7th stack formal map | **Medium** | Mis-documented ABI |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | SEH / alloc |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = insert_at - begin; suffix = size - prefix; n = last - first
  if prefix < suffix:
    front arms with FUN_0043e3d0 + FUN_0043ec50
  else:
    back arms with FUN_0043d670 + FUN_0043ebb0 / FUN_0043ec50

bytes:
  MOV ESI, ECX
  … SEH LAB_009a4170 …
  RET 0x1C

caller FUN_00545190:
  zero dest header; push full [src.begin, src.begin+size) at insert 0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Body ~951 B through `RET 0x1C`.

vs W29-A InsertN: same shorter-side **shape**, different **payload** (range vs fill-N) and **push ABI** (thiscall W31-I vs EAX W29-B).

---

## 4. Surviving contract for AutoCore

```
// GuardedVector insert range (thiscall body):
//   ECX = dest; 7 stack formals; RET 0x1C
//   prefix/suffix shorter-side; room via PushFront/PushBack_Thiscall
//   assign via ring forward (0043ec50) / backward (0043ebb0)
// Do not reuse InsertN (ECX=N, RET 0x10) ABI.
// Do not invent flat vector::insert without page map + absolute indices.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/callees/layout; residuals are product English + exact 7-stack map → **accept-with-gaps**.
