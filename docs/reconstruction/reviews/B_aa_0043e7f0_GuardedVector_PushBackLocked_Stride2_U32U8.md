# Review B (skeptical / adversarial): `aa_0043e7f0` GuardedVector_PushBackLocked_Stride2_U32U8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e7f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-N) |
| **Counterpart** | `reviews/A_aa_0043e7f0_GuardedVector_PushBackLocked_Stride2_U32U8.md` |
| **Scratch** | `tmp/a_0043e7f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EDI**; ECX unused as this |
| 2 | Unlocked push body | **Falsified** — this is CS wrapper; body is `0043e9e0` |
| 3 | Same as dword `PushBackLocked` including nested | **Nuanced** — opcode twin of `0043c4f0` but nested is **stride-2 U32U8**, not dword PushBack |
| 4 | Host-level lock (`DAT+0x6c`) | **Falsified** — uses container `+0x14` / `+0x2c` |
| 5 | Single-caller helper | **Falsified** — **8** xrefs / **6** caller functions |
| 6 | Product name retail | **Overstated** — inferred |
| 7 | Decompiler signature complete | **Falsified** — omits EDI formal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI container + RET 0x4 | **High** | Wrong object / stack tear |
| CS +0x14 / flag +0x2c | **High** | Deadlock / data race |
| Nested = Stride2 U32U8 PushBack | **High** | Wrong POD / map stride |
| Multi-caller general ABI | **High** | Overfit one site |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | CS races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if [EDI+0x2c]: EnterCS(EDI+0x14)
  FUN_0043e9e0(param) with EAX=EDI
  if [EDI+0x2c]: LeaveCS

bytes (94 B full seal):
  SEH prolog → CMP [EDI+0x2C] → LEA ESI,[EDI+0x14]
  MOV EAX,[ESP+18]; PUSH EAX; MOV EAX,EDI; CALL 0043e9e0
  CMP [ESI+0x18] (=EDI+0x2C); Leave; ADD ESP,10; RET 4

twin 0043c4f0 vs 0043e7f0:
  identical except E8 rel32 (0043c830 vs 0043e9e0)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Nested free is W31-J sealed; lock wrapper free was residual there — sealed here.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector locked push_back (stride-2, dword+byte POD):
//   EDI = container; stack = const {u32,u8}*; RET 0x4
//   if lockEnable(+0x2c): EnterCS(+0x14)
//   PushBack_Stride2_U32U8(EAX=container, value)   // W31-J
//   if lockEnable: LeaveCS
// Do not substitute dword PushBackLocked (0043c4f0) nested body.
// Do not invent thiscall ECX=this.
// Do not substitute host-level CS (DAT+0x6c).
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/nested target; product residual only → **accept**.
